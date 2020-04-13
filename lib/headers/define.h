/**
 *  @file   define.h
 *  @author Vinícius Ferreira Aguiar
 *  @date   09.03.2020
 *  @brief  Contain all the definitions of the program.
 *
 *  @see https://github.com/AceVinicius
 *
 */
#ifndef _DEFINE_H_
# define _DEFINE_H_



// # define MAKE_BACKUP
// # define NCURSES

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



/*
 *  Structs
 */
struct node_list_s
{
    struct node_list_s *next;

    char *word;
};

struct list_s
{
    struct node_list_s *head;

    unsigned int size;
};

struct node_rb_s
{
	struct node_rb_s *left;
	struct node_rb_s *right;
    struct node_rb_s *parent;

	struct list_s *list;
	char key;

	enum { RED, BLACK } color_e;
};

struct tree_rb_s
{
    struct node_rb_s *root;

    unsigned int size;
};



/*
 *  Typedefs
 */
typedef struct node_rb_s node_rb_t;
typedef struct tree_rb_s tree_rb_t;
typedef struct tree_rb_s TREE;
typedef struct node_list_s node_list_t;
typedef struct list_s list_t;
typedef struct list_s LIST;



#endif  // _DEFINE_H_
