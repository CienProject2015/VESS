#include <iostream>
#include <random>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "unit.h"
using namespace std;

int random()
{
	srand(time(NULL));

	return rand() % 100 + 1;
}

int main()
{
	Unit abc;
	int a;
	cout << "1.강화 or 2.전투?" << endl;
	cin >> a;

	switch (a)
	{
	case 1:
		int a, b;

		cout << "무엇을 강화?" << endl << "1. sword" << endl << "2. shield" << endl;
		cin >> a;
		cout << "무슨 템으로 강화?" << endl;
		abc.temdul[0].name = "DRGAON";
		for (int i = 0; i < MAX_ITEM; i++)
		{
			cout << i + 1 << ". " << abc.temdul[i].name << endl;
		}
		cin >> b;

		switch (a)
		{
		case 1:
			abc.swordGanghwa(abc.sword, abc.temdul[b]);
			break;

		case 2:
			abc.shieldGanghwa(abc.shield, abc.temdul[b]);
			break;
		}
		break;

	case 2:
	{
		int playerHP = 200;

		int monsterHP = 200;
		int monsterAttack = 13;
		int monsterDefense = 2;
		int monsterProperty = 3;                //1은 가위 2는 바위 3은 보 , 이기는 속성이면 1.5배 데미지 입힘, 지는 속성이면 0.8배의 데미지를 입힘

		int swordAttack = 17;
		int shieldDefense = 10;
		int swordProperty = 4;

		int selDungeon = 3;

		int propertyWin;

		cout << "Battle을 시작합니다\n\n" << endl;

		Sleep(500);

		do
		{
			cout << "사용할 칼의 속성을 정하세요(1=가위, 2=바위, 3=보)." << endl;
			cin >> swordProperty;
		} while (swordProperty > 3);

		propertyWin = monsterProperty - swordProperty;
		if (propertyWin < 0) propertyWin += 3;
		if (propertyWin == 1)
		{
			swordAttack *= 1.5;
			cout << "상성이김\n";
		}
		if (propertyWin == 2)
		{
			swordAttack *= 0.7;
			cout << "상성짐\n";
		}

		Sleep(500);

		do
		{
			cout << "\n입장할 던전을 선택하시오.\n1.스터디룸\n2.동아리방" << endl;
			cin >> selDungeon;
			if (selDungeon == 1)
				cout << "스터디룸으로 입장합니다.\n" << endl;
			else if (selDungeon == 2)
				cout << "동아리방으로 입장합니다.\n" << endl;
			else
				cout << "잘못된 입력입니다. 다시 입력해주세요.\n" << endl;
		} while (selDungeon > 2);

		Sleep(500);

		while (playerHP != 0 && monsterHP != 0)
		{
			int judgement = random();

			cout << "\n현재 용사의 HP " << playerHP << "마물의 HP" << monsterHP << endl;

			Sleep(1000);

			if (random() == 1)
			{
				cout << "용사의 혼신의 일격! " << endl;
				monsterHP -= swordAttack * 100;
			}
			else if ((1 < judgement) && (judgement <= 90))
			{
				cout << "용사의 평범한 일격! " << endl;
				monsterHP -= swordAttack * 2;
			}
			else if ((90 < judgement) && (judgement <= 95))
			{
				cout << "용사의 비범한 일격! " << endl;
				monsterHP -= swordAttack * 5;
			}
			else if ((95 < judgement) && (judgement <= 100))
				cout << "용사의 일격이 빗나갔다!" << endl;

			Sleep(500);

			judgement = random();

			if (judgement == 1)
			{
				cout << "마물의 필살의 일격! " << endl;
				playerHP -= monsterAttack * 100;
			}
			else if ((1 < judgement) && (judgement <= 90))
			{
				cout << "마물의 평범한 일격! " << endl;
				playerHP -= monsterAttack;
			}
			else if ((90 < judgement) && (judgement <= 95))
			{
				cout << "마물의 회심의 일격! " << endl;
				playerHP -= monsterAttack * 1.5;
			}
			else if ((95 < judgement) && (judgement <= 100))
				cout << "마물의 일격이 빗나갔다!" << endl;
			Sleep(500);

			if (monsterHP <= 0)
			{
				cout << "\n용사가 마물을 물리쳤다!" << endl;
				break;
			}
			else if (playerHP <= 0)
			{
				cout << "\n용사의 패배!" << endl;
				break;
			}
		}
		break;
	}
	}
}

