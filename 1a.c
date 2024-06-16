#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Congratulations! You are eligible for casting your vote.\n");
    } else {
        printf("You are not eligible for casting your vote.\n");
    }

    return 0;
}
