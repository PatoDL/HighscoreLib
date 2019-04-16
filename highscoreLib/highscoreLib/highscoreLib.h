#ifndef HSLIB_H
#define HSLIB_H

#include <iostream>
#include <string>

using namespace std;

struct Player
{
	int score;
	string name;
};

class HighscoreTable
{
private:
	int size;
	Player* players;
	Player* bestPlayer;
	int highscore;
public:
	HighscoreTable();
	~HighscoreTable();
	void setSize(int s);
	int getSize();
	void addPlayer(Player p);
	int getPlayerScoreByName(string n);
	Player* getHighscorePlayer();
};
#endif
