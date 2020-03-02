#include "interpreter.h"
#include "shellmemory.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int parse(char userInput[])
{
	char temp[200];
	char* words[100];

	int start,end;
	int numberArgs = 0;

	for( start = 0 ; userInput[start] == ' ' && start < 1000 ; start++ ) ;

	while( userInput[start] != '\0' && start < 1000 )
    {
		for( end = 0 ; userInput[start] != '\0' &&  userInput[start] != '\n' && userInput[start] != ' ' && start < 1000; start++, end++)
        {
			temp[end] = userInput[start];
		}

		temp[end] = '\0';

		words[numberArgs] = strdup(temp);
		start++;
		numberArgs++;
	}

	return interpreter(words, numberArgs);
}


int shellUI(void) 
{
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
			printf( "Error 2 : Variable does not exist \n" ) ;

		} else if ( errorCode == 3 ) 
        {
			printf( "Error 3 : Script does not exist \n" ) ;

		} else if ( errorCode == 4 )
        {
			printf( "Error 4 : Shell memory is full!\n" ) ;

		} else if ( errorCode == 5 ) 
        {
			printf( "Error 5 : No variable input\n" ) ;

		} else if ( errorCode == 6 ) 
        {
			printf( "Error 6 : No value input\n" ) ;

		} else if ( errorCode == 7 ) 
        {
			printf( "Error 7 : 'exec' expects between 1 and 3 arguments \n" ) ;

		} else if ( errorCode == 8 )
        {
			printf( "Error 8 : Insufficient RAM \n" ) ;
		}
	}

	return EXIT_SUCCESS;
}
