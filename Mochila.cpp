/** Clase Mochila, representa una Mochila que debe de ser llenada de materiales
 *  hasta alcanzar el tamaño maximo, maximizando el precio de los materiales que
 *  se introduccen en ella
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
#include <list>
#include <string>
#include <limits>
#include <valarray>
#include "Mochila.hpp"
#include "ListaMateriales.hpp"

using namespace std;

namespace algoritmia
{
	void Mochila::showDisponibles() const
	{
		ListaMateriales lista = this->getDisponibles();
		cout << lista << endl;
	}
	
	void Mochila::show() const
	{
		ListaMateriales lista = this->getMaterialesMochila();
		
		for(unsigned int i = 0; i < lista.size(); i++)
		{
			Material mat = lista.get(i);
			cout << mat.getNombre() << " - ";
		}
		cout << endl;
	}
	
	Mochila& Mochila::clone() const
	{
		ListaMateriales disponibles = this->getDisponibles();
		ListaMateriales mochila = this->getMaterialesMochila();
		unsigned int volumen = this->getVolumenMaximo();
		
		Mochila  *nueva = new Mochila(disponibles, volumen);
		nueva->llenar();
		return *nueva;
	}
	
	void Mochila::llenar()
	{
		//Inicialización de las variables que nos seran utiles durante el proceso de llenado
		ListaMateriales disponibles = this->getDisponibles(); //Almacena una lista de materiales de los que disponemos
		unsigned int nDisponibles = disponibles.size(); //Mantiene cuantos elementos disponemos
		unsigned int volumenMaximo = this->getVolumenMaximo();  //Dice cual es el volumen maximo de la mochila, el cual no se debe sobrepasar
		valarray<valarray<double> > elementos; //Matriz de elementos, en los cuales se ira buscando la solución optima en cada paso
		
		//Vaciamos la lista de materiales seleccionados
		this->vaciar();
		
		//Redimensionamos la matriz de precios, a una dimension de nDisponibles x volumenMaximo (filas x columnas)
		elementos.resize(nDisponibles);
		
		for(unsigned int i = 0; i < elementos.size(); i++)
		{
			elementos[i].resize(volumenMaximo + 1, 0);
		}
		
		//Ordenamos lso materiales que se encuentran disponibles en orden creciente de volumen
		disponibles.sort(ORDER_BY_VOLUMEN);
		
		// La primera fila de la matriz es igual a una serie de elementos que valdran cero y el resto de
		// ellos valdran el volumen del material más pequeño * su precio
		// con esto ponemos toda la fila a un valor distinto de cero
		elementos[0] = disponibles.get(0).getPrecio() * disponibles.get(0).getVolumen();
		//elementos[0][0] = 0;
		
		// Con este bucle colocamos aquellos pocos elementos de la fila que deberian de estar a cero.
		for(unsigned int i = 0; i < elementos[0].size(); i++)
		{
			Material m = disponibles.get(0);
			if(m.getVolumen() < i)
			{
				elementos[0][i] = 0;
			}
			else
			{
				break;
			}
		}
		
		unsigned int volumen = disponibles.get(0).getVolumen();
		
		//Rellenamos la matriz de doubles
		for(unsigned int i = 1; i < disponibles.size(); i++)
		{
			Material mat = disponibles.get(i);
			unsigned int k;
			volumen += mat.getVolumen();
			bool relleno = false;
			
			for(unsigned int j = 1; j < elementos[i].size(); j++)
			{
				if(mat.getVolumen() > j)
				{
					elementos[i][j] = elementos[i-1][j];
				}
				else if(elementos[i-1][j] > (elementos[i][j-mat.getVolumen()] + (mat.getPrecio() * mat.getVolumen())))
				{
					elementos[i][j] = elementos[i-1][j];
				}
				else
				{
					elementos[i][j] = elementos[i][j-mat.getVolumen()] + (mat.getPrecio() * mat.getVolumen());
					//elementos[i][j+1] = elementos[i][j - mat.getVolumen() + 1] + (mat.getPrecio() * mat.getVolumen());
					
					if(volumen <= j)
					{
						k = j;
						relleno = true;
						break;
					}
				}
			}
			
			if(relleno)
			{
				for(unsigned int j = k + 1; j < elementos[i].size(); j++)
				{
					elementos[i][j] = elementos[i][j - 1];
				}
			}
		}
		
		// Leemos la matriz y guardamos el resultado
		for(unsigned int i = disponibles.size() - 1, columnaBusqueda = this->getVolumenMaximo(); ((i >= 0) && (columnaBusqueda != 0)); i--)
		{
			if(i == 0)
			{
				Material mat = disponibles.get(i);
				_materialesSeleccionados.add(mat);
				break;
			}
			else if(elementos[i][columnaBusqueda] != elementos[i - 1][columnaBusqueda])
			{
				Material mat = disponibles.get(i);
				_materialesSeleccionados.add(mat);
				columnaBusqueda -= mat.getVolumen();
			}
		}
		
	}
	
	ostream& operator<<(ostream &output, const Mochila &m)
	{
		ListaMateriales lista = m.getMaterialesMochila();
		
		output << "Volumen maximo: " << m.getVolumenMaximo() << " Litro(s)" << endl;
		output << "Volumen rellenado: " << m.getVolumen() << " Litro(s)" << endl;
		output << "Precio obtenido: " << lista.sumarPrecios() << " €" << endl;
		output << "Lista de materiales: " << endl;
		output << "====================" << endl;
		output << lista << endl;
		return output;
	}
	
	istream& operator>>(istream &input, Mochila &m)
	{
		ListaMateriales lista;
		unsigned int nElementos;
		double volumenMaximo;
		
		cout << "Introduzca el volumen maximo de la mochila: ";
		input >> volumenMaximo;
		cout << endl;
		
		cout << "Introduzca el numero de elementos disponibles: ";
		input >> nElementos;
		cout << endl;
		
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		
		for(unsigned int i = 0; i < nElementos; i++)
		{
			Material mat;
			cout << "INTRODUCCIENDO EL MATERIAL " << i + 1 << endl;
			cin >> mat;
			cout << endl;
			lista.add(mat);
		}
		
		m.setVolumen(volumenMaximo);
		m.setDisponibles(lista);
		m.llenar();
		
		return input;
	}
}