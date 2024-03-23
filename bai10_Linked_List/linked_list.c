#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* next;
}node;

// Function to create a new node
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

/* ---------------------------- */
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void push_front(node **array, int value) // them 1 node vao phia truoc
{
    // Create a new node with the provided value
    node* temp;
    temp = createNode(value);

    // Make the new node point to the head
    temp->next = *array;
    
    // Update the head pointer to point to the new node
    *array = temp;
}

/* ---------------------------- */

void pop_back(node** array) //Xoa node cuoi
{
    node* p, * temp;  //node* p ; node* temp;
    p = *array;
    // int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        // i++;
    }
    // Remove the last node and free its memory
    temp = p->next;
    p->next = NULL;
    free(temp);

}

// xoa node dau tien
void pop_front(node **array) 
{
    if (*array == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = *array; // Store the current head node 
    *array = (*array)->next; // Move head to the next node
    free(temp); // Free memory of the removed node
}


/* ---------------------------------------------- */

int front(node *array) // lay gia tri cua node dau tien
{ 
    int value = array->value;
    return value;
}

int back(node *array) // lay gia tri cua node cuoi cung
{
    while (array->next != NULL)
    {
        array = array->next;
    }

    int value = array->value;
    return value;
}

void insert(node **array, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    // Create a new node with the provided value
    node* temp;
    temp = createNode(value);

    int i = 0;
    node* p = *array;
    while (p->next != NULL && i < pos - 1) {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
}

void delete(node **array, int pos) // xoa 1 node tai mot vi tri bat ky
{   if (*array == NULL) {
        printf("List is empty\n");
        return;
    }

    int i = 0;
    node* temp = *array;
    node* p = NULL; // tạo 
    while (temp->next != NULL && i < pos) {
        p = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    p->next = temp->next;
    free(temp);
}

int size(node *array) // lay kich thuoc cua list
{
    int count = 0;
    while (array != NULL) {
        count++;
        array = array->next;
    }
    return count;
}

int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}


bool empty(node **array) // kiem tra list co rong hay khong
{
    if(*array == NULL) {
        printf("List is empty\n");
        return true;
    } else {
        printf("List is not empty\n");
        return false;
    }
}

// node *createNode(int value); 
// void push_back(node** array, int value); 
// void push_front(node **array, int value); // them 1 node vao phia truoc
// void pop_back(node **array); 
// void pop_front(node **array); // xoa node dau tien
// int front(node *array); // lay gia tri cua node dau tien
// int back(node *array); // lay gia tri cua node cuoi cung
/* void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void deletee(node **array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node **array); // lay kich thuoc cua list
// int get(node **array, int pos); 
bool empty(node **array); // kiem tra list co rong hay khong */


void show (node *arr)
{
     // Print the values of the linked list
    printf("Values of the linked list: ");
    node* temp = arr;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    push_front(&arr, 11);
    push_front(&arr, 8);

    show(arr);

    pop_front(&arr);
    
    pop_back(&arr);


    printf("Value test: %d\n", get(arr, 2)); 
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));

    printf("Value test: %d\n", front(arr));
    printf("Value test: %d\n", back(arr));

    empty(&arr);
    show(arr);

    insert(&arr, 15, 3);
    show(arr);

    delete(&arr, 3);
    show(arr);

    printf("Size: %d\n",size(arr));
	return 0;
}
