#include <utility>

/** @file main.cpp
 *  @brief Entire media player production program.
 *
 *  This is the main file for the media player production.
 *  This was made in COP 2001 in the summer of 2019.
 *
 *
 *  @author Adam M. Dressel
 *  @bug Login currently broken. Program currently cannot verify usernames past the first line.
 *  The elements added to the vector contain a space that is not recognized.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// prototypes

void showMenu();

/** @brief Adds products to the catalog file,
 *
 *  The addProduct function takes user input and writes strings
 *  to the catalog file. Two menu functions are called to prompt the
 *  user to enter input.
 */
void addProduct();

/** @brief dispStat Calls different functions that show certain production statistics.
 *
 *  First step is to display a menu to prompt user input. A switch case
 *  is used to determine the choice and calls the corresponding function.
 */
void dispStat();

void addEmp();

/**
 * Gets user input with getline for a first and last name. The first name is the characters up until the first space,
 * the last name is the proceeding characters after the first space.
 *
 * @return Returns the userID created from the user input of first and last name.
 */
string getUserID();

/**
 * @brief Creates userID from two strings
 *
 * Creates a userID from the first initial of first name and lowercases of a last name.
 *
 * @param First name and last name.
 * @return Returns the generated userID.
 */
string createUserID(string, const string &);

/**
 * @brief Takes user input to add password.
 *
 * This function takes user input for a password. If input does not match the parameters in check password,
 * the loop continues until a proper password is entered.
 *
 * @return Returns a string value, the password entered encrypted.
 * */
string getEncryptPass();

/**
 * @brief Checks conditions of a string in an if else statement.
 *
 * Uses the string method find_first_of to determine if certain characters are in the string. If characters are not
 * supposed be in the string then the boolean value returned reflects the failure to pass the requirements.
 *
 * @param A string that is chosen as a password.
 * @return Returns a boolean value based on if the string is a proper password based on the given restrictions.
 */
bool checkPassword(const string &);

/**
 * @brief Takes a string and shifts its ascii codes.
 *
 * @param Takes in a string, which is a supposed password.
 * @return Returns the passed in string with shifted ascii codes.
 * */
string encryptPass(string);

/**
 @brief Prints a menu for the user to login or create an account.
 *
 * A switch case calling different functions based on user input.
 *
 * */
void loginMenu();

void outputLoginStr();

/**
 * @brief Gets user input for their username and password and checks whether they are in the employee file.
 *
 * First creates vectors for userID and password by calling corresponding functions. Checks to see if file is empty so
 * user isn't trapped in infinite login. Inputs are given and compared to elements in the vectors that were created.
 * Will continue to ask until matching strings are found.
 *
 * @return Currently returns a string that is the userID when all security checks have been passed.
 *
 * */
string userLogin();

/**
 * @brief Reads the employee file and appends each user to a vector.
 *
 * Reads the text file while there is a line with a space. Space is used as delimiter, and every other string is skipped
 * so only userids are added.
 *
 * @return Returns a list of the users in the text file.
 *
 * */
vector<string> getUsers();

/**
 * @brief Very similar to get users function. Except gets encrypted passwords in employee file.
 * @return Returns a list of password.
 *
 * */
vector<string> getPasswrds();

/**
 * @brief Checks whether or not the user input string matches one of the users in the list of users vector.
 *
 *
 * @param A string, inputted by the user, and a vector of users obtained from the text file.
 * @return A boolean value based on if the user id is found in the vector.
 *
 * */
bool findUserId(const string &, const vector<string> &);

/** @brief menu output choosing an itemType when adding a product
 */
void itemTypeChoice();

/** @brief Creates vectors for holding catalog items.
 *
 *  The catalog text file is opened and read from. The categories
 *  are separated with a comma delimiter, and are added to the corresponding
 *  vectors. The function calls addItems so that items can be produced based on
 *  what is in the catalog file.
 */
void createCatalog();

/** @brief Produces items and adds them to the production file.
 *
 *  The add items function writes products to the production file by taking
 *  using the catalog via vectors. Each category for a product is chosen in a menu,
 *  one by one via three different functions. User chooses amount and products
 *  are added to text file with a for loop.
 *
 *  @param 3 string vectors used as parameters. Used to pass info
 *  from catalog to the production menu.
 */
void addItems(const vector<string> &, const vector<string> &, vector<string>);

/** @brief User is prompted to choose a manufacturer from the catalog.
 *
 *  A menu is outputted in the for loop with a list of all the available manufactuers.
 *  User input is taken, and the matching string is found in the manufacs vector.
 *  @param Takes a vector manufacs, which is a vector of all the
 *  manufacturers in the catalog file. Originally from the createCatalog,
 *  passed to add items and finally passed to this function.
 *  @return A string is returned corresponding to the manufacturer chosen
 *  by the user.
 */
string chooseManu(vector<string> manufacs);

