#ifndef LISTAENCADEADA_H
# define LISTAENCADEADA_H

#include <stdbool.h>



list_t *createList( void );
void push( list_t *, char * );
void pop( list_t * );
bool isEmpty( list_t * );
void printList( list_t * );



#endif  // LISTAENCADEADA_H
