//-----------------------------------------------------------------------------------/
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: ConversionNum.cpp
// Date de cr�ation 	: 21.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			:        
//----------------------------------------------------------------------------------//

//-- librairie standart --// 

								// pour les objets de type chaine de caract�re 
#include <iostream>				// pour les m�thode cin et cout

//-- librairie personnelle --// 
#include "ConversionBCD.h"

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBCD 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: si constructeur surcharg� - il faut d�finir le constructeur 
//						  par d�faut + ajouter le lien de au constructeur parent !!!
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD()
{

}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBCD 
// Entr�e				: choixCodage	-> entier	-> enum�ration : e_codageBinaire
//						  valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				:  
// Description			: constructeur surcharg� 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::ConversionBCD(ConversionNumerique::e_codageBinaire choixCodage, float valUser)
{
	//-- test le choixCodage correspond � l'�num�ration BCD 
	if (choixCodage < ConversionNumerique::e_codageBinaire::AIKEN)
	{
		//-- cr�ation d'un tableau dynamique via pointeur --// 
		m_ptTbDigitEntier = new char[m_nbrDigitMaxValEntier];

		//-- appel fonction : d�termine le nb de digit du nombre entier --//
		ConversionBCD::CalculerNbrDigitEntier(valUser);

		//-- appel fonction : r�cuperation de chaque digit --//
		ConversionBCD::RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --//
		ConversionBCD::ConversionBinaire();
	}
}
	
			





//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ~ConversionBCD 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
ConversionBCD::~ConversionBCD()
{

}



//----------------------------------------------------------------------------------//
// Nom de la m�thode	: CalculerNbrDigitEntier 
// Entr�e				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: d�termine le nb de digit d'un nombre entier 
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)
{
	//-- d�claration de variables --// 
	int nbrDigitScan = 0;
	int powerScan = 1;
	int inputEntier = valUser;

	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
	//-- fin de boucle -> �gal � 0
	while ((inputEntier / powerScan) > 0)
	{
		//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur enti�re
		powerScan *= 10;

		//-- MAJ du Digit => incr�ment de 1 --//
		nbrDigitScan++;
	}

	//-- MAJ du membre parents -> nbrDigitEntier
	m_nbrDigitMaxValEntier = nbrDigitScan;
}

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: RecupererDigitEntier 
// Entr�e				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: d�termine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 21.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- d�claration variable --// 
	int digitScan = 0;
	int inputEntier = valUser;
	char getDigit = 0;

	//-- it�ration pour remplire le tableau de digit --//
	while ((inputEntier > 0) && (m_nbrDigitMaxValEntier > digitScan))
	{
		//-- MAJ facteur de puissance de 10 --//
		getDigit = inputEntier % 10;

		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier-digitScan-1] = getDigit;

		//-- MAJ valeur utilisateur
		inputEntier /= 10;
		digitScan++;
	}
}
	 
		
	



//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBinaire
// Entr�e				: 
// Sortie				: 
// in-out				: 
// Description			: convertir un valeur d�cimale selon les attributs de la 
//						  la classe parent 
// Date modfification	: le 22.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::ConversionBinaire(void)
{
	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	char *m_ptTbBin = new char[m_nbrDigitMaxValEntier];

	//-- d�claration de variable --//
	char getDigit = 0;
	char getDin = 0;
	int BinScan = 0;

	//-- boucle d'it�ration pour pour chaque digit --// 
	for (int digitScan=0; digitScan < m_nbrDigitMaxValEntier; digitScan++)
	{
		//-- r�cup�re la valeur du digit � convertir --// 
		getDigit = m_ptTbDigitEntier[digitScan];

		//-- it�ration de conversion binaire --//
		while (getDigit > 0)
		{
			//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//
			if ((getDigit % 10) == 0)
				//-- MAJ du tabelau string --//
				m_ptTbBin[BinScan] = '1';
			else
				//-- MAJ du tabelau string --//
				m_ptTbBin[BinScan] = '0';
			//-- MAJ de la valeur � convertir --//
			BinScan++;
			getDigit /= 10;
		}
	}
	m_ptTbBinaire = new std::string(m_ptTbBin);
}		