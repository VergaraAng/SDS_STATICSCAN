#include "Persona.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <regex>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "ModuloFecha.h"


using namespace std;

Persona::Persona()
{
    //ctor
}
Persona::Persona(string nombre, string apellidoM, string apellidoP, char sexo,Fecha fnacimiento){
    (*this).nombre = nombre;
    (*this).apellidoM = apellidoM;
    (*this).apellidoP = apellidoP;
    (*this).sexo = sexo;
    (*this).fnacimiento = fnacimiento;
}

void RegistrarCita(Persona *p,string dia, string ce){
        string newHistoryID = "H_" + p->GetID() + ".txt";
        const char * d = newHistoryID.c_str(); //!el nombre se convierte para poder usarlo como nombre del archivo
        time_t now = time(0);
        char* dt = ctime(&now);
        ofstream ofh(d, ios::app);
        ofh << "\n\n*Fecha cita: " << dt;
        ofh << "\nDoctor a cargo: " << ce;
        ofh << "\nDiagnóstico:\n" << dia;
        ofh.close();
}

istream& operator>>(istream& in, Persona &p){
    p.Setnombre(LeerCadena("nombre"));
    p.SetapellidoP(LeerCadena("apellido paterno"));
    p.SetapellidoM(LeerCadena("apellido materno"));
    p.Setsexo(LeerSexo());
    p.Setfnacimiento(LeerFecha("nacimiento"));
    p.SetID();

    return in;
}
ostream& operator<<(ostream& out, Persona &p){
    out << endl << setw(25) << "Nombre:" << p.Getnombre() << endl;
    out << setw(25) << "Apellido Paterno:"<< p.GetapellidoP()<< endl;
    out << setw(25) << "Apellido Materno:"<< p.GetapellidoM()<< endl;
    out << setw(25) << "Sexo:"<< p.Getsexo()<< endl;
    out << setw(25) << "\nFecha de nacimiento:"<< p.Getfnacimiento().dia<< "/"<< p.Getfnacimiento().mes<< "/"<< p.Getfnacimiento().year<< endl;
    return out;
}

void Persona::Setfnacimiento(Fecha f){
      fnacimiento.dia = f.dia;
      fnacimiento.mes = f.mes;
      fnacimiento.year = f.year;
}

void LeerPersona(Persona *temp, string filename){
     ifstream fin;
     string d, m, y;

    fin.open(filename);
    if (!fin) {
        cout << "Error in opening the file" << endl;
    }
     getline(fin,temp->nombre);
     getline(fin,temp->apellidoP);
     getline(fin,temp->apellidoM);
     fin >> temp->sexo;
     getline(fin,d,'/');
     getline(fin,m,'/');
     getline(fin,y);
     getline(fin,temp->ID);

     Fecha f = SetFecha(stoi(d),stoi(m),stoi(y));
    temp->Setfnacimiento(f);


}
