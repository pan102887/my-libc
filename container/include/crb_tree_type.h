#ifndef _MY_LIBC_CONTAINER_C_RB_TREE_H_
#define _MY_LIBC_CONTAINER_C_RB_TREE_H_
#include "ExportApi.h"
#include <stdint.h>

#if defined(_MSC_VER)
#include "compatible_with_windows.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

struct EXPORT_API crb_node {
    uint64_t __rb_parent_color;
    struct crb_node *left;
    struct crb_node *right;
}__attribute__((aligned(sizeof(uint64_t))));

struct EXPORT_API crb_root {
    struct crb_node *node;
};

struct EXPORT_API crb_root_cached {
    struct crb_root crb_root;
    struct crb_node *rb_leftmost;
};

#define CRB_ROOT (struct crb_root) { NULL, }
#define CRB_ROOT_CACHED (struct crb_root_cached) { {NULL, }, NULL, }


#if defined(__cplusplus)
}
#endif

#endif