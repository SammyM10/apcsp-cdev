//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id) {
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

  Student* estudiantes = (Student*)malloc(sizeof(Student));
  estudiantes->firstName = (char*)malloc(sizeof(char) *256);
  estudiantes->lastName = (char*)malloc(sizeof(char) *256);
  strcpy(estudiantes->firstName, fname);
  strcpy(estudiantes->lastName, lname);
  estudiantes->age = age;
  estudiantes->id = id;

  students[numStudents] = estudiantes;

  numStudents++;  

}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free (student->firstName);
  free (student->lastName);
  free (student);  


}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting the pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i = 0; i < numStudents; i++) {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents	= 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  
  FILE* fp;
  fp = fopen(STUFILE, "w");
  if (fp)
  {
    for (int i = 0; i < numStudents; i++) {
      caesarEncrypt(students[i]->firstName, key);
      caesarEncrypt(students[i]->lastName, key);
      char message[100] = "";
      sprintf(message, "%d", students[i]->age);
      caesarEncrypt(message, key);
       char message2[100] = "";
      sprintf(message2, "%ld", students[i]->id);
      caesarEncrypt(message2, key);
      fprintf(fp, "%s %s %s %s\n", students[i]->firstName,students[i]->lastName, message, message2);
     
    }
    fclose(fp);
  }
}

void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  deleteStudents();
  
  FILE* fp;
  fp = fopen(STUFILE, "r");

  if (fp){
    numStudents = 0;
 
    while (1){
      char firstName[256]; char lastName[256]; char age[256]; char id[256];

      if (fscanf(fp, "%s %s %s %s\n", firstName, lastName, age, id) == 4) {
        caesarDecrypt(firstName, key);
        caesarDecrypt(lastName, key);
        caesarDecrypt(age, key);
        caesarDecrypt(id, key);
        int numAge;
        long numID;
        sscanf(age, "%d", &numAge);
        sscanf(id, "%ld", &numID);
        createStudent(firstName, lastName, numAge, numID);

      }
 
      else
        break;
    }
    fclose(fp);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




