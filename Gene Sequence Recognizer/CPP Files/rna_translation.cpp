#include "rna_translation.h"

#include <iostream>

int getAAFromCodon(std::string codon) {
	if (codon.length() != 3) {
		return -1;
	}

	char firstCodonNucleotide = codon[0];
	char secondCodonNucleotide = codon[1];
	char thirdCodonNucleotide = codon[2];

	switch (firstCodonNucleotide) {		// FIRST CODON NUCLEOTIDE
	case 'A':								// First Codon Nucleotide is 'A' (Adenine)			- A__
		switch (secondCodonNucleotide) {	// SECOND CODON NUCLEOTIDE
		case 'A':								// Second Codon Nucleotide is 'A' (Adenine)		- AA_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- AAA	- Lys
				return LYSINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- AAC	- Asn
				return ASPARAGINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- AAG	- Lys
				return LYSINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- AAU	- Asn
				return ASPARAGINE;
			}
		case 'C':								// Second Codon Nucleotide is 'C' (Cytosine)	- AC_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- ACA	- Thr
				return THREONINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- ACC	- Thr
				return THREONINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- ACG	- Thr
				return THREONINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- ACU	- Thr
				return THREONINE;
			}
		case 'G':								// Second Codon Nucleotide is 'G' (Guanine)		- AG_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- AGA	- Arg
				return ARGININE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- AGC	- Ser
				return SERINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- AGG	- Arg
				return ARGININE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- AGU	- Ser
				return SERINE;
			}
		case 'U':								// Second Codon Nucleotide is 'U' (Uracil)		- AU_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- AUA	- Ile
				return ISOLEUCINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- AUC	- Ile
				return ISOLEUCINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- AUG	- Met	// START CODON
				return METHIONINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- AUU	- Ile
				return ISOLEUCINE;
			}								// -----------------------------------------------------------------------
		}
	case 'C':								// First Codon Nucleotide is 'C' (Cytosine)			- C__ 
		switch (secondCodonNucleotide) {	// SECOND CODON NUCLEOTIDE
		case 'A':								// Second Codon Nucleotide is 'A' (Adenine)		- CA_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- CAA	- Gln
				return GLUTAMINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- CAC	- His
				return HISTIDINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- CAG	- Gln
				return GLUTAMINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- CAU	- His
				return HISTIDINE;
			}
		case 'C':								// Second Codon Nucleotide is 'C' (Cytosine)	- CC_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- CCA	- Pro
				return PROLINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- CCC	- Pro
				return PROLINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- CCG	- Pro
				return PROLINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- CCU	- Pro
				return PROLINE;
			}
		case 'G':								// Second Codon Nucleotide is 'G' (Guanine)		- CG_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- CGA	- Arg
				return ARGININE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- CGC	- Arg
				return ARGININE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- CGG	- Arg
				return ARGININE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- CGU	- Arg
				return ARGININE;
			}
		case 'U':								// Second Codon Nucleotide is 'U' (Uracil)		- CU_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- CUA	- Leu
				return LEUCINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- CUC	- Leu
				return LEUCINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- CUG	- Leu
				return LEUCINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- CUU	- Leu
				return LEUCINE;
			}								// -----------------------------------------------------------------------
		}								
	case 'G':								// First Codon Nucleotide is 'G' (Guanine)			- G__
		switch (secondCodonNucleotide) {	// SECOND CODON NUCLEOTIDE
		case 'A':								// Second Codon Nucleotide is 'A' (Adenine)		- GA_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- GAA	- Glu
				return GLUTAMIC_ACID;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- GAC	- Asp
				return ASPARTIC_ACID;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- GAG	- Glu
				return GLUTAMIC_ACID;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- GAU	- Asp
				return ASPARTIC_ACID;
			}
		case 'C':								// Second Codon Nucleotide is 'C' (Cytosine)	- GC_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- GCA	- Ala
				return ALANINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- GCC	- Ala
				return ALANINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- GCG	- Ala
				return ALANINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- GCU	- Ala
				return ALANINE;
			}
		case 'G':								// Second Codon Nucleotide is 'G' (Guanine)		- GG_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- GGA	- Gly
				return GLYCINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- GGC	- Gly
				return GLYCINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- GGG	- Gly
				return GLYCINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- GGU	- Gly
				return GLYCINE;
			}
		case 'U':								// Second Codon Nucleotide is 'U' (Uracil)		- GU_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- GUA	- Val
				return VALINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- GUC	- Val
				return VALINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- GUG	- Val
				return VALINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- GUU	- Val
				return VALINE;
			}								// -----------------------------------------------------------------------
		}
	case 'U':								// First Codon Nucleotide is 'U' (Uracil)			- U__
		switch (secondCodonNucleotide) {	// SECOND CODON NUCLEOTIDE
		case 'A':								// Second Codon Nucleotide is 'A' (Adenine)		- UA_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- UAA	- STOP	// STOP CODON
				return STOP;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- UAC	- Tyr
				return TYROSINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- UAG	- STOP	// STOP CODON
				return STOP;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- UAU	- Tyr
				return TYROSINE;
			}
		case 'C':								// Second Codon Nucleotide is 'C' (Cytosine)	- UC_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- UCA	- Ser
				return SERINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- UCC	- Ser
				return SERINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- UCG	- Ser
				return SERINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- UCU	- Ser
				return SERINE;
			}
		case 'G':								// Second Codon Nucleotide is 'G' (Guanine)		- UG_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- UGA	- STOP	// STOP CODON
				return STOP;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- UGC	- Cys
				return CYSTEINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- UGG	- Trp
				return TRYPTOPHAN;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- UGU	- Cys
				return CYSTEINE;
			}
		case 'U':								// Second Codon Nucleotide is 'U' (Uracil)		- UU_
			switch (thirdCodonNucleotide) {		// THIRD CODON NUCLEOTIDE
			case 'A':								// Third Codon Nucleotidie is 'A' (Adenine)		- UUA	- Leu	
				return LEUCINE;
			case 'C':								// Third Codon Nucleotidie is 'C' (Cytosine)	- UUC	- Phe
				return PHENYLALANINE;
			case 'G':								// Third Codon Nucleotidie is 'G' (Guanine)		- UUG	- Leu
				return LEUCINE;
			case 'U':								// Third Codon Nucleotidie is 'U' (Uracil)		- UUU	- Phe
				return PHENYLALANINE;
			}
		}
	}
}


