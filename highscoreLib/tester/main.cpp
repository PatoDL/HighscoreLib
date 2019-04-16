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

	hst->addPlayer(tomas);
	hst->addPlayer(momo);

	Player* p;

	p = hst->getHighscorePlayer();

	for (int i = 0; i < (*hst).getSize(); i++)
	{
		cout << p->name.c_str() << " - " << p->score << endl;
		p++;
	}

	delete hst;

	cin.get();
}