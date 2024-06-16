#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

// Function to create a new polynomial term node
PolyNode* createNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in the polynomial linked list
void insertNode(PolyNode** poly, int coeff, int exp) {
    PolyNode* newNode = createNode(coeff, exp);
    newNode->next = *poly;
    *poly = newNode;
}

// Function to display a polynomial
void displayPoly(PolyNode* poly) {
    PolyNode* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}
// Function to add two polynomials
PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode* temp1 = poly1;
    PolyNode* temp2 = poly2;
   while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            insertNode(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
  } else if (temp1->exp > temp2->exp) {
            insertNode(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
} else {
            insertNode(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertNode(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertNode(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to subtract two polynomials
PolyNode* subtractPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode* temp1 = poly1;
    PolyNode* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            insertNode(&result, temp1->coeff - temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insertNode(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insertNode(&result, -temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
   while (temp1 != NULL) {
        insertNode(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertNode(&result, -temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode* temp1 = poly1;
    PolyNode* temp2;
while (temp1 != NULL) {
        temp2 = poly2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            PolyNode* resTemp = result;
            PolyNode* prev = NULL;

            while (resTemp != NULL && resTemp->exp > exp) {
                prev = resTemp;
                resTemp = resTemp->next;
            }

            if (resTemp != NULL && resTemp->exp == exp) {
                resTemp->coeff += coeff;
            } else {
                PolyNode* newNode = createNode(coeff, exp);
                if (prev == NULL) {
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

int main() {
    PolyNode* poly1 = NULL;
    PolyNode* poly2 = NULL;

    // Example polynomials
    insertNode(&poly1, 5, 0);
    insertNode(&poly1, 4, 1);
    insertNode(&poly1, 3, 2);

    insertNode(&poly2, 1, 1);
    insertNode(&poly2, 3, 2);
    insertNode(&poly2, 2, 3);

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
displayPoly(poly2);

    PolyNode* sum = addPolynomials(poly1, poly2);
    printf("Polynomial Addition: ");
    displayPoly(sum);

    PolyNode* difference = subtractPolynomials(poly1, poly2);
    printf("Polynomial Subtraction: ");
    displayPoly(difference);

    PolyNode* product = multiplyPolynomials(poly1, poly2);
    printf("Polynomial Multiplication: ");
    displayPoly(product);

    return 0;
}


