# Project Title
- This project for Programming methodology is an inventory tracking system for a manufacturing company. The intended user is an employee that is able to track the items they produced, as well as add products that the company can produce. Products and items are also added to text files. New Employees can be created and stored in another text file.

- This project was made independently for COP 2001 - Programming Methodology.
- This was made before my junior year, still getting acquainted with basic software development and terminology. This was also my first time programming in C++.
- This was an assignment, but extra features were added to get more familiar with the C++ programming language.
This was made while I was a student at FGCU.

## Demonstration
![](Project_Demo.gif)

## Documentation
https://dresseladam.github.io/Procedural_Project/html/index.html
## Getting Started


## Built With
CLion by JetBrains with Visual Studio Compiler
C++
## Contributing
- Find ways to simplify code and make program more efficient.
- Implement more features for the inventory tracking system.
- Convert from procedural paradigm to an object-oriented version.

## Author
Adam Dressel

## License
![](LICENSE.md)

## Acknowledgments
https://geeksforgeeks.com/
https://cplusplusreference.com/
https://www.screentogif.com/
## History
Sprint 1 Backlog (SBL) - Basic Input and Output

    Output a greeting to the user and the product line from main.
        Store Manufacturer, Name, and ItemType for two products that the production facility produces. There will be four item types initially: AudioMobile, Audio, VideoMobile, and Video. Each type has an associated code, AM, AU, VM, and VI respectively. The product line output should look similar to this:
            Apple iPod AudioMobile
            Sylvania SDVD1187 VideoMobile
        Optional: There will be two types of products initially, audio players and video players. Audio players will also store compatible formats (like mp3 or wav) and video players will also store information about monitor type (like LED or LCD) and refresh rate (like 120Hz).
    Output a message that functionality to log production will be added soon. 

Sprint 2 Backlog (SBL) - Conditions, Loops, Functions, Files intro. 

    Create a working menu. 
        The only menu options necessary for this sprint are Log Production and Exit. 
        Only accept values that are listed in the menu.
        If the user selects a different value, they are asked to choose again.
        Menu is printed from a showMenu function that is called from main. 
        Menu choices result in calls to functions. 
        After output of menu choice, show menu again until user chooses to exit.
    Add functionality to log production for the products from the previous sprint.
        The user should be able to choose which of the products was produced.
        The user should be able to enter how many of the products were produced.
        A record should be output that displays the production number, manufacturer, product name, item type, and serial number. 
            ProductionNumber should be unique, sequential for all products, and automatically assigned.
            The SerialNumber should start with the first three letters of the Manufacturer, then the two letter ItemType code, then five digits (with leading 0s if necessary) that are unique and sequential for the item type. The entire Serial Number should be automatically assigned. 

Sprint 3 - Arrays and Vectors, Searching and Sorting

    Store the product line in a collection (parallel vectors). 
        Use code to populate some products.
        Allow the user to add products.
        Allow user to view the product line. 
    When logging production, the user should be prompted to enter the product produced from the product line.
    Store the production log in a collection (parallel vectors). 
        Allow the user to view the production log. 
    Output the product line sorted by name.
    Given a Serial Number, output the Production Number  

Sprint 4 - Pointers, Characters, Strings, Recursion

    Create an Employee account. 
        Allow user to input full name in format FirstName LastName.  
            Generate user id, which is their first initial and surname in all lowercase.
            Optional: Don't allow duplicate user names. 
        Allow user to input a password for the user
            The password must contain at least one digit, at least one lowercase letter, and at least one uppercase letter. The password cannot contain a space or any other symbols. 
            Use a recursive function to encrypt the password. 
    Optional: Require users to log in. Track which employee recorded production. 

Sprint 5 - Data Structures, Structs, Files

    Store product line, production records, and production statistics in structs.
    Save products that can be produced to a text file named ProductLine.csv 
    Save the production log to a text file name ProductionLog.csv 
    Save the usernames and encrypted passwords to a text file name Users.txt
    Load data from the files into vectors of structs when the program starts.

Sprint 6 - Quality Analysis

    Output production statistics such as total number of items produced and number of items of each type. 
    Clear all warnings from Inspect Code.
    Format code using standard style guidelines.
    Enhance documentation:
        Javadoc style comments for Doxygen
        Comments in code
        README
            Create animated gif of program running
    Deployment

## Key Programming Concepts Utilized
If/else constructs, switch cases.
do/while for loops
C++ Stream objects and operators.
C++ function calls
  -Parameters Return values

