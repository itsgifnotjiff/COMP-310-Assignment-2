#include "pcb.h"

struct CPU 
{
	int IP ; 
	char IR[1000] ; 
	int quanta ;
} CPU;



bool isAvailable()
{
	if (CPU->quanta == 0 || readyQueue->head == NULL ) { return true; } else { return false; }
}
