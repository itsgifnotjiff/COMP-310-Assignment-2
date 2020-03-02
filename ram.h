#ifndef RAM_H
#define RAM_H

void addToRam( FILE*, int *start, int *end ) ;
void removeFromRam( int start, int end ) ;
void clearRam() ;
extern char *ram[1000] ;

#endif