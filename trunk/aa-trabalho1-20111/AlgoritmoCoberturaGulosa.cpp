/*
 * AlgoritmoCoberturaGulosa.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include "AlgoritmoCoberturaGulosa.h"

AlgoritmoCoberturaGulosa::AlgoritmoCoberturaGulosa ( )
{


}

AlgoritmoCoberturaGulosa::~AlgoritmoCoberturaGulosa ( )
{

}

void AlgoritmoCoberturaGulosa::CalculateCobertura(std::list< int > & listCobertura, AdjacencyList & grafo, int debug )
{

    while ( grafo.HasEdge( ) )
    {
        if ( debug >= 2 )
        {
            fprintf( stderr, "removendo vertice de maior grau e atualizando vizinhos\n" );
        }

        int vertex = grafo.RemoveHighestDegreeVertex( debug );

        if ( debug >= 2 )
        {
            fprintf( stderr, "vertice de maior grau: %d\n", vertex );
        }

        listCobertura.push_back( vertex );
    }
}
