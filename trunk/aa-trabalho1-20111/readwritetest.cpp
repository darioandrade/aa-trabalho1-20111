
#include <stdio.h>

#include "GeraGrafo.h"
#include "DegreeVectorAdjacencyList.h"

#define NVERTEX 10
#define FILENAME_GRAFO "testedegrafo_gerado.grafo"
#define FILENAME_GRAFO_LIDO "testedegrafo_lido.grafo"

int main( int argc, char ** argv )
{
    int debug = 2;

    fprintf( stderr, "Gerando grafo com %d vertices\n", NVERTEX );

    FILE * f = fopen( FILENAME_GRAFO, "w" );

    GeraGrafo( f, NVERTEX, 1, debug );

    fclose( f );

    f = fopen( FILENAME_GRAFO, "r" );

    DegreeVectorAdjacencyList grafo;

    fprintf( stderr, "lendo arquivo do grafo gerado: %s\n", FILENAME_GRAFO );

    grafo.read( f, debug );

    fclose( f );

    f = fopen( FILENAME_GRAFO_LIDO, "w" );

    fprintf( stderr, "escrevendo arquivo do grafo lido: %s\n", FILENAME_GRAFO_LIDO );

    grafo.write( f );

    fclose ( f );

    return 0;
}
