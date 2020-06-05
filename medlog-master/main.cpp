#include <iostream>
#include <fstream>
#include <locale.h>
#include "Funciones.h"
#include "Paciente.h"
#include "Persona.h"
#include "Doctor.h"
using namespace std;

int main()
{
    vector<Persona*> personas;
    CargarPersonas(personas);

//Persona *temp = new Doctor();
//LeerPersona(temp,"R_1999JAA61217.txt");


    setlocale(LC_ALL, "Spanish");

    //!Se muestra menu principal
    bool reg = false;

    do{
        reg= MostrarMenuPrincipal(personas);

        }while(reg);

    system("cls");system("exit");
    return 0;
}
