/**
 *  @file   tree.h
 *  @author Vinícius Ferreira Aguiar
 *  @date   09.03.2020
 *  @brief  Contain all the definitions of the program.
 *
 *  Functions in this file:
 *    @see initialize_tree_rb()
 *    @see create_new_node_rb()
 *    @see insert_rb()
 *
 *  @see https://github.com/AceVinicius
 *
 */
#ifndef _TREE_H_
# define _TREE_H_



tree_rb_t *initialize_tree_rb( void );
bool search_rb( tree_rb_t *, char * );
void insert_rb( tree_rb_t *, char * );
void remove_rb( tree_rb_t * , char * );

node_rb_t *__create_new_node_rb( const char, node_rb_t *, char * );
node_rb_t *__insert_rb( node_rb_t *, const char, char * );
node_rb_t *__insert_fix_up( node_rb_t *, node_rb_t * );
void __delete_rb( void );
node_rb_t *__search_rb( node_rb_t *, char );
void __left_rotate( node_rb_t **, node_rb_t * );
void __right_rotate( node_rb_t **, node_rb_t * );



#endif  // _TREE_H_
