// Library of code call a preprocessor Directive
// #include to include directives
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << std::endl;
    // cout = Character Output
    std::cout << "\nYou're an electricion hired to shut off the power to the nuclear reactor... \n";
    // \n is one way start a new line
    std::cout << "To enter the back entrance you need each code level \n";
    // This is another way. \n does not work at the end of a variable
    std::cout << "Currently you are on the " << Difficulty << " level \n";
}

bool PlayGame(int Difficulty)
{

    // Calling function
    PrintIntroduction(Difficulty);
    int LevelDifficulty = Difficulty + 3;
    // Assigning variables
    int CodeA = rand() % LevelDifficulty + 1;
    int CodeB = rand() % LevelDifficulty + 1;
    int CodeC = rand() % LevelDifficulty + 1;
    bool bLevelComplete;

    // Unreal Engine 4 uses UpperCamelCase variable names
    const int CodeD = 150;

    // Math
    int CodeProduct = CodeA * CodeB * CodeC;
    int CodeSum = CodeA + CodeB + CodeC;

    std::cout << std::endl;
    std::cout << "there are 3 numbers in the code" << std::endl;
    std::cout << "the codes multiplied are: " << CodeProduct << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "there are 3 numbers in the code" << std::endl;
    std::cout << "the codes add-up to: " << CodeSum << std::endl;

    int GuessA, GuessB, GuessC;

    // cin = Character Input
    // >> = Extraction Operator
    // When this is executed the program will pause and wait for the user to input some data
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // if Statement syntax
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "CORRECT \n";
        bLevelComplete = true;
    }
    else
    {
        std::cout << "INCORRECT THE NUMBERS WERE" << CodeA << CodeB << CodeC << std::endl;
        bLevelComplete = false;
    }

    // Escape Sequences
    // Used to represent different characters within a string
    // Escape sequences modify the format of a string --  EX:  std::cout << "He said: \"Hello, World!\"\n";

    std::cout << "Your guess Sum was: " << GuessSum << "\n";
    std::cout << "Your guess Product was: " << GuessProduct << std::endl;
    return bLevelComplete;
}

int main()
{
    srand(time(NULL)); // This will create a new random sequence based on time of day

    int LevelDifficulty = 1;
    int CodeCrackAttempts = 0;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel && CodeCrackAttempts <= 3)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer
        if (bLevelComplete && CodeCrackAttempts <= 3)
        {
            std::cout << "LEVEL INCREASED";
            // increase level difficulty
            ++LevelDifficulty;
        }
        else if (!bLevelComplete && CodeCrackAttempts <= 3)
        {
            ++CodeCrackAttempts;
            std::cout << "FAILED ATTEMPT " << CodeCrackAttempts << "/3 \n";
        }
    }
    if (LevelDifficulty >= MaxLevel)
    {
        std::cout << "\n -----YOU WIN!----- \n";
    }
    else if (CodeCrackAttempts > 3)
    {
        std::cout << "\n ***BOMB EXPLODES** \n";
    }

    return 0;
}