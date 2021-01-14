#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, float* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%f", b);
  }
}

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  return radius*radius*M_PI;
}

int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  
  float upper;
  float start;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &upper);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

  // added code below:
  if(argc == 1) {
    
  printf("input lower:\n");

  char input[256];
  while (1)
    {
  fgets(input, 256, stdin);
  if (sscanf(input, "%f", &start) == 1) break;
   printf("Not a valid radius. Try again!\n");
    }
 printf("input upper:\n");
  
  while (1)
    {
  fgets(input, 256, stdin);
  if (sscanf(input, "%f", &upper) == 1) break;
  printf("Not a valid radius. Try again!\n");
    }
  
    }
  for(float i=start; i <= upper; i++)
    {
printf("The area of the circle is: %f\n", areaOfCircle(i));
    }
}

