#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <vector>
#include <boost/filesystem.hpp>
#include "Persona.h"
#include "Paciente.h"
#include "Doctor.h"

#include "Funciones.h"

#include "ModuloFecha.h"  //importa para usar funcion leerInt()


//!Definiciones de las funciones declaradas en el header Funciones.h

using namespace std;

template<class T>
class Dato{
    public:
        Dato(){};
        void Imprimir(T v){
            cout << v;
        }
};

//!Faltan por definir
void OpcMostrarDoctores(vector<Persona*> &personas){
    for (const auto& person : personas) {
        if((*person).GettipoPersona() == 'D')
            cout << (*person);
    }
}

void ModificarPersona(vector<Persona*> &p, int &pos, int &opc){
    switch(opc)
    {
        case 1: p.at(pos)->Setnombre(LeerCadena("nombre"));break;
        case 2: p.at(pos)->SetapellidoP(LeerCadena("apellido paterno"));break;
        case 3: p.at(pos)->SetapellidoM(LeerCadena("apellido materno"));break;
        case 4: p.at(pos)->Setsexo(LeerSexo());break;
        case 5: p.at(pos)->Setfnacimiento(LeerFecha("nacimiento"));break;
    }
    p.at(pos)->RegistrarPersona();
}

//!Definiciones de las funciones que presentan cada menu

bool MostrarMenuPrincipal(vector<Persona*> &personas){
    int opc;
    cout<<"\n*****************************************************\n";
    cout <<"*                 Bienvenido a MedLog               *\n";
    cout<<"*****************************************************\n\n";
    cout<<"\t1) Ingresar como administrativo\n";
    cout<<"\t2) Ingresar como doctor\n";
    cout<<"\t3) Salir\n\n";
    cout<<"*****************************************************\n";
    opc = ValidarOpcionMenu('A');
    switch(opc){
        case 1:
            return MostrarMenuAdministrativo(personas);
        break;
        case 2:
            return MostrarMenuDoctor(personas);
        break;
        case 3:
           return false;
        break;
    }
}

bool MostrarMenuAdministrativo(vector<Persona*> &personas){
    Persona *p;
    int opc = 0, pos = 0;
    cout<<"\n*****************************************************\n";
    cout<<"                      OPCIONES                       \n";
    cout<<"\n*****************************************************\n\n";
    cout<<"\t1) Registrar Doctor\n";
    cout<<"\t2) Mostrar Doctores\n";
    cout<<"\t3) Buscar Doctor\n";
    cout<<"\t4) Modificar Persona\n";
    cout<<"\t5) Regresar\n";
    cout<<"\t6) Salir\n\n";
    cout<<"*****************************************************\n";
    opc = ValidarOpcionMenu('B');
    switch(opc){
        case 1:
            p = new Doctor();
            cin >> (*p);
            personas.push_back(p);
            cout << (*p);
            p->RegistrarPersona();
            return MostrarMenuAdministrativo(personas);
            break;
        case 2:
            OpcMostrarDoctores(personas);
            return MostrarMenuAdministrativo(personas);
            break;
        case 3:
            pos = OpcBuscarPersona(personas,'D');
            if(pos == -1){
                cout << "Esta persona no existe";
                return MostrarMenuAdministrativo(personas);
            }
            cout << *(personas.at(pos));
            return MostrarMenuAdministrativo(personas);
            break;
        case 4:
            pos = OpcBuscarPersona(personas,'T');
            if(pos>=0){return MostrarMenuArchivo(personas,pos);}
            else {return MostrarMenuPrincipal(personas);}
            break;
        case 5:
            return MostrarMenuPrincipal(personas);
            break;
        case 6:
            return false;
            break;
    }
}

bool MostrarMenuDoctor(vector<Persona*> &personas){
    Persona *p;
    int pos = 0;
    int opc;
     cout<<"\n*****************************************************\n";
     cout<<"                     OPCIONES                       \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Registrar Paciente\n";
     cout<<"\t2) Registrar cita\n";
     cout<<"\t3) Buscar Paciente\n";
     cout<<"\t4) Regresar\n";
     cout<<"\t5) Salir\n\n";
     cout<<"*****************************************************\n";
     opc = ValidarOpcionMenu('C');
     switch(opc){
        case 1:
            p = new Paciente();
            cin >> *p;
            personas.push_back(p);
            cout << *p;
            p ->RegistrarPersona();
            return MostrarMenuDoctor(personas);
            break;
        case 2:
            {
            p = new Paciente;
            cin >> *p;
            cout << *p;
            cout << "\nDiagnóstico: "; string dia;
            cin.ignore(); getline(cin,dia);
            string ce;
            ce = LeerCadena("Cédula");
            pos = OpcBuscarPersona(personas,'D');
            if(pos>=0){RegistrarCita(p,dia,ce);cout<<*(personas.at(pos));}
            else {cout << "\nNo se puede realizar la cita porque no existe el paciente";}
            return MostrarMenuDoctor(personas);
            break;}
        case 3:
            pos = OpcBuscarPersona(personas,'P');
            if(pos == -1)
                return MostrarMenuPrincipal(personas);
            return MostrarMenuDoctorBuscarPaciente(personas,pos);
            break;
        case 4:
            return MostrarMenuPrincipal(personas);
            break;
        case 5:
            return false;
            break;
     }
}

