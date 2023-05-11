#include <iostream>
#include <ctime>

char getUserChoice();
char getPCChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer, int &playerWins, int &computerWins, int &ties);

int main()
{
    char player;
    char computer;
    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;

    while (true)
    {
        player = getUserChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        computer = getPCChoice();
        std::cout << "PC's choice: ";
        showChoice(computer);

        chooseWinner(player, computer, playerWins, computerWins, ties);
        std::cout << "\nPlayer wins: " << playerWins << "\n";
        std::cout << "Computer wins: " << computerWins << "\n";
        std::cout << "Ties: " << ties << "\n\n";
    }
    return 0;
}


char getUserChoice()
{
    char player;
    std::cout << "Rock-Paper-Scissors Game!\n";

    do
    {
        std::cout << "Choose one of the following\n";
        std::cout << "*************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cout << "'q' for exit\n";
        std::cin >> player;

        if (player == 'q')
        {
            exit(0);
        }
        
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}


char getPCChoice()
{
    srand(time(NULL));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';

    case 2:
        return 'p';

    case 3:
        return 's';
    }

    return 0;
}


void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;

    case 'p':
        std::cout << "Paper\n";
        break;

    case 's':
        std::cout << "Scissors\n";
        break;
    
    default:
        break;
    }
}


void chooseWinner(char player, char computer, int &playerWins, int &computerWins, int &ties)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            std::cout << "Draw\n";
            ties++;
        }
        else if (computer == 'p')
        {
            std::cout << "You lose\n";
            computerWins++;
        }
        else
        {
            std::cout << "You win\n";
            playerWins++;
        }
        break;

    case 'p':
        if (computer == 'r')
        {
            std::cout << "You win!\n";
            playerWins++;
        }
        else if (computer == 'p')
        {
            std::cout << "Draw\n";
            ties++;
        }
        else
        {
            std::cout << "You lose\n";
            computerWins++;
        }
        break;

    case 's':
        if (computer == 'r')
        {
            std::cout << "You lose\n";
            computerWins++;
        }
        else if (computer == 'p')
        {
            std::cout << "You win!\n";
            playerWins++;
        }
        else
        {
            std::cout << "Draw\n";
            ties++;
        }
        break;
    }
    std::cout << "Score:\nPlayer: " << playerWins << "\nComputer: " << computerWins << std::endl;
}