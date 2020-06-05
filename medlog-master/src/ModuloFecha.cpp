#include <ModuloFecha.h>
#include <iostream>
#include<limits>
#include<exception>
#include <regex>

using namespace std;
//!Funciones para leer fecha

char LeerSexo(){
    char sexo;
    cout << "Sexo (M- Masculino F- Femenino): ";
    cin >> sexo;
    switch(sexo){
        case 'M': case 'F':
            return sexo;
        default:
            return LeerSexo();
    }
}

int LeerInt()
{
    cin.exceptions(ios::failbit | ios::badbit);
    int num = 0;
    string errorRango = "\nError: Número no válido";
    try
	{
		cin >> num;
		if(num<0){throw errorRango;}
	}
	catch(ios_base::failure& e)
	{
		cout<<"\nError: dato ingresado incorrecto. Ingrese de nuevo\n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(),'\n');
		return LeerInt();
	}
	 catch(string e)
	 {
           cout << e << endl;
           return LeerInt();
     }
     catch(exception &e){
        cout<<"\nError: dato ingresado incorrecto. Ingrese de nuevo\n";
		cin.clear();
		cin.ignore(numeric_limits<int>::max(),'\n');
		return LeerInt();
     }
	catch(...)
    {
      cout << "Error inesperado";
      return LeerInt();
    }

    return num;


}

string LeerCadena(string dato){

    //! Se valida el string para nombre, apellido paterno y materno
    //! No puede ser mayor a 255 caracteres ni contener caracteres que no sean letras

  string cadena;
  string errorChar="Error: dato ingresado incorrecto";
  string errorTam="Error: solo se aceptan hasta 255 caractres";

  cout << "\nIngrese su  "+dato+":\t";
  cin >> cadena;

  string subject(cadena);
    try
    {
        regex rgx("[^A-Za-z]");
        smatch match;
        if (cadena.size()>255) {throw errorTam;}
        if (regex_search(subject, match, rgx)) {throw errorChar;}
    }
    catch (regex_error& e) {
      // Syntax error in the regular expression
    }
    catch (string e) {
        cout << e << endl;
        return LeerCadena(dato);
    }
    catch(...)
    {
        cout << "Error inesperado";
        return LeerCadena(dato);
    }

    return cadena;
}

struct Fecha LeerFecha(string evento){
    Fecha fecha;
    cout<<"\nIngrese fecha de "+ evento;
    fecha.year = LeerAnio();
    fecha.mes = LeerMes();
    fecha.dia = LeerDia(fecha.mes,fecha.year);
    return fecha;
 }

 struct Fecha SetFecha(int dia,int mes ,int year){
    Fecha fecha;
    fecha.year = year;
    fecha.mes =mes;
    fecha.dia = dia;
    return fecha;
 }

int IndicarNumDias(int mes, int anio)
{
    int dias = 0;
    switch(mes)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:dias = 31;break;
        case 2:
            if((anio % 4) == 0 && ((anio % 100) == 0 && (anio % 400) == 0))
                dias = 29;
            else
                dias = 28;
            break;
        case 4:case 6:case 9:case 11:dias = 30;break;
    }
    return dias;
}

int LeerDia(int mes, int anio)
{
    cout <<"\nDía: ";
    string errorDia = "\nError: Número no válido";
    int dia = LeerInt();
    try
    {
        if(dia<1||dia>IndicarNumDias(mes,anio)){throw errorDia;}
    }
    catch(string e)
    {
        cout << e << endl;
        LeerDia(mes,anio);
    }
    return dia;
}

int LeerMes()
{
    cout <<"\nMes: ";
    string errorMes = "\nError: Número no válido";
    int mes = LeerInt();
    try
    {
        if(mes>12){throw errorMes;}
    }
    catch(string e)
    {
        cout << e << endl;
        return LeerMes();
    }
    return mes;
}

int LeerAnio()
{
    cout <<"\nAño: ";
    string errorAnio = "\nError: Número no válido";
    int anio = LeerInt();
    try
    {
         if(anio<1900||anio>5000){throw errorAnio;}
    }
    catch(string e)
    {
        cout << e << endl;
        return LeerAnio();
    }
    return anio;
}