std::vector<aminoAcid> getAminoAcidSequence(std::string& mRNA) {
	// Vector stores the amino acids making up the protein
	std::vector<aminoAcid> proteinSequence;

	// Check to ensure that the mRNA that has been provided is divisible by 3 - codons use 3 nucleotides, so valid mRNA sequences must be divisible by 3 (%3 == 0)
	if (mRNA.length() % 3 != 0) {
		return proteinSequence;
	}

	// Stores the codon result as an int tied to amino acid enum amino_acids.h
	int codonResult = 0;

	// Position in mRNA sequence to get next codon
	int nextCodonPos = 0;

	// String to store the next codon that needs to be translated
	std::string nextCodon;

	// Get instance of Amino Acid Table to build the amino acid sequence
	AminoAcidTable AATable;

	while (1) {
		// Get the next codon
		nextCodon = mRNA.substr(nextCodonPos, 3);

		// Get the codong result 
		codonResult = getAAFromCodon(nextCodon);

		// Add new amino acid to the protein chain
		if (codonResult < 20) {
			aminoAcid nextAA = AATable.getAminoAcid(codonResult);
			proteinSequence.push_back(nextAA);
		}
		// Stop codon reached
		else {
			return proteinSequence;
		}

		// Next codon pos will be three nucleotides away
		nextCodonPos += 3; 
	}
}


