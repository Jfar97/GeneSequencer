#ifndef SEQUENCE_FINDER_H
#define SEQUENCE_FINDER_H

#include <string>

#include "lcs_matrix.h"

int geneLCS(std::string& codingSequence, std::string& DNA, LCSMatrix& geneMatrix);
std::string constructLCS(std::string& DNAChunk, LCSMatrix& geneMatrix, int row, size_t col);
void printLCS(std::string& DNASequence, LCSMatrix& geneMatrix);
bool doesCodingSequenceExist(std::string& codingSequence, std::string& calculatedLCS);
void printDNAPercentages(std::string& calculatedLCS);

struct DNAPercentages {
	int totalNucleotides = 0;
	int Adenine = 0;
	int Cytosine = 0;
	int Guanine = 0;
	int Thymine = 0;
};

#endif // SEQUENCE_FINDER_H	