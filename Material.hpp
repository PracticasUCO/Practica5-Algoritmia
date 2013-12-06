/** Clase Material, representa un material por su nombre, volumen y precio
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

#ifndef __MATERIAL_HPP
#define __MATERIAL_HPP

#include <iostream>

using namespace std;

namespace algoritmia
{
	class Material
	{
	private:
		string _nombre;
		unsigned int _valorEuros;
		unsigned int _valorCentimos;
		unsigned int _volumen;
		
	public:
		/** @brief Constructor vacio
		 * **/
		Material();
		
		/** @brief Constructor de la clase Material
		*  @param nombre Nombre del material
		*  @param volumen Volumen que ocupa el material
		*  @param precio Precio del volumen
		* **/
		Material(const string &nombre, const double &precio, const unsigned int &volumen);
		
		/** @brief Constructor de copia de la clase Material
		*  @param m Material a ser copiado
		* **/
		Material(const Material &m);
		
		/** @brief Establece el nombre del material
		*  @param nombre Nombre del material
		* **/
		inline void setNombre(const string &nombre)
		{
			_nombre = nombre;
		}
		
		/** @brief Devuelve el nombre del material
		*  @return Nombre del material
		* **/
		inline string getNombre() const
		{
			return _nombre;
		}
		
		/** @brief Establece el volumen que ocupa el material
		 *  @param volumen Volumen del material
		 * **/
		inline void setVolumen(const unsigned int &volumen)
		{
			_volumen = volumen;
		}
		
		/** @brief Devuelve el volumen del material
		*  @return Volumen del material
		* **/
		inline unsigned int getVolumen() const
		{
			return _volumen;
		}
		
		/** @brief Devuelve el precio del material, expresado como un double
		*  @return Precio del material
		* **/
		inline double getPrecio() const
		{
			return static_cast<double>(_valorEuros) + static_cast<double>(_valorCentimos) / 100;
		}
		
		/** @brief Establece el precio del material
		*  @param precio Precio del material
		* **/
		void setPrecio(const double &precio);
		
		/** @brief Borra el material **/
		void borrarMaterial();
		
		/** @brief Sobrecarga del operador = **/
		Material& operator=(const Material &m);
		
		/** @brief Sobrecarga del operador == **/
		bool operator==(const Material &m) const;
		
		/** @brief Sobrecarga del operador > **/
		bool operator>(const Material &m) const;
		
		/** @brief Sobrecarga del operador >= **/
		bool operator>=(const Material &m) const;
		
		/** @brief Sobrecarga del operador < **/
		bool operator<(const Material &m) const;
		
		/** @brief Sobrecarga del operador <= **/
		bool operator<=(const Material &m) const;
		
		/** @brief Sobrecarga del operador +
		*  Esta sobrecarga implica la suma de los precios y volumenes de los materiales, lo cual se devolvera
		*  en una clase Material, la cual contendra:
		*  Volumen final: volumenA + volumenB
		*  Precio final: preciaA + precioB
		*  Nombre: Concatenacion de nombreA + " and " + nombreB
		* **/
		Material& operator+(const Material &m);
		
		/** @brief Sobrecarga del operador -
		*  Esta sobrecarga implica la resta de el volumenA - volumenB y precioA - precioB, si y solo si,
		*  el nombre del material contiene un and y el nombre del material m. En caso contrario devuelve
		*  el material tal y como esta
		* **/
		Material& operator-(const Material &m);
		
		/** @brief Sobrecarga del operador <<
		* **/
		friend ostream& operator<<(ostream &output, const Material &m);
		
		/** @brief Sobrecarga del operador >>
		 * **/
		friend istream& operator>>(istream &input, Material &m);
	};
}

#endif
