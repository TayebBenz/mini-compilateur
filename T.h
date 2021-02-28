#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>





typedef struct chain{
	struct chain * next;
	char * name;
	char * entity;
	char * type;
	char * value;
	float f_value;
	int max_index;
}chain;

typedef struct tableau{

	char * ptr;
	struct tableau * next;

}tableau;



	chain * tete_KW = NULL;
	chain * tete_SP= NULL;
	chain * tete_IDF= NULL;
	chain * ptr;



void update(char* name, char* value)
{
	while(ptr != NULL )
	{
		if(strcmp(ptr->name,name)==0)
		{
			ptr->value = malloc(sizeof(char)*strlen(value));
			strcpy(ptr->value,value);
			return;
		}
		ptr=ptr->next;
	}
	return;
}

bool recherche(char * name, char * type , chain * ptr)
{
	if(ptr == NULL)
	{
		return false;
	}
	if(strcmp(ptr->name,name)==0 && strcmp(ptr->type,type)==0)
	{
		return true;
	}

	return recherche(name,type,ptr->next);
}

int recherche_max_index(char * name)
{
	ptr = tete_IDF;
	while(ptr != NULL )
	{
		if(strcmp(ptr->name,name)==0)  //&& strcmp(ptr->type,type)==0
		{
			return ptr->max_index;
		}
		ptr=ptr->next;
	}
	return -1;


}

bool recherche_syn(char * name) //,char * type
{
	ptr = tete_IDF;
	while(ptr != NULL )
	{
		if(strcmp(ptr->name,name)==0)  //&& strcmp(ptr->type,type)==0
		{
			return true;
		}
		ptr=ptr->next;
	}
	return false;



}

char *recherche_type(char * name) //,char * type
{
	ptr = tete_IDF;
	while(ptr != NULL )
	{
		if(strcmp(ptr->name,name)==0)  //&& strcmp(ptr->type,type)==0
		{
			return ptr->type;
		}
		ptr=ptr->next;
	}
	return NULL;

}

bool compatible(char * first,char *second)
{
	char *type1;
	char *type2;
	type1 = recherche_type(first);
	type2 = recherche_type(second);
	if(!strcmp(type1,"FLOAT"))
	{if(!strcmp(type2,"FLOAT") || !strcmp(type2,"INT")){return true;}printf("%s",type1);
	return false;
	}else{if(!strcmp(type1,type2)){return true;}
	printf("%s",type1);return false;}
}

void insert_tab(char * name,char * type,char * entity, int index){


	if(strcmp(entity,"TAB")== 00)
		{if(!recherche(name,type,tete_IDF))
			{
				ptr = (chain*)malloc(sizeof(chain));
				ptr->name = malloc(sizeof(char)*strlen(name));
				ptr->type = malloc(sizeof(char)*strlen(type));
				ptr->entity = malloc(sizeof(char)*strlen(entity));
				ptr->max_index = index;
				strcpy(ptr->entity,entity);
				strcpy(ptr->name,name); strcpy(ptr->type,type) ;
				ptr->next = tete_IDF;tete_IDF = ptr;
				
			}
		}

}

void insert(char * name,char * type,char * entity){


	if(strcmp(entity,"CONST")==0)
	{ 	if(!recherche(name,type,tete_IDF))
		{
			ptr = (chain*)malloc(sizeof(chain));
			ptr->name = malloc(sizeof(char)*strlen(name));
			ptr->type = malloc(sizeof(char)*strlen(type));
			ptr->value = malloc(sizeof(char)*strlen(name));
			ptr->entity = malloc(sizeof(char)*strlen(entity));
			strcpy(ptr->entity,entity);
			strcpy(ptr->name,name); strcpy(ptr->type,type);strcpy(ptr->value,name) ;
			ptr->next = tete_IDF;tete_IDF = ptr;
		}
	}
	else {
		if(strcmp(entity,"IDF")== 00)
		{if(!recherche(name,type,tete_IDF))
			{
				ptr = (chain*)malloc(sizeof(chain));
				ptr->name = malloc(sizeof(char)*strlen(name));
				ptr->type = malloc(sizeof(char)*strlen(type));
				ptr->entity = malloc(sizeof(char)*strlen(entity));
				strcpy(ptr->entity,entity);
				strcpy(ptr->name,name); strcpy(ptr->type,type) ;
				ptr->next = tete_IDF;tete_IDF = ptr;
			}
		}
		else if(strcmp(entity,"TAB")== 00)
		{if(!recherche(name,type,tete_IDF))
			{
				ptr = (chain*)malloc(sizeof(chain));
				ptr->name = malloc(sizeof(char)*strlen(name));
				ptr->type = malloc(sizeof(char)*strlen(type));
				ptr->entity = malloc(sizeof(char)*strlen(entity));
				strcpy(ptr->entity,entity);
				strcpy(ptr->name,name); strcpy(ptr->type,type) ;
				ptr->next = tete_IDF;tete_IDF = ptr;
			}
		}
		else if(strcmp(entity,"SEPARATOR")==0)
		{
			if(!recherche(name,type,tete_SP))
			{
			ptr = (chain*)malloc(sizeof(chain));
			ptr->name = malloc(sizeof(char)*strlen(name));
			ptr->type = malloc(sizeof(char)*strlen(type));
			ptr->entity = malloc(sizeof(char)*strlen(entity));
			strcpy(ptr->entity,entity);
			strcpy(ptr->name,name); strcpy(ptr->type,type);
			ptr->next = tete_SP;tete_SP = ptr;
			}

		}else{
			if(!recherche(name,type,tete_KW))
			{
			ptr = (chain*)malloc(sizeof(chain));
			ptr->name = malloc(sizeof(char)*strlen(name));
			ptr->type = malloc(sizeof(char)*strlen(type));
			ptr->entity = malloc(sizeof(char)*strlen(entity));
			strcpy(ptr->entity,entity);
			strcpy(ptr->name,name); strcpy(ptr->type,type) ;
			ptr->next = tete_KW;tete_KW = ptr;
			}
		}



}

}



void affich()
{

//printf("/********************Table des symboles IDF*************/\n");
//printf("*****************************************************************\n");
//printf("*                         TABLE DES SYMBOLE                     *\n");
//printf("*****************************************************************\n");
printf("/**********************Table des symboles IDF********************/\n");
//printf("*       TYPE          *        NAME         *       VALUE       *\n");
//printf("*****************************************************************\n");
	ptr = tete_IDF;
	while(ptr != NULL)
	{
	printf("nom:%s entity:%s type:%s VALUE: %s",ptr->name,ptr->entity,ptr->type,ptr->value);

	ptr=ptr->next;
	printf("\n");
	}

// printf("/********************Table des symboles SEPARATOR********************/\n");
// 	ptr = tete_SP;
// 	while(ptr != NULL)
// 	{
// 	printf("nom:%s entity:%s type:%s\n",ptr->name,ptr->entity,ptr->type);
// 	ptr=ptr->next;
// 	}
// printf("/********************Table des symboles KEYWORDS********************/\n");
// 	ptr = tete_KW;
// 	while(ptr != NULL)
// 	{
// 	printf("nom:%s entity:%s type:%s\n",ptr->name,ptr->entity,ptr->type);
// 	ptr=ptr->next;
	// }




}
