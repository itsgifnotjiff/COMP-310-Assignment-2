#include "pcb.h"

struct CPU 
{
	int IP ; 
	char IR[1000] ; 
	int quanta ;
} CPU;

struct readyQueue
{
	bool isEmpty;
	PCB *head ;
	PCB *tail ;
} readyQueue ;

bool isAvailable()
{
	if (CPU.quanta = 0 || readyQueue.isEmpty ) { return true; } else { return false; }
}
