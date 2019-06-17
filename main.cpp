

/** @file main.cpp
 *  @brief Entire media player production program.
 *
 *  This is the main file for the media player production.
 *  This was made in COP 2001 in the summer of 2019.
 *
 *
 *  @author Adam M. Dressel
 *
 */
#include <utility>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string manu;
    string name;
    string itemType;
};

struct ProdRecord {
    string prodNum;
    string serialNum;
    string name;
    string manufac;
    string type;
};

struct prodRecStats {
    int prodNum;
    int MMcount;
    int VIcount;
    int VMcount;
    int AMcount;
};
/*
struct Employee {
    string userID;
    string password;
};
*/

#include "prototypes.h"

/** @brief Calls corresponding functions to run program.
 *
 *  Outputs a menu and user input is taken to traverse through a switch case.
 */
int main() {

    loginMenu();

    // The loop runs until the user exits the program.
    do {
        // Product vector used to store each producible item.
        vector<Product> catalog;
        createCatalog(catalog);
        // ProdRecord vector holds the record of each item produced
        vector<ProdRecord> prodLog;
        // Adds production and serial numbers to prodLog
        readProducedItems(prodLog);

        prodRecStats prodLineRecord = {0, 0, 0, 0, 0};
        countTypes(prodLineRecord, prodLog);

        // Calls the showMenu function that displays the main menu.
        showMenu();
        // Menu choice takes a character as an input for menu selection.
        char menuChoice;
        cin >> menuChoice;

        // Different paths for menu selection are put into a switch statement
        switch (menuChoice) {
            case '1':
                addItems(catalog, prodLog);
                break;
            case '2':
                addProduct();
                cout << "Product Added!" << endl;
                break;
            case '3':
                dispStat(catalog, prodLog, prodLineRecord);
                break;
            case '4':
                addEmp();
                break;
                // Case 4 terminates the program by calling the exit function.
            case '5':
                cout << "GoodBye!";
                exit(0);
            default:
                cout << "Please choose a valid menu option" << endl;
        }
    } while (true);
}

void showMenu() {
// Menu Output
    cout << "Welcome! Please choose a menu option.\n";
    cout << "1. Produce Items\n" << "2. Add Items to ProductLine \n"
         << "3. View Production Statistics\n" << "4. Create New Employee\n" << "5. Exit\n";

}

void prodMenu(string &manuFac, string &name, int &typeChoice, string &itemType) {
    cout << "Enter the product manufacturer: \n";
    cin >> manuFac;
    cout << "Enter the product Name: \n";
    cin >> name;

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
}

void itemTypeChoice() {
    cout << "Select an itemType: \n";
    cout << "1. Audio (\"MM\") \n" << "2. Visual (\"VI\") \n" <<
         "3. AudioMobile(\"AM\") \n" << "4. VisualMobile(\"VM\")" << endl;
}

void addProduct() {
    // Variables for product records
    string manuFac;
    string name;
    string itemType;
    // typeChoice is an integer that will be used to determine which
    // menu option is chosen for the corresponding itemtype.
    int typeChoice;
    // Calls the itemTypeChoice function to display the itemType menu.
    itemTypeChoice();
    cin >> typeChoice;
    // Call to the production menu function
    // User input is written to the arguments that are passed to the function.

    prodMenu(manuFac, name, typeChoice, itemType);
    // File used to store products added to inventory.
    ofstream catFile;
    catFile.open("ProductLine.csv", ofstream::app);
    catFile << manuFac + "," << name + "," << itemType << endl;
    catFile.close();
}

vector<Product> createCatalog(vector<Product> &catalog) {

    // Item holds the place when reading the file.
    string item;
    ifstream catFile;
    catFile.open("ProductLine.csv");

    // Increments each time a line is extracted from the file.
    int lineNum = 0;
    if (catFile.is_open()) {
        // While loop gets string up until comma. While there is a comma
        // file will be read and corresponding string will be assigned to item.
        while (getline(catFile, item, ',')) {
            // New Product object is initialized and pushed to the catalog vector.
            Product line = Product();
            catalog.push_back(line);
            catalog[lineNum].manu = item;
            getline(catFile, item, ',');
            catalog[lineNum].name = item;
            getline(catFile, item);
            catalog[lineNum].itemType = item;
            lineNum++;
        }
        catFile.close();
    }

    return catalog;
}

void dispStat(vector<Product> &catalog, vector<ProdRecord> &prodLog, prodRecStats &prodLineStats) {
    cout << "Select info to display." << endl;
    cout << "1. Display inventory by type. \n" <<
         "2. ProductLine \n" << "3. Find product number by serial number" << endl;
    // Each menu option corresponds to a different function in the program.
    int dispChoice;
    cin >> dispChoice;

    //prodRecStats prodLineStats = {0, 0, 0, 0, 0};
    switch (dispChoice) {
        case 1:
            printTypeStats(prodLineStats);
            break;
        case 2:
            sortProdLine(prodLog);
            break;
        case 3:
            serialToProd(prodLog);
            break;
        default:
            cout << "This is not a valid option.";
    }

}

