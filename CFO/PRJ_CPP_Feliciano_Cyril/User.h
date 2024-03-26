//-----------------------------------------------------------------------------------//
// Nom du projet 		: Conversion Num�rique 
// Nom du fichier 		: User.h
// Date de cr�ation 	: 08.03.2024
// Date de modification : 22.03.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : ce programme est reli� au projet n�1 C++ - SLO2
//
// Remarques			:            
//----------------------------------------------------------------------------------//
#ifndef CLASS_USER
#define CLASS_USER 

#include "ConversionNum.h"

class user
{
	//-- attribut --// 
	//-> visibilit� 
	public : 
		enum e_MsgInfo : int {message1, message2, message3, message4};		
		ConversionNumerique* pt_ObjetConversion;							//-- objet de conversion 
	
	protected :  
		float valUser_m;

	private : 
		const short CST_VAL_LIMIT_MAX; 
		const short CST_VAL_LIMIT_MIN; 


	//-- prototype -> constructeur 
	//-> visibilit� 
	public : 
		user(short limitmax, short limitmin); 
	
	//-- prototype -> m�thode --//
	//-> visibilit� 
	public :
		void AfficherMsgUser(e_MsgInfo msg);							// affichage de diff�rents msg � l'utilisateur 
		void AfficherValConvertie(ConversionNumerique *objAConvertir);	// affiche la valeur de conversion num�rique selon les param�tres de l'utilisateur 
		float GetNumberValue();											// prend un valeur (attribut) pour la donner � l'ext�rieur 
		float SetNumberValue();											// r�cup�re une valeur num�rique (entier ou r�el) de l'ext�rieur 
		bool ValiderValUser(float valATester);							// valide une valeur num�rique (selon CDC)

};



#endif // !CLASS_USER
