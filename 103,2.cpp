#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char *Fixer(string InpStr)
{
  string Str17 = InpStr;
  char *Fixer = new char[Str17.length() + 1]; // Creates the char* fixer and makes it one longer than str7.
  strcpy(Fixer, Str17.c_str());               // Makes the char* fixer and makes have the same content as str7.

  return Fixer;
}
string Formatter(string input)//Formatts strings to replace spaces with underscores
{
  int Inputlength = input.length();
  char *Formatter = new char[input.length() + 1];
  strcpy(Formatter, input.c_str());
  for (int i = 0; i < Inputlength; i++)
  {
    if (Formatter[i] == char(32))
    {
      Formatter[i] = char(95);
    }
  }
  
  return Formatter;
}
void startup() // Checks if the files for the programm exist and if not creates them.
{
  system("set colordir=.txt:blue");
  system("set colordir=JUNCTION:blue");
  system("if not exist C:\\logins\\Teachers mkdir C:\\logins\\Teachers");
}
void makefile(string content, string directory, string filename) // Make a text file in  a choosen  directory.
{
  char Bs = 92; // A Back slash
  char Qm = 34; // A Quotation mark.
  string command = " echo. ";
  string AA = " >> "; // Two arrows so that, it will add to a file, not overwrite it.
  string out = command + Qm + content + Qm + AA + directory + Bs + filename + ".txt";
  system(Fixer(out));
}
void makefolder(string input, string directory, string warning) // Make folder in  a choosen  directory.
{
  string Ck = "if not exist "; // Checks if a directory exists
  string C1 = " mkdir ";       // Command Makes directory
  string C2 = " else ";        // Command two
  string C3 = " echo. ";       // Command puts warning text in console.
  char Bs = 92;                // A Back slash
  char Ob = 40;                // A Open bracket.
  char Cb = 41;                // A Closed bracket.
  char Sp = 32;                // A space.
  char Qm = 34;                // A Quotation mark.
  string out = Ck + directory + Bs + input + Sp + Ob + C1 + directory + Bs + input + Cb + C2 + Ob + C3 + Qm + warning + Qm + Cb;
  system(Fixer(out));
}

void AddATeacher() // WIP
{
  string path = "C:\\logins\\Teachers";            // Path to folder;
  string error = "Inputed teacher already exists"; // Warns if the inputed teacher's name already exists;
  string input = "";
  cout << "Name of Teacher : ";
  getline(cin, input);
  Formatter(input);
  makefolder(input, path, error);
  system("TREE C:\\logins");
}
void AddAClass() // WIP
{
  Formatter("Nathan Black");
  char Bs = 92;                            // A Back slash
  string TeacherName;                      // The teachers name
  string ClassName;                        // The new class's name
  string Classtype;                        // The new class's Type ie: Maths, English, History, ect.
  string Warning = "Class already exists"; // Warns if the inputed class already exists;
  cout << "The classes teachers name : ";
  getline(cin, TeacherName);
  Formatter(TeacherName);
  cout << "The classes  name : ";
  getline(cin, ClassName);
  Formatter(ClassName);
  cout << "The classes  type : ";
  getline(cin, Classtype);
  Formatter(Classtype);
  // ↑Inputs ↓File and folder making
  string path = "C:\\logins\\Teachers";
  path = path + Bs + TeacherName + Bs + "Classes"; // Path to folder;
  makefolder(ClassName, path, Warning);            // makes the folder
  string Fullpath = path + Bs + ClassName;
  makefile("Test ", Fullpath, ClassName); // makes the file
}
void AddStudent()
{
  string path = "C:\\logins\\Teachers";    // the main path
  char Bs = 92;                            // A Back slash
  string TeacherName;                      // The students teacher's name
  string ClassName;                        // the name of the student's class
  string StudentName;                        // the name of the student
  string Warning = "Class already exists"; // Warns if the inputed class already exists;
  cout << "The student's teacher's name : ";
  getline(cin, TeacherName); //>> TeacherName
  Formatter(TeacherName);
  cout << "The student's class's  name : ";
  getline(cin, ClassName);
  Formatter(ClassName);
  cout << "The student's  name : ";
  getline(cin, StudentName);
  Formatter(StudentName);
  // ↑Inputs ↓File and folder making
  string Fullpath = path + Bs + TeacherName + Bs + "Classes" + Bs + ClassName; // Path to folder;
  makefolder(StudentName, path, Warning);
  string classname = StudentName; 
  makefile("",Fullpath,ClassName);
}

int main()
{

  system("tree /F  C:\\logins");
  startup();
  AddAClass();
  AddStudent();
  AddATeacher();
  system("tree /F  C:\\logins");
  cout << "Hello World!\n";
}