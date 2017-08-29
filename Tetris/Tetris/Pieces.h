#pragma once

struct piece 
{
	char pieceChar;
	int shape;
	int rotation;
	int x;
	int y;
	int currentX;
	int currentY;
};

int getBlockType(piece piece);

int getInitialX(piece piece);

int getInitialY(piece piece);

int movePiece(piece piece);