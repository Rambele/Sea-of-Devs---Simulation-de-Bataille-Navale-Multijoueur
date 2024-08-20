#include <stdlib.h>
#include <stdio.h>
#include "navalmap.h"
#include "nm_rect.c"
#include "navalmap.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




int main(int argc ,char** argv)
{
		
	//creation des variable 
		printf("//Creeation des variables\n");
		map_t typeMap;
		coord_t tailMap;
		int nbShip,nbTour;
		int Cmax,Kmax;
		char charTailX[5];
		char charTailY[5];
		char charNbShip[5];
		char charTypeMap[10];
		char charCmax[5];
		char charKmax[5];
		char charNbTour[5];
	//=============================================
	
	
	//lire le fichier appel system argv[1]
		int fileD=open("RambelFile",O_RDONLY);
		if(fileD==-1)
			{
				printf("\n\tError file system !");
				return 0;
			}
	//==============================================
	
	
	//le fichier a etait ouvert correctement 
	//recuperer les information sous forme de chaine de caractères

		getInformationFile(fileD,charTypeMap,charTailX,charTailY,charNbShip,charCmax,charKmax,charNbTour);
	//==========================================================
		
	//Transormer les chaine en entier 
		
		
		tailMap.x=(int)atof(charTailX);
		tailMap.y=(int)atof(charTailY);
		nbShip=(int)atof(charNbShip);
		Cmax=(int)atof(charCmax);
		Kmax=(int)atof(charKmax);
		nbTour=(int)atof(charNbTour);
		if(!strcmp(charTypeMap,"MAP_RECT"))
				typeMap=MAP_RECT;
		else 
				typeMap=MAP_TOTAL;
		
	// Initialisation de la bibliothèque
		printf("// Initialisation de la bibliothèque\n");
		initNavalMapLib ();
	
		
	// Initialisation d'une carte navale
		printf("// Initialisation d'une carte navale\n");
		navalmap_t *np=init_navalmap(typeMap,tailMap,nbShip);
		placeRemainingShipsAtRandom(np);//PLACE LESNAVIRES RANDOM
		afficher_la_carte(np);
		printf("\n=============================\n\t\n");
		printf("Le type de map : %s\n",charTypeMap);
		printf("La tail x : %s\n",charTailX);
		printf("La tail y : %s\n",charTailY);
		printf("Le nombre de ships : %s\n",charNbShip);
		printf("Le Cmax :  : %s\n",charCmax);
		printf("Le Kmax : %s\n",charKmax);
		printf("Lenombre de tour : %s\n",charNbTour);
	
	return 0;
	
}
