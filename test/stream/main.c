/* main.c  -  Foundation stream test  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
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
#include <test/test.h>

#if FOUNDATION_PLATFORM_WINDOWS
#include <foundation/windows.h>
#endif

#if FOUNDATION_PLATFORM_POSIX
#include <foundation/posix.h>
#endif


static const char longline[] = "Lorem ipsum dolor sit amet, eam mundi concludaturque id, cu sea modus saepe postea. Purto natum vel ex, est eius possim ex, vix at sumo reformidans. Eos oratio forensibus persequeris an, diam gubergren ne mea, tacimates postulant expetenda ut pri. Vel everti facilis nominati ea, eos eu quis molestiae assueverit. His paulo utroque officiis ut, eum eu mutat congue hendrerit. Luptatum consulatu in cum, ea posse pertinax vim."
" Usu dicta audiam voluptatum in. Vis habeo molestiae rationibus ea. Paulo bonorum facilis cu quo. Sit in appetere concludaturque, ius cu zril invidunt patrioque, clita ceteros recteque sed in. Vim in graece prompta molestiae, vel enim magna ei."
" Ne qui dicant comprehensam, ipsum scriptorem mei no. Odio appareat pericula no sit. Vix ad latine persius intellegam, eam movet altera ei. Minimum copiosae has no, ne utamur aliquando eam."
" Verterem lucilius adversarium vix ne, brute laudem ex vel. Aperiri quaeque scribentur ei pri, ne mei copiosae complectitur. Ferri graece sed an. An usu etiam audire erroribus, vis commodo pertinax id."
" Dicunt inimicus ei sit. Consequat prodesset te pri, dictas vidisse fierent est et. Cu qui omittam evertitur. Vim ad vidit erant expetenda. Ex duo nibh molestiae tincidunt."
" Vel ad utroque inimicus definitionem, et posse consul aliquip per. Ne quaeque epicuri signiferumque est. Pri saepe doming partiendo ei. Ea nec vidit suscipit erroribus, odio nihil corrumpit qui ex, ne consulatu assentior pri. Eu qui dolore ubique, eos option albucius et."
" Sea recteque cotidieque ea, mei tota paulo intellegebat ei, cu eam tation partem abhorreant. Mel luptatum mnesarchum liberavisse no, quis regione detraxit nam te. Nec ad everti nonumes, euismod tincidunt duo eu. Ea illud petentium pro, ex pro soluta necessitatibus."
" Eum cu nonumes delicata, reque omnium fastidii in mel, eu eum dolore euismod. Noster insolens accusata in pri, eam dicam exerci instructior in. No posse maluisset abhorreant has, qui denique assentior ea, sea labore legendos vituperata te. Facer scripserit vis in."
" Verterem mnesarchum scriptorem eam ex, pro semper theophrastus id. Sit ex inani iuvaret interpretaris, rebum labores consulatu te qui. Eu errem perpetua nam. Veniam elaboraret vel eu. Cum tation semper ex."
" Illud eirmod ius at. Soleat animal eripuit mei ea, duo nominavi adipiscing eu. Utroque voluptatum no nam. Usu omnesque iracundia ad."
" Magna detraxit ex nec, et nec impedit civibus scribentur. Sea et nibh appareat, postea sadipscing signiferumque an vim, alii vidisse qualisque eos ei. Nisl mnesarchum ad cum. Sint esse causae ius ex, scripta omittam probatus vix cu, legere persequeris ea mea."
" Ad vel iriure propriae, et cum eripuit partiendo assueverit. Vix an velit dolorum prodesset, usu at utinam partem. Ius vide veniam tempor cu. Ut electram hendrerit est, est altera verterem in. Ius audire definiebas ea, eos ea semper moderatius intellegebat, his ei ludus libris fabellas. Vix cu malorum voluptaria, ne vix nostrum pericula persequeris."
" Cum habemus fuisset delectus at. Vix dicta inani omnes ea, graecis offendit evertitur cu mel, no offendit oporteat mea. An alterum facilisis qui. Sed dicta mundi ubique cu, cu sonet everti regione vix. Qui intellegat adolescens at, ipsum tation interpretaris usu an, natum suscipit sadipscing est et. Mea esse scripta antiopam in, adhuc appetere moderatius mei eu."
" Augue populo at mei, hinc graece qui id, cu cum summo epicurei intellegam. At vim habeo ullum labitur, in est aliquam fierent legendos, ne eam homero dolorem. Quo eu partiendo patrioque eloquentiam. Sonet prodesset posidonium mei ea, an mei vidit definiebas vituperata. Ne doming ullamcorper vim, et purto sale dicunt sit. Id legere perpetua est, mel cu erant petentium deterruisset. Ei eos errem vitae feugiat, te brute luptatum scripserit sit, per lorem persius ea."
" In quo doctus invenire. Eos ancillae definiebas interesset at. Primis mucius mel ad, ea audiam nominavi has, veniam fuisset ei mei. Ut clita affert aliquando pro, no quem vero sea. Quas ridens dissentiunt ius ne, eos rationibus incorrupte ex, sea ei aperiri constituto."
" Sit at detracto appetere, ut ius hinc vulputate. Et veniam populo reformidans vel, eum at nisl essent apeirian. Per iudicabit definitiones id, pertinax electram in sea, pro modo meis epicuri ea. Aliquando contentiones definitionem in ius, nec novum laoreet at, sonet quaerendum in qui."
" Consulatu similique gloriatur ei vis. An quis temporibus usu, at sed ipsum discere. Te equidem laoreet suavitate mel, an ponderum deseruisse sea. Dico omittam ius ex. Quaeque incorrupte quo ea, causae qualisque ocurreret eu duo, exerci laboramus sed ei."
" Vis solet torquatos ex, qui clita offendit ex, an consul moderatius conclusionemque vix. Eam oratio option in, per et unum fierent scripserit. Ea duo dicat omittantur. Ea unum debet noster est, mel putent laboramus in."
" Vel purto indoctum an, tincidunt vituperata interpretaris an sit. Mei nostro graecis no, cu putant torquatos eos. Iuvaret mediocrem vix et. Esse commune suavitate ea qui, mea ut veri solet fuisset, in eros ludus accommodare eum. Qui novum nemore maiorum te, cu pertinax disputationi est. Torquatos democritum assueverit ad vim, quo clita corrumpit cu."
" Esse possim ea has, option iracundia te nec, sea ei agam nostrud. Postea ancillae nominavi id vis, in sed liber dicant sensibus. Ut gubergren euripidis mnesarchum qui, habeo incorrupte ea mel. Vix ad enim ipsum concludaturque, has homero ignota pertinacia an, prima atomorum intellegebat cu sea."
" Est ea altera prompta mediocritatem, ne quis omnis quo. Labore utamur pro in, mea te justo facete. Vim et mucius habemus delicata. Eum graece fierent propriae an. At vel solet dolores, justo zril cu est."
" Case facer ad nec. Cum quod posse impetus et. Mazim alterum tacimates eum ea. Has graeci scribentur accommodare et."
" Usu euismod invidunt lucilius ex, ornatus appareat has ut, ferri noster tamquam sit te. Autem illum quaestio vel ex, illum assum tractatos mea eu. In admodum singulis consetetur pro, unum etiam fabellas in eum, no mollis volutpat his. Prima placerat mediocrem has id. Qui novum zril liberavisse in, id petentium necessitatibus sed. Vim discere sententiae et."
" Mei cu eius accusamus forensibus. Ubique principes at ius, ei quem eros sea. Ne sea nisl malorum instructior, affert pericula intellegebat has cu. Everti commodo eos ad."
" Nostro labitur aliquando ei his, erant dignissim vis ea. Reque populo sapientem ne mea, aeque appareat eloquentiam no pro. Et his sensibus assentior. Quo et fierent nominati, sed inani causae animal et, cum ex nulla paulo facilisis. Et vim fabulas impedit, porro consul delenit vel et. Graecis prodesset eam at. Usu at modus quidam incorrupte."
" Ad vim convenire molestiae. Sed in oporteat salutatus, te mazim erroribus principes ius, tempor hendrerit sed te. Ea mundi omittantur sit. Nec illum impetus forensibus te, odio percipit constituto nam ex, ei iusto sententiae voluptatibus nec. Est iudico possit omittam cu."
" Mea electram efficiendi id. Ne ius idque ornatus persecuti, est ei rebum legimus hendrerit. Sit ea noluisse accusamus scripserit, ne dignissim consequuntur concludaturque ius. Elit mandamus intellegam per ne, adolescens referrentur pro et, pri veritus appareat abhorreant no. Mentitum posidonium ex cum, his stet sale atomorum ut. Fabellas platonem at vis. Eu mel doming impetus honestatis."
" Ut has putant causae debitis, id duo mutat velit, facete offendit sit te. Vitae singulis suscipiantur mea cu, ei est graece signiferumque. Cum petentium sententiae ne. Has ea quas omnes, magna illum augue vix et, quot delectus perfecto usu eu. Pro natum voluptua euripidis te."
" Audiam latine cu eum, has no diceret mentitum constituam. An vim elit maiestatis. Ei dicam epicurei disputando per, an modus meliore civibus per, id mazim iisque delenit eum. No duo nonumy singulis, debet facilisi pri ut. Facer utinam nec at. Dolores phaedrum at per, inciderint neglegentur delicatissimi et duo."
" Mollis fabellas legendos in mel. Duo ei congue appareat consetetur, qui cu expetenda repudiandae. Delenit veritus admodum id nec, luptatum inimicus postulant qui eu. Interesset conclusionemque no vix, eu eius iudico mentitum pri. Usu ut sumo rationibus, etiam iisque conceptam vis at. Blandit consetetur ea duo, mea possit petentium euripidis no, habeo legimus in his."
" Duo quas perfecto ne, odio iriure in usu. Vix no ponderum intellegat, eam lorem vidisse no. In nominati convenire petentium usu, eu vero ullum ignota his. Ne rebum diceret dissentiet per, per ne putent placerat, minimum dolores ullamcorper ex mei. Dignissim appellantur id nam, cu lucilius inimicus eum. Est tantas causae intellegat ut, dicta pericula definitiones eam in, eum modus omnesque delectus ea."
" Ei deleniti phaedrum eum, pertinax comprehensam sea cu. Ut graeco alienum singulis ius, te veri luptatum convenire has. Perfecto torquatos eu eum. Verterem neglegentur ius eu. Eum an ridens feugait adversarium, per saepe singulis euripidis et. Nam periculis corrumpit at, eam cu omnes quodsi, ei mel explicari aliquando."
" Vix ea erant iusto, porro incorrupte at per. An mel quodsi constituto, ex usu sonet verterem. Enim sale temporibus cum ad, an mea oporteat pertinacia. Id vim saepe aeterno, te ullum salutandi mea. Ea integre admodum assueverit mel. Ei ullum consul cotidieque vix."
" Eu laudem fastidii recteque usu, docendi democritum delicatissimi sed eu. Has te scripta impedit feugait, et mea aeterno nostrud, sed copiosae partiendo sadipscing at. Erant ridens sententiae per in, ut solum posse propriae vim, sed ut wisi denique. Cu eam movet quodsi neglegentur, choro cetero menandri ex eum."
" Pri malorum fabulas ne. Ex ullum omnes tollit per, dicit antiopam pro ut. Pri ex labore tamquam complectitur, rebum impetus gubergren eos at. Sed id quod tibique, ei quo decore tractatos inciderint, nobis iriure efficiantur at qui. Partem democritum philosophia mea ut, ex senserit repudiandae vix. Ea mel assum regione petentium, alia vide ex vel. Has ei brute dicunt similique, eu pri soleat tamquam."
" Qui cu aperiam tibique verterem, no eam equidem voluptua accusata, nostro omnium suscipit qui ei. Mei ne vidisse indoctum. Iuvaret dolorum cu mei, dolor iudicabit ei mei. Cu unum ubique efficiendi quo, accommodare interpretaris ut sea. Commodo intellegat ex mea, tota postulant conceptam eam et.";
static const unsigned int longlength = sizeof( longline );


static application_t test_stream_application( void )
{
	application_t app;
	memset( &app, 0, sizeof( app ) );
	app.name = "Foundation stream tests";
	app.short_name = "test_stream";
	app.config_dir = "test_stream";
	app.flags = APPLICATION_UTILITY;
	app.dump_callback = test_crash_handler;
	return app;
}


static memory_system_t test_stream_memory_system( void )
{
	return memory_system_malloc();
}


static int test_stream_initialize( void )
{
	return 0;
}


static void test_stream_shutdown( void )
{
}


DECLARE_TEST( stream, std )
{
	tick_t now;
	stream_t* in;
	stream_t* out;
	stream_t* err;
	stream_t* in_clone;
	stream_t* out_clone;
	stream_t* err_clone;

	in = stream_open( "stdin://", STREAM_OUT | STREAM_IN | STREAM_BINARY );
	out = stream_open( "stdout://", STREAM_OUT | STREAM_IN );
	err = stream_open( "stderr://", STREAM_OUT | STREAM_IN | STREAM_BINARY );

	EXPECT_NE_MSG( in, 0, "Failed to open stdin://" );
	EXPECT_NE_MSG( out, 0, "Failed to open stdout://" );
	EXPECT_NE_MSG( err, 0, "Failed to open stderr://" );

	EXPECT_NE_MSG( in, 0, "Failed to open stdin://" );
	EXPECT_NE_MSG( out, 0, "Failed to open stdout://" );
	EXPECT_NE_MSG( err, 0, "Failed to open stderr://" );

	EXPECT_EQ_MSG( stream_tell( in ), 0, "stdin pos is not 0");
	EXPECT_EQ_MSG( stream_tell( out ), 0, "stdout pos is not 0");
	EXPECT_EQ_MSG( stream_tell( err ), 0, "stderr pos is not 0");

	stream_seek( in, 1, STREAM_SEEK_BEGIN );
	stream_seek( out, 1, STREAM_SEEK_CURRENT );
	stream_seek( err, 1, STREAM_SEEK_END );

	EXPECT_EQ_MSG( stream_tell( in ), 0, "stdin pos is not 0");
	EXPECT_EQ_MSG( stream_tell( out ), 0, "stdout pos is not 0");
	EXPECT_EQ_MSG( stream_tell( err ), 0, "stderr pos is not 0");

	EXPECT_EQ_MSG( stream_eos( in ), false, "stdin at eos" );
	EXPECT_EQ_MSG( stream_eos( out ), false, "stdout at eos" );
	EXPECT_EQ_MSG( stream_eos( err ), false, "stderr at eos" );

	EXPECT_EQ_MSG( stream_size( in ), 0, "stdin size is not 0");
	EXPECT_EQ_MSG( stream_size( out ), 0, "stdout size is not 0");
	EXPECT_EQ_MSG( stream_size( err ), 0, "stderr size is not 0");

	EXPECT_EQ_MSG( stream_is_binary( in ), true, "stdin did not preserve binary mode" );
	EXPECT_EQ_MSG( stream_is_binary( out ), false, "stdout did not preserve ascii mode" );
	EXPECT_EQ_MSG( stream_is_binary( err ), true, "stderr did not preserve binary mode" );

	EXPECT_EQ_MSG( stream_is_sequential( in ), true, "stdin not sequential" );
	EXPECT_EQ_MSG( stream_is_sequential( out ), true, "stdout not sequential" );
	EXPECT_EQ_MSG( stream_is_sequential( err ), true, "stderr not sequential" );

	EXPECT_EQ_MSG( stream_is_reliable( in ), true, "stdin not reliable" );
	EXPECT_EQ_MSG( stream_is_reliable( out ), true, "stdout not reliable" );
	EXPECT_EQ_MSG( stream_is_reliable( err ), true, "stderr not reliable" );

	EXPECT_EQ_MSG( stream_is_inorder( in ), true, "stdin not inorder" );
	EXPECT_EQ_MSG( stream_is_inorder( out ), true, "stdout not inorder" );
	EXPECT_EQ_MSG( stream_is_inorder( err ), true, "stderr not inorder" );

	EXPECT_EQ_MSG( stream_is_swapped( in ), false, "stdin is swapped" );
	EXPECT_EQ_MSG( stream_is_swapped( out ), false, "stdout is swapped" );
	EXPECT_EQ_MSG( stream_is_swapped( err ), false, "stderr is swapped" );

	EXPECT_EQ_MSG( stream_byteorder( in ), system_byteorder(), "stdin not native byteorder" );
	EXPECT_EQ_MSG( stream_byteorder( out ), system_byteorder(), "stdout not native byteorder" );
	EXPECT_EQ_MSG( stream_byteorder( err ), system_byteorder(), "stderr not native byteorder" );

	stream_set_byteorder( in, BYTEORDER_LITTLEENDIAN );
	stream_set_byteorder( out, BYTEORDER_LITTLEENDIAN );
	stream_set_byteorder( err, BYTEORDER_LITTLEENDIAN );

	EXPECT_EQ_MSG( stream_byteorder( in ), BYTEORDER_LITTLEENDIAN, "stdin not little endian after explicit set" );
	EXPECT_EQ_MSG( stream_byteorder( out ), BYTEORDER_LITTLEENDIAN, "stdout not little endian after explicit set" );
	EXPECT_EQ_MSG( stream_byteorder( err ), BYTEORDER_LITTLEENDIAN, "stderr not little endian after explicit set" );

	stream_set_byteorder( in, BYTEORDER_BIGENDIAN );
	stream_set_byteorder( out, BYTEORDER_BIGENDIAN );
	stream_set_byteorder( err, BYTEORDER_BIGENDIAN );

	EXPECT_EQ_MSG( stream_byteorder( in ), BYTEORDER_BIGENDIAN, "stdin not big endian after explicit set" );
	EXPECT_EQ_MSG( stream_byteorder( out ), BYTEORDER_BIGENDIAN, "stdout not big endian after explicit set" );
	EXPECT_EQ_MSG( stream_byteorder( err ), BYTEORDER_BIGENDIAN, "stderr not big endian after explicit set" );

	stream_set_binary( in, true );
	stream_set_binary( out, true );
	stream_set_binary( err, true );

	EXPECT_EQ_MSG( stream_is_binary( in ), true, "stdin did not set binary mode" );
	EXPECT_EQ_MSG( stream_is_binary( out ), true, "stdout did not set binary mode" );
	EXPECT_EQ_MSG( stream_is_binary( err ), true, "stderr did not set binary mode" );

	stream_set_binary( in, false );
	stream_set_binary( out, false );
	stream_set_binary( err, false );

	EXPECT_EQ_MSG( stream_is_binary( in ), false, "stdin did not set ascii mode" );
	EXPECT_EQ_MSG( stream_is_binary( out ), false, "stdout did not set asii mode" );
	EXPECT_EQ_MSG( stream_is_binary( err ), false, "stderr did not set ascii mode" );

	EXPECT_STREQ_MSG( stream_path( in ), "stdin://", "stdin has wrong path" );
	EXPECT_STREQ_MSG( stream_path( out ), "stdout://", "stdout has wrong path" );
	EXPECT_STREQ_MSG( stream_path( err ), "stderr://", "stderr has wrong path" );

	now = time_system();

	EXPECT_GE_MSG( stream_last_modified( in ), now, "stdin has noncurrent last modification" );
	EXPECT_GE_MSG( stream_last_modified( out ), now, "stdout has noncurrent last modification" );
	EXPECT_GE_MSG( stream_last_modified( err ), now, "stderr has noncurrent last modification" );

	stream_set_binary( in, true );
	stream_set_byteorder( out, BYTEORDER_LITTLEENDIAN );

	in_clone = stream_clone( in );
	out_clone = stream_clone( out );
	err_clone = stream_clone( err );

	EXPECT_NE_MSG( in_clone, 0, "Clone stdin stream returned null" );
	EXPECT_NE_MSG( out_clone, 0, "Clone stdout stream returned null" );
	EXPECT_NE_MSG( err_clone, 0, "Clone stderr stream returned null" );

	EXPECT_STREQ_MSG( stream_path( in_clone ), "stdin://", "stdin clone has wrong path" );
	EXPECT_STREQ_MSG( stream_path( out_clone ), "stdout://", "stdout clone has wrong path" );
	EXPECT_STREQ_MSG( stream_path( err_clone ), "stderr://", "stderr clone has wrong path" );

	EXPECT_EQ_MSG( stream_is_binary( in_clone ), stream_is_binary( in ), "stdin did not preserve mode" );
	EXPECT_EQ_MSG( stream_is_binary( out_clone ), stream_is_binary( out ), "stdout clone did not preserve mode" );
	EXPECT_EQ_MSG( stream_is_binary( err_clone ), stream_is_binary( err ), "stderr did not preserve mode" );

	EXPECT_EQ_MSG( stream_byteorder( in_clone ), stream_byteorder( in ), "stdin did not preserve byte order" );
	EXPECT_EQ_MSG( stream_byteorder( out_clone ), stream_byteorder( out ), "stdout clone did not preserve byte order" );
	EXPECT_EQ_MSG( stream_byteorder( err_clone ), stream_byteorder( err ), "stderr did not preserve byte order" );

	stream_seek( in_clone, 1, STREAM_SEEK_BEGIN );
	stream_seek( out_clone, 1, STREAM_SEEK_CURRENT );
	stream_seek( err_clone, 1, STREAM_SEEK_END );

	EXPECT_EQ_MSG( stream_tell( in_clone ), 0, "stdin clone pos is not 0");
	EXPECT_EQ_MSG( stream_tell( out_clone ), 0, "stdout clone pos is not 0");
	EXPECT_EQ_MSG( stream_tell( err_clone ), 0, "stderr clone pos is not 0");

	EXPECT_EQ_MSG( stream_eos( in_clone ), false, "stdin clone at eos" );
	EXPECT_EQ_MSG( stream_eos( out_clone ), false, "stdout clone at eos" );
	EXPECT_EQ_MSG( stream_eos( err_clone ), false, "stderr clone at eos" );

	EXPECT_EQ_MSG( stream_size( in_clone ), 0, "stdin clone size is not 0");
	EXPECT_EQ_MSG( stream_size( out_clone ), 0, "stdout clone size is not 0");
	EXPECT_EQ_MSG( stream_size( err_clone ), 0, "stderr clone size is not 0");

	stream_deallocate( in_clone );
	stream_deallocate( out_clone );
	stream_deallocate( err_clone );

	stream_buffer_read( in );
	stream_buffer_read( out );
	stream_buffer_read( err );

	//EXPECT_GE_MSG( stream_available_read( in ), 0, "stdin invalid value for available bytes to read" );
	EXPECT_EQ_MSG( stream_available_read( out ), 0, "stdout not empty as expected" );
	EXPECT_EQ_MSG( stream_available_read( err ), 0, "stderr not empty as expected" );

	EXPECT_EQ_MSG( uint128_is_null( stream_md5( in ) ), true, "stdin md5 not null" );
	EXPECT_EQ_MSG( uint128_is_null( stream_md5( out ) ), true, "stdout md5 not null" );
	EXPECT_EQ_MSG( uint128_is_null( stream_md5( err ) ), true, "stderr md5 not null" );

	stream_truncate( in, 256 );
	stream_truncate( out, 256 );
	stream_truncate( err, 256 );

	stream_flush( in );
	stream_flush( out );
	stream_flush( err );

	//EXPECT_GE_MSG( stream_available_read( in ), 0, "stdin invalid value for available bytes to read" );
	EXPECT_EQ_MSG( stream_available_read( out ), 0, "stdout not empty as expected" );
	EXPECT_EQ_MSG( stream_available_read( err ), 0, "stderr not empty as expected" );

	//Verify that eos is set when stdin is closed
#if FOUNDATION_PLATFORM_WINDOWS
	CloseHandle( GetStdHandle( STD_INPUT_HANDLE ) );
#elif FOUNDATION_PLATFORM_POSIX
	close( STDIN_FILENO );
#else
#  error Not implemented
#endif
	EXPECT_EQ_MSG( stream_read_int8( in ), 0, "stdin read when closed did not return 0" );
	EXPECT_EQ_MSG( stream_eos( in ), true, "stdin not at eos when closed" );

	stream_deallocate( in );
	stream_deallocate( out );
	stream_deallocate( err );

	return 0;
}


DECLARE_TEST( stream, readwrite_binary )
{
	char write_buffer[1024];
	char read_buffer[1024];
	stream_t* teststream;
	char* path;
	char* directory;
	char* line;
	int i;
	uint64_t was_read;

	path = path_make_temporary();
	directory = path_directory_name( path );
	fs_make_directory( directory );

	teststream = stream_open( path, STREAM_IN | STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );
	stream_write_string( teststream, 0 );

	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 43 + 45 + 40 + FOUNDATION_SIZE_POINTER*2 + 1, "stream position not expected after writes (%lld)", stream_tell( teststream ) );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	read_buffer[0] = 123;
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSG( read_buffer[0], 123, "buffer modified when reading zero bytes" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 1, "read one byte failed" );
	EXPECT_EQ_MSG( read_buffer[0], write_buffer[0], "data not read correctly when reading one byte" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 1024, "read 1024 bytes failed" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSGFORMAT( read_buffer[i], write_buffer[i], "data not read correctly in pos %d when reading 1024 bytes", i );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), true, "read boolean failed" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 127, "read int8 failed" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 178, "read uint8 failed" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), -1234, "read int16 failed" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 45678, "read uint16 failed" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), -1324567, "read int32 failed" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 3245678U, "read uint32 failed" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 123456789012LL, "read int64 failed" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 8712634987126ULL, "read uint64 failed" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 1.0f, "read float32 failed" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), -1.0, "read float64 failed" );

	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 11, "read line buffer failed" );
	EXPECT_STREQ_MSG( read_buffer, "test string", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_NE_MSG( line, 0, "read line failed" );
	EXPECT_STREQ_MSG( line, "with some newlines", "read line failed data" );
	string_deallocate( line );

	line = stream_read_string( teststream );
	EXPECT_NE_MSG( line, 0, "read string failed" );
	EXPECT_STREQ_MSG( line, "in the string", "read string failed data" );
	string_deallocate( line );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 39 + FOUNDATION_SIZE_POINTER*2, "read string buffer failed (%lld)", was_read );
#if FOUNDATION_SIZE_POINTER == 8
	EXPECT_STREQ_MSG( read_buffer, "formatted output with a null pointer 0x0000000000000000", "read string buffer data failed" );
#else
	EXPECT_STREQ_MSG( read_buffer, "formatted output with a null pointer 0x00000000", "read string buffer data failed" );
#endif

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "Read empty string did not return null" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSGFORMAT( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer failed at end of stream, read %s", read_buffer );

	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	stream_determine_binary_mode( teststream, 1024 );
	EXPECT_EQ_MSG( stream_is_binary( teststream ), true, "Binary mode was not detected" );
	stream_seek( teststream, -34, STREAM_SEEK_END ); //There is a terminating zeros at end
	stream_determine_binary_mode( teststream, 32 );
	EXPECT_EQ_MSG( stream_is_binary( teststream ), false, "Text mode was not detected" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_IN | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 0, "write one bytes failed (wrote in read-only stream)" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 0, "write 1024 bytes failed (wrote in read-only stream)" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after writes" );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after seek" );

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 43 + 45 + 40 + FOUNDATION_SIZE_POINTER*2, "stream position not expected after writes (%lld)", stream_tell( teststream ) );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	string_deallocate( path );
	string_deallocate( directory );

	return 0;
}


DECLARE_TEST( stream, readwrite_text )
{
	char write_buffer[1024];
	char read_buffer[1024];
	stream_t* teststream;
	char* path;
	char* directory;
	char* line;
	int i;
	uint64_t was_read;

	path = path_make_temporary();
	directory = path_directory_name( path );
	fs_make_directory( directory );

	teststream = stream_open( path, STREAM_IN | STREAM_OUT | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	//Make sure byte swap does not affect text mode
	stream_set_byteorder( teststream, ( system_byteorder() == BYTEORDER_LITTLEENDIAN ) ? BYTEORDER_BIGENDIAN : BYTEORDER_LITTLEENDIAN );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, true ); stream_write_endl( teststream );
	stream_write_int8( teststream, 127 ); stream_write_endl( teststream );
	stream_write_uint8( teststream, 178 ); stream_write_endl( teststream );
	stream_write_int16( teststream, -1234 ); stream_write_endl( teststream );
	stream_write_uint16( teststream, 45678 ); stream_write_endl( teststream );
	stream_write_int32( teststream, -1324567 ); stream_write_endl( teststream );
	stream_write_uint32( teststream, 3245678U ); stream_write_endl( teststream );
	stream_write_int64( teststream, 123456789012LL ); stream_write_endl( teststream );
	stream_write_uint64( teststream, 8712634987126ULL ); stream_write_endl( teststream );
	stream_write_float32( teststream, 1.0f ); stream_write_endl( teststream );
	stream_write_float64( teststream, -1.0 ); stream_write_endl( teststream );
	stream_write_string( teststream,  "test string\nwith some newlines\nin the string" ); stream_write_endl( teststream );
	stream_write_format( teststream,  "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 ); stream_write_endl( teststream );

	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 74 + 45 + 40 + FOUNDATION_SIZE_POINTER*2, "stream position not expected after writes (%lld) : %s", stream_tell( teststream ), stream_path( teststream ) );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	read_buffer[0] = 123;
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSG( read_buffer[0], 123, "buffer modified when reading zero bytes" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 1, "read one byte failed" );
	EXPECT_EQ_MSG( read_buffer[0], write_buffer[0], "data not read correctly when reading one byte" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 1024, "read 1024 bytes failed" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSGFORMAT( read_buffer[i], write_buffer[i], "data not read correctly in pos %d when reading 1024 bytes", i );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), true, "read boolean failed" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 127, "read int8 failed" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 178, "read uint8 failed" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), -1234, "read int16 failed" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 45678, "read uint16 failed" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), -1324567, "read int32 failed" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 3245678U, "read uint32 failed" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 123456789012LL, "read int64 failed" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 8712634987126ULL, "read uint64 failed" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 1.0f, "read float32 failed" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), -1.0, "read float64 failed" );

	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 11, "read line buffer failed" );
	EXPECT_STREQ_MSG( read_buffer, "test string", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_NE_MSG( line, 0, "read line failed" );
	EXPECT_STREQ_MSG( line, "with some newlines", "read line failed data" );
	string_deallocate( line );

	line = stream_read_string( teststream );
	EXPECT_NE_MSG( line, 0, "read string failed" );
	EXPECT_STREQ_MSG( line, "in", "read string failed data" );
	string_deallocate( line );

	line = stream_read_line( teststream, '\n' );
	EXPECT_NE_MSG( line, 0, "read line failed" );
	EXPECT_STREQ_MSG( line, "the string", "read line failed data" );
	string_deallocate( line );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 9, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "formatted", "read string buffer data failed" );

	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 29 + FOUNDATION_SIZE_POINTER*2, "read line buffer failed" );
#if FOUNDATION_SIZE_POINTER == 8
	EXPECT_STREQ_MSG( read_buffer, "output with a null pointer 0x0000000000000000", "read string buffer data failed" );
#else
	EXPECT_STREQ_MSG( read_buffer, "output with a null pointer 0x00000000", "read string buffer data failed" );
#endif

	read_buffer[0] = 0;
	EXPECT_EQ_MSGFORMAT( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer failed at end of stream, read %s", read_buffer );

	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	stream_determine_binary_mode( teststream, 1024 );
	EXPECT_EQ_MSG( stream_is_binary( teststream ), true, "Binary mode was not detected" );
	stream_seek( teststream, -32, STREAM_SEEK_END );
	stream_determine_binary_mode( teststream, 32 );
	EXPECT_EQ_MSG( stream_is_binary( teststream ), false, "Text mode was not detected" );

	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	EXPECT_EQ_MSG( stream_write( teststream, longline, longlength ), longlength, "Failed to write long line data to stream" );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_STREQ_MSG( line, longline, "Long line read failed data" );
	string_deallocate( line );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_IN | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 0, "write one bytes failed (wrote in read-only stream)" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 0, "write 1024 bytes failed (wrote in read-only stream)" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after writes" );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after seek" );

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 43 + 45 + 40 + FOUNDATION_SIZE_POINTER*2, "stream position not expected after writes (%lld)", stream_tell( teststream ) );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	string_deallocate( path );
	string_deallocate( directory );

	return 0;
}


DECLARE_TEST( stream, readwrite_sequential )
{
	char write_buffer[1024];
	char read_buffer[1024];
	stream_t* teststream;
	char* path;
	char* directory;
	char* line;
	int i;
	uint64_t was_read;

	path = path_make_temporary();
	directory = path_directory_name( path );
	fs_make_directory( directory );

	teststream = stream_open( path, STREAM_IN | STREAM_OUT | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	teststream->sequential = 1;

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, false ); stream_write_endl( teststream );
	stream_write_int8( teststream, 127 ); stream_write_endl( teststream );
	stream_write_uint8( teststream, 178 ); stream_write_endl( teststream );
	stream_write_int16( teststream, -1234 ); stream_write_endl( teststream );
	stream_write_uint16( teststream, 45678 ); stream_write_endl( teststream );
	stream_write_int32( teststream, -1324567 ); stream_write_endl( teststream );
	stream_write_uint32( teststream, 3245678U ); stream_write_endl( teststream );
	stream_write_int64( teststream, 123456789012LL ); stream_write_endl( teststream );
	stream_write_uint64( teststream, 8712634987126ULL ); stream_write_endl( teststream );
	stream_write_float32( teststream, 1.0f ); stream_write_endl( teststream );
	stream_write_float64( teststream, -1.0 ); stream_write_endl( teststream );
	stream_write_string( teststream,  "test string\nwith some newlines\nin the string" ); stream_write_endl( teststream );
	stream_write_format( teststream,  "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 ); stream_write_endl( teststream );

	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 75 + 45 + 40 + FOUNDATION_SIZE_POINTER*2, "stream position not expected after writes (%lld) : %s", stream_tell( teststream ), stream_path( teststream ) );
	teststream->sequential = 0;
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	teststream->sequential = 1;

	read_buffer[0] = 123;
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSG( read_buffer[0], 123, "buffer modified when reading zero bytes" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 1, "read one byte failed" );
	EXPECT_EQ_MSG( read_buffer[0], write_buffer[0], "data not read correctly when reading one byte" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 1024, "read 1024 bytes failed" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSGFORMAT( read_buffer[i], write_buffer[i], "data not read correctly in pos %d when reading 1024 bytes", i );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean failed" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 127, "read int8 failed" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 178, "read uint8 failed" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), -1234, "read int16 failed" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 45678, "read uint16 failed" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), -1324567, "read int32 failed" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 3245678U, "read uint32 failed" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 123456789012LL, "read int64 failed" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 8712634987126ULL, "read uint64 failed" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 1.0f, "read float32 failed" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), -1.0, "read float64 failed" );

	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 11, "read line buffer failed" );
	EXPECT_STREQ_MSG( read_buffer, "test string", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_NE_MSG( line, 0, "read line failed" );
	EXPECT_STREQ_MSG( line, "with some newlines", "read line failed data" );
	string_deallocate( line );

	line = stream_read_string( teststream );
	EXPECT_NE_MSG( line, 0, "read string failed" );
	EXPECT_STREQ_MSG( line, "in", "read string failed data" );
	string_deallocate( line );

	line = stream_read_line( teststream, '\n' );
	EXPECT_NE_MSG( line, 0, "read line failed" );
	EXPECT_STREQ_MSG( line, "the string", "read line failed data" );
	string_deallocate( line );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 9, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "formatted", "read string buffer data failed" );

	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 29 + FOUNDATION_SIZE_POINTER*2, "read line buffer failed" );
#if FOUNDATION_SIZE_POINTER == 8
	EXPECT_STREQ_MSG( read_buffer, "output with a null pointer 0x0000000000000000", "read string buffer data failed" );
#else
	EXPECT_STREQ_MSG( read_buffer, "output with a null pointer 0x00000000", "read string buffer data failed" );
#endif

	read_buffer[0] = 0;
	EXPECT_EQ_MSGFORMAT( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer failed at end of stream, read %s", read_buffer );

	teststream->sequential = 0;
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	teststream->sequential = 1;

	EXPECT_EQ_MSG( stream_write( teststream, longline, longlength ), longlength, "Failed to write long line data to stream" );
	teststream->sequential = 0;
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	teststream->sequential = 1;

	line = stream_read_line( teststream, '\n' );
	EXPECT_STREQ_MSG( line, longline, "Long line read failed data" );
	string_deallocate( line );

	teststream->sequential = 0;
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	teststream->sequential = 1;
	stream_set_binary( teststream, true );
	stream_determine_binary_mode( teststream, 1024 );
	EXPECT_EQ_MSG( stream_is_binary( teststream ), true, "Text mode was detected even if stream is sequential, expected to fail" );
	stream_set_binary( teststream, false );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_IN | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 0, "write one bytes failed (wrote in read-only stream)" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 0, "write 1024 bytes failed (wrote in read-only stream)" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	teststream->sequential = 0;
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after writes" );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position in read-only stream not null after seek" );
	teststream->sequential = 1;

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	for( i = 0; i < 1024; ++i )
		write_buffer[i] = (char)( i + 63 );

	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 0 ), 0, "write zero bytes failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1 ), 1, "write one byte failed" );
	EXPECT_EQ_MSG( stream_write( teststream, write_buffer, 1024 ), 1024, "write 1024 bytes failed" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, 127 );
	stream_write_uint8( teststream, 178 );
	stream_write_int16( teststream, -1234 );
	stream_write_uint16( teststream, 45678 );
	stream_write_int32( teststream, -1324567 );
	stream_write_uint32( teststream, 3245678U );
	stream_write_int64( teststream, 123456789012LL );
	stream_write_uint64( teststream, 8712634987126ULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );
	stream_write_string( teststream, "test string\nwith some newlines\nin the string" );
	stream_write_endl( teststream );
	stream_write_format( teststream, "formatted output with a null pointer 0x%" PRIfixPTR, (void*)0 );

	teststream->sequential = 0;
	EXPECT_EQ_MSGFORMAT( stream_tell( teststream ), 1025 + 43 + 45 + 40 + FOUNDATION_SIZE_POINTER*2, "stream position not expected after writes (%lld)", stream_tell( teststream ) );
	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	teststream->sequential = 1;

	for( i = 0; i < 1024; ++i )
		read_buffer[i] = (char)( i + 79 );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 0 ), 0, "read zero bytes failed" );
	EXPECT_EQ_MSGFORMAT( read_buffer[0], 79, "buffer modified when reading zero bytes (%d)", (int)read_buffer[0] );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1 ), 0, "read one byte from read-only stream did not fail as expected" );
	EXPECT_EQ_MSG( read_buffer[0], 79, "buffer modified when reading from zero size read-only stream" );
	EXPECT_EQ_MSG( stream_read( teststream, read_buffer, 1024 ), 0, "read 1024 bytes from read-only stream did not fail as expected" );
	for( i = 0; i < 1024; ++i )
		EXPECT_EQ_MSG( read_buffer[i], (char)( i + 79 ), "buffer modified when reading from zero size read-only stream" );

	EXPECT_EQ_MSG( stream_read_bool( teststream ), false, "read boolean did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int8( teststream ), 0, "read int8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint8( teststream ), 0, "read uint8 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int16( teststream ), 0, "read int16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint16( teststream ), 0, "read uint16 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int32( teststream ), 0, "read int32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint32( teststream ), 0, "read uint32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_int64( teststream ), 0, "read int64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_uint64( teststream ), 0, "read uint64 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float32( teststream ), 0, "read float32 did not fail as expected" );
	EXPECT_EQ_MSG( stream_read_float64( teststream ), 0, "read float64 did not fail as expected" );

	read_buffer[0] = 0;
	EXPECT_EQ_MSG( stream_read_line_buffer( teststream, read_buffer, 1024, '\n' ), 0, "read line buffer did not fail as expected" );
	EXPECT_STREQ_MSG( read_buffer, "", "read line buffer failed data" );

	line = stream_read_line( teststream, '\n' );
	EXPECT_EQ_MSG( line, 0, "read line did not fail as expected" );

	line = stream_read_string( teststream );
	EXPECT_EQ_MSG( line, 0, "read string did not fail as expected" );

	read_buffer[0] = 0;
	was_read = stream_read_string_buffer( teststream, read_buffer, 1024 );
	EXPECT_EQ_MSGFORMAT( was_read, 0, "read string buffer failed (%lld)", was_read );
	EXPECT_STREQ_MSG( read_buffer, "", "read string buffer data failed" );

	stream_deallocate( teststream );
	fs_remove_file( path );

	string_deallocate( path );
	string_deallocate( directory );

	return 0;
}


DECLARE_TEST( stream, readwrite_swap )
{
	stream_t* teststream;
	char* path;
	char* directory;
	bool read_bool;
	int8_t read_int8;
	uint8_t read_uint8;
	int16_t read_int16;
	uint16_t read_uint16;
	int32_t read_int32;
	uint32_t read_uint32;
	int64_t read_int64;
	uint64_t read_uint64;
	float32_cast_t cast32;
	float64_cast_t cast64;

	path = path_make_temporary();
	directory = path_directory_name( path );
	fs_make_directory( directory );

	teststream = stream_open( path, STREAM_IN | STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	stream_set_byteorder( teststream, ( system_byteorder() == BYTEORDER_LITTLEENDIAN ) ? BYTEORDER_BIGENDIAN : BYTEORDER_LITTLEENDIAN );
	EXPECT_EQ_MSG( stream_is_swapped( teststream ), true, "swap was not set correctly" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, (int8_t)0x8f );
	stream_write_uint8( teststream, (uint8_t)0xab );
	stream_write_int16( teststream, (int16_t)0xfeef );
	stream_write_uint16( teststream, (uint16_t)0xbaad );
	stream_write_int32( teststream, (int32_t)0x12345678 );
	stream_write_uint32( teststream, 0x98765432UL );
	stream_write_int64( teststream, 0x1234567890abcdefLL );
	stream_write_uint64( teststream, 0x1234567890abcdefULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );

	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	stream_set_byteorder( teststream, system_byteorder() );
	EXPECT_EQ_MSG( stream_is_swapped( teststream ), false, "swap was not set correctly" );

	read_bool = stream_read_bool( teststream );
	read_int8 = stream_read_int8( teststream );
	read_uint8 = stream_read_uint8( teststream );
	read_int16 = stream_read_int16( teststream );
	read_uint16 = stream_read_uint16( teststream );
	read_int32 = stream_read_int32( teststream );
	read_uint32 = stream_read_uint32( teststream );
	read_int64 = stream_read_int64( teststream );
	read_uint64 = stream_read_uint64( teststream );

	EXPECT_EQ_MSG( read_bool, true, "read boolean did not swap as expected" );
	EXPECT_EQ_MSGFORMAT( read_int8, (int8_t)0x0000008f, "read int8 did not swap as expected (%02x)", (int)read_int8 );
	EXPECT_EQ_MSGFORMAT( read_uint8, (uint8_t)0x000000ab, "read uint8 did not swap as expected (%02x)", (int)read_uint8 );
	EXPECT_EQ_MSGFORMAT( read_int16, (int16_t)0x0000effe, "read int16 did not swap as expected (%04x)", (int)read_int16 );
	EXPECT_EQ_MSGFORMAT( read_uint16, (uint16_t)0x0000adba, "read uint16 did not swap as expected (%04x)", (int)read_uint16 );
	EXPECT_EQ_MSGFORMAT( read_int32, (int32_t)0x78563412, "read int32 did not swap as expected (%08x)", read_int32 );
	EXPECT_EQ_MSGFORMAT( read_uint32, 0x32547698UL, "read uint32 did not swap as expected (%048x)", read_uint32 );
	EXPECT_EQ_MSGFORMAT( read_int64, (int64_t)0xefcdab9078563412LL, "read int64 did not swap as expected (%016x)", read_int64 );
	EXPECT_EQ_MSGFORMAT( read_uint64, 0xefcdab9078563412ULL, "read uint64 did not swap as expected (%016x)", read_uint64 );

	cast32.fval = stream_read_float32( teststream );
	cast32.ival = byteorder_swap32( cast32.ival );
	EXPECT_EQ_MSGFORMAT( cast32.fval, 1.0f, "read float32 did not swap as expected : %f", cast32.fval );

	cast64.fval = stream_read_float64( teststream );
	cast64.ival = byteorder_swap64( cast64.ival );
	EXPECT_EQ_MSGFORMAT( cast64.fval, -1.0f, "read float64 did not swap as expected : %lf", cast64.fval );

	stream_deallocate( teststream );
	fs_remove_file( path );

	teststream = stream_open( path, STREAM_IN | STREAM_OUT | STREAM_BINARY | STREAM_CREATE );
	EXPECT_NE_MSGFORMAT( teststream, 0, "test stream '%s' not created", path );

	EXPECT_EQ_MSG( stream_is_swapped( teststream ), false, "swap was not set correctly" );

	stream_write_bool( teststream, true );
	stream_write_int8( teststream, (int8_t)0x8f );
	stream_write_uint8( teststream, (uint8_t)0xab );
	stream_write_int16( teststream, (int16_t)0xfeef );
	stream_write_uint16( teststream, (uint16_t)0xbaad );
	stream_write_int32( teststream, (int32_t)0x12345678 );
	stream_write_uint32( teststream, 0x98765432UL );
	stream_write_int64( teststream, 0x1234567890abcdefLL );
	stream_write_uint64( teststream, 0x1234567890abcdefULL );
	stream_write_float32( teststream, 1.0f );
	stream_write_float64( teststream, -1.0 );

	stream_seek( teststream, 0, STREAM_SEEK_BEGIN );
	EXPECT_EQ_MSG( stream_tell( teststream ), 0, "stream position not null after seek" );
	stream_set_byteorder( teststream, ( system_byteorder() == BYTEORDER_LITTLEENDIAN ) ? BYTEORDER_BIGENDIAN : BYTEORDER_LITTLEENDIAN );
	EXPECT_EQ_MSG( stream_is_swapped( teststream ), true, "swap was not set correctly" );

	read_bool = stream_read_bool( teststream );
	read_int8 = stream_read_int8( teststream );
	read_uint8 = stream_read_uint8( teststream );
	read_int16 = stream_read_int16( teststream );
	read_uint16 = stream_read_uint16( teststream );
	read_int32 = stream_read_int32( teststream );
	read_uint32 = stream_read_uint32( teststream );
	read_int64 = stream_read_int64( teststream );
	read_uint64 = stream_read_uint64( teststream );

	EXPECT_EQ_MSG( read_bool, true, "read boolean did not swap as expected" );
	EXPECT_EQ_MSGFORMAT( read_int8, (int8_t)0x0000008f, "read int8 did not swap as expected (%02x)", (int)read_int8 );
	EXPECT_EQ_MSGFORMAT( read_uint8, (uint8_t)0x000000ab, "read uint8 did not swap as expected (%02x)", (int)read_uint8 );
	EXPECT_EQ_MSGFORMAT( read_int16, (int16_t)0x0000effe, "read int16 did not swap as expected (%04x)", (int)read_int16 );
	EXPECT_EQ_MSGFORMAT( read_uint16, (uint16_t)0x0000adba, "read uint16 did not swap as expected (%04x)", (int)read_uint16 );
	EXPECT_EQ_MSGFORMAT( read_int32, (int32_t)0x78563412, "read int32 did not swap as expected (%08x)", read_int32 );
	EXPECT_EQ_MSGFORMAT( read_uint32, 0x32547698UL, "read uint32 did not swap as expected (%048x)", read_uint32 );
	EXPECT_EQ_MSGFORMAT( read_int64, (int64_t)0xefcdab9078563412LL, "read int64 did not swap as expected (%016x)", read_int64 );
	EXPECT_EQ_MSGFORMAT( read_uint64, 0xefcdab9078563412ULL, "read uint64 did not swap as expected (%016x)", read_uint64 );

	cast32.fval = stream_read_float32( teststream );
	cast32.ival = byteorder_swap32( cast32.ival );
	EXPECT_EQ_MSGFORMAT( cast32.fval, 1.0f, "read float32 did not swap as expected : %f", cast32.fval );

	cast64.fval = stream_read_float64( teststream );
	cast64.ival = byteorder_swap64( cast64.ival );
	EXPECT_EQ_MSGFORMAT( cast64.fval, -1.0f, "read float64 did not swap as expected : %lf", cast64.fval );

	stream_deallocate( teststream );
	fs_remove_file( path );

	string_deallocate( path );
	string_deallocate( directory );

	return 0;
}


static void test_stream_declare( void )
{
	ADD_TEST( stream, std );
	ADD_TEST( stream, readwrite_binary );
	ADD_TEST( stream, readwrite_text );
	ADD_TEST( stream, readwrite_sequential );
	ADD_TEST( stream, readwrite_swap );
}


test_suite_t test_stream_suite = {
	test_stream_application,
	test_stream_memory_system,
	test_stream_declare,
	test_stream_initialize,
	test_stream_shutdown
};


#if BUILD_MONOLITHIC

int test_stream_run( void );
int test_stream_run( void )
{
	test_suite = test_stream_suite;
	return test_run_all();
}

#else

test_suite_t test_suite_define( void );
test_suite_t test_suite_define( void )
{
	return test_stream_suite;
}

#endif