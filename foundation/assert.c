/* assert.c  -  Foundation library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform foundation library in C11 providing basic support data types and
 * functions to write applications and games in a platform-independent fashion. The latest source code is
 * always available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#include <foundation/foundation.h>

#include <stdio.h>
#include <stdarg.h>


#define ASSERT_BUFFER_SIZE             2048U

static assert_handler_fn _assert_handler;
static char              _assert_buffer[ASSERT_BUFFER_SIZE];

#if BUILD_ENABLE_ASSERT
#define ASSERT_STACKTRACE_MAX_DEPTH    128U
#define ASSERT_STACKTRACE_SKIP_FRAMES  1U
static void*             _assert_stacktrace[ASSERT_STACKTRACE_MAX_DEPTH];
static char              _assert_context_buffer[ASSERT_BUFFER_SIZE];
static char              _assert_stacktrace_buffer[ASSERT_BUFFER_SIZE];
static char              _assert_message_buffer[ASSERT_BUFFER_SIZE];
#endif


assert_handler_fn assert_handler( void )
{
	return _assert_handler;
}


void assert_set_handler( assert_handler_fn new_handler )
{
	_assert_handler = new_handler;
}


int assert_report( hash_t context, const char* condition, size_t cond_length, const char* file, size_t file_length, unsigned int line, const char* msg, size_t msg_length )
{
	static const char nocondition[] = "<Static fail>";
	static const char nofile[] = "<No file>";
	static const char nomsg[] = "<No message>";
	static const char assert_format[] = "****** ASSERT FAILED ******\nCondition: %.*s\nFile/line: %.*s : %d\n%.*s%.*s\n%.*s\n";
	string_t tracestr = { _assert_stacktrace_buffer, ASSERT_BUFFER_SIZE };
	string_t contextstr = { _assert_context_buffer, ASSERT_BUFFER_SIZE };
	string_t messagestr = { _assert_message_buffer, ASSERT_BUFFER_SIZE };

	if( !condition  ) { condition = nocondition; cond_length = sizeof( nocondition ); }
	if( !file ) { file = nofile; file_length = sizeof( nofile ); }
	if( !msg ) { msg = nomsg; msg_length = sizeof( nomsg ); }

	if( _assert_handler && ( _assert_handler != assert_report ) )
		return (*_assert_handler)( context, condition, cond_length, file, file_length, line, msg, msg_length );

#if BUILD_ENABLE_ASSERT
	contextstr = error_context_buffer( contextstr.str, contextstr.length );

	if( foundation_is_initialized() )
	{
		unsigned int num_frames = stacktrace_capture( _assert_stacktrace, ASSERT_STACKTRACE_MAX_DEPTH, ASSERT_STACKTRACE_SKIP_FRAMES );
		if( num_frames )
			tracestr = stacktrace_resolve( tracestr.str, tracestr.length, _assert_stacktrace, num_frames, 0U );
		else
			tracestr = string_copy( tracestr.str, tracestr.length, "<no stacktrace>", 15 );
	}
	else
	{
		tracestr = string_copy( tracestr.str, tracestr.length, "<no stacktrace - not initialized>", 32 );
	}

	messagestr = string_format_buffer( messagestr.str, messagestr.length, assert_format, sizeof( assert_format ),
		(int)cond_length, condition, (int)file_length, file, line,
		(int)contextstr.length, contextstr.str, (int)msg_length, msg,
		(int)tracestr.length, tracestr.str );

	log_errorf( context, ERROR_ASSERT, STRING_CONST( "%.*s" ), (int)messagestr.length, messagestr.str );

	system_message_box( STRING_CONST( "Assert Failure" ), messagestr.str, messagestr.length, false );
#else
	log_errorf( context, ERROR_ASSERT, assert_format,
		(int)condition.length, condition.str, (int)file_length, file, line,
		0, "", (int)msg.length, msg.str, 0, "" );
#endif

	return 1;
}


int assert_report_formatted( hash_t context, const char* condition, size_t cond_length, const char* file, size_t file_length, unsigned int line, const char* msg, size_t msg_length, ... )
{
	if( msg )
	{
		/*lint --e{438} Lint gets confused about assignment to ap */
		string_t buffer = { _assert_buffer, ASSERT_BUFFER_SIZE };
		va_list ap;
		va_start( ap, msg_length );
		buffer = string_vformat_buffer( buffer.str, buffer.length, msg, msg_length, ap );
		va_end( ap );
		return assert_report( context, condition, cond_length, file, file_length, line, buffer.str, buffer.length );
	}

	return assert_report( context, condition, cond_length, file, file_length, line, 0, 0 );
}
