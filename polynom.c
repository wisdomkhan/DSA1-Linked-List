#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node {
    int coeff;
    int power;
    struct node *link;
};

void createPolynomial(struct node **n) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = *n;

    printf("Enter the coefficient and power: ");
    scanf("%d", &(new_node->coeff));
    scanf("%d", &(new_node->power));

    new_node->link = NULL;

    if(*n == NULL) {
        *n = new_node;
        return;
    }

    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void displayPolynomial(struct node *n) {
    printf("[ ");
    while (n != NULL) {
        if(n->coeff > 0) {
            if(n->power > 1) {
                printf("%dx^(%d)", n->coeff, n->power);
            }
            else if(n->power == 1) {
                printf("%dx", n->coeff);
            }
            else {
                printf("%d", n->coeff);
            }
        }
        else if(n->coeff < 0) {
            if(n->power > 1) {
                printf("(%d)x^(%d)", n->coeff, n->power);
            }
            else if(n->power == 1) {
                printf("(%d)x", n->coeff);
            }
            else {
                printf("(%d)", n->coeff);
            }
        }
        // COEFFICIENT == 0
        else {
            printf("0");
        }

        if(n->link != NULL) {
            printf(" + ");
        }
        n = n->link;
    }
    printf(" ]");
}

void addNode(struct node **n, int c, int p) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    struct node *ptr = *n;

    new_node->coeff = c;
    new_node->power = p;
    new_node->link = NULL;

    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void addPolynomial(struct node **p1, struct node **p2) {
    struct node *ptr1 = *p1;
    struct node *ptr2 = *p2;

    while (ptr1 != NULL) {
        ptr2 = *p2;
        while (ptr2 != NULL) {
            if(ptr1->power == ptr2->power) {
                ptr1->coeff += ptr2->coeff;
                ptr2->coeff = 0;
            }
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    
    ptr1 = *p1;
    ptr2 = *p2;
    while (ptr1->link != NULL) {
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL) {
        if(ptr2->coeff != 0) {
            addNode(p1, ptr2->coeff, ptr2->power);
        }
        ptr2 = ptr2->link;
    }
}

int main() {
    struct node *first = NULL;

    int num=0;
    printf("enter no. of elements for pol-1: ");
    scanf("%d", &num);

    for (size_t i = 0; i < num; i++) {
        createPolynomial(&first);
    }
    displayPolynomial(first);

    struct node *second = NULL;
    printf("\nenter no. of elements for pol-2: ");
    scanf("%d", &num);

    for (size_t i = 0; i < num; i++) {
        createPolynomial(&second);
    }
    displayPolynomial(second);

    addPolynomial(&first, &second);
    printf("\n");
    displayPolynomial(first);
    
    return 0;
}