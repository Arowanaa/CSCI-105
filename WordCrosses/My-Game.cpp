#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono> 
#include <thread>
#include <stdlib.h>
#include <cstring>

// ANSI color codes for text
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_TEXT "\033[0m"

// function prototypes
void welcomeScreen();
std::string readWordList(const std::string&, int);
std::string letterChecker(std::string, char);

bool compareWords(const std::string&, const std::string&);

int main()
{
// set all variables 

  // booleans 
    // used for welcome screen 
    bool start = false;
    

    // used for when game is playing 
    bool guessed = false;
    bool playing = true;
    bool countCheck = false;
    bool guessing = true;

    // used for end screen 
    bool gameCont = false;

    
    


 //integers 
    int length = 3;

 // characters
    char input;

    // used for letterChecker function
    char letterGuess = '0';

 // strings 
    static std::string guessingWord = "null";
    std::string guessedLetters = "-";
    std::string correctLetters = "+";
    std::string totalLetters = "=";



    while (!gameCont) {



    // display a y/n with the welcome screen
        while (!start) {
            // displaying welcome screen 
            welcomeScreen();

        // y/n text prompt 
            std::cout << "Would you like to play? (y/n)" << std::endl;
            std::cin >> input;
            std::cout << std::endl;

        // case statement for y or n (adjusted for caps) 

            if (tolower(input) == 'y') {      
                std::this_thread::sleep_for(std::chrono::milliseconds(240)); // clear screen after y is pressed
                system("CLS");
                start = true;
                break; // Exit the loop after 'y' is entered
            }
            else if (tolower(input) == 'n') { 
                return 0;
            }
            else { // invalid input statement
                std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
                return 0;
            }
        }

    // code for game 
        while (playing) 
        {
        // asking and checking validity of word length 
            while (!countCheck) {
                std::cout << "Please enter an integer for a word length between 3-6 inclusively:" << std::endl;
                std::cin >> length;
                std::cout << std::endl;
                if (length <= 8 && length >= 3) {
                    guessingWord = readWordList("wordlist.txt", length); 
                    std::this_thread::sleep_for(std::chrono::milliseconds(240)); // ensure a smoother transition
                    system("CLS");
                    break;
                }
                else {
                    length = 0;
                    std::cout << "Please enter a valid word length" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    system("CLS");
                    std::cout << std::endl;
                }
            }

        // code for guessing 
            
            // reset variables before each guessing session
            guessed = false;
            guessing = true;
            
            // guess checking code
            while (guessing) {

                for (int attempts = 0; attempts <= 6; attempts++) {
                    if (!guessed) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(300));
                        std::cout << std::endl;
                        std::cout << "Enter a singular letter to guess" /* << guessingWord*/ << std::endl;
                        std::cout << std::endl;
                        std::cin >> letterGuess;
                        std::cout << std::endl;
                        std::cout << letterChecker(guessingWord, letterGuess);
                        std::cout << std::endl;
                        
                        totalLetters += letterGuess;
                        if (compareWords(totalLetters, guessingWord)) {
                            guessed = true;
                            guessing = false;
                            break;
                        }
                    }
                    else {
                        guessing = false;
                        break;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(600));

                }
                if (guessed){
                // Ending screen
                    system("CLS");
                    std::cout << BLUE_TEXT;
                    std::cout << "Great Job!" << std::endl;
                    std::cout << RESET_TEXT;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    std::cout << std::endl;
                    system("CLS");
                    std::cout << "Play again?\n\nY/N" << std::endl;
                    std::cin >> input;

                    // Y/N case statement
                    if (tolower(input) == 'y') {
                        std::this_thread::sleep_for(std::chrono::milliseconds(240)); // clear screen after y is pressed

                        system("CLS");


// reset all variables 
                        // booleans 
                        // used for welcome screen 
                        start = false;


                        // used for when game is playing 
                        guessed = false;
                        playing = true;
                        countCheck = false;
                        guessing = true;

                        // used for end screen 
                        gameCont = false;

                        //integers 
                        length = 3;

                        // characters
                        input = '!';

                        // used for letterChecker function
                        letterGuess = '0';

                        // strings 
                        guessingWord = "null";
                        guessedLetters = "-";
                        correctLetters = "+";
                        totalLetters = "=";
                        std::cout << totalLetters;
                        std::cout << RESET_TEXT;

                        break; // Exit the loop after 'y' is entered
                    }
                    else if (tolower(input) == 'n') {
                        return 0;
                    }
                    else { // invalid input 
                        return 0;
                    }
                    

                }
                else
                {
                // Ending screen
                    system("CLS");
                    std::cout << BLUE_TEXT;
                    std::cout << "Good Effort!" << std::endl;
                    std::cout << RESET_TEXT;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    std::cout << std::endl;

                    system("CLS");
                    std::cout << "Play again?\n\nY/N" << std::endl;
                    std::cin >> input;
                    
                // Y/N case statement
                    if (tolower(input) == 'y') {
                        std::this_thread::sleep_for(std::chrono::milliseconds(240)); // clear screen after y is pressed
                        system("CLS");


// reset all variables 
                        // booleans 
                        // used for welcome screen 
                        start = false;


                        // used for when game is playing 
                        guessed = false;
                        playing = true;
                        countCheck = false;
                        guessing = true;

                        // used for end screen 
                        gameCont = false;

                        //integers 
                        length = 3;

                        // characters
                        input = '!';

                        // used for letterChecker function
                        letterGuess = '0';

                        // strings 
                        guessingWord = "null";
                        guessedLetters = "-";
                        correctLetters = "+";
                        totalLetters = "=";
                        std::cout << totalLetters;
                        std::cout << RESET_TEXT;

                        break; // Exit the loop after 'y' is entered
                    }
                    else if (tolower(input) == 'n') {
                        return 0;
                    }
                    else { // invalid input 
                        return 0;
                    }
                    
                    
                }
            }
           
        }
       
        
    }

    return 0;
}



