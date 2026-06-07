#include"header.h"
void stud_del_name(sll **ptr)
{
        char n1[20];
        pf("Enter name to delete: \n");
        sf(" %s",n1);
        sll *temp = *ptr;
        int c=0;
        while(temp)
        {
                if(strcmp(n1,temp->n) == 0)
                        c++;
                temp = temp->next;
        }
        if(c == 0)
        {
                pf("No record with this name found\n");
                return;
        }
        if(c == 1)
        {
                sll *del = *ptr,*prev = NULL;
                while(del)
                {
                        if(strcmp(n1,del->n) == 0)
                        {
                                if(del == *ptr)
                                        *ptr = del->next;
                                else
                                        prev->next = del->next;
                                free(del);
                                pf("Record deleted\n");
                                return;
                        }
                        prev = del;
                        del = del->next;
                }
        }
        pf("Multiple records found...\n");
        pf("\n========================================================\n");
        pf("\t%-6s %-18s %-8s\n","Roll", "Name", "Marks");
        pf("----------------------------------------------------------\n");
        temp = *ptr;
        while(temp)
        {
                if(strcmp(n1,temp->n) == 0)
                        pf("\t%-6d %-18s %-8f\n",temp->r,temp->n,temp->m);
                temp = temp->next;
        }
        stud_del_roll(ptr);
}
///////////////////////////////////////////////////////////
void stud_del_roll(sll **ptr)
{
        int roll;
        pf("Enter roll to delete: \n");
        sf(" %d",&roll);
        sll *del = *ptr,*prev;
        while(del)
        {
                if(roll == del->r)
                {
                        if(del == *ptr)
                                *ptr = del->next;
                        else
                                prev->next = del->next;
                        free(del);
                        pf("Records deleted successfully\n");
                        return;
                }
                prev = del;
                del = del->next;
        }
        pf("No records found\n");
}
/////////////////////////////////////////////////////////////////
void delete_all(sll **ptr)
{
        if(*ptr == 0)
        {
                pf("No records present\n");
                return;
        }
        int c=1;
        sll *del = *ptr;
        while (del)
	{
                *ptr = del->next;
                free(del);
                pf("Node position deleted: %d\n",c++);
                sleep(1);
                del = *ptr;
    }
    pf("All nodes deleted.\n");
}