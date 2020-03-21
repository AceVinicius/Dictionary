#ifndef _PRINT_H_
# define _PRINT_H_



/*
 *  Structs
 */
struct trunk
{
    struct trunk *prev;
    char *str;
};



/*
 *  Functions
 */
void print_trunks( struct trunk *p );
void print_tree( node_rb_t *node, struct trunk *prev, int is_left );
void Tree_Print( tree_rb_t *tree );



#endif  // _PRINT_H_
