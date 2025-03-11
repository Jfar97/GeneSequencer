#include "sequence_finder.h"
#include <iostream>

// Use the LCS algorithm to create function to find the desired gene input inside a large set of nucleotides
int geneLCS(std::string& codingSequence, std::string& DNA, LCSMatrix& geneMatrix)
{
	// Store string sizes for looping through lcs matrix
	int csLength = codingSequence.length();
	size_t dnaLength = DNA.length();

	//std::cout << "DEBUG: Input lengths - Coding sequence: " << csLength << ", DNA: " << dnaLength << std::endl;

	// If the coding sequence being searched for does not match the length of the previous matrix coding sequence, update the matrix using resize call
	if (codingSequence.length() != geneMatrix.getCodingSeqLength()) {
		geneMatrix.resizeMatrix(codingSequence.length());
	}

	// Loop over strings to calculate LCS in the matrix
	for (int i = 1; i <= csLength; i++) {
		for (size_t j = 1; j <= dnaLength; j++) {
			// Match found
			if (codingSequence[i-1] == DNA[j-1]) {
				//std::cout << "DEBUG: Match found at i=" << i << ", j=" << j
					//<< " (" << codingSequence[i-1] << " = " << DNA[j-1] << ")" << std::endl;
				geneMatrix.lcsMatrix[i][j].cellValue = geneMatrix.lcsMatrix[i - 1][j - 1].cellValue + 1;
				geneMatrix.lcsMatrix[i][j].arrowDirection = "NORTHWEST";
			}
			// No match - maximum is cell above
			else if (geneMatrix.lcsMatrix[i - 1][j].cellValue >= geneMatrix.lcsMatrix[i][j - 1].cellValue) {
				geneMatrix.lcsMatrix[i][j].cellValue = geneMatrix.lcsMatrix[i - 1][j].cellValue;
				geneMatrix.lcsMatrix[i][j].arrowDirection = "NORTH";
			}
			// No Match - maximum is cell to the left
			else {
				geneMatrix.lcsMatrix[i][j].cellValue = geneMatrix.lcsMatrix[i][j - 1].cellValue;
				geneMatrix.lcsMatrix[i][j].arrowDirection = "WEST";
			}
		}
	}

	//std::cout << "DEBUG: Final LCS length: " << geneMatrix.getFinalLCSLength() << std::endl;
	return geneMatrix.getFinalLCSLength();
}


// Uses the lcs matrix in order to construct the calculated LCS from the section of DNA
// This ensures that the calculated LCS is found from the section of DNA, and not from the "correct" coding sequence, which allows the constructed LCS to be compared to the "correct" coding sequence to validate if the coding sequence exists in the DNA chunk
std::string constructLCS(std::string& DNAChunk, LCSMatrix& geneMatrix, int row, size_t col) {
	//std::cout << "DEBUG: constructLCS called with row=" << row << ", col=" << col << std::endl;

	// End of LCS
	if (row < 0 || col < 0) {
		//std::cout << "DEBUG: Base case hit, returning empty string" << std::endl;
		return "";
	}

	if (geneMatrix.lcsMatrix[row][col].arrowDirection == "") {
		//std::cout << "DEBUG: Arrow is empty so base case hit, returning empty string\n";
		return "";
	}

	//std::cout << "DEBUG: Current arrow direction: " << geneMatrix.lcsMatrix[row][col].arrowDirection << std::endl;

	// Character of LCS found
	// Recursive call = move up and left
	if (geneMatrix.lcsMatrix[row][col].arrowDirection == "NORTHWEST") {
		//std::cout << "DEBUG: NORTHWEST - adding character: " << DNAChunk[col] << std::endl;
		return constructLCS(DNAChunk, geneMatrix, row - 1, col - 1) + DNAChunk[col - 1];
	}
	// Recursive call = move up
	else if (geneMatrix.lcsMatrix[row][col].arrowDirection == "NORTH") {
		//std::cout << "DEBUG: Going NORTH" << std::endl;
		return constructLCS(DNAChunk, geneMatrix, row - 1, col);
	}
	// Recursive call = move left
	else {
		//std::cout << "DEBUG: Going WEST" << std::endl;
		return constructLCS(DNAChunk, geneMatrix,row, col - 1);
	}

	// Default return statement
	return "";
}


// Prints the calculated LCS by iterating over the constructed LCS
void printLCS(std::string& DNASequence, LCSMatrix& geneMatrix) {
	//std::cout << "DEBUG: printLCS called" << std::endl;

	if (geneMatrix.getFinalMatrixCellArrow() == "") {
		std::cout << "The genetic LCS has not been calculated yet";
	}
	else {
		//std::cout << "DEBUG: Matrix dimensions - Rows: " << geneMatrix.getCodingSeqLength() + 1
			//<< ", Cols: " << geneMatrix.getFullDNALength() + 1 << std::endl;

		// Empty string that will store calculated LCS
		std::string LCS = "";

		// Max row and col values of the lcs matrix
		int maxRow = geneMatrix.getCodingSeqLength();
		size_t maxCol = geneMatrix.getFullDNALength();

		//std::cout << "DEBUG: Starting constructLCS with maxRow=" << maxRow << ", maxCol=" << maxCol << std::endl;

		// Construct the LCS from the matrix
		LCS = constructLCS(DNASequence, geneMatrix, maxRow, maxCol);

		//std::cout << "DEBUG: Constructed LCS length: " << LCS.length() << std::endl;
		std::cout << "The LCS of the coding sequence and the section of DNA is " << LCS << std::endl;
	}
}


bool doesCodingSequenceExist(std::string& codingSequence, std::string& calculatedLCS) {
	// First check if the LCS matches the coding sequence in length
	if (calculatedLCS.length() == codingSequence.length())
	{
		// If they match in size, validate that the LCS matches the coding sequence charcter by character
		// Big Omega (n) 
		for (int i = 0; i < codingSequence.length(); i++) {
			// Calculated LCS and coding sequence input do not match
			if (calculatedLCS[i] != codingSequence[i]) {
				return false;
			}
		}

		// Length is the same
		// Loop has validated the characters of the LCS and the coding sequence are the same
		return true;
	}

	// Default case is false if the lengths do not match
	return false;
}



void printDNAPercentages(std::string& calculatedLCS) {
	DNAPercentages tracker;

	for (int i = 0; i < calculatedLCS.length(); i++) {
		char nucleotide = calculatedLCS[i];
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
		case 'T':
			tracker.totalNucleotides++;
			tracker.Thymine++;
			break;
		default:
			std::cout << "An invalid character for a DNA nucleotide was encountered - please validate your file inputs";
			return;
		}

	}

	std::cout << "The percentage of Adenine is " << (tracker.Adenine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Cytosine is " << (tracker.Cytosine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Guanine is " << (tracker.Guanine / tracker.totalNucleotides) * 100 << "%\n";
	std::cout << "The percentage of Thymine is " << (tracker.Thymine / tracker.totalNucleotides) * 100 << "%\n";
}