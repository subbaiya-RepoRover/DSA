#include <stdio.h>
union Data {
    int integer;
    float floating;
    char character;
};

int main() {
    union Data data;
    printf("Enter an integer value: ");
    scanf("%d", &data.integer);
    printf("Enter a float value: ");
    scanf("%f", &data.floating);
    printf("Enter a character value: ");
    scanf(" %c", &data.character);
    printf("\nValues stored in the union:\n");
    printf("Integer value: %d\n", data.integer);
    printf("Float value: %f\n", data.floating);
    printf("Character value: %c\n", data.character);

    return 0;
}
