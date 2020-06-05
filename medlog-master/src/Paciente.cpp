#include "Paciente.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

Paciente::Paciente()
{
    tipoPersona = 'P';
}
Paciente::Paciente(string nombre, string apellidoM, string apellidoP, char sexo, Fecha fnacimiento) : Persona(nombre,apellidoM, apellidoP, sexo, fnacimiento){
    SetID();
    tipoPersona = 'P';
}
void Paciente::RegistrarPersona(){
    string newID = "R_" + GetID() + ".txt";
    const char * c = newID.c_str(); //!el nombre se convierte para poder usarlo como nombre del archivo
    ofstream of(c);

    of << (*this).Getnombre()<< "\n";
    of << (*this).GetapellidoP()<< "\n";
    of << (*this).GetapellidoM()<< "\n";
    of << (*this).Getsexo()<< "\n";
    of << (*this).Getfnacimiento().dia<< "/"<< (*this).Getfnacimiento().mes<< "/"<< (*this).Getfnacimiento().year << "\n";
    of << (*this).GetID();

    of.close();
    cout << "\nSe guardó el expediente como: " << newID;

    string newHistoryID = "H_" + GetID() + ".txt";
    const char * d = newHistoryID.c_str(); //!el nombre se convierte para poder usarlo como nombre del archivo
    ofstream ofh(d);

    time_t now = time(0);
    char* dt = ctime(&now);

    ofh <<"Inicio de historial: " <<dt << endl;
    ofh.close();
    cout << "\nSe guardó el historial como: " << newHistoryID;
}
void Paciente::SetID(){

     //!el ID se conforma con las iniciales de su nombre + su fecha de nacimiento (nmeros)
     //!variables temporales

    char n = toupper(Getnombre().at(0));     //primera letra del nombre
    char a1 = toupper(GetapellidoP().at(0)); //primera letra del apellido
    char a2 = toupper(GetapellidoM().at(0)); //primera letra del segundo apellido

    stringstream st;
    st << Getfnacimiento().year << n << a1 << a2 << Getfnacimiento().dia << Getfnacimiento().mes << (Getnombre().size() + GetapellidoM().size() + GetapellidoP().size());
    string cad = st.str();
    ID= cad; //convierte el stream a string
}


