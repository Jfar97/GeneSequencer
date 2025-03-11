#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <string>

#include "gene_transcription.h"

int nextInstruction(std::string& userCommand, int* commandSubtype);
void readInputFiles(std::string& desSeqFile, std::string& fullDNAFile, std::string& codingSequence, std::string& fullSequence);
int validateInputFiles(std::string& codingSequence, std::string& fullSequence);

enum InstructionResult {  
    END_OF_INPUT = 0,
    VALID_INSTRUCTION = 1,
    INVALID_INSTRUCTION = 2
};

enum FileValidationResults {
    BOTH_VALIDATED = 0,                 // No error in either of the file inputs
    CODING_SEQUENCE_FILE_ERROR = -1,    // There is an error in the FIRST input file, the coding sequence file (argv[1])
    FULL_SEQUENCE_FILE_ERROR = -2       // There is n error in the SECOND input file, the full DNA chunk file (argv[2])
};

#endif // UTIL_H