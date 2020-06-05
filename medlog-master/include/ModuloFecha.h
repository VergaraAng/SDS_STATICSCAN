#ifndef MODULOFECHA_H
#define MODULOFECHA_H
#include <iostream>
using namespace std;
struct Fecha
        {
        int dia;
        int mes;
        int year;
};
int LeerInt();
string LeerCadena(string dato);
char LeerSexo();
struct Fecha LeerFecha(string evento);//evento puede ser consulta o naciemiento
struct Fecha SetFecha(int dia,int mes ,int year);
int IndicarNumDias(int,int);
int LeerDia(int,int);
int LeerMes();
int LeerAnio();

#endif // MODULOFECHA_H
