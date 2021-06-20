#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>

template <int SIZE>
class Matrix{

private:
    double value[SIZE][SIZE];               // Wartosci Matrixy

public:


    Matrix();                               // Konstruktor klasy

    Vector<SIZE> operator * (Vector<SIZE> tmp);           // Operator mnożenia przez wektor
                 // Operator mnożenia przez wektor
float  Wyznacznik();
    Matrix<SIZE> operator + (Matrix<SIZE> tmp);
      Matrix<SIZE> operator * (Matrix<SIZE> tmp);
void count_Matrix(double angle);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
};
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat);
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<SIZE> const &mat);
/*!
 *  operator wymnarzanaia macierzy                                                         |
 * Argumenty:                                                                |
 *     \param[in] this - parametr pierwszy.                                                  |
*    \param[in] tmp - pramatr drugi.                                               |
*                                                                    |
*    \retval  wynik iloczyn macierzy                            |
 */
template <int SIZE>
 Matrix<SIZE> Matrix<SIZE>::operator * (Matrix<SIZE> tmp)
 {
     Matrix<SIZE> wynik;
       for( int i = 0; i < SIZE; i++ )
    for(int j = 0; j < SIZE; j++ )
    {
      wynik(i,j) = 0;
      for( int k = 0; k < SIZE; k++ )  
      wynik(i,j) += value[ i ][ k ] * tmp(k,j);
  
    }
    return wynik;
 }
 /*!
 * Konstruktor klasy Matrix<SIZE>.                                                         |
 *                                                   |
 *                                                                    |
 *    \retval Matrix wypelnione wartoscia 0.                             |
 */

 template <int SIZE>
Matrix<SIZE>::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i==j)
      value[i][j] = 1;
            else
            value[i][j] = 0;
        }
    }
}

/*!
 * Realizuje mnozenie Matrixy przez wektor.                                                         |
 *  Argumenty:                                                                |
 *     \param[in] this - Matrix, czyli pierwszy skladnik mnozenia,                                                |
 *     \param[in] v - wektor, czyli drugi skladnik mnozenia.                                                  |
 *                                                                    |
 *    \retval   Iloczyn dwoch skladnikow przekazanych jako wektor.                             |
 */


template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator * (Vector<SIZE> tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/*!
 *  Funktor Matrixy                                                          |
 *  Argumenty:                                                                |
 *     \param[in] row - numer wiersza.                                                  |
 *     \param[in] column - numer kolumny.                                               |
 *                                                                    |
 *    \retval  Wartosc Matrixy w danym miejscu tablicy.                             |
 */
 template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
      throw "Error: Matrix jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
      throw "Error: Matrix jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}
/*!
 *     Funktor Matrixy                                                        |
 * Argumenty:                                                                |
 *     \param [in]  row - numer wiersza                                   |
*       \param [in]   column - numer kolumny.                                                           |
*    \retval  Wartosc Matrixy w danym miejscu tablicy jako stala.                          |
 */


 template <int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw "Error: Matrix jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
       throw "Error: Matrix jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}
/*!
 *    Przeciążenie dodawania Matrix                                                      |
 * Argumenty:                                                                |
 *     \param [in]  this - Matrix, czyli pierwszy skladnik dodawania,                                   |
*       \param [in]   v - wektor, czyli drugi skladnik dodawania.                                                           |
*    \retval iloczyn dwóch podanych Matrixy                          |
 */

 template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}
/*!
 *   Przeciazenie operatora >>                                                         |
 * Argumenty:                                                                |
 *     \param [in] mat - Matrix.                                    |
*                                                                    |
*    \param [in]  in - strumien wyjsciowy,                          |
 */

 template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}
/*!
 *  Przeciazenie operatora <<  y                                                         |
 * Argumenty:                                                                |
 *     \param [in] mat - Matrix.                                    |
*                                                                    |
*    \param [in]  out - strumien wejsciowy,                           |
 */


 template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
//modyfikacja 2d

template <int SIZE>
float Matrix<SIZE>::Wyznacznik()
{

float wyznacznik = 1;
Matrix<SIZE> tablica=*this;
for (int k = 0; k < SIZE - 1; k++)
{

for (int i = (1+k); i < SIZE; i++)
{


for (int j = (0+k); j < SIZE; j++)
{
tablica(i,j) = tablica(i,j)-((tablica(i,k) / tablica(k,k))*tablica(k,j));
}
}
}


for(int i =0 ; i<SIZE ;i++)
wyznacznik=wyznacznik*tablica(i,i);
return wyznacznik;

} 

/*!
 *  obr w okół x                                                            |
 *  Argumenty:                                                                |
 *     \param[in] kat - kat obr                                                  |
 *                                                 |
 *                                                                    |
 *   \retval  macierz obr                              |
 */
 Matrix<3> obr_x(double  kat)
{
    kat=kat*M_PI/180;
 Matrix<3> wynik;
 wynik(0,0)=1;
  wynik(0,1)=0;
   wynik(0,2)=0;
    wynik(1,0)=0;
     wynik(1,1)=cos(kat);
      wynik(1,2)=-sin(kat);
       wynik(2,0)=0;
        wynik(2,1)=sin(kat);
         wynik(2,2)=cos(kat);

         return wynik;

}
/*!
 *  obr w okół y                                                          |
 *  Argumenty:                                                                |
 *     \param[in] kat - kat obr                                                  |
 *                                                 |
 *                                                                    |
 *    \retval  macierz obr                              |
 */
 Matrix<3> obr_y(double  kat)
{
    kat=kat*M_PI/180;
 Matrix<3> wynik;
 wynik(0,0)=cos(kat);
  wynik(0,1)=0;
   wynik(0,2)=sin(kat);
    wynik(1,0)=0;
     wynik(1,1)=1;
      wynik(1,2)=0;
       wynik(2,0)=-sin(kat);
        wynik(2,1)=0;
         wynik(2,2)=cos(kat);

         return wynik;

}
/*!
 *  obr w okół z                                                          |
 *  Argumenty:                                                                |
 *     \param[in] kat - kat obr                                                  |
 *                                                 |
*                                                                   |
  *   \retval  macierz obr                              |
 */
 Matrix<3> obr_z(double  kat)
{
    kat=kat*M_PI/180;
 Matrix<3> wynik;
 wynik(0,0)=cos(kat);
  wynik(0,1)=-sin(kat);
   wynik(0,2)=0;
    wynik(1,0)=sin(kat);
     wynik(1,1)=cos(kat);
      wynik(1,2)=0;
       wynik(2,0)=0;
        wynik(2,1)=0;
         wynik(2,2)=1;

         return wynik;

}