void countTypes(prodRecStats &prodLineStat, vector<ProdRecord> &itemLog) {
    for (const ProdRecord &item: itemLog) {
        if (item.type == "VI") {
            prodLineStat.VIcount++;
        } else if (item.type == "MM") {
            prodLineStat.MMcount++;
        } else if (item.type == "AM") {
            prodLineStat.AMcount++;
        } else {
            prodLineStat.VMcount++;
        }
    }
    prodLineStat.prodNum = prodLineStat.VMcount + prodLineStat.VIcount + prodLineStat.AMcount + prodLineStat.MMcount;
}

void printTypeStats(prodRecStats &prodLineStat) {
    cout << "Items Produced: " << prodLineStat.prodNum << endl
         << "VM items produced: " << prodLineStat.VMcount << endl << "AM items produced: " << prodLineStat.AMcount <<
         endl << "MM items produced: " << prodLineStat.MMcount << endl << "VI items produced: " << prodLineStat.VIcount
         << endl;
}

int chooseProduct(vector<Product> &catalog) {
    cout << "Please choose a product to produce:" << endl;
    // For loop to iterate through manufacturers and output.
    for (unsigned int i = 0; i < catalog.size(); i++) {
        cout << i + 1 << ". " << catalog[i].name << endl;
    }

    int choice;
    cin >> choice;
    // Match starts at 1 since user is given options 1 - ...
    // Once a match is found the corresponding index - 1 is returned.
    for (unsigned int match = 1; match <= catalog.size(); match++) {
        if (match == choice) {
            return match - 1;
        }
    }
    //Returns an error if no match is found.
    return -1;
}

void addItems(vector<Product> &catalog, vector<ProdRecord> &prodLog) {
    if (catalog.empty()) {
        cout << "No products in catalog." << endl;
        return;
    }
    int productIndex = chooseProduct(catalog);
    if (productIndex == -1) {
        cout << "Not a valid product" << endl;
        return;
    }
    string name = catalog[productIndex].name;
    string manufac = catalog[productIndex].manu;
    string itemType = catalog[productIndex].itemType;

    cout << "How many of this item were produced?" << endl;
    int amount;
    cin >> amount;

    int prodNum;
    if (prodLog.empty()) {
        prodNum = 0;
    } else {
        string strProdNum = prodLog[prodLog.size() - 1].prodNum;
        prodNum = stoi(strProdNum);
    }

    ofstream prodFile;
    prodFile.open("ProductionLog.csv", ofstream::app);

    for (int serialNum = 1; serialNum <= amount; serialNum++) {
        prodFile << name << "," << manufac << "," << itemType << "," << ++prodNum << "," << manufac.substr(0, 3) <<
                 itemType << setw(5) << setfill('0') << serialNum << endl;
    }
    prodFile.close();
    cout << "Items Added!" << endl;
}

void sortProdLine(vector<ProdRecord> &itemsLog) {
    if (itemsLog.empty()) {
        cout << "No items have been produced." << endl;
        return;
    }

    vector<string> names;

    names.reserve(itemsLog.size());
    for (const ProdRecord &item: itemsLog) {
        names.push_back(item.name);
    }
    sort(names.begin(), names.end());
    for (const string &name: names) {
        cout << name << endl;
    }
}

void readProducedItems(vector<ProdRecord> &prodLog) {
    string line;
    // Chooses file to read from.
    int lineNum = 0;
    ifstream readFile("ProductionLog.csv");
    if (readFile.is_open()) {
        // Gets a line from the text file and puts the line into the string line.
        while (getline(readFile, line, ',')) {
            ProdRecord product = ProdRecord();
            prodLog.push_back(product);
            prodLog[lineNum].name = line;
            getline(readFile, line, ',');
            prodLog[lineNum].manufac = line;
            getline(readFile, line, ',');
            prodLog[lineNum].type = line;
            getline(readFile, line, ',');
            prodLog[lineNum].prodNum = line;
            getline(readFile, line);
            prodLog[lineNum].serialNum = line;
            lineNum++;
        }
    } else {
        // Exits function if no products are in the log.
        return;
    }
}

void serialToProd(vector<ProdRecord> &itemsLog) {

    if (itemsLog.empty()) {
        cout << "No items have been produced." << endl;
        return;
    }
    cout << "Enter serial number" << endl;
    string serialNum;
    do {
        cin >> serialNum;
        for (const ProdRecord &item : itemsLog) {
            if (item.serialNum == serialNum) {
                cout << "Production Number: " << item.prodNum << " Manufacturer: " << item.manufac << " Product: " <<
                     item.name << " ItemType: " << item.type << endl;
                return;
            }
        }
        cout << "No product with that serial number found. Try again." << endl;
    } while (true);
}

