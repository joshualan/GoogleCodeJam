/*
  Created by Alan Estrada

  This program is for the Google Code Jam 2009 1C, All Your Base. It can be
  found here:
  https://code.google.com/codejam/contest/189252/dashboard#s=p0

*/

#include <stdio.h>
#include <math.h>

int map[36] ;

double findLowestNumberOfSeconds( char *numString ) ;
double convertAlienToDecimal( char *numString, char numChars, int base ) ;
void initMap() ;
int getKeyValue( char c ) ;
int setKeyValue( char c , int a ) ;

int main( int argc, char *argv[] ) {

  char WAR[61];

  int i, numCases ;

  FILE *fin ;
  
  if ( argc != 2 ) {
    printf( "Usage: allYourBase file_name_with_test_cases\n" ) ;
    return 0 ;
  }

  fin = fopen( argv[1], "r" ) ;

  /* Get number of test cases */
  fscanf( fin, "%d", &numCases ) ;

  /* Iterate through each string/test case */
  for ( i = 0 ; i < numCases ; i++ ) {
    initMap();
    fscanf( fin, "%s", WAR ) ;
    printf( "Case #%d: %.0f\n", i+1, findLowestNumberOfSeconds(WAR)) ;
  }
  
return 0 ;

}

double findLowestNumberOfSeconds( char *numString ) {
  
  int currChar = 0, numChars = 0;
  int highestNumber = 1 ;
  int isZeroAssigned = 0 ;

  char c ;

  while( c = numString[currChar] ) {
    
    if ( getKeyValue(c) == -1 ) {
      if ( highestNumber > 1 && !isZeroAssigned ) {
	setKeyValue(c, 0) ;
	isZeroAssigned = 1;
      }
      else {
	setKeyValue(c, highestNumber++) ;
      }
    }
    currChar++;
    numChars++;
  }

  return convertAlienToDecimal(numString, numChars, highestNumber ) ;
}

double convertAlienToDecimal( char *numString, char numChars, int base ) {

  int i;
  double sum = 0 ;

  /*  for ( i = numChars - 1 ; i >= 0 ; i-- ) {
    sum += pow(base, numChars - 1 - i) * getKeyValue( numString[i] ) ;
  }
  */

  for ( i = 0 ; i < numChars ; i++ ) {
    sum = sum * base + getKeyValue( numString[i] ) ;
  }
  return sum ;

}

/* This "resets" all of the values in our "map" to -1. We want the default value
   to be a negative number and not 0 because 0 is a valid value for a character.
*/
void initMap() {
  int i ;
  for (i = 0; i < 36; i++) {
    map[i] = -1 ;
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
    return map[c-48] ;
  }
  else if ( c >= 97 && c <= 122 ) {
    return map[c-87] ;
  }
  else {
    return -1 ;
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
