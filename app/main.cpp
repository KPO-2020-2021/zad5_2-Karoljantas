// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>
#include "scena.hh"
#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "Graniastoslup6.hh"


/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150

int main() {
  srand(time(NULL));
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;





 
  char opcja;

Scena a;
std::cout<<"obruc"<<std::endl;
std::cout<<"powtorz obroc"<<std::endl;
std::cout<<"przesun"<<std::endl;
std::cout<<"wyswietl wiezcholki"<<std::endl;
std::cout<<"move"<<std::endl;

while (opcja != 'k')
{
     a.Zapis();
     a.opcja();
      a.Zapis();
  std::cout<<"opcja"<<std::endl;
    std::cin>>opcja;

}

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}

