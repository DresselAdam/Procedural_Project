#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    //Strings userName and password hold user input for creating an account.
    string userName;
    string password;
    cout << "Welcome to OraclProduction Ltd!\n";

    cout << "It seems you are new! Please create a username and password:\n" ;

    cin >> userName;
    cin >> password;

    // Creates text file to hold accounts.
    ofstream accounts;
    accounts.open("accounts.txt");
    // Writes text to accounts file.
    accounts << "Username: " << userName << " - Password: " << password << endl;
    // Menu Output
    cout << "Welcome Aboard! " + userName + "!\n";
    cout << "1. Add Music Player\n" << "2. Add Movie Player\n" << "3. View Production Statistics\n"
         << "4. Create New Employee\n" << "5. Exit\n";

    // Menu choice takes an integer as an input for menu selection.
    int menuChoice;
    cin >> menuChoice;

    // Different paths for menu selection are put into a switch statement
    // Case 5 terminates the program by calling the exit function.
    switch(menuChoice){
        case 1:
            cout << "Music Player Added!" << endl;
            break;
        case 2:
            cout << "Movie Player Added!" << endl;
            break;
        case 3:
            cout << "Display Stats" << endl;
            break;
        case 4:
            cout << "Create New Employee" << endl;
            break;
        case 5:
            cout << "GoodBye!";
            exit(0);
        default:
            cout << "Please choose a valid menu option" << endl;
    }
    return 0;
}