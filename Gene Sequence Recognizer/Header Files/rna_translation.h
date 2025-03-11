#ifndef RNA_TRANSLATION_H
#define RNA_TRANSLATION_H

#include <string>

#include "amino_acids.h"

int getAAFromCodon(std::string codon);
std::vector<aminoAcid> getAminoAcidSequence(std::string& mRNA);
std::string getAminoAcidNameSequence(std::string& mRNA);
std::string getAminoAcidAbbreviationSequence(std::string& mRNA);
std::string getAminoAcidLetterSequence(std::string& mRNA);
void printMessRNAPercentages(std::string& mRNA);


struct mRNAPercentages {
	int totalNucleotides = 0;
	int Adenine = 0;
	int Cytosine = 0;
	int Guanine = 0;
	int Uracil = 0;
};


#endif // RNA_TRANSLATION_H