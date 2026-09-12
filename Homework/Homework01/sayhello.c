#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {

   char name[100];

   printf( "What is your name? " );
   fgets( name, sizeof(name), stdin );

   printf( "Hello, %s!\n", name );

   return 0;
}