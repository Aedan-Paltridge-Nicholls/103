
#include <string>
#include <conio.h>
#include <cstring>
#include <iostream>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define cout std::cout
char *Fixer(string InpStr)
{
  string Str17 = InpStr;
  char *Fixer = new char[Str17.length() + 1]; // Creates The char* fixer and makes it one longer than str7.
  strcpy(Fixer, Str17.c_str());               // Makes The char* fixer and makes have The same content as str7.

  return Fixer;
}
string Formatter(string input) // Formatts strings to replace spaces with underscores
{
  char Sp = 32;                // A space. " "
  char Us = 95;                // An Underscore _
  int Inputlength = input.length();
  char *Formatter = new char[input.length() + 1];
  strcpy(Formatter, input.c_str());
  for (int i = 0; i < Inputlength; i++)
  {
    if (Formatter[i] == Sp)
    {
      Formatter[i] = Us;
    }
  }

  return Formatter;
}
void startup() // Checks if The files for The programm exist and if not creates them.
{
  system("if not exist C:\\logins\\Teachers mkdir C:\\logins\\Teachers");
  system("tree /F  C:\\logins");
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
  cin.ignore();
  string path = "C:\\logins\\Teachers";            // Path to folder;
  string error = "Inputed teacher already exists"; // Warns if The inputed teacher's name already exists;
  string input = "";
  cout << "Name of Teacher  ";
  getline(cin, input);
  input = Formatter(input);
  makefolder(input, path, error);
  system("TREE C:\\logins");
}
string OutTime[14]; 
void SetTimetable()
{ 
    bool ChangedTime = false;
  string Weekdays[7] ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  string StartOrEnd[2]={"Start","End"};
  int input = 0,Time=555,x=1,Runs = 1,sre=0,days=0;
  while (true)
  {
    int Highlow[14],laststart;// These are for checking if "Time", end time is Higher or lower than the Last start time.
    string out = "NA";
    input = 0;
    system("cls");
    if (Runs %2 !=0){sre = 1;}else{sre =2;} 
    if (sre == 2)
    {
     laststart = Highlow[(Runs-2)];
      if(Time < laststart ){Time = Time + laststart;}
    }
    if (Time<10){cout <<"000";}else if (Time<100&&Time>10){cout <<"00";}else if (Time<1000&&Time>100){cout <<"0";} 
    
    cout <<Time<< " :"<<StartOrEnd[(sre-1)]<<" "<<Weekdays[days]<<" Time change by :"<< x <<endl;
   
    
    switch ((input=getch()))
    { 
      case KEY_UP:// When the Up arrow is pushed increases Time by x
      {
       Time=Time+x;
       ChangedTime = true;
      }
      break;
      case KEY_DOWN:// When the Down arrow is pushed decreases Time by x
      {
        Time=Time-x;
        ChangedTime = true;
      }
      break;
      case KEY_LEFT:// When the Left arrow is pushed decreases x by 15 only if x above 0
      {
        if(x != 0)
        {x=x-15;}
      }
      break;
      case KEY_RIGHT:// When the Right arrow is pushed increases x by 15 only if x Below 60
      {
        if(x != 60)
       {x=x+15;}
      }
      break;
      case KEY_ENTER:
      {
        if (Runs %2 == 0){days++;} 
        if (days > 7){return;}
        if (Time<10){out ="000"; out += to_string(Time);}
        else if (Time < 100 && Time > 10){out ="00"; out += to_string(Time); }
        else if (Time < 1000 && Time > 100){out = "0";out += to_string(Time);}
        else{out = to_string(Time);}
        OutTime[(Runs-1)] = out ;
        Runs ++;
      }
      break;
      default:
      break;
    }
    
   
    Time = -2403; 
    Highlow[(Runs-1)] = Time;
    int Array[4] ={0,0,0,0};
    for (int t = 0; t < 4; t++)
    {
      Array[(3-t)] = Time %10;
      Time /= 10;
    }
    if (Array[2]>6||Array[2]==6&&Array[3]>0)
    {
      Array[1]++;
      if (Array[1]<10)
      {
        Array[2] = 0;
        Array[3] = 0;
      }
      else if (Array[0]<=2)
      {
        Array[0]++;
        Array[1] = 0;
        Array[2] = 0;
        Array[3] = 0;
      }
      else if (Array[0] > 2 && Array[1] > 4 || Array[1] == 4 && Array[2] > 0 || Array[3] > 0)
      {
        Array[0] = 0;
        Array[1] = 0;
        Array[2] = 0;
        Array[3] = 0;
      }
    }
    else if (Array[0] > 2 && Array[1] > 4 || Array[1] == 4 && Array[2] > 0 || Array[3] > 0)
    {
      Array[0] = 0;
      Array[1] = 0;
      Array[2] = 0;
      Array[3] = 0;
    }
    else if (Array[0] < 0 || Array[1] < 0 || Array[2] < 0 || Array[3] < 0 )
    {
      Array[0] = 0;
      Array[1] = 0;
      Array[2] = 0;
      Array[3] = 0;
    }
    {
        Time =
            (Array[0] * 1000) +
            (Array[1] * 100) +
            (Array[2] * 10) +
            (Array[3] * 1);
    };
    
  }
  
}
void Timetable()
{ char SP = 32;  // " " Space
  char AA = 175; // » Two arrows 
  char BK = 219; // █ Block 
  char TL = 201; // ╔ Top Left
  char TM = 203; // ╦ Top Middle
  char TR = 187; // ╗ Top Right
  char LM = 205; // ═ Line Middle
  char MM = 186; // ║ Middle Middle
  char LL = 204; // ╠ Line Left
  char LC = 206; // ╬ Line Center
  char LR = 185; // ╣ Line Right
  char BL = 200; // ╚ Bottom Left
  char BM = 202; // ╩ Bottom Middle
  char BR = 188; // ╝ Bottom Right
  int left = 13; // Size of the left half
  int right = 15;// Size of the right half
  string Hours = "Hours" ;
  string Days = "Days" ;
  string Weekdays[7] ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  string InTimes[7];
  string Times[7];
  SetTimetable();
 
  int StartClass = 0;
  int End  = 1;
 for (int R = 0; R < 7; R++)
 {  
   Times[R] = OutTime[StartClass] + SP+AA+SP + OutTime[End];
   StartClass +=2;
   End +=2;
   Times[R] ;//= InTimes[R];
 }
 
  {
    for (int i = 0; i < 7; i++)
    {
     // Times[i] = SetTimetable() + CenterTime + SetTimetable();
      if (Times[i] == "NA")
      {
        for (int x = 0; x < 13; x++)
        {
          Times[x] += BK;
        }
      }
    }
  }
  string Top,Header,Divider,Content[7],Bottom;
  Top = TL; // The Top of the timetable
  {
    for (int i = 0; i < left; i++)
    {
      Top += LM;
    }
    Top += TM;
    for (int i = 0; i < right; i++)
    {
      Top += LM;
    }
    Top += TR;
  }
  Header = MM ; // The header of the timetable
  {
    int h,d;
    d = (left- Days.length())/2;
    h = (right- Hours.length())/2;
    Days += SP;
    for (int i = 0; i < d; i++){Header += SP;}
    Header += Days;
    for (int i = 0; i < d; i++){Header += SP;}
    Header += MM ;
    for (int i = 0; i < h; i++){Header += SP;}
    Header += Hours;
    for (int i = 0; i < h; i++){Header += SP;}
    
   
    Header += MM ;
  }
  Divider = LL;// The divider between each of day of the timetable
  {
    for (int i = 0; i < left; i++)
    {
      Divider += LM;
    }
    Divider += LC;
    for (int i = 0; i < right; i++)
    {
      Divider += LM;
    }
    Divider += LR;
  }
  Bottom = BL; // The bottom of the timetable
  {
    for (int i = 0; i < left; i++)
    {
      Bottom += LM;
    }
    Bottom += BM;
    for (int i = 0; i < right; i++)
    {
      Bottom += LM;
    }
    Bottom += BR;
  }
  // The content of the timetable
  {
    for (int i = 0; i < 7; i++)
    {
      int v = ((left) - (Weekdays[i].length())-1);
      Content[i] += MM;
      Content[i] += SP;
      Content[i] += Weekdays[i];
      for (int j = 0; j < v ; j++)
      {Content[i] += SP;}
      Content[i] += MM;
      Content[i] += SP;
      Content[i] += Times[i];
      Content[i] += SP;
      Content[i] += MM;
    }
  }
  cout << Top <<endl;
  cout << Header <<endl;
  for (int i = 0; i < 7; i++)
  {
    cout << Divider <<endl;
    cout << Content[i] <<endl;
  }
  cout << Bottom <<endl;

}