bool MostrarMenuDoctorBuscarPaciente(vector<Persona*> &personas, int &pos){
    int opc;
    string historial = "H_";
     cout<<"\n*****************************************************\n";
     cout<<"                     OPCIONES                       \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Ver Registro\n";
     cout<<"\t2) Ver historial de consultas\n";
     cout<<"\t3) Regresar\n";
     cout<<"\t4) Salir\n\n";
     cout<<"*****************************************************\n";
     opc = ValidarOpcionMenu('D');
     switch(opc){
        case 1:
            cout << *(personas.at(pos));
            return MostrarMenuDoctorBuscarPaciente(personas,pos);
            break;
        case 2:
            historial+=personas.at(pos)->GetID();
            historial+=".txt";
            LeerArchivo(historial);
            return MostrarMenuDoctorBuscarPaciente(personas,pos);
            break;
        case 3:
             return MostrarMenuPrincipal(personas);
            break;
        case 4:
            return false;
            break;
        default: return MostrarMenuPrincipal(personas);
     }
}


//Este menu es para archivos que se puedan modificar

bool MostrarMenuArchivo(vector<Persona*> &p, int &pos){
    int opc = 0;
     cout<<"\n*****************************************************\n";
     cout<<"               OPCIONES(Dato a cambiar)                \n";
     cout<<"*****************************************************\n\n";
     cout<<"\t1) Nombre\n";
     cout<<"\t2) Apellido Paterno\n";
     cout<<"\t3) Apellido Materno\n";
     cout<<"\t4) Sexo\n";
     cout<<"\t5) Fecha de Nacimiento\n";
     cout<<"\t6) Salir\n\n";
     cout<<"*****************************************************\n";
     opc = ValidarOpcionMenu('E');
     if(opc==6){return false;}
     ModificarPersona(p,pos,opc);
     return MostrarMenuPrincipal(p);
}


//!Valida la opcion seleccionada en cada menu

int ValidarOpcionMenu(char menu){
    int lim=0,opc=0;

    //Establece el numero de opciones disponible para cada menu
    switch(menu){
        case 'A':lim=3;break;
        case 'B':lim=6;break;
        case 'C':lim=5;break;
        case 'D':lim=4;break;
        case 'E':lim=6;break;
    }
    cout << "Ingrese opcion del menu\n";
    //Valida si la opcion seleccionada es valida tomando en cuenta las opciones disponibles
    try
    {
        opc= LeerInt();
        if(opc < 1||opc>lim){throw invalid_argument("La opción del menu no es válida.");}

    }
    catch(invalid_argument& ia)
	{
        cout << ia.what()<<"\n";
        return ValidarOpcionMenu(menu);
		//!No se deberia enviar el menu como argumento
	}
	catch(exception& e)
	{
        cout << "Hubo un error\n Intente de nuevo: \n";
        return ValidarOpcionMenu(menu);
    }
    catch(...){
        cout << "Se debe de cerrar la aplicación";
    }

    return opc;
}

int OpcBuscarPersona(vector<Persona*> &personas,char tipo){
    string nombre, apellidoP, apellidoM;
    char sexo;
    Fecha fnac;
    int pos = 0;
    Persona *p;
    nombre = LeerCadena("nombre");
    apellidoP = LeerCadena("apellido paterno");
    bool existe = false;
    for(int i = 0; !existe && i < personas.size(); i++){
        if(personas.at(i)->Getnombre() == nombre && personas.at(i)->GetapellidoP() == apellidoP){
            if(personas.at(i)->GettipoPersona() == tipo){
                existe = true;
                pos = i;
                break;
            }else if(tipo == 'T'){
                existe = true;
                pos = i;
                break;
            }
        }
    }
      if(existe){
        cout << "\nEsta persona si existe en memoria!\n";
        return pos;
    }else{
        cout << "\nEsta persona no existe en memoria!\n";
        return (-1);
    }
}

void LeerArchivo(string filename){
  string sLine = "";
  ifstream infile;

  infile.open(filename);

  while (!infile.eof()){
    getline(infile, sLine);
    cout << sLine << endl;
  }

  infile.close();
}

void CargarPersonas(vector<Persona*> &p){
    using namespace boost::filesystem;
    vector<string> fnames;
    string extension = ".txt";
    //!Definir path personalizado
    Persona *punt;

    char * directorio = "C:\\Users\\Lenovo\\Desktop\\Equipo3_PIACpp";//! dirección en donde se tiene el proyecto (carpeta)

    for(directory_iterator itr(directorio); itr!=directory_iterator(); ++itr){
        int i = 0;
        if(itr->path().extension()== extension){
            fnames.push_back(itr->path().filename().string());
            if(fnames.at(i).at(0) == 'R' || fnames.at(0).at(0) == 'D'){
                if(fnames.at(i).at(0) == 'R'){
                    punt = new Paciente();
                    p.push_back(punt);
                    LeerPersona(p.at(i),fnames.at(i));
                    i++;
                }else if(fnames.at(i).at(0) == 'D'){
                    punt = new Doctor();
                    p.push_back(punt);
                    LeerPersona(p.at(i),fnames.at(i));
                    i++;
                }
            }
        }
    }
}
