

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

#include "cmake-build-debug/CMakeFiles/structs.h"

#include "prototypes.h"

/**
 * @brief Takes a string and shifts its ascii codes.
 *
 * @param Takes in a string, which is a supposed password.
 * @return Returns the passed in string with shifted ascii codes.
 * */
string encrypt_pass(string);

/** @brief Calls corresponding functions to run program.
 *
 *  Outputs a menu and user input is taken to traverse through a switch case.
 */
int main()
{

    login_menu();

    // The loop runs until the user exits the program.
    do {
        // Product vector used to store each producible item.
        vector<Product> catalog;
        create_catalog(catalog);
        // Prod_record vector holds the record of each item produced
        vector<Prod_record> prod_log;
        // Adds production and serial numbers to prod_log
        read_produced_items(prod_log);

        Prod_rec_stat prod_line_record = {0, 0, 0, 0, 0};
        count_types(prod_line_record, prod_log);

        // Calls the show_menu function that displays the main menu.
        show_menu();
        // Menu choice takes a character as an input for menu selection.
        char menu_choice;
        cin >> menu_choice;

        // Different paths for menu selection are put into a switch statement
        switch (menu_choice) {
        case '1':
            add_items(catalog, prod_log);
            break;
        case '2':
            add_product();
            cout << "Product Added!" << endl;
            break;
        case '3':
            display_stat(catalog, prod_log, prod_line_record);
            break;
        case '4':
            add_emp();
            break;
            // Case 4 terminates the program by calling the exit function.
        case '5':
            cout << "GoodBye!";
            exit(0);
        default:
            cout << "Please choose a valid menu option" << endl;
        }
    }
    while (true);
}

void show_menu()
{
// Menu Output
    cout << "Welcome! Please choose a menu option.\n";
    cout << "1. Produce Items\n" << "2. Add Items to ProductLine \n"
         << "3. View Production Statistics\n" << "4. Create New Employee\n" << "5. Exit\n";

}

void prod_menu(string& manuFac, string& name, int& type_choice, string& item_type)
{
    cout << "Enter the product manufacturer: \n";
    cin >> manuFac;
    cout << "Enter the product Name: \n";
    cin >> name;

    // item_type will be assigned based on the menu choice the user selects.
    switch (type_choice) {
    case 1:
        item_type = "MM";
        break;
    case 2:
        item_type = "VI";
        break;
    case 3:
        item_type = "AM";
        break;
    case 4:
        item_type = "VM";
        break;
    default:
        break;
    }
}

void item_type_choice()
{
    cout << "Select an item_type: \n";
    cout << "1. Audio (\"MM\") \n" << "2. Visual (\"VI\") \n" <<
         "3. AudioMobile(\"AM\") \n" << "4. VisualMobile(\"VM\")" << endl;
}

void add_product()
{
    // Variables for product records
    string manuFac;
    string name;
    string item_type;
    // type_choice is an integer that will be used to determine which
    // menu option is chosen for the corresponding itemtype.
    int type_choice;
    // Calls the item_type_choice function to display the item_type menu.
    item_type_choice();
    cin >> type_choice;
    // Call to the production menu function
    // User input is written to the arguments that are passed to the function.

    prod_menu(manuFac, name, type_choice, item_type);
    // File used to store products added to inventory.
    ofstream catFile;
    catFile.open("ProductLine.csv", ofstream::app);
    catFile << manuFac+"," << name+"," << item_type << endl;
    catFile.close();
}

vector<Product> create_catalog(vector<Product>& catalog)
{

    // Item holds the place when reading the file.
    string item;
    ifstream cat_file;
    cat_file.open("ProductLine.csv");

    // Increments each time a line is extracted from the file.
    int line_num = 0;
    if (cat_file.is_open()) {
        // While loop gets string up until comma. While there is a comma
        // file will be read and corresponding string will be assigned to item.
        while (getline(cat_file, item, ',')) {
            // New Product object is initialized and pushed to the catalog vector.
            Product line = Product();
            catalog.push_back(line);
            catalog[line_num].manu = item;
            getline(cat_file, item, ',');
            catalog[line_num].name = item;
            getline(cat_file, item);
            catalog[line_num].item_type = item;
            line_num++;
        }
        cat_file.close();
    }

    return catalog;
}

void display_stat(vector<Product>& catalog, vector<Prod_record>& prod_log, Prod_rec_stat& prod_line_stat)
{
    cout << "Select info to display." << endl;
    cout << "1. Display inventory by type. \n" <<
         "2. ProductLine \n" << "3. Find product number by serial number" << endl;
    // Each menu option corresponds to a different function in the program.
    int disp_choice;
    cin >> disp_choice;

    //Prod_rec_stat prod_line_stat = {0, 0, 0, 0, 0};
    switch (disp_choice) {
    case 1:
        print_type_stats(prod_line_stat);
        break;
    case 2:
        sort_prod_line(prod_log);
        break;
    case 3:
        serial_to_prod(prod_log);
        break;
    default:
        cout << "This is not a valid option.";
    }

}

