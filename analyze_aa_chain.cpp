#include "analyze_aa_chain.h"

#include <iostream>

void printAAByLine(std::vector<aminoAcid>& protein) {
	for (int i = 0; i < protein.size(); i++) {
		std::cout << i + 1 << ") " << protein[i].name << " - " << protein[i].letter << std::endl;
	}
}


double getProteinWeight(std::vector<aminoAcid>& protein) {
	// protein weight in Daltons (Da)
	double molWeight = 0.0;

	for (int i = 0; i < protein.size(); i++) {
		molWeight += protein[i].molecularWeight;
	}

	return molWeight;
}


void getAAPercentages(std::vector<aminoAcid>& protein) {
	int totalNumAA = protein.size();
	int aaList[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	AminoAcidTable aaTable;

	for (int i = 0; i < protein.size(); i++) {
		char currentAminoAcid = protein[i].letter[0];

		switch (currentAminoAcid) {
		case 'A':	// 1 - ALANINE
			aaList[0]++;
			break;
		case 'R':	// 2 - ARGININE
			aaList[1]++;
			break;
		case 'N':	// 3 - ASPARAGINE
			aaList[2]++;
			break;
		case 'D':	// 4 - ASPARTIC ACID
			aaList[3]++;
			break;
		case 'C':	// 5 - CYSTEINE
			aaList[4]++;
			break;
		case 'E':	// 6 - GLUTAMIC ACID
			aaList[5]++;
			break;
		case 'Q':	// 7 - GLUTAMINE
			aaList[6]++;
			break;
		case 'G':	// 8 - GLYCINE
			aaList[7]++;
			break;
		case 'H':	// 9  - HISTIDINE
			aaList[8]++;
			break;
		case 'I':	// 10 - ISOLEUCINE
			aaList[9]++;
			break;
		case 'L':	// 11 - LEUCINE
			aaList[10]++;
			break;
		case 'K':	// 12 - LYSINE
			aaList[11]++;
			break;
		case 'M':	// 13 - METHIONINE
			aaList[12]++;
			break;
		case 'F':	// 14 - PHENYLALANINE
			aaList[13]++;
			break;
		case 'P':	// 15 - PROLINE
			aaList[14]++;
			break;
		case 'S':	// 16 - SERINE
			aaList[15]++;
			break;
		case 'T':	// 17 - THREONINE
			aaList[16]++;
			break;
		case 'W':	// 18 - TRYPTOPHAN
			aaList[17]++;
			break;
		case 'Y':	// 19 - TYROSINE
			aaList[18]++;
			break;
		case 'V':	// 20 - VALINE
			aaList[19]++;
			break;
		}

	}

	// Print out percentages
	std::cout << "The amino acid composition of this protein is:\n";
	for (int i = 0; i < 20; i++) {
		std::cout << aaTable.getAminoAcidName(i) << ": " << (aaList[i] / totalNumAA) * 100 << "%\n";
	}

}