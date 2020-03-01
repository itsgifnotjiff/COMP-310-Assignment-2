#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
#include "shell.h"
#include "ram.h"


volatile int isAvailable;

// c. It calls the run(quanta) function within cpu.c to run the script by copying quanta
// lines of code from ram[] using IP into the IR, which then calls: interpreter(IR)

int run( int quanta)
{
	int errorCode = 0 ;
	isAvailable = 1 ;

	for( int i = 0 ; i < quanta ; i++ )
	{
		strcpy( CPU.IR , ram[CPU.IP] ) ;
		CPU.IP += 1 ;

		if( strcmp( CPU.IR , "quit\n" ) == 0 )
		{
			isAvailable = 0 ;
			return 0 ;
		}
		errorCode = parse( CPU.IR ) ;

		if( errorCode != 0 )
		{
			isAvailable = 0 ;
			return errorCode ;
		}
	}
	isAvailable = 0 ;
	return errorCode ;
}
