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
#include <bitset>
#include <cmath>
#include <string>

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
ConversionBCD::ConversionBCD(e_codageBinaire choixCodage, float valUser)
{
	//-- test le choixCodage correspond � l'�num�ration BCD 
	if (choixCodage == BCD)
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
	int valUserEntier;
	int result;

	valUserEntier = (int)valUser;


	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
	do
	{
		result = (valUserEntier % 10);
		if (result != 0)
		{
			valUserEntier = valUserEntier / 10;
			ConversionBCD::m_nbrDigitMaxValEntier++;
		}

	} while (result != 0);
	//-- fin de boucle -> �gal � 0


		//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur enti�re

		//-- MAJ du Digit => incr�ment de 1 --//
		//-- MAJ du membre parents -> nbrDigitEntier 
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
	int index = 0;
	int valEnEntier = (int)valUser;

	//-- it�ration pour remplire le tableau de digit --//
	for (int i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- MAJ facteur de puissance de 10 
		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[index] = (valEnEntier / pow(10, i));
	}
		//-- MAJ valeur utilisateur 
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
	m_ptTbBinaire = new std::string[m_nbrDigitMaxValEntier];
	std::string digitConvert;

	//-- d�claration de variable --//
	char digit = 0, digitToConvert = 0;
	bool flagEndCoonvert = false;

	//-- boucle d'it�ration pour pour chaque digit --// 
	do
	{
		digit = m_ptTbDigitEntier[digitToConvert];

		std::bitset<8> digit;
		digitToConvert++;

		if (digitToConvert == m_nbrDigitMaxValEntier)
		{
			flagEndCoonvert = true;
		}

	} while (flagEndCoonvert == false);

		//-- r�cup�re la valeur du digit � convertir --// 


		//-- it�ration de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//


			//-- MAJ de la valeur � convertir --// 


			//-- MAJ du tabelau string --// 

}

