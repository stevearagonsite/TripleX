#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " you need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    // Generate Code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The codes add-up to: " << CodeSum << std::endl;
    std::cout << "The codes multiply to give " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA + GuessB + GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeSum){
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }else{
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main(){
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    // Loop game until all levels completed
    while (LevelDifficulty <= MaxDifficulty){ 
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discard the buffer

        if (bLevelComplete){
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}
