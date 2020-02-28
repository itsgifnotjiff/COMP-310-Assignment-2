an array of size 3 to hold the up to 3 programs

char *ram[1000];

loadToRam
{
	int startInRam = base;
	int counteroflines = 0;
	int endInRam;
	fopen(script)
	getNextCellRam()
	copyLinesToRam()
	endInRam= startInRam + counteroflines;

	helper
	{
		fgets(file,buffer,limit)
		ram[k] = strdup(buffer)
	}

	clearRam
	{
		for ( i=0 ; i < 1000 ; i++ )
		{
			ram[i] = NULL;
		}
	}



}
