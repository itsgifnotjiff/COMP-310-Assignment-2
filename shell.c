#include "interpreter.h"
#include "shellmemory.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    printf("Welcome to the Yordan Radev shell!\n"
           "Version 2.0 Created February 2020\n");

    shell_memory_initialize();

    while (!feof(stdin))
    {
        printf("$ ");
        fflush(stdout);

        char *line = NULL;
        size_t linecap = 0;
        if (getline(&line, &linecap, stdin) == -1)
            break;

        (void)interpreter(line);
        free(line);
    }

    shell_memory_destory();

    return 0;
}

int parse(char userInput[])
{
	char temp[200];
	char* words[100];

	int a,b;
	int numberWords = 0;

	for( a = 0 ; userInput[a] == ' ' && a < 1000; a++);

	while(userInput[a] != '\0' && a < 1000){
		for( b = 0 ; userInput[a] != '\0' && userInput[a] != ' ' && userInput[a] != '\n' && a < 1000; a++, b++)
        {
			temp[b] = userInput[a];
		}

		temp[b] = '\0';

		words[numberWords] = strdup(temp);
		a++;
		numberWords++;
	}

	return interpreter(words, numberWords);
}


int shellUI(void) {
	char prompt[100] = {'$','\0'};
	char userInput[1000];
	int errorCode = 0;

    printf("Welcome to the Yordan Radev shell!\n"
           "Version 2.0 Created February 2020\n");	
    while(1)
    {
		printf( "%s " , prompt ) ;
		fgets( userInput , 999 , stdin ) ;
		errorCode = parse( userInput ) ;
		if( errorCode == -1 )
        {
			exit( 99 ) ;

		} else if ( errorCode == 1 ) 
        {
			printf( "Error 1 : Unknown command. Use 'help' for more details\n" ) ;

		} else if ( errorCode == 2 )
        {
			printf( "Error 2 : Variable does not exist!\n" ) ;

		} else if ( errorCode == 3 ) 
        {
			printf( "Error 3 : Script not found\n" ) ;

		} else if ( errorCode == 4 )
        {
			printf( "Error 4 : Shell memory is full!\n" ) ;

		} else if ( errorCode == 5 ) 
        {
			printf( "Error 5 : No variable provided\n" ) ;

		} else if ( errorCode == 6 ) 
        {
			printf( "Error 6 : No value provided\n" ) ;

		} else if ( errorCode == 7 ) 
        {
			printf( "Error 7 : Command 'exec' takes between 1 and 3 arguments\n" ) ;

		} else if ( errorCode == 8 )
        {
			printf( "Error 8 : Not enough memory space in RAM\n" ) ;
		}
	}

	return EXIT_SUCCESS;
}
