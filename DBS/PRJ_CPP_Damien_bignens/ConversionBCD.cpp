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

ConversionBCD::ConversionBCD(e_codageBinaire choixCodage, float valUser)
{

	//-- test le choixCodage correspond � l'�num�ration BCD 
	if (choixCodage == ConversionNumerique::e_codageBinaire::BCD)
	{
		//-- cr�ation d'un tableau dynamique via pointeur --// 
		ConversionNumerique::m_ptTbDigitEntier [ConversionNumerique::m_nbrDigitMaxValEntier] ;
	
		//-- appel fonction : d�termine le nb de digit du nombre entier --//
		this->CalculerNbrDigitEntier(valUser);

		//-- appel fonction : r�cuperation de chaque digit --//
		this->RecupererDigitEntier(valUser);

		//-- appel fonction : conversion binaire de chaque digit entier --// 
		this->conversionBinaire();

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
	char valtestuser = valUser;
	char nbdigitetest = 0 ;
	//-- it�ration pour connaitre le nbr de digit sur une valeur enti�re

	while (valtestuser != 0 )
	//-- fin de boucle -> �gal � 0
	{
		
		valtestuser = valtestuser / 10;//-- division de la valeur enti�re par des puissance de 10 : 10^0 => (1), 10^1 => (10), 10^2 => (100) ..
									   //-- et MAJ de la valeur enti�re
		nbdigitetest++;					//-- MAJ du Digit => incr�ment de 1 --//
	} 


	//ConversionNumerique::m_ptTbDigitEntier = &nbdigitetest;


	//-- MAJ du membre parents -> nbrDigitEntier 
	ConversionNumerique::m_nbrDigitMaxValEntier = nbdigitetest;
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
	char contdigit = 0; 
	char valtestUser = 0;
	//-- it�ration pour remplire le tableau de digit --//
	while (contdigit <= ConversionNumerique::m_nbrDigitMaxValEntier)
	{
		
		valtestUser = valUser /  pow(10, ConversionNumerique::m_nbrDigitMaxValEntier - (contdigit+1));//-- MAJ facteur de puissance de 10 --// 
		
		valtestUser = valtestUser % 10;	
		//-- MAJ TAbleau -> digit 
		ConversionNumerique::m_ptTbDigitEntier[contdigit] = valtestUser; //pour mettre dans le tableaux ( faux)
		contdigit++; 
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
void ConversionBCD::conversionBinaire()
{

	//-- Creation du tableau dynamique de string en fct des digit entier --// 
	ConversionNumerique::m_ptTbBinaire[ConversionNumerique::m_nbrDigitMaxValEntier];

	//-- d�claration de variable --//
	int i = ConversionNumerique::m_nbrDigitMaxValEntier; 
	char valeaCouvertir = 0; 
	std::string binaryString = "";
	int hexsadesimaldigite  = 4 ;
	//-- boucle d'it�ration pour pour chaque digit --// 
	for (i ; i >= 0 ; i--)
	{ 
		//-- r�cup�re la valeur du digit � convertir --// 
		valeaCouvertir = ConversionNumerique::m_ptTbDigitEntier[i];
		
		//-- it�ration de conversion binaire --// 	

			//-- conversion binaire -> modulo 2 (r�cup�re le reste) --//
		for (hexsadesimaldigite - 1; hexsadesimaldigite >= 0; hexsadesimaldigite--)
		{
			//-- r�cuperation de l'info binaire --//
			// Ajoute 1 ou 0 au string en fonction de la valeur du LSB
			ConversionNumerique::m_ptTbBinaire[i] += ((valeaCouvertir & (1 << i)) != 0) ? "1" : "0";
		}
			
			//-- MAJ de la valeur � convertir --// 
			
			
			//-- MAJ du tabelau string --// 
	}

}

