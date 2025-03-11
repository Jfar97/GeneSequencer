#include "gene_transcription.h"
#include <iostream>


// Validates a nucletide character passed in
// O(1)
char getRNANucleotide(char DNAnucleotide) {
	switch (DNAnucleotide) {
	case 'A':			// RNA Uracil binds to DNA Adenine - (RNA does not use Thymine)
		return 'U';
	case 'C':			// RNA Guanine binds to DNA Cytosine
		return 'G';
	case 'G':			// RNA Cytosine binds to DNA Guanine
		return 'C';
	case 'T':			// RNA Adenine binds to DNA Thymine
		return 'A';
	default:			// Returns 'X' if an invalid DNA nucleotide is attempted to be transcribed
		return 'X';
	}
}


// Validates the entire string of length n to verify that it is a valid chunk of DNA nucleotides
// O(n)
bool validateDNA(std::string& DNAChunk) {
	int segmentSize = DNAChunk.length();
	char nucleotide;

	for (int i = 0; i < segmentSize; i++) {
		nucleotide = DNAChunk[i];
		if (getRNANucleotide(nucleotide) == 'X') {
			return false;
		}
	}

	return true;
}

// Builds thes DNA sequence or returns ERROR if the DNA sequence is invalid
// O(n)
std::string buildMessengerRNA(std::string& DNAChunk) {
	std::string mRNA = "";
	int segmentSize = DNAChunk.length();
	char nucleotide;
	
	for (int i = 0; i < segmentSize; i++) {
		nucleotide = DNAChunk[i];
		// Ensure INVALID nucleotides are caught	-	can not guarantee users will validate sequences beforehand
		if (getRNANucleotide(nucleotide) == 'X') {
			return "ERROR";
		}
		// Build mRNA from nucleotides
		else {
			mRNA += getRNANucleotide(nucleotide);
		}
	}

	return mRNA;
}

int validateMessRNA(std::string& mRNA) {

	// Validate mRNA length
	if (mRNA.length()%3 != 0) {
		return INVALID_LENGTH;									// 1
	}
	


	// Get the first codon of the mRNA sequence
	std::string firstCodon = mRNA.substr(0, 3);

	// Validate it begins with a start codon
	if (firstCodon != "AUG") {
		return NO_START_CODON;									// 2
	}



	// Get the last codon of the mRNA sequence
	std::string lastCodon = mRNA.substr(mRNA.length() - 3);
	//std::cout << lastCodon << std::endl;

	// Validate the last codon is a stop coddon (ends with a stop codon)
	if (lastCodon != "UAA"
		&& lastCodon != "UAG"
		&& lastCodon != "UGA"
		) {
		return NO_STOP_CODON;									// 3
	}


	// mRNA has passed all conditions and is valid
	return 0;
}




