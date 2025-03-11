EXEC = GeneSequenceFinder
CC = g++
CFLAGS = -c -Wall

# Object files
OBJS = main.o sequence_finder.o util.o gene_transcription.o rna_translation.o analyze_aa_chain.o

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

# Main
main.o: main.cpp main.h sequence_finder.h util.h gene_transcription.h rna_translation.h analyze_aa_chain.h lcs_matrix.h amino_acids.h
	$(CC) $(CFLAGS) main.cpp

# Sequence finder implementation
sequence_finder.o: sequence_finder.cpp sequence_finder.h lcs_matrix.h
	$(CC) $(CFLAGS) sequence_finder.cpp

# Utility functions
util.o: util.cpp util.h gene_transcription.h
	$(CC) $(CFLAGS) util.cpp

# Gene transcription implementation
gene_transcription.o: gene_transcription.cpp gene_transcription.h
	$(CC) $(CFLAGS) gene_transcription.cpp

# RNA translation implementation
rna_translation.o: rna_translation.cpp rna_translation.h amino_acids.h
	$(CC) $(CFLAGS) rna_translation.cpp

# Amino acid chain analysis implementation
analyze_aa_chain.o: analyze_aa_chain.cpp analyze_aa_chain.h amino_acids.h
	$(CC) $(CFLAGS) analyze_aa_chain.cpp

# Clean rule
clean:
	rm -f *.o $(EXEC)