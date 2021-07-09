#include <stdio.h>
#include <stdlib.h>

struct node{
    int cof, pow;
    struct node* next;
};
struct node *p1 = NULL, *p2 = NULL;

// p1 is a pointer to first node of polynom 1
// **p stores address of p1 (=&p1)
// use *p to point to address of p1 and **p to value to which p1 points
void create(struct node **p)
{
    // we used **p and not *p as in display as we need a tail to point to it too
    // ASK MUSKAN Y IF ABOVE CMNT IS T/F
    struct node *newTerm = (struct node *)malloc(sizeof(struct node));
    struct node *tail; // tail is a simple node which points to address stored in p

    printf("Enter coefficient and power ");
    scanf("%d %d", &newTerm->cof, &newTerm->pow);
    newTerm->next = NULL;

    if(*p == NULL)
    {
        *p = newTerm; // assign it the first node
        tail = *p;
    }
    // CODE DIFFERS
    else{
        tail->next = newTerm;
        tail = newTerm;
    }
}

void display(struct node *p){
    printf("\n");
    struct node *temp;
    temp = p;
    while(temp != NULL){
        // if(temp->cof != 0){
        if (temp->cof != 0 && temp->pow > 1 && temp->cof != 1)
            printf("%dx^%d", (temp->cof>0)?(temp->cof):(-temp->cof), temp->pow);
        else if (temp->cof != 0 && temp->pow == 0)
            printf("%d", (temp->cof>0)?(temp->cof):(-temp->cof));
        else if (temp->cof != 0 && temp->pow == 1)
            printf("%dx", (temp->cof>0)?(temp->cof):(-temp->cof));
        else if (temp->cof == 1 && temp->pow > 0)
            printf("x^%d", temp->pow);
        else if (temp->cof == 1 && temp->pow == 1)
            printf("x");
        // }
        if (temp->next != NULL)
        {
            if(temp->next->cof > 0)
                printf(" + ");
            else
                printf(" - ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n;
    // creating polynom 1 and 2
    printf("Enter no of terms in poly 1 ");
    scanf("%d", &n);
    while(n!=0){
        // passing address of polynom 1, i.e., pointer to p1
        create(&p1);
        n--;
    }
    // displaying polynom
    display(p1);

    printf("Enter no of terms in poly 2 ");
    scanf("%d", &n);
    while (n != 0)
    {
        create(&p2);
        n--;
    }
    display(p2);
}