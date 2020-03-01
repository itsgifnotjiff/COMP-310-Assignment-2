#ifndef RAM_H
#define RAM_H

void addToRam( FILE*, int *start, int *end ) ;
void removeFromRAM( int start, int end ) ;
void clearRAM() ;
extern char *ram[1000] ;

#endif