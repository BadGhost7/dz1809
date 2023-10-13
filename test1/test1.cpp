#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std:

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


int rollDice()
{
    return getRandomNumber(1, 6);
}


int sumDiceValues(int dice[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += dice[i];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "");
    srand(static_cast<unsigned int>(time(0)));

    int botDice[5];
    int playerDice[5];

   
    for (int i = 0; i < 5; i++) {
        botDice[i] = rollDice();
        playerDice[i] = rollDice();
    }

    
    bool botAllSame = (botDice[0] == botDice[1] && botDice[1] == botDice[2] &&
        botDice[2] == botDice[3] && botDice[3] == botDice[4]);

    bool playerAllSame = (playerDice[0] == playerDice[1] && playerDice[1] == playerDice[2] &&
        playerDice[2] == playerDice[3] && playerDice[3] == playerDice[4]);

    if (botAllSame && !playerAllSame) {
        cout << "Бот победил, у него все кости одинаковы." << endl;
    }
    else if (!botAllSame && playerAllSame) {
        cout << "Игрок победил, у него все кости одинаковы." << endl;
    }
    else {
       
        int botSum = sumDiceValues(botDice);
        int playerSum = sumDiceValues(playerDice);

        if (botSum > playerSum) {
            cout << "Бот победил, у него больше сумма значений на костях." << botSum << " " << playerSum << endl;
        }
        else if (playerSum > botSum) {
            cout << "Игрок победил, у него больше сумма значений на костях." << botSum << " " << playerSum << endl;
        }
        else {
            cout << "Ничья, у бота и игрока одинаковая сумма значений на костях." << botSum << " " << playerSum << endl;
        }
    }

    return 0;
}