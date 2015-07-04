
#pragma once

#include "stdafx.h"
#include "Nodo.h"
#include "IteradorLista.h"
#include "IteradorInversoLista.h"

using namespace std;

template<class T>
class Lista {

	template<class T>
	friend ostream & operator<<(ostream &, Lista<T> &);

protected:

	Nodo<T> * primero;
	Nodo<T> * ultimo;
	int cantidadElementos;

public:

	Lista() {
		cantidadElementos = 0;
		primero = NULL;
		ultimo = NULL;

	}

	virtual ~Lista(){

		if (primero != NULL) {
			destruirRec(primero);
		}

	}

	Iterador<T> begin() {
		return Iterador<T>(primero);
	}

	Iterador<T> end() {
		return Iterador<T>(NULL);
	}

	IteradorInverso<T> rBegin() {
		return IteradorInverso<T>(ultimo);
	}

	IteradorInverso<T> rEnd() {
		return IteradorInverso<T>(NULL);
	}

	void insertarInicio(T actual) {

		Nodo<T> * nodo = new Nodo<T>(actual);
		if (primero == NULL) {
			primero = nodo;
			primero->anterior = NULL;
			ultimo = nodo;
			cantidadElementos++;
		}
		else {
			insertarInicioRec(primero, actual);
		}

		ordenarPosiciones(primero, 0);
	}

	void insertarFinal(T actual) {

		Nodo<T> * nodo = new Nodo<T>(actual);
		int p = 0;
		if (primero == NULL) {
			primero = nodo;
			primero->anterior = NULL;
			ultimo = nodo;
			nodo->posicion = p;
			cantidadElementos++;
		}
		else {
			insertarElementoRec(primero, nodo);
		}

		ordenarPosiciones(primero, 0);

	}

	void insertarPosicion(T  insertar, int p){
		Nodo<T> * nodo = new Nodo<T>(insertar);
		if (primero != NULL){

			insertarPosicionRec(nodo, primero, p);

		}

		ordenarPosiciones(primero, 0);
	}

	void ordenarPosiciones(Nodo<T>* nodo, int p){

		nodo->posicion = p;

		if (nodo->siguiente != NULL){

			ordenarPosiciones(nodo->siguiente, p + 1);

		}

	}

	void eliminar(int posicion){
		if (primero != NULL){

			eliminarRec(primero, posicion);

		}

		ordenarPosiciones(primero, 0);
	}

	void eliminarPrimero(){
		eliminar(0);
	}
	void eliminarUltimo(){
		eliminar(cantidadElementos - 1);
	}

	int getCantidad(){
		return cantidadElementos;
	}

private:

	void destruirRec(Nodo<T> * nodo) {

		if (nodo->siguiente != NULL) {
			destruirRec(nodo->siguiente);
		}

		delete nodo;
	}

	void insertarPosicionRec(Nodo<T> * insertar, Nodo<T> * actual, int p){
		if (actual->posicion != p){

			if (actual->siguiente != NULL){
				insertarPosicionRec(insertar, actual->siguiente, p);
			}

		}
		else {

			if (p == 0){
				insertar->siguiente = primero;
				primero = insertar;
				primero->anterior = NULL;
				insertar->siguiente->anterior = insertar;

			}
			else {
				actual->anterior->siguiente = insertar;
				insertar->anterior = actual->anterior->siguiente;
				insertar->siguiente = actual;
				actual->anterior = insertar;
				cantidadElementos++;
			}
		}
	}

	void eliminarRec(Nodo<T>* actual, int p){
		if (actual->posicion != p){

			if (actual->siguiente != NULL){
				eliminarRec(actual->siguiente, p);
			}

		}
		else {

			if (p == 0){
				primero = actual->siguiente;
				primero->anterior = NULL;
				actual->siguiente->anterior = NULL;
				cantidadElementos--;
			}
			else if (p == cantidadElementos - 1){
				actual->anterior->siguiente = NULL;
				cantidadElementos--;
			}
			else {
				actual->anterior->siguiente = actual->siguiente;
				actual->siguiente->anterior = actual->anterior;
				cantidadElementos--;
			}
		}
	}

	void insertarInicioRec(Nodo<T>* actual,
		T insertar) {

		Nodo<T> * nodo = new Nodo<T>(insertar);

		if (actual->anterior != NULL) {

			insertarInicioRec(actual->anterior, nodo);
		}
		else {
			actual->anterior = nodo;
			nodo->siguiente = actual;
			primero = nodo;
			primero->anterior = NULL;
			cantidadElementos++;
		}

	}

	void insertarElementoRec(Nodo<T>* actual,
		Nodo<T>* insertar) {

		if (actual->siguiente != NULL) {
			insertarElementoRec(actual->siguiente, insertar);
		}
		else {
			actual->siguiente = insertar;
			insertar->anterior = actual;
			ultimo = insertar;
			cantidadElementos++;
		}

	}

	void imprimir(Nodo<T>* nodo, ostream& out) {

		if (nodo != NULL) {
			out << nodo->actual << " Posicion: " << nodo->posicion << endl;
			imprimir(nodo->siguiente, out);
		}
	}


};

template<class T>
ostream & operator<<(ostream & out, Lista<T> & l) {
	l.imprimir(l.primero, out);
	return out;
}


