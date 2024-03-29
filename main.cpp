// using iostream header to make use of cin and cout
#include <iostream>
// using fstream to read file stream objects
#include <fstream>
// using string header allows me to manipulate strings & arrays easier
#include <string>

/*
 * Searches each line for patterns
 * searchPattern: what the user is searching for
 * patternLen: the length of the search pattern
 * userFileString: the users file they are searching
 * psearchResult: the resulting data string we want to print
 */
void linear_search(std::string searchPattern, int patternLen, std::string userFileString, std::string psearchResult) {
    // read from users file
    std::ifstream userFile(userFileString);
    // Implementing a simple linear search for now.
    char patternFirstChar = searchPattern[0];
    int lineCtr = 0;
    while (getline (userFile, psearchResult)) {
        lineCtr++;
        //cycle through current line looking for the first character of the pattern
        for (int i = 0; i < psearchResult.length(); i++) {
            if (psearchResult[i] == patternFirstChar) {
                //check substring of pattern len
                if (psearchResult.substr(i, patternLen) == searchPattern) {
                    std::cout << "result found on line: " << lineCtr << " line contents: " << psearchResult << "\n";
                }
            }
        }
    }
    // closing the file to be memory safe
    userFile.close();
}

/*
 * Searches each line for patterns twice as fast
 * searchPattern: what the user is searching for
 * patternLen: the length of the search pattern
 * userFileString: the users file they are searching
 * psearchResult: the resulting data string we want to print
 */
void two_pointer_search(std::string searchPattern, int patternLen, std::string userFileString, std::string psearchResult) {
    // read from users file
    std::ifstream userFile(userFileString);
    // Implementing a simple linear search for now.
    char patternFirstChar = searchPattern[0];
    char patternLastChar = searchPattern.back();
    int lineCtr = 0;

    while (getline (userFile, psearchResult)) {
        lineCtr++;
        //place pointers at both ends of each line and iterate and compare inward
        int left = 0;
        int right = psearchResult.length();
        while (left < right && left + patternLen < right - patternLen) {
            //checks left side
            if (psearchResult[left] == patternFirstChar) {
                //check substring of pattern len
                if (psearchResult.substr(left, patternLen) == searchPattern) {
                    std::cout << "result found on line: " << lineCtr << " line contents: " << psearchResult << "\n";
                }
            }
            //checks ride side
            if (psearchResult[right] == patternLastChar) {
                //check substring of pattern len
                int right_word_pos = right - patternLen;
                if (psearchResult.substr(right_word_pos, patternLen) == searchPattern) {
                    std::cout << "result found on line: " << lineCtr << " line contents: " << psearchResult << "\n";
                }
            }
            left++;
            right--;
        }
    }
    // closing the file to be memory safe
    userFile.close();
}

// argc gets the count of arguments passed in from user
// argv is the arguments themselves
int main (int argc, char* argv[]) {
    // I just want the first argument for the path
    if (argc != 3) {
        std::cout << "This command only accepts a pattern & a file path as arguments \n";
        return -1;
    }

    std::string searchPattern = argv[1];
    int patternLen = searchPattern.length();
    std::string userFileString = argv[2];
    // where we will store results of our search with line numbers
    std::string psearchResult;

    //linear_search(searchPattern, patternLen, userFileString, psearchResult);
    two_pointer_search(searchPattern, patternLen, userFileString, psearchResult);
}