/*
 * cobertura.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include <sys/timeb.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "AlgoritmoCoberturaGulosa.h"
#include "DegreeVectorAdjacencyList.h"
#include "VertexVectorAdjacencyList.h"
#include "DegreeHeapAdjacencyList.h"

#include "GeraGrafo.h"

typedef long unsigned int ltime;

static ltime getMilliCount(){
    timeb tb;
    ftime(&tb);
    time_t nCount = tb.millitm + ( tb.time * 1000 );
    return nCount;
}

void FacaTarefa( AdjacencyList* pGrafo, int debug )
{    
    AdjacencyList& grafo = * pGrafo;

    AlgoritmoCoberturaGulosa guloso;

    std::list< int > listaDaCobertura;

    fprintf( stderr, "Calculando cobertura para o grafo com %d vertices\n", grafo.GetSize( ) );

    guloso.CalculateCobertura( listaDaCobertura, grafo, debug );

    fprintf( stderr, "Cobertura para o grafo (nvertex: %d) tem %d vertices:\n",
             grafo.GetSize( ),
             ( int ) listaDaCobertura.size( ) );

    for ( std::list< int >::iterator it = listaDaCobertura.begin( );
            it != listaDaCobertura.end( );
            it ++ )
    {
        fprintf( stdout, "%d ", * it );
    }

    fprintf( stderr, "\n" );
}

AdjacencyList * EscolhaGrafo( int tarefa )
{
    AdjacencyList * pGrafo = NULL;

    switch ( tarefa )
    {
        case 3:
            pGrafo = new DegreeVectorAdjacencyList();
            break;

        case 4:
            pGrafo = new DegreeHeapAdjacencyList();
            break;

        case 5:
            pGrafo = new VertexVectorAdjacencyList();
            break;
    }

    return pGrafo;
}

int main(int argc, char ** argv)
{
    if ( argc < 2 )
    {
        fprintf( stderr, "Cobertura. Uso: %s (benchmark|(filename ([3|4|5]))) [debug]\n", argv[ 0 ] );
        exit( 1 );
    }

    int debug =  1;

    if ( strcmp( "benchmark", argv[ 1 ] ) == 0 )
    {
        if ( argc > 2 )
        {
            debug = atoi( argv[ 2 ] );
        }

        for ( int algo = 3; algo <= 5; algo++ )
        {
            AdjacencyList * pGrafo = EscolhaGrafo( algo );

            for ( int c = 0; c < NSEQS; c++ )
            {
                for ( int i = 1; i <= NGRAFOS_POR_SEQ; i++ )
                {
                    char path[ 256 ];
                    ltime deltams;

                    sprintf( path, "grafo_p%d_%02d.grafo", c, i );

                    fprintf( stderr, "Lendo grafo %s\n", path );

                    FILE * f = fopen( path , "r" );

                    deltams = getMilliCount();

                    pGrafo->read( f );

                    deltams = getMilliCount() - deltams;

                    fclose( f );

                    fprintf( stderr, "Grafo com %d vertices lido em %lu ms. Calculando cobertura com algoritmo %d\n",
                             pGrafo->GetSize( ),
                             deltams,
                             algo );

                    deltams = getMilliCount();

                    std::list< int > listaDaCobertura;

                    AlgoritmoCoberturaGulosa guloso;

                    guloso.CalculateCobertura( listaDaCobertura, * pGrafo, debug );

                    fprintf( stderr, "Cobertura possui %d vertices, calculada em %lu ms\n",
                             ( int  ) listaDaCobertura.size(),
                             getMilliCount() - deltams );
                } // end for ngrafos por seq
            } // end for seqs

            delete pGrafo;
        } // end for de tarefas
    }
    else
    {
        int tarefa = atoi( argv[ 2 ] );

        if ( argc > 3 )
        {
            debug = atoi( argv[ 3 ] );
        }

        AdjacencyList * pGrafo = EscolhaGrafo( tarefa );

        char * sFilename = argv[ 1 ];

        fprintf( stderr, "Lendo grafo %s:\n",
                 sFilename );

        FILE * f = fopen( sFilename, "r" );

        pGrafo->read( f , debug );

        fclose( f );

        FacaTarefa( pGrafo, debug );

        delete pGrafo;
    }

    return 0;
}

