#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Persona.h"
#include "Paciente.h"
#include "Doctor.h"
#include <vector>
#include <iomanip>

//! Prototipos de las funciones que definiermos en el cpp

//Muestra el menu que se requiere segun el parametro
//void MostrarMenu(char menu);

//Mostrar Menus individuales
bool MostrarMenuPrincipal(vector<Persona*>&);
bool MostrarMenuArchivo(vector<Persona*>&,int&);
bool MostrarMenuAdministrativo(vector<Persona*>&);
bool MostrarMenuDoctor(vector<Persona*>&);
bool MostrarMenuDoctorBuscarPaciente(vector<Persona*>&,int&);

//Valida la opcion considerando el menu en que se encuentra
int ValidarOpcionMenu(char menu);

//!Opciones del menu

// Opcion que llama constructores para crear en memoria
void OpcRegistrar(char);

//Servirá para buscar doctores y pacientes  en vector (memoria)
int OpcBuscarPersona(vector<Persona*>&,char);

//escribir en archivo
void OpcRegistrarCita();

// va a servir para leer archivos (historiales y expedientes)
void LeerArchivo(string);

//  Se utilizará leer de vector
void OpcMostrarDoctores(vector<Persona*>&);

//Se utilizará para llamar funciones que lean los filenames y a partir de eso clasificquen
//Pacientes y doctores y lean su info
void CargarPersonas(vector<Persona*>&);

void ModificarPersonas(vector<Persona*>&,int&,int&);

template <class D>
inline void ImprimirFormato(D dato){
    std::cout << std::setw(6) << dato << "\n";
}


#endif // FUNCIONES_H
