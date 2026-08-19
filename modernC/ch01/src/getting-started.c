/* getting-started.c */

/* A complete C Program */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, [[maybe_unused]] char **argv) {

  double numbers[] = {
      [0] = 9.0,
      [1] = 2.9,
      [4] = 3.E+25,
      [3] = .00007,
  };
  for (size_t i = 0; i < 5; i++) {
    printf("numbers[%zu] is %g, \tIt is square is %g\n", i, numbers[i],
           numbers[i] * numbers[i]);
  }

  return EXIT_SUCCESS;
}
