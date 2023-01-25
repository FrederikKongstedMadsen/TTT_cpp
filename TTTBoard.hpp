#include <iostream>
#include <vector>

#define ROWS 3
#define COLS 3
#define UNDEFINED '-'

class TTTBoard
{
private:
    char gamePad[3][3];
    char turn = 'X';
    std::vector<int> usedSpaces;

public:
    TTTBoard();
    ~TTTBoard();
    void printBoard();
    void changeBoardSpace(int spaceNo);
    bool findWinner();
    void playSpace();
};

TTTBoard::TTTBoard(/* args */)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int n = 0; n < COLS; n++)
        {
            gamePad[n][i] = UNDEFINED;
        }
    }



    int tempBoard[3][3];
    int count = 1;
    for(int i = 0; i < ROWS; i++)
    {
        for(int n = 0; n < COLS; n++)
        {
            tempBoard[n][i] = count;
            count++;
        }
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int n = 0; n < COLS; n++)
        {
            std::cout << tempBoard[n][i] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "Player" << turn << " starts. Pick a space according to the numbers (1-9)" << std::endl;


}



TTTBoard::~TTTBoard()
{
}

void TTTBoard::printBoard()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int n = 0; n < COLS; n++)
        {
            std::cout << gamePad[n][i] << "  ";
        }
        std::cout << std::endl;

    }
    std::cout << std::endl;
}

void TTTBoard::changeBoardSpace(int spaceNo)
{
    switch (spaceNo)
    {
    case 1:
        gamePad[0][0] = gamePad[0][0] == '-' ? turn : gamePad[0][0];
        break;

    case 2:
        gamePad[1][0] = gamePad[1][0] == '-' ? turn : gamePad[1][0];
        break;

    case 3:
        gamePad[2][0] = gamePad[2][0] == '-' ? turn : gamePad[2][0];
        break;    
    
    case 4:
        gamePad[0][1] = gamePad[0][1] == '-' ? turn : gamePad[0][1];
        break;

    case 5:
        gamePad[1][1] = gamePad[1][1] == '-' ? turn : gamePad[1][1];
        break;

    case 6:
        gamePad[2][1] = gamePad[2][1] == '-' ? turn : gamePad[2][1];
        break;   

    case 7:
        gamePad[0][2] = gamePad[0][2] == '-' ? turn : gamePad[0][2];
        break;

    case 8:
        gamePad[1][2] = gamePad[1][2] == '-' ? turn : gamePad[1][2];
        break;

    case 9:
        gamePad[2][2] = gamePad[2][2] == '-' ? turn : gamePad[2][2];
        break; 

    default:
        break;
    }


    if(turn == 'X')
    {
        turn = 'O';
    }
    else
    {
        turn = 'X';
    }
}

bool TTTBoard::findWinner()
{
    if(gamePad[0][0] == gamePad[0][1] && gamePad[0][1] == gamePad[0][2] && gamePad[0][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[0][0] << " has won!" << std::endl;
        return true;
    }

    else if(gamePad[1][0] == gamePad[1][1] && gamePad[1][1] == gamePad[1][2] && gamePad[1][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[1][1] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[2][0] == gamePad[2][1] && gamePad[2][1] == gamePad[2][2] && gamePad[2][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[2][0] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[0][0] == gamePad[1][0] && gamePad[1][0] == gamePad[2][0] && gamePad[2][0] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[2][0] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[0][1] == gamePad[1][1] && gamePad[1][1] == gamePad[2][1] && gamePad[2][1] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[0][1] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[0][2] == gamePad[1][2] && gamePad[1][2] == gamePad[2][2] && gamePad[2][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[0][2] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[0][0] == gamePad[1][1] && gamePad[1][1] == gamePad[2][2] && gamePad[2][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[0][0] << " has won!" << std::endl;
        return true;
    }
    
    else if(gamePad[2][0] == gamePad[1][1] && gamePad[1][1] == gamePad[0][2] && gamePad[0][2] != UNDEFINED)
    {
        std::cout << "Player " << gamePad[2][0] << " has won!" << std::endl;
        return true;
    }
    return false;
}

void TTTBoard::playSpace()
{
    if(usedSpaces.size() == 9)
    {
        std::cout << "It's a draw" << std::endl;
        exit(1);
    }
    std::cout << "It is player " << turn << "'s turn. Pick between space 1-9" << std::endl;
    int tempSpace;
    bool isUsed = false;
    do
    {
        isUsed = false;
        std::cin >> tempSpace;
        if(tempSpace < 1 && tempSpace > 9)
        {
            std::cout << "Invalid option, try again" << std::endl;
        }
        else
        {
            std::vector<int>::iterator iter;
            for(iter = usedSpaces.begin(); iter != usedSpaces.end(); iter++)
            {
                if(*iter == tempSpace)
                {
                    std::cout << "This space is already used, choose another" << std::endl;
                    isUsed = true;
                }
            }
        }
    } while((tempSpace < 1 && tempSpace > 9) || isUsed);

    usedSpaces.push_back(tempSpace);

    
    

    changeBoardSpace(tempSpace);
    printBoard();
    if(findWinner())
    {
        exit(1);
    }
}
