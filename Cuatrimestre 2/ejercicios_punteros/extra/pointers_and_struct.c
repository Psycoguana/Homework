#include <stdio.h>
#include <stdlib.h>

// Ingresar 5 nombres con edades y printearlos
#define N 2

struct Person {
  char name[20];
  int age;
};

inputData(struct Person[]);
showData(struct Person[]);

int main(int argc, char const *argv[]) {
  struct Person array[N];
  struct Person *p;

  inputData(array);

  showData(array);

  printf("\n\n");
  return 0;
}

inputData(struct Person array[]) {
  struct Person *p;
  for (p = array; p < array + N; p++) {
    printf("Ingrese un nombre:");
    gets(p->name);

    printf("Ingrese una edad: ");
    scanf("%d", &(p->age));
    clean_stdin();
  }
}

showData(struct Person array[]) {
  struct Person *p;
  for (p = array; p < array + N; p++) {
    printf("%s", p->name);
    printf("%d", p->age);
  }
}

void clean_stdin(void) {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}