#include "util.h"
#include <iostream>

/**
*	LIST OF VALID COMMAND CALLS
*	-------------------------------------------------------------------------------------------------------------------------------
*	Stop				 - Exits the program                                                                                               1
*	CalculateLCS		 - Calculates the LCS of the two input files inside the LCS matrix                                                 2
*	PrintLCS			 - Prints out the calculated LCS                                                                                   3
*	PrintMatrixNums		 - Prints the LCS matrix numbers                                                                                   4
*	PrintMatrixArrows	 - Prints the LCS matrix arrows                                                                                    5
*	CheckForSequence	 - Checks to ensure that the LCS found matches the desired coding sequence                                         6
*	ListCommands		 - Prints out the valid commands accepted by the program                                                           7
*   DNANucPercentages    - Gets the percentage of each of the four DNA nucleotides that make up the calculated LCS segment                 8
*	ValidateInputs		 - Validate the file inputs to ensure they are valid and will not cause a program crash                            9
*	TranscribeDNA		 - Transcribe the DNA coding sequence input into its mRNA counterpart                                              10
*   PrintRNA             - Prints the messenger RNA transcribed from the calculated LCS                                                    11
*   ValidateRNA          - Ensures the mRNA transcribed from the LCS is a valid protein coding mRNA                                        12
*   RNANucPercentages    - Gets the percentage of each of the four RNA nucleotides that make up the transcribed mRNA                       13
*	TranslateRNA <Num>	 - Translate the mRNA into the amino acid sequence for the protein, varies based on second input                   14
*	AssessProtein <Num>	 - Checks the amino acid sequence of the protein for different properties                                          15
*/

// Next instruction function
int nextInstruction(std::string& userCommand, int* commandSubtype) {
	// No command given by user
	if (!(std::cin >> userCommand)) {								// No input given
		return END_OF_INPUT;
	}

	// Valid user commands											// Valid input given
	if (userCommand == "Stop"										// 1
		|| userCommand == "CalculateLCS"							// 2
		|| userCommand == "PrintLCS"								// 3
		|| userCommand == "PrintMatrixNums"							// 4
		|| userCommand == "PrintMatrixArrows"						// 5
		|| userCommand == "CheckForSequence"						// 6
		|| userCommand == "ListCommands"							// 7
		|| userCommand == "ValidateInputs"							// 8
		|| userCommand == "DNANucPercentages"						// 9
		|| userCommand == "TranscribeDNA"							// 10
		|| userCommand == "PrintRNA"								// 11
		|| userCommand == "ValidateRNA"								// 12
		|| userCommand == "RNANucPercentages"						// 13
		) {
		return VALID_INSTRUCTION;									
	}

	if (userCommand == "TranslateRNA"								// 14
		|| userCommand == "AssessProtein"							// 15
		) {
		if (std::cin >> *commandSubtype) {
			return VALID_INSTRUCTION;
		}
	}

	// Default case of non valid instruction input by user
	return INVALID_INSTRUCTION;										// Invalid input given
}


// Read input file function
// Pull in length of inputs here to define the size of the array for the LCS calculation
void readInputFiles(std::string& desSeqFile, std::string& fullDNAFile, std::string& codingSequence, std::string& fullSequence) {
	// Files opened using ifstreams
	std::ifstream desiredCodingSequence(desSeqFile);
	std::ifstream fullDNASequence(fullDNAFile);

	// Confirm both files successfully opened
	if (!desiredCodingSequence.is_open() || !fullDNASequence.is_open())
	{
		std::cerr << "ERROR: Faild to open input files\n";
		exit(1);
	}
	
	// Temp string storage for each line inside the files
	std::string nextFileLine;

	// Loop through each file and input contents into a string
	while (getline(desiredCodingSequence, nextFileLine))
	{
		codingSequence += nextFileLine;	// Concatonate each line of the file
	}
	while (getline(fullDNASequence, nextFileLine))
	{
		fullSequence += nextFileLine;	// Concatonate each line of the file
	}

	// Close files after reading through them
	desiredCodingSequence.close();
	fullDNASequence.close();
}


int validateInputFiles(std::string& codingSequence, std::string& fullSequence) {
	int codSeqLen = codingSequence.length();
	size_t fullSeqLen = fullSequence.length();

	std::cout << "Coding sequence file has length " << codSeqLen << " and full sequence file has length " << fullSeqLen << std::endl;

	int codSeqCheckPos = 0;
	size_t fullSeqCheckPos = 0;

	while (codSeqCheckPos < codSeqLen && fullSeqCheckPos < fullSeqLen) {
		// Check if there are still coding sequence characters to check
		if (codSeqCheckPos < codSeqLen) {
			// Validate DNA nucleotide of coding sequence input at current position that must be checked
			if (getRNANucleotide(codingSequence[codSeqCheckPos]) == 'X') {
				// Improper nucleotide character encountered in coding sequence input file
				std::cout << "Coding sequence file has an error\n";
				return CODING_SEQUENCE_FILE_ERROR;
			}

			// Increment to check next position if it exists
			codSeqCheckPos++;
		}

		// Check if there are still full sequence characters to check
		if (fullSeqCheckPos < fullSeqLen) {
			// Validate DNA nucleotide of full sequence input at current position that must be checked
			if (getRNANucleotide(fullSequence[codSeqCheckPos]) == 'X') {
				// Improper nucleotide character encountered in full sequence input file
				std::cout << "Full DNA chunk file has an error\n";
				return FULL_SEQUENCE_FILE_ERROR;
			}
		}
	}

	std::cout << "Both files validated\n";

	return BOTH_VALIDATED;
}
// Write output file function