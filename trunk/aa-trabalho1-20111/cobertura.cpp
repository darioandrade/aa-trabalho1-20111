/*
 * cobertura.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include <sys/timeb.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "AlgoritmoCoberturaGulosa.h"
#include "DegreeVectorAdjacencyList.h"
#include "VertexVectorAdjacencyList.h"
#include "DegreeHeapAdjacencyList.h"

#include "GeraGrafo.h"

typedef long unsigned int ltime;

static ltime getMilliCount ( )
{
    timeb tb;
    ftime( &tb );
    time_t nCount = tb.millitm + ( tb.time * 1000 );
    return nCount;
}

/*
static ltime getMicroCount ( )
{
    timeval tv;
    timezone tz;
    tm *tm;
    gettimeofday(&tv, &tz);
    return tv.tv_usec;
}
*/

void FacaTarefa ( AdjacencyList* pGrafo, int debug )
{
    AdjacencyList& grafo = *pGrafo;

    AlgoritmoCoberturaGulosa guloso;

    std::list<int> listaDaCobertura;

    if ( debug >= 1 )
    {
        fprintf( stderr, "Calculando cobertura para o grafo com %d vertices\n", grafo.GetSize( ) );
    }

    guloso.CalculateCobertura( listaDaCobertura, grafo, debug );

    if ( debug >= 1 )
    {
        fprintf( stderr, "Cobertura para o grafo (nvertex: %d) tem %d vertices:\n", grafo.GetSize( ),
                ( int ) listaDaCobertura.size( ) );
    }

    for ( std::list<int>::iterator it = listaDaCobertura.begin( ); it != listaDaCobertura.end( ); it++ )
    {
        fprintf( stdout, "%d ", *it );
    }

    fprintf( stdout, "\n" );
}

AdjacencyList * EscolhaGrafo ( int tarefa )
{
    AdjacencyList * pGrafo = NULL;

    switch (tarefa)
    {
        case 3:
            pGrafo = new DegreeVectorAdjacencyList( );
            break;

        case 4:
            pGrafo = new DegreeHeapAdjacencyList( );
            break;

        case 5:
            pGrafo = new VertexVectorAdjacencyList( );
            break;
    }

    return pGrafo;
}

void Benchmark ( int debug )
{
    struct BenchmarkData {
        char sFilename[ 256 ];
        int graphtype;
        ltime loadtime, processingtime;
        int algorithm;
        int nvertex;
        int nedges;
        int ncobertura;
    };

    BenchmarkData results[ 3 ][ NSEQS ][ NGRAFOS_POR_SEQ ];

    for ( int algo = 3; algo <= 5; algo++ )
    {
        AdjacencyList * pGrafo = EscolhaGrafo( algo );

        for ( int c = 0; c < NSEQS; c++ )
        {
            for ( int i = 1; i <= NGRAFOS_POR_SEQ; i++ )
            {
                char path[256];
                ltime deltams;
                BenchmarkData & data = results[ algo - 3 ][ c ][ i - 1 ];

                sprintf( path, "grafo_p%d_%02d.grafo", c, i );

                if ( debug >= 1 )
                {
                    fprintf( stderr, "Lendo grafo %s\n", path );
                }

                data.algorithm = algo;
                data.graphtype = c;
                strcpy( data.sFilename, path );

                FILE * f = fopen( path, "r" );

                deltams = getMilliCount( );

                pGrafo->read( f );

                deltams = getMilliCount( ) - deltams;

                fclose( f );

                if ( debug >= 1 )
                {
                    fprintf( stderr, "Grafo com %d vertices lido em %lu ms. Calculando cobertura com algoritmo %d\n",
                            pGrafo->GetSize( ), deltams, algo );
                }

                data.loadtime = deltams;
                data.nvertex = pGrafo->GetSize( );
                data.nedges = pGrafo->GetEdges( );

                deltams = getMilliCount( );

                std::list<int> listaDaCobertura;

                AlgoritmoCoberturaGulosa guloso;

                guloso.CalculateCobertura( listaDaCobertura, *pGrafo, debug );

                deltams = getMilliCount( ) - deltams;

                if ( debug >= 1 )
                {
                    fprintf( stderr, "Cobertura possui %d vertices, calculada em %lu ms\n",
                            ( int ) listaDaCobertura.size( ), deltams );
                }

                data.ncobertura = listaDaCobertura.size();
                data.processingtime = deltams;

                fprintf( stdout, "%d,%d,%s,%d,%d,%d,%lu,%lu\n",
                         data.algorithm,
                         data.graphtype,
                         data.sFilename,
                         data.nvertex,
                         data.nedges,
                         data.ncobertura,
                         data.loadtime,
                         data.processingtime );

                fflush( stdout );
            } // end for ngrafos por seq
        } // end for seqs

        delete pGrafo;
    } // end for algos
}

int main ( int argc, char ** argv )
{
    if ( argc < 2 )
    {
        fprintf( stderr, "Cobertura. Uso: %s (benchmark|(filename ([3|4|5]))) [debug]\n", argv[0] );
        exit( 1 );
    }

    int debug = 1;

    if ( strcmp( "benchmark", argv[1] ) == 0 )
    {
        if ( argc > 2 )
        {
            debug = atoi( argv[2] );
        }

        Benchmark( debug );
    }
    else
    {
        int tarefa = atoi( argv[2] );
        if ( argc > 3 )
        {
            debug = atoi( argv[3] );
        }

        AdjacencyList * pGrafo = EscolhaGrafo( tarefa );

        char * sFilename = argv[1];

        if ( debug >= 1 )
        {
            fprintf( stderr, "Lendo grafo %s:\n", sFilename );
        }

        FILE * f = fopen( sFilename, "r" );
        pGrafo->read( f, debug );

        fclose( f );

        FacaTarefa( pGrafo, debug );

        delete pGrafo;
    }

    return 0;
}

