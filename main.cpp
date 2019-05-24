#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <iomanip>

using namespace std;

// prototypes
void showMenu(string);

void showWelcome();

void addProduct();

void dispStat();

void addEmp();

// product number is tracked independently of the type of product.
// This int is still looking for a better home.
int prodNum = 1;

int main() {
    // Call to the welcome menu function.
    showWelcome();

    //String USERNAME holds user input for creating an account.
    string USERNAME;
    cin >> USERNAME;

    // The loop runs until the user exits the program.
    do {
        // Calls the showMenu function that displays the main menu.
        showMenu(USERNAME);
        // Menu choice takes a character as an input for menu selection.
        char menuChoice;
        cin >> menuChoice;

        // Different paths for menu selection are put into a switch statement
        switch (menuChoice) {
            case '1':
                addProduct();
                cout << "Products Added!" << endl;
                break;
            case '2':
                dispStat();
                break;
            case '3':
                addEmp();
                break;
                // Case 4 terminates the program by calling the exit function.
            case '4':
                cout << "GoodBye!";
                exit(0);
            default:
                cout << "Please choose a valid menu option" << endl;
        }
    } while (true);
}

// First welcome screen.
void showWelcome() {
    cout << "Welcome to OraclProduction Ltd!\n";

    cout << "It seems you are new! Please create a username:\n";
}

// Main menu output, takes in the USERNAME as a parameter to use in print statement
void showMenu(string USERNAME) {
// Menu Output
    cout << "Welcome " + USERNAME + "! Please choose a menu option.\n";
    cout << "1. Add Production\n" << "2. View Production Statistics\n"
         << "3. Create New Employee\n" << "4. Exit\n";

}

// Outputs the beginning of the production menu.
// Parameters are given the values of the user input.
// The values inputted are pointed to the reference where
// original argument was passed.
void prodMenu(string &manuFac, string &name) {
    cout << "Enter the product manufacturer: \n";
    cin >> manuFac;
    cout << "Enter the product Name: \n";
    cin >> name;
    cout << "Select an itemType: \n";
}

// Displays the menu for choosing what time of item
// the product added will be.
void itemChoice() {
    cout << "1. Audio (\"MM\") \n" << "2. Visual (\"VI\") \n" <<
         "3. AudioMobile(\"AM\") \n" << "4. VisualMobile(\"VM\")" << endl;
}

// addProduct function is used to add and save products to inventory.
void addProduct() {
    // Variables for product records
    string manuFac;
    string name;
    string itemType;
    // typeChoice is an integer that will be used to determine which
    // menu option is chosen for the corresponding itemtype.
    int typeChoice;

    // Call to the production menu function
    // User input is written to the arguments that are passed to the function.
    prodMenu(manuFac, name);
    // Calls the itemChoice function to display the itemType menu.
    itemChoice();
    // User input is given after they are shown menu options.
    cin >> typeChoice;

    // itemType will be assigned based on the menu choice the user selects.
    switch (typeChoice) {
        case 1:
            itemType = "MM";
            break;
        case 2:
            itemType = "VI";
            break;
        case 3:
            itemType = "AM";
            break;
        case 4:
            itemType = "VM";
            break;
        default:
            break;
    }
    // Amount of products to be added to the production file.
    int amount;
    cout << "How many were produced:";
    cin >> amount;

    // File used to store products added to inventory.
    ofstream prodFile;
    prodFile.open("production.txt", ofstream::app);

    // For loop iterates through the # of items added by the user
    // Each product is written to the production.txt file via prodFile object.

    for (int i = 1; i <= amount; i++) {
        // manuFac.substr takes the first three characters of the manufacturer name.
        string serialNum = manuFac.substr(0, 3) + itemType;
        prodFile << "Production Number: " << prodNum << " Serial Number: "
                 << serialNum << setfill('0') << setw(5) << i << endl;
        prodNum++;
    }

}

// dispStat shows the production statistics.
// Read from the production.txt file
void dispStat() {
    string line;

    // Chooses file to read from.
    ifstream readFile("production.txt");
    if (readFile.is_open()) {
        // Gets a line from the text file and puts the line into the string line.
        while (getline(readFile, line)) {
            cout << line << "\n";
        }
    }
}

// Add employee function is a work in progress.
void addEmp() {
    cout << "Work in progress..." << endl;
}
