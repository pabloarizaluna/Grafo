#include "Grafo.h"

template< class T >
Grafo< T >::Grafo()
{

}

template< class T >
Grafo< T >::Grafo( std::list< Vertice< T > > vertices )
{
  this->vertices = vertices;
}

template< class T >
std::list< Vertice< T > > Grafo< T >::getVertices()
{
  return this->vertices;
}

template< class T >
void Grafo< T >::setVertices( std::list< Vertice< T > > nVertices )
{
  this->vertice = nVertices;
}

template< class T >
bool Grafo< T >::eliminarVert( T vertice )
{
  Vertice< T > vert( vertice );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), vert );
  if( elemento != ( this->vertice ).end() )
  {
    ( this->vertices ).erase( elemento );
    for( typename std::list< Vertice< T > >::iterator it =  ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
    {
      ( *it ).eliminarAdy( vertice );
    }
    return true;
  }
  return false;
}

template< class T >
bool Grafo< T >::insertarVert( T vertice )
{
  Vertice< T > vert( vertice );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), vert );
  if( elemento == ( this->vertices ).end() )
  {
    ( this->vertices ).push_back( vert );
    return true;
  }
  return false;
}

template< class T >
bool Grafo< T >::insertarArist( T inicio, T final, double peso )
{
  Vertice< T > ini( inicio );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), ini );
  if( elemento != ( this->vertices ).end() )
    elemento->insertarAdy( final, peso );
}

template< class T >
void Grafo< T >::recorridoPlano()
{
  int size = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); ++it )
  {
    std::cout << ( *it ).getVertice();
    size++;
    if( ( size ) != ( this->vertices ).size() )
      std::cout << " - ";
  }
  std::cout << std::endl;
}

template< class T >
void Grafo< T >::DFS( T vertice )
{
  std::set< Vertice< T > > visitados;
  Vertice< T > vert( vertice );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), vert );
  if( elemento != ( this->vertices ).end() )
  {
    typename std::set< Vertice< T > >::const_iterator itVis = visitados.find( *elemento );
    if( itVis == visitados.end() )
    {
      elemento->DFS( this->vertices, visitados );
    }
  }
  std::cout << std::endl;
}

template< class T >
void Grafo< T >::BFS( T vertice )
{
  Vertice< T > vert( vertice );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), vert );
  if( elemento != ( this->vertices ).end() )
  {
    std::queue< Vertice< T > > cola;
    std::set< Vertice< T > > visitados;
    cola.push( *elemento );
    while( !cola.empty() )
    {
      vert = cola.front();
      cola.pop();
      typename std::set< Vertice< T > >::iterator itVis = visitados.find( vert );
      if( itVis == visitados.end() )
      {
        std::cout << vert.getVertice() << " ";
        visitados.insert( vert );
      }
      for( auto& elemento : vert.getVertAdy() )
      {
        typename std::list< Vertice< T > >::iterator temp = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), Vertice< T >( elemento.first ) );
        if( temp != ( this->vertices ).end() )
          cola.push( *temp );
      }
    }
  }
  std::cout << std::endl;
}

template< class T >
int Grafo< T >::numComponentes()
{
  std::set< Vertice< T > > visitados;
  int componentes = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    typename std::set< Vertice< T > >::const_iterator itVis = visitados.find( *it );
    if( itVis == visitados.end() )
    {
      it->numComponentes( this->vertices, visitados );
      componentes++;
    }
  }
  return componentes;
}

template< class T >
bool Grafo< T >::tieneCaminoEuler()
{
  int numVert = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    int aux = ( ( *it ).getVertAdy() ).size() - this->gradoEntrada( ( *it ).getVertice() );
    if( aux > 1 || aux < -1 )
      numVert++;
    if( numVert > 2 )
      return false;
  }
  int componentes = this->numComponentes();
  if( componentes == 1 )
    return true;
  numVert = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    if( ( ( *it ).getVertAdy() ).size() == 0 && this->gradoEntrada( ( *it ).getVertice() ) == 0 )
      numVert++;
  }
  if( componentes == numVert )
    return true;
  return false;
}

template< class T >
bool Grafo< T >::tieneCircuitoEuler()
{
  int numVert = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    int aux = ( ( *it ).getVertAdy() ).size() - this->gradoEntrada( ( *it ).getVertice() );
    if( aux > 1 || aux < -1 )
      numVert++;
    if( numVert > 0 )
      return false;
  }
  int componentes = this->numComponentes();
  numVert = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    if( ( ( *it ).getVertAdy() ).size() == 0 && this->gradoEntrada( ( *it ).getVertice() ) == 0 )
      numVert++;
  }
  if( componentes == numVert )
    return true;
  return false;
}

