/* getting-started.c */

/* A complete C Program */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, [[maybe_unused]] char* argv[argc+1]){

    double values[5] = {[0] = 9.0, [1] = 2.9, [4] = 3.E+25, [3] = 0.00007};
    for (size_t i = 0; i < 5; i++) {
        printf("values[%zu] is %g, \tIt is square is %g\n",
            i, values[i], values[i] * values[i]);
    }
}
