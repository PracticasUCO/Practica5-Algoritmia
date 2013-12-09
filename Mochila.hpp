/** Solucion al problema de la mochila 
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

#ifndef __MOCHILA_HPP
#define __MOCHILA_HPP

#include "ListaMateriales.hpp"
#include "Material.hpp"

namespace algoritmia
{
	class Mochila
	{
	private:
		ListaMateriales _materialesDisponibles;
		ListaMateriales _materialesSeleccionados;
		
		unsigned int _volumenMaximo;
		
	public:
		/** @brief Constructor vacio de clase **/
		inline Mochila()
		{
			this->setVolumen(0);
			//Las listas de materiales ya estan en un estado consistente
		}
		
		/** @brief Constructor por defecto de la Mochila.
		*   @param lista Lista de materiales disponibles
		*   @param volumen Volumen maximo que tendra la mochila **/
		inline Mochila(const ListaMateriales &lista, const unsigned int &volumen = 0)
		{
			this->setDisponibles(lista);
			this->setVolumen(volumen);
		}
		
		/** @brief Constructor de copia
		*  @param m Mochila a copiar
		* **/
		inline Mochila(const Mochila &m)
		{
			*this = m;
		}

		/** @brief Cambia el volumen de la mochila
		 *  @param volumen Nuevo volumen de la mochila
		 *  @warning El cambiar el volumen hara que se vacie la mochila **/
		inline void setVolumen(const unsigned int &volumen)
		{
			_materialesSeleccionados.clear();
			_volumenMaximo = volumen;
		}
		
		/** @brief Muestra los materiales disponibles **/
		void showDisponibles() const;
		
		/** @brief Establece los materiales disponibles
		*  @param mat Lista de materiales disponibles
		* **/
		inline void setDisponibles(const ListaMateriales &mat)
		{
			_materialesDisponibles = mat;
		}
		
		/** @brief Devuelve la lista de elementos disponibles **/
		inline ListaMateriales getDisponibles() const
		{
			return _materialesDisponibles;
		}
		
		/** @brief Añade un material para que este disponible
		*  @param mat Material a añadir
		*  @return True si se pudo añadir el material y false en caso contrario **/
		inline bool anadirMaterialDisponible(const Material &mat)
		{
			return _materialesDisponibles.add(mat);
		}
		
		/** @brief Llena la mochila intentando que sea de maximo valor **/
		void llenar();
		
		/** @brief Vacia la mochila **/
		inline void vaciar()
		{
			_materialesSeleccionados.clear();
		}
		
		/** @brief Devuelve el volumen relleno de la mochila **/
		inline unsigned int getVolumen() const
		{
			ListaMateriales lista = this->getMaterialesMochila();
			return lista.sumarVolumenes();
		}
		
		/** @brief Muestra los materiales de la mochila **/
		void show() const;
		
		/** @brief Devuelve la lista de los materiales introduccidos en la mochila **/
		inline ListaMateriales getMaterialesMochila() const
		{
			return _materialesSeleccionados;
		}
		
		/** @brief Devuelve el precio total de la mochila
		*  @return precio de la mochila **/
		inline double getValor() const
		{
			ListaMateriales lista = this->getMaterialesMochila();
			return lista.sumarPrecios();
		}
		
		/** @brief Devuelve el volumen llenado de la mochila
		*  @return Volumen lleno de la mochila
		* **/
		inline unsigned int getVolumenMaximo() const
		{
			return _volumenMaximo;
		}
		
		/** @brief Muestra toda la información de los materiales guardados en la mochila **/
		inline void detail() const
		{
			ListaMateriales lista = this->getMaterialesMochila();
			cout << lista << endl;
		}
		
		/** @brief Comprueba si la mochila esta vacia
		*  @return True si la mochila esta vacia, false en caso contrario **/
		inline bool empty() const
		{
			return _materialesSeleccionados.empty();
		}
		
		/** @brief Comprueba si hay materiales disponibles
		*  @return True si aún quedan materiales disponibles, False en caso contrario **/
		inline bool hayMateriales() const
		{
			return !(_materialesDisponibles.empty());
		}
		
		/** @brief Devuelve una copia de la mochila
		*  @return Una mochila exactamente igual que esta
		* **/
		Mochila& clone() const;
		
		/** @brief Borra la lista de materiales disponibles **/
		inline void clearDisponibles()
		{
			_materialesDisponibles.clear();
		}
		
		/** @brief Destructor de la clase **/
		inline ~Mochila()
		{
			//No es necesario
		}
		
		/** @brief Sobrecarga del operador =
		*  @param m Mochila a copiar
		*  @return Una mochila exactamente igual que la anterior **/
		inline Mochila& operator=(const Mochila &m)
		{
			return m.clone();
		}
		
		/** @brief Sobrecarga del operador ==
		*  @param m Mochila con la que se comprobara la clase
		*  @return True si las dos mochilas tienen el mismo valor, false en caso contrario
		* **/
		inline bool operator==(const Mochila &m) const
		{
			return this->getValor() == m.getValor();
		}
		
		/** @brief Sobrecarga del operador >
		*  @param m Mochila con la que se hara la copia
		*  @return True si la mochila tiene mas valor que m. False en caso contrario **/
		inline bool operator>(const Mochila &m) const
		{
			return this->getValor() > m.getValor();
		}
		
		/** @brief Sobrecarga del operador >=
		*  @param m Mochila con la que se hara la comprobacion
		*  @return True si la mochila tiene mas valor o igual que m. False en caso contrario **/
		inline bool operator>=(const Mochila &m) const
		{
			return this->getValor() >= m.getValor();
		}
		
		/** @brief Sobrecarga del operador <
		*  @param m Mochila con la que realizar la comparacion
		*  @return True si la mochila tiene menos valor que m. False en caso contrario **/
		inline bool operator<(const Mochila &m) const
		{
			return this->getValor() < m.getValor();
		}
		
		/** @brief Sobrecarga del operador <=
		*  @param m Mochila con la que realizar la operacion
		*  @return True si la mochila tiene menos valor o igual que m. False en caso contrario **/
		inline bool operator<=(const Mochila &m) const
		{
			return this->getValor() <= m.getValor();
		}
		
		/** @brief Sobrecarga del operador << **/
		friend ostream& operator<<(ostream &output, const Mochila &m);
		
		/** @brief Sobrecarga del operador >> **/
		friend istream& operator>>(istream &input, Mochila &m);
	};
}

#endif
