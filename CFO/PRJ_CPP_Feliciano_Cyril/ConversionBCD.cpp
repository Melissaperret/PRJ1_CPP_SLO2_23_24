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
#include "ConversionNum.h"
#include "ConversionBCD.h"

//-- librairie personnelle --// 


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
	if (choixCodage == 1)
	{
		//-- cr�ation d'un tableau dynamique via pointeur --// 
		tabDynamique[0] = ConversionNumerique::m_ptTbDigitEntier;
		*tabDynamique[1] = ConversionNumerique::m_nbrDigitMaxValEntier;

		//-- appel fonction : d�termine le nb de digit du nombre entier --//
		ConversionBCD::CalculerNbrDigitEntier(valUser);

		//-- appel fonction : r�cuperation de chaque digit --//
		ConversionBCD::RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 

		ConversionBCD::ConversionBinaire();
	}
	else
	{

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
	char nombreDigit = 0;
	char valDigit[32];
	char indexDigit = 0;

	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
	for (indexDigit = 0; indexDigit < valUser; indexDigit++)
	{
		if (valUser != 0)
		{
			valDigit[indexDigit] = valUser;
			//valUser = valUser >> 1;
			nombreDigit++;
		}
	}
	//-- fin de boucle -> �gal � 0


		//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur enti�re


		//-- MAJ du Digit => incr�ment de 1 --//



	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier = nombreDigit;
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
	int valDigit = 0;
	char tabValDigit[32];
	char indexValDigit;
	//-- it�ration pour remplire le tableau de digit --//
	
		//-- MAJ facteur de puissance de 10 --// 


		//-- MAJ TAbleau -> digit 
	

		//-- MAJ valeur utilisateur 
	*tabDynamique[1] = valDigit;
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
void ConversionBCD::ConversionBinaire()
{
	
	//-- Creation du tableau dynamique de string en fct des digit entier --// 


	//-- d�claration de variable --//
	char indexConversionBin;

	//-- boucle d'it�ration pour pour chaque digit --// 

		//-- r�cup�re la valeur du digit � convertir --// 


		//-- it�ration de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//


			//-- MAJ de la valeur � convertir --// 


			//-- MAJ du tabelau string --// 

}