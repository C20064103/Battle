#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")

int main(void)
{
	printf("******************************************************************************\n");
	printf("					  �@_,,...,_\n");
	printf("				   /_~,,..::: ~\"'�R\n");
	printf("				  (\"�S�@ii�@/ ^ ',)\n");
	printf("				 �@ :i�@ �@ i\"\n");
	printf("				�@�@ |(,,߄D�)	\<���̐搶���̂���ɂ�\n");
	printf("				�@�@ |(Ɂ@�@|�j \n");
	printf("				�@�@ | �@�@ |\n");
	printf("				�@   �R__�Q�m\n");
	printf("				     �@U\"U\n");
	printf("\n");
	printf("******************************************************************************\n");

	sndPlaySound(L"n78.wav", SND_ASYNC); //Play sound for Windows User

	_getch();
	system("cls");
	printf("�Q�[�����J�n���܂�.\n");
	_getch();
	printf("���̃Q�[���̖ړI��, �����X�^�[��ގ����邱�Ƃł�.\n");
	_getch();
	printf("���Ȃ��̃p�����[�^����͂��Ă�������.\n");

	int a;
	int b;	//player's state
	int h;

	printf("������:");
	scanf("%d", &a);
	assert(a >= 1);
	printf("�݂̂܂���:");
	scanf("%d", &b);
	assert(b >= 1);
	printf("������傭:");
	scanf("%d", &h);
	assert(h >= 1);
	printf("���Ȃ��̑�����\n");
	printf("	�Ђ̂��̂ڂ��F �U����2\n");
	printf("	�ʂ̂̂ӂ�: �h���2\n");
	printf("�ł�.\n");
	printf("\n");

	double ap = (double)a;	//convert state'snumber from int to double
	double bp = (double)b;
	double hp = (double)h;

	double at = (2 * 1.1) + ap;	//number for battle
	double dm = at - (double)2 / 6;
	int countm = ceil((double)8/dm);
	double bm = bp + (double)2;
	double de = (double)3 - (double)bm / 6;
	int counte = ceil((double)h / de);

	double he = 8;

	_getch();
	printf("�X���C���̃p�����[�^��, HP:8	�U����:3	�h���:2�ł�.\n");
	printf("���Ȃ��̍U���͂͂��悻%0.0f�ł�.\n", at);
	printf("�X���C���ɍU������Ƃ��悻%0.0f�̃_���[�W��^���܂�.\n", dm);
	printf("�X���C����%d��̍U���œ|�����Ƃ��ł��܂�.\n", countm);
	printf("\n");
	_getch();
	printf("���Ȃ���HP��	%0.0f, �h��͂�	%0.0f�ł�.\n", hp, bm);
	printf("�X���C���ɍU�������Ƃ��悻%0.0f�̃_���[�W���󂯂܂�.\n", de);
	printf("�X���C����%d��U�������Ɠ|��܂�.\n", counte);
	_getch();
	printf("�����L�[�������Ɛ퓬���J�n���܂�\n");

	_getch();
	system("cls");
	printf("******************************************************************************\n");
	printf("\n");
	printf("�@�@�@�@�@�@�@�@�@�@ i��i\n");
	printf("�@�@�@�@�@�@�@�@�@�@ |�@ |\n");
	printf("�@�@�@�@�@�@�@�@ ,,���f�@ �@ �e�R�A\n");
	printf("�@�@�@�@�@�@,,r�]�h�@�@�@�@�@�@ �R�\n");
	printf("�@�@�@�@ �^�@�@�@�@�@�@�@�@�@�@�@�_\n");
	printf("�@�@�@ /�@�@�@�@�i � �j�i � �j�@�@�@�@�R\n");
	printf("�@�@�@ |�@�@�@ ,-��@�@�@�@�@,-��@�@�@ |\n");
	printf("�@�@�@ �R�@�@ �R� �P�P�P�@�m�@�@�@/\n");
	printf("�@�@�@�@ `-��@�@�M�P�P�P�L�@�@�@�^\n");
	printf("�@�@�@�@�@�@ �P�P�P�P�P�P�P\n");
	printf("\n");
	printf("******************************************************************************\n");
	printf("�G�����ꂽ!!\n");

	srand((unsigned)time(NULL));
	double rm = 0.0;
	double re = 0.0;

	do
	{
		/*	//loop for rand, but this didn't work well. 
		do 
		{
			do 
			{
				double rm = (double)rand() / (double)(RAND_MAX + 1)+(double)1/10;
				printf("%f\n", rm);
			} while (rm < (double)1/10);
		} while (rm > (double)11/10);
		do
		{
			do
			{
				double re = (double)rand() / (double)(RAND_MAX + 1);
			} while (re < 0.9);
		} while (re > 1.1);
		*/

		//decide rand
		double rm = ((double)rand() / (double)(RAND_MAX + 1))*(double)1/5 + (double)9 / 10;
		double re = ((double)rand() / (double)(RAND_MAX + 1)) * (double)1 / 5 + (double)9 / 10;
		//printf("%f,%f\n", rm, re);   //rand test
		double rdm = rm * dm;
		double rde = re * de;

		int userhp = ceil((double)hp); //avoid that player looks at HP:0
		
		printf("�v���C���[(HP:%d)\n", userhp);
		printf("1.��������\n");
		printf("2.�ڂ�����\n");
		printf("3.�܂ق�\n");
		printf("4.�ɂ���\n");

		int act = 0;
		scanf("%d", &act);
		assert(act >= 1);
		assert(act <= 4);
		if (act <= 3)
		{
			switch (act)
			{
			case 1:
				he -= rdm;
				printf("�v���C���[�̍U��!\n");
				_getch();
				printf("�X���C����%0.0f�̃_���[�W!\n", rdm);
				if (he <= (double)0)
				{
					_getch();
					printf("�G��|����!\n");
					exit(1);
				}
				else
				{
					//NR
				}
				break;
			case 2:
				rde /= (double)2;
				printf("�v���C���[�͂܂���������߂�!\n");
				break;
			case 3:
				printf("�v���C���[�͎�����������!\n");
				_getch();
				printf("�������Ȃɂ�������Ȃ�����!\n");
				break;
			default:
				break;
			}
			hp -= rde;
			_getch();
			printf("�X���C���̍U��!\n");
			_getch();
			printf("�v���C���[��%0.0f�̃_���[�W���󂯂�!\n", rde);
			_getch();
			double de = (double)3 - (double)bm / 6;
			if (hp <= (double)0)
			{
				printf("�v���C���[�͓|�ꂽ!\n");
				exit(1);
			}
			else
			{
				//NR
			}
		}
		else
		{
			printf("�����o����!\n");
			exit(1);
		}
	} while (hp > (double)0);

	return 0;
}