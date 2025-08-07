// escape.c

// A complete C Program
#include <stdio.h>

int main(int argc, char** argv){

    float salary;
    printf("Enter your monthly salary: ");
    printf("$______\b\b\b\b\b\b");
    scanf("%f", &salary);

    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");

    return 0;
}
