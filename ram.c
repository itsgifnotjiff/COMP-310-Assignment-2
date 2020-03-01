#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ram[1000];

int getNextAvailableCell() ;
int getLastAvailableCell( int start ) ; 

void addToRam(FILE *p, int *start, int *end)
{
	*start = getNextAvailableCell() ;

	if ( *start == -1 )
	{
		return;
	}

	*end = getLastAvailableCell( *start ) ;

	if ( *end == -1 )
	{
		return;
	}

	char line[1000] ;
	fgets( line , 999 , p ) ;
	int i = *start ;

	while( !feof( p ) )
	{
		if ( i > *end )
		{
			clearRam() ;
			*end = -1 ;
			fclose( p ) ;
			return ;
		}
		ram[i] = strdup( line ) ;
		fgets( line , 999 , p ) ;
		i++ ;
	}
		*end = i - 1 ;
		fclose( p ) ;
}

void removeFromRam( int start , int end)
{
	for( int i = start ; i <= end ; i++ )
	{
		ram[i] = NULL;
	}
}

void clearRam()
{
	for ( int i = 0 ; i < 1000 ; i++ )
	{
		if ( ram[i] != NULL )  
		{ free( ram[i] ) ; }

		ram[i] = NULL;
	}
}

int getLastAvailableCell( int start )
{
	for( int i = start ; i < 1000 ; i++ )
	{
		if( ram[i] != NULL )
		{
			return i - 1 ;
		} else if ( ram[i] == NULL && i == 999 )
		{
			return i;
		}
	}

	return -1;
}


int getNextAvailableCell()
{
	for( int i = 0 ; i < 1000 ; i++ )
	{
		if( ram[i] == NULL )
		{
			return i;
		}
	}
	return -1;
}
