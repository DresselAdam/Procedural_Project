#include <iostream>

using namespace std;

int main() {
    string empName;
    cout << "Welcome to OraclProduction Ltd!\n";
    cout << "It seems you are new! Please enter your name and we'll create an employee account for you.\n" ;
    cin >> empName;
    cout << "Welcome Aboard " + empName + "!\n";
    cout << "1. Add Music Player\n" << "2. Add Movie Player\n" << "3. View Production Statistics\n"
         << "4. Create New Employee\n" << "5. Exit";
    return 0;
}