# Gene Sequence Recognizer
Gene Sequencer is a C++ application that takes one file containing a desired DNA nucleotide sequence and a second file containing a chunk of DNA nucleotides. This program searches to see if the desired DNA sequence exists within the DNA chunk in some form, allowing users to search for coding protein sequences that are split up by introns and other inter-exon nucleotide chunks by using an LCS algorithmic search. The user can also convert the DNA sequence to messenger RNA and further to the amino acid sequence if the mRNA is of valid protein coding form, and at each step has analytical capabilities to get various properties of the DNA, mRNA, or amino acid chain of the desired DNA nucleotide sequence. This application is still currently in development and needs to have final portions of the application implemented

[![Static Badge](https://img.shields.io/badge/C%2B%2B-%23007fff?style=flat&logo=C%2B%2B&logoColor=%23007fff&logoSize=large&labelColor=white)](#) [![Static Badge](https://img.shields.io/badge/Bioinformatics-purple?style=flat)](#) [![Static Badge](https://img.shields.io/badge/LCS%20Algorithm-%23fcb21c?style=flat)](#) [![Static Badge](https://img.shields.io/badge/I%2FO%20Handling-%23a61cfc?style=flat)](#) [![Static Badge](https://img.shields.io/badge/OOP%20Design-%2300ffff?style=flat)](#) [![Static Badge](https://img.shields.io/badge/Data%20Structures-%23ff0099?style=flat)](#)


# Technical Skills Implemented:

## Advanced C++ Programming

- **Modern C++ Features** - Implemented advanced object-oriented design with nested switch statements for codon lookups and structured inheritance patterns for biological data
- **Memory Management** - Utilized smart data structures with proper scoping to avoid memory leaks when processing large genomic sequences
- **Compilation Process** - Created a comprehensive Makefile demonstrating understanding of build dependencies and compiler optimization flags

## Data Structures & Algorithms

- **Dynamic Programming** - Implemented the Longest Common Subsequence (LCS) algorithm to efficiently identify DNA patterns within large genomic datasets
- **Custom Data Structures** - Designed specialized matrix cells and amino acid representations using structs with appropriate member organization
- **Recursive Algorithms** - Built a recursive sequence reconstruction function that traverses the direction matrix to rebuild DNA sequences

## Bioinformatics Implementation

- **DNA/RNA Processing** - Developed nucleotide validation, transcription functions, and codon mapping with complete genetic code implementation
- **Protein Translation** - Created a complete mRNA-to-protein translation system with support for start/stop codons and amino acid chain building
- **Biological Analysis** - Implemented nucleotide frequency analysis, protein weight calculation, and amino acid composition statistics

## Software Engineering Practices

- **Modular Design** - Separated functionality into 6+ specialized components with clean interfaces between DNA processing, RNA transcription, and protein analysis
- **Command Processing** - Built an extensible command interpreter with 15+ specialized commands for interactive biological sequence analysis
- **Error Handling** - Implemented domain-specific error types and validation checks to ensure biological data integrity throughout the pipeline
- **Debugging & Logging** - Incorporated detailed debug logs throughout the codebase to trace execution flow and facilitate troubleshooting
- **File Input Management** - Developed robust file input handling functions to read, validate, and process genomic sequence files efficiently

## Scientific Computing

- **Statistical Analysis** - Calculated detailed composition statistics for both nucleotides and amino acids using specialized tracking structures
- **Chemical Property Modeling** - Incorporated detailed molecular information including chemical formulas, weights, and amino acid properties
- **Formatted Scientific Output** - Generated human-readable reports of biological sequences and their properties in standard scientific notation

## Build System & Project Organization

- **Makefile Implementation** - Created a structured build system with proper dependency tracking and clean targets
- **Header Organization** - Built a well-organized code hierarchy with 7+ specialized header files for clean separation of concerns
- **Dependency Management** - Maintained proper include hierarchies to prevent circular dependencies while allowing component reuse
