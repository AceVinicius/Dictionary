#ifndef _CONSTANTS_H_
# define _CONSTANTS_H_



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



#endif  // _CONSTANTS_H_
