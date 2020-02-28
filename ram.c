#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ram[1000];

int startInRam = 0;
int endInRam = 0;
int firstEmptyCell;

void addToRam(FILE*, int *start, int *end)
{
	FILE * program = fopen(FILE*, "r");
	
	int line_numbers = 0;
	char buffer[1000];
	while(fgets(buffer, 1000, program) != NULL)
	{
		line_numbers++;
	}
	for ( int i = 0 ; i < 1000 ; i++) 
	{
		if (ram[i] == NULL) { firstEmptyCell = i; break; }
	}
	*start = firstEmptyCell;
	rewind(program);
	int i = firstEmptyCell;
	while(fgets(buffer, 1000, program) != NULL)
	{
		ram[i] = strdup(buffer);
		i++;
	}

	*end = start + line_numbers;

}

void clearRam()
{
	for ( int i = 0 ; i < 1000 ; i++ )
	{
		if (ram[i] != NULL) 
		{free(ram[i]);}

		ram[i] = NULL;
	}
}

