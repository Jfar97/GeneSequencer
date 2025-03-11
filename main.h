#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <iomanip>
#include <string>

#include "sequence_finder.h"
#include "util.h"
#include "gene_transcription.h"
#include "rna_translation.h"
#include "analyze_aa_chain.h"


void handleInstructions(std::string& codingSequence, std::string& DNA, LCSMatrix& geneMatrix);

#endif // MAIN_H