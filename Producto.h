#pragma once
#include "SuperMercado.h"
#include <mysql.h>
#include <iostream>
#include<string.h>
#include<string>
#include "ConexionBD.h"
using namespace std;
class Producto : SuperMercado {
	   // constructor
public:
	Producto() {
	}
	Producto(string marc, string prod, string des, int exis, string img, string pc, string pv, string fi) : SuperMercado(marc, prod, des, exis, img, pc, pv, fi) {
	}

	// METODOS
	//set (modificar)
	void setProducto(string prod) { producto = prod; }
	void setDescripcion(string des) { descripcion = des; }
	void setImagen(string img) { imagen = img; }
	void setPrecio_costo(string pc) { precio_costo = pc; }
	void setPrecio_venta(string pv) { precio_venta = pv; }
	void setExistecia(int exis) { existencia = exis; }
	void setFecha_ingreso(int fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getProducto() { return producto; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	string getPrecio_costo() { return precio_costo; }
	string getPrecio_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }
	// metodo
	void crear_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(existencia);
		if (cn.getConectar()) {
			string fecha = "now()";
			string producto, idmarca, descripcion, precio_costo, precio_venta, existencia;
			cin.ignore();
			cout << "Ingrese producto:";
			getline(cin, producto);
			cout << ("ingrese Id marca:");
			cin >> idmarca;
			cin.ignore();
			cout << "Ingrese descripcion de producto: ";
			getline(cin, descripcion);
			cout << ("Ingrese precio costo del producto: ");
			cin >> precio_costo;
			cout << ("Ingrese precio venta del producto: ");
			cin >> precio_venta;
			cout << ("Ingrese existencia: ");
			cin >> existencia;
			string insertar = "insert into productos(producto,idmarca,descripcion,precio_costo, precio_venta,existencia,fecha_ingreso) values('" + producto + "'," + idmarca + ",'" + descripcion + "'," + precio_costo + "," + precio_venta + "," + existencia + "," + fecha + ")";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------------- Datos de Productos --------------------------------" << endl;
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "ID |" << "Producto |" << "ID Marca |" << "Descripcion |" << "Precio costo |" << "Precio venta |    " << "Fecha Ingreso    | " << endl;
				cout << ("----------------------------------------------------------------------------------------------------------------");
				cout << ("\n");
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1] << "     |" << fila[2] << "   |" << fila[3] << "        |" << fila[4] << "        |" << fila[5] << "       |" << fila[7] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idproducto, producto, idmarca, descripcion, existencia, precio_costo, precio_venta;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del Cliente que desea modificar: ";
			cin >> idproducto;
			string consulta = "select * from productos where id_producto=" + idproducto + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "IdProducto: " << fila[0] << endl;
					cout << ("Producto: ") << fila[1] << endl;
					cout << ("IdMarca: ") << fila[2] << endl;
					cout << ("Descripcion: ") << fila[3] << endl;
					cout << ("Imagen: ") << fila[4] << endl;
					cout << ("Precio de compra: ") << fila[5] << endl;
					cout << ("Precio de venta: ") << fila[6] << endl;
					cout << ("Existencia: ") << fila[7] << endl;
					cout << ("Fecha de Ingreso: ") << fila[8] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
			cout << "Ingrese el id del registro que desea modificar";
			cin >> idproducto;
			cout << "Ingrese el nuevo nombre del producto";
			cin >> producto;
			cout << "Ingrese el nuevo id de marca";
			cin >> idmarca;
			cout << "Ingrese la nueva descripcion";
			cin >> descripcion;
			cout << "Ingrese la nueva cantidad de existencias";
			cin >> existencia;
			cout << "Ingrese el nuevo precio de costo";
			cin >> precio_costo;
			cout << "Ingrese el nuevo precio de venta";
			cin >> precio_venta;
			string modificar = "update productos set producto = '" + producto + "',idmarca = '" + idmarca + "',descripcion = '" + descripcion + "',existencia = '" + existencia + "',precio_costo = '" + precio_costo + "',precio_venta = '" + precio_venta + "'  where idmarca =" + idproducto + "";
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
	void eliminar_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idproducto;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> idproducto;
			string eliminar = "delete from Productos where idproducto = (" + idproducto + ")";
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