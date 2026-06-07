#include"header.h"
void stud_show(sll *ptr)
{
        sll *temp = ptr;
        if (ptr == NULL)
        {
                pf("No records available!\n");
                return;
        }
        pf("\n========================================================\n");
        pf("\t%-6s %-18s %-8s\n","Roll", "n", "Marks");
        pf("----------------------------------------------------------\n");

        while (temp != NULL)
        {
                pf("\t%-6d %-18s %-8.2f\n",
                temp->r,
                temp->n,
                temp->m);

                temp = temp->next;
        }
        pf("==========================================================\n");
}