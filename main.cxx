#include <iostream>
#include <limits>
#include "Grafo.h"

int main()
{
  std::cout << "Ejercicio 1" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  Grafo< char > ejercicio1;
  char vertice = 'A';
  for( int i = 0; i < 12; i++ )
  {
    ejercicio1.insertarVert( vertice );
    vertice++;
  }
  ejercicio1.insertarArist( 'A', 'B', 20 );
  ejercicio1.insertarArist( 'A', 'C', 15 );

  ejercicio1.insertarArist( 'B', 'D', 12 );
  ejercicio1.insertarArist( 'B', 'E', 32 );

  ejercicio1.insertarArist( 'C', 'B', 18 );
  ejercicio1.insertarArist( 'C', 'D', 28 );
  ejercicio1.insertarArist( 'C', 'G', 35 );

  ejercicio1.insertarArist( 'D', 'E', 17 );
  ejercicio1.insertarArist( 'D', 'H', 45 );

  ejercicio1.insertarArist( 'E', 'F', 12 );

  ejercicio1.insertarArist( 'F', 'H', 11 );
  ejercicio1.insertarArist( 'F', 'I', 17 );

  ejercicio1.insertarArist( 'G', 'H', 9 );
  ejercicio1.insertarArist( 'G', 'J', 12 );

  ejercicio1.insertarArist( 'H', 'I', 8 );
  ejercicio1.insertarArist( 'H', 'K', 5 );

  ejercicio1.insertarArist( 'I', 'L', 7 );

  ejercicio1.insertarArist( 'J', 'K', 7 );
  ejercicio1.insertarArist( 'J', 'L', 18 );

  ejercicio1.insertarArist( 'K', 'L', 11 );

  ejercicio1.recorridoPlano();
  ejercicio1.BFS( 'A' );

  dijkstra< char > distancia1 = ejercicio1.Dijkstra( 'A' );
  for( typename std::map< Vertice< char >, double >::iterator it = ( distancia1.dist ).begin(); it != ( distancia1.dist ).end(); it++ )
  {
    Vertice< char > aux( it->first );
    std::cout << "Vertice: " << aux.getVertice() << " Peso: " << ( it->second ) << std::endl;
  }
  for( auto& it : distancia1.arbol )
  {
    Vertice< char > auxP( it.second ), auxH( it.first );
    std::cout << "VerticeP: " << auxP.getVertice() << " VerticeH: " << auxH.getVertice() << std::endl;
  }
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;

  Grafo< int > ejercicio2;
  for( int i = 1; i <=7; i++ )
    ejercicio2.insertarVert( i );
  ejercicio2.recorridoPlano();

  ejercicio2.insertarArist( 1, 3, 6 );
  ejercicio2.insertarArist( 1, 7, -5 );

  ejercicio2.insertarArist( 2, 5, 3 );

  ejercicio2.insertarArist( 3, 2, 5 );
  ejercicio2.insertarArist( 3, 6, -1 );

  ejercicio2.insertarArist( 4, 1, 8 );
  ejercicio2.insertarArist( 4, 2, -2 );
  ejercicio2.insertarArist( 4, 3, 4 );
  ejercicio2.insertarArist( 4, 6, 6 );

  ejercicio2.insertarArist( 5, 6, 6 );

  ejercicio2.insertarArist( 7, 4, 9 );
  ejercicio2.insertarArist( 7, 5, 5 );

  std::cout << "-----------------------------------------------------" << std::endl;
  prim< int > aristas;
  for( int i = 1; i <= 7; i++ )
  {
    aristas = ejercicio2.Prim( i );
    for( auto& it : aristas.dist )
    {
      Vertice< int > aux =  it.first;
      std::cout << "Vertice: " << aux.getVertice() << " Peso: " << it.second << std::endl;
    }
    for( auto& it : aristas.aristas )
    {
      Vertice< int > auxP =  it.second, auxH =  it.first;
      std::cout << "VerticeP: " << auxP.getVertice() << " VerticeH: " << auxH.getVertice() << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
