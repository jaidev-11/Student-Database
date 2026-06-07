#include"header.h"
void stud_mod(sll *ptr)
{
    int choice;
    struct st *temp = ptr;
    int found = 0;

    if (ptr == NULL) {
        pf("No records available to modify!\n");
        return;
    }

    pf("\nModify Menu\n");
    pf("1. Modify by Roll\n");
    pf("2. Modify by n\n");
    pf("3. Modify by Percentage\n");
    pf("Enter your choice: ");
       sf("%d", &choice);

    // ----------- MODIFY BY ROLL -----------
    if (choice == 1) {
        int roll;
        pf("Enter roll number: ");
        sf("%d", &roll);

        while (temp != NULL) {
            if (temp->r == roll) {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            pf("Record not found!\n");
            return;
        }

        pf("Enter new n: ");
        sf(" %[^\n]", temp->n);

        pf("Enter new marks: ");
        sf("%f", &temp->m);
        
        pf("Record updated successfully!\n");
    }

    // ----------- MODIFY BY NAME -----------
    else if (choice == 2) {
        char n[50];
        pf("Enter n to search: ");
        sf(" %[^\n]", n);

        pf("\nMatching Records:\n");
        while (temp != NULL) {
            if (strcmp(temp->n, n) == 0) {
                pf("Roll: %d | n: %s | Marks: %.2f\n",
                       temp->r, temp->n, temp->m);
                found = 1;
            }
                       temp = temp->next;
        }

        if (!found) {
            pf("No matching records found!\n");
            return;
        }

        int roll;
        pf("Enter roll number to modify: ");
        sf("%d", &roll);

        temp = ptr;
        while (temp != NULL && temp->r != roll)
            temp = temp->next;

        if (temp == NULL) {
            pf("Invalid roll number!\n");
            return;
        }

        pf("Enter new n: ");
        sf(" %[^\n]", temp->n);

        pf("Enter new marks: ");
        sf("%f", &temp->m);
        
        pf("Record updated successfully!\n");
    }

    //* ----------- MODIFY BY PERCENTAGE -----------
    else if (choice == 3) {
        float perc;
        pf("Enter percentage to search: ");
        sf("%f", &perc);

        pf("\nMatching Records:\n");
        temp = ptr;

        while (temp != NULL) {
            if (temp->m == perc) {   // marks = percentage (out of 100)
                pf("Roll: %d | n: %s | Marks: %.2f\n",
                       temp->r, temp->n, temp->m);
                                      found = 1;
            }
            temp = temp->next;
        }

        if (!found) {
            pf("No matching records found!\n");
            return;
        }

        int roll;
        pf("Enter roll number to modify: ");
        sf("%d", &roll);

        temp = ptr;
        while (temp != NULL && temp->r != roll)
            temp = temp->next;

        if (temp == NULL) {
            pf("Invalid roll number!\n");
            return;
        }

        pf("Enter new n: ");
        sf(" %[^\n]", temp->n);
        
        pf("Enter new marks: ");
        sf("%f", &temp->m);

        pf("Record updated successfully!\n");
    }

    else {
        pf("Invalid choice!\n");
    }
}