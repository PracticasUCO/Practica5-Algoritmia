#include <cassert>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Material.hpp"
#include <limits>

using namespace std;

namespace algoritmia
{
	Material::Material()
	{
		this->borrarMaterial();
	}
	
	Material::Material(const string &nombre, const double &precio, const double &volumen)
	{
		this->setNombre(nombre);
		this->setPrecio(precio);
		this->setVolumen(volumen);
	}
	
	Material::Material(const Material &m)
	{
		*this = m;
	}
	
	void Material::setPrecio(const double &precio)
	{
		assert(precio >= 0.0);
		
		unsigned int euros;
		unsigned int centimos;
		
		euros = static_cast<unsigned int>(precio);
		centimos = static_cast<unsigned int>(precio * 100) - (euros * 100);
		
		if(centimos > 99)
		{
			euros += (centimos / 100);
			centimos = centimos % 100;
		}
		
		_valorEuros = euros;
		_valorCentimos = centimos;
	}
	
	void Material::borrarMaterial()
	{
		string nombre = "Empty";
		double precio = 0.0;
		double volumen = 0.0;
		
		this->setNombre(nombre);
		this->setPrecio(precio);
		this->setVolumen(volumen);
	}
	
	Material& Material::operator=(const Material &m)
	{
		string nombre;
		double precio;
		double volumen;
		
		nombre = m.getNombre();
		precio = m.getPrecio();
		volumen = m.getVolumen();
		
		this->setNombre(nombre);
		this->setPrecio(precio);
		this->setVolumen(volumen);
		
		return *this;
	}
	
	bool Material::operator==(const Material &m) const
	{
		return this->getPrecio() == m.getPrecio();
	}
	
	bool Material::operator>(const Material &m) const
	{
		if(this->getPrecio() > m.getPrecio())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Material::operator>=(const Material &m) const
	{
		return this->getPrecio() >= m.getPrecio();
	}
	
	bool Material::operator<(const Material &m) const
	{
		if(this->getPrecio()  < m.getPrecio())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Material::operator<=(const Material &m) const
	{
		return this->getPrecio() <= m.getPrecio();
	}
	
	Material& Material::operator+(const Material &m)
	{
		Material *suma = new Material;
		
		string nuevoNombre;
		double nuevoPrecio;
		double nuevoVolumen;
		
		nuevoNombre = "SUMA DE MATERIALES";
		nuevoPrecio = this->getPrecio() + m.getPrecio();
		nuevoVolumen = this->getVolumen() + m.getVolumen();
		
		suma->setNombre(nuevoNombre);
		suma->setPrecio(nuevoPrecio);
		suma->setVolumen(nuevoVolumen);
		
		return *suma;
	}
	
	Material& Material::operator-(const Material &m)
	{
		Material * resta = new Material;
		string nombre = "RESTA DE MATERIALES";
		
		double precio = this->getPrecio() - m.getPrecio();
		double volumen = this->getVolumen() - m.getVolumen();
		
		resta->setNombre(nombre);
		resta->setPrecio(precio);
		resta->setVolumen(volumen);
		
		return *resta;
	}
	
	ostream& operator<<(ostream &output, const Material &m)
	{
		string nombre;
		double precio;
		double volumen;
		
		nombre = m.getNombre();
		precio = m.getPrecio();
		volumen = m.getVolumen();
		
		output << "Nombre del material: " << nombre << endl;
		output << "Volumen del material: " << volumen << " Litro(s)"  <<endl;
		output << "Precio del material: " << precio << " €" << endl;
		
		return output;
	}
	
	istream& operator>>(istream &input, Material &m)
	{
		string nombre;
		double precio;
		double volumen;
		
		cout << "Introduzca el nombre del material: ";
		getline(input, nombre);
		
		cout << "Introduzca el volumen del material: ";
		input >> volumen;
		
		cout << "Introduzca el precio del material: ";
		input >> precio;
		
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		
		m.setNombre(nombre);
		m.setPrecio(precio);
		m.setVolumen(volumen);
		
		return input;
	}
}