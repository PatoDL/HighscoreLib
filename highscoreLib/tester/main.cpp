#include "highscoreLib.h"

void main()
{
	HighscoreTable* hst = new HighscoreTable();

	Player tomas;
	tomas.name = "tomas";
	tomas.score = 10;

	Player momo;
	momo.name = "momo";
	momo.score = 40;

	(*hst).addPlayer(tomas);
	(*hst).addPlayer(momo);

	cout << (*hst).getPlayerScoreByName(tomas.name) << "-" << tomas.name << endl;
	cout << (*hst).getPlayerScoreByName(momo.name) << "-" << momo.name << endl;

	delete hst;

	cin.get();
}