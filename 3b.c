#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for shape types
#define CIRCLE 0
#define SQUARE 1
#define RECTANGLE 2

// Define a structure for a circle
struct Circle {
    double radius;
};

// Define a structure for a square
struct Square {
    double sideLength;
};

// Define a structure for a rectangle
struct Rectangle {
    double length;
    double width;
};
// Define a union for representing different shapes
union Shape {
    struct Circle circle;
    struct Square square;
    struct Rectangle rectangle;
};

// Function to calculate the area of a circle
double calculateCircleArea(struct Circle c) {
    return M_PI * c.radius * c.radius;
}

// Function to calculate the area of a square
double calculateSquareArea(struct Square s) {
    return s.sideLength * s.sideLength;
}
// Function to calculate the area of a rectangle
double calculateRectangleArea(struct Rectangle r) {
    return r.length * r.width;
}
// Function to calculate and display the area of each shape
void displayAreas(union Shape shapes[], int numShapes) {
    printf("Areas of shapes:\n");
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                printf("Area of circle %d: %.2f\n", i + 1, area);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                printf("Area of square %d: %.2f\n", i + 1, area);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                printf("Area of rectangle %d: %.2f\n", i + 1, area);
                break;
        }
    }
}

// Function to find the largest area among the shapes
double findLargestArea(union Shape shapes[], int numShapes) {
    double largestArea = 0.0;
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                break;
        }
        if (area > largestArea) {
            largestArea = area;
        }
    }
    return largestArea;
}

int main() {
    int numShapes;

    // the user to enter the number of shapes
    printf("Enter the number of shapes: ");
    scanf("%d", &numShapes);

    // Dynamically allocate memory to store the shapes
    union Shape* shapes = (union Shape*)malloc(numShapes * sizeof(union Shape));
    if (shapes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read details for each shape
    for (int i = 0; i < numShapes; i++) {
        int shapeType;
        printf("Enter type of shape (0 for circle, 1 for square, 2 for rectangle) for shape %d: ", i + 1);
        scanf("%d", &shapeType);
        switch (shapeType) {
            case CIRCLE:
                printf("Enter radius of circle: ");
                scanf("%lf", &shapes[i].circle.radius);
                break;
            case SQUARE:
                printf("Enter side length of square: ");
                scanf("%lf", &shapes[i].square.sideLength);
                break;
            case RECTANGLE:
                printf("Enter length and width of rectangle: ");
                scanf("%lf %lf", &shapes[i].rectangle.length, &shapes[i].rectangle.width);
                break;
            default:
                printf("Invalid shape type\n");
                free(shapes);
                return 1;
        }
    }
    // Display the area of each shape
    displayAreas(shapes, numShapes);

    // Find and print the largest area among the shapes
    double largestArea = findLargestArea(shapes, numShapes);
    printf("\nLargest area among the shapes: %.2f\n", largestArea);

    // Free dynamically allocated memory
    free(shapes);

    return 0;
}
