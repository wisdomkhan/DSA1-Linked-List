#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    float p;
    struct node *prev;
    struct node *next;
} * head, *last;

void createList(int);
void displayList();

int main()
{
    int n;
    head = NULL;
    last = NULL;
    printf("Enter the total number of students: ");
    scanf("%d", &n);
    createList(n);
    printf("\n\n\n");
    displayList();
    return 0;
}

void createList(int n)
{
    int i, id;
    float p;
    struct node *newNode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter ID and percentage of 1 student: ");
        scanf("%d%f", &id, &p);
        head->id = id;
        head->p = p;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter ID and percentage of %d student: ", i);
            scanf("%d%f", &id, &p);
            newNode->id = id;
            newNode->p = p;
            newNode->prev = last;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }
    }
}

void displayList()
{
    struct node *temp;
    int n = 1;
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("ID : %d    Percentage : %.1f\n", temp->id, temp->p);
            n++;
            temp = temp->next;
        }
        printf("\n");
    }
}