/** @brief User chooses the name corresponding to the manufacturer they chose.
 *
 *  For loop checks for a match between the chosenManu and the corresponding element of manufacs vector.
    The matching index is used to print out the correct product name and add it to namesForMenu.
    The menu takes user input and checks for a match in the for loop. The value of the namesForMenu
    index is chosen based on this input.
 *  @param The first vector is the list of names in the catalog.
 *  @param The second vector is the list of manufacturers in the catalog.
 *  @param The string is the manufacturer returned by chooseManu. Should be
 *  the name of the matching manufacturer.
 *
 *  @return The chosen name is returned as a string.
 */
string chooseName(vector<string>, vector<string>, const string &);

/** @brief Assigns itemType to product being added based on the chosen name.
 *
 *  For loop similar to those in chooseManu and chooseName. Matching string
 *  is found in names and the corresponding index is used to find the related
 *  itemType.
 *  @param first vector string is list of types
 *  @param second vector string is list of names.
 *  @param string is used to align type with corresponding name.
 *  @return Returns a string of the itemType.
 */
string chooseTypes(vector<string> types, vector<string> names, const string &chosenName);

/** @brief Sorts the names of products in the catalog A-Z.
 *
 *  A string vector is created to hold the names of the products in the catalog.
 *  The names are read from the catalog file and added to the vector.
 *  The sort function is used to sort the names.
 */
void sortProdLine();

/** @brief Prints the production text file to std out.
 *
 *  Creates an ifstream object and outputs production file line
 *  by line.
 */
void readProducedItems();

int getProdNum();

/** @brief Finds the production number given a serial number.
 *
 * Production file is siffed through and the production and serial numbers
 * are extracted and added to vectors. User is prompted to type a serial number.
 * If a match is found in the vector, that same index will be used to output the
 * production number. If not output will say no matching serial number was found.
 */
void serialToProd();


/** @brief Calls corresponding functions to run program.
 *
 *  Outputs a menu and user input is taken to traverse through a switch case.
 */
