#include "highscoreLib.h"

HighscoreTable::HighscoreTable()
{
	size = 1;
	players = new Player[size];
	(*players).name = "pepe";
	(*players).score = 0;
	bestPlayer = players;
	highscore = 0;
}

HighscoreTable::~HighscoreTable()
{
	delete[] players;
}

void HighscoreTable::setSize(int s)
{
	size = s;
}

int HighscoreTable::getSize()
{
	return size;
}

void HighscoreTable::addPlayer(Player p)
{
	bool added = false;
	players = bestPlayer;
	for (int i = 0; i < size; i++)
	{
		if (p.score > (*players).score)
		{
			size++;
			players++;
			*players = p;
			added = true;
		}

		if (!added)
		{
			players++;
		}
		else
		{
			i = size;
		}
	}
}

int HighscoreTable::getPlayerScoreByName(string n)
{
	players = bestPlayer;
	for (int i = 0; i < size; i++)
	{
		if ((*players).name == n)
		{
			return (*players).score;
		}
	}
}

Player HighscoreTable::getHighscorePlayer()
{
	return *bestPlayer;
}