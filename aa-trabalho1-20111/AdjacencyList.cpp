/*
 * AdjacencyList.cpp
 *
 *  Created on: May 28, 2011
 *      Author: darioandrade
 */

#include "AdjacencyList.h"

#define MAX_LINE_SIZE ( 64 * 1024 )

AdjacencyList::AdjacencyList ( int nVertex )
{
    m_nVertex = nVertex;

    m_arrAdjLists = new std::list< int >[ nVertex ];
}

AdjacencyList::~AdjacencyList ( )
{
    delete [ ] m_arrAdjLists;
}

void AdjacencyList::addEdge ( int iVertex, int jVertex )
{
    m_arrAdjLists[ iVertex ].push_back( jVertex );
    m_arrAdjLists[ jVertex ].push_back( iVertex );
}

// print edges, one vertex each line, to stdout
void AdjacencyList::write ( FILE * f )
{
    if ( f == NULL )
    {
        f = stdout;
    }

    // run all vertex
    for ( int i = 0; i < m_nVertex; i++ )
    {
        // iterate through edges
        for ( std::list<int>::iterator it = m_arrAdjLists[ i ].begin( ); it != m_arrAdjLists[ i ].end( ); it++ )
        {
            fprintf( f, "%d ", *it );
        }

        fputs( "\n", f );
    }
}

void AdjacencyList::read( FILE * f, int debug )
{
    if ( f == NULL )
    {
        f = stdin;
    }

    static char sLine[ MAX_LINE_SIZE ];

    // read all lines
    for ( int nCurrentVertex = 0;
            fgets( sLine, MAX_LINE_SIZE, f ) != NULL;
            nCurrentVertex++ )
    {
        if ( debug >= 2 )
        {
            fprintf( stderr, "  lendo linha do vertice %d\n", nCurrentVertex );
        }

        m_nVertex ++;

        int offset = 0;

        // read all neighbors from the line
        for ( int i = 0; i < MAX_LINE_SIZE; i++ )
        {
            int nNeighborVertex;

            // only read if offset is within array boundaries
            if ( offset < MAX_LINE_SIZE )
            {
                // read neighbor
                int ret = sscanf( sLine + offset, " %d", &nNeighborVertex );

                // did we read a neighbor? or end of line/file?
                if ( ret != EOF && ret > 0 )
                {
                    if ( debug >= 2 )
                    {
                        fprintf( stderr, " %d ", nNeighborVertex );
                    }

                    addEdge( nCurrentVertex, nNeighborVertex );

                    // find next item in line
                    while ( offset < MAX_LINE_SIZE
                            && sLine[ offset ]
                            && sLine[ offset ] != ' ' )
                    {
                        offset ++;
                    }
                }
                else
                {
                    // stop reading the line
                    break;
                }
            }
        }
    }

    if ( debug >= 2 )
    {
        fprintf( stderr, "\n fim do stream de leitura\n" );
    }

}
