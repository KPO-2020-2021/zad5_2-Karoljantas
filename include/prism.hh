#pragma once
#include "bryla.hh"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */
class  prism: public bryla
{
 
   public:
    prism(){};
    prism(  Vector<3> pkt0, double wysokosc, double szerokosc, double dlugosc, std::string nazwa);
/*!
 * Funkcja opisujaca zapis                                                          |
 *  Argumenty:                                                                |
 *                                                |
 */
bool Zapis()
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(nazwa);
  if (!StrmPlikowy.is_open())
    {

    return false;
  }

 for(int i=0;i< 8;i++)
    {
    StrmPlikowy<<point[i]<<std::endl;
    if((i+1)%2==0)
      StrmPlikowy<<std::endl;
    }
    StrmPlikowy<<point[0]<<std::endl;
     StrmPlikowy<<point[1]<<std::endl;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

};

/*!
 * Konstruktor parametryczny budujacy prostopadloscian przez obliczenie wierzcholkow na podstawie
 * podanych danych punbktu pierwszego oraz długiosci i szerokosci
 * \param[in] pkt0 - wektor poczatkowy okreslajacy lewy dolny rog prostopadloscianu
 * \param[in] wysokosc - parametr przyjmujacy wysokosci prostopadloscianu
 * \param[in] szerokosc - parametr przyjmujacy szerokosc prostopadloscianu
 \param[in] dlugosc - parametr przyjmujacy dlugosc  prostopadloscianu
 */
  prism:: prism(  Vector<3> pkt0, double wysokosc, double szerokosc, double dlugosc, std::string nazwa)
 {
     SIZE=8;
     this->nazwa=nazwa;
     point.resize(SIZE);
     for(int i=0;i< SIZE;i++)
 point[i]=pkt0;

  srodek[0]=pkt0[0]+szerokosc/2;
    srodek[1]=pkt0[1]+wysokosc/2;
      srodek[2]=pkt0[2]+dlugosc/2;
 point[1][0]+=szerokosc;

 point[2][1]+=wysokosc;

 point[3][0]+=szerokosc;
 point[3][1]+=wysokosc;

 point[4][1]+=wysokosc;
  point[4][2]+=dlugosc;

 point[5][0]+=szerokosc;
 point[5][1]+=wysokosc;
 point[5][2]+=dlugosc;

  point[6][2]+=dlugosc;

 point[7][0]+=szerokosc;
 point[7][2]+=dlugosc;
 }

/*!
*  Przeciazenie operatora <<                                                                                                               
 * \param[in]     out - strumien wejsciowy,                                             
 * \param[in]    tmp - prostokat.                                                         
 */
std::ostream &operator <<(std::ostream &out,const  prism &tmp )
{
    for(int i=0;i< 8;i++)
    {
    out<<tmp[i]<<std::endl;
    if((i+1)%2==0)
      out<<std::endl;
    }
    out<<tmp[0]<<std::endl;
     out<<tmp[1]<<std::endl;
     return out;
}






