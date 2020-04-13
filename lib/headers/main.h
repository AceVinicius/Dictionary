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


#ifdef NCURSES
WINDOW *create_basic_layout( const int , const int );
int menu_screen( void );
char *tree_operations_screen( const char *, const unsigned long long );
char *print_node_screen( const char *, const unsigned long long );
// void node_screen( const char *string, const char size );
// void tree_screen( const char *string, const char size );
void exit_screen( void );
#endif
void parse( char * );
void search( tree_rb_t * );
void insert( tree_rb_t * );
void delete( tree_rb_t * );
void print_node( tree_rb_t * );
void print_tree( tree_rb_t * );
void exit_loop( bool * );
#ifdef NCURSES
bool start_terminal( void );
#endif
void initial_tree_setup( TREE * );



#endif  // _MAIN_H_
