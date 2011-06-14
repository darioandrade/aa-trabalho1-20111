#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "GeraGrafo.h"

void imprimeErro ( char* exename )
{
    printf( "Gerador de grafos. Uso: %s [nvertex tipo(0|1) [debuglevel(0-2)]]\n", exename );
    printf( "Se chamado sem parametros, gera 20 sequencias, 10 de cada tipo.\n" );
    printf( "Tipo 0: p = 0.2\n" );
    printf( "Tipo 1: p = 1 / ( 2 * ( n ^ 0.5 ) )\n" );
}

int main ( int argc, char ** argv )
{
    int debug = 0;
    int nVertex = 0;

    if ( argc < 3 )
    {
        for ( int c = 0; c < NSEQS; c++ )
        {
            for ( int i = 1; i <= NGRAFOS_POR_SEQ; i++ )
            {
                char path[ 256 ];

                sprintf( path, "grafo_p%d_%02d.grafo", c, i );

                FILE * f = fopen( path , "w" );

                int n = 10 * ( ( int ) pow( 2, i ) );

                // gera grafo com debug = 1 (so para dizer o que esta fazendo, nao depurar)
                GeraGrafo( f, n, c, 1 );

                fclose( f );
            }
        }
    }
    else
    {
        nVertex = ( int ) ( atoi( argv[1] ) );

        int type = atoi( argv[2] );
        if ( type > 1 )
        {
            printf( "Tipo invalido.\n\n" );
            imprimeErro( argv[0] );

            exit( 2 );
        }

        if ( nVertex <= 0 || nVertex > 100000 )
        {
            printf( "Numero de vertices invalido (%d).\n\n", nVertex );
            imprimeErro( argv[0] );

            exit( 3 );
        }

        if ( argc > 3 )
        {
            debug = atoi( argv[3] );
        }

        GeraGrafo( stdout, nVertex, type, debug );
    }

    return 1;
}
