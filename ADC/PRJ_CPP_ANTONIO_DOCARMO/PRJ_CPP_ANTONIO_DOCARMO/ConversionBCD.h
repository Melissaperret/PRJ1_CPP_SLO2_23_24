//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: ConversionBCD.h
// Date de cr�ation 	: 11.03.2024
// Date de modification : 25.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			: si h�ritage <=> attention la visibilit� de la class parent 
//						  doit aussi figurer !!!          
//----------------------------------------------------------------------------------//
#ifndef CONV_BCD
#define CONV_BCD

//-- librairie standart --//

#include <iostream>

//-- librairie personnelle --// 
#include "ConversionNum.h"


class ConversionBCD 
{
		

		//-- attribut --// 
		//-> visibilit� 
		//--> public
		public: 

			ConversionNumerique::e_codageBinaire choixCodage;		//choixCodage de type e_codageBinaire
			new tabDyn[m_ptTbDigitEntier];
			
			//new tbDyn[m_nbrDigitMMaxValEntier];		//Pas au bon endroit

		//--> protected 
		//--> private 
		private:

			float valUser;		//valUser de type float


		//-- prototype -> constructeur --//
		//-> visibilit� 
		//--> public
		public:

			ConversionBCD(); //Constructeur g�rite de ConversionNumerique
		//--> protected 
		//--> private 

		

		

		



		//-- prototype -> destructeur --//
		//-> visibilit� 
		//--> public
		 public:
			 ~ConversionBCD();

		//--> protected 
		//--> private 



		//-- prototype -> m�thode --//
		//-> visibilit� 
		//--> public 
		 public:
			 void CalculerNbrDigitEntier(float valUser);	//Declaration methode CalculerNbrDigitEntier param�tre valUser
			 void RecupererNbDigitEntier(float valUser);	//Declaration methode RecupererNbDigitEntier param�tre valUser
			 void ConversionBinaire(void);
			 ConversionBCD(float valUser, ConversionNumerique::e_codageBinaire choixCodage);
			 
		//--> protected
		//--> private
		private:

			







};

#endif // !CONV_NUM


