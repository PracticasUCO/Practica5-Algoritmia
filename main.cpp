/** Esqueleto principal del programa que muestra una solucion al problema de la mochila
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
#include <limits>
#include "Material.hpp"
#include "ListaMateriales.hpp"
#include "Mochila.hpp"
#include "funcionesAltoNivel.hpp"

using namespace std;
using namespace algoritmia;

int main()
{
	Mochila mochila;
	unsigned int opcion;
	double volumenInicial;
	
	cout << "Introduzca el volumen inicial de la mochila: ";
	cin >> volumenInicial;
	cout << endl;
	
	mochila.setVolumen(volumenInicial);
	
	do
	{
		opcion = menu();
		cin.ignore();
		switch(opcion)
		{
			case 1:
			{
				unsigned int nMateriales;
				
				cout << "Introduzca el numero de materiales a introduccir: ";
				cin >> nMateriales;
				cout << endl;
				
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				for(unsigned int i = 0; i < nMateriales; i++)
				{
					Material m;
					cout << "Introducciendo el material Nº " << i + 1 << endl;
					cout << "==============================" << endl;
					cin >> m;
					cout << endl;
					
					cout << "Añadiendo material Nº " << i + 1 << " ...";
					if(mochila.anadirMaterialDisponible(m))
					{
						cout << " OK" << endl;
					}
					else
					{
						cout << " FAIL. Probablemente el material ya existia" << endl;
						i--;
					}
					cout << endl;
				}
				break;
			}
			
			case 2:
				if(mochila.hayMateriales())
				{
					ListaMateriales lista = mochila.getDisponibles();
					cout << lista << endl;
				}
				else
				{
					cout << "No hay materiales disponibles" << endl;
				}
				break;
				
			case 3:
				mochila.llenar();
				break;
				
			case 4:
				cout << mochila << endl;
				break;
				
			case 5:
				cout << "Precio: " << mochila.getValor() << " €" << endl;
				cout << "Volumen: " << mochila.getVolumen() << " L" << endl;
				cout << "Volumen maximo: " << mochila.getVolumenMaximo() << " L" << endl;
				break;
				
			case 6:
				{
					double nuevoVolumen;
					cout << "Introduzca el nuevo volumen: ";
					cin >> nuevoVolumen;
					cout << endl;
					
					mochila.setVolumen(nuevoVolumen);
				}
				break;
			case 7:
				mochila.clearDisponibles();
				break;
				
			case 8:
				mochila.vaciar();
				break;
				
			case 0:
				break;
				
			default:
				cerr << "Parametro recibido invalido " << opcion << " del menu" << endl;
				break;
		}
	}while(opcion != 0);
	
	return 0;
}
