#ifndef AMINO_ACIDS_H
#define AMINO_ACIDS_H

#include <string>
#include <vector>

enum essentialAATypes {
	ESSENTIAL = 0,					// Can NOT be made by the body - must be obtained from food
	NONESSENTIAL = 1,				// Is able to be produced by the body
	CONDITIONALLY_ESSENTIAL = 2		// Are usually not essential, but are essential during periods of illness or stress
};


struct aminoAcid {
	// Name of the amino acid
	std::string name;

	// The commonly accepted scientific abbreviation of the amino acid
	std::string nameAbbreviation;

	// The alphabetical letter used to denote the amino acid
	std::string letter;
	
	// Flag variable for if the amino acid is either hydrophobic or hydrophilic
	// TRUE - the aa is HYDROPHOBIC (water fearing)
	// FALSE - the aa is HYDROPHILIC (water loving)
	bool isHydrophobic;

	// Flag variable that defines if the amino acid is an essential amino acid or not
	essentialAATypes isEssential;	// Essential amino acids can not be produced by the body and must be consumed

	// Vector that contains the RNA codons that code for the amino acid during transcription
	std::vector<std::string> RNACodons;

	// The chemical structure of the amino acid
	std::string chemicalStructure;

	// The molecular weight of the amino acid
	double molecularWeight;

	// The name of the R group of the amino acid (side chain)
	std::string RGroupType;

	// The properties of the R group (side chain)
	std::string RGroupClassification;

	// The chemical structure of the R group (side chain)
	std::string RGroupChemicalStructure;
};


// Ties the amino acids to their AminoAcidTable positions by name
enum AATablePositions {
	ALANINE = 0,
	ARGININE = 1,
	ASPARAGINE = 2,
	ASPARTIC_ACID = 3,
	CYSTEINE = 4,
	GLUTAMIC_ACID = 5,
	GLUTAMINE = 6,
	GLYCINE = 7,
	HISTIDINE = 8,
	ISOLEUCINE = 9,
	LEUCINE = 10,
	LYSINE = 11,
	METHIONINE = 12,		// START codon - must be at the start of all mRNA codon sequences for translation to occur
	PHENYLALANINE = 13,
	PROLINE = 14,
	SERINE = 15,
	THREONINE = 16,
	TRYPTOPHAN = 17,
	TYROSINE = 18,
	VALINE = 19,
	STOP = 20,				// STOP codon encountered - translation ends
};


