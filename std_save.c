#include"header.h"
void sort_name(sll *ptr)
{
        if(ptr == 0)
        {
                pf("No records found\n");
                return;
        }
        sll *p1,*p2,t;
        int i,j,c = count_node(ptr);
        p1 = ptr;
        for(i=0;i<c;i++)
        {
                p2 = p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(strcmp(p1->n,p2->n) > 0)
                        {
                                t.r = p1->r;
                                strcpy(t.n,p1->n);
                                t.m = p1->m;

                                p1->r = p2->r;
                                strcpy(p1->n,p2->n);
                                p1->m = p2->m;

                               p2->r = t.r;
                               strcpy(p2->n,t.n);
                               p2->m = t.m;
                       }
                       p2 = p2->next;
                 }
                 p1 = p1->next;
        }
        pf("Sorted success\n");
}
/////////////////////////////////////////////////
void sort_perc(sll *ptr)
{
        if(ptr == 0)
        {
                pf("No records found\n");
                return;
	}
        sll *p1,*p2,t;
        int i,j,c = count_node(ptr);
        p1 = ptr;
        for(i=0;i<c;i++)
        {
                p2 = p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(p1->m > p2->m)
                        {
                                t.r = p1->r;
                                strcpy(t.n,p1->n);
                                t.m = p1->m;

                                p1->r = p2->r;
                                strcpy(p1->n,p2->n);
                                p1->m = p2->m;

                               p2->r = t.r;
                               strcpy(p2->n,t.n);
                               p2->m = t.m;
                       }
                       p2 = p2->next;
                 }
                 p1 = p1->next;
        }
        pf("Sorted success\n");
}
/////////////////////////////////////////////////
void sort_roll(sll *ptr)
{
        if(ptr == 0)
        {
                pf("No records found\n");
                return;
        }
        sll *p1,*p2,t;
        int i,j,c = count_node(ptr);
        p1 = ptr;
        for(i=0;i<c;i++)
        {
                p2 = p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(p1->r > p2->r)
                        {
                                t.r = p1->r;
                                strcpy(t.n,p1->n);
                                t.m = p1->m;

                                p1->r = p2->r;
                                strcpy(p1->n,p2->n);
                                p1->m = p2->m;

                               p2->r = t.r;
                               strcpy(p2->n,t.n);
                               p2->m = t.m;
                       }
                       p2 = p2->next;
                 }
                 p1 = p1->next;
        }
        pf("Sorted success\n");
}
//////////////////////////////////////////////////////
void rev_links(sll **ptr)
{
        if(*ptr == 0)
        {
                pf("No records found\n");
                return;
        }
        int c;
        c = count_node(*ptr);      // finding node count
        if(c > 1)
        {
                sll **a = malloc(sizeof(sll *)*c);      //alloc memory
                sll *t = *ptr;  //start from 1st
                int i=0;
                // storing the address
                while(t)
                {
                        a[i++] = t;
                        t = t->next;
                }
                // change the links
                for(i=c-1;i>0;i--)
                        a[i]->next = a[i-1];
                a[0]->next = 0; //update 1st node nxt address
                *ptr = a[c-1];  //update ptr
        }
}
//////////////////////////////////////////////////////
void save_file(sll *ptr)
{
        if(ptr == 0)
        {
                pf("No records present\n");
                return;
        }
        FILE *fp = fopen("student.dat","w");
        while(ptr)
        {
                fprintf(fp,"%d %s %.2f\n",ptr->r,ptr->n,ptr->m);
                ptr = ptr->next;
        }
        pf("Data Saved Successfully\n");
        fclose(fp);
}