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
	cout << "1.��ȭ or 2.����?" << endl;
	cin >> a;

	switch (a)
	{
	case 1:
		int a, b;

		cout << "������ ��ȭ?" << endl << "1. sword" << endl << "2. shield" << endl;
		cin >> a;
		cout << "���� ������ ��ȭ?" << endl;
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
		int monsterProperty = 3;                //1�� ���� 2�� ���� 3�� �� , �̱�� �Ӽ��̸� 1.5�� ������ ����, ���� �Ӽ��̸� 0.8���� �������� ����

		int swordAttack = 17;
		int shieldDefense = 10;
		int swordProperty = 4;

		int selDungeon = 3;

		int propertyWin;

		cout << "Battle�� �����մϴ�\n\n" << endl;

		Sleep(500);

		do
		{
			cout << "����� Į�� �Ӽ��� ���ϼ���(1=����, 2=����, 3=��)." << endl;
			cin >> swordProperty;
		} while (swordProperty > 3);

		propertyWin = monsterProperty - swordProperty;
		if (propertyWin < 0) propertyWin += 3;
		if (propertyWin == 1)
		{
			swordAttack *= 1.5;
			cout << "���̱�\n";
		}
		if (propertyWin == 2)
		{
			swordAttack *= 0.7;
			cout << "����\n";
		}

		Sleep(500);

		do
		{
			cout << "\n������ ������ �����Ͻÿ�.\n1.���͵��\n2.���Ƹ���" << endl;
			cin >> selDungeon;
			if (selDungeon == 1)
				cout << "���͵������ �����մϴ�.\n" << endl;
			else if (selDungeon == 2)
				cout << "���Ƹ������� �����մϴ�.\n" << endl;
			else
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n" << endl;
		} while (selDungeon > 2);

		Sleep(500);

		while (playerHP != 0 && monsterHP != 0)
		{
			int judgement = random();

			cout << "\n���� ����� HP " << playerHP << "������ HP" << monsterHP << endl;

			Sleep(1000);

			if (random() == 1)
			{
				cout << "����� ȥ���� �ϰ�! " << endl;
				monsterHP -= swordAttack * 100;
			}
			else if ((1 < judgement) && (judgement <= 90))
			{
				cout << "����� ����� �ϰ�! " << endl;
				monsterHP -= swordAttack * 2;
			}
			else if ((90 < judgement) && (judgement <= 95))
			{
				cout << "����� ����� �ϰ�! " << endl;
				monsterHP -= swordAttack * 5;
			}
			else if ((95 < judgement) && (judgement <= 100))
				cout << "����� �ϰ��� ��������!" << endl;

			Sleep(500);

			judgement = random();

			if (judgement == 1)
			{
				cout << "������ �ʻ��� �ϰ�! " << endl;
				playerHP -= monsterAttack * 100;
			}
			else if ((1 < judgement) && (judgement <= 90))
			{
				cout << "������ ����� �ϰ�! " << endl;
				playerHP -= monsterAttack;
			}
			else if ((90 < judgement) && (judgement <= 95))
			{
				cout << "������ ȸ���� �ϰ�! " << endl;
				playerHP -= monsterAttack * 1.5;
			}
			else if ((95 < judgement) && (judgement <= 100))
				cout << "������ �ϰ��� ��������!" << endl;
			Sleep(500);

			if (monsterHP <= 0)
			{
				cout << "\n��簡 ������ �����ƴ�!" << endl;
				break;
			}
			else if (playerHP <= 0)
			{
				cout << "\n����� �й�!" << endl;
				break;
			}
		}
		break;
	}
	}
}

