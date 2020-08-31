//Programa que saca el promedio de 4 archivos csv, por columnas y un promedio total de estas.
//Creado por Camilo Acevedo.
//Inspirado en promedio csv Cesar Aceros, programacion ats, https://www.programarya.com/Cursos/C++/Estructuras-de-Datos/Punteros, repositorio varios archivos csv.

#include <iostream> //Libreria para leer y escribir desde / hacia archivos.
#include <fstream> //Archivo de la biblioteca que contiene la defincion de constantes, funciones y algunas operaciones.
#include <vector> //Libreria para operar con arreglos unidimensionales de datos
#include <sstream> //Libreria que proporciona plantillas y tipos que permiten la inter operación entre búferes de flujo y objetos de cadena .
#include <string> //Componente de la biblioteca, utilizado para operaciones de entrada / salida.
#include <ctype.h> //Componente de la biblioteca diseñado para operaciones básicas con caracteres.
using namespace std; //Creamos un bloque que asocie nuestras funciones.

double prom1 = 0;//variable que almacena el promedio 1 
double prom2 = 0;//variable que almacena el promedio 2
double prom3 = 0;//variable que almacena el promedio 3
double prom4 = 0;//variable que almacena el promedio 4
double promt1 = 0;//variable que almacena el promedio total 1 
double promt2 = 0;//variable que almacena el promedio total 2 
double promt3 = 0;//variable que almacena el promedio total 3 
double promt4 = 0;//variable que almacena el promedio total 4 
int num = 0; //variable para la cantidad de estudiantes por archivo.
int numsalones= 0 ; //creamos una variable para la cantidad de salones.
double promedios_individuales(const char* archivocvv) //funcion promedio que recibe una variable que almacena el archivo.
{
	ifstream archivo(archivocvv); //leemos el archivo y lo almacenamos en una variable.
	string linea; //creamos un string "linea."
	vector<vector<string>> parsedCsv; //creamos un vector.
    int rowcount=0; //Declaramos una variable contador.
    int colcount=0; //Declaramos una variable contador.
	while (getline (archivo, linea)) { //Leemos una linea del archivo
		stringstream l(linea); //almacenamos "linea" en una variable
		string celda; //secuencia de caracteres guardados en string.
        vector<string> parsedRow; // //Almacenamos nuestros datos en un vector.
        colcount=0; //Miramos la cantidad de columnas del archivo.
		while(getline(l, celda, ',')) { //leemos la variable celda de la linea, separada por comas.
 			parsedRow.push_back(celda);// recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector
            colcount++;//Miramos la cantidad de filas del archivo incrementandolas en 1.
		}
        rowcount++;//Miramos la cantidad de columnas del archivo incrementando en 1.
        parsedCsv.push_back(parsedRow);//recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector
	}
    int n1 = 0;//variable que almacena la suma1.
    int n2 = 0;//variable que almacena la suma2.
    int n3 = 0;//variable que almacena la suma3.
    int n4 = 0;//variable que almacena la suma4.
    for (int i=0 ; i<rowcount ; i++){ //para cada variable i, tomamos el rowcount y aumentamos en 1.
        std::string::size_type sz; //creamos un sobrenombre para el tamaño del string.
        int j=2; //j siempre inicialmente valdrá 2, esta es la columna que vamos a tomar. Contando la primera columna como 0. 
        double valor1 = stod(parsedCsv[i][j],&sz); //convertimos el string en una variabe double.
        n1= n1 + valor1;//la suma aumentará dependiendo del valor.
        j = 3;
        double valor2 = stod(parsedCsv[i][j],&sz);
        n2= n2 + valor2;//la suma aumentará dependiendo del valor.
        j = 4;
        double valor3 = stod(parsedCsv[i][j],&sz);
        n3= n3 + valor3;//la suma aumentará dependiendo del valor.
        j = 5;
        double valor4 = stod(parsedCsv[i][j],&sz);
        n4= n4 + valor4;//la suma aumentará dependiendo del valor.
        j=1; // tomamos esta columna para hacer un contador de alumnos por archivo.
        num=num+1;

    }
    
    prom1= n1/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom2= n2/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom3= n3/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom4= n4/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
	archivo.close(); //cerramos el archivo.
    return prom1 and prom2 and prom3 and prom4;// regresamos las variables.

}

double volvernulo(){ //esta funcion se crea para volver nulas las variables y que no se mezclen las notas.
    prom1=0;
    prom2=0;
    prom3=0;
    prom4=0;
    num=0;
    return prom1 and prom2 and prom3 and prom4 and num;// regresamos las variables.
}

double calculo_promediot(){ //esta funcion nos acumulará los promedios en nuevas variables para no perder el valor antes de que se restablezca a 0.
    promt1=prom1+promt1;
    promt2=prom2+promt2;
    promt3=prom3+promt3;
    promt4=prom4+promt4;
    return promt1 and promt2 and promt3 and promt4;// regresamos las variables.
}

double promediototal()//esta funcion, por ultimo, divide el valor de los promedios acumulados en 4.
{
    promt1=promt1/numsalones;
    promt2=promt2/numsalones;
    promt3=promt3/numsalones;
    promt4=promt4/numsalones;
    return promt1 and promt2 and promt3 and promt4;// regresamos las variables.
}

double incrementoSalones (){
    numsalones= numsalones + 1;
    return numsalones;
}

int main()
{
	promedios_individuales("cinco.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    incrementoSalones ();
    cout << "El promedio del archivo 1 es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del primer archivo..
    calculo_promediot();
    volvernulo();

    promedios_individuales("diez.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    incrementoSalones ();
    cout << "El promedio del archivo 2 es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del segundo archivo.
    calculo_promediot();
    volvernulo();

    promedios_individuales("quince.csv");//llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    incrementoSalones ();
    cout << "El promedio del archivo 3 es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del tercer archivo..
    calculo_promediot();
    volvernulo();

    promedios_individuales("veinte.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    incrementoSalones ();
    cout << "El promedio del archivo 4 es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del ultimo archivo..
	calculo_promediot();
    volvernulo();
    
    promediototal();
    cout << "El promedio total de los promedios por archivos es: " << promt1 << " " << promt2 << " " << promt3 << " " << promt4 << endl; // imprimimos un mensaje con los promedios totales.
    return 0;
}