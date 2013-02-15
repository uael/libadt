/* android.c  -  Foundation library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
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
#include <foundation/android.h>


#if FOUNDATION_PLATFORM_ANDROID

static struct android_app*       _android_app = 0;
static struct ASensorEventQueue* _android_sensor_queue = 0;
static bool                      _android_sensor_enabled[16] = {0};

static void _android_enable_sensor( int sensor_type );
static void _android_disable_sensor( int sensor_type );


int android_initialize( struct android_app* app )
{
	_android_app = app;
	
	app->onAppCmd = android_handle_cmd;
	app->onInputEvent = android_handle_input;
	app->userData = 0;

	//log_debugf( "Force window fullscreen" );
	//ANativeActivity_setWindowFlags( app->activity, AWINDOW_FLAG_FULLSCREEN, AWINDOW_FLAG_FORCE_NOT_FULLSCREEN );	

	log_debugf( "Waiting for application window to be set" );
	{
		int ident = 0;
		int events = 0;
		struct android_poll_source* source = 0;
		while( !app->window )
		{
			while( ( ident = ALooper_pollAll( 0, 0, &events, (void**)&source ) ) >= 0 )
			{
				// Process this event.
				if( source )
					source->process( app, source );
			}
			thread_sleep( 10 );
		}
	}
	log_debugf( "Application window set, continuing" );

	log_debugf( "Internal data path: %s", app->activity->internalDataPath );
	log_debugf( "External data path: %s", app->activity->externalDataPath );

	ASensorManager* sensor_manager = ASensorManager_getInstance();
	_android_sensor_queue = ASensorManager_createEventQueue( sensor_manager, app->looper, 0, android_sensor_callback, 0 );

	//Enable accelerometer sensor
	_android_enable_sensor( ASENSOR_TYPE_ACCELEROMETER );
}


void android_shutdown( void )
{
	log_debugf( "exiting native android app" );

	_android_app->onAppCmd = 0;
    _android_app->onInputEvent = 0;
	_android_app->userData = 0;

	if( _android_sensor_queue )
	{
		ASensorManager* sensor_manager = ASensorManager_getInstance();
		ASensorManager_destroyEventQueue( sensor_manager, _android_sensor_queue );
	}
	_android_sensor_queue = 0;

	ANativeActivity_finish( app->activity );
	{
		int ident = 0;
		int events = 0;
		struct android_poll_source* source = 0;
		while( ( ident = ALooper_pollAll( 0, 0, &events, (void**)&source ) ) >= 0 )
		{
			// Process this event.
			if( source )
				source->process( app, source );
		}
	}

	_android_app = 0;

	log_debugf( "calling exit(0)" );

	exit( 0 );
}


struct android_app* android_app( void )
{
	return _android_app;
}


void _android_enable_sensor( int sensor_type )
{
	FOUNDATION_ASSERT( sensor_type > 0 && sensor_type < 16 );
	if( _sensor_enabled[sensor_type] )
		return;

	ASensorManager* sensor_manager = ASensorManager_getInstance();
	if( sensor_manager )
	{
		const ASensor* sensor = ASensorManager_getDefaultSensor( sensor_manager, sensor_type );
		if( sensor )
		{
			log_debugf( "Initializing sensor of type %d", sensor_type );
			if( _android_sensor_queue )
			{
				if( ASensorEventQueue_enableSensor( _android_sensor_queue, sensor ) < 0 )
					log_warnf( WARNING_SYSTEM_CALL_FAIL, "Unable to enable sensor" );
				else
				{
					int min_delay = ASensor_getMinDelay( sensor );
					if( min_delay < 60000 )
						min_delay = 60000;
					if( ASensorEventQueue_setEventRate( _android_sensor_queue, sensor, min_delay ) < 0 )
						log_warnf( WARNING_SYSTEM_CALL_FAIL, "Unable to set sensor event rate" );

					_android_sensor_enabled[sensor_type] = true;
				}
			}
		}
	}
	else
	{
		log_warnf( WARNING_UNSUPPORTED, "Unable to initialize sensor, no sensor manager" );
	}
}


void _android_disable_sensor( int sensor_type )
{
	FOUNDATION_ASSERT( sensor_type > 0 && sensor_type < 16 );
	if( !_sensor_enabled[sensor_type] )
		return;

	ASensorManager* sensor_manager = ASensorManager_getInstance();
	if( _android_sensor_queue && sensor_manager )
	{
		const ASensor* sensor = ASensorManager_getDefaultSensor( sensor_manager, sensor_type );
		if( sensor )
		{
			ASensorEventQueue_disableSensor( _android_sensor_queue, sensor );
			_android_sensor_enabled[sensor_type] = false;
		}
    }
}


#endif


