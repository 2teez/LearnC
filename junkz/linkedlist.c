// linkedlist.c

// A complete C Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

typedef struct Movie *pmovie;

typedef struct Movie {
    char name[SIZE];
    int rating;
    pmovie next;
} movie;

char * get_name(char*, int);

int main(int argc, char** argv){

    pmovie head = NULL;
    pmovie current, previous;

    char input[SIZE];

    // get info
    puts("Enter the movie name: ");
    while(get_name(input, SIZE) != NULL && input[0] != '\0') {
        current = malloc(sizeof(movie));
        if (head == NULL)
            head = current;
        else
            previous->next = current;
        current->next = NULL;
        strncpy(current->name, input, SIZE);
        puts("Enter the movie rating <1-10>:");
        scanf("%d", &current->rating);
        while(getchar() != '\n');
        puts("Enter next movie title (empty line to stop):");
        previous = current;
    }

    // print all the movies
    if (head == NULL) {
        puts("No Data Present.");
    } else {
        current = head;
        while(current != NULL) {
            printf("Movie titled: %s is rated: %d\n", current->name, current->rating);
            current = current->next;
        }
    }

    // free all the data used
    if (head != NULL) {
        current = head;
        while(current != NULL) {
            pmovie temp = current->next;
            free(current);
            current = temp;
        }
    }

    return 0;
}

char * get_name(char* ch, int size) {
    char* result;

    result = fgets(ch, size, stdin);
    if (!result) {
        printf("N/A string.");
        exit(EXIT_FAILURE);
    }
    char * find = strchr(ch, '\n');
    if (find) *find = '\0';
    else while(getchar() != '\n');
    return result;
}
