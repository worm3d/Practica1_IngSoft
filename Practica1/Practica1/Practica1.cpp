#include "stdafx.h"
#define WORLDSIZE 80
#define GAMEWAIT 39.998

int main()
{
	int characterPos = 40;
	int bulletPos = 40;
	bool bullet = false; //Indicates if the bullet is moving
	bool bulletDir = false; //Indicates the direction of the bullet, false is left, and true is right

	printf("\n\n\n\n\n\n\n"); //Move the cursor a bit down from initial position

	while (true)
	{
		if (!bullet) bulletPos = characterPos; //If a bullet is not moving, its position must be equal to the character position
		else if (bullet) {
			if (!bulletDir)	bulletPos--;
			else bulletPos++;
		}

		if (bulletPos <= 0 || bulletPos >= WORLDSIZE) {
			bullet = false;
			bulletPos = characterPos;
		}

		for (int i = 0; i < WORLDSIZE; i++)
		{
			if (i == characterPos)				printf("^.^");	//Prints the character
			else if (i == bulletPos && bullet)	printf("-");	//Prints the bullet
			else								printf("_");	//Prints the world's floor
		}

		printf("\r"); //Returns the cursor to the beginning of the line

		if (_kbhit()) {
			char c = _getch();

			if (c == 'a' && characterPos > 0)				characterPos--;
			else if (c == 'd' && characterPos < WORLDSIZE)	characterPos++;
			else if (c == 'q' && !bullet) {
				bulletPos--;
				bulletDir = false;
				bullet = true;
			}
			else if (c == 'e' && !bullet) {
				bulletPos++;
				bulletDir = true;
				bullet = true;
			}
		}

		Sleep(GAMEWAIT);
	}

	return 0;
}