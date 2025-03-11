#include "main.h"
#include <iostream>

// argc == 4
// argv[0] - program execution call
// argv[1] - .txt input file containing desired coding nucleotide sequence being searched for
// argv[2] - .txt input file containing a large sequence of DNA which is searched through for the coding sequence defined in argv[1]
// argv[3] - .txt output file that has the discovered results written into it
int main(int argc, char* argv[])
{
    // Ensure correct number of command-line arguments
    if (argc != 4) {
        // Show error otherwise
        std::cerr << "Incorrect number of program inputs given.\n";
        std::cerr << "Please provide the protein coding sequence of the gene being checked for, the section of DNA that must be parsed, and the desired output file\n";
        exit(1);
    }
    // String for storing the desired protein's nucleotide coding sequence inside the DNA
    std::string codingSequence;

    // String for storing the section of DNA that will be searched for the coding sequence
    std::string DNAChunk;

    // Files converted from type char* to string so they can be passed in as parameters of type string& into readInputFiles below
    std::string desSeqFile = argv[1];
    std::string fullDNAFile = argv[2];

    // Read input files
    readInputFiles(desSeqFile, fullDNAFile, codingSequence, DNAChunk);

    // Get lengthes of desired sequence and full sequence stored as ints
    int desSeqLen = codingSequence.length();
    size_t fullDNALen = DNAChunk.length();
    std::cout << "The coding sequence length is " << desSeqLen << " and the full DNA length is " << fullDNALen << std::endl;

    // Create LCS Matrix using given lengths
    LCSMatrix geneMatrix(desSeqLen, fullDNALen);

    // Process user instructions once prerequisets above are all created and initialized
    handleInstructions(codingSequence, DNAChunk, geneMatrix);

    return 0;
}


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
// Processes user instructions
void handleInstructions(std::string& codingSequence, std::string& DNA, LCSMatrix& geneMatrix)
{
    int maxRow = geneMatrix.getCodingSeqLength();
    size_t maxCol = geneMatrix.getFullDNALength();


    /** USER INPUT VARIABLES **/
    // Stores the command input from the user
    std::string userInput;

    // Stores the subtype of a selected command if applicable
    int subtypeCommand;

    // Stores the int result from validating the user input
    int inputResult;


    /** KEY VARIABLES **/
    /** KEY VARIABLES - DNA SECTION **/
    // String that stores the LCS of the two input files    - this should match the protein coding sequence in input file 1 (argv[1]) if the coding sequence is present in the DNA chunk
    std::string calculatedLCS = "";

    /** KEY VARIABLES - RNA SECTION **/
    // String that stores the messenger RNA transcribed from the calculated LCS
    std::string mRNA = "";

    /** KEY VARIABLES - AMINO ACID CHAIN (PROTEIN) SECTION **/
    std::vector<aminoAcid> proteinSequence;

    std::string proteinStringSequenceNames = "";
    std::string proteinStringSequenceAbbr = "";
    std::string proteinStringSequenceLetters = "";

    double proteinWeight = -1;


    /** STATE VARIABLES **/
    // Stores the state of whether the inputs are valid or not
    bool inputsAreValid = false;

    // Stores the state of whether the user has run the input validation
    bool hasRunValdiationOnInputs = false;


    // Program execution loop - accepts user intrsuctions at each loop iteration
    while ((inputResult = nextInstruction(userInput, &subtypeCommand))) {

        // Invalid instructions are caught and processed so program does not crash
        if (inputResult == INVALID_INSTRUCTION) {
            std::cout << "WARNING: Invalid instruction" << std::endl;
            continue;
        }



        // COMMAND: STOP
        // Stop - Exits the program
        if (userInput == "Stop") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            break;
        }



        // COMMAND: LIST COMMANDS
        // ListCommands - Prints out the valid commands accepted by the program
        else if (userInput == "ListCommands") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            std::cout << "LIST OF VALID COMMAND CALLS" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "1)  Stop:" << std::endl;
            std::cout << "     -   Exits the program" << std::endl;
            std::cout << "2)  CalculateLCS:" << std::endl;
            std::cout << "     -   Calculates the LCS of the two input files inside the LCS matrix" << std::endl;
            std::cout << "3)  PrintLCS:" << std::endl;
            std::cout << "     -   Prints out the calculated LCS" << std::endl;
            std::cout << "4)  PrintMatrixNums:" << std::endl;
            std::cout << "	   -   Prints the LCS matrix numbers" << std::endl;
            std::cout << "5)  PrintMatrixArrows:" << std::endl;
            std::cout << "	   -   Prints the LCS matrix arrows" << std::endl;
            std::cout << "6)  CheckForSequence:" << std::endl;
            std::cout << "	   -   Checks to ensure that the LCS found matches the desired coding sequence" << std::endl;
            std::cout << "7)  ValidateInputs:" << std::endl;
            std::cout << "     -   Validate the file inputs to ensure they are valid and will not cause a program crash" << std::endl;
            std::cout << "8)  DNANucPercentages:" << std::endl;
            std::cout << "     -   Gets the percentage of each of the four DNA nucleotides that make up the calculated LCS segment" << std::endl;
            std::cout << "9)  TranscribeDNA:" << std::endl;
            std::cout << "     -   Transcribe the DNA coding sequence input into its mRNA counterpart" << std::endl;
            std::cout << "10) PrintRNA:" << std::endl;
            std::cout << "     -   Prints the messenger RNA transcribed from the calculated LCS" << std::endl;
            std::cout << "11) ValidateRNA:" << std::endl;
            std::cout << "     -   Ensures the mRNA transcribed from the LCS is a valid protein coding mRNA" << std::endl;
            std::cout << "12) RNANucPercentages:" << std::endl;
            std::cout << "     -   Gets the percentage of each of the four RNA nucleotides that make up the transcribed mRNA" << std::endl;
            std::cout << "13) TranslateRNA <Num>:" << std::endl;
            std::cout << "     -   Translate the mRNA into the amino acid sequence for the protein, varies based on second input" << std::endl;
            std::cout << "     -    1) Creates amino acid struct vector" << std::endl;
            std::cout << "     -    2) Creates full name amino acid string" << std::endl;
            std::cout << "     -    3) Creates abbreviated named amino acid string" << std::endl;
            std::cout << "     -    4) Creates letter amino acid string" << std::endl;
            std::cout << "14) AssessProtein <Num>:" << std::endl;
            std::cout << "     -   Checks the amino acid sequence of the protein for different properties" << std::endl;
            std::cout << "     -    1) Prints the amino acid composition" << std::endl;
            std::cout << "     -    2) Gets the weight of the protein" << std::endl;
            std::cout << "     -    3) Get the percentage of each of the 20 amino acids making up the protein" << std::endl;
            //std::cout << "     -    4) " << std::endl;
            //std::cout << "14) " << std::endl;
            //std::cout << "14) " << std::endl;
        }



        // COMMAND: CALCULATE LCS
        // CalculateLCS - Calculates the LCS of the two input files inside the LCS matrix
        else if (userInput == "CalculateLCS") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            int length = geneLCS(codingSequence, DNA, geneMatrix);
            std::cout << "The genetic LCS of the coding sequence and the section of DNA has been found with a length of " << length << std::endl;
            std::cout << "Constructing the LCS...";
            calculatedLCS = constructLCS(DNA, geneMatrix, maxRow, maxCol);
            std::cout << " LCS constructed.";
        }


        
        // COMMAND: PRINT LCS
        // PrintLCS - Prints out the calculated LCS
        else if (userInput == "PrintLCS") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            if (calculatedLCS == "") {
                std::cout << "No LCS has been calculated - please calculate the LCS of the two inputs";
            }
            else {
                std::cout << calculatedLCS << std::endl;
            }
            
        }



        // COMMAND: PRINT MATRIX NUMBERS
        // PrintMatrixNums
        else if (userInput == "PrintMatrixNums") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            geneMatrix.printMatrixNums(codingSequence, DNA);
        }



        // COMMAND: PRINT MATRIX ARROWS
        // PrintMatrixArrows
        else if (userInput == "PrintMatrixArrows") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            geneMatrix.printMatrixArrows(codingSequence, DNA);
        } 



        // COMMAND: CHECK FOR SEQUENCE
        // CheckForSequence - Checks to ensure that the LCS found matches the desired coding sequence
        else if (userInput == "CheckForSequence") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            if (calculatedLCS == "") {
                std::cout << "No LCS has been calculated - please calculate the LCS of the two inputs";
                continue;
            }

            if (doesCodingSequenceExist(codingSequence, calculatedLCS) == true) {
                std::cout << "VALID: the genetic coding sequence exists within the section of DNA given\n";              // Coding sequence found in the DNA
            }

            else {
                std::cout << "INVALID: the genetic coding sequence does NOT exist within the section of DNA given\n";    // Coding sequence is NOT present in the DNA
            }
        }



        // COMMAND: VALIDATE INPUTS
        // ValidateInputs - 
        else if (userInput == "ValidateInputs") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            // Validate the files and store the result to check
            int validationResult = validateInputFiles(codingSequence, DNA);

            // Make flag variable true
            hasRunValdiationOnInputs = true;

            // -1 means argv[1] has an error
            if (validationResult == -1) {
                std::cout << "There is an error in your first input file that contains the protein coding sequence.\n";
            }
            // -2 means argv[2] has an error 
            else if (validationResult == -2) {
                std::cout << "There is an error in your second input file that contains the full chunk of DNA.\n";
            }
            // Otherwise there is no error
            else {
                std::cout << "The input files both contain valid DNA sequences.\n";
                inputsAreValid = true;
            }
        }



        // COMMAND: DNA NUCLEOTIDE PERCENTAGES
        // DNANucPercentages - 
        else if (userInput == "DNANucPercentages") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            printDNAPercentages(calculatedLCS);
        }



        // COMMAND: TRANSCRIBE DNA
        // TranscribeDNA -
        else if (userInput == "TranscribeDNA") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            //if (hasRunValdiationOnInputs == false) {
                //std::cout << "The input files' contents has not been validated, potential error during transcription is possible.\n";
            //}
            if (hasRunValdiationOnInputs == true && inputsAreValid == false) {
                std::cout << "There is at least one nonvalid file input, please fix the file giving validation errors before attempting to transcribe the DNA sequence.\n";
                continue;
            }

            mRNA = buildMessengerRNA(calculatedLCS);
            if (mRNA == "ERROR") {
                std::cout << "There was an error transcribing the LCS - please ensure your file inputs are valid, continuous DNA sequences and try again\n";
            }
        }



        // COMMAND: PRINT RNA
        // PrintRNA - prints the messenger RNA transcribed from the calculated LCS
        else if (userInput == "PrintRNA") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            if (mRNA == "") {
                std::cout << "The LCS has not been converted to mRNA yet - please calcualte the LCS and transcribe it\n";
            }
            else if (mRNA == "ERROR") {
                std::cout << "There was an error transcribing the LCS - please ensure your file inputs are valid, continuous DNA sequences and try again\n";
            }
            else {
                std::cout << mRNA << std::endl;
            }
        }



        // COMMAND: VALIDATE RNA
        // ValidateRNA - Ensures the mRNA transcribed from the LCS is a valid protein coding mRNA
        else if (userInput == "ValidateRNA") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            if (mRNA == "") {
                std::cout << "The LCS has not been converted to mRNA yet - please calcualte the LCS and transcribe it\n";
                continue;
            }
            else if (mRNA == "ERROR") {
                std::cout << "There was an error transcribing the LCS - please ensure your file inputs are valid, continuous DNA sequences and try again\n";
                continue;
            }
            
            int validationResult = validateMessRNA(mRNA);
            if (validationResult == 1) {
                std::cout << "INVALID: The mRNA's length is invalid, as it must be divisible by 3 for the codon sequencing during translation\n";
            }
            else if (validationResult == 2) {
                std::cout << "INVALID: The mRNA does not begin with the START codon\n";
            }
            else if (validationResult == 3) {
                std::cout << "INVALID: The mRNA does not end with any of the STOP codons\n";
            }
            else {
                std::cout << "VALID: The mRNA can successfully code for a protein during translation. Its lenght is divisible by\n3 for codon sequencing, it begins with the START codon, and it ends with STOP codon\n";
            }
        }



        // COMMAND: RNA NUCLEOTIDE PERCENTAGES
        // RNANucPercentages - 
        else if (userInput == "RNANucPercentages") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << std::endl;

            printMessRNAPercentages(mRNA);
        }



        // COMMAND: TRANSLATE RNA <NUM>
        else if (userInput == "TranslateRNA") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << " " << subtypeCommand << std::endl;

            // Check command subtype is valid
            if (subtypeCommand < 1 || subtypeCommand > 4) { // 4 command types available 
                std::cout << "The command subtype you entered is invalid - please choose a number from 1 to 4, or type ListCommands\nto review what each subtype command does\n";
                continue;
            }

            // Check mRNA
            if (mRNA == "") {
                std::cout << "The LCS has not been converted to mRNA yet - please calcualte the LCS and transcribe it\n";
                continue;
            }
            else if (mRNA == "ERROR") {
                std::cout << "There was an error transcribing the LCS - please ensure your file inputs are valid, continuous DNA sequences and try again\n";
                continue;
            }

            // Different translation cases
            // 1 - aminoAcid vector
            if (subtypeCommand == 1) {
                proteinSequence = getAminoAcidSequence(mRNA);
                std::cout << "Full amino acid sequence has been translated from the mRNA, use AssessProtein commands to examine the protein chain\n";
            }

            // 2 - string with full names
            else if (subtypeCommand == 2) {
                proteinStringSequenceNames = getAminoAcidNameSequence(mRNA);
                std::cout << "mRNA translated into full name amino acid sequence:\n";
                std::cout << proteinStringSequenceNames << std::endl;
            }

            // 3 - string with abbreviated name
            else if (subtypeCommand == 3) {
                proteinStringSequenceAbbr = getAminoAcidAbbreviationSequence(mRNA);
                std::cout << "mRNA translated into abbreviated name amino acid sequence:\n";
                std::cout << proteinStringSequenceAbbr << std::endl;
            }

            // 4 - string with letter representations
            else {
                proteinStringSequenceLetters = getAminoAcidLetterSequence(mRNA);
                std::cout << "mRNA translated into letter representation amino acid sequence:\n";
                std::cout << proteinStringSequenceLetters << std::endl;
            }
        }



        // COMMAND: ASSESS PROTEIN <NUM>
        else if (userInput == "AssessProtein") {
            // Print instruction
            std::cout << "\nInstruction: " << userInput << " " << subtypeCommand << std::endl;

            // Ensure the aminoAcid vector has been initialized
            if (proteinSequence.size() < 1) {
                std::cout << "The mRNA must be first be translated into a full amino acid sequence using 'TranslateRNA 1'\n";
            }

            // Check command subtype is valid
            if (subtypeCommand < 1 || subtypeCommand > 3) { // 3 command types available 
                std::cout << "The command subtype you entered is invalid - please choose a number from 1 to 4, or type ListCommands\nto review what each subtype command does\n";
                continue;
            }


            // 1 - Print AAs
            if (subtypeCommand == 1) {
                printAAByLine(proteinSequence);
            }

            // 2 - Get weight of the protein
            else if (subtypeCommand == 2) {
                if (proteinWeight == -1) {
                    proteinWeight = getProteinWeight(proteinSequence);
                }

                std::cout << "The weight of the protein is " << proteinWeight << " Daltons (Da)\n";
            }

            // 3 - Get AA percentages
            else if (subtypeCommand == 3) {
                getAAPercentages(proteinSequence);
            }
        }
    }
}