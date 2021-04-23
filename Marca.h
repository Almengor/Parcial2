#pragma once
#include "SuperMercado.h"
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Marca : SuperMercado {
		// METODOS
		//set (modificar)
		void setMarca(string mar) { marca = mar; }
		//get (mostrar)
		string getMarca() { return marca; }
		// metodo
	void crear_marca() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string marca;
			cout << "Ingrese Marca:";
			cin >> marca;
			string insertar = "insert into marcas(marca) values('" + marca + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer_marca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "------------ Datos de Marcas ------------" << endl;
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;
				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar_marca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idmarca, marca;
			char s;
			cout << ("------------------------- Modificar Datos ---------------------------") << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idmarca;
			string consulta = "select * from marcas where idmarca=" + idmarca + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id Marca: " << fila[0] << endl;
					cout << ("Marca: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\ningrese el nuevo nombre de la marca: ";
						cin >> marca;
						string modificar = "update marcas set marca = '" + marca + "' where idmarca =" + idmarca + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar_marca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idmarca;
			cout << "Ingrese Marca:";
			cin >> idmarca;
			string eliminar = "delete from marcas where idmarca=(" + idmarca + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};
