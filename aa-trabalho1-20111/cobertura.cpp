/*
 * cobertura.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include <stdio.h>

#include "AlgoritmoCoberturaGulosa.h"
#include "DegreeVectorAdjacencyList.h"

void Tarefa_3( int debug )
{
    DegreeVectorAdjacencyList grafo3;

    fprintf( stderr, "Lendo grafo %s:\n",
             "grafo_p1_01.grafo" );

    FILE * f = fopen( "grafo_p1_10.grafo", "r" );

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
    if ( argc <= 1 )
    {
        fprintf( stderr, "Cobertura. Uso: %s [3|4|5]\n", argv[ 0 ] );
        exit( 1 );
    }

    int tarefa = atoi( argv[ 1 ] );

    switch ( tarefa )
    {
        case 3:
            Tarefa_3( 1 );
            break;
    }

    return 0;
}

