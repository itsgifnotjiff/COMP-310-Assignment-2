#ifndef PCB_H
#define PCB_H

struct PCB 
{ 
	int PC ; 
	int start ; 
	int end ;
	struct PCB* next;
};

struct PCB* constructorPCB ( int start , int end ) ;
struct PCB* copyPCB ( struct PCB* source ) ;

#endif