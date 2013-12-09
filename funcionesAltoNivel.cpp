/** Funciones de alto nivel para el programa de la mochila
 * 
 *  Copyright (C) 2013  Pedro José Piquero Plaza (e-mail: gowikel@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * **/

#include <iostream>
#include "funcionesAltoNivel.hpp"

using namespace algoritmia;
using namespace std;

namespace algoritmia
{
	unsigned int menu()
	{
		unsigned int opcion;
		
		do
		{
			cout << endl;
			cout << "1- Añadir materiales disponibles" << endl;
			cout << "2- Ver materiales disponibles" << endl;
			cout << "3- Llenar mochila" << endl;
			cout << "4- Ver en detalle la mochila" << endl;
			cout << "5- Ver volumen y precio de la mochila" << endl;
			cout << "6- Cambiar volumen de la mochila" << endl;
			cout << "7- Borrar materiales disponibles" << endl;
			cout << "8- Borrar mochila" << endl;
			cout << endl;
			cout << "0- Salir" << endl;
			
			cout << "Introduzca una opcion: ";
			cin >> opcion;
			cout << endl << endl;
		}while(opcion > 8);
		
		return opcion;
	}
}