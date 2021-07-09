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
void create(struct node **p){
    // we used **p and not *p as in display as we need a tail to point to it too
    // ASK MUSKAN IF ABOVE CMNT IS T/F
    struct node *newTerm = (struct node *)malloc(sizeof(struct node));
    struct node *tail = *p; // tail is a simple node which points to address of p

    printf("Enter coefficient and power ");
    scanf("%d %d", &newTerm->cof, &newTerm->pow);
    newTerm->next = NULL;

    if(tail == NULL){
        *p = newTerm;
        tail = *p; // assign it the first node
    }
    else{
        tail->next = newTerm;
        tail = newTerm;
    }
}

void display(struct node *poly){
    printf("\n");
    struct node *p = poly; // temp var p to save *p so we do not change it
    while(p != NULL){
        if (p->cof != 0 && p->cof != 1 && p->pow > 1)
            printf("%dx^%d", (p->cof > 0) ? (p->cof) : (-p->cof), p->pow);
        else if (p->cof != 0 && p->pow == 0)
            printf("%d", (p->cof > 0) ? (p->cof) : (-p->cof));
        else if (p->cof != 0 && p->cof != 1 && p->pow == 1)
            printf("%dx", (p->cof > 0) ? (p->cof) : (-p->cof));
        else if (p->cof == 1 && p->pow > 1)
            printf("x^%d", p->pow);
        else if (p->cof == 1 && p->pow == 1)
            printf("x");

        if (p->next != NULL)
            {
                if (p->next->cof > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
        p = p->next;
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