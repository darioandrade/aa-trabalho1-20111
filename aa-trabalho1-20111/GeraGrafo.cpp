/*
 * GeraGrafo.cpp
 *
 *  Created on: May 28, 2011
 *      Author: darioandrade
 */

#include <stdlib.h>
#include <math.h>
#include <ctime>

#include "AdjacencyList.h"

#define P_TIPO_0 0.2

double randd ( )
{
    return ( ( double ) rand( ) ) / RAND_MAX;
}

void GeraGrafo ( FILE* f, int nVertex, int type, int debug )
{
    // alimentando a semente randomica
    srand( time( NULL ) );

    // calculando p
    double p = ( type == 0 ) ? P_TIPO_0 : ( 1.0 / ( 2.0 * sqrt( nVertex ) ) );

    if ( debug > 0 )
    {
        fprintf( stderr,
                "Gerando %d vertices de grafo nao direcionado tipo %d (p = %.7f)\n",
                nVertex, type, p );
    }

    // criando o grafo
    AdjacencyList graph( nVertex );

    // percorrendo do primeiro vertice ate o penultimo (zero based list)
    for ( int i = 0; i < nVertex - 1; i++ )
    {
        if ( debug > 1 )
        {
            fprintf( stderr, "  vertice %d: ", i );
        }

        for ( int j = i + 1; j < nVertex; j++ )
        {
            double x = randd( );

            if ( debug > 1 )
            {
                fprintf( stderr, " %.4f", x );
            }

            // should we cast an edge to j?
            if ( x < p )
            {
                if ( debug > 1 )
                {
                    fprintf( stderr, "Y" );
                }

                graph.addEdge( i, j );
            }
            else
            {
                if ( debug > 1 )
                {
                    fprintf( stderr, " " );
                }
            }
        }

        if ( debug > 1 )
        {
            fprintf( stderr, "\n" );
        }
    }

    graph.write( f );
}
