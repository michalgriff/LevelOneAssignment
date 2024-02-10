#include<iostream>
#include<vector>
#include <map>

struct Room
{
	enum class Name { cell, gate, armory, jailers, exit };
	enum class Direction { N, S, E, W, none };
	std::string message; // the message displayed when in the room.
	std::vector<Direction> doors;// the directions in which there are doors.
	std::vector<Name> connectedRoom;// the name of the room in which the corresponding door leads.
	//NOTE:: these two vectors will eventually become a std::map after the STL level.
	bool hasKey{ false }; //whether or not the player has picked up the key.
};
//struct keeps track of the room the player is in, their health, and rather or not they have picked up the key.
struct Player
{
	Room::Name currentRoom{ Room::Name::cell };
	int health{ 10 };
	bool hasKey{ false };
};
/* GUI Functions */
void clearConsole();
void pauseConsole();
void splashScreen();
displayGameState;
displayGameDone;
displayIllegalMove;
getAction;

/* Engine Functions*/
std::vector<Room> buildMap();
randomizeKey;
changeGameState;
gameIsNotDone;

int main() {

	/*Splash Screen*/
	clearConsole();
	splashScreen();

	/*set up game*/
	std::vector<Room> map{ buildMap() };
	Player player;

	/*Until Game Termination Condition*/
	while (gameIsNotDone(player))
	{

		/*Display Game State*/
		clearConsole();
		displayGameState(player, map);

		/*Collect Player Action*/
		Room::Direction action{ getAction() };

		/*Update Game State*/
		if (!changeGameState(action, player, map))
		{
			displayIllegalMove(player, action);
		}
	}

	/*Display Termination Game State*/
	displayGameDone(player, map);

	return 0;

}


std::vector<Room> buildMap()
{
	std::vector<Room> map;
	map.push_back(
		{
			"A small, dark prison cell with doors South and East.",
			{Room::Direction::S, Room::Direction::E},
			{Room::Name::armory, Room::Name::gate},
			false
		});
	map.push_back(
		{
			"A large, torchlit room with doors West, South, and East. \n There is daylight entering under the door to the East.",
			{Room::Direction::W, Room::Direction::S, Room::Direction::E},
			{Room::Name::cell, Room::Name::jailers, Room::Name::exit},
			false
		});
	map.push_back(
		{
			"A store room with doors North and East.",
			{Room::Direction::N, Room::Direction::E},
			{Room::Name::cell, Room::Name::jailers},
			false
		});
	map.push_back(
		{
			"A jailer's barracks with doors West and North.",
			{Room::Direction::W, Room::Direction::N},
			{Room::Name::armory, Room::Name::gate},
			true
		});
	map.push_back(
		{
			"YOU FOUND THE KEY AND ESCAPED!",
			{},
			{},
			false
		});
	return map;
}

void clearConsole() {
	system("cls");
}

void pauseConsole() {
	system("PAUSE");
}

void splashScreen() {
	std::cout << "DUNGEON ADVENTURE" << std::endl;
	std::cout << std::endl;
	std::cout << "Michal Griffith (2024)" << std::endl;
	std::cout << "CPSC 2376, Programming II, Level 1 Quest" << std::endl;
	std::cout << "UA Little Rock, Computer Science Dept." << std::endl;
	std::cout << std::endl;
	std::cout << "INSTRUCTIONS:" << std::endl;
	std::cout << std::endl;
	std::cout << "Find the key and get out of the dungeon!" << std::endl;
	std::cout << std::endl;
	std::cout << "        (North)          " << std::endl;
	std::cout << "           w             " << std::endl;
	std::cout << "           |             " << std::endl;
	std::cout << "(West) a --+-- d (East)  " << std::endl;
	std::cout << "           |             " << std::endl;
	std::cout << "           s             " << std::endl;
	std::cout << "        (South)          " << std::endl;
	std::cout << std::endl;
	pauseConsole();
}

//randomly place the key in either the cell, the armory, the jailer's barrack, or the gate room.
randomizeKey //you will need to decide on the return type and parameters!
{

}

//output information as demonstrated in the instructions.
//You will need to deal with display changes that depend on the key.
//NOTE:: NO game variables such as the player or rooms should be modified in this function!!!
displayGameState
{


}
//output messages depending on if the player has one or lost.
displayGameDone
{


}

//output illegal move messages depending if player tries to exit without the key
//or the player tries to exit the wrong way out of a room.
displayIllegalMove
{


}

//ask for user input, convert char to Room::Direction
getAction
{
	std::map<char,Room::Direction> charConverter =
	{
		{'w', Room::Direction::N},
		{'s', Room::Direction::S},
		{'d',Room::Direction::E},
		{'a', Room::Direction::W}
	};
	char nextMove;
	std::cout << "Select Next Action: \n";
	std::cin >> nextMove;
	switch (nextMove)
	{
	case 'w':
		break;
	case 's':
		break;
	case 'd':
		break;
	case 'a':
		break;
	}

}

//This function is the only one that should make modifications to the player/rooms including picking up the key.
// This function should call other functions in order to display illegal moves and/or move the player to a new room.
// If the player moves to a new room, health needs to be decremented.
// Look at int main to decide on return type.

changeGameState
{

}



//Check the end-of-game conditions.  i.e If the player is out
//of health or the player has reached the exit
gameIsNotDone
{

}
