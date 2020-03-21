#include <stdlib.h>
#include <string.h>

#include "../lib/headers/define.h"
#include "../lib/headers/tree.h"



tree_rb_t *
initialize_tree( void )
{
    tree_rb_t *new_tree = (tree_rb_t *) malloc( sizeof(tree_rb_t *) );

    new_tree->root = NULL;
    new_tree->size = 0;

    return new_tree;
}



node_rb_t *
insert_rb()
{

}