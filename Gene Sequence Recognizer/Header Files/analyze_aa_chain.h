#ifndef ANALYZE_AA_CHAIN_H
#define ANALYZE_AA_CHAIN_H

#include "amino_acids.h"

void printAAByLine(std::vector<aminoAcid>& protein);
double getProteinWeight(std::vector<aminoAcid>& protein);
void getAAPercentages(std::vector<aminoAcid>& protein);

#endif // ANALYZE_AA_CHAIN_H