#include <stdlib.h>
#include <string.h>

#include "../lib/headers/define.h"
#include "../lib/headers/tree.h"

#ifdef NCURSES
# include <ncurses.h>
#else
# include <stdio.h>
#endif



/******************************************************************************
 ****                          EXTERNAL FUNCTIONS                          ****
 ******************************************************************************/



tree_rb_t *
initialize_tree_rb( const unsigned int type )
{
    tree_rb_t *new_tree = (tree_rb_t *) malloc( sizeof(tree_rb_t *) );

    if (new_tree == NULL)
    {
        return NULL;
    }

    new_tree->root = NULL;
    new_tree->size = 0;
    new_tree->type = type;

    return new_tree;
}



void
insert_rb(       tree_rb_t *tree ,
           const char      *key  )
{
    tree->root = __insert_rb( tree->root ,
                              tree->type ,
                              key[ 0 ]   ,
                              key        );

}



// void
// remove_rb(       tree_rb_t *tree ,
//            const char      *key  )
// {
    // tree->root = __insert_rb( tree->root ,
    //                           tree->type ,
    //                           key[ 0 ]   ,
    //                           key        );
// }



/******************************************************************************
 ****                          INTERNAL FUNCTIONS                          ****
 ******************************************************************************/



node_rb_t *
__create_new_node_rb( const          int        key    ,
                                     node_rb_t *father ,
                      const unsigned int        type   ,
                      const          void      *data   )
{
    node_rb_t *new_node = (node_rb_t *) malloc( sizeof(node_rb_t) );

    if (new_node == NULL)
    {
        // puts( "  error: Could not allocate new 'node_rb_t'" );
        return NULL;
    }

    new_node->data = malloc( type );

    if (new_node->data == NULL)
    {
        free( new_node );
        return NULL;
    }

    memcpy( new_node->data, data, type );

    new_node->key     = key;
    new_node->left    = NULL;
    new_node->right   = NULL;
    new_node->parent  = father;
    new_node->color_e = RED;

    return new_node;
}



node_rb_t *
__insert_rb(                node_rb_t *root ,
             const unsigned int        type ,
             const          char       key  ,
             const          void      *data )
{
    node_rb_t *new_node  = NULL;
    node_rb_t *last_node = NULL;

    if (root == NULL)
    {
        new_node = __create_new_node_rb( key, last_node, type, data );
        new_node->color_e = BLACK;
        return new_node;
    }

    node_rb_t *current_node = root;

    while (current_node != NULL)
    {
        last_node = current_node;

        if (current_node->key < current_node->key)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }

    new_node = __create_new_node_rb( key, last_node, type, data );

    if (new_node->key > last_node->key)
    {
        last_node->right = new_node;
    }
    else
    {
        last_node->left = new_node;
    }

    return __insert_fix_up( root, new_node );
}



node_rb_t *
__insert_fix_up( node_rb_t *root      ,
                 node_rb_t *last_node )
{
    while (last_node != root && last_node->parent->color_e == RED)
    {
        node_rb_t *grandfather = last_node->parent->parent;
        node_rb_t *father      = last_node->parent;
        node_rb_t *uncle;

        if (father == grandfather->left)
        {
            uncle = grandfather->right;
            /* case 1 */
            if (uncle != NULL && uncle->color_e == RED)
            {
                grandfather->color_e = RED;
                father->color_e      = BLACK;
                uncle->color_e       = BLACK;
                last_node = grandfather;
            }
            else
            {
                /* case 2 */
                if (last_node == father->right)
                {
                    last_node   = father;
                    father      = grandfather;
                    grandfather = grandfather->parent;
                    __left_rotate( &root, last_node );
                }
                /* case 3 */
                grandfather->color_e = RED;
                father->color_e      = BLACK;
                __right_rotate( &root, grandfather );
            }
        }
        else
        {
            uncle = grandfather->left;
            /* case 1 */
            if (uncle != NULL && uncle->color_e == RED)
            {
                grandfather->color_e = RED;
                father->color_e      = BLACK;
                uncle->color_e       = BLACK;
                last_node = grandfather;
            }
            else
            {
                /* case 2 */
                if (last_node == father->left)
                {
                    last_node   = father;
                    father      = grandfather;
                    grandfather = grandfather->parent;
                    __right_rotate( &root, last_node );
                }
                /* case 3 */
                grandfather->color_e = RED;
                father->color_e      = BLACK;
                __left_rotate( &root, grandfather );
            }
        }
    }

    root->color_e = BLACK;
    return root;
}



void
__delete_rb( void )
{

}



void
__left_rotate( node_rb_t **root ,
               node_rb_t *x     )
{
    node_rb_t *y = x->right;

    x->right = y->left;

    if ( y->left != NULL ) y->left->parent = x;

    y->parent = x->parent;

    if ( x->parent == NULL )
    {
        *root = y;
    }
    else
    {
        if ( x == (x->parent)->left ) x->parent->left  = y;
        else                          x->parent->right = y;
    }

    y->left   = x;
    x->parent = y;
}



void
__right_rotate( node_rb_t **root ,
                node_rb_t *x     )
{
    node_rb_t *y = x->left;

    x->left = y->right;

    if ( y->right != NULL ) y->right->parent = x;

    y->parent = x->parent;

    if ( x->parent == NULL )
    {
        *root = y;
    }
    else
    {
        if ( x == (x->parent)->right ) x->parent->right  = y;
        else                           x->parent->left   = y;
    }

    y->right  = x;
    x->parent = y;
}
