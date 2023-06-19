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
string Formatter(string input) // Formatts strings to replace spaces with underscores
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
void makefile2(string content, string directory, string filename) // Make a text file in  a choosen  directory.
{
  char Bs = 92; // A Back slash
  char Qm = 34; // A Quotation mark.
  string command = " echo. ";
  string AA = " >> "; // Two arrows so that, it will add to a file, not overwrite it.
  string out = command  + content  + AA + directory + Bs + filename + ".txt";
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
  input = Formatter(input);
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
  TeacherName = Formatter(TeacherName);
  cout << "The classes  name : ";
  getline(cin, ClassName);
  ClassName = Formatter(ClassName);
  cout << "The classes  type : ";
  getline(cin, Classtype);
  Classtype = Formatter(Classtype);
  // ↑Inputs ↓File and folder making
  string path = "C:\\logins\\Teachers";
  path = path + Bs + TeacherName + Bs + "Classes"; // Path to folder;
  makefolder(ClassName, path, Warning);            // makes the folder
  string Fullpath = path + Bs + ClassName;
  makefile("Test ", Fullpath, ClassName); // makes the file
}
void StudentInfoFile(string str1,string str2,string str3,string str4,string str5,string str6)
{
  /* string StudentName   =   str1                 // the name of the student
  string StudentAge       =   str2                 // the age of the student
  string Studentparents   =   str3                 // the parents of the student
  string phonenumber;     =   str4                 // the student's parent's phone number.
  string Studentaddress;  =   str5                 // the address of the student
  string Yearlevel;       =   str6                 // the Year level of the student
  formatt 
  Name: "StudentName" Age: "StudentAge" Year level: "Yearlevel" Home Address: "Studentaddress"
  Name of parents: "Studentparents"  parents phonenumber: "phonenumber" 
  */
 char Bs = 92;                // A Back slash
  char Ob = 40;                // A Open bracket.
  char Cb = 41;                // A Closed bracket.
  char Sp = 32;                // A space.
  char Qm = 34;                // A Quotation mark.

}
void AddStudent()
{
  string path = "C:\\logins\\Teachers";    // the main path
  char Bs = 92;                            // A Back slash
  string TeacherName;                      // The students teacher's name
  string ClassName;                        // the name of the student's class
  string StudentName;                      // the name of the student
  string StudentAge;                       // the age of the student
  string Studentparents;                   // the parents of the student
  string phonenumber;                      // the student's parent's phone number.
  string Studentaddress;                   // the address of the student
  string Yearlevel;                        // the Year level of the student
  string Warning = "Class already exists"; // Warns if the inputed class already exists;
  // Other info.↓
  cout << "The student's teacher's name : ";        // The students teacher's name
  getline(cin, TeacherName);
  TeacherName = Formatter(TeacherName);
  cout << "The student's class's  name : ";         // the name of the student's class
  getline(cin, ClassName);
  ClassName = Formatter(ClassName);
  // The  Student's info. ↓
  cout << "The student's  name : ";                 // the name of the student
  getline(cin, StudentName);
  StudentName = Formatter(StudentName);
  cout << "The student's  age : ";                  // the age of the student
  getline(cin, StudentAge);
  StudentAge = Formatter(StudentAge);
  cout << "The student's  parents names : ";        // the parents of the student
  getline(cin, Studentparents);
  Studentparents = Formatter(Studentparents);
  cout << "The student's parent's phone number : "; // the student's parent's phone number.
  getline(cin, phonenumber);
  phonenumber = Formatter(phonenumber);
  cout << "The student's  address : ";              // the address of the student
  getline(cin, Studentaddress);
  Studentaddress = Formatter(Studentaddress);
  cout << "The student's  Year level : ";           // the Year level of the student
  getline(cin, Yearlevel);
  Yearlevel = Formatter(Yearlevel);
  // ↑Inputs ↓File and folder making
  string Fullpath = path + Bs + TeacherName + Bs + "Classes"  + Bs + ClassName; // Path to folder;
  makefolder(StudentName, Fullpath, Warning);
  string classname = StudentName;
  string content = StudentName;
  makefile(content, Fullpath, ClassName);

}

int main()
{   char Ob = 40;                // A Open bracket.
    char Cb = 41;                // A Closed bracket.
    char qm  = char(9);
   string content;
   content  = content +Ob+ "echo test  & echo. & echo line two"+Cb+">> C:\\logins\\Teachers\\file.txt";
   system(Fixer(content));
  system("tree /F  C:\\logins");
  startup();
  // AddAClass();
  AddStudent();
  // AddATeacher();
  system("tree /F  C:\\logins");
  cout << "Hello World!\n";
}