std::string getAminoAcidNameSequence(std::string& mRNA) {
	// Check to ensure that the mRNA that has been provided is divisible by 3 - codons use 3 nucleotides, so valid mRNA sequences must be divisible by 3 (%3 == 0)
	if (mRNA.length() % 3 != 0) {
		return "";
	}
	
	// Stores the codon result as an int tied to amino acid enum amino_acids.h
	int codonResult = 0;

	// Position in mRNA sequence to get next codon
	int nextCodonPos = 0;

	// String to store the next codon that needs to be translated
	std::string nextCodon;

	// Get instance of Amino Acid Table to build the amino acid sequence
	AminoAcidTable AATable;
	
	// Stores the protein sequence name 
	std::string proteinSequence;

	while (1) {
		// Get the next codon
		nextCodon = mRNA.substr(nextCodonPos, 3);

		// Get the codong result 
		codonResult = getAAFromCodon(nextCodon);

		// Add new amino acid to the protein chain
		if (codonResult < 20) {
			std::string nextAA = AATable.getAminoAcidName(codonResult) + "--";
			proteinSequence += nextAA;
		}
		// Stop codon reached
		else {
			return proteinSequence;
		}

		// Next codon pos will be three nucleotides away
		nextCodonPos += 3;
	}
}


std::string getAminoAcidAbbreviationSequence(std::string& mRNA) {
	// Check to ensure that the mRNA that has been provided is divisible by 3 - codons use 3 nucleotides, so valid mRNA sequences must be divisible by 3 (%3 == 0)
	if (mRNA.length() % 3 != 0) {
		return "";
	}

	// Stores the codon result as an int tied to amino acid enum amino_acids.h
	int codonResult = 0;

	// Position in mRNA sequence to get next codon
	int nextCodonPos = 0;

	// String to store the next codon that needs to be translated
	std::string nextCodon;

	// Get instance of Amino Acid Table to build the amino acid sequence
	AminoAcidTable AATable;

	// Stores the protein sequence name 
	std::string proteinSequence;

	while (1) {
		// Get the next codon
		nextCodon = mRNA.substr(nextCodonPos, 3);

		// Get the codong result 
		codonResult = getAAFromCodon(nextCodon);

		// Add new amino acid to the protein chain
		if (codonResult < 20) {
			std::string nextAA = AATable.getAminoAcidAbbreviation(codonResult) + "--";
			proteinSequence += nextAA;
		}
		// Stop codon reached
		else {
			return proteinSequence;
		}

		// Next codon pos will be three nucleotides away
		nextCodonPos += 3;
	}
}


std::string getAminoAcidLetterSequence(std::string& mRNA) {
	// Check to ensure that the mRNA that has been provided is divisible by 3 - codons use 3 nucleotides, so valid mRNA sequences must be divisible by 3 (%3 == 0)
	if (mRNA.length() % 3 != 0) {
		return "";
	}

	// Stores the codon result as an int tied to amino acid enum amino_acids.h
	int codonResult = 0;

	// Position in mRNA sequence to get next codon
	int nextCodonPos = 0;

	// String to store the next codon that needs to be translated
	std::string nextCodon;

	// Get instance of Amino Acid Table to build the amino acid sequence
	AminoAcidTable AATable;

	// Stores the protein sequence name 
	std::string proteinSequence;

	while (1) {
		// Get the next codon
		nextCodon = mRNA.substr(nextCodonPos, 3);

		// Get the codong result 
		codonResult = getAAFromCodon(nextCodon);

		// Add new amino acid to the protein chain
		if (codonResult < 20) {
			std::string nextAA = AATable.getAminoAcidLetter(codonResult) + "--";
			proteinSequence += nextAA;
		}
		// Stop codon reached
		else {
			return proteinSequence;
		}

		// Next codon pos will be three nucleotides away
		nextCodonPos += 3;
	}
}


void printMessRNAPercentages(std::string& mRNA) {
	mRNAPercentages tracker;

	for (int i = 0; i < mRNA.length(); i++) {
		char nucleotide = mRNA[i];
		switch (nucleotide) {
		case 'A':
			tracker.totalNucleotides++;
			tracker.Adenine++;
			break;
		case 'C':
			tracker.totalNucleotides++;
			tracker.Cytosine++;
			break;
		case 'G':
			tracker.totalNucleotides++;
			tracker.Guanine++;
			break;
		case 'U':
			tracker.totalNucleotides++;
			tracker.Uracil++;
			break;
		default:
			std::cout << "An invalid character for a RNA nucleotide was encountered - please validate your file inputs";
			return;
		}

	}

	std::cout << "The percentage of Adenine is " << (tracker.Adenine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Cytosine is " << (tracker.Cytosine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Guanine is " << (tracker.Guanine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Uracil is " << (tracker.Uracil / tracker.totalNucleotides) * 100 << "%\n";
}