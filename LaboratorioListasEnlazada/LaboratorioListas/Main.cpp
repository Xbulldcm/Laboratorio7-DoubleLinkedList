

#include "stdafx.h"
#include "Lista.h"
#include "Persona.h"
#include "IteradorLista.h"
#include "IteradorInversoLista.h"


using namespace std;

int main(int argc, char **argv) {

	srand((unsigned int) time(NULL));
	string s[30] = { "Diego", "Maria", "Juan", "Andres", "Pedro", "Luis",
		"Juana", "Siria", "Roberto", "Siria", "Sebastian", "Ricardo",
		"Aria", "Andrey", "Chris", "Jose", "Ana", "Tyler", "Alberto",
		"Carolina", "Catalina", "Leonardo", "Walter", "Helen", "Silvia",
		"Monse", "Camila", "Carlos", "Aracely", "Mario" };


	Lista<char> lC;

	for (int i = 0; i < rand() % 30 + 10; ++i) {
		char n = 'a' + rand() % 20;
		lC.insertarFinal(n);
	}

	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Lista Char" << endl;
	cout << endl;
	cout << lC << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << lC.getCantidad() << endl;
	cout << endl;


	Lista<double> lD;

	for (int i = 0; i < rand() % 30 + 10; ++i) {
		double n = (rand() % 1000) / 0.578971371391;
		lD.insertarFinal(n);
	}

	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Lista Double" << endl;
	cout << endl;
	cout << lD << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << lD.getCantidad() << endl;
	cout << endl;

	Lista<int> lI;

	for (int i = 0; i < rand() % 30 + 10; ++i) {
		int n = rand() % 1000;
		lI.insertarFinal(n);
	}

	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Lista Enteros" << endl;
	cout << endl;
	cout << lI << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << lI.getCantidad() << endl;
	cout << endl;

	Lista<Persona> lP;

	for (int w = 0; w < rand() % 30 + 10; ++w) {

		Persona p(rand() % 1000, s[rand() % 30], rand() % 100);
		lP.insertarFinal(p);

	}

	cout << "----------------------------------"<< endl;
	cout << endl;
	cout << "Lista Personas" << endl;
	cout << endl;
	cout << lP << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << lP.getCantidad() << endl;
	cout << endl;
	
	
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Preincremento" << endl;
	cout << endl;

	Iterador<Persona> it = lP.begin();
	while (it != lP.end()) {
		cout << *it << endl;
		++it;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Posincremento" << endl;
	cout << endl;

	Iterador<Persona> it2 = lP.begin();
	while (it2 != lP.end()) {
		cout << *it2 << endl;
		it2++;
	}


	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Inverso Predecremento" << endl;
	cout << endl;

	IteradorInverso<Persona> it3 = lP.rBegin();
	while (it3 != lP.rEnd()) {
		cout << *it3 << endl;
		--it3;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Inverso Posdecremento" << endl;
	cout << endl;

	IteradorInverso<Persona> it4 = lP.rBegin();
	while (it4 != lP.rEnd()) {
		cout << *it4 << endl;
		it4--;
	}

	system("pause");
	return 0;

}

