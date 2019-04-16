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
			size++; //aumento el tamaño del array
			players = new Player[size]; //inicio un array nuevo
			*players = *bestPlayer; //ahora la primera pos del array apunta a una variable igual a bestplayer
			players++; //siguiente elemento del array
			*players = *(players - 1); //la segunda posicion del array ahora apunta a una variable igual a la de la posicion anterior
			players--; //vuelvo a la primera pos del array
			Player* bestPlayerA = bestPlayer; //pido memoria para guardar la posicion del bestplayer
			bestPlayer = players; //actualizo la posicion del bestplayer
			delete[] bestPlayerA; //me deshago de la anterior
			(*players) = p; //asigno al nuevo "best player" la data
			added = true; //confirmo que se agrego el nuevo elemento
		}

		if (!added)
		{
			players++;
		}
		else
		{
			i = size+1;
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

Player* HighscoreTable::getHighscorePlayer()
{
	return bestPlayer;
}