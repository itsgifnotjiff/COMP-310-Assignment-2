#include "interpreter.h"
#include "shellmemory.h"
#include "kernel.h"
#include "shell.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>


static int run( char* program );

int print( char* argument[] , int numberArgs )
{
	int errorCode = 0 ;
	if( numberArgs == 1 || strcmp( argument[1] , "\0" ) == 0 )
    {
		errorCode = 5 ;
		return errorCode ;
	}
	char* var = argument[1] ;
	char* value = getVariable( var ) ;
	if(strcmp( value , "Variable does not exist" ) == 0 )
    {
		errorCode = 2;
	} else 
    {
		printf( "%s = %s\n" , var , value ) ;
	}
	return errorCode;
}

int set(char* argument[], int numberArgs)
{
	int errorCode = 0;
	if( numberArgs == 1 || strcmp( argument[1] , "\0" ) == 0 )
    {
		errorCode = 5 ;
		return errorCode ;
	}
	if ( numberArgs == 2 || strcmp( argument[2] , "\0" ) == 0 )
    {
		errorCode = 6 ;
		return errorCode ;
	}
	errorCode = setValue( argument[1] , argument[2] ) ;
	return errorCode ;
}

int quit()
{
	printf("Ciao!\n");
	return -1;
}

int help()
{
	printf( "\n\tmyshell man page"
            "\n"
            "\nCOMMAND\tDESCRIPTION"
            "\nhelp\tDisplays all the commands"
            "\nquit\tExits / terminates the shell with Bye!"
            "\nset VAR STRING\tAssigns a value to shell memory"
            "\nprint VAR\tDisplays the STRING assigned to VAR"
            "\nrun SCRIPT.TXT\tExecutes the file SCRIPT.TXT"
			"\nexec p1 p2 p3\tExecutes concurrent programs\n");
	return 0;
}
int exec( char* argument[] , int numberArgs )
{
	int errorCode = 0 ;
	int sameProgram = 0 ;
	char* program ;

	if ( numberArgs < 2 || numberArgs > 4 )
	{
		errorCode = 7 ;
		return errorCode ;
	}

	if ( numberArgs == 3 )
	{
		if( strcmp( argument[1] , argument[2]) == 0 )
		{
			sameProgram = 2 ;
			program = argument[2] ;
		}
	}

	if ( numberArgs == 4 )
    {
		if ((strcmp(argument[1], argument[3]) == 0) && (strcmp(argument[2], argument[3]) == 0))
		{
			sameProgram = -1 ;
			program = argument[1] ;

		} else if (strcmp(argument[1], argument[3]) == 0)
        {
			sameProgram = 3;
			program = argument[1];

		} else if (strcmp(argument[2], argument[3]) == 0 )
        {
			sameProgram = 3;
			program = argument[3];

		} else if ( strcmp(argument[1], argument[2]) == 0)
        {
			sameProgram = 2;
			program = argument[1];
		}
	}

	for( int i = 0 ; i < numberArgs - 1 ; i++ )
    {
		if ( sameProgram != 0 && i == sameProgram - 1 )
        {
			continue ;

		} else
        {
			errorCode = myinit( argument[ i+1 ] ) ;
			if ( errorCode != 0 )
            {
				return errorCode;
			}
		}
		if( sameProgram == -1 )
        {
			break;
		}
	}

	errorCode = scheduler() ;

	if( sameProgram == -1)
	{
		printf ( "Error: Script %s already loaded\n" , program ) ;

	} else if (sameProgram != 0)
	{
		printf ( "Error: Script %s already loaded\n" , program ) ;
	}
	return errorCode;
}

static int run(char* program)
{
	int errorCode = 0 ;
	char program_line[1000] ;
	FILE *p = fopen( program , "r" ) ;

	if( p == NULL )
	{
		errorCode = 3 ;
		return errorCode ;
	}

	fgets( program_line , 999 , p ) ;

	while( !feof(p) )
	{
		if( strcmp ( program_line , "quit\n" ) == 0 ) break ;
		errorCode = parse( program_line ) ;
		if( errorCode != 0 )
		{
			fclose(p) ;
			return errorCode = interpreter(parse(program_line), 1);
		}

		//interpreter(parse(program_line), 1);

		fgets( program_line , 999 , p ) ;
	}

	fclose(p) ;

	return errorCode ;
}

int interpreter(char* command[], int numberArgs )
{
	int errorCode = 0;

	if ( strcmp( command[0] , "help" ) == 0)
    {
		errorCode = help();

	} else if( strcmp( command[0] , "quit" ) == 0 )
    {
		errorCode = quit() ;

	} else if ( strcmp( command[0] , "set" ) == 0 )
    {
		errorCode = set( command , numberArgs ) ;

	} else if ( strcmp( command[0] , "print" ) == 0 )
    {
		errorCode = print( command , numberArgs ) ;

	} else if ( strcmp( command[0] , "run" ) == 0 )
    {
		errorCode = run( command[1] ) ;

	} else if ( strcmp( command[0] , "exec" ) == 0 )
    {
		errorCode = exec( command , numberArgs ) ;

	} else 
    {
		errorCode = 1;
	}

	return errorCode;
}
