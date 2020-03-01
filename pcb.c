#include<stdio.h>
#include<stdlib.h>

struct PCB 
{ 
	int PC ; 
	int start ; 
	int end ; 
	struct PCB* next ;
};

struct PCB* constructorPCB ( int start , int end )
{
	struct PCB* thisPCB = (struct PCB*) malloc ( sizeof ( struct PCB ) ) ;
	thisPCB->PC = start ;
	thisPCB->start = start ;
	thisPCB->end = end ;
	thisPCB->next = NULL ;

	return thisPCB ;
}

struct PCB* copyPCB ( struct PCB*source ) 
{
	struct PCB* copy = (struct PCB*) malloc (sizeof ( struct PCB ) ) ;
	copy->PC = source->PC ;
	copy->start = source->start ;
	copy->end = source->end ;
	copy->next = NULL ;
	return copy ;
}