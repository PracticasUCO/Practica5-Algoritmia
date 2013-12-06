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

#include <iostream>
#include <string>
#include <limits>
#include "ListaMateriales.hpp"
#include "Material.hpp"

using namespace std;

namespace algoritmia
{
	void ListaMateriales::show() const
	{
		list<Material> l = this->getLista();
		
		for(list<Material>::iterator iterador = l.begin(); iterador != l.end(); iterador++)
		{
			cout << *iterador;
			cout << endl;
		}
	}
	
	bool ListaMateriales::add(const Material &m)
	{
		if(this->find(m)) //El material ya esta
		{
			return false;
		}
		else
		{
			_lista.push_back(m);
			return true;
		}
	}
	
	bool ListaMateriales::remove(const Material &m)
	{
		if(this->find(m))
		{
			for(list<Material>::iterator i = _lista.begin(); i != _lista.end(); i++)
			{
				if(m.getNombre() == i->getNombre())
				{
					_lista.erase(i);
					break;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	
	unsigned int ListaMateriales::size() const
	{
		return _lista.size();
	}
	
	Material ListaMateriales::get(const unsigned int &n) const
	{
		if(this->size() < n)
		{
			Material empty;
			return empty;
		}
		else
		{
			list<Material> lista = this->getLista();
			
			list<Material>::iterator iterador = lista.begin();
			
			for(unsigned int i = 0; i < n; i++)
			{
				iterador++;
			}
			return *iterador;
		}
	}
	
	Material ListaMateriales::get(const string &s) const
	{
		if(this->find(s))
		{
			list<Material> lista = this->getLista();
			
			list<Material>::iterator i;
			
			for(i = lista.begin(); i != lista.end(); i++)
			{
				if(i->getNombre() == s)
				{
					break;
				}
			}
			return *i;
		}
		else
		{
			Material empty;
			return empty;
		}
	}
	
	Material ListaMateriales::get(const Material &m) const
	{
		if(this->find(m))
		{
			list<Material> lista = this->getLista();
			list<Material>::iterator i;
			
			for(i = lista.begin(); i != lista.end(); i++)
			{
				if(i->getNombre() == m.getNombre())
				{
					break;
				}
			}
			return *i;
		}
		else
		{
			Material empty;
			return empty;
		}
	}
	
	bool ListaMateriales::find(const Material &m) const
	{
		list<Material> lista = this->getLista();
		bool resultado = false;
		
		for(list<Material>::iterator i = lista.begin(); i != lista.end(); i++)
		{
			if(i->getNombre() == m.getNombre())
			{
				resultado = true;
				break;
			}
		}
		return resultado;
	}
	
	bool ListaMateriales::find(const string &s) const
	{
		list<Material> lista = this->getLista();
		bool resultado = false;
		
		for(list<Material>::iterator i = lista.begin(); i != lista.end(); i++)
		{
			if(i->getNombre() == s)
			{
				resultado = true;
				break;
			}
		}
		return resultado;
	}
	
	Material ListaMateriales::sumar() const
	{
		Material suma;
		list<Material> lista = this->getLista();
		
		for(list<Material>::iterator i = lista.begin(); i != lista.end(); i++)
		{
			suma = suma + *i;
		}
		
		return suma;
	}
	
	ostream& operator<<(ostream &output, const ListaMateriales &l)
	{
		for(unsigned int i = 0; i < l.size(); i++)
		{
			Material m = l.get(i);
			output << m;
			output << endl;
		}
		
		return output;
	}
	
	istream& operator>>(istream &input, ListaMateriales &l)
	{
		unsigned int nMateriales;
		
		cout << "Introduzca el numero de materiales a añadir: ";
		input >> nMateriales;
		cout << endl;
		
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		
		for(unsigned int i = 0; i < nMateriales; i++)
		{
			Material m;
			
			cout << "Introducciendo el material " << i + 1 << endl;
			input >> m;
			cout << endl;
			
			cout << "Añadiendo el material " << i + 1 << " ... ";
			
			if(l.add(m))
			{
				cout << "Ok" << endl;
			}
			else
			{
				cout << "Fail. El material ya estaba en la lista" << endl;
				i--;
			}
			cout << endl;
		}
		return input;
	}
	
	ListaMateriales& ListaMateriales::operator=(const ListaMateriales &l)
	{
		list<Material> lista = l.getLista();
		
		_lista = lista;
		
		return *this;
	}
	
	bool ListaMateriales::operator==(const ListaMateriales &l) const
	{
		Material sumaA;
		Material sumaB;
		
		sumaA = this->sumar();
		sumaB = l.sumar();
		
		if(sumaA.getPrecio() == sumaB.getPrecio())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ListaMateriales::operator>(const ListaMateriales &l) const
	{
		if(this->sumarPrecios() > l.sumarPrecios())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ListaMateriales::operator>=(const ListaMateriales &l) const
	{
		if(this->sumarPrecios() >= l.sumarPrecios())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ListaMateriales::operator<(const ListaMateriales &l) const
	{
		if(this->sumarPrecios() < l.sumarPrecios())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool ListaMateriales::operator<=(const ListaMateriales &l) const
	{
		if(this->sumarPrecios() <= l.sumarPrecios())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	ListaMateriales& ListaMateriales::operator+(const ListaMateriales &l) const
	{
		ListaMateriales * n = new ListaMateriales;
		list<Material> lista = l.getLista();
		
		*n = *this;
		
		for(list<Material>::iterator i = lista.begin(); i != lista.end(); i++)
		{
			n->add(*i); //El metodo add ya tiene cuidado de no añadir repetidos
		}
		
		return *n;
	}
	
	ListaMateriales& ListaMateriales::operator-(const ListaMateriales &l) const
	{
		ListaMateriales * n = new ListaMateriales;
		list<Material> lista = l.getLista();
		
		*n = *this;
		
		for(list<Material>::iterator i = lista.begin(); i != lista.end(); i++)
		{
			n->remove(*i); //El metodo remove tiene cuidado de borrar los materiales adecuados
		}
		
		return *n;
	}
};