void addEmp() {
    string userID = getUserID();
    string encryptPass = getEncryptPass();
    cout << "Your userID is: " << userID << endl;

    ofstream accountsFile;
    accountsFile.open("Employees.txt", ofstream::app);
    accountsFile << userID << ' ' << encryptPass << endl;
}

string getUserID() {
    string name;
    cout << "Please enter your first and last name, separated by a space." << endl;

    cin.ignore();
    getline(cin, name);

    // Finds where the first and last name are separated.
    int space = name.find_first_of(' ');

    string firstName;
    string surName;
    // Loop iterates up until the first space, adds each char to first name.
    for (int letter = 0; letter < space; letter++) {
        firstName.push_back(name[letter]);
    }
    // Index letter starts at the char after the first space. Iterates until the end of string and adds to surName.
    for (int letter = space + 1; letter < name.size(); letter++) {
        surName.push_back(name[letter]);
    }
    return createUserID(firstName, surName);
}

string createUserID(string firstName, const string &surName) {
    string userID;
    // Adds first letter of firstName to userID
    userID.push_back(static_cast<const char>(tolower(firstName[0])));
    // iterates through surName and converts each character to lower before adding to userID.
    for (char letter: surName) {
        userID.push_back(static_cast<const char>(tolower(letter)));
    }

    return userID;
}

string getEncryptPass() {
    string password;
    cout << "Please enter a password with atleast 1 digit, 1 uppercase and 1 lowercase character. " <<
         "spaces and symbols are not allowed.";
    do {

        getline(cin, password);

    } while (!checkPassword(password));

    cout << "Your password is: " << password << endl;
    return encryptPass(password);
}

bool checkPassword(const string &password) {
    // Checks to see if the find method returns null. Thus no match was found.
    if (password.find(' ') != -1 || password.find_first_of("!@#$%^&*()-_=+*[{]};:\'\"|/.,><`~") != -1 ||
        password.find_first_of("qwertyuiopasdfghjklzxcvbnm") == -1
        || password.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM") == -1 ||
        password.find_first_of("1234567890") == -1) {
        cout << "Invalid password." << endl;
        return false;
    } else {
        return true;
    }

}

string encryptPass(string password) {
    string ascii;
    int asciiVal;
    int i = 0;
    for (char letter:password) {
        asciiVal = (int) letter + 3;
        password[i] = (char) asciiVal;
        i++;
    }
    return password;

}

void loginMenu() {
    bool badChoice;
    char userChoice;
    do {
        badChoice = false;
        outputLoginStr();

        cin >> userChoice;

        switch (userChoice) {
            case '1':
                userLogin();
                break;
            case '2':
                addEmp();
                break;
            case '3':
                cout << "Goodbye!";
                exit(0);
            default:
                badChoice = true;
        }
    } while (badChoice);
}

void outputLoginStr() {
    cout << "Welcome, please sign in or create an account." << endl;
    cout << "1. Login" << endl << "2. Create an account." << endl;
    cout << "3. Exit" << endl;
}

string userLogin() {
    vector<string> listOfUsers = getUsers();
    vector<string> listOfPasswords = getPasswords();

    // Make sure there are users in the employee listing.
    if (listOfUsers.empty()) {
        cout << "No employees at this time." << endl;
        loginMenu();
    }
    string userID;
    string password;
    bool foundUser;

    do {
        cout << "Enter your userID:" << endl;
        cin >> userID;
        foundUser = findUserId(userID, listOfUsers);
    } while (!foundUser);

    // Finding index where userID is to check the corresponding password.
    int i;
    for (i = 0; i < listOfUsers.size(); i++) {
        if (userID == listOfUsers[i]) {
            break;
        }
    }
    bool matchPass;
    cout << "Enter your password: " << endl;
    do {
        cin >> password;
        // Changed to encrypted version for comparison.
        password = encryptPass(password);
        if (password == listOfPasswords[i]) {
            cout << "Success!" << endl;
            matchPass = true;
        } else {
            cout << "Wrong password." << endl;
            matchPass = false;
        }
    } while (!matchPass);

    return userID;
}

vector<string> getUsers() {
    vector<string> userIDs;
    string userID;
    ifstream empFile;
    empFile.open("Employees.txt");
    if (empFile.is_open()) {
        while (getline(empFile, userID, ' ')) {
            userIDs.push_back(userID);
            getline(empFile, userID);
        }
    } else {
        cout << "Could not open file." << endl;
    }
    return userIDs;
}

vector<string> getPasswords() {
    vector<string> passwords;
    string password;
    ifstream empFile;
    empFile.open("Employees.txt");
    if (empFile.is_open()) {
        while (getline(empFile, password, ' ')) {
            getline(empFile, password);
            passwords.push_back(password);
        }
    } else {
        cout << "Could not open file." << endl;
    }
    return passwords;
}

bool findUserId(const string &userID, const vector<string> &userIDs) {
    for (const string &id: userIDs) {
        if (userID == id || (" " + userID) == id) {
            return true;
        }
    }
    cout << "No user found with that ID. Try again." << endl;
    return false;
}