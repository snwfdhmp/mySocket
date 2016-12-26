#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_NUMBER_CLONE 1
#define COMMAND_NUMBER_UPDATE 2
#define COMMAND_NUMBER_QUIT 3
#define COMMAND_NUMBER_NOASSIGN 0
#define COMMAND_NUMBER_ERROR 666

//DECLARATION DE FONCTIONS
char* readFile(char* filename);
int getCommandNumberFromString(char* string);
int commandClone();
int commandUpdate();
int commandQuit();
int makeActionFromCommandNumber(int commandNumber);



//STORYLINE
int main() {
	char commandInput[255];
	while(1) {
		printf("$ ");
		scanf("%s", commandInput);
		makeActionFromCommandNumber(getCommandNumberFromString(commandInput));
	}
	return 0;
}


//INPUT TREATMENT
int getCommandNumberFromString(char* string) {
	if (strcmp(string, "clone") == 0) {
		return COMMAND_NUMBER_CLONE;
	}
	else if (strcmp(string, "update") == 0){
		return COMMAND_NUMBER_UPDATE;
	}
	else if (strcmp(string, "quit") == 0){
		return COMMAND_NUMBER_QUIT;
	}
	else {
		return COMMAND_NUMBER_ERROR;
	}
}



//COMMAND
int commandClone() {
	printf("Clonage ....\n");
	char* content = readFile("commandInterpret");
	printf("Cloné dans :\n");
	int i = 1;
	while(i <= 10) {
		char fileName[150];
		sprintf(fileName, "clone%d", i);
		FILE* toWrite = fopen(fileName, "w+");
		fprintf(toWrite, "%s", content);
		printf("[%d] - %s\n", i, fileName);
		fclose(toWrite);
		i++;
	}
}
int commandUpdate() {
	printf("Mise à jour ...\n");
}
int commandQuit() {
	printf("A bientot !\n");
	exit(0);
}


//DIRECTIVE FUNCTION 
int makeActionFromCommandNumber(int commandNumber) {	
		switch(commandNumber) {
			case COMMAND_NUMBER_CLONE:
				commandClone();
			break;
			case COMMAND_NUMBER_UPDATE:
				commandUpdate();
			break;
			case COMMAND_NUMBER_QUIT:
				commandQuit();
			break;
			default :
			break;
		}
}

char* readFile(char* filename)
{
    FILE* fichier = fopen(filename,"r");
    int c;
    char content[1000000];
	while(1)
   {
      c = fgetc(fichier);
      if( feof(fichier) )
      { 
         break ;
      }
      sprintf(content, "%s%c",content, c);
   }
   return content;
}