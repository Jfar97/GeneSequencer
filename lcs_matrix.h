#ifndef LCS_MATRIX_H
#define LCS_MATRIX_H

#include <vector>
#include <string>
#include <iostream>

// A struct used for the LCS matrix that allows the vector to store the calculated LCS value as an int and the arrow direction of the LCS as a string
struct matrixCell {
	// cellValue represents the current length of the LCS at that matrix cell within the LCS matrix
	int cellValue = 0;

	// arrowDirection represents the arrow direction pointing towards the next relelvant matrix cell that should be visited when following the LCS
	std::string arrowDirection = "";	// "" means no arrow in the cell
};


class LCSMatrix {
private:
	// Coding sequence size is stored as int, as int variable size can store all known nucleotide coding sequences
	int codingSeqSize;

	// DNA chunk being searched has size stored as size_t to ensure that extraordinarily large chunks of DNA being searched can be inputted
	size_t DNAChunkSize;

public:
	// 2D array is used to represent the LCS matrix when performing the search for the coding sequence
	// Rows are coding sequence
	// Columns are DNA sequence
	std::vector<std::vector<matrixCell>> lcsMatrix;

	// Class functions (define below class)
	inline LCSMatrix(int csLen, size_t dnaLen);
	inline int getCodingSeqLength();
	inline size_t getFullDNALength();
	inline int getFinalLCSLength();
	inline std::string getFinalMatrixCellArrow();
	inline void resizeMatrix(int searchSeqLen);
	inline void printMatrixNums(std::string& codingSequence, std::string& DNA);
	inline void printMatrixArrows(std::string& codingSequence, std::string& DNA);
};

// Constructor stores the length of the sequences and resizes the 2D vector matrix
// Sizes are determined from contents of the input files
inline LCSMatrix::LCSMatrix(int csLen, size_t dnaLen) {
	this->codingSeqSize = csLen;
	this->DNAChunkSize = dnaLen;
	lcsMatrix.resize(codingSeqSize + 1, std::vector<matrixCell>(DNAChunkSize + 1));
}

// Getter for coding sequence size
inline int LCSMatrix::getCodingSeqLength() {
	return this->codingSeqSize;
}

// Getter for size of DNA sequence being checked
inline size_t LCSMatrix::getFullDNALength() {
	return this->DNAChunkSize;
}

// Gets the length of the LCS by returning the value of the last cell in the matrix 
inline int LCSMatrix::getFinalLCSLength() {
	return lcsMatrix[codingSeqSize][DNAChunkSize].cellValue;	// Bottom right corner cell value
}

// Gets the direction of the arrow in the last cell, or returns NULL if the LCS has not been calculated yet
inline std::string LCSMatrix::getFinalMatrixCellArrow() {
	return lcsMatrix[codingSeqSize][DNAChunkSize].arrowDirection;	// Bottom right corner arrow direction
}


// Resizes matrix to search the DNA chunk for new coding sequences that have different lengths
inline void LCSMatrix::resizeMatrix(int searchSeqLen) {
	codingSeqSize = searchSeqLen;
	lcsMatrix.resize(searchSeqLen + 1, std::vector<matrixCell>(DNAChunkSize + 1));	
}

// Prints the LCS matrix nums to console
inline void LCSMatrix::printMatrixNums(std::string& codingSequence, std::string& DNA) {
	if (codingSequence.length() != codingSeqSize || DNA.length() != DNAChunkSize) {
		std::cerr << "ERROR: Incorrect coding sequence and/or DNA chunk for current LCS matrix\n";
		return;
	}

	// Print top row of column numbers
	std::cout << "          ";
	for (int i = 0; i <= DNAChunkSize; i++) {
		std::cout << " ";
		if (i < 10) {
			std::cout << " " << i << " |";
		}
		else {
			std::cout << i << " |";
		}
	}
	std::cout << "\n";

	// Print row of DNA chunk characters
	std::cout << "               ";
	for (int i = 0; i < DNAChunkSize; i++) {
		std::cout << "  " << DNA[i] << " |";
	}
	std::cout << "\n";

	// Print rows of LCS matrix
	for (int i = 0; i <= codingSeqSize; i++) {
		// Print row number
		std::cout << " ";
		if (i < 10) {
			std::cout << " " << i << " |";
		}
		else {
			std::cout << i << " |";
		}

		// Print row coding sequence character
		if (i == 0) {
			// Do not print character on the first row
			std::cout << "    |";
		}
		else {
			std::cout << "  " << codingSequence[i-1] << " |";
		}

		// Print the nums of the row in the LCS matrix
		for (int j = 0; j <= DNAChunkSize; j++) {
			if (lcsMatrix[i][j].cellValue < 10) {
				std::cout << " *" << lcsMatrix[i][j].cellValue << " |";
			}
			else {
				std::cout  << "*" << lcsMatrix[i][j].cellValue << " |";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Prints the LCS matrix arrows to the console
inline void LCSMatrix::printMatrixArrows(std::string& codingSequence, std::string& DNA) {
	if (codingSequence.length() != codingSeqSize || DNA.length() != DNAChunkSize) {
		std::cerr << "ERROR: Incorrect coding sequence and/or DNA chunk for current LCS matrix\n";
		return;
	}

	// Print top row of column numbers
	std::cout << "          ";
	for (int i = 0; i <= DNAChunkSize; i++) {
		std::cout << " ";
		if (i < 10) {
			std::cout << " " << i << " |";
		}
		else {
			std::cout << i << " |";
		}
	}
	std::cout << "\n";

	// Print row of DNA chunk characters
	std::cout << "               ";
	for (int i = 0; i < DNAChunkSize; i++) {
		std::cout << "  " << DNA[i] << " |";
	}
	std::cout << "\n";

	// Print rows of LCS matrix
	for (int i = 0; i <= codingSeqSize; i++) {
		// Print row number
		std::cout << " ";
		if (i < 10) {
			std::cout << " " << i << " |";
		}
		else {
			std::cout << i << " |";
		}

		// Print row coding sequence character
		if (i == 0) {
			// Do not print character on the first row
			std::cout << "    |";
		}
		else {
			std::cout << "  " << codingSequence[i - 1] << " |";
		}

		// Print the arrows of the row in the LCS matrix
		for (int j = 0; j <= DNAChunkSize; j++) {
			if (lcsMatrix[i][j].arrowDirection == "NORTHWEST") {
				std::cout << " *NW|";
			}
			else if (lcsMatrix[i][j].arrowDirection == "NORTH") {
				std::cout << " *N |";
			}
			else if (lcsMatrix[i][j].arrowDirection == "WEST") {
				std::cout << " *W |";
			}
			else {
				std::cout << " *  |";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

#endif // LCS_MATRIX_H