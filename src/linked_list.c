#include <stdlib.h>
#include <stdbool.h>

#include "../lib/headers/define.h"

#ifdef NCURSES
# include <ncurses.h>
#else
# include <stdio.h>
#endif

#include "../lib/headers/linked_list.h"



list_t
*createList( void )
{
    list_t *new_list = ( list_t * ) malloc( sizeof(list_t) );

    if ( new_list == NULL )
    {
        return NULL;
    }

    new_list->size = 0;
    new_list->head = NULL;

    return new_list;
}



void
push( list_t *list ,
      char   *word )
{
    node_list_t *new_node = ( node_list_t * ) malloc( sizeof(node_list_t) );

    if ( new_node == NULL )
    {
        return;
    }

    new_node->word = word;
    new_node->next = list->head;

    list->head = new_node;
    list->size++;
}



void
pop( list_t *list )
{
    if (isEmpty( list ))
    {
        return;
    }

    node_list_t *ptr = list->head;

    list->head = ptr->next;
    list->size--;

    free( ptr );
}



bool
isEmpty( list_t *list )
{
    return ( list->size == 0 ? true : false );
}



void
printList( list_t *list )
{
    if ( isEmpty( list ) )
    {
        puts( "Empty List" );
        return;
    }

    node_list_t *ptr = list->head;

    while ( ptr != NULL )
    {
        printf( "%s", ptr->word );
        ptr = ptr->next;
    }
    puts( "" );
}
