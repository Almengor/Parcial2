#pragma once
#include <iostream>
using namespace std;

class SuperMercado {
	// atributos
protected: string marca, producto, descripcion, imagen, precio_costo, precio_venta, fecha_ingreso;
		 int existencia = 0;
		 // costructor
protected:
	SuperMercado() {
	}
	SuperMercado(string mar, string prod, string des, int exis, string img, string pc, string pv, string fi) {
		marca = mar;
		producto = prod;
		descripcion = des;
		existencia = exis;
		imagen = img;
		precio_costo = pc;
		precio_venta = pv;
		fecha_ingreso = fi;
	}
};

