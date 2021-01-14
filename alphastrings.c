#include <stdio.h>
#include <string.h>
int main() {
char myString [27] = "";

for(int i = 0; i < 26; i++) {

  char letters[] =  "a";
  letters[0] += i;
  strcat(myString, letters);
 }
 printf("%s\n", myString);


 char* strConstP = "abcdefghijklmnopqrstuvwxyz";
 
 char str[100];

  if (strcmp (myString, strConstP) == 0)
   printf("the strings are the same\n");

 if (strcmp (myString, strConstP) != 0)
   printf("the strings are different\n");

 for(int i = 0; i < 26; i++) {

   myString[i] -= 32;
 }
 printf("%s\n", myString);


 if (strcmp (myString, strConstP) == 0)
   printf("the strings are the same\n");

 if (strcmp (myString, strConstP) != 0)
   printf("the strings are different\n");

 strcpy(str, strConstP);
 strcat(str, myString);

 printf("%s + %s = %s\n", strConstP, myString, str);
 
}


