#include <stdio.h>
#include <string.h>



// student structure
//struct Student...
struct Student {
  char firstname[256];
  char lastname[256];
  int age;
  int studentid;
};



void printStudent(struct Student* student)
{
  printf("----- student ------\n");
  printf(" Student first name:%s\n", student->firstname);
  printf(" Student last name:%s\n", student->lastname);
  printf(" Student age:%d\n", student->age);
  printf(" Student id:%d\n", student->studentid);
}


void printAllStudents(struct Student students[], int num)
{
 
  for(int i = 0; i < num; i++) {
   printStudent(&students[i]);
  }
  // call printStudent for each student in students
}


int main()
{

  // an array of students
  //xxx students;
  char input[256];
  int numStudents = 0;
  struct Student students[256];
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      
  char firstname[256];
  char lastname[256];
  int age;
  int studentid;
      
      printf("Enter your first name\n");
      fgets(input, 256, stdin);
      sscanf(input,"%s", firstname);

      printf("Enter your last name\n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", lastname);

      printf("Enter your age\n");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &age);

      printf("Enter your studentid\n");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &studentid);

      struct Student estudiantes;

      strcpy(estudiantes.firstname, firstname);
      strcpy(estudiantes.lastname, lastname);
      estudiantes.age = age;
      estudiantes.studentid = studentid;

      students[numStudents] = estudiantes; 
      
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}

