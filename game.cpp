#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//by Ryan Veith
//
//This should create the student list project


struct student {
  //if I want each value in the stuct to be a pointer
  //this is unecesarry because we only need to read the struct or
  //completley reset it, there is no need to change it in the middle
  /*
  Student() {
    nameFirst = new char[10];
    nameLast = new char[10];
    id = new int;
    gpa = new float;
  }
  ~Student() {
    delete[] nameFirst;
    delete[] nameLast;
    delete id;
    delete gpa;
  }
  //*/
  char nameFirst[10];
  char nameLast[10];
  int id;
  float gpa;
};

/* ex declration
void name(int thing);
void evenBetterName(bool &referencedBoolean);
*/
void addStudent(vector<student> &studentList);
void printStudent(vector<student> studentList);
void deleteStudent(vector<student> &studentList);
//void quit(); just quit

int main()
{
  //initialize vaiables
  char input[6];
  for (int a = 0; a < 6; a++)
    {
      input[a] = ' ';
    }
  bool quit = false;

  vector<student> studentList;
  
  //program
  while (quit == false) {
    cin.get(input, 7); //6 chars
    cin.ignore(2,'\n');

    //check for each command and run the correct function
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D' )
      {
	addStudent(studentList);
      }
    else if (input[0] == 'P' &&
	     input[1] == 'R' &&
	     input[2] == 'I' &&
	     input[3] == 'N' &&
	     input[4] == 'T' )
      {
	printStudent(studentList);
      }
    else if (input[0] == 'D' &&
	     input[1] == 'E' &&
	     input[2] == 'L' &&
	     input[3] == 'E' &&
	     input[4] == 'T' &&
	     input[5] == 'E' )
      {
	deleteStudent(studentList);
      }
    else if (input[0] == 'Q' &&
	     input[1] == 'U' &&
	     input[2] == 'I' &&
	     input[3] == 'T' )
      {
	quit = true;
      }
    else
      {
	cout << "Cannot find that command" << endl;
	cout << "The possible commands are: " <<endl;
	cout << "ADD" << endl;
	cout << "PRINT" << endl;
	cout << "DELETE" << endl;
	cout << "QUIT" << endl;
      }
  }

  /*
  //example(for reference):     it is missing the ingore for cin
  Student geroge;
  cin >> geroge.name;
  geroge.id = 1234;
  geroge.gpa = 3.0;
  cout << geroge.name << " ID:" << geroge.id << " GPA:";
  cout << geroge.gpa << endl;
  */
}

void addStudent(vector<student> &studentList)
{
  //add a new student to a not yet created linkedlist
  //wil need to do anouther set of 4 cins (10 char each?)
  //first name (char array)
  //last name  (char array)
  //id# (int)
  //GPA (float)
  char nameF[10];
  char nameL[10];
  for (int a = 0; a < 10; a++)
    {
      nameF[a] = ' ';
      nameL[a] = ' ';
    }
  int  idNumber = 0;
  float studentGPA = 0;

  //first name
  cout << "Enter the students first name"<< endl;
  cin.get(nameF, 11); //10 chars
  cin.ignore(10,'\n');
  //last name
  cout << "Enter the students last name"<< endl;
  cin.get(nameL, 11); //10 chars
  cin.ignore(10,'\n');
  //id num
  cout << "Enter the students id number"<< endl;
  cin >> idNumber; //6 chars
  cin.ignore(7,'\n');
  //gpa
  cout << "Enter the students gpa"<< endl;
  cin >> studentGPA; //4 chars
  cin.ignore(4,'\n');

  //create a new student and then add it to the vector
  student *s = new student();
  for (int a = 0; a < 10; a++)
    {
      s->nameFirst[a] = nameF[a];
      s->nameLast[a] = nameL[a];
    }
   s->id = idNumber;
   s->gpa = studentGPA;
   
   studentList.push_back(*s);

   //Testing delete command and why it does not apply
   //delete[] *s->nameFirst;
}

void printStudent(vector<student> studentList)
{
  //go though everything in the linked list and cout it
  //currently couts " " at the end of name which could be changed or left
  for (int a = 0; a < studentList.size(); a++)
    {
      //first name
      for (int b = 0; b < 10; b++)
	{
	  cout << studentList[a].nameFirst[b];
	}
      cout << " ";
      //last name
      for (int b = 0; b < 10; b++)
	{
	  cout << studentList[a].nameLast[b];
	}
      cout << ", ";
      //id
      cout << studentList[a].id << ", ";
      //gpa
      cout << setprecision(3) << studentList[a].gpa << endl;
      
    }
}

void deleteStudent(vector<student> &studentList)
{
  //delete the struct then remove it from the linked list

  //ask id number to delete it
  int idNumber = 0;
  cout << "Enter the id number of the student to delete"<< endl;
  cin >> idNumber; //7 chars
  cin.ignore(7,'\n');
  
  //going to need to go through each student is the list to check id#
  for (int a = 0; a < studentList.size(); a++)
    {
      if (studentList[a].id == idNumber)
	{
	  //We have found the sturct so delete it
	  //the code for vectors has a wierd format for selecitng
	  studentList.erase((studentList.begin()+a));

	  //My process of trying to figure out what delete does
	  //Ultimatley not necesary since memory does not need to
	  //be freed explicitly since it is not a pointer
	  //apperently when it goes out of scope
	  //it will be automatically destroed
	  
	  //cout << studentList[a].nameFirst << endl;
	  //delete (studentList[a])->nameFirst;
	  //delete ((studentList[a]));
	  //delete[] (studentList[a].nameFirst);
	  //delete (studentList[a].nameLast);
	  //delete (studentList[a].id);
	  //delete (studentList[a].gpa);
	  //*/
	}
    }
}
