#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ncurses.h>

#include "../lib/headers/define.h"
#include "../lib/headers/constants.h"
#include "../lib/headers/tree.h"
// #include "../lib/headers/print.h"
#include "../lib/headers/main.h"



/******************************************************************************
 ****                         SCREEN OUTPUT LAYOUT                         ****
 ******************************************************************************/



WINDOW *
create_basic_layout( const int min_y, const int min_x )
{
    int term_y;
    int term_x;

    getmaxyx( stdscr, term_y, term_x );

    const int padding_y = term_y < min_y ? 3 : term_y - min_y;
    const int padding_x = term_x < min_x ? 3 : term_x - min_x;
    const int height    = term_y - padding_y;
    const int width     = term_x - padding_x;
    const int start_y   = padding_y / 2;
    const int start_x   = padding_x / 2;

    WINDOW *content = newwin( height, width, start_y, start_x );
    WINDOW *shadow  = newwin( height, width, start_y + 1, start_x + 1 );

    bkgd( COLOR_PAIR(1) );
    wbkgd( shadow, COLOR_PAIR(2) );
    wbkgd( content, COLOR_PAIR(3) );

    box( content, 0, 0 );
    wattron( content, COLOR_PAIR(4) );
    mvwprintw( content, 0, (width - k_program_size) / 2, k_program );
    mvwprintw( content, height - 1, width - k_creator_size - 2, k_creator );
    wattroff( content, COLOR_PAIR(4) );

    refresh( );
    wrefresh( shadow );
    wrefresh( content );

    return content;
}



int
menu_screen( void )
{
    WINDOW *content = create_basic_layout( k_height_min, k_width_min );

    keypad( content, true );

    int  choice;
    int  highlight = 0;
    bool status    = true;

    while (status)
    {
        for (int i = 0; i < k_menu_size; ++i)
        {
            if (i == highlight)
            {
                wattron( content, COLOR_PAIR(4) );
            }
            mvwprintw( content, i+2, 4, k_menu[ i ] );
            wattroff( content, COLOR_PAIR(4) );
        }

        choice = wgetch( content );

        switch (choice)
        {
            case KEY_UP:
            {
                if (highlight > 0) highlight--;
                else               highlight = k_menu_size - 1;
                break;
            }
            case KEY_DOWN:
            {
                if (highlight < k_menu_size - 1) highlight++;
                else                             highlight = 0;
                break;
            }
            case '1':  highlight = 0; break;
            case '2':  highlight = 1; break;
            case '3':  highlight = 2; break;
            case '4':  highlight = 3; break;
            case '5':  highlight = 4; break;
            case '6':  highlight = 5; break;
            case '7':  highlight = 6; break;
            case '\n': status = STOP; break;
            default:   break;
        }
    }

    return highlight;
}



char *
tree_operations_screen( const char *string, const unsigned long long size )
{
    static char key[ MAX_WORD ];
    WINDOW *content = create_basic_layout( k_height_min, k_width_min );

    mvwprintw( content, 2, (k_width_min - size) / 2, string );
    mvwprintw( content, 4, 4, "What word do you want to %s?", string );

    wattron( content, COLOR_PAIR(5) );
    mvwprintw( content, 6, 4, "           Type here            " );
    wattroff( content, COLOR_PAIR(5) );

    wrefresh( content );

    wattron( content, COLOR_PAIR(6) );
    mvwscanw( content, 6, 4, " %s", key);
    wattroff( content, COLOR_PAIR(6) );

    return key;
}



char *
print_node_screen( const char *string, const unsigned long long size )
{
    static char key[ MAX_WORD ];
    WINDOW *content = create_basic_layout( k_height_min, k_width_min );

    mvwprintw( content, 2, (k_width_min - size) / 2, string );
    mvwprintw( content, 4, 4, "What node do you want to print?" );

    wattron( content, COLOR_PAIR(5) );
    mvwprintw( content, 6, 4, "           Type here            " );
    wattroff( content, COLOR_PAIR(5) );

    wrefresh( content );

    wattron( content, COLOR_PAIR(6) );
    mvwscanw( content, 6, 4, " %s", key);
    wattroff( content, COLOR_PAIR(6) );

    return key;
}



// void
// node_screen( const char *string, const char size )
// {
//     WINDOW *content = create_basic_layout( k_height_min, k_width_min );

//     mvwprintw( content, 2, (k_width_min - size) / 2, string );
//     mvwprintw( content, 4, 4, "What word do you want to %s?", string );

