#ifndef GENE_TRANSCRIPTION_H
#define GENE_TRANSCRIPTION_H

#include <string>

char getRNANucleotide(char DNAnucleotide);
bool validateDNA(std::string& DNAChunk);
std::string buildMessengerRNA(std::string& DNAChunk);
int validateMessRNA(std::string& mRNA);

enum mRNAErrorType {
	INVALID_LENGTH = 1,
	NO_START_CODON = 2,
	NO_STOP_CODON = 3
};
#endif // GENE_TRANSCRIPTION_H