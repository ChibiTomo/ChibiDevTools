#ifndef CDT_CORE_LIBEXPORT_H
#define CDT_CORE_LIBEXPORT_H

#if defined _WIN32 || defined __CYGWIN__
	#define LIB_IMPORT __declspec(dllimport)
	#define LIB_EXPORT __declspec(dllexport)
	#define LIB_PRIVATE
#else
	#if __GNUC__ >= 4
		#define LIB_IMPORT __attribute__ ((visibility ("default")))
		#define LIB_EXPORT __attribute__ ((visibility ("default")))
		#define LIB_PRIVATE  __attribute__ ((visibility ("hidden")))
	#else
		#define LIB_IMPORT
		#define LIB_EXPORT
		#define LIB_PRIVATE
	#endif
#endif

#ifdef LIB_BUILD
#define CDT_API LIB_EXPORT

#else
#define CDT_API LIB_IMPORT

#endif // LIB_BUILD

#endif // CDT_CORE_LIBEXPORT_H