void ClassInfoFile()
{
  /*
  *  TeacherName = str1   //The teacher's name
  *  ClassName = str2     //The name of the class
  *  ClassType = str3     //The class's Type ie Maths, English, History, ect.
  * 
  * Name of the teacher : "TeacherName" || Start date : "start" || End date : "end"
  * Name of "TeacherName"'s class : "ClassName" ||  "ClassName"'s class Type :
  * "ClassName"'s Time table : 
  * ╔═══════════╦═════════════╗   //  Class time slots to be displayed like : ↓
  * ║   Days    ║    Hours    ║   //          start ↓   ↓ end       not on this day ↓ 
  * ╠═══════════╬═════════════╣   //╠═══════════╬═════════════╣  ╠═══════════╬═════════════╣  
  * ║ Sunday    ║             ║   //║ Sunday    ║ 0700 » 1200 ║  ║ Sunday    ║█████████████║ 
  * ╠═══════════╬═════════════╣   //╠═══════════╬═════════════╣  ╠═══════════╬═════════════╣
  * ║ Monday    ║             ║
  * ╠═══════════╬═════════════╣  
  * ║ Tuesday   ║             ║
  * ╠═══════════╬═════════════╣
  * ║ Wednesday ║             ║
  * ╠═══════════╬═════════════╣
  * ║ Thursday  ║             ║
  * ╠═══════════╬═════════════╣
  * ║ Friday    ║             ║
  * ╠═══════════╬═════════════╣
  * ║ Saturday  ║             ║
  * ╚═══════════╩═════════════╝
  * 
  */
}
void AddAClass() // WIP
{
  cin.ignore();
  char Bs = 92;                            // A Back slash
  string TeacherName;                      // The teacher's name
  string ClassName;                        // The new class's name
  string ClassType;                        // The new class's Type ie Maths, English, History, ect.
  string Warning = "Class already exists"; // Warns if The inputed class already exists;
  cout << "The classes teachers name  ";
  getline(cin, TeacherName);
  TeacherName = Formatter(TeacherName);
  cout << "The classes  name  ";
  getline(cin, ClassName);
  ClassName = Formatter(ClassName);
  cout << "The classes  type  ";
  getline(cin, ClassType);
  ClassType = Formatter(ClassType);
  // ↑Inputs ↓File and folder making
  string path = "C:\\logins\\Teachers";
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
  /*This ↓ is the format that will be written to the file.
  *string StudentName      =   str1                 // The name of The student
  *string StudentDOB       =   str2                 // The Date of birth of The student
  *string Studentparents   =   str3                 // The parents of The student
  *string phonenumber;     =   str4                 // The student's parent's phone number.
  *string Studentaddress;  =   str5                 // The address of The student
  *string Yearlevel;       =   str6                 // The Year level of The student
  *string Path             =   str7                 // The path to The file
  *string gender           =   gender()             // the student's gender. 
  *formatt
  *Name "StudentName"  Age "StudentAge"   Year level "Yearlevel"
  *Gender" " Home Address "Studentaddress"
  *Name of parents "Studentparents"  parents phonenumber "phonenumber"
  */
 char Bs = 92;                              // A Back slash
 char Ob = 40;                              // A Open bracket.
 char Cb = 41;                              // A Closed bracket.
 char Sp = 32;                              // A space.
 char Qm = 34;                              // A Quotation mark.
 string gen = gender();                     // the student's gender.
 string Path = str7 + Formatter(str1);      // The path to The file
 string Tb = "^|  ^|";                      // Adds a tab
 string SC = "(echo.";                      // Starts The command
 string EC = ") >";                         // Ends The command
 string NL = "& echo. & echo";              // adds a new line to a file
 string L1;                                 // line one
 string L2;                                 // line two
 string L3;                                 // line three
 string T1 = "Name:";                       // Name
 string T2 = "'s Date of birth:";           // Dob
 string T3 = "'s Year level:";              // Year level
 string T4 = "Home address of";             // Home address
 string T5 = ": ";                          // Formating :
 string T6 = "Name of";                     // Name of
 string T7 = "'s : ";                       // Formating 's
 string T8 = "'s Parent/s's Phonenumbers:"; // Parent/s's Phonenumbers
 string T9 = ".txt";                        // File format

 L1 = T1 + Sp + str1 + Sp + Tb + Sp + str1 + T2 + Sp + str2 + Sp + Tb + Sp + str1 + T3 + Sp + str3;
 L2 = str1 + gen + Sp + T4 + Sp + str1 + T5 + Sp + str4;
 L3 = T6 + Sp + str1 + T7 + Sp + str5 + Sp + Tb + Sp + str1 + T8 + Sp + str6;
 string command = SC + Sp + L1 + Sp + NL + Sp + L2 + Sp + NL + Sp + L3 + Sp + EC + Sp + Path + T9;
 system(Fixer(command));
 command = "type " + Path + T9;
 system(Fixer(command));
}

void AddStudent()
{
  cin.ignore();
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

void interface()
{
  cout << "What do you want to do\nAddAClass\t[C]\nAddaStudent\t[S]\nAddateacher\t[T]\nExit\t\t[E]\n";
  char input;
  cin >> input;
  switch (toupper(input))
  {
    case 'C':
    { AddAClass();
    } 
    break;
   
    case 'S':
    { AddStudent();
    }
    break;
    case 'T':
    {  AddATeacher();
    }
    break;
    case 'E':
    {  system("exit");
    }
    break;
    default:
    {
      cout <<"Invaild input try again"<<endl;
    }
    break;
  }
}
int main()
{
  Timetable();
  cin.ignore();
 // SetTimetable();
 // StudentInfoFile("Aedan H Paltridge-Nicholls","17","13","6a harley rd","Aaron rodney Nicholls ","64 22 400 3301","C:\\logins\\teachers\\");
  /*string text ;
  cin >> noskipws  >>text ;
  cout << text;*/
  startup();
   while (true)
  {
     //cin.ignore();
    interface();
  }
  
 
}