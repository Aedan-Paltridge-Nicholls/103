#include <iostream>
#include <string>
using namespace std;

void startup()
{
 system("if not exist C:\\logins\\Teachers mkdir C:\\logins\\Teachers");
}


int main()
{
    
    startup();
    cout << "Hello World!\n";
}