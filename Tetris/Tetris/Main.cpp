#include <iostream>
#include <math.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "Pieces.h"
#include "pieceArray.h"

using namespace std;

bool gameOver = false;
const int width = 12;
const int height = 22;
int score = 0;
piece current;
int a = 0;
int b = 0;
int flagx = 0;
int flagy = 0;

int previousBoard[22][12];

int boardArray[22 /*y*/ ][12 /*x*/ ]
{
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
};

void Setup() 
{
	srand(time(NULL));
	current.shape = rand() % 7;
	current.rotation = rand() % 4;
	current.x = 0;
	current.y = 0;
	current.currentX = 3;
	current.currentY = -1;

	for (int i = 0; i < 5; i++)
	{
		b = current.currentY + i;
		for (int j = 0; j < 5; j++)
		{
			a = current.currentX + j;
			if (pieces[current.shape][current.rotation][i][j] == 1 || pieces[current.shape][current.rotation][i][j] == 2)
			{
				boardArray[b][a] = pieces[current.shape][current.rotation][i][j];
			}
			if (boardArray[b][a] == 1)
			{
				flagx = a;
				flagy = b;
			}
		}
	}
}

void Draw() 
{	
	system("cls");
	
	/*for (int i = 0; i < width; i++)
	{
		boardArray[0][i] = 1;
	}
	for (int i = 0; i < width; i++)
	{
		boardArray[21][i] = 1;
	}*/
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (boardArray[i][j] == 3) 
			{
				cout << "#";
			}
			else if (boardArray[i][j] == 2 || boardArray[i][j] == 1)
			{
				cout << "1";
			}
			else 
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}

void Input() 
{
	
}

void Logic() 
{
	for (int i = 0; i < 5; i++)
	{
		b = current.currentY + i;
		for (int j = 0; j < 5; j++)
		{
			a = current.currentX + j;
			if (boardArray[a][b] == 3) 
			{
				
			}
			else 
			{
				boardArray[b][a] = pieces[current.shape][current.rotation][i][j];
			}
			if (boardArray[b][a] == 1) 
			{
				flagx = a;
				flagy = b;
			}
		}
	}
	for (int i = 0; i < width; i++)
	{
		boardArray[0][i] = 3;
	}
	for (int i = 0; i < width; i++)
	{
		boardArray[21][i] = 3;
	}
	if (boardArray[flagy + 1][flagx] == 0)
	{
		current.currentY++;
	}
	else 
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (boardArray[i][j] == 1 || boardArray[i][j] == 2)
				{
					boardArray[i][j] = 3;
				}
				previousBoard[i][j] = boardArray[i][j];
			}
		}
		current.shape = rand() % 7;
		current.rotation = rand() % 4;
		current.x = 0;
		current.y = 0;
		current.currentX = 3;
		current.currentY = -1;
	}
}

int main() 
{
	Setup();
	while (!gameOver) 
	{
		this_thread::sleep_for(chrono::milliseconds(600));
		Draw();
		Input();
		Logic();
	}
}