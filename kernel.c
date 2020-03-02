#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "ram.h"
#include "pcb.h"
#include "cpu.h"

struct PCB* head = NULL;
struct PCB* tail = NULL;

void enqueue( struct PCB* thisNode )
{
	thisNode->next = NULL ;
	tail->next = thisNode ;
	tail = thisNode ;
}

struct PCB* dequeue()
{
	struct PCB *node = head ;
	head = node->next ;
	node->next = NULL ;
	return node ;
}

void addToReady(struct PCB* thisPCB )
{
	if( head == NULL )
	{
		tail = thisPCB ;
		head = thisPCB ;

	} else
	{
		thisPCB->next = NULL ;
		tail->next = thisPCB ;
		tail = thisPCB ;
	}
}

int scheduler()
{
	int errorCode = 0;

	while(head != NULL)
	{
		if(!isAvailable)
		{
			CPU.IP = head->PC ;
			int linesLeft = head->end - head->PC + 1 ;

			if( linesLeft <= CPU.quanta )
			{
				errorCode = run( linesLeft ) ;
				if(errorCode == 0)
				{
					removeFromRam(head->start,head->end) ;
					head->PC += linesLeft ;
					struct PCB* temp = dequeue() ;
					free(temp) ;

				} else 
				{
					clearRam() ;
					return errorCode ;
				}
			} else
			{
				errorCode = run( CPU.quanta ) ;
				if( errorCode == 0 )
				{
					head->PC += CPU.quanta ;
					struct PCB* temp = copyPCB(head) ;
					enqueue(temp) ;
					head = head->next ;
				} else
				{
					clearRam() ;
					return errorCode ;
				}
			}
		}
	}

	return errorCode;
}

int myinit(char *fileName)
{
	int errorCode = 0 ;
	FILE *p = fopen( fileName, "r" ) ;
	int start ;
	int end ;

	if( p == NULL )
	{
		errorCode = 3 ;
		return errorCode ;
	}

	addToRam( p , &start , &end ) ;

	if ( start == -1 || end == -1 )
	{
		errorCode = 8 ;
		return errorCode ;
	}

	struct PCB* thisPCB = constructorPCB ( start , end ) ;
	addToReady ( thisPCB ) ;
	return 0 ;
}

int main( void )
{
	head = NULL ;
	tail = NULL ;
	CPU.quanta = 2 ;
	shellUI() ;
}
