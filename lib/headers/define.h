/**
 *  @file   define.h
 *  @author Vinícius Ferreira Aguiar
 *  @date   09.03.2020
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
#ifndef _DEFINE_H_
# define _DEFINE_H_



/*
 *  FLAGS
 */
// # define MAKE_BACKUP

# define ERROR    true
# define ALL_SET false
# define STOP    false
# define RUNNING  true

# define MAX_WORD   32
# define SEARCH      0
# define INSERT      1
# define DELETE      2
# define PRINT_NODE  3
# define PRINT_TREE  4
# define EXIT        5



/**
 *  Structs
 */
struct node_rb_s
{
	struct node_rb_s *left;
	struct node_rb_s *right;

	// void *data;
	int key;

	enum { RED, BLACK } color_e;
};

struct tree_rb_s
{
	struct node_rb_s *root;

    int size;

};
//
//
/*
 *  Typedefs
 */
typedef struct node_rb_s node_rb_t;
typedef struct tree_rb_s tree_rb_t;
// typedef;
// typedef;



/*
 *  Constants
 */
const char k_fatal_error[ ] = {
    "\033[31;1mfatal error:\033[0;0m"
};
const char k_program[ ] = {
    " Dictionary "
};
const char k_creator[ ] = {
    " Vinicius F. Aguiar "
};
const char *k_menu[ ] = {
    "Search",
    "Insert",
    "Delete",
    "Print Node",
    "Print Tree",
    "Exit"
};
const int k_creator_size = sizeof( k_creator ) / sizeof( char );
const int k_program_size = sizeof( k_program ) / sizeof( char );
const int k_menu_size    = sizeof( k_menu ) / sizeof( char * );
const int k_height_min   = k_menu_size + 4;
const int k_width_min    = 40;



/*
 *  Functions
 */
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


#endif  // _DEFINE_H_
