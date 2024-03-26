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
#include <string>				// pour la m�thode conversion binaire

//-- librairie personnelle --// 
#include "ConversionBCD.h"
#include "ConversionNum.h"

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
	if (choixCodage == BCD)
	{
		int* m_ptTbDigitEntier[] = { 0 };
		int* m_nbrDigitMaxValEntier[] = { 0 };

		CalculerNbrDigitEntier(valUser);
		RecupererDigitEntier(valUser);
		ConversionBinaire(valUser);
	}
	std::cout << "Constructeur de Rectangle" << std::endl;
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

void ConversionBDC()
{
	int tbdynamique[100] = { 0 };
	//-- test le choixCodage correspond � l'�num�ration BCD 
	if (choixCodage = BCD)
	{
		

	}
}
		//-- cr�ation d'un tableau dynamique via pointeur --// 
	
	
		//-- appel fonction : d�termine le nb de digit du nombre entier --//
		

		//-- appel fonction : r�cuperation de chaque digit --//


		//-- appel fonction : conversion binaire de chaque digit entier --// 
			





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


	//-- d�claration de variables --// 
	void ConversionNumerique(float valUser)
	{
		while (valUser != 0)
		{

		}

	}

	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re
	//-- fin de boucle -> �gal � 0


		//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
		//-- et MAJ de la valeur enti�re
		

		//-- MAJ du Digit => incr�ment de 1 --//
		


	//-- MAJ du membre parents -> nbrDigitEntier 





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
void RecupererDigitEntier(float valUser)
{
	int i;
	int taille = 0; 

	while (valUser != 0)
	{
		if (isdigit(valUser))
		{
			std::cout << "";
		}
	}
}

//-- d�claration variable --// 

	 
	//-- it�ration pour remplire le tableau de digit --//

	 
		//-- MAJ facteur de puissance de 10 --// 
		

		//-- MAJ TAbleau -> digit 
		

		//-- MAJ valeur utilisateur 
		
	



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

void ConversionBinaire(int valAConv, char(&ptTbDigitEntier)[100])
{
	char binaireInverse[100] = { 0 } // binaireInverse: 00000 0000
	int index = 0;

		// commentaires: example pour valAConv = 6
		while (valAConv != 0)
		{
			binaireInverse[index] = valAConv % 2;  //octal modulo 8

			valAConv = valAConv >> 1;  // divison par deux
			//valAConv = valAConv / 2; // version alternative  //octal division par 8

			index++;
		}

	std::string binaire = ""; // Initialisez une cha�ne de caract�res pour stocker le r�sultat binaire

			
