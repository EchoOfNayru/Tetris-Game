#pragma once

struct piece 
{
	char pieceChar;
	int rotation;
	int x;
	int y;
};

char getBlockType(piece piece);

int getInitialX(piece piece);

int getInititalY(piece piece);