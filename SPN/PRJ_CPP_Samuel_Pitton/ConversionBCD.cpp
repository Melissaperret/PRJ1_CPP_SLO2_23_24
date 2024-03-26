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
#include <bitset>
	
//-- librairie personnelle --// 
#include "ConversionNum.h"	
#include "ConversionBCD.h"


//-- attribut --// 


//--> protected 
//--> private 

//-- prototype -> m�thode --//
//-> visibilit� 



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
ConversionBCD::ConversionBCD() : ConversionNumerique()
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
	if (choixCodage == valUser)
	{
		//-- cr�ation d'un tableau dynamique via pointeur --// 
		
		m_ptTbDigitEntier[m_nbrDigitMaxValEntier];
	
		//-- appel fonction : d�termine le nb de digit du nombre entier --//
		CalculerNbrDigitEntier(valUser);

		//-- appel fonction : r�cuperation de chaque digit --//
		RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		ConversionBinaire();
	}
	else
	{
		//ne fait rien 
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
	int valuser_transition;
	int cnt_digit = 0 ;

	valuser_transition = (int)valUser;

	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re

	do
	{
		//test si il y a un digit
		if ((valuser_transition % 10) != 0)
		{
			cnt_digit++;
			//suprimme le digit detect�
			valuser_transition = (valuser_transition / 10);
		}



	//tanque le nombre de digit n est pas totalement detect�
	} while (valuser_transition != 0);
	//-- fin de boucle -> �gal � 0

	//-- MAJ du membre parents -> nbrDigitEntier 
	m_nbrDigitMaxValEntier  = cnt_digit;

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
	int valuser_transition;
	int cnt_digit = 0;

	valuser_transition = (int)valUser;

	//-- it�ration pour remplire le tableau de digit --//

	for (size_t i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//recuperation du digite puis sauvegadre dans le tableau dans la case correspondnate

		m_ptTbDigitEntier[i] = (valuser_transition % 10) * 10;

		//mise a jour de la valeur enti�re a sauvegard�
		valuser_transition = (valuser_transition / 10);
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
	 m_ptTbBinaire[m_nbrDigitMaxValEntier];

	//-- d�claration de variable --//
	std::string Mot_bin = "default value";
	int ValueToConvert;


	//-- boucle d'it�ration pour pour chaque digit --// 

	for (size_t i = 0; i < m_nbrDigitMaxValEntier; i++)
	{
		//-- MAJ de la valeur � convertir --// 
		ValueToConvert = m_ptTbDigitEntier[1];

		// Utilisation de std::bitset pour convertir l'entier en binaire
		Mot_bin = std::bitset<sizeof(unsigned int) * 8>(ValueToConvert).to_string();

		//-- MAJ du tabelau string --// 
		m_ptTbBinaire[i] = Mot_bin;


	}
}