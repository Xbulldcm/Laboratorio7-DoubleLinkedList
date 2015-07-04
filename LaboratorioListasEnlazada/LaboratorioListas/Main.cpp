

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

	Lista<int> l;

	for (int i = 0; i < rand() % 30 + 10; ++i) {
		int n = rand() % 1000;
		l.insertarFinal(n);
	}

	cout << "Lista Enteros" << endl;
	cout << endl;
	cout << l << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << l.getCantidad() << endl;
	cout << endl;

	Lista<Persona> l2;

	for (int w = 0; w < rand() % 30 + 10; ++w) {

		Persona p(rand() % 1000, s[rand() % 30], rand() % 100);
		l2.insertarFinal(p);

	}

	cout << "----------------------------------"<< endl;
	cout << endl;
	cout << "Lista Personas" << endl;
	cout << endl;
	cout << l2 << endl;
	cout << endl;
	cout << "Cantidad de Elementos: " << l2.getCantidad() << endl;
	cout << endl;
	
	
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Preincremento" << endl;
	cout << endl;

	Iterador<Persona> it = l2.begin();
	while (it != l2.end()) {
		cout << *it << endl;
		++it;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Posincremento" << endl;
	cout << endl;

	Iterador<Persona> it2 = l2.begin();
	while (it2 != l2.end()) {
		cout << *it2 << endl;
		it2++;
	}


	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Inverso Predecremento" << endl;
	cout << endl;

	IteradorInverso<Persona> it3 = l2.rBegin();
	while (it3 != l2.rEnd()) {
		cout << *it3 << endl;
		--it3;
	}

	cout << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << "Iterador Inverso Posdecremento" << endl;
	cout << endl;

	IteradorInverso<Persona> it4 = l2.rBegin();
	while (it4 != l2.rEnd()) {
		cout << *it4 << endl;
		it4--;
	}

	system("pause");
	return 0;

}

