#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  double time_spent = 0.0;
  clock_t begin = clock();

  int num[2], cifra_1, cifra_2, cifra_3;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        cifra_1 = i;
        cifra_2 = j;
        cifra_3 = k;

        num[0] = cifra_1;
        num[1] = cifra_2;
        num[2] = cifra_3;
        printf("%d\n", num[0]);
        break;
        // int producto = (cifra_1 * cifra_1) + (cifra_2 * cifra_2) + (cifra_3 * cifra_3);

        // printf("%d\t%d\n", num, producto);
      }
    }
  }

  printf("\n\n");

  clock_t end = clock();
  printf("Time spent %f", time_spent);
  return 0;
}
