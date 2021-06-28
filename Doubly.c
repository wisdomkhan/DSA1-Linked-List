#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *last = NULL; //last is same tail

void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int pos);
void delEnd();
void delFront();
void delAtn(int pos);

void delEnd(){
    if(head == NULL)
        printf("empty list\n");
    else{
        struct node *temp;
        temp = last -> prev;
        temp -> next = NULL;
        last -> prev = NULL;
        last = temp;
        printf("Node at end deleted.\n");
        displayList();
    }
}

void delFront(){
    head -> next -> prev = NULL;
    head = head ->next;
    printf("Front node deleted\n");
    displayList();
}

void delAtn(int pos){
    int i = 1;
    struct node *loop = head;
    while(loop != NULL && i < pos){
        loop = loop->next;
        i++;
    }
    loop -> prev -> next = loop -> next;
    loop -> prev = NULL;
    loop -> next = NULL;
    printf("Node %d deleted\n", pos);
    displayList();
}

int main()
{
    int n, pos, data, choice = 1;
    while (choice != 0)
    {
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Insert node - at N\n");
        printf("5. Display list\n");
        printf("6. Delete at end\n");
        printf("7. Delete at front\n");
        printf("8. Delete at position\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the total number of nodes in list: ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            printf("Enter data of first node: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data of last node : ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            printf("Enter the position where you want to insert new node: ");
            scanf("%d", &pos);
            printf("Enter data of %d node : ", pos);
            scanf("%d", &data);
            insertAtN(data, pos);
            break;
        case 5:
            displayList();
            break;
        case 6:
            delEnd();
            break;
        case 7:
            delFront();
            break;
        case 8:
            printf("Enter position of node to be deleted\n");
            scanf("%d", &pos);
            if(pos > 1 && pos < n)
                delAtn(pos);
            else if(pos==1)
                delFront();
            else if(pos==n)
                delEnd();
            else
                printf("Invalid position");
            break;
        case 0:
            break;
        default:
            printf("Error! Invalid choice. Please choose between 0-8");
        }
        printf("\n");
    }
    return 0;
}

void createList(int n)
{
    int i = 2, data;
    if (n >= 1)
    {
        for (i = 1; i <= n; i++)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            if (head == NULL)
            {
                printf("Enter 1st node: ");
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                newNode->prev = NULL;
                last = newNode;
                head = newNode;
            }
            else
            {
                printf("Enter next node ");
                scanf("%d", &data);
                newNode->data = data;
                newNode->prev = last;
                newNode->next = NULL;
                last->next = newNode;
                last = newNode;
            }
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        displayList();
    }
}

void displayList()
{
    struct node *temp = head;
    int n = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("DATA IN THE LIST:\n");
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            n++;
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insertAtBeginning(int data)
{
    struct node *newNode;

    if (head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
        displayList();
    }
}

void insertAtEnd(int data)
{
    struct node *newNode;

    if (last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
        displayList();
    }
}

void insertAtN(int data, int pos)
{
    int i = 1;
    struct node *newNode, *temp = head;

    if (head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (pos == 1)
            insertAtBeginning(data);
        else if (temp == last)
            insertAtEnd(data);
        else if (temp != NULL) // position found
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) // checking if it is the end of list
                temp->next->prev = newNode;
            temp->next = newNode;
            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", pos);
            displayList();
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}