// function definitions 

void welcomeScreen() {
    std::cout << YELLOW_TEXT;
    std::cout << " __     __  ______  ______  _____         " << std::endl;
    std::cout << "/\\ \\  _ \\ \\/\\  __ \\/\\  == \\/\\  __-.       " << std::endl;
    std::cout << "\\ \\ \\/ \".\\ \\ \\ \\/\\ \\ \\  __<\\ \\ \\/\\ \\      " << std::endl;
    std::cout << " \\ \\__//\".~\\_\\ \\_____\\ \\_\\ \\_\\ \\____-      " << std::endl;
    std::cout << " ______  _______________/______________   " << std::endl;
    std::cout << "/\\  ___\\/\\  == \\/\\  __ \\/\\  ___\\/\\  ___\\  " << std::endl;
    std::cout << "\\ \\ \\___\\ \\  __<\\ \\ \\/\\ \\ \\___  \\ \\___  \\ " << std::endl;
    std::cout << " \\ \\_____\\ \\_\\ \\_\\ \\_____\\/\\_____\\/\\_____\\ " << std::endl;
    std::cout << "  \\/_____/\\/_/ /_/\\/_____/\\/_____/\\/_____/ \n" << std::endl;

    std::cout << BLUE_TEXT;
    std::cout << "By: Matthew Chang   " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << RESET_TEXT; // Reset color to default

}


std::string readWordList(const std::string& filename, int len) {
    std::random_device myEngine;
    std::mt19937 eng(myEngine());
    std::uniform_int_distribution<int> randomInt(1, 40);

    std::string word = "";
    std::string out = "";
    std::ifstream file(filename);

    int rand = randomInt(eng);
    int count = 0;

    if (!file.is_open()) {
        return "File not open";
    }
    else {
        while (file >> word) {
            if (word.length() == len) {
                count++;
                if (count == rand) {
                    out = word; // Assign the found word to 'out'
                    break;
                }
            }
        }
        file.close();
    }
    return out;
}


std::string letterChecker(std::string guessingWord, char guess) {
    std::string result;

    for (char c : guessingWord) {
        if (c == guess) {
            result += ' ';
            result += guess; // If letter found, add it to the result string
            result += ' ';
        }
        else if (c != ' ') {
            result += '_'; // Replace non-space characters with underscore
            result += ' ';
        }
        else {
            result += ' ';
            result += ' '; // Keep spaces as they are
            result += ' ';
        }
    }
    return result;
}


bool compareWords(const std::string& shortWord, const std::string& longWord) {
    // Check if either word is empty
    if (shortWord.empty() || longWord.empty()) {
        return false;
    }

    // Get the lengths of the words
    size_t shortLength = shortWord.length();
    size_t longLength = longWord.length();

    // Check if the lengths are within the specified range
    if (shortLength < 1 || shortLength > 6 || longLength < 3) { // Min word len = 3
        return false;
    }

    // Iterate through each character in the long word
    for (size_t i = 0; i < longLength; ++i) {
        // Check if the current character is present in the short word
        if (shortWord.find(longWord[i]) == std::string::npos) {
            // If not, return false
            return false;
        }
    }

    // If all characters are present, return true
    return true;
}




