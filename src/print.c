#include <ncurses.h>

#include "../lib/headers/define.h"
#include "../lib/headers/print.h"



void
print_trunks( struct trunk *p )
{
    if (!p) return;

    print_trunks (p->prev);
    printf ("%s", p->str);
}



void
print_tree (node_rb_t *tree, struct trunk *prev, int is_left)
{
    if (tree == NULL) return;

    struct trunk this_disp = { prev, "     " };
    char *prev_str = this_disp.str;
    print_tree (tree->right, &this_disp, 1);

    if (!prev)
    {
        this_disp.str = " --";
    }
    else if (is_left)
    {
        this_disp.str = ".--";
        prev_str = "    |";
    }
    else
    {
        this_disp.str = "`--";
        prev->str = prev_str;
    }

    print_trunks (&this_disp);
    printf ("%04d (%+d)\n",tree->key, tree->color);

    if (prev)
    {
        prev->str = prev_str;
    }
    this_disp.str = "    |";

    print_tree (tree->left, &this_disp, 0);
    if (!prev)
    {
        puts ("");
    }
}



void Tree_Print (tree_rb_t *tree)
{
    puts("");
    print_tree (tree->root, 0, 0);
    fflush (stdout);
}