template< class T >
int Grafo< T >::gradoEntrada( T vertice )
{
  int gradoEnt = 0;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    std::map< T, double > aux = ( *it ).getVertAdy();
    typename std::map< T, double >::iterator encontro = aux.find( vertice );
    if( encontro != aux.end() )
      gradoEnt++;
  }
  return gradoEnt;
}

template< class T >
dijkstra< T > Grafo< T >::Dijkstra( T vertice )
{
  double inf = std::numeric_limits< double >::infinity();
  std::map< Vertice< T >, double > dist;
  std::map< Vertice< T >, Vertice< T > > arbol;
  std::set< Vertice< T > > vert;
  for( typename std::list< Vertice< T > >::iterator it = ( this->vertices ).begin(); it != ( this->vertices ).end(); it++ )
  {
    if( vertice == ( *it ).getVertice() )
      dist[ *it ] = 0;
    else
      dist[ *it ] = inf;
    vert.insert( *it );
  }
  std::set< Vertice< T > > visitados;
  while( !vert.empty() )
  {
    Vertice< T > minVert = this->minDistancia( vert, dist, visitados );
    typename std::set< Vertice< T > >::iterator itVis = visitados.find( minVert );
    if( itVis == visitados.end() )
    {
      visitados.insert( minVert );
      vert.erase( minVert );
      for( auto& elemento : minVert.getVertAdy() )
      {
        if( dist[ elemento.first ] > dist[ minVert ] + elemento.second )
        {
          dist[ elemento.first ] = dist[ minVert ] + elemento.second;
          arbol[ elemento.first ] = minVert;
        }
      }
    }
  }
  dijkstra< T > solucion( dist, arbol );
  return solucion;
}

template< class T >
Vertice< T > Grafo< T >::minDistancia( std::set< Vertice< T > > vert, std::map< Vertice< T >, double > dist, std::set< Vertice< T > > visitados )
{
  double min = std::numeric_limits< double >::infinity();
  Vertice< T > minVert, aux;
  for( auto& it : dist )
  {
    aux = it.first;
    typename std::set< Vertice< T > >::iterator itVis = visitados.find( it.first );
    if( itVis == visitados.end() )
    {
      if( it.second <= min )
      {
        min = it.second;
        minVert = it.first;
      }
    }
  }
  return minVert;
}

template< class T >
prim< T > Grafo< T >::Prim( T vertice )
{
  std::set< Vertice< T > > visitados;
  std::map< Vertice< T >, double > dist;
  std::map< Vertice< T >, Vertice< T > > aristas;
  Vertice< T > uVert, vVert;
  int i = 0;
  typename std::list< Vertice< T > > ::iterator temp = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), Vertice< T >( vertice ) );
  if( temp != ( this->vertices ).end() )
  {
    dist[ *temp ] = 0;
    visitados.insert( *temp );
    while( i != visitados.size() )
    {
      double minPeso = std::numeric_limits< double >::infinity();
      for( typename std::set< Vertice< T > >::iterator uit = visitados.begin(); uit != visitados.end(); uit++ )
      {
        Vertice< T > u( *uit );
        for( auto& vit : u.getVertAdy() )
        {
          Vertice< T > aux( vit.first );
          typename std::set< Vertice< T > >::iterator encontro = visitados.find( aux );
          if( encontro == visitados.end() )
          {
            if( minPeso > vit.second )
            {
              minPeso = vit.second;
              uVert = u;
              typename std::list< Vertice< T > > ::iterator temp = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), aux );
              if( temp != ( this->vertices ).end() )
              {
                vVert = *temp;
                dist[ vVert ] = vit.second + dist[ uVert ];
              }
            }
          }
        }
      }
      visitados.insert( vVert );
      aristas[ vVert ] = uVert;
      i++;
    }
  }
  return prim< T >( dist, aristas );
}

template< class T >
void Grafo< T >::mostrarAdy( T vertice )
{
  Vertice< T > vert( vertice );
  typename std::list< Vertice< T > >::iterator elemento = std::find( ( this->vertices ).begin(), ( this->vertices ).end(), vert );
  if( elemento != ( this->vertices ).end() )
  {
    vert = *elemento;
    for( auto& x : vert.getVertAdy() )
    {
  		Vertice< T > ver( x.first );
      std::cout << ver.getVertice() << " ";
    }
  }
  std::cout << std::endl;
}
