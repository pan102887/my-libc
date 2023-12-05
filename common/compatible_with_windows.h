#ifndef _MY_LIBC_COMPATIBLE_WITH_WINDOWS_H_
#define _MY_LIBC_COMPATIBLE_WITH_WINDOWS_H_

#if defined(_MSC_VER)
#define __attribute__(x)
#define container_of(ptr, type, member) \
        ((type *)((void *)(ptr) - (char *)(&((void *)0)->member)))
#endif

#endif