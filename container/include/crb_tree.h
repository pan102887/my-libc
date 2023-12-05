#ifndef _MY_LIBC_CRB_TREE_H_
#define _MY_LIBC_CRB_TREE_H_

#include "crb_tree_type.h"
#include "ExportApi.h"
#if defined(__cplusplus)
extern "C" {
#endif

#define RED 0
#define BLACK 1

#define rb_parent(r) ((struct crb_node *)((r)->_parent_color & ~3))

#define rb_entry(ptr, type, member) container_of(ptr, type, member)

#define RB_EMPTY_ROOT(root)  (READ_ONCE((root)->rb_node) == NULL)

#define RB_EMPTY_NODE(node)  \
	((node)->__rb_parent_color == (unsigned long)(node))
#define RB_CLEAR_NODE(node)  \
	((node)->__rb_parent_color = (unsigned long)(node))

#define rb_color(r) ((r)->_parent_color & 1)
#define rb_is_red(r) (!rb_color(r))
#define rb_is_black(r) (rb_color(r))

extern void rb_insert_color(struct rb_node *, struct rb_root *);
extern void rb_erase(struct rb_node *, struct rb_root *);


/* Find logical next and previous nodes in a tree */
extern struct rb_node *rb_next(const struct rb_node *);
extern struct rb_node *rb_prev(const struct rb_node *);
extern struct rb_node *rb_first(const struct rb_root *);
extern struct rb_node *rb_last(const struct rb_root *);

/* Postorder iteration - always visit the parent after its children */
extern struct rb_node *rb_first_postorder(const struct rb_root *);
extern struct rb_node *rb_next_postorder(const struct rb_node *);

/* Fast replacement of a single node without remove/rebalance/add/rebalance */
extern void rb_replace_node(struct rb_node *victim, struct rb_node *new_,
			    struct rb_root *root);
extern void rb_replace_node_rcu(struct rb_node *victim, struct rb_node *new_,
				struct rb_root *root);

EXPORT_API extern void crb_tree_test(void);

#if defined(__cplusplus)
}
#endif
#endif // !_MY_LIBC_CRB_TREE_H_