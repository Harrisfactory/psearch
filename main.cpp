// using iostream header to make use of cin and cout
#include <iostream>
// using fstream to read file stream objects
#include <fstream>
// using string header allows me to manipulate strings & arrays easier
#include <string>

// argc gets the count of arguments passed in from user
// argv is the arguments themselves
int main (int argc, char* argv[]) {
    // I just want the first argument for the path
    if (argc != 2) {
        std::cout << "This command only accepts a file path \n";
        return -1;
    }

    // where we will store results of our search with line numbers
    std::string psearchResult;

    // read from users file
    std::ifstream userFile(argv[1]);

    // currently outputting every line for debug purposes
    while (getline (userFile, psearchResult)) {
        // Output the text from the file
        std::cout << psearchResult;
    }

    // closing the file to be memory safe
    userFile.close();
}