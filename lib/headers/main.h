/**
 *  @file   main.h
 *  @author Vinícius Ferreira Aguiar
 *  @date   27.03.2020
 *  @brief  Contain all the definitions of the program.
 *
 *  Functions in this file:
 *    @see create_basic_layout()
 *    @see menu_screen()
 *    @see tree_operations_screen()
 *    @see node_screen()
 *    @see node_screen()
 *    @see tree_screen()
 *    @see exit_screen()
 *    @see parse()
 *    @see search()
 *    @see insert()
 *    @see delete()
 *    @see print_node()
 *    @see print_tree()
 *    @see exit_loop()
 *    @see start_terminal()
 *    @see initial_tree_setup()
 *
 *  @see https://github.com/AceVinicius
 *
 */
#ifndef _MAIN_H_
# define _MAIN_H_



WINDOW *create_basic_layout( const int min_y, const int min_x );
int menu_screen( void );
char *tree_operations_screen( const char *string, const unsigned long long size );
char *print_node_screen( const char *string, const unsigned long long size );
// void node_screen( const char *string, const char size );
// void tree_screen( const char *string, const char size );
void exit_screen( void );
void parse( char *string );
void search( tree_rb_t *tree );
void insert( tree_rb_t *tree );
void delete( tree_rb_t *tree );
void print_node( tree_rb_t *tree );
void print_tree( tree_rb_t *tree );
void exit_loop( bool *status );
bool start_terminal( void );
// void initial_tree_setup( void );



#endif  // _MAIN_H_
