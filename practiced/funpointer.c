// funpointer.c
// A complete C Program
#include <stdio.h>
#include <string.h>

#define MSIZE 4
#define MONTHS 12

void show(void (*fn)(char*), char*);
void print(char* msg);
void get_three_lettered_name(char*);
void get_days_n_numbers(unsigned int*);

/* struct */
typedef struct month {
    char name[MSIZE];
    unsigned int days;
    unsigned int month_number;
} Month;

void print_month(const Month*);
void init_month(Month*);

int main(int argc, char** argv){

    show(print, "Hello, World!");

    //
    Month months[MONTHS] = {{"jan", 31, 1},{"feb", 28, 2}};

    for (size_t i = 2; i < 4; i++) {
        init_month(&months[i]);
    }

    for (size_t i = 0; i < MONTHS; i++)
        print_month(&months[i]);

    return 0;
}

void init_month(Month* month) {
    printf("Enter month name: ");
    get_three_lettered_name(month->name);
    printf("Enter number of days in %s : ", month->name);
    get_days_n_numbers(&month->days);
    printf("Enter %s number: ", month->name);
    get_days_n_numbers(&month->month_number);
}

void print_month(const Month* month) {
    printf("Month{ Name: %s, Days: %d, Number: %d }\n",
        month->name, month->days, month->month_number);
}

void show(void (*fn)(char*), char* ch) {
    fn(ch);
}

void print(char* msg) {
    printf("%s\n", msg);
}

void get_three_lettered_name(char* month) {
    char name[MSIZE];
    int ch, count = 0;
    while((ch = getchar())) {
        if (count == 3) break;
        name[count++] = (char)ch;
    }
    name[count] = '\0';
    while(getchar() != '\n');
    strncpy(month, name, MSIZE);
}

void get_days_n_numbers(unsigned int* number) {
    scanf("%u", number);
    while(*number < 1 || *number > 31) {
        puts("Number should be between 1 and 31.");
        scanf("%d", number);
    }
    while(getchar() != '\n');
}
