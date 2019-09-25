#include <iostream>

void PrintIntroduction(){
    std::cout << "\n\nYou are a secret agent breaking into a secure server room\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(){
    PrintIntroduction();

    // Declare 3 number code
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

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
        std::cout << "You win!";
        return true;
    }else{
        std::cout << "You lose!!" ;
        return false;
    }
}

int main(){

    while (true){
        bool bLevelComplete = PlayGame();
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discard the buffer
    }
    
    return 0;
}
