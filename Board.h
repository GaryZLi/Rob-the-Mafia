class Board
{
private:
	int i, j, a, row, column, num, randRow, randColumn, randNum;
	int BoardValue[7][7];
	int BoardValueAi[7][7];
	char BoardOut[7][7];
	char BoardOutAi[7][7];

public:
	int destroyedMe = 0, destroyedAi = 0;

public:
	void random();

	void set_BoardValueE();

	void set_BoardValueM();

	void set_BoardValueH();

	void set_BoardValueAiE();

	void set_BoardValueAiM();

	void set_BoardValueAiH();

	void set_BoardOut();

	void set_BoardOutAi();

	void show_BoardValue();

	void show_BoardValueAi();

	void show_BoardOut();

	void show_BoardOutAi();

	void AttackAi();

	void AttackMeE();

	void AttackMeM();

	void AttackMeH();

	int get_DestroyedAi();

	int get_DestroyedMe();
};



