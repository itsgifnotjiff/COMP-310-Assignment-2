#include "pcb.h"

PCB* makePCB(int start, int end)
{
	PCB* thispcb = (PCB*) (malloc(sizeof(PCB)));
	thispcb->start = start;
	thispcb->end = end;
	thispcb->next = NULL;
	thispcb->PC = start; 
	return thispcb;
}