void count_types(Prod_rec_stat& prod_line_stat, vector<Prod_record>& item_log)
{
    for (const Prod_record& item: item_log) {
        if (item.type=="VI") {
            prod_line_stat.VI_count++;
        }
        else if (item.type=="MM") {
            prod_line_stat.MM_count++;
        }
        else if (item.type=="AM") {
            prod_line_stat.AM_count++;
        }
        else {
            prod_line_stat.VM_count++;
        }
    }
    prod_line_stat.prodNum =
            prod_line_stat.VM_count+prod_line_stat.VI_count+prod_line_stat.AM_count+prod_line_stat.MM_count;
}

void print_type_stats(Prod_rec_stat& prod_line_stat)
{
    cout << "Items Produced: " << prod_line_stat.prodNum << endl
         << "VM items produced: " << prod_line_stat.VM_count << endl << "AM items produced: " << prod_line_stat.AM_count
         <<
         endl << "MM items produced: " << prod_line_stat.MM_count << endl << "VI items produced: "
         << prod_line_stat.VI_count
         << endl;
}

int choose_product(vector<Product>& catalog)
{
    cout << "Please choose a product to produce:" << endl;
    // For loop to iterate through manufacturers and output.
    for (unsigned int i = 0; i<catalog.size(); i++) {
        cout << i+1 << ". " << catalog[i].name << endl;
    }

    int choice;
    cin >> choice;
    // Match starts at 1 since user is given options 1 - ...
    // Once a match is found the corresponding index - 1 is returned.
    for (unsigned int match = 1; match<=catalog.size(); match++) {
        if (match==choice) {
            return match-1;
        }
    }
    //Returns an error if no match is found.
    return -1;
}

void add_items(vector<Product>& catalog, vector<Prod_record>& prod_log)
{
    if (catalog.empty()) {
        cout << "No products in catalog." << endl;
        return;
    }
    int product_index = choose_product(catalog);
    if (product_index==-1) {
        cout << "Not a valid product" << endl;
        return;
    }
    string name = catalog[product_index].name;
    string manufac = catalog[product_index].manu;
    string item_type = catalog[product_index].item_type;

    cout << "How many of this item were produced?" << endl;
    int amount;
    cin >> amount;

    int prod_num;
    if (prod_log.empty()) {
        prod_num = 0;
    }
    else {
        string str_prod_num = prod_log[prod_log.size()-1].prod_num;
        prod_num = stoi(str_prod_num);
    }

    ofstream prod_file;
    prod_file.open("ProductionLog.csv", ofstream::app);

    for (int serial_num = 1; serial_num<=amount; serial_num++) {
        prod_file << name << "," << manufac << "," << item_type << "," << ++prod_num << "," << manufac.substr(0, 3) <<
                  item_type << setw(5) << setfill('0') << serial_num << endl;
    }
    prod_file.close();
    cout << "Items Added!" << endl;
}

void sort_prod_line(vector<Prod_record>& items_log)
{
    if (items_log.empty()) {
        cout << "No items have been produced." << endl;
        return;
    }

    vector<string> names;

    names.reserve(items_log.size());
    for (const Prod_record& item: items_log) {
        names.push_back(item.name);
    }
    sort(names.begin(), names.end());
    for (const string& name: names) {
        cout << name << endl;
    }
}

void read_produced_items(vector<Prod_record>& prod_log)
{
    string line;
    // Chooses file to read from.
    int line_num = 0;
    ifstream readFile("ProductionLog.csv");
    if (readFile.is_open()) {
        // Gets a line from the text file and puts the line into the string line.
        while (getline(readFile, line, ',')) {
            Prod_record product = Prod_record();
            prod_log.push_back(product);
            prod_log[line_num].name = line;
            getline(readFile, line, ',');
            prod_log[line_num].manufac = line;
            getline(readFile, line, ',');
            prod_log[line_num].type = line;
            getline(readFile, line, ',');
            prod_log[line_num].prod_num = line;
            getline(readFile, line);
            prod_log[line_num].serialNum = line;
            line_num++;
        }
    }
    else {
        // Exits function if no products are in the log.
        return;
    }
}

void serial_to_prod(vector<Prod_record>& items_log)
{

    if (items_log.empty()) {
        cout << "No items have been produced." << endl;
        return;
    }
    cout << "Enter serial number" << endl;
    string serial_num;
    do {
        cin >> serial_num;
        for (const Prod_record& item : items_log) {
            if (item.serialNum==serial_num) {
                cout << "Production Number: " << item.prod_num << " Manufacturer: " << item.manufac << " Product: " <<
                     item.name << " ItemType: " << item.type << endl;
                return;
            }
        }
        cout << "No product with that serial number found. Try again." << endl;
    }
    while (true);
}

void add_emp()
{
    string user_id = get_user_ID();
    string encrypted_pass = get_encrypt_pass();
    cout << "Your user_id is: " << user_id << endl;

    ofstream accounts_file;
    accounts_file.open("Employees.txt", ofstream::app);
    accounts_file << user_id << ' ' << encrypted_pass << endl;
}

