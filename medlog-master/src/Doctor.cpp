#include "Doctor.h"
#include <iostream>


using namespace std;

Doctor::Doctor()
{
    tipoPersona = 'D';
}
Doctor::Doctor(string nombre, string apellidoM, string apellidoP, char sexo,Fecha fnacimiento) : Persona(nombre,apellidoM, apellidoP, sexo, fnacimiento){
      SetID();
      tipoPersona = 'D';
}
void Doctor::RegistrarPersona(){
    string newID = "D_" + GetID() + ".txt";
    const char * c = newID.c_str(); //!el nombre se convierte para poder usarlo como nombre del archivo
    ofstream of(c);

    of << (*this).Getnombre()<< "\n";
    of << (*this).GetapellidoP()<< "\n";
    of << (*this).GetapellidoM()<< "\n";
    of << (*this).Getsexo()<< "\n";
    of << (*this).Getfnacimiento().dia<< "/"<< (*this).Getfnacimiento().mes<< "/"<< (*this).Getfnacimiento().year << "\n";
    of << (*this).GetID();
    of.close();
    cout << "\nSe guardó el registro del doctor como: " << newID;
}

void Doctor::SetID(){
    ID =LeerCadena("cédula");
}
