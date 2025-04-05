#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// Function to check if a string is part of a predefined set of strings
bool isInSet(const string& s) {
    cout << "\n--------------------------------------------------------" << endl;
    cout << "\nChecking String: " << s << endl;

    // Predefined set of strings
    string set[3] = {"aaaba", "xxxxyyx", "0000001110"};
    bool found = false;

    int sLength = s.length();

    // Iterate through the predefined set
    for (const string& j : set) {
        int jLength = j.length();
        int n = 0, m = 0;

        // If lengths do not match, continue to next string in the set
        if (sLength != jLength) {
            cout << s << "'s size does not match " << j << ", so it won't be part of the set." << endl;
            continue;
        }

        // Check if the first character matches
        if (s[0] == j[0]) {
            while (n < sLength && s[n] == j[m]) {
                n++;
                m++;
            }

            // If we successfully matched the entire string
            if (n == sLength) {
                cout << "Found " << s << " in the set corresponding to " << j << endl;
                found = true;
                break;
            }
        } else {
            cout << "Did not find " << s << " in the string " << j << endl;
        }
    }

    cout << "\nIs the string " << s << " in the set? " << (found ? "yes" : "no") << endl;
    return found;
}

int main() {
    cout << "L is a language and S is an array of strings. We're trying to see if S is a subset of L. Enter L's elements or use predefined elements to pose as its elements and debug the appl. " <<endl;
    string input = "";
    vector<string> inputArray;

    // Example string array
    string strArray[9] = {
        "aaaba", "aaabaasdf", "aaaasdfabaadsfasdfa", "xxxxyyx", 
        "xxxxxxxxxxyyx", "xxxxxyx", "0000001110", "10000001110", "0001001110"
    };

    // Ask the user for input
    cout << "Do you want to use a dynamic set of elements for L, or use an example with strings like 'aaaba', 'aaabaasdf', etc.? (yes/no)" << endl;

    unordered_set<string> validAnswers = {"yes", "no", "y", "n"};

    while (true) {
        cout << "Enter your choice (yes/no): ";
        cin >> input;

        // Exit loop if valid input is provided
        if (validAnswers.find(input) != validAnswers.end()) {
            break;
        } else {
            cout << "Please enter 'yes' or 'no'." << endl;
        }
    }

    if (input == "yes" || input == "y") {
        // If user wants to enter their own dynamic set of strings
        cout << "Enter strings to check (enter 'done' to stop): " << endl;
        
        while (true) {
            cout << "Enter string: ";
            cin >> input;
            
            if (input == "done") {
                break;  // Exit loop when 'done' is entered
            }
            inputArray.push_back(input);
        }
        
        // Check if the entered strings are in the set
        for (const string& userStr : inputArray) {
            isInSet(userStr);
        }
    } else {
        // Use the predefined example strings
        cout << "Using example strings for checking." << endl;
        for (const string& exampleStr : strArray) {
            isInSet(exampleStr);
        }
    }

    return 0;
}
