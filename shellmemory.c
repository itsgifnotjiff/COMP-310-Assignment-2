#include "shellmemory.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MEM
{
	char *var;
	char *value;
}shellMemory[1000];

int size = 0;

int match( char* memory , char* variable )
{
	int length = strlen( variable ) ;
    int matchCount = 0 ; 

	for( int i = 0 ; i < length ; i++ ) 
    {
		if ( *(memory+i) == *( variable + i ) ) matchCount++ ;
	}
	if (matchCount == length)
    {
		return 1 ;

	} else 
    {
		return 0 ;
	}
}

char* getVariable(char* variable)
{
	if( size == 0 || variable == NULL )
    {
		return "Variable does not exist";
	}

	for( int i = 0 ; i < size ; i++ )
    {
		if( match( shellMemory[i].var , variable))
        {
			char* value = strdup( shellMemory[i].value ) ;
			return value ;
		}
	}
	return "Variable does not exist";
}

int setValue(char* variable, char* value) 
{
	if( shellMemory[0].var == NULL )
    {
		shellMemory[0].var = strdup( variable ) ;
		shellMemory[0].value = strdup( value ) ;
		size++ ;
		return 0 ;
	}

	for( int i = 0 ; i < size ; i++ )
    {
		if ( match( shellMemory[i].var , variable ) ) 
        {
			shellMemory[i].value = strdup(value);
			return 0;
		}
	}
	if( size == 1000 )
    {
		return 4 ;

	} else
    {
		shellMemory[size].var = strdup( variable ) ;
		shellMemory[size].value = strdup( value ) ;
		size++ ;
		return 0 ;
	}
}