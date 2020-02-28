

char *ram[1000];

int startInRam = 0;
int endInRam = 0;

loadToRam(FILE*, int *start, int *end)
{
	
	int counteroflines = 0;
	
	fopen(FILE*)
	getNextCellRam(){
	endInRam= startInRam + counteroflines;

}

void clearRam()
{
	for ( i=0 ; i < 1000 ; i++ )
	{
		if (ram[i] != NULL) 
		{free(ram[i]);}

		ram[i] = NULL;
	}
}

void copyLinesToRam()
{
	fgets(file,buffer,limit)
	ram[k] = strdup(buffer)
}
