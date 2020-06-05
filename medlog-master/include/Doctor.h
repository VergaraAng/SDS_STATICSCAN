#ifndef DOCTOR_H
#define DOCTOR_H

#include <Persona.h>
#include <iostream>
#include <fstream>
using namespace std;

class Doctor : public Persona
{
    public:
        Doctor();
        Doctor(string nombre, string apellidoM, string apellidoP, char sexo,Fecha fnacimiento);
        void SetID();
        void RegistrarPersona();


    protected:

    private:
};

#endif // DOCTOR_H
