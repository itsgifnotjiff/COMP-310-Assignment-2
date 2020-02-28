char *ram[1000];

int startInRam = 0;
int endInRam = 0;

loadToRam(FILE*, int *start, int *end)
{
	program = fopen(FILE*, "r");
	
	int line_numbers = 0;
	while(fgets(buffer, 1000, program) != NULL)
	{
		line_numbers++;
	}
	int i = 0;
	while(fgets(buffer, 1000, program))
	{
		addToRam(buffer);
		ram[i] = strdup(buffer);
	}

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
