/* main.c  -  Foundation bin2hex tool  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
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

#include "errorcodes.h"



typedef struct
{
	char**       input_files;
	char**       output_files;
} bin2hex_input_t;

static bin2hex_input_t      bin2hex_parse_command_line( const char* const* cmdline );

static int                  bin2hex_process_files( const char* const* input, const char* const* output );
static int                  bin2hex_process_file( stream_t* input, stream_t* output );


int main_initialize( void )
{
	application_t application = {0};
	application.name = "bin2hex";
	application.short_name = "bin2hex";
	application.config_dir = "bin2hex";

	return foundation_initialize( memory_system_malloc(), application );
}


int main_run( void* main_arg )
{
	int result = 0;
	bin2hex_input_t input = bin2hex_parse_command_line( environment_command_line() );

	result = bin2hex_process_files( input.input_files, input.output_files );
	if( result < 0 )
		goto exit;

exit:

	string_array_deallocate( input.input_files );
	string_array_deallocate( input.output_files );

	return result;
}


void main_shutdown( void )
{
	foundation_shutdown();
}


bin2hex_input_t bin2hex_parse_command_line( const char* const* cmdline )
{
	bin2hex_input_t input = {0};
	int arg, asize;

	error_context_push( "parsing command line", "" );
	for( arg = 1, asize = array_size( cmdline ); arg < asize; ++arg )
	{
		if( string_equal( cmdline[arg], "--" ) )
			break; //Stop parsing cmdline options

		array_push( input.input_files, string_clone( cmdline[arg] ) );
		array_push( input.output_files, string_format( "%s.hex", cmdline[arg] ) );
	}
	error_context_pop();

	return input;
}


int bin2hex_process_files( const char* const* input, const char* const* output )
{
	int result = BIN2HEX_RESULT_OK;
	unsigned int ifile, files_size;
	for( ifile = 0, files_size = array_size( input ); ( result == BIN2HEX_RESULT_OK ) && ( ifile < files_size ); ++ifile )
	{
		char* input_filename;
		char* output_filename;

		stream_t* input_file;
		stream_t* output_file;

		input_filename = path_clean( string_clone( input[ifile] ), path_is_absolute( input[ifile] ) );
		error_context_push( "parsing file", input_filename );

		output_filename = path_clean( string_clone( output[ifile] ), path_is_absolute( output[ifile] ) );

		log_infof( "bin2hex %s -> %s", input_filename, output_filename );

		input_file  = stream_open( input_filename, STREAM_IN | STREAM_BINARY );
		output_file  = stream_open( output_filename, STREAM_OUT );

		if( !input_file )
		{
			log_warnf( WARNING_BAD_DATA, "Unable to open input file: %s", input_filename );
			result = BIN2HEX_RESULT_MISSING_INPUT_FILE;
		}
		else if( !output_file )
		{
			log_warnf( WARNING_BAD_DATA, "Unable to open output file: %s", output_filename );
			result = BIN2HEX_RESULT_UNABLE_TO_OPEN_OUTPUT_FILE;
		}
		
		if( input_file && output_file )
			result = bin2hex_process_file( input_file, output_file );

		stream_deallocate( input_file );
		stream_deallocate( output_file );

		string_deallocate( input_filename );
		string_deallocate( output_filename );
	}

	if( ( result == BIN2HEX_RESULT_OK ) && ( files_size > 0 ) )
		log_infof( "All files generated" );

	return result;
}


int bin2hex_process_file( stream_t* input, stream_t* output )
{
	uint8_t block[32];
	int64_t read, byte;
	while( !stream_eos( input ) )
	{
		read = stream_read( input, block, 32 );
		if( !read )
			break;

		for( byte = 0; byte < read; ++byte )
			stream_write_format( output, "0x%02x, ", (unsigned int)block[byte] );
		stream_write_endl( output );
	}
	return BIN2HEX_RESULT_OK;
}
