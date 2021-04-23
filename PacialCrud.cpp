#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Producto.h"
#include "Marca.h"
#include "SuperMercado.h"
using namespace std;
void menu();
void menu2();
void menu_principal();
void crear_marca();
void leer_marca();
void modificar_marca();
void eliminar_marca();
void crear_producto();
void leer_producto();
void modificar_producto();
void eliminar_producto();


int main()
{
	menu_principal();
}
void menu_principal() {
	int p;
	do {
		system("cls");
		cout << ("1. Tabla Puesto") << endl;
		cout << ("2. Tabla Empleados") << endl;
		cout << ("3. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> p;
		switch (p) {
		case 1:system("cls"); menu();
			break;
		case 2: system("cls"); menu2();
			break;
		}
	} while (p != 3);
}
void crear_Marca()
{
}
void menu() {
	int a;
	do {
		system("cls");
		cout << ("1. Insertar Datos") << endl;
		cout << ("2. Mostrar Datos ") << endl;
		cout << ("3. Modificar Datos") << endl;
		cout << ("4. Eliminar Datos") << endl;
		cout << ("5. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> a;
		switch (a) {
		case 1:system("cls");
			crear_marca();
			break;
		case 2:system("cls");
			leer_marca();
			break;

		case 3:system("cls");
			modificar_marca();
			break;

		case 4: system("cls");
			eliminar_marca();
			break;
		}
	} while (a != 5);
}

void menu2() {
	int a;
	do {
		system("cls");
		cout << ("1. Crear Datos") << endl;
		cout << ("2. Morstrar Datos ") << endl;
		cout << ("3. Modificar Datos") << endl;
		cout << ("4. Eliminar Datos") << endl;
		cout << ("5. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> a;
		switch (a) {
		case 1:system("cls");
			crear_producto();
			break;
		case 2:system("cls");
			leer_producto();
			break;

		case 3:system("cls");
			modificar_producto();
			break;

		case 4: system("cls");
			eliminar_producto();
			break;
		}
	} while (a != 5);
}