int main() {

    // Call to the welcome menu function.
    // showWelcome();

    //String USERNAME holds user input for creating an account.
    // string USERNAME;
    // cin >> USERNAME;

    // The loop runs until the user exits the program.
    do {
        //loginMenu();
        // Calls the showMenu function that displays the main menu.
        showMenu();
        // Menu choice takes a character as an input for menu selection.
        char menuChoice;
        cin >> menuChoice;

        // Different paths for menu selection are put into a switch statement
        switch (menuChoice) {
            case '1':
                createCatalog();
                break;
            case '2':
                addProduct();
                cout << "Product Added!" << endl;
                break;
            case '3':
                dispStat();
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
    catFile.open("catalog.txt", ofstream::app);
    catFile << manuFac + "," << name + "," << itemType << endl;
    catFile.close();
}

void createCatalog() {
    // Vectors used to store different types of products for menu output.
    vector<string> manufacs;
    vector<string> names;
    vector<string> types;
    // Amount of products to be added to the production file.
    string item;
    ifstream catFile;
    catFile.open("catalog.txt");

    if (catFile.is_open()) {
        // While loop gets string up until comma. While there is a comma
        // file will be read and corresponding string will be assigned to item.
        while (getline(catFile, item, ',')) {
            manufacs.push_back(item);
            getline(catFile, item, ',');
            names.push_back(item);
            getline(catFile, item);
            types.push_back(item);
        }
        catFile.close();
    } else {
        cout << "No products in catalog." << endl;
        return;
    }
    // Call to addItems, each of the vectors are passed as arguments.
    addItems(manufacs, names, types);
}

void dispStat() {
    cout << "Select info to display." << endl;
    cout << "1. Items that have been produced \n" <<
         "2. ProductLine \n" << "3. Find product number by serial number" << endl;
    // Each menu option corresponds to a different function in the program.
    int dispChoice;
    cin >> dispChoice;
    switch (dispChoice) {
        case 1:
            readProducedItems();
            break;
        case 2:
            sortProdLine();
            break;
        case 3:
            serialToProd();
            break;
        default:
            cout << "This is not a valid option.";
    }

}


string chooseManu(vector<string> manufacs) {
    cout << "Please choose a manufacturer" << endl;
    // For loop to iterate through manufacturers and output.
    for (unsigned int i = 0; i < manufacs.size(); i++) {
        cout << i + 1 << ". " << manufacs[i] << endl;
    }

    int choice;
    cin >> choice;
    // Match starts at 1 since user is given options 1 - ...
    // Once a match is found the corresponding index - 1 is returned.
    for (unsigned int match = 1; match <= manufacs.size(); match++) {
        if (match == choice) {
            return manufacs[match - 1];
        }
    }
    //Returns an error if no match is found.
    return "Not a valid menu option.";
}

string chooseName(vector<string> names, vector<string> manufacs, const string &chosenManu) {
    cout << "Please choose an item to produce." << endl;

    // Select names are appended to the namesForMenu vector, for user choice by input.
    vector<string> namesForMenu;

    // For loop checks for a match between the chosenManu and the corresponding element of manufacs vector.
    // The matching index is used to print out the correct product name and add it to namesForMenu.
    int i = 0;
    for (unsigned int n = 0; n < names.size(); n++) {
        if (manufacs[n] == chosenManu) {
            cout << i + 1 << ". " << names[n] << endl;
            namesForMenu.push_back(names[n]);
            i++;
        }
    }
    int choice;
    cin >> choice;
    // For loop checks to see if the user choice  matches the iterator, and then returns the
    // corresponding index from the namesForMenu made in the previous loop.
    for (unsigned int match = 1; match <= namesForMenu.size(); match++) {
        if (match == choice) {
            return namesForMenu[match - 1];
        }
    }

    //Returns an error if no match is found.
    return "Not a valid menu option.";

}

string chooseTypes(vector<string> types, vector<string> names, const string &chosenName) {
    // For loop similar to loops in chooseManu and chooseName.
    for (unsigned int match = 0; match < types.size(); match++) {
        if (names[match] == chosenName) {
            return types[match];
        }
    }
    // Returns an error if no match is found.
    return "Not a valid menu option.";
}

void addItems(const vector<string> &manufacs, const vector<string> &names, vector<string> types) {
    string manufac = chooseManu(manufacs);
    if (manufac == "Not a valid menu option.") {
        cout << manufac << endl;
        return;
    }
    string name = chooseName(names, manufacs, manufac);
    if (name == "Not a valid menu option.") {
        cout << name << endl;
        return;
    }
    string type = chooseTypes(move(types), names, name);
    if (type == "Not a valid menu option.") {
        cout << type << endl;
        return;
    }
    cout << "How many of this item were produced?" << endl;
    int amount;
    cin >> amount;

    int prodNum = getProdNum();
    ofstream prodFile;
    prodFile.open("production.txt", ofstream::app);

    for (int serialNum = 1; serialNum <= amount; serialNum++) {
        prodFile << "Production Number-" << ++prodNum << "-" << "Serial Number-" <<
                 manufac.substr(0, 3) << type << setw(5) << setfill('0') << serialNum << endl;
    }
    prodFile.close();
    cout << "Items Added!" << endl;
}

void sortProdLine() {
    vector<string> names;

    ifstream catFile;
    catFile.open("catalog.txt");
    string item;
    // This while loop is very similar to the one in createCatalog.
    if (catFile.is_open()) {
        while (getline(catFile, item, ',')) {
            getline(catFile, item, ',');
            names.push_back(item);
            getline(catFile, item);
        }
        catFile.close();
    } else {
        cout << "Cannot open file.";
    }
    sort(names.begin(), names.end());
    for (const string &name: names) {
        cout << name << endl;
    }
}

void readProducedItems() {
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

int getProdNum() {
    string line;
    int prodNum = 0;
    // Chooses file to read from.
    ifstream readFile("production.txt");
    if (readFile.is_open()) {
        // Gets a line from the text file and increments prodNum for each line.
        while (getline(readFile, line)) {
            prodNum++;
        }
    }
    return prodNum;
}

void serialToProd() {
    vector<string> prodNums;
    vector<string> serNums;
    string num;
    ifstream prodFile;
    prodFile.open("production.txt");

    // This while loop is similar to others used to read textfiles, but uses
    // the dash character as an optional delimiter.
    if (prodFile.is_open()) {
        // Since locations are known, only the second and fourth num in the loop
        // are added to the vectors.
        while (getline(prodFile, num, '-')) {
            getline(prodFile, num, '-');
            prodNums.push_back(num);
            getline(prodFile, num, '-');
            getline(prodFile, num);
            serNums.push_back(num);
        }
        prodFile.close();
    } else {
        cout << "Cannot open file.";
    }

    cout << "Enter serial number" << endl;
    string serialNum;
    bool foundSerial = false;
    cin >> serialNum;

    for (unsigned int n = 0; n < serNums.size(); n++) {
        if (serNums[n] == serialNum) {
            foundSerial = true;
            cout << prodNums[n] << endl;
        }
    }
    if (!foundSerial) {
        cout << "No matching serial number found" << endl;
    }
}

// Add employee function is a work in progress.
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
    vector<string> listOfPasswords = getPasswrds();

    // Make sure there are users in the employee listing.
    if (listOfUsers.empty()) {
        cout << "No employees at this time." << endl;
        loginMenu();
    }
    string userID;
    string password;
    bool foundUser;

    cout << "Enter your userID: " << endl;
    do {
        cin >> userID;
        cout << listOfUsers[1];
        foundUser = findUserId(userID, listOfUsers);
    } while (!foundUser);

    // Finding index where userID is to check the corresponding password.
    int i;
    for (i = 0; i < listOfUsers.size(); i++) {
        if (userID == listOfUsers[i]) {
            break;
        } else {

        }
    }
    bool matchPass = true;
    cout << "Enter your password: " << endl;
    do {
        cin >> password;
        // Changed to encrypted version for comparison.
        password = encryptPass(password);
        if (password == listOfPasswords[i]) {
            cout << "Success!" << endl;
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

vector<string> getPasswrds() {
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