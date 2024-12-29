/**
 * Driver file for an implementation of a linked list.
 * 
 * @author Troy Butler
 * @date 12/29/2024
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "list.h"
using namespace std;

int main() {
    // Create seed for adding random values
    srand(time(0));

    // Create a new list
    List myList;

    // Declare variables for list operations
    char menuChoice = ' ';
    int userInput = -1;
    int index = -1;

    // Main program loop
    do {
        // Display menu
        cout << "\nPlease choose one of the following menu options." << endl << endl;
        cout << "A.\tAdd a value at end" << endl;
        cout << "B.\tAdd N random values" << endl;
        cout << "C.\tInsert a value at start" << endl;
        cout << "D.\tInsert a value at a certain position" << endl;
        cout << "E.\tRemove the first value" << endl;
        cout << "F.\tRemove the last value" << endl;
        cout << "G.\tRemove a value from a certain position" << endl;
        cout << "H.\tRemove a value if it exists" << endl;
        cout << "I.\tRemove all values" << endl;
        cout << "J.\tSort the list" << endl;
        cout << "K.\tReverse the list" << endl;
        cout << "L.\tFind a value in the list" << endl;
        cout << "M.\tDisplay the size of the list" << endl;
        cout << "N.\tQuit" << endl << endl;
        cout << myList.toString() << endl << endl;
        cout << ">> ";

        // Fetch and validate menu choice
        cin >> menuChoice;
        while (tolower(menuChoice) < 'a' || tolower(menuChoice) > 'n') {
            cout << "That is not a valid option, please try again." << endl;
            cout << ">> ";
            cin >> menuChoice;
        }
        // Convert user's choice to lowercase
        menuChoice = tolower(menuChoice);

        // Switch statement to handle menu selection
        switch (menuChoice) {
            case 'a': // Add a new node
                cout << "Please enter a value to add." << endl;
                cout << ">> ";
                cin >> userInput;
                myList.addNode(userInput);
                break;
            case 'b': // Add n nodes with random values
                cout << "How many random values would you like to add?" << endl;
                cout << ">> ";
                cin >> userInput;
                myList.addRandom(userInput);
                break;
            case 'c': // Insert a new node at the start of the list
                cout << "Please enter a value to insert at the start." << endl;
                cout << ">> ";
                cin >> userInput;
                myList.insertStart(userInput);
                break;
            case 'd': // Insert a new node at a specified index
                cout << "Please enter a value to insert." << endl;
                cout << ">> ";
                cin >> userInput;
                // Case 1: list is not empty
                if (!myList.empty()) {
                    cout << "Please enter the index to insert at (0 ~ " << myList.size() << ")." << endl;
                    cout << ">> ";
                    cin >> index;
                    // Validate specified index exists
                    while (index < 0 || index > myList.size()) {
                        cout << "That index does not exist, please try again." << endl;
                        cin >> index;
                    }
                }
                // Case 2: list is empty, so new node will automatically place at start
                else {
                    index = 0;
                }                
                myList.insertAt(index, userInput);
                break;
            case 'e': // Remove node from start of list
                if (myList.empty())
                    cout << "The list is empty!" << endl; // Display error if list is empty
                else
                    myList.removeFirst();
                break;
            case 'f': // Remove node from end of list
                if (myList.empty())
                    cout << "The list is empty!" << endl; // Display error if list is empty
                else
                    myList.removeLast();
                break;
            case 'g': // Remove node from specified index
                if (myList.empty())
                    cout << "The list is empty!" << endl; // Display error if list is empty
                else {
                    cout << "Please enter the index to remove (0 ~ " << myList.size() - 1 << ")." << endl;
                    cout << ">> ";
                    cin >> index;
                    // Validate specified index exists in list
                    while (index < 0 || index > myList.size() - 1) {
                        cout << "That index does not exist, please try again." << endl;
                        cout << ">> ";
                        cin >> index;
                    }
                    myList.removeAt(index);
                }
                break;
            case 'h': // Remove first instance of a value from the list
                cout << "Please enter a value to remove (if it exists in the list)." << endl;
                cout << "Note: only the first instance will be removed." << endl;
                cout << ">> ";
                cin >> userInput;
                myList.removeValue(userInput);
                break;
            case 'i': // Remove all nodes
                myList.clear();
                break;
            case 'j': // Sort nodes into ascending order of value
                myList.sort();
                break;
            case 'k': // Reverse current order of nodes
                myList.reverse();
                break;
            case 'l': // Search the list for a specified value
                cout << "Please enter a value to find." << endl;
                cout << ">> ";
                cin >> userInput;
                index = myList.find(userInput);
                // Display message if value not found
                if (index < 0)
                    cout << userInput << " was not found in the list." << endl;
                else {
                    // Display index if value was found
                    cout << userInput << " was found at index " << index << "." << endl;
                }
                break;
            case 'm': // Display the current size of the list
                cout << "The list contains " << myList.size() << " items." << endl;
                break;
            default: // Display goodbye message
                cout << "Have a nice day!" << endl;
                break;
        }
    } while (menuChoice != 'n');

    return 0;
}