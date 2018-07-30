#ifndef __Vertice_H__
#define __Vertice_H__

#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

template< class T >
class Vertice
{
protected:
	T vertice;
	std::map< T, double > vertAdy;

public:
	Vertice();
	Vertice( T ver );
	Vertice( T ver, std::map< T, double > mapAdy );
	T getVertice();
	void setVertice( T nver );
	std::map< T, double > getVertAdy();
	void setVertAdy( std::map< T, double > mapAdy );
	bool buscar( T adyacente );
	bool eliminarAdy( T adyacente );
	bool insertarAdy( T adyacente, double peso);
	void DFS( std::list< Vertice< T > >& grafo, std::set< Vertice< T > >& visitados );
	void numComponentes( std::list< Vertice< T > >& grafo, std::set< Vertice< T > >& visitados );

	template< typename U >
	friend bool operator>( const Vertice< U >& left, const Vertice< U >& right );

	template< typename U >
	friend bool operator<( const Vertice< U >& left, const Vertice< U >& right );

	template< typename U >
	friend bool operator==( const Vertice< U >& left, const Vertice< U >& right );

	template< typename U >
	friend bool operator!=( const Vertice< U >& left, const Vertice< U >& right );
};

#include "Vertice.hxx"

#endif
