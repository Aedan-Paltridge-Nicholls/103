// VS2022 103.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string.h>
#include <string>
#include <conio.h>
#include <cstring>
#include <iostream>
//#pragma warning(disable : 4996)
using namespace std;
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_BACKSPACE = 8;
char* Fixer(string InpStr)
{
    string Str17 = InpStr;
    char* Fixer = new char[Str17.length() + 1]; // Creates The char* fixer and makes it one longer than str7.
    strcpy_s(Fixer, Str17.length()+1, Str17.c_str());// Makes The char* fixer and makes have The same content as str7.

    return Fixer;
}
string Formatter(string input) // Formatts strings to replace spaces with underscores
{
    char Sp = 32;                // A space. " "
    char Us = 95;                // An Underscore _
    size_t Inputlength = input.length();
    char* Formatter = new char[input.length() + 1];
    strcpy_s(Formatter, input.length() + 1,input.c_str());
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
    string Bs = "\\";  // A Back slash
    char Qm = 34;      // A Quotation mark.
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
    string Bs = "\\";            // A Back slash
    string Ob = "(";             // A Open bracket.
    string Cb = ")";             // A Closed bracket.
    unsigned char Sp = 32;       // A space.
    unsigned char Qm = 34;       // A Quotation mark.
    string out = Ck + directory + Bs + input += Sp +""+ Ob + C1 + directory + Bs + input + Cb  + C2 + Ob +""+ C3 += Qm +""+ warning += Qm +""+ Cb;
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
    string Weekdays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    string StartOrEnd[2] = { "Start","End" };
    int input = 0, Time = 555, x = 5, Runs = 1, sre = 1, days = 0, Index = 0, TimeArray[4] = { 0,0,0,0 };
    int Highlow[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0}, laststart=0;// These are for checking if "Time", end time is Higher or lower than the Last start time.
    while (true)
    {
 
        string out = "NA";
        input = 0;
        system("cls");
        if (Runs % 2 != 0) { sre = 1; }
        else { sre = 2; }

        if (Runs >= 2)
        {Index = Runs - 2;}
        if (sre == 2)
        {
            laststart = Highlow[(Index)];
            if (Time < laststart) { Time = Time + laststart; }
        }
        if (Time < 10) { cout << "000"; }
        else if (Time < 100 && Time>=10) { cout << "00"; }
        else if (Time < 1000 && Time>=100) { cout << "0"; }

        cout << Time << " :" << StartOrEnd[(sre -1)] << " " << Weekdays[days] << " Time change by :" << x << endl;


        switch ((input = _getch()))
        {
            case KEY_UP:// When the Up arrow is pushed increases Time by x
            {
                for (int t = 0; t < 4; t++)
                {
                    TimeArray[(3 - t)] = Time % 10;
                    Time /= 10;
                }
                {   int UP = 0;
                    do
                    {
                        TimeArray[3]++;
                        if (TimeArray[3] > 9)
                        {
                            TimeArray[3] = 0;
                            TimeArray[2]++;
                            if (TimeArray[2] > 6)
                            {

                                TimeArray[2] = 0;
                                TimeArray[1]++;
                                if (TimeArray[1] > 9 && TimeArray[0] < 2)
                                {
                                    TimeArray[1] = 0;
                                    TimeArray[0]++;
                                    
                                }
                                else if (TimeArray[1] > 4 && TimeArray[0] == 2)
                                {
                                    for (int t = 0; t < 4; t++)
                                    {
                                        TimeArray[t] = 0;
                                    }
                                }
                                else if (TimeArray[1] > 4 && TimeArray[0] > 2)
                                {
                                    for (int t = 0; t < 4; t++)
                                    {
                                        TimeArray[t] = 0;
                                    }
                                }
                            }
                        }
                        UP++;

                    } while (UP != x);
                    Time =
                        (TimeArray[0] * 1000) +
                        (TimeArray[1] * 100) +
                        (TimeArray[2] * 10) +
                        (TimeArray[3] * 1);
                    ChangedTime = true;

                }
            }
            break;
            case KEY_DOWN:// When the Down arrow is pushed decreases Time by x
            {
                for (int t = 0; t < 4; t++)
                {
                    TimeArray[(3 - t)] = Time % 10;
                    Time /= 10;
                }
                {   int Down=0;
                    do
                    {
                        TimeArray[3]--;
                        if (TimeArray[3] < 0)
                        {
                            TimeArray[3] = 9;
                            TimeArray[2]--;
                            if (TimeArray[2] < 0)
                            {
                                
                                TimeArray[2] = 5;
                                TimeArray[1]--;
                                if (TimeArray[1] < 0)
                                {
                                    TimeArray[1] = 9;
                                    TimeArray[0]--;
                                    if (TimeArray[0] < 0)
                                    {
                                        TimeArray[1] = 4;
                                        TimeArray[0] = 2;
                                    }
                                }
                            }
                        }
                        Down++;

                    } while (Down!=x);
                    
               
                }

                Time = 
                    (TimeArray[0] * 1000) +
                    (TimeArray[1] * 100) +
                    (TimeArray[2] * 10) +
                    (TimeArray[3] * 1);
                ChangedTime = true;
            }
            break;
            case KEY_LEFT:// When the Left arrow is pushed decreases x by 15 until 15, then decreases x by 5 only if x above 0
            {
                if (x == 5)
                {
                    x = 5;
                }
                else if (x == 10)
                {
                    x = 5;
                }
                else if (x == 15)
                {
                    x = 10;
                }
                else
                {
                    x = x - 15;
                }
            }
            break;
            case KEY_RIGHT:// When the Right arrow is pushed increases x by 5 until 15, then increases x by 15 only if x Below 60
            {
                if (x < 60)
                {
                    if (x==0)
                    {
                        x = 5;
                    }
                    else if (x==5)
                    {
                        x = 10;
                    }
                    else if(x==10)
                    {
                        x = 15;
                    }
                    else
                    {
                        x = x + 15;
                    }
                }
            }
            break;
            case KEY_ENTER:
            {
                if (Runs % 2 == 0) { days++; }
                if (days > 7) { return; }
                if (Time < 10) { out = "000"; out += to_string(Time); }
                else if (Time < 100 && Time >= 10) { out = "00"; out += to_string(Time); }
                else if (Time < 1000 && Time >= 100) { out = "0"; out += to_string(Time); }
                else { out = to_string(Time); }
                OutTime[(Runs - 1)] = out;
                Runs++;
            }
            break;
            default:
                break;
        }
        Highlow[(Runs - 1)] = Time;
        for (int t = 0; t < 4; t++)
        {
            TimeArray[(3 - t)] = Time % 10;
            Time /= 10;
        }
        if (TimeArray[2] > 6 || TimeArray[2] == 6 && TimeArray[3] > 0)
        {
            TimeArray[1]++;
            if (TimeArray[1] < 10)
            {
                TimeArray[2] = 0;
                TimeArray[3] = 0;
            }
            else if (TimeArray[0] <= 2)
            {
                TimeArray[0]++;
                TimeArray[1] = 0;
                TimeArray[2] = 0;
                TimeArray[3] = 0;
            }
        }
        else if (TimeArray[0] >= 2 && TimeArray[1] >= 4 )
        {
            TimeArray[0] = 0;
            TimeArray[1] = 0;
            TimeArray[2] = 0;
            TimeArray[3] = 0;
        }
        else if (TimeArray[0] < 0 || TimeArray[1] < 0 || TimeArray[2] < 0 || TimeArray[3] < 0)
        {
            TimeArray[0] = 0;
            TimeArray[1] = 0;
            TimeArray[2] = 0;
            TimeArray[3] = 0;
        }
        {
            Time =
                (TimeArray[0] * 1000) +
                (TimeArray[1] * 100) +
                (TimeArray[2] * 10) +
                (TimeArray[3] * 1);
        };

    }

}
void Timetable()
{
    unsigned  char SP = 32;  // " " Space
    unsigned  char AA = 175; // » Two arrows 
    unsigned  char BK = 219; // █ Block 
    unsigned  char TL = 201; // ╔ Top Left
    unsigned  char TM = 203; // ╦ Top Middle
    unsigned  char TR = 187; // ╗ Top Right
    unsigned  char LM = 205; // ═ Line Middle
    unsigned  char MM = 186; // ║ Middle Middle
    unsigned  char LL = 204; // ╠ Line Left
    unsigned  char LC = 206; // ╬ Line Center
    unsigned  char LR = 185; // ╣ Line Right
    unsigned  char BL = 200; // ╚ Bottom Left
    unsigned  char BM = 202; // ╩ Bottom Middle
    unsigned  char BR = 188; // ╝ Bottom Right
    int left = 13;           // Size of the left half
    int right = 15;         // Size of the right half
    string Hours = "Hours";
    string Days = "Days";
    string Weekdays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    string InTimes[7];
    string Times[7];
    SetTimetable();

    int StartClass = 0;
    int End = 1;
    for (int R = 0; R < 7; R++)
    {
        Times[R] = OutTime[StartClass] += SP += AA += SP;
        Times[R] += OutTime[End];
        StartClass += 2;
        End += 2;
        Times[R];//= InTimes[R];
    }

    {
        for (int i = 0; i < 7; i++)
        {
            // Times[i] = SetTimetable() + CenterTime + SetTimetable();
            if (Times[i] == "NA")
            {
                for (int x = 0; x < 13; x++)
                {
                    Times[i] += BK;
                }
            }
        }
    }
    string Top, Header, Divider, Content[7], Bottom;
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
    Header = MM; // The header of the timetable
    {
        size_t h, d;
        d = (left - Days.length()) / 2;
        h = (right - Hours.length()) / 2;
        Days += SP;
        for (int i = 0; i < d; i++) { Header += SP; }
        Header += Days;
        for (int i = 0; i < d; i++) { Header += SP; }
        Header += MM;
        for (int i = 0; i < h; i++) { Header += SP; }
        Header += Hours;
        for (int i = 0; i < h; i++) { Header += SP; }


        Header += MM;
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
            size_t v = ((left)-(Weekdays[i].length()) - 1);
            Content[i] += MM;
            Content[i] += SP;
            Content[i] += Weekdays[i];
            for (int j = 0; j < v; j++)
            {
             Content[i] += SP;
            }
            Content[i] += MM;
            Content[i] += SP;
            Content[i] += Times[i];
            Content[i] += SP;
            Content[i] += MM;
        }
    }
    cout << Top << endl;
    cout << Header << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << Divider << endl;
        cout << Content[i] << endl;
    }
    cout << Bottom << endl;

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
    unsigned  char Bs = 92;                            // A Back slash
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
    path = path += Bs +""+ TeacherName += Bs + "Classes"; // Path to folder;
    makefolder(ClassName, path, Warning);            // Makes The folder
    string Fullpath = path += Bs +"" + ClassName;
    makefile("Test ", Fullpath, ClassName); // Makes The file
}
char Gen;// The students Gender.
string gender()
{
    unsigned  char Male = 11;                  // Male Symbol.    
    unsigned  char Female = 12;                // Male Symbol. 
    unsigned  char Fs = 47;                    // A forward slash
    string out = "'s Gender is :";
    switch (Gen)
    {
        case 'M':
        {
            out.append(" Male ");
            out += Male;
        }
        break;
        case 'F':
        {
            out.append(" Female ");
            out += Female;
        }
        break;
        case 'O':
        {
            out.append(" other");
            out += Female+= Fs += Male;
        }
        break;
        default:
        {
            out.append(" Unspecified ");
       
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
    unsigned  char Bs = 92;                              // A Back slash
    unsigned  char Ob = 40;                              // A Open bracket.
    unsigned  char Cb = 41;                              // A Closed bracket.
    unsigned  char Qm = 34;                              // A Quotation mark.
    string Sp =  " ";                                    // A space.
    string gen = gender();                               // the student's gender.
    string Path = str7 + Formatter(str1);                // The path to The file
    string Tb = "^|  ^|";                                // Adds a tab
    string SC = "(echo.";                                // Starts The command
    string EC = ") >";                                   // Ends The command
    string NL = "& echo. & echo";                        // adds a new line to a file
    string L1;                                           // line one
    string L2;                                           // line two
    string L3;                                           // line three
    string T1 = "Name:";                                 // Name
    string T2 = "'s Date of birth:";                     // Dob
    string T3 = "'s Year level:";                        // Year level
    string T4 = "Home address of";                       // Home address
    string T5 = ": ";                                    // Formating :
    string T6 = "Name of";                               // Name of
    string T7 = "'s : ";                                 // Formating 's
    string T8 = "'s Parent/s's Phonenumbers:";           // Parent/s's Phonenumbers
    string T9 = ".txt";                                  // File format

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
    unsigned  char Male = 11;                // Male Symbol.    
    unsigned  char Female = 12;              // Male Symbol.    
    string Bs = "\\";                        // A Back slash.
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
        << "Male "<< Male << " [M]\tFemale "<< Female <<" [F]\t other ? [O] ";
    cin >> Gen;
    Gen = toupper(Gen);
    cout << "The student's  Dob  \n please type in DD-MM-YY Format"; // The Date of birth of The student.
    getline(cin, StudentDOB);
    cout << "The student's  parent/parents's names \n" // The parents's names of The student.
        << "If The parents info is unknown or is not applicable type: NA\n";
    cout << "The student's  father's name :";
    getline(cin, StudentFather);
    cout << "The student's  Mother's name :";
    getline(cin, StudentMother);
    cout << "The student's parent/parents's phone number  \n" // The student's parents's phonenumbers.
        << "If The parents info is unknown or is not applicable type: NA\n";
    cout << "The student's  father's name :";
    getline(cin, FatherPhonenumber);
    cout << "The student's  Mother's name :";
    getline(cin, MotherPhonenumber);
    cout << "The student's  address  "; // The address of The student
    getline(cin, Studentaddress);
    cout << "The student's  Year level  "; // The Year level of The student
    getline(cin, Yearlevel);
    if (StudentFather != "NA") { StudentParents = StudentParents + "Father's name : " + StudentFather; }
    if (StudentMother != "NA") { StudentParents = StudentParents + "Mother's name : " + StudentMother; }
    if (StudentFather == "NA" && StudentMother == "NA") { StudentParents = " Unknown "; }
    if (FatherPhonenumber != "NA") { Phonenumber = Phonenumber + "Father's phonenumber : " + FatherPhonenumber; }
    if (MotherPhonenumber != "NA") { Phonenumber = Phonenumber + "Mother's phonenumber : " + MotherPhonenumber; }
    if (FatherPhonenumber == "NA" && MotherPhonenumber == "NA") { StudentParents = " Unknown "; }
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
        cout << "Invaild input try again" << endl;
    }
    break;
    }
}
int main()
{
   cout << Fixer("Hello world"); cin.ignore();
    Timetable();
   
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