string get_user_ID()
{
    string name;
    cout << "Please enter your first and last name, separated by a space." << endl;

    cin.ignore();
    getline(cin, name);

    // Finds where the first and last name are separated.
    int space = name.find_first_of(' ');

    string first_name;
    string sur_name;
    // Loop iterates up until the first space, adds each char to first name.
    for (int letter = 0; letter<space; letter++) {
        first_name.push_back(name[letter]);
    }
    // Index letter starts at the char after the first space. Iterates until the end of string and adds to sur_name.
    for (int letter = space+1; letter<name.size(); letter++) {
        sur_name.push_back(name[letter]);
    }
    return create_user_id(first_name, sur_name);
}

string create_user_id(string first_name, const string& sur_name)
{
    string userID;
    // Adds first letter of first_name to user_id
    userID.push_back(static_cast<const char>(tolower(first_name[0])));
    // iterates through sur_name and converts each character to lower before adding to user_id.
    for (char letter: sur_name) {
        userID.push_back(static_cast<const char>(tolower(letter)));
    }

    return userID;
}

string get_encrypt_pass()
{
    string password;
    cout << "Please enter a password with at least 1 digit, 1 uppercase and 1 lowercase character. " <<
         "spaces and symbols are not allowed.";
    do {

        getline(cin, password);

    }
    while (!check_password(password));

    cout << "Your password is: " << password << endl;
    return encrypt_pass(password);
    //return password;
}

bool check_password(const string& password)
{
    // Checks to see if the find method returns null. Thus no match was found.
    if (password.find(' ')!=-1 || password.find_first_of("!@#$%^&*()-_=+*[{]};:\'\"|/.,><`~")!=-1 ||
            password.find_first_of("qwertyuiopasdfghjklzxcvbnm")==-1
            || password.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM")==-1 ||
            password.find_first_of("1234567890")==-1) {
        cout << "Invalid password." << endl;
        return false;
    }
    else {
        return true;
    }

}

string encrypt_pass(string password)
{
    string ascii;
    int ascii_val;
    int i = 0;
    for (char letter:password) {
        ascii_val = (int) letter+3;
        password[i] = (char) ascii_val;
        i++;
    }
    return password;

}

void login_menu()
{
    bool bad_choice;
    char user_choice;
    do {
        bad_choice = false;
        output_login_str();

        cin >> user_choice;

        switch (user_choice) {
        case '1':
            user_login();
            break;
        case '2':
            add_emp();
            break;
        case '3':
            cout << "Goodbye!";
            exit(0);
        default:
            bad_choice = true;
        }
    }
    while (bad_choice);
}

void output_login_str()
{
    cout << "Welcome, please sign in or create an account." << endl;
    cout << "1. Login" << endl << "2. Create an account." << endl;
    cout << "3. Exit" << endl;
}

string user_login()
{
    vector<string> list_of_users = get_users();
    vector<string> list_of_passwords = get_passwords();

    // Make sure there are users in the employee listing.
    if (list_of_users.empty()) {
        cout << "No employees at this time." << endl;
        login_menu();
    }
    string user_id;
    string password;
    bool found_user;

    do {
        cout << "Enter your user_id:" << endl;
        cin >> user_id;
        found_user = find_user_id(user_id, list_of_users);
    }
    while (!found_user);

    // Finding index where user_id is to check the corresponding password.
    int i;
    for (i = 0; i<list_of_users.size(); i++) {
        if (user_id==list_of_users[i]) {
            break;
        }
    }
    bool match_pass;
    cout << "Enter your password: " << endl;
    do {
        cin >> password;
        // Changed to encrypted version for comparison.
        password = encrypt_pass(password);
        if (password==list_of_passwords[i]) {
            cout << "Success!" << endl;
            match_pass = true;
        }
        else {
            cout << "Wrong password." << endl;
            match_pass = false;
        }
    }
    while (!match_pass);

    return user_id;
}

vector<string> get_users()
{
    vector<string> userIDs;
    string userID;
    ifstream empFile;
    empFile.open("Employees.txt");
    if (empFile.is_open()) {
        while (getline(empFile, userID, ' ')) {
            userIDs.push_back(userID);
            getline(empFile, userID);
        }
    }
    else {
        cout << "Could not open file." << endl;
    }
    return userIDs;
}

vector<string> get_passwords()
{
    vector<string> passwords;
    string password;
    ifstream empFile;
    empFile.open("Employees.txt");
    if (empFile.is_open()) {
        while (getline(empFile, password, ' ')) {
            getline(empFile, password);
            passwords.push_back(password);
        }
    }
    else {
        cout << "Could not open file." << endl;
    }
    return passwords;
}

bool find_user_id(const string& user_id, const vector<string>& user_IDs)
{
    for (const string& id: user_IDs) {
        if (user_id==id || (" "+user_id)==id) {
            return true;
        }
    }
    cout << "No user found with that ID. Try again." << endl;
    return false;
}