#pragma once
#include "bryla.hh"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */
class  Graniastoslup6: public bryla
{
 
   public:
    Graniastoslup6(){};
    Graniastoslup6(  Vector<3> srodek,double promien, std::string nazwa);
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

  for(int i=0;i< 12;i++)
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
  Graniastoslup6:: Graniastoslup6(  Vector<3> srodek,double promien, std::string nazwa)
 {
     SIZE=12;
     this->srodek=srodek;
     this->nazwa=nazwa;
    Vector<3> tmp;
    for(int i=0; i<=300; i+=60){
        tmp[2]=srodek[2];
        tmp[0]=srodek[0]+promien*sin(i*M_PI/180);
        tmp[1]=srodek[1]+promien*cos(i*M_PI/180);
        point.push_back(tmp);
        tmp[2]=srodek[2]+20;
        tmp[0]=srodek[0]+promien*sin(i*M_PI/180);
        tmp[1]=srodek[1]+promien*cos(i*M_PI/180);
        point.push_back(tmp);
    }
 }

/*!
*  Przeciazenie operatora <<                                                                                                               
 * \param[in]     out - strumien wejsciowy,                                             
 * \param[in]    tmp - prostokat.                                                         
 */
std::ostream &operator <<(std::ostream &out,const  Graniastoslup6 &tmp )
{
    for(int i=0;i< 12;i++)
    {
    out<<tmp[i]<<std::endl;
    if((i+1)%2==0)
      out<<std::endl;
    }
   
     return out;
}





