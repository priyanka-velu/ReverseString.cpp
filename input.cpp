#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// append user input to the correct file
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error opening file for appending." << endl;
        return;
    }

    string userInput;
    cout << "Enter text to append to the file (press Enter to finish):\n";
    getline(cin, userInput);

    file << userInput << endl;
    file.close();
}

// reverse the string
string reverseString(const string& str) {
    string reversedStr = str;
    int length = str.length();
    for (int i = 0; i < length / 2; ++i) {
        swap(reversedStr[i], reversedStr[length - i - 1]);
    }
    return reversedStr;
}

// reverse the content of a file
void reverseFileContent(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << reverseString(line) << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "File content reversed and stored in " << outputFilename << endl;
}

int main() {
    const string inputFilename = "CSC450_CT5_mod5.txt";
    const string outputFilename = "CSC450-mod5-reverse.txt";

    appendToFile(inputFilename);
    reverseFileContent(inputFilename, outputFilename);

    return 0;
}
