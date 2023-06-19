#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char *Fixer(string InpStr)
{
  string Str17 = InpStr;
  char *Fixer = new char[Str17.length() + 1]; // Creates The char* fixer and makes it one longer than str7.
  strcpy(Fixer, Str17.c_str());               // Makes The char* fixer and makes have The same content as str7.

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
void startup() // Checks if The files for The programm exist and if not creates them.
{
  system("if not exist C\\logins\\Teachers mkdir C\\logins\\Teachers");
  system("tree /F  C\\logins");
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
  string path = "C\\logins\\Teachers";            // Path to folder;
  string error = "Inputed teacher already exists"; // Warns if The inputed teacher's name already exists;
  string input = "";
  cout << "Name of Teacher  ";
  getline(cin, input);
  input = Formatter(input);
  makefolder(input, path, error);
  system("TREE C\\logins");
}
void AddAClass() // WIP
{
  char Bs = 92;                            // A Back slash
  string TeacherName;                      // The teachers name
  string ClassName;                        // The new class's name
  string Classtype;                        // The new class's Type ie Maths, English, History, ect.
  string Warning = "Class already exists"; // Warns if The inputed class already exists;
  cout << "The classes teachers name  ";
  getline(cin, TeacherName);
  TeacherName = Formatter(TeacherName);
  cout << "The classes  name  ";
  getline(cin, ClassName);
  ClassName = Formatter(ClassName);
  cout << "The classes  type  ";
  getline(cin, Classtype);
  Classtype = Formatter(Classtype);
  // ↑Inputs ↓File and folder making
  string path = "C\\logins\\Teachers";
  path = path + Bs + TeacherName + Bs + "Classes"; // Path to folder;
  makefolder(ClassName, path, Warning);            // Makes The folder
  string Fullpath = path + Bs + ClassName;
  makefile("Test ", Fullpath, ClassName); // Makes The file
}
char Gen;// The students Gender.
string gender()
{
  string out = "'s Gender is :";
  switch (Gen)
  {   
   case 'M':
    {
      out.append(" Male ♂ ");
    }
    break;
    case 'F':
    {
      out.append(" Female ♀ ");
    }
    break;
    case 'O':
    {
      out.append(" other ♀/♂ ");
    }
    break;
    default:
    {
      out.append(" Male ♂ ");
    }
    break;
  }
  Gen = ' ';
 return out;
}
void StudentInfoFile(string str1, string str2, string str3, string str4, string str5, string str6, string str7)
{
  /*
  string StudentName      =   str1                 // The name of The student
  string StudentDOB       =   str2                 // The Date of birth of The student
  string Studentparents   =   str3                 // The parents of The student
  string phonenumber;     =   str4                 // The student's parent's phone number.
  string Studentaddress;  =   str5                 // The address of The student
  string Yearlevel;       =   str6                 // The Year level of The student
  string Path             =   str7                 // The path to The file
  string gender           =   gender()             // the student's gender. 
  formatt
  Name "StudentName"  Age "StudentAge"   Year level "Yearlevel"
  Gender" " Home Address "Studentaddress"
  Name of parents "Studentparents"  parents phonenumber "phonenumber"
  */
  char Bs = 92;                         // A Back slash
  char Ob = 40;                         // A Open bracket.
  char Cb = 41;                         // A Closed bracket.
  char Sp = 32;                         // A space.
  char Qm = 34;                         // A Quotation mark.
  string gen = gender();                // the student's gender. 
  string Path = str7 + Formatter(str1); // The path to The file
  string Tb = "^|  ^|";                 // Adds a tab
  string SC = "(echo.";                 // Starts The command
  string EC = ") >";                    // Ends The command
  string NL = "& echo. & echo";         // adds a new line to a file
  string L1;                            // line one
  string L2;                            // line two
  string L3;                            // line three
  string T1 = "Name:";
  string T2 = "'s Date of birth:";
  string T3 = "'s Year level:";
  string T4 = "Home address of";
  string T5 = ": ";
  string T6 = "Name of";
  string T7 = "'s : ";
  string T8 = "'s Parent/s's Phonenumbers:";
  string T9 = ".txt";

  L1 = T1 + Sp + str1 + Sp + Tb + Sp + str1 + T2 + Sp + str2 + Sp + Tb + Sp + str1 + T3 + Sp + str3;
  L2 = T4 + Sp + str1 + T5 + Sp + str4;
  L3 = T6 + Sp + str1 + T7 + Sp + str5 + Sp + Tb + Sp + str1 + T8 + Sp + str6;
  string command = SC + Sp + L1 + Sp + NL + Sp + L2 + Sp + NL + Sp + L3 + Sp + EC + Sp + Path + T9;
  system(Fixer(command));
  command = "type " + Path + T9;
  system(Fixer(command));
}

void AddStudent()
{
  string path = "C:\\logins\\Teachers";    // The main path.
  char Bs = 92;                            // A Back slash.
  string TeacherName;                      // The student's teacher's name.
  string ClassName;                        // The name of The student's class.
  string StudentName;                      // The name of The student.
  string StudentDOB;                       // The Date of birth of The student.
  string StudentParents;                   // The parents of The student.
  string StudentMother;                    // The parents of The student.
  string StudentFather;                    // The parents of The student.
  string Phonenumber;                      // The student's parent's phone number.
  string MotherPhonenumber;                // The student's parent's phone number.
  string FatherPhonenumber;                // The student's parent's phone number.
  string Studentaddress;                   // The address of The student.
  string Yearlevel;                        // The Year level of The student.
  string Warning = "Class already exists"; // Warns if The inputed class already exists.
  // Other info.↓
  cout << "The student's teacher's name  "; // The students teacher's name.
  getline(cin, TeacherName);
  TeacherName = Formatter(TeacherName);
  cout << "The student's class's  name  "; // The name of The student's class.
  getline(cin, ClassName);
  ClassName = Formatter(ClassName);
  // The  Student's info. ↓
  cout << "The student's  name  "; // The name of The student.
  getline(cin, StudentName);
  cout << "The student's  Gender\n" // The name of The student.
  <<"Male ♂ [M]\tFemale ♀ [F]\t other ? [O] ";
  cin >> Gen;  
  Gen = toupper(Gen);
  cout << "The student's  Dob  \n please type in DD-MM-YY Format"; // The Date of birth of The student.
  getline(cin, StudentDOB);
  cout << "The student's  parent/parents's names \n" // The parents's names of The student.
  <<"If The parents info is unknown or is not applicable type: NA\n";
  cout << "The student's  father's name :";
  getline(cin, StudentFather);
  cout << "The student's  Mother's name :";
  getline(cin, StudentMother);
  cout << "The student's parent/parents's phone number  \n" // The student's parents's phonenumbers.
  <<"If The parents info is unknown or is not applicable type: NA\n";
  cout << "The student's  father's name :";
  getline(cin, FatherPhonenumber);
  cout << "The student's  Mother's name :";
  getline(cin, MotherPhonenumber);
  cout << "The student's  address  "; // The address of The student
  getline(cin, Studentaddress);
  cout << "The student's  Year level  "; // The Year level of The student
  getline(cin, Yearlevel);
  if (StudentFather != "NA"){StudentParents = StudentParents + "Father's name : "+ StudentFather;}
  if (StudentMother != "NA"){StudentParents = StudentParents + "Mother's name : "+ StudentMother;}
  if (StudentFather == "NA" && StudentMother == "NA"){StudentParents =" Unknown ";}
  if (FatherPhonenumber != "NA"){Phonenumber = Phonenumber + "Father's phonenumber : "+ FatherPhonenumber;}
  if (MotherPhonenumber != "NA"){Phonenumber = Phonenumber + "Mother's phonenumber : "+ MotherPhonenumber;}
  if (FatherPhonenumber == "NA" && MotherPhonenumber == "NA"){StudentParents =" Unknown ";}
  // ↑Inputs ↓File and folder making
  string Fullpath = path + Bs + TeacherName + Bs + "Classes" + Bs + ClassName; // Path to folder;
  makefolder(Formatter(StudentName), Fullpath, Warning);
}
/*
void interface()
{
  cout << "What do you want to do\nAddAClass\t[C]\nAddaStudent\t[S]\nAddateacher\t[T]\nExit\t\t[E]\n";
  char input;
  cin >> input;
  switch (toupper(input))
  {
    case 'C'
    { AddAClass();
    }
    break;
    case 'S'
    { AddStudent();
    }
    break;
    case 'T'
    {  AddATeacher();
    }
    break;
    case 'E'
    {  system("exit");
    }
    break;
    default
    {
      cout <<"Invaild input try again"<<endl;
    }
    break;
  }
}*/
int main()
{
  StudentInfoFile("Aedan H Paltridge-Nicholls","17","13","6a harley rd","Aaron rodney Nicholls ","64 22 400 3301","C:\\logins\\teachers\\");
  string text ;
  cin >> noskipws  >>text ;
  cout << text;
  startup();
  /* while (true)
  {
     
    interface();
  }
  */
 
}