#pragma once

#include "size.hh"
#include <iostream>


/*!
 * \brief Kalasa opisujaca vector
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu vectora
 */
template <int SIZE>
class Vector
{
private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector<SIZE> operator + (const Vector<SIZE> &v);

    Vector<SIZE> operator - (const Vector<SIZE> &v);

    Vector<SIZE> operator * (const double &tmp);

    Vector<SIZE> operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);
    
    bool operator==(const Vector<SIZE> arg) const;

};

template <int SIZE>
bool Vector<SIZE>::operator==(const Vector<SIZE> arg) const
{
    for(int i=0; i<SIZE; i++)
    if(abs(arg[i] - size[i])>0.001  )
    {
        return false;
   }
    return true;
    
}


template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp);


template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp);
/*!
 * Konstruktor klasy Vector                                                        |
 *  Argumenty:                                                                |
 *                                                     |
 *                                                 |
 *                                                                    |
 *    \retval  Tablice wypelniona wartoscia 0                              |
 */

template <int SIZE>
Vector<SIZE>::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
  
}

/*!
 * Konstruktor klasy Vector                                                        |
 *  Argumenty:                                                                |
 *   \param [in]   tmp - Jednowymiarowa tablica typu double.                                                |
 *                                                 |
 *                                                                    |
 *    \retval   Tablice wypelniona wartosciami podanymi w argumencie.                            |
 */



template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}

/*!
 *Realizuje dodawanie dwoch wektorow.                                                         |
 *  Argumenty:                                                                |
 *   \param [in]   this - pierwszy skladnik dodawania                                               |
 *     \param [in]  v   - drugi skladnik dodawania                               |
 *                                                                    |
 *    \retval    Sume dwoch skladnikow przekazanych jako wskaznik                      |
 *      na parametr.                           |
 */


template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator + (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}

/*!
 *|Realizuje odejmowanie dwoch wektorow. .                                                         |
  * Argumenty:                                                                |
 *   \param [in]   this - pierwszy skladnik odejmowania,                                                |
 *     \param [in]  v   - drugi skladnik odejmowania.                               |
 *                                                                    |
 *    \retval    Roznice dwoch skladnikow przekazanych jako wskaznik                      |
 *      na parametr.                           |
 */


template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator - (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/*!
 * Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa. .                                                         |
 *  Argumenty:                                                                |
 *   \param [in]     this - pierwszy skladnik mnozenia (wektor),                                                 |
 *     \param [in]  v - drugi skladnik mnozenia (liczba typu double).                           |
 *                                                                    |
 *    \retval     Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 *     na parametr.             |
 */



template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator * (const double &tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/*!
 * Realizuje dzielenie dwoch wektorow. .                                                         |
 *  Argumenty:                                                                |
 *   \param [in]     this - licznik dzielenia,                                               |
 *     \param [in]  v - mianownik dzielenia.                           |
 *                                                                    |
 *    \retval     Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 *      na parametr.          |
 */



template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator / (const double &tmp) {
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}
/*!
 * Funktor wektora.                                                         |
 *  Argumenty:                                                                |
 *                                                |
 *     \param [in]        index - index wektora                       |
 *                                                                    |
 *   \retval      Wartosc wektora w danym miejscu tablicy jako stala.        |
 */





template <int SIZE>
const double &Vector<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}

/*!
 * Funktor wektora.                                                         |
 *  Argumenty:                                                                |
 *                                                |
 *     \param [in]        index - index wektora                       |
 *                                                                    |
 *   \retval      Wartosc wektora w danym miejscu tablicy.  .        |
 */


template <int SIZE>
double &Vector<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
} 
/*!
 * Przeciazenie operatora <<                                                            |
 *  Argumenty:                                                                |
 *                                                |
 *     \param [in]       out - strumien wejsciowy,                          |
 *              \param [in]           tmp - wektor.                                                   |
 *    .        |
 */

template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        out << tmp[i] << " ";
    }
    return out;
}

/*!
 * Przeciazenie operatora >>                                                           |
 *  Argumenty:                                                                |
 *                                                |
 *     \param [in]     in - strumien wyjsciowy,                           |
 *              \param [in]           tmp - wektor.                                                   |
 *    .        |
 */


template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
