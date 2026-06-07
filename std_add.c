#include"header.h"
int main()
{
        sll *hptr = 0;
        int c;
        char ch;
        while(1)
        {
                pf("\n====== Student Record Menu ======\n");
                pf("\ta/A: Add new record\n\td/D: Delete a record\n\ts/S: Show the list of records\n\tm/M: Modify the records\n\tv/V: Save\n\te/E: Exit\n\tt/T: Sort the list of records\n\tl/L: Delete all the records\n\tr/R: Reverse the list of records\n");
                pf("\n\tEnter your choice: ");
                sf(" %c", &ch);
                ch = loweralpa(ch);
                switch(ch)
                {
                        case 'a': stud_add(&hptr); break;
                        case 'd': {
                                char op1;
                                if(hptr == 0)
                                {
                                        pf("No records found\n");
                                        break;
                                }
                                pf("n/N: del by name\nr/R: del by Roll\nEnter your choice: \n");
                                sf(" %c",&op1);
                                op1 = loweralpa(op1);
                                switch(op1)
                                {
                                        case 'n': stud_del_name(&hptr); break;
                                        case 'r': stud_del_roll(&hptr); break;
                                        default: pf("Invalid Option\n"); break;
                                }
                                break;
                                }; break;
                        case 's': stud_show(hptr); break;
                        case 'm': stud_mod(hptr); break;
                        case 'e': {
                                        char op2;
                                        pf("Exit without saving (y/n): \n");
                                        sf(" %c",&op2);
                                        op2 = loweralpa(op2);
                                        if(op2 == 'n')
                                        {
                                                save_file(hptr);
                                                free_mem(hptr);
                                                exit(0);
                                                break;
                                        }
                                        else
                                        {
                                                free_mem(hptr);
                                                exit(0);
                                                break;
                                        }
                                }
                                break;
                        case 'v': save_file(hptr); break;
                        case 't': {
                                        char op3;
                                        if(hptr == 0)
                                {
                                        pf("No records found\n");
                                        break;
                                }
                                pf("r/R: sort by roll\nn/N: sort by name\np/P: sort by Percentage\nEnter your choice: \n");
                                sf(" %c",&op3);
                                op3 = loweralpa(op3);
                                switch(op3)
                                {
                                        case 'r': sort_roll(hptr); break;            
                                        case 'n': sort_name(hptr); break;
                                        case 'p': sort_perc(hptr); break;
                                        default: pf("Invalid Option\n"); break;
                                }
                                break;
                                }
			case 'l': delete_all(&hptr); break;
                        case 'r': rev_links(&hptr); break;
                        default: pf("Invalid choice!\n"); break;
                }
        }
}
////////////////////////////////////////
char loweralpa(char ch)
{
        if(ch >= 'A' && ch <='Z')
                return ch ^ 32;
        else
                return ch;
}
//////////////////////////////////////////////////
void free_mem(sll *ptr)
{
        sll *del = ptr;
        while(del)
        {
                ptr = del->next;
                free(del);
                del = ptr;
        }
}
////////////////////////////////////////////////////
int count_node(sll *ptr)
{
        int c=0;
        while(ptr)
        {
                c++;
                ptr = ptr->next;
                       }
        return c;
}
///////////////////////////////////////
void stud_add(sll ** ptr)
{
        struct st *new;

        new = (struct st*)malloc(sizeof(struct st));
        pf("Enter name & marks: \n");
        sf(" %s%f",new->n,&new->m);
        int roll = 1;
        sll *temp;
        while(1)
        {
                int f=0;
                temp = *ptr;
                while(temp)
                {
                        if(temp->r == roll)
                        {
                                f = 1;
                                break;
                        }
                        temp = temp->next;
                }
                if(f == 0)
                        break;
                roll++;
        }
        new->r = roll;
        new->next = NULL;

        if (*ptr == NULL || (*ptr)->r > roll)
        {
                new->next = *ptr;
                *ptr = new;
                return;
        }
        temp = *ptr;
        while (temp->next && temp->next->r < roll)
                temp = temp->next;
        new->next = temp->next;
        temp->next = new;
}
////////////////////////////////////////////////