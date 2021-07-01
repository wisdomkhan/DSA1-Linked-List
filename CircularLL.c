#include <stdio.h>
#include <stdlib.h>

// delFront not  working
// display not working when inside other functions
// Empty ist is printed at last

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;

int n = 0;

void display() // treaversal
{
    struct node *current = head;
    if (head == NULL)
        printf("Empty list\n");
    else
    {
        while (current != tail)
        {
            printf("%d ", current->data);
            current = current->next;
            printf(" -> ");
        }
        printf("%d -> NULL\n", tail->data);
    }
}

void addNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    n++;
    display();
    printf("n=%d\n", n);
}

void addAtPos(int data, int pos) // this is same as addBefore
{
    int i = 1; //run from 1 as loop starts from head
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct node *loop = head;
        struct node *prev = head;
        while (loop != NULL && i <= pos)
        {
            if (i == pos)
            {
                prev->next = newNode; //prev node points to new node
                newNode->next = loop; //new node points to current node
                printf("New node added before %d\n", pos);
                break;
            }
            i++;
            prev = loop; //stores previous node
            loop = loop->next;
        }
    }
    n++;
    display();
    printf("n=%d\n", n);
}

void addFront(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node %d added at front\n", head->data);
    n++;
    display();
    printf("n=%d\n", n);
}

void delEnd()
{
    struct node *loopNode = head;
    struct node *prev = head;
    while (loopNode->next != NULL)
    {
        prev = loopNode;
        loopNode = loopNode->next;
    }
    prev->next = head;
    tail = prev;
    printf("Node deleted at end\n");
    n--;
    display();
    printf("n=%d\n", n);
}

void delFront()
{
    struct node *temp;
    temp = head;
    head = head->next;
    temp->next = NULL;
    printf("Node (value=%d) at front deleted\n", temp->data);
    n--;
    display();
    printf("n=%d\n", n);
}

void delAtn(int pos)
{
    int i = 1;
    struct node *loop = head;
    while (loop != NULL && i < pos - 1) // exit form loop as soon as we reach the node before node to be deleted
    {
        i++;
        loop = loop->next;
    }
    int d;
    d = loop->next->data;
    loop->next = loop->next->next;
    printf("%d deleted\n", d);
    n--;
    display();
    printf("n=%d\n", n);
}

int main()
{
    int data, i = 1;
    int v1, v2, pos;
    printf("Enter nodes\n");
    while (i <= 5)
    {
        scanf("%d", &data);
        addNode(data);
        i++;
    }
    printf("Enter value and position where to add\n");
    scanf("%d %d", &v2, &pos);
    if (pos > 5 || pos < 1)
        printf("Invalid position\n");
    else
        addAtPos(v2, pos);
    printf("Enter value to add at the beginning ");
    scanf("%d", &v1);
    addFront(v1);
    printf("Enter position of node to delete ");
    scanf("%d", &pos);
    if (pos == 1)
        delFront();
    else if (pos == n)
        delEnd();
    else
        delAtn(pos);
    delFront();
    delEnd();
    display();
}