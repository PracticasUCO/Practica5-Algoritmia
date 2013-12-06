/** Clase ListaMateriales, la cual genera una lista especifica de Materiales
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

#ifndef __LISTA_MATERIALES_HPP
#define __LISTA_MATERIALES_HPP

#include <list>
#include <string>
#include "Material.hpp"

using namespace std;

namespace algoritmia
{
	class ListaMateriales
	{
	private:
		list<Material> _lista;
		
	public:
		/** @brief Constructor vacio **/
		inline ListaMateriales()
		{
			//El constructor en este caso es vacio
		}
		
		/** @brief Constructor de copia **/
		inline ListaMateriales(const ListaMateriales &l)
		{
			*this = l;
		}
		
		inline list<Material> getLista() const //Devuelve una copia de la lista interna
		{
			return _lista;
		}
		
		/** @brief Muestra la lista almacenada por pantalla **/
		void show() const;
		
		/** @brief Almacena un elemento en la lista (si es que no esta repetido)
		 *  @param m El material a ser añadido
		 *  @return True si pudo añadir el elemento, false en caso contrario **/
		bool add(const Material &m);
		
		/** @brief Borra un elemento de la lista
		 *  @param m El elemento a ser borrado
		 *  @return True si pudo borrar el elemento, false en caso contrario **/
		bool remove(const Material &m);
		
		/** @brief Devuelve el numero de materiales almacenado
		 *  @return Un valor indicando el numero de materiales almacenado
		 * **/
		unsigned int size() const;
		
		/** @brief Devuelve el material que ocupa la posicion n
		 *  @param n Elemento que se desea coger
		 *  @return El material de la posicion n, siempre y cuando no sobrepase 
		 *  el tamaño de la lista, en cuyo caso devolvera un material Vacio**/
		Material get(const unsigned int &n) const;
		
		/** @brief Devuelve el material que coincida con el nombre s
		 *  @param s Nombre del material que se desea obtener
		 *  @return El material s si es hallado, o un material vacio en caso contrario **/
		Material get(const string &s) const;
		
		/** @brief Devuelve el material que coincida con m
		 *  @param m Material que se desea su coincidencia
		 *  @return El material que se deseaba de la lista, o Empty si no esta **/
		Material get(const Material &m) const;
		
		/** @brief Busca un elemento en la lista
		 *  @param m El elemento a buscar
		 *  @return True si el elemento esta en la lista, false en caso contrario
		 * **/
		bool find(const Material &m) const;
		
		/** @brief Busca el material en la lista por su nombre
		 *  @param s El nombre del material a buscar
		 *  @return True si el elemento esta en la lista, y false en caso contrario **/
		bool find(const string &s) const;
		
		/** @brief Devuelve la suma de todos los elementos de la lista, en formato Material
		 *  @return Un Material, que contiene la suma de todos los campos de la lista **/
		Material sumar() const;
		
		/** @brief Devuelve la suma de todos los precios de la lista **/
		inline double sumarPrecios() const
		{
			list<Material>::const_iterator it;
			double precio = 0;
			
			for(it = _lista.begin(); it != _lista.end(); it++)
			{
				precio += (it->getVolumen() * it->getPrecio());
			}
			
			return precio;
		}
		
		/** @brief Devuelve la suma de todos los volumenes de la lista **/
		inline unsigned int sumarVolumenes() const
		{
			Material suma = this->sumar();
			
			return suma.getVolumen();
		}
		
		/** @brief Comprueba si la lista esta vacia
		 *  @return True si la lista esta vacia, False en caso contrario **/
		inline bool empty() const
		{
			return _lista.empty();
		}
		
		/** @brief Ordena la lista de materiales
		 * **/
		inline void sort()
		{
			_lista.sort();
		}
		
		/** @brief Revierte el orden de los elementos
		 * **/
		inline void reverse()
		{
			_lista.reverse();
		}
		
		/** @brief Borra completamente la lista **/
		inline void clear()
		{
			_lista.clear();
		}
		
		friend ostream& operator<<(ostream &output, const ListaMateriales &l);
		friend istream& operator>>(istream &input, ListaMateriales &l);
		ListaMateriales& operator=(const ListaMateriales &l);
		bool operator==(const ListaMateriales &l) const;
		bool operator>(const ListaMateriales &l) const;
		bool operator>=(const ListaMateriales &l) const;
		bool operator<(const ListaMateriales &l) const;
		bool operator<=(const ListaMateriales &l) const;
		ListaMateriales& operator+(const ListaMateriales &l) const;
		ListaMateriales& operator-(const ListaMateriales &l) const;
	};
}

#endif
 
