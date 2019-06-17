//
// Created by amdressel8336 on 6/17/2019.
//

#ifndef HELLOWORLD_PROTOTYPES_H
#define HELLOWORLD_PROTOTYPES_H
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
void dispStat(vector<Product> &catalog, vector<ProdRecord> &prodLog, prodRecStats &prodLineStats);

void countTypes(prodRecStats &prodLineStats, vector<ProdRecord> &);

void printTypeStats(prodRecStats &prodLineStat);

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
vector<string> getPasswords();

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
 *  @param Takes a product vector, manufacturer, name and item type are all added to the struct vector via reference.
 *  @return Returns the modified Product vector.
 */
vector<Product> createCatalog(vector<Product> &);

/** @brief Produces items and adds them to the production file.
 *
 *  The add items function writes products to the production file by taking
 *  using the catalog via vectors. Each category for a product is chosen in a menu,
 *  one by one via three different functions. User chooses amount and products
 *  are added to text file with a for loop.
 *
 *  @param A Product vector used to read from the catalog. ProdRecord is passed to get the current production number.
 */
void addItems(vector<Product> &catalog, vector<ProdRecord> &prodLog);

/** @brief User is prompted to choose a manufacturer from the catalog.
 *
 *  A list of the product names is given for the user to decide between. This choice is compared to the catalog with
 *  a for loop, the index of the product in the Product vector is returned to get the corresponding manufacturer and
 *  item type.
 *  @param Takes a Product vector, used to compare the user's decision to the products in the catalog.
 *  @return An int is returned related to the index at which the match is found.
 */
int chooseProduct(vector<Product> &catalog);

/** @brief Sorts the names of products in the catalog A-Z.
 *
 *  A string vector is created to hold the names of the products in the catalog.
 *  The names are read from the catalog file and added to the vector.
 *  The sort function is used to sort the names.
 */
void sortProdLine(vector<ProdRecord> &itemsLog);

/** @brief Prints the production text file to std out.
 *
 *  Creates an ifstream object and pushes the serial and production number to the prodLog vector.
 *
 *  @param Production record vector for holding serial and product numbers.
 */
void readProducedItems(vector<ProdRecord> &prodLog);

/** @brief Finds the production number given a serial number.
 *
 * Production file is siffed through and the production and serial numbers
 * are extracted and added to vectors. User is prompted to type a serial number.
 * If a match is found in the vector, that same index will be used to output the
 * production number. If not output will say no matching serial number was found.
 */
void serialToProd(vector<ProdRecord> &itemsLog);
#endif //HELLOWORLD_PROTOTYPES_H
