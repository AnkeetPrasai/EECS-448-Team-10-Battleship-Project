/**
*	@author Team 10
*	@date 02/19/21
*	@file Executive.cpp
*	@brief Sets up board with ships for game
*/
#include "Board.h"
#include "Executive.h"
#include "Ships.h"
#include <string>
#include <iostream>


Executive::Executive()
{
	p1Carrier.buildShip(6);
	p2Carrier.buildShip(6);
	p1BattleShip.buildShip(5);
	p2BattleShip.buildShip(5);
	p1Destroyer.buildShip(4);
	p2Destroyer.buildShip(4);
	p1Cruiser.buildShip(3);
	p2Cruiser.buildShip(3);
	p1Patrol.buildShip(2);
	p2Patrol.buildShip(2);
	p1Sub.buildShip(1);
	p2Sub.buildShip(1);
}

void Executive::run()
{
	/// Game runtime function, requries input from both players, Displays prompts from the console and takes input. 
	/// Uses a turn counter to regulate turns for Player 1 and Player 2

	PrintMenu();
	
	Game();

	//SAMPLE PROMPTS: ALL OF THESE NEED TO BE CODED INTO THEIR RESPECITVE SPOTS
	 //ADD code to make actually affect board.
	cout << "Great, both players' boats have now been placed on the board. Now, it is time to attack the enemy!";
	cout << endl;
	cout << endl;
	int turn = 1;

	//Turn Text with turn counter
	cout << "PLAYER 1 TURN [" << turn << "]";
	cout << endl;
	//stuff happens
	cout << "PLAYER 2 TURN [" << turn << "]";
	cout << endl;

	//Player ship sunk
	cout << "YOUR " << "insert ship name" << " SUNK!";
	cout << endl;

	//Player ship hit
	cout << "YOUR " << "insert ship name" << " WAS HIT!";
	cout << endl;

	//Enemy ship hit
	cout << "HIT!";
	cout << endl;

	//Enemy ship miss
	cout << "MISS!";
	cout << endl;


	//Enemy ship sunk
	cout << "YOU SUNK A " << "insert ship name" << "!";
	cout << endl;

	cout << "PLAYER 1 LOST!";
	cout << endl;

	cout << "PLAYER 2 LOST!";
	cout << endl;

	cout << "PLAYER 1 WON!";
	cout << endl;

	cout << "PLAYER 2 WON!";
	cout << endl;

	//CHECK TO SEE IF BOAT IS PLACED ON TOP OF ANOTHER BOAT
}

void Executive::PrintMenu()
{
	bool loop = true;
	int selection = 0;
	cout << "  WELCOME TO" << endl;
	cout << " //BATTLESHIP//" << endl << endl << endl;
	while (loop)
	{
		cout << endl << "Enter in number to navigate menu" << endl;
		cout << "1: Start Game" << endl;
		cout << "2: How to Play" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:
			loop = false;
			break;
		case 2:
			cout << "BASIC RULES" << endl;
			cout << "The goal of the game is to eliminate all of your opponent's ships ";
			cout << "by selecting spots on the game board to see if you hit or miss." << endl;
			cout << "The game is over when one player loses all of their ships." << endl;
			break;
		default:
			cout << selection << " is not a valid choice, try again." << endl;
		}
	}
}

void Executive::Game()
{
	int numberOfShips = 0;
	int row;
	char column;
	int vert;
	cout << "Enter the number of ships you would like to play with, up to a total of 6." << endl;
	cin >> numberOfShips;
	cout << "HIDE THE SCREEN SO ONLY ONE PLAYER CAN SEE IT" << endl;
	cout << "PLAYER 1" << endl;
	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		cout << "Enter a 1 if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;

		if ((p1Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
		{
			cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
			i--;
		}
		p1Ships.Display();
	}
	p1Ships.clearScreen();
	cout << "SWITCH PLAYERS" << endl;
	cout << "PLAYER 2" << endl;
	for (int i = 0; i < numberOfShips; i++)
	{
		cout << "Enter in the position of where you would like to place your 1x" << i + 1 << " ship." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		cout << "Enter a 1 if you want the ship to be oriented vertically, 0 for horizontal." << endl;
		cin >> vert;
		if ((p2Ships.addShip(row, trueColumn, vert, i + 1, i)) == false)
		{
			cout << "SHIP WAS UNABLE TO BE ADDED, TRY AGAIN." << endl;
			i--;
		}
		p2Ships.Display();
	}
	//add in delay time as second player will not see last ship placed.
	p2Ships.clearScreen();
	cout << "Great, both players' boats have now been placed on the board. Now, it is time to attack the enemy!";
	cout << endl << endl;

	bool winner = false;
	int turn = 1;

	std::string ready = "";
	do
	{
		cout << "Are you ready to begin the game? (y/n)";
		cout << endl;
		cin >> ready;

	} while (ready != "yes" && ready != "y");

	cout << endl << endl;

	while (winner == false)
	{
		cout << "PLAYER 1 TURN [" << turn << "]";
		cout << endl << endl;

		cout << "YOUR SHIPS:";
		cout << endl << endl;

		p1Ships.Display();

		cout << endl << endl;

		cout << "ENEMY SHIPS:";
		cout << endl << endl;

		p1HitOrMiss.Display();
		cout << endl << endl;
		cout << "Enter in the position of where you would like to attack." << endl;
		cout << "Columns are labeled A-J, and rows are 1-10" << endl;
		cout << "Enter in the row value." << endl;
		cin >> row;
		while (row < 1 || row > 10)
		{
			cout << "Not a valid row position, try again." << endl;
			cin >> row;
		}
		cout << "Enter in the column value." << endl;
		cin >> column;
		while (column < 'A' || column > 'J')
		{
			cout << "Not a valid column position, try again." << endl;
			cin >> column;
		}
		int trueColumn = 0;
		if (column == 'A')
		{
			trueColumn = 1;
		}
		else if (column == 'B')
		{
			trueColumn = 2;
		}
		else if (column == 'C')
		{
			trueColumn = 3;
		}
		else if (column == 'D')
		{
			trueColumn = 4;
		}
		else if (column == 'E')
		{
			trueColumn = 5;
		}
		else if (column == 'F')
		{
			trueColumn = 6;
		}
		else if (column == 'G')
		{
			trueColumn = 7;
		}
		else if (column == 'H')
		{
			trueColumn = 8;
		}
		else if (column == 'I')
		{
			trueColumn = 9;
		}
		else if (column == 'J')
		{
			trueColumn = 10;
		}
		string spot = p2Ships.checkHit(row, trueColumn);
		if (spot != ".")
		{
			cout << "HIT!";
			cout << endl;
			if (spot == "S")
			{
				p2Sub.hit();
			}
			if (spot == "P")
			{
				p2Patrol.hit();
			}
			if (spot == "c")
			{
				p2Cruiser.hit();
			}
			if (spot == "D")
			{
				p2Destroyer.hit();
			}
			if (spot == "B")
			{
				p2BattleShip.hit();
			}
			if (spot == "C")
			{
				p2Carrier.hit();
			}
			p1HitOrMiss.update(row, column, "H");
		}
		else
		{
			cout << "MISS!";
			cout << endl;
			p1HitOrMiss.update(row, column, "M");
		}

		//stuff happens
		cout << "PLAYER 2 TURN [" << turn << "]";
		cout << endl;
	}


}


Executive::~Executive()
{
}
