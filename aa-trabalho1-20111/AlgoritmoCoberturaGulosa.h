/*
 * AlgoritmoCoberturaGulosa.h
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include <list>

#include "AdjacencyList.h"

#ifndef ALGORITMOCOBERTURAGULOSA_H_
#define ALGORITMOCOBERTURAGULOSA_H_

class AlgoritmoCoberturaGulosa
{
public:
    AlgoritmoCoberturaGulosa ( );
    virtual ~AlgoritmoCoberturaGulosa ( );

    void CalculateCobertura(std::list< int > & listCobertura, AdjacencyList& grafo, int debug );

private:
};

#endif /* ALGORITMOCOBERTURAGULOSA_H_ */
