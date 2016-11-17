#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "Vertice.h"
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <limits>

template< class T >
struct dijkstra
{
public:
	std::map< Vertice< T >, double > dist;
	std::map< Vertice< T >, Vertice< T > > arbol;

	dijkstra()
	{

	};

	dijkstra( std::map< Vertice< T >, double > dist, std::map< Vertice< T >, Vertice< T > > arbol )
	{
		this->dist = dist;
		this->arbol = arbol;
	};
};

template< class T >
struct prim
{
public:
	std::map< Vertice< T >, double > dist;
	std::map< Vertice< T >, Vertice< T > > aristas;

	prim()
	{

	};

	prim( std::map< Vertice< T >, double > dist, std::map< Vertice< T >, Vertice< T > > aristas )
	{
		this->dist = dist;
		this->aristas = aristas;
	};
};

template< class T >
class Grafo
{
protected:
	std::list< Vertice< T > > vertices;
public:
	Grafo();
	Grafo( std::list< Vertice< T > > vertices );
	std::list< Vertice< T > > getVertices();
	void setVertices( std::list< Vertice< T > > nVertices );
	bool eliminarVert( T vertice );
	bool insertarVert( T vertice );
	bool insertarVert( T vertice, std::map< Vertice< T >, double > mapAdy );
	bool insertarArist( T inicio, T final, double peso );
	bool eliminarArist( T inicio, T final );
	void mostrarAdy( T vertice );
	void recorridoPlano();
	void DFS( T vertice );
	void BFS( T vertice );
	int numComponentes();
	bool tieneCaminoEuler();
	bool tieneCircuitoEuler();
	int gradoEntrada( T vertice );
	dijkstra< T > Dijkstra( T vertice );
	Vertice< T > minDistancia( std::set< Vertice< T > > vert, std::map< Vertice< T >, double > dist, std::set< Vertice< T > > visitados );
	prim< T > Prim( T vertice );
};

#include "Grafo.hxx"

#endif
