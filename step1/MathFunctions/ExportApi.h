#ifndef _EXPORT_API_H_
#define _EXPORT_API_H_

#if defined(_MSC_VER) && defined(USE_DLL)


#if defined(EXPORT_DLL)
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif

#else
#define EXPORT_API
#endif


#endif