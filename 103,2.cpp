#include <iostream>
#include <string>
using namespace std;
char* Fixer(string InpStr)
{
  std::string Str17 = InpStr;
  char *Fixer = new char[Str17.length()+1];//Creates the char* fixer and makes it one longer than str7.
  strcpy(Fixer,Str17.c_str());//Makes the char* fixer and makes have the same content as str7.
  return Fixer;
}
void startup()//Checks if the files for the programm exist and if not creates them.
{
 system("if not exist C:\\logins\\Teachers mkdir C:\\logins\\Teachers");
}
void AddATeacher()
{ 
  string Check = "if not exist ";
  string path = "C:\\logins\\Teachers";//Path to folder;
  string command = " (mkdir ";
  string command2 = " else (echo Teacher already exists) ";
  string name ="\\";
  string input ="";
  cout <<"Name of Teacher : ";
  cin >>  input ;
  name.append(input);
  path.append(name);
  command.append(path);
  string finalcommand = Check + path + command + ')' + command2;
  Fixer(finalcommand);
  system(Fixer(finalcommand));//
  system("TREE C:\\logins");
}
void AddAClass()
{ 

}

int main()
{
   system("TREE C:\\logins");
   startup();
   AddATeacher();
  cout << "Hello World!\n";
}