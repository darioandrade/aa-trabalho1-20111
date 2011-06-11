/*
 * cobertura.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include <stdio.h>

#include "AlgoritmoCoberturaGulosa.h"
#include "DegreeVectorAdjacencyList.h"

void Tarefa_3( char sFilename[ ], int debug )
{
    DegreeVectorAdjacencyList grafo3;

    fprintf( stderr, "Lendo grafo %s:\n",
             sFilename );

    FILE * f = fopen( sFilename, "r" );

    grafo3.read( f , debug );

    fclose( f );

    AlgoritmoCoberturaGulosa guloso;

    std::list< int > listaDaCobertura;

    fprintf( stderr, "Calculando cobertura para o grafo com %d vertices\n", grafo3.GetSize( ) );

    guloso.CalculateCobertura( listaDaCobertura, grafo3, debug );

    fprintf( stderr, "Cobertura para o grafo (nvertex: %d) tem %d vertices:\n",
             grafo3.GetSize( ),
             ( int ) listaDaCobertura.size( ) );

    for ( std::list< int >::iterator it = listaDaCobertura.begin( );
            it != listaDaCobertura.end( );
            it ++ )
    {
        fprintf( stdout, "%d ", * it );
    }

    fprintf( stderr, "\n" );
}

int main(int argc, char ** argv)
{
    if ( argc <= 2 )
    {
        fprintf( stderr, "Cobertura. Uso: %s filename ([3|4|5]) [debug]\n", argv[ 0 ] );
        exit( 1 );
    }

    int tarefa = atoi( argv[ 2 ] );

    int debug = argc > 3 ? atoi( argv[ 3 ] ) : 1;

    switch ( tarefa )
    {
        case 3:
            Tarefa_3( argv[ 1 ], debug );
            break;
    }

    return 0;
}