// Table containing the 20 amino acids 
class AminoAcidTable {
private:
	aminoAcid aminoAcidTable[20] = {
		{			// 1 - ALANINE - ALA - A
			"Alanine",
			"Ala",
			"A",
			true,
			NONESSENTIAL,
			{
				"GCU", 
				"GCC", 
				"GCA", 
				"GCG"
			},
			"C3_H7_N_O2",
			89.10,
			"Methyl group",
			"Nonpolar, Aliphatic",										// Aliphatic means the side chain is made up of an alkyl (single-bonded) chain of carbon
			"CH3"
		},	
		{			// 2 - ARGININE - ARG - R
			"Arginine",
			"Arg",
			"R",
			false,
			CONDITIONALLY_ESSENTIAL,
			{
				"AGA",
				"AGG",
				"CGU",
				"CGC",
				"CGA",
				"CGG"
			},
			"C6_H14_N4_O2",
			174.20,
			"Guanidinium group",
			"Polar, Basic",												// Basic means positively charged
			"(CH2)3NHC(NH2)2 (+)"
		},	
		{			// 3 - ASPARAGINE - ASN - N
			"Asparagine",
			"Asn",
			"N",
			false,
			NONESSENTIAL,
			{
				"AAU",
				"AAC"
			},
			"C4_H8_N2_O3",
			132.12,
			"Amide group",
			"Polar, Neutral",											// Neutral means uncharged
			"CONH2"
		},	
		{			// 4 - ASPARATIC ACID - ASP - D
			"Asparatic Acid (Aspartate)",
			"Asp",
			"D",
			false,
			NONESSENTIAL,
			{
				"GAU",
				"GAC"
			},
			"C4_H7_N_O4",
			133.11,
			"Carboxyl group",											// Acidic means negatively charged
			"Polar, Acidic",
			"COO (-)"
		},	
		{			// 5 - CYSTEINE - CYS - C
			"Cysteine",
			"Cys",
			"C",
			false,
			CONDITIONALLY_ESSENTIAL,
			{
				"UGU",
				"UGC"
			},
			"C3_H7_N_O2_S",
			121.16,
			"Sulfhydryl group",
			"Polar, Neutral",
			"SH"
		},	
		{			// 6 - GLUTAMIC ACID - GLU - E
			"Glutamic Acid (Glutamate)",
			"Glu",
			"E",
			false,
			ESSENTIAL,
			{
				"GAA",
				"GAG"
			},
			"C5_H9_N_O4",
			147.13,
			"Carboxyl group",
			"Polar, Acidic",
			"COO (-)"
		},	
		{			// 7 - GLUTAMINE - GLN - Q
			"Glutamine",
			"Gln",
			"Q",
			false,
			CONDITIONALLY_ESSENTIAL,
			{
				"CAA",
				"CAG"
			},
			"C5_H10_N2_O3",
			146.15,
			"Amide group",
			"Polar, Neutral",
			"CONH2"
		},	
		{			// 8 - GLYCINE - GLY - G
			"Glycine",
			"Gly",
			"G",
			true,
			CONDITIONALLY_ESSENTIAL,
			{
				"GGU",
				"GGC",
				"GGA",
				"GGG"
			},
			"C2_H5_N_O2",
			75.07,
			"Hydrogen",
			"Nonpolar, Aliphatic",
			"H"
		},	
		{			// 9 - HISTINDINE - HIS - H
			"Histindine",
			"His",
			"H",
			false,
			ESSENTIAL,
			{
				"CAU",
				"CAC"
			},
			"C6_H9_N3_O2",
			155.16,
			"Imidazole Ring",
			"Polar, Basic",
			"CH2-C3H3N2 (+)"
		},	
		{			// 10 - ISOLEUCINE - ILE - I
			"Isoleucine",
			"Ile",
			"I",
			true,
			ESSENTIAL,
			{
				"AUU",
				"AUC",
				"AUA",
			},
			"C6_N13_N_O2",
			131.18,
			"Sec-Butyl group",
			"Nonpolar, Aliphatic",
			"CH(CH3)CH2CH3"
		},	
		{			// 11 - LEUCINE - LEU - L
			"Leucine",
			"Leu",
			"L",
			true,
			ESSENTIAL,
			{
				"CUU",
				"CUC",
				"CUA",
				"CUG",
				"UUA",
				"UUG"
			},
			"C6_H13_N_O2",
			131.18,
			"Isobutyl group",
			"Nonpolar, Aliphatic",
			"CH2CH(CH3)2"
		},	
		{			// 12 - LYSINE - LYS - K
			"Lysine",
			"Lys",
			"K",
			false,
			ESSENTIAL,
			{
				"AAA",
				"AAG"
			},
			"C6_H14_N2_O2",
			146.19,
			"Amino group",
			"Polar, Basic",
			"(CH2)4NH3 (+)"
		},	
		{			// 13 - METHIONINE - MET - M
			"Methionine",				
			"Met",
			"M",
			true,
			ESSENTIAL,
			{					// START CODON
				"AUG",
			},
			"C5_H11_N_O2_S",
			149.21,
			"Thioether group",
			"Nonpolar, Aliphatic",
			"(CH2)2SCH3"
		},	
		{			// 14 - PHENYLALANINE - PHE - F
			"Phenylalanine",
			"Phe",
			"F",
			true,
			ESSENTIAL,
			{
				"UUU",
				"UUC"
			},
			"C9_H11_N_O2",
			165.19,
			"Phenyl group",
			"Nonpolar, Aromatic",
			"CH2C6H5"
		},	
		{			// 15 - PROLINE - PRO - P
			"Proline",
			"Pro",
			"P",
			true,
			CONDITIONALLY_ESSENTIAL,
			{
				"CCU",
				"CCC",
				"CCA",
				"CCG"
			},
			"C9_H11_N_O2",
			115.13,
			"Pyrrolidine ring that loops back to the alpha-amino group",
			"Nonpolar, Aliphatic",
			"C4H9N"
		},	
		{			// 16 - SERINE - SER - S
			"Serine",
			"Ser",
			"S",
			false,
			CONDITIONALLY_ESSENTIAL,
			{
				"AGU",
				"AGC",
				"UCU",
				"UCC",
				"UCA",
				"UCG"
			},
			"C3_H7_N_O3",
			105.09,
			"Hydroxyl group",
			"Polar, Neutral",
			"OH"
		},	
		{			// 17 - THREONINE - THR - T
			"Threonine",
			"Thr",
			"T",
			false,
			ESSENTIAL,
			{
				"ACU",
				"ACC",
				"ACA",
				"ACG"
			},
			"C4_H9_N_O3",
			119.12,
			"Hydroxyl group on alkyl chain",
			"Polar, Neutral",
			"CH(CH3)OH"
		},	
		{			// 18 - TRYPTOPHAN - TRP - W
			"Tryptophan",
			"Trp",
			"W",
			true,
			ESSENTIAL,
			{
				"UGG",
			},
			"C11_H12_N2_O2",
			204.23,
			"Indole ring",
			"Nonpolar, Aromatic",
			"CH2C6H4CCNH3"
		},	
		{			// 19 - TYROSINE - TYR - Y
			"Tyrosine",
			"Tyr",
			"Y",
			true,
			CONDITIONALLY_ESSENTIAL,
			{
				"UAU",
				"UAC"
			},
			"C9_H11_N_O3",
			181.19,
			"Hydroxyl-Substituted Phenyl group",
			"Nonpolar, Aromatic",
			"CH2C6H4OH"
		},	
		{			// 20 - VALINE - VAL - V
			"Valine",
			"Val",
			"V",
			true,
			ESSENTIAL,
			{
				"GUU",
				"GUC",
				"GUA",
				"GUG"
			},
			"C5_H11_N_O3",
			181.19,
			"Isopropyl group",
			"Nonpolar, Aliphatic",
			"CH(CH3)2"
		},
	};

public:
	inline aminoAcid getAminoAcid(int aa);
	inline std::string getAminoAcidName(int aa);
	inline std::string getAminoAcidAbbreviation(int aa);
	inline std::string getAminoAcidLetter(int aa);
};


inline aminoAcid AminoAcidTable::getAminoAcid(int aa) {
	return this->aminoAcidTable[aa];
}

inline std::string AminoAcidTable::getAminoAcidName(int aa) {
	return this->aminoAcidTable[aa].name;
}

inline std::string AminoAcidTable::getAminoAcidAbbreviation(int aa) {
	return this->aminoAcidTable[aa].nameAbbreviation;
}

inline std::string AminoAcidTable::getAminoAcidLetter(int aa) {
	return this->aminoAcidTable[aa].letter;
}


#endif //AMINO_ACIDS_H

/** Credit to :
*	https://www.sigmaaldrich.com/US/en/technical-documents/technical-article/protein-biology/protein-structural-analysis/amino-acid-reference-chart?srsltid=AfmBOoofHDIfiu9mVlsWwf7-GErs9KnsNBTRPfNLpdgj_gTgHcdyIXXc
*	https://www.hgmd.cf.ac.uk/docs/cd_amino.html
*	https://medlineplus.gov/ency/article/002222.htm
*	https://biology.kenyon.edu/courses/biol114/Chap05/Chapter05.html
*	https://www.creative-biostructure.com/amino-acid-properties-and-structure.htm
*/