//     wattron( content, COLOR_PAIR(6) );
//     mvwprintw( content, 6, 4, "Type here" );
//     wattroff( content, COLOR_PAIR(6) );

//     wrefresh( content );
// }



// void
// tree_screen( const char *string, const char size )
// {
//     WINDOW *content = create_basic_layout( k_height_min, k_width_min );
//
//     mvwprintw( content, 2, (k_width_min - size) / 2, string );
//     mvwprintw( content, 4, 4, "What word do you want to %s?", string );
//
//     wattron( content, COLOR_PAIR(5) );
//     mvwprintw( content, 6, 4, "Type here" );
//     wattroff( content, COLOR_PAIR(5) );
//
//     wrefresh( content );
// }



void
exit_screen( void )
{
    WINDOW *content = create_basic_layout( k_height_min, k_width_min );

    mvwprintw( content, k_height_min / 2, (k_width_min - 10) / 2, "Exiting." );
    wrefresh( content );
    sleep( 1 );

    for( int i = 2; i <= 3; ++i)
    {
        mvwprintw( content, k_height_min / 2, (k_width_min + 3) / 2 + i, "." );
        wrefresh( content );
        sleep( 1 );
    }
}



/******************************************************************************
 ****                             FLUX CONTROL                             ****
 ******************************************************************************/



void
parse( char *string )
{
    for (int i = 0; string[ i ]; ++i)
    {
        string[ i ] = tolower( string[ i ] );
    }
}



void
search( tree_rb_t *tree )
{
    char *key = tree_operations_screen( k_menu[ SEARCH ], strlen( k_menu[ SEARCH ] ) );
    parse( key );
}



void
insert( tree_rb_t *tree )
{
    char *key = tree_operations_screen( k_menu[ INSERT ], strlen( k_menu[ INSERT ] ) );
    parse( key );

#ifdef MAKE_BACKUP

#endif

}



void
delete( tree_rb_t *tree )
{
    char *key = tree_operations_screen( k_menu[ DELETE ], strlen( k_menu[ DELETE ] ) );
    parse( key );

#ifdef MAKE_BACKUP

#endif

}



void
print_node( tree_rb_t *tree )
{
    char *key = print_node_screen( k_menu[ PRINT_NODE ], strlen( k_menu[ PRINT_NODE ] ) );
    parse( key );
    // node_screen( )
}



void
print_tree( tree_rb_t *tree )
{
    // tree_screen( k_menu[ PRINT_TREE ], strlen( k_menu[ PRINT_TREE ] ) );
}



void
exit_loop( bool *status )
{
    *status = STOP;
    exit_screen( );
}



/******************************************************************************
 ****                             INITIAL SETUP                            ****
 ******************************************************************************/



bool
start_terminal( void )
{
    if (has_colors( ))
    {
        fprintf(stderr, "dictionary: %s your terminal does not support colors\n",
                k_fatal_error );
        return ERROR;
    }

    initscr();
    cbreak();
    // raw();
    curs_set( 0 );
    start_color( );
    init_pair( 1, COLOR_YELLOW, COLOR_MAGENTA );
    init_pair( 2, COLOR_BLACK , COLOR_BLACK );
    init_pair( 3, 16          , 15 );
    init_pair( 4, COLOR_RED   , 15 );
    init_pair( 5, COLOR_BLACK , 16 );
    init_pair( 6, COLOR_WHITE , 16 );

    return ALL_SET;
}



void
initial_tree_setup( void )
{
    char word[ MAX_WORD ];

    scanf( " %s", word );

    while (strcmp( word, "0"))
    {
        scanf( " %s", word );
        parse( word );
        // insert_rb();
    }
}



/******************************************************************************
 ****                                 MAIN                                 ****
 ******************************************************************************/



int
main( void )
{
    if (start_terminal( )) return EXIT_FAILURE;


    tree_rb_t *tree = initialize_tree( );

    bool status = RUNNING;


    // initial_setup_tree( tree );

    do
    {
        int choice = menu_screen( );

        switch (choice)
        {
            case SEARCH:     search( tree );       break;
            case INSERT:     insert( tree );       break;
            case DELETE:     delete( tree );       break;
            case PRINT_NODE: print_node( tree );   break;
            case PRINT_TREE: print_tree( tree );   break;
            case EXIT:       exit_loop( &status ); break;
            default:         break;
        }
    }
    while (status);

    // kill_tree( tree );
    free( tree );
    endwin();

    return EXIT_SUCCESS;
}
