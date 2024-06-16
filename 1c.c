#include <stdio.h>

int main() {
    float temperature;
    printf("Enter the temperature in centigrade: ");
    scanf("%f", &temperature)
    if (temperature < 0) {
        printf("Freezing weather.\n");
    } else if (temperature < 10) {
        printf("Very Cold weather.\n");
    } else if (temperature < 20) {
        printf("Cold weather.\n");
    } else if (temperature < 30) {
        printf("Normal in Temp.\n");
    } else if (temperature < 40) {
        printf("Its Hot.\n");
    } else {
        printf("Its Very Hot.\n");
    }

    return 0;
}
