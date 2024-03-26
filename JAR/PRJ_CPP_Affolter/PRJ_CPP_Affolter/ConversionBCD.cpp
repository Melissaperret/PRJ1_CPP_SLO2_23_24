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

#include <string>				// pour les objets de type chaine de caract�re 
#include <iostream>				// pour les m�thode cin et cout
#include <bitset>				// pour le tableau binaire

//-- librairie personnelle --// 
#include "ConversionBCD.h"

//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ConversionBCD 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: constructeur 
// Date modfification	: le 26.03.2024 
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
// Date modfification	: le 26.03.2024 
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
		CalculerNbrDigitEntier(valUser);

		//-- appel fonction : r�cuperation de chaque digit --//
		RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		ConversionBinaire();
	}
}


//----------------------------------------------------------------------------------//
// Nom de la m�thode	: ~ConversionBCD 
// Entr�e				: 
// Sortie				: 
// in-out				:  
// Description			: destructeur 
// Date modfification	: le 26.03.2024 
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
// Date modfification	: le 26.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::CalculerNbrDigitEntier(float valUser)
{
	//-- d�claration de variables --// 
	char countDigits = 0;	// Variable de comptage du nombre d'it�ration de la boucle
	int valUserEntier = (int) valUser;	// Valeur enti�re de valUser

	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
	//-- fin de boucle -> �gal � 0
	/*for (i = 10; i = 0; i--)*/
	while (valUserEntier > 0)
	{
		//-- division de la valeur enti�re par 10
		//-- et MAJ de la valeur enti�re
		valUserEntier = valUserEntier / 10;

		//-- MAJ du Digit => incr�ment de 1 --//
		countDigits++;

	} ;

	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier = countDigits;
}


//----------------------------------------------------------------------------------//
// Nom de la m�thode	: RecupererDigitEntier 
// Entr�e				: valUser		-> reel		-> 4 octets  
// Sortie				: 
// in-out				: 
// Description			: d�termine la valeur de chaque digit et l'enregistre dans 
//						  un tableau
// Date modfification	: le 26.03.2024 
// Remarque				: 
//----------------------------------------------------------------------------------//
void ConversionBCD::RecupererDigitEntier(float valUser)
{
	//-- d�claration variable --// 
	char i = 0;	// Variable de comptage de la boucle
	int valUserEntier = (int)valUser;	// Valeur enti�re de valUser

	//-- it�ration pour remplire le tableau de digit --//
	for (i = m_nbrDigitMaxValEntier; i > 0; i--)
	{
		//-- MAJ TAbleau -> digit 
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier - i] = valUserEntier / (10 ^ i); 
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
void ConversionBCD::ConversionBinaire()
{
	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	m_ptTbBinaire = new std::string[m_nbrDigitMaxValEntier];

	//-- d�claration de variable --//
	char i = 0;	// Variable de comptage de la boucle des digits
	char y = 0;	// Variable de comptage de la boucle de convertion
	char digit = 0;	// Variable de sauvegarde du digit
	std::bitset<1> tb_Bin[4];


	//-- boucle d'it�ration pour pour chaque digit --// 
	for (i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- r�cup�re la valeur du digit � convertir --// 
		digit = m_ptTbDigitEntier[i];

		//-- it�ration de conversion binaire --// 	
		while (digit > 0)
		{
			//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//
			tb_Bin[y] = digit % 2;

			//-- MAJ de la valeur � convertir --// 
			digit = digit / 2;

			y++;
		}
		//-- MAJ du tabelau string --// 
		m_ptTbBinaire[i] = tb_Bin->to_string();
	}
}