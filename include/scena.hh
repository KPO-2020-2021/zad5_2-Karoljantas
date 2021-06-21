#pragma once
#include "dron.hh"
#include "Gran.hh"
#include "Gora.hh"
#include "Plaskowyz.hh"
#include "powierzchnia.hh"
#include <list>
#include <memory>
using namespace std;
/*!
 * \brief Kalasa opisujaca scene
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu scene
 */
#include "../include/lacze_do_gnuplota.hh"
class Scena {
  std::list<shared_ptr<bryla>> lista_przeszkod;
  PzG::LaczeDoGNUPlota Lacze;
  Powierzchnia *dno;
  int nr_ob;
  Dron *nowy[2];

public:
  Scena() {
    double argumentsV2[] = {10.0, 25.0, 10.0};
    double argumentsV3[] = {-100.0, -105.0, -10.0};
        double argumentsV4[] = {100.0, 105.0, 0};
    nowy[0] = new Dron(0, argumentsV2);
    nowy[1] = new Dron(1, argumentsV3);
    nr_ob=3;
    lista_przeszkod.push_front(make_shared<Gran>(argumentsV4,100,150,150,"../datasets/obiekt0.dat"));
      Lacze.DodajNazwePliku("../datasets/obiekt0.dat");
         argumentsV4[0]=rand()%400-200;
         argumentsV4[1]=rand()%400-200;
       
    lista_przeszkod.push_front(make_shared<Plaskowyz>(argumentsV4,100,150,150,"../datasets/obiekt1.dat"));
      Lacze.DodajNazwePliku("../datasets/obiekt1.dat");
     argumentsV4[0]=rand()%400-200;
         argumentsV4[1]=rand()%400-200;
       
    lista_przeszkod.push_front(make_shared<Gora>(argumentsV4,100,150,250,"../datasets/obiekt2.dat"));
      Lacze.DodajNazwePliku("../datasets/obiekt2.dat");
    for (int i = 0; i < 2; i++) {
      Lacze.DodajNazwePliku(
          ("../datasets/prostopadloscian" + std::to_string(i) + ".dat").c_str());
      for (int j = 0; j < 4; j++)
        Lacze.DodajNazwePliku(
            ("../datasets/gra" + std::to_string(i) + std::to_string(j) + ".dat")
                .c_str());
    }
    Lacze.DodajNazwePliku("../datasets/dno.dat");
    Lacze.ZmienTrybRys(PzG::TR_3D);
    // Ustawienie zakresow poszczegolnych osi
    Lacze.UstawZakresY(-400, 400);
    Lacze.UstawZakresX(-400, 400);
    Lacze.UstawZakresZ(-400, 400);
    dno = new Powierzchnia(800, 800, -20, "../datasets/dno.dat");
  }

  void Zapis() {
      for (std::list<std::shared_ptr<bryla>>::const_iterator a = lista_przeszkod.begin(); a != lista_przeszkod.end(); a++)
  {

    (*a)->Zapis();
  }
    for (int i = 0; i < 2; i++)
      nowy[i]->Zapis();
    dno->Zapis();
    Lacze.Rysuj();
  }

  /*!
   * Funkcja opisująca opcje. | Argumenty: |
   *                                                |
   *     \param [in]        kat - kat                        |
   *            \param [in] nr   - nr drona |
   * \param [in] x  -droga |         
    *            \param [in] opc   - opcja |   
   */

