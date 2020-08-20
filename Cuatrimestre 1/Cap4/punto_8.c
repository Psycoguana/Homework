#include <stdio.h>
#include <stdlib.h>

int isAmigo(unsigned int number_1, unsigned int number_2);
int sumModules(unsigned int number);

int main(int argc, char const *argv[]) {
  int num_1 = 220, num_2 = 284;
  
  if (isAmigo(num_1, num_2) == 0) {
    printf("%d y %d son amigos", num_1, num_2);
  } else {
    printf("%d y %d NO son amigos", num_1, num_2);
  }

  printf("\n\n");
  return 0;
}

int isAmigo(unsigned int number_1, unsigned int number_2) {
  int sum_1 = sumModules(number_1);
  int sum_2 = sumModules(number_2);

  // Se compara que la suma del primer número sea igual
  // a el 2do, y viceversa.
  if (sum_1 == number_2 && sum_2 == number_1) {
    return 0;
  } else {
    return 1;
  }
}

int sumModules(unsigned int number) {
  // Se suman los números cuyo módulo de number sea 0
  int count;
  int sum = 0;

  for (count = 1; count < number; count++) {
    if (number % count == 0) {
      sum += count;
    }
  }

  return sum;
}
