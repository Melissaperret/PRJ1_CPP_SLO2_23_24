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


//-- librairie personnelle --// 


class ConversionBCD : public ConversionNumerique
{
		//-- attribut --// 
		//-> visibilit� 
		//--> public
public: 
	char* tabDynamique[2];
		//--> protected 
		//--> private 

		//-- prototype -> constructeur --//
		//-> visibilit� 
		//--> public
public:
		ConversionBCD();

		ConversionBCD(e_codageBinaire choixCodage, float valUser);

	
		//-- attributs --//

	

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
		//--> protected
		//--> private
private:
	void CalculerNbrDigitEntier(float valUser);
	
	void RecupererDigitEntier(float valUser);

	void ConversionBinaire();

};

#endif // !CONV_NUM