  void opcja() {
            double argumentsV4[] = {100.0, 105.0, 0};
    int opc;
    double x, a;
    double kat = 0;
    int nr;
    std::cout << "1 normlany lot 2 okregi 3 dodaj przeszkode " << std::endl;
    std::cin >> opc;
    switch (opc) {
    case 1: {
      std::cout << "podaj nr drona: " << std::endl;
      std::cin >> nr;
      std::cout << "podaj drogę: " << std::endl;
      std::cin >> x;
      std::cout << "podaj kat: " << std::endl;
      std::cin >> kat;
      Lacze.DodajNazwePliku("../datasets/droga.dat");
      nowy[nr]->okresl_droge(x);
      for (int i = 0; i < 50; i++) {
        nowy[nr]->lot_w_gore();
        Zapis();
      }

      nowy[nr]->set_kat(kat);
      for (int i = 0; i < kat; i++) {

        nowy[nr]->obrot();

        Zapis();
      }
      for (int i = 0; i < x; i++) {
        nowy[nr]->przesun();

        Zapis();
      }
      for (int i = 0; i < 50; i++) {
        nowy[nr]->lot_w_dol();
        Zapis();
      }
       Lacze.UsunNazwePliku("../datasets/droga.dat");

    } break;
    case 2: {

      std::cout << "podaj nr drona: " << std::endl;
      std::cin >> nr;
      std::cout << "podaj drogę: " << std::endl;
      std::cin >> x;
      std::cout << "podaj kat: " << std::endl;
      std::cin >> kat;
      Lacze.DodajNazwePliku("../datasets/droga.dat");
      nowy[nr]->okresl_droge(x);
      for (int i = 0; i < 50; i++) {
        nowy[nr]->lot_w_gore();
        Zapis();
      }

      nowy[nr]->set_kat(kat);
      for (int i = 0; i < kat; i++) {

        nowy[nr]->obrot();

        Zapis();
      }
      for (int i = 0; i < x; i++) {
        nowy[nr]->przesun();

        Zapis();
      }

      a = (x * 2) / sqrt(4 + 2 * sqrt(2));
      nowy[nr]->okresl_droge(a);
      nowy[nr]->set_kat(112);
      for (int i = 0; i < 112; i++) {

        nowy[nr]->obrot();

        Zapis();
      }
      for (int i = 0; i < a; i++) {
        nowy[nr]->przesun();

        Zapis();
      }
      for (int i = 0; i < 7; i++) {
        nowy[nr]->okresl_droge(a);
        nowy[nr]->set_kat(45);
        for (int i = 0; i < 45; i++) {

          nowy[nr]->obrot();

          Zapis();
        }
        for (int i = 0; i < a; i++) {
          nowy[nr]->przesun();

          Zapis();
        }
      }
      nowy[nr]->set_kat(112);
      for (int i = 0; i < 112; i++) {

        nowy[nr]->obrot();

        Zapis();
      }
      for (int i = 0; i < x; i++) {
        nowy[nr]->przesun();

        Zapis();
      }

      for (int i = 0; i < 50; i++) {
        nowy[nr]->lot_w_dol();
        Zapis();
      }
      Lacze.UsunNazwePliku("../datasets/droga.dat");
    }
   

    break;
    case 3:

{
       argumentsV4[0]=rand()%400-200;
         argumentsV4[1]=rand()%400-200;
       int ob=rand()%3;

if(ob==0)
{
    lista_przeszkod.push_front(make_shared<Gora>(argumentsV4,100,150,250,"../datasets/obiekt" + std::to_string(nr_ob) + ".dat"));
      Lacze.DodajNazwePliku(("../datasets/obiekt" + std::to_string(nr_ob) + ".dat").c_str());
}if(ob==1)
{
    lista_przeszkod.push_front(make_shared<Plaskowyz>(argumentsV4,100,150,250,"../datasets/obiekt" + std::to_string(nr_ob) + ".dat"));
      Lacze.DodajNazwePliku(("../datasets/obiekt" + std::to_string(nr_ob) + ".dat").c_str());
}if(ob==2)
{
    lista_przeszkod.push_front(make_shared<Gran>(argumentsV4,100,150,250,"../datasets/obiekt" + std::to_string(nr_ob) + ".dat"));
      Lacze.DodajNazwePliku(("../datasets/obiekt" + std::to_string(nr_ob) + ".dat").c_str());
}
nr_ob++;
}
    break;
    default:
      break;
    }
  }
};