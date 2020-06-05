#ifndef PERSONA_H
#define PERSONA_H
#include<string>
#include<iostream>
#include<vector>

#include "ModuloFecha.h" //Se importa para poder ejecutar las funciones que requieren manejar fechas
using namespace std;


class Persona
{
    public:
        Persona();
        Persona(string nombre, string apellidoM, string apellidoP, char sexo,Fecha fnacimiento);

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string GetapellidoP() { return apellidoP; }
        void SetapellidoP(string val) { apellidoP = val; }
        string GetapellidoM() { return apellidoM; }
        void SetapellidoM(string val) { apellidoM = val; }
        void Setsexo(char val){ sexo = val; }
        char Getsexo() { return sexo; }
        Fecha Getfnacimiento() { return fnacimiento; }
        void Setfnacimiento(Fecha);
        void SettipoPersona(char val){ tipoPersona = val; }
        char GettipoPersona() { return tipoPersona; }

        virtual void SetID()=0;//!método para calcular el ID
        string GetID() { return ID; }//!obtiene el ID

        virtual void RegistrarPersona()=0;
        friend void LeerPersona(Persona*, string);
        friend void RegistrarCita(Persona*, string, string);
        friend ostream& operator<<(ostream&,  Persona&);
        friend istream& operator>>(istream&, Persona&);

    protected:
       string ID; //!EL ID, para el paciente o el doctor
       char tipoPersona;
    private:
        string nombre;
        string apellidoP;
        string apellidoM;
        char sexo;
        Fecha fnacimiento;
};

#endif // PERSONA_H
