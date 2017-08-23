#include <iostream>
#include <math.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include "Pieces.h"
#include "pieceArray.h"

using namespace std;

char getBlockType(piece piece)
{
	return pieces [piece.pieceChar][piece.rotation][piece.x][piece.y];
}

int getInitialX(piece piece)
{
	return pieceInitialPosition [piece.pieceChar][piece.rotation][0];
}

int getInititalY(piece piece)
{
	return pieceInitialPosition [piece.pieceChar][piece.rotation][1];
}
