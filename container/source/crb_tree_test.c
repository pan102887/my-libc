#include <stdlib.h>
#include <stdio.h>

#include "crb_tree.h"
#include "my_libc_micro.h"


#if defined(__cplusplus)
extern "C" {
#endif

struct Demo
{
    char *key;
    int value;
};

static inline void container_of_test(void)
{
    struct Demo demo = {"key", 24};
    struct Demo *demo_ptr = container_of(&(demo.key), struct Demo, key);
    printf("demo_ptr->key: %s\n", demo_ptr->key);
    printf("demo_ptr->value: %d\n", demo_ptr->value);
}

extern void crb_tree_test(void)
{
    container_of_test();
    const int node_list_size = 10;
    struct crb_node *node_list = malloc(sizeof(struct crb_node) * node_list_size);
    for (int i = 0; i < node_list_size; ++i)
    {
        printf("node_%d address: %p\n", i, &node_list[i]);
    }
}

union 
{
    int i;
    char c[sizeof(int)];
} u;
}
#if defined(__cplusplus)
}
#endif
