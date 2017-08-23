#include <iostream>
#include <math.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "Pieces.h"
//#include "pieceArray.h"

using namespace std;

bool gameOver = false;
const int width = 10;
const int height = 20;
int score = 0;

void Setup() 
{

}

void Draw() 
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}

			if (j == width)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input() 
{
	
}

void Logic() 
{
	
}

int main() 
{
	Setup();
	while (!gameOver) 
	{
		this_thread::sleep_for(chrono::milliseconds(300));
		Draw();
		Input();
		Logic();
	}
}