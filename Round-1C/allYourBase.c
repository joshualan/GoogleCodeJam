/*
  Created by Alan Estrada

  This program is for the Google Code Jam 2009 1C, All Your Base. It can be
  found here:
  https://code.google.com/codejam/contest/189252/dashboard#s=p0

*/

#include <stdio.h>

int map[36] ;

void initMap() ;
int getKeyValue( char c ) ;
int setKeyValue( char c , int a ) ;

int main( int argc, char *argv[] ) {

  initMap();

  setKeyValue( '0', 1 ) ;
  setKeyValue( '9', 2 ) ;
  setKeyValue( 'a', 3 ) ;
  setKeyValue( 'z', 4 ) ;
  
  printf( "0: %d\n", getKeyValue('0')) ;
  printf( "9: %d\n", getKeyValue('9')) ;
  printf( "a: %d\n", getKeyValue('a')) ;
  printf( "z: %d\n", getKeyValue('z')) ;
  

  return 0 ;

}

/* This "resets" all of the values in our "map" to 0 */
void initMap() {
  int i ;
  for (i = 0; i < 36; i++) {
    map[i] = 0 ;
  }
  return ;
}

/* This function basically is the bread and butter of the map. It's simply just
   structured like this:
   map[0] to map[9]:     These represent the numbers 0-9. Ex. map[5] returns the value
                         of the key '5'.
   map[10] to map[35]:   These represent the letters a-z. Ex. map[10] returns the value
                         of the key 'a'.

   This function accepts a character from '0' to '10' and 'a' to 'z' and returns
   the key's corresponding value. Returns -1 if an invalid key is given.
*/
int getKeyValue( char c ) {
  if ( c >= 48 && c <= 57 ) {
    return map[c-48];
  }
  else if ( c >= 97 && c <= 122 ) {
    return map[c-87];
  }
  else {
    return -1;
  }
}

/* This function pretty much behaves the same as getKeyValue except this accepts a key 
   and a new value for that key. Returns 0 if successful and -1 if not.
*/
int setKeyValue( char c, int a ) {
  if ( c >= 48 && c <= 57 ) {
    map[c-48] = a;
    return 0;
  }
  else if ( c >= 97 && c <= 122 ) {
    map[c-87] = a;
    return 0 ;
  }
  else {
    return -1;
  }
}
