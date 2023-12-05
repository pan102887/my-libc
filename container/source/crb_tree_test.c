#include "crb_tree.h"
#include "stdlib.h"
#include "stdio.h"


#if defined(__cplusplus)
extern "C" {
#endif

extern void crb_tree_test(void)
{
    const int node_list_size = 10;
    struct crb_node *node_list = malloc(sizeof(struct crb_node) * node_list_size);
    for (int i = 0; i < node_list_size; ++i)
    {
        printf("node_%d address: %p\n", i, &node_list[i]);
    }
    
}
#if defined(__cplusplus)
}
#endif
