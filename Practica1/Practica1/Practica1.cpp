#include "stdafx.h"
#define WORLDSIZE 80
#define GAMEWAIT 39.998

int characterPos = 40;

int bulletPos = 40;
bool bullet = false;	//Indicates if the bullet is moving
int bulletDir = -1;	//Indicates the direction of the bullet, -1 is left, and 1 is right

void readInput()
{
	if (_kbhit()) {
		char c = _getch();

		if (c == 'a' && characterPos > 0)				characterPos--;
		else if (c == 'd' && characterPos < WORLDSIZE)	characterPos++;
		else if (c == 'q' && !bullet) {
			bulletPos--;
			bulletDir = -1;
			bullet = true;
		}
		else if (c == 'e' && !bullet) {
			bulletPos++;
			bulletDir = 1;
			bullet = true;
		}
	}
}

//This function updates the state of the bullet and its position
void updateBullet()
{
	if (!bullet) bulletPos = characterPos; //If a bullet is not moving, its position must be equal to the character position
	else if (bullet) {
		if (bulletDir == -1)	bulletPos--;
		else bulletPos++;
	}

	if (bulletPos <= 0 || bulletPos >= WORLDSIZE) { //If the bullet is on the limits of the world, it dissapears and the position goes back to the player
		bullet = false;
		bulletPos = characterPos;
	}
}

void printWorld()
{
	for (int i = 0; i < WORLDSIZE; i++)
	{
		if (i == characterPos)				printf("^.^");	//Prints the character
		else if (i == bulletPos && bullet)	printf("-");	//Prints the bullet
		else								printf("_");	//Prints the world's floor
	}
}

int main()
{
	printf("\n\n\n\n\n\n\n"); //Move the cursor a bit down from initial position

	while (true)
	{
		updateBullet();

		printWorld();
		printf("\r"); //Returns the cursor to the beginning of the line

		readInput();

		Sleep(GAMEWAIT);
	}

	return 0;
}