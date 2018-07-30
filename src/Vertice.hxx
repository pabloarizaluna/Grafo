#include "Vertice.h"

template< class T >
Vertice< T >::Vertice()
{
	this->vertice = T( NULL );
}

template< class T >
Vertice< T >::Vertice( T ver )
{
	this->vertice = ver;
}

template< class T >
Vertice< T >::Vertice( T ver, std::map< T, double > mapAdy )
{
	this->vertice = ver;
	this->vertAdy = mapAdy;
}

template< class T >
T Vertice< T >::getVertice()
{
	return this->vertice;
}

template< class T >
void Vertice< T >::setVertice( T ver )
{
	this->vertice = ver;
}

template< class T >
std::map< T, double > Vertice< T >::getVertAdy()
{
	return this->vertAdy;
}

template< class T >
void Vertice< T >::setVertAdy( std::map< T, double > mapAdy )
{
	this->vertAdy = mapAdy;
}

template< class T >
bool Vertice< T >::buscar( T adyacente )
{
	typename std::map< T, double >::const_iterator it = ( this->vertAdy ).find( adyacente );
	return it != ( this->vertAdy ).end();
}

template< class T >
bool Vertice< T >::insertarAdy( T adyacente, double peso )
{
	( this->vertAdy ).emplace( adyacente, peso );
	return true;
}

template< class T >
bool Vertice< T >::eliminarAdy( T adyacente )
{
	if( !( this->buscar( adyacente ) ) )
	{
		( this->vertAdy ).erase( adyacente );
		return true;
	}
	return false;
}

template< class T >
void Vertice< T >::DFS( std::list< Vertice< T > >& grafo, std::set< Vertice< T > >& visitados )
{
  std::cout << this->vertice << " ";
	visitados.insert( *this );
	for( typename std::map< T, double >::iterator it = ( this->vertAdy ).begin(); it != ( this->vertAdy ).end(); it++ )
  {
		Vertice< T > ver( it->first );
    typename std::set< Vertice< T > >::iterator itVis = visitados.find( ver );
    if( itVis == visitados.end() )
    {
		  typename std::list< Vertice< T > >::iterator elemento = std::find( grafo.begin(), grafo.end(), ver );
			elemento->DFS( grafo, visitados );
    }
  }
}

template< class T >
void Vertice< T >::numComponentes( std::list< Vertice< T > >& grafo, std::set< Vertice< T > >& visitados )
{
	visitados.insert( *this );
	for( typename std::map< T, double >::iterator it = ( this->vertAdy ).begin(); it != ( this->vertAdy ).end(); it++ )
  {
		Vertice< T > ver( it->first );
    typename std::set< Vertice< T > >::iterator itVis = visitados.find( ver );
    if( itVis == visitados.end() )
    {
		  typename std::list< Vertice< T > >::iterator elemento = std::find( grafo.begin(), grafo.end(), ver );
			elemento->numComponentes( grafo, visitados );
    }
  }
}

template< class T >
bool operator>( Vertice< T >& left, Vertice< T >& right )
{
	return left.vertice > right.vertice;
}

template< class T >
bool operator<( const Vertice< T >& left, const Vertice< T >& right )
{
	return left.vertice < right.vertice;
}

template< class T >
bool operator==( const Vertice< T >& left, const Vertice< T >& right )
{
	return left.vertice == right.vertice;
}

template< class T >
bool operator!=( const Vertice< T >& left, const Vertice< T >& right )
{
	return !( left == right );
}
