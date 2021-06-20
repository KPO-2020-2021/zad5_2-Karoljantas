#pragma once
#include "matrix.hh"



//modyfikacja

typedef Matrix<4> Matrix4x4;


void translacja(Matrix4x4 &m, double alfa, double beta, double gamma, double x double y, double z)
{
    m(0,0)=cos(alfa)*cos(beta);
    m(0,1)=cos(alfa)*sin(beta)*sin(gamma)-sin(alfa)*cos(gamma);
    m(0,2)=cos(alfa)*sin(beta)*cos(gamma)+sin(alfa)*sin(gamma);
    m(0,3)=x;


       m(1,0)=sin(alfa)*cos(beta);
    m(1,1)=sin(alfa)*sin(beta)*sin(gamma)+cos(alfa)*cos(gamma);
    m(1,2)=sin(alfa)*sin(beta)*cos(gamma)-cos(alfa)*sin(gamma);
    m(1,3)=y;

       m(2,0)=-sin(beta);
    m(2,1)=cos(beta)*sin(gamma;
    m(2,2)=cos(beta)*cos(gamma);
    m(2,3)=z;

     m(3,0)=0;
    m(3,1)=0;
    m(3,2)=0;
    m(3,3)=1;


}

