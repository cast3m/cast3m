/*  Declarations dependantes machines pour Cast3M  */
#ifdef WIN32
  #define SUN 1
  #define UNIX32 1
  #undef BUFFER
  #undef AIO
  #define THREAD 1
  #undef LIMIT
#endif

#ifdef WIN64
  #define SUN 1
  #define UNIX64 1
  #undef BUFFER
  #undef AIO
  #define THREAD 1
  #undef LIMIT
#endif

#ifdef LINUX
  #define SUN 1
  #define UNIX32 1
  #undef BUFFER
  #define AIO 1
  #define THREAD 1
  #define LIMIT 1
#endif

#ifdef LINUX64
  #define SUN 1
  #define UNIX64 1
  #undef BUFFER
  #define AIO 1
  #define THREAD 1
  #define LIMIT 1
#endif

#ifdef OSX
  #define SUN 1
  #define UNIX64 1
  #undef BUFFER
  #define AIO 1
  #define THREAD 1
  #define LIMIT 1
#endif

#ifdef AIX
  #undef SUN
  #define UNIX32 1
  #undef BUFFER
  #undef AIO   /* version sp�ciale pour aix */
  #define THREAD 1
  #define LIMIT 1
#endif

#ifdef SUN
  #define getcpu getcpu_
  #define timespv timespv_
  #define verdat verdat_
  #define gistty gistty_
  #define cgibnam cgibnam_
  #define threadii threadii_
  #define threadis threadis_
  #define threadid threadid_
  #define threadif threadif_
  #define threadmi threadmi_
  #define threadml threadml_
  #define inithread inithread_

  #define trfin trfin_

  #define xopen xopen_
  #define xrinit xrinit_
  #define xfenet xfenet_
  #define xrlabl xrlabl_
  #define xhcoul xhcoul_
  #define xvalis xvalis_
  #define xolrl xolrl_
  #define xrface xrface_
  #define xraiso xraiso_
  #define xraff xraff_
  #define xrget xrget_
  #define xclik xclik_
  #define xenu xenu_
  #define xranim xranim_
  #define xrimag xrimag_
  #define xrswap xrswap_

  #define initserver initserver_
  #define initclient initclient_
  #define writesocket writesocket_
  #define readsocket readsocket_
  #define closesocket closesocket_

  #define otrbox otrbox_
  #define ofvali ofvali_
  #define omenu omenu_
  #define oinseg oinseg_
  #define otrdig otrdig_
  #define otrais otrais_
  #define otreff otreff_
  #define otrmfi otrmfi_
  #define ozoom ozoom_
  #define ochang ochang_
  #define oini oini_
  #define oflgi oflgi_
  #define oval oval_
  #define omajse omajse_
  #define otrani otrani_
  #define otrima otrima_
  #define otrmes otrmes_
  #define oglini oglini_
  #define ogldfene ogldfene_
  #define ogltrlabl ogltrlabl_
  #define oglchcou oglchcou_
  #define oglpolrl oglpolrl_
  #define ogltrfac ogltrfac_
  #define oglaff oglaff_
  #define ogltriso ogltriso_
  #define oglfvali oglfvali_
  #define oglinsegt oglinsegt_
  #define oglmajse oglmajse_
  #define oglchang oglchang_
  #define ogltrmess ogltrmess_
  #define oglzoom oglzoom_
  #define otrdigro otrdigro_
  #define oglget oglget_
  #define oclik oclik_
  #define invrs invrs_
#endif

// D�finition des types
#if defined WIN64
  typedef long long cast_int   ;
  typedef double    cast_float ;
#elif defined LINUX64
  typedef long      cast_int   ;
  typedef double    cast_float ;
#else
  typedef int       cast_int   ;
  typedef float     cast_float ;
#endif
typedef long        cast_long  ;
typedef double      cast_double;
