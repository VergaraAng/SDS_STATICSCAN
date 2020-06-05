#ifndef PACIENTE_H
#define PACIENTE_H

#include <Persona.h>
#include <iostream>
using namespace std;

class Paciente : public Persona
{
    public:
        Paciente();
        Paciente(string nombre, string apellidoM, string apellidoP, char sexo,Fecha fnacimiento);
        void SetID();
        void RegistrarPersona();


    protected:

    private:
};

#endif // PACIENTE_H
