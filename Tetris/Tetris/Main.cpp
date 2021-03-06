#include <iostream>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Pieces.h"
#include "pieceArray.h"
#include <string>
#include <fstream>

using namespace std;

void Highscore(int score) 
{
	std::fstream highscore;
	std::string buffer;
	int num = 0;
	int list[10];
	int placeholder = 0;
	
	highscore.open("highscore.txt", std::ios_base::in | std::ios_base::out);
	
	if (highscore.fail()) 
	{
		cout << "Error: cannot find highscores" << endl;
		system("pause");
	}
	else
	{
		int i = 0;
		while (std::getline(highscore, buffer))
		{
			list[num] = std::stoi(buffer);
			num++;
		}
		for (int i = 0; i < 10; i++) 
		{
			if (score >= list[i]) 
			{
				if (i != 9)
				{
					list[i + 1] = list[i]; 
				}
				list[i] = score;
				score = -1;
				for (int j = i + 1; j < 10; j++) 
				{
					if (j != 9) 
					{
						list[j + 1] = list[j];
					}
				}
			}
		}

		highscore.clear();
		highscore.seekp(0);

		highscore << list[0] << endl;
		highscore << list[1] << endl;
		highscore << list[2] << endl;
		highscore << list[3] << endl;
		highscore << list[4] << endl;
		highscore << list[5] << endl;
		highscore << list[6] << endl;
		highscore << list[7] << endl;
		highscore << list[8] << endl;
		highscore << list[9] << endl;
		cout << list[0] << endl;
		cout << list[1] << endl;
		cout << list[2] << endl;
		cout << list[3] << endl;
		cout << list[4] << endl;
		cout << list[5] << endl;
		cout << list[6] << endl;
		cout << list[7] << endl;
		cout << list[8] << endl;
		cout << list[9] << endl;
		system("pause");
	}
	highscore.close();
}

void TrainingWheels(int KobeyNeedsHelp) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), KobeyNeedsHelp);
}

bool gameOver = false;
const int width = 12;
const int height = 22;
int score = 0;
piece current;
int a = 0;
int b = 0;
int flagx = 0;
int flagy = 0;
int pause = 0;

int previousBoard[22][12];

