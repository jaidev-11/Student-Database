#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define pf printf
#define sf scanf


typedef struct st
{
        int r;
        char n[50];
        float m;
        struct st *next;
}sll;

void stud_add(sll **);
void stud_show(sll *);
void stud_del_roll(sll **);
void delete_all(sll **);
void stud_del_name(sll **);
void stud_mod(sll *);
void rev_links(sll **);
void sort_name(sll *);
void sort_roll(sll *);
void sort_perc(sll *);
void free_mem(sll *);
void save_file(sll *);
int count_node(sll *);
char loweralpa(char );
