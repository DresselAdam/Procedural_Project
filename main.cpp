#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>

using namespace std;

void showMenu(string);
void showWelcome();

int main() {
    showWelcome();

    //Strings userName and password hold user input for creating an account.
    string userName;
    string password;

    cin >> userName;

    showMenu(userName);

    bool menuOpt;
    // Different paths for menu selection are put into a switch statement
    // Case 5 terminates the program by calling the exit function.
    do {

        int menuChoice;
        // Menu choice takes an integer as an input for menu selection.
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                cout << "Production Function" << endl;
                menuOpt = true;
                break;
            case 2:
                cout << "Display Stats" << endl;
                menuOpt = true;
                break;
            case 3:
                cout << "Create New Employee" << endl;
                menuOpt = true;
                break;
            case 4:
                cout << "GoodBye!";
                exit(0);
            default:
                menuOpt = false;
                cout << "Please choose a valid menu option" << endl;
        }
    }while(!menuOpt);
    return 0;
}

void showWelcome() {
    cout << "Welcome to OraclProduction Ltd!\n";

    cout << "It seems you are new! Please create a username:\n" ;
}

void showMenu(string userName) {
// Menu Output
    cout << "Welcome Aboard " + userName + "! Please choose a menu option.\n";
    cout << "1. Add Production\n" << "2. View Production Statistics\n"
         << "3. Create New Employee\n" << "4. Exit\n";

}