int boardArray[22 /*y*/ ][12 /*x*/ ]
{
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
	{3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
};

void Setup() 
{
	srand(time(NULL));
	current.shape =  rand() % 7;
	current.rotation = rand() % 4;
	current.x = 0;
	current.y = 0;
	current.currentX = 3;
	current.currentY = -1;
	pause = 0;

	for (int i = 0; i < 5; i++)
	{
		b = current.currentY + i;
		if (b < 0) { b = 0; }
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
	
	int rando = rand() % 70+1;
	TrainingWheels(5);


	system("cls");
	
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


int getKey(char key)
{
	return GetAsyncKeyState(key);
}


void Input(int &Movement, int &rot) 
{	
	bool doTheThing = true;
	bool doTheThing2 = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (boardArray[i][j] == 1 || boardArray[i][j] == 2) 
			{
				if (/*boardArray[i][j - 1] == 3 || */boardArray[i + 1][j - 1] == 3) 
				{
					canMoveLeft = false;
				}
				if (/*boardArray[i][j + 1] == 3 || */boardArray[i + 1][j + 1] == 3)
				{
					canMoveRight = false;
				}
			}
		}
	}
	
	if (getKey('A')) 
		{
			if (canMoveLeft)
			{
				Movement -= 1;
			}
			for (int i = 0; i < 5; i++)
			{

				b = current.currentY + i;
				if (b < 0) { b = 0; }
				for (int j = 0; j < 5; j++)
				{

					a = current.currentX + j;

					if (boardArray[b][a] != 3)
					{
						boardArray[b][a] = 0;
					}
				}
			}
		}
		else if (getKey('D'))
		{
			if (canMoveRight)
			{
				Movement += 1;
			}
			for (int i = 0; i < 5; i++)
			{

				b = current.currentY + i;
				if (b < 0) { b = 0; }
				for (int j = 0; j < 5; j++)
				{

					a = current.currentX + j;

					if (boardArray[b][a] != 3)
					{
						boardArray[b][a] = 0;
					}
				}
			}
		}
		 if (getKey('E'))
		{
			if (current.rotation == 3)
			{
				rot = -3;
				//current.rotation = 0;
			}
			else
			{
				rot = 1;
				//current.rotation++;
			}
		}
		if (getKey('Q'))
		{
			if (current.rotation == 0)
			{
				rot = 3;
				//current.rotation = 3;
			}
			else
			{
				rot = -1;
				//current.rotation--;
			}
		}
}
void SpawnPiece(bool &Ready)
{
	if (Ready == true)
	{
		if (boardArray[1][5] == 3 || boardArray[1][6] == 3) 
		{
			gameOver = true;
		}
		current.shape = rand() % 7;
		current.rotation = rand() % 4;
		current.x = 0;
		current.y = 0;
		current.currentX = 3;
		current.currentY = -4;
		Ready = false;
	}
}
void Logic(bool &Spawn, int Movement, int rot) 
{
	current.currentX += Movement;
	current.rotation += rot;

	//Brick Movement downwards
	bool canMoveDown = true;
	bool hashtag = false;
	for (int i = 0; i < 5; i++)
	{
		b = current.currentY + i;
		if (b < 0) { b = 0; }
		for (int j = 0; j < 5; j++)
		{
			a = current.currentX + j;
			if (boardArray[b][a] != 3)
			{
				boardArray[b][a] = pieces[current.shape][current.rotation][i][j];
			}
			if (boardArray[b][a] == 1 || boardArray[b][a] == 2)
			{
				flagx = a;
				flagy = b;
			}
			if (boardArray[flagy + 1][flagx] == 3)
			{
				hashtag = true;
				for (int k = 0; k < height; k++)
				{
					for (int l = 0; l < width; l++)
					{
						if (boardArray[k][l] == 1 || boardArray[k][l] == 2)
						{
							boardArray[k][l] = 3;
						}
					}
				}
				canMoveDown = false;
			}
		}
		if (hashtag == true)
		{

			for (int k = 0; k < height; k++)
			{
				for (int l = 0; l < width; l++)
				{
					if (boardArray[k][l] == 1 || boardArray[k][l] == 2)
					{
						boardArray[k][l] = 3;

					}
				}
			}
		}
	}
	//Line Clearing and score
	bool isFull = true;
	int placeHolder[height][width];
	for (int i = 0; i < height - 1; i++)
	{
		isFull = true;
		for (int j = 1; j < width - 1; j++)
		{
			if (boardArray[i][j] != 3)
			{
				isFull = false;
			}
		}
		if (isFull)
		{
			for (int j = 0; j < height; j++)
			{
				for (int k = 0; k < width; k++)
				{
					placeHolder[j][k] = boardArray[j][k];
					boardArray[j][k] = 0;
					if (j > i)
					{
						boardArray[j][k] = placeHolder[j][k];
					}
					else if (j <= i)
					{
						boardArray[j][k] = placeHolder[j - 1][k];
					}
				}
			}
			score += 1;
		}
	}

	//border preservation
	for (int i = 0; i < width; i++)
	{
		boardArray[0][i] = 0;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				boardArray[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < width; i++)
	{
		boardArray[21][i] = 3;
	}
	if (canMoveDown)
	{
		current.currentY++;
	}
	else
	{
		Spawn = true;
	}
}

int main() 
{
	Setup();
	bool Spawn = false;
	while (!gameOver) 
	{
		int Movement = 0;
		int rot = 0;
		this_thread::sleep_for(chrono::milliseconds(400));
		SpawnPiece(Spawn);
		Draw();
		Input(Movement, rot);
		Logic(Spawn, Movement, rot);
		Draw();
	}
	cout << "You died!\n";
	system("pause");
	system("cls");
	Highscore(score);
	system("pause");
}