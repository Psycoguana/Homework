// Construir un programa que se denomine GRADOS.EXE y que se invoque desde línea de comandos con dos argumentos.
// El primero representa un valor de temperatura y tiene formato flotante.
// El segundo representa el sistema en que está expresada dicha temperatura y puede ser:
// C(Celsius), F(Farenheit) o K(Kelvin).
// GRADOS 57.25 F 
// Debe mostrarse en pantalla el equivalente de la temperatura en los tres sistemas.

#include <stdio.h>
#include <stdlib.h>

          float cToF(float);
float fToK(float);
float kToC(float);

int main(int argc, char const *argv[]) {

  float argTemp = atof(argv[1]);
  char system = argv[2][0];

  float cTemp, fTemp, kTemp;

  switch (system) {
  case 'C':
    cTemp = argTemp;
    fTemp = cToF(cTemp);
    kTemp = fToK(fTemp);
    break;

  case 'F':
    fTemp = argTemp;
    kTemp = fToK(fTemp);
    cTemp = kToC(kTemp);
    break;

  case 'K':
    kTemp = argTemp;
    cTemp = kToC(kTemp);
    fTemp = cToF(cTemp);
    break;

  default:
    break;
  }

  printf("Temperaturas convertidas desde °%c:\n\n", system);
  printf("Celcius: %.2f\nFarenheitt: %.2f\nKelvin: %.2f", cTemp, fTemp, kTemp);
  printf("\n\n");
  return 0;
}

float cToF(float cTemp) { return (cTemp * 9 / 5) + 32; }

float fToK(float fTemp) { return (fTemp - 32) * 5 / 9 + 273.15; }

float kToC(float kTemp) { return kTemp - 273.15; }
