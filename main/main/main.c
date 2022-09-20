//
//  main.c
//  main
//
//  Created by Spataru Dionisie on 19.09.2022.
//
#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int value)
{
    // Create dynamic node
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        // checking memory overflow
        printf("Memory overflow\n");
    }
    else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;
 
            // finding last node
            while (temp->next != NULL) {
                temp = temp->next;
            }
 
            // adding node at last position
            temp->next = node;
        }
    }
}

void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


//for sort
struct Node* last_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

//for sort
struct Node* parition(struct Node* first, struct Node* last)
{
    // Get first node of given linked list
    struct Node* pivot = first;
    struct Node* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;
 
            // Swapping  node values
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            // Visiting the next node
            first = first->next;
        }
 
        // Visiting the next node
        front = front->next;
    }
 
    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}

void quick_sort(struct Node* first, struct Node* last)
{
    if (first == last) {
        return;
    }
    struct Node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

void prepend(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}
 

static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

bool search(struct Node* head, int x)
{
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

void serialize(struct Node* root) {
    FILE* file = fopen("list.txt", "w");
    if (file == NULL) {
        exit(1);
    }

    for (struct Node* curr = root; curr != NULL; curr = curr->next) {
        fprintf(file, "%d, ", curr->data);
    }
    fclose(file);
}

void deserialize(struct Node** root) {
    FILE* file = fopen("list.txt", "r");
    if (file == NULL) {
        exit(2);
    }

    int val;
    while(fscanf(file, "%d, ", &val) > 0) {
        append(root, val);
    }
    fclose(file);
}


int main()
{
    struct Node* head = NULL;
    
    append(&head, 12);
    append(&head, 16);
    display(head);
    

    
    printf("\n\n\t\tLinked List options\n\n\n");
    int choice;
    

    while(1)
    {
        system("clear");
        printf("1. Append\n");
        printf("2. Prepend\n");
        printf("3. Reverse\n");
        printf("4. Add a value to the specific index \n");
        printf("5. Remove a value the from index\n");
        printf("6. Sort the linked list\n");
        printf("7. Search for a value \n");
        printf("8. Display list\n");
        printf("0. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:{
                int data;
                scanf("%d", &data);
                append(&head, data);
                break;
            }
            case 2:{
                int data;
                scanf("%d", &data);
                prepend(&head, data);
                break;
            }
        
            case 3:{
                reverse(&head);
                break;
            }
            
            case 4:
                printf("Enter number:\n");
                break;
                
            case 5:
                printf("Enter number:\n");
                break;
            
            case 6:
                quick_sort(head, last_node(head));
                break;
                
            case 7:{
                int data;
                scanf("%d", &data);
                search(head, data) ? printf("Yes") : printf("No");
                printf("\n");
                
                break;
            }
                
            case 8:
                display(head);
                break;
                
            case 0:
                return(0);    // terminates the complete program execution
        }
    }
    return 0;
}
