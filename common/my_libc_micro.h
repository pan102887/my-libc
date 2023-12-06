#ifndef _MY_LIBC_MICRO_H_
#define _MY_LIBC_MICRO_H_
#include <int-ll64.h>


#undef offsetof
#define offsetof(type, member) (size_t)&((type *)0)->member

#undef container_of
#define container_of(ptr, type, member) ({                      \
    void *__mptr = (void *)(ptr);                               \
    ((type *)(__mptr - offsetof(type, member))); })


    // static_assert(__same_type(*(ptr), ((type *)0)->member) ||   \
    //         __same_type(*(ptr), void),                          \
    //         "pointer type mismatch in container_of()");         \



#define __READ_ONCE_SIZE                        \
({                                  \
    switch (size) {                         \
    case 1: *(__u8 *)res = *(volatile __u8 *)p; break;      \
    case 2: *(__u16 *)res = *(volatile __u16 *)p; break;        \
    case 4: *(__u32 *)res = *(volatile __u32 *)p; break;        \
    case 8: *(__u64 *)res = *(volatile __u64 *)p; break;        \
    default:                            \
        barrier();                      \
        __builtin_memcpy((void *)res, (const void *)p, size);   \
        barrier();                      \
    }                               \
})

/**
__read_once_size函数要完成的操作是将要读取的变量的值拷贝到临时定义的局部联合体变量__u中。
如果要读取变量的长度是1、2、4、8字节的时候，直接使用取指针赋值就行了，由于要读取变量的指针已经被转成了volatile的，编译器保证这个操作不会被优化。如果要读取的变量不是上面说的整字节，那么就要用__builtin_memcpy操作进行拷贝了，但前后都需要加上编译器屏障barrier()，这样就可以保证__builtin_memcpy函数调用本身不会被编译器优化掉。
*/
static __always_inline
void __read_once_size(const volatile void *p, void *res, int size)
{
    __READ_ONCE_SIZE;
}
    
#endif