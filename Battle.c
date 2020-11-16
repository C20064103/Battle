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
	printf("					  　_,,...,_\n");
	printf("				   /_~,,..::: ~\"'ヽ\n");
	printf("				  (\"ヾ　ii　/ ^ ',)\n");
	printf("				 　 :i　 　 i\"\n");
	printf("				　　 |(,,ﾟДﾟ)	\<この先生きのこるには\n");
	printf("				　　 |(ﾉ　　|） \n");
	printf("				　　 | 　　 |\n");
	printf("				　   ヽ__＿ノ\n");
	printf("				     　U\"U\n");
	printf("\n");
	printf("******************************************************************************\n");

	sndPlaySound(L"n78.wav", SND_ASYNC); //Play sound for Windows User

	_getch();
	system("cls");
	printf("ゲームを開始します.\n");
	_getch();
	printf("このゲームの目的は, モンスターを退治することです.\n");
	_getch();
	printf("あなたのパラメータを入力してください.\n");

	int a;
	int b;	//player's state
	int h;

	printf("ちから:");
	scanf("%d", &a);
	assert(a >= 1);
	printf("みのまもり:");
	scanf("%d", &b);
	assert(b >= 1);
	printf("たいりょく:");
	scanf("%d", &h);
	assert(h >= 1);
	printf("あなたの装備は\n");
	printf("	ひのきのぼう： 攻撃力2\n");
	printf("	ぬののふく: 防御力2\n");
	printf("です.\n");
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
	printf("スライムのパラメータは, HP:8	攻撃力:3	防御力:2です.\n");
	printf("あなたの攻撃力はおよそ%0.0fです.\n", at);
	printf("スライムに攻撃するとおよそ%0.0fのダメージを与えます.\n", dm);
	printf("スライムを%d回の攻撃で倒すことができます.\n", countm);
	printf("\n");
	_getch();
	printf("あなたのHPは	%0.0f, 防御力は	%0.0fです.\n", hp, bm);
	printf("スライムに攻撃されるとおよそ%0.0fのダメージを受けます.\n", de);
	printf("スライムに%d回攻撃されると倒れます.\n", counte);
	_getch();
	printf("何かキーを押すと戦闘を開始します\n");

	_getch();
	system("cls");
	printf("******************************************************************************\n");
	printf("\n");
	printf("　　　　　　　　　　 i⌒i\n");
	printf("　　　　　　　　　　 |　 |\n");
	printf("　　　　　　　　 ,,ｒ’　 　 ‘ヽ、\n");
	printf("　　　　　　,,r‐”　　　　　　 ヽ､\n");
	printf("　　　　 ／　　　　　　　　　　　＼\n");
	printf("　　　 /　　　　（ ･ ）（ ･ ）　　　　ヽ\n");
	printf("　　　 |　　　 ,-､　　　　　,-､　　　 |\n");
	printf("　　　 ヽ　　 ヽ､ ￣￣￣　ノ　　　/\n");
	printf("　　　　 `-､　　｀￣￣￣´　　　／\n");
	printf("　　　　　　 ￣￣￣￣￣￣￣\n");
	printf("\n");
	printf("******************************************************************************\n");
	printf("敵が現れた!!\n");

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
		
		printf("プレイヤー(HP:%d)\n", userhp);
		printf("1.こうげき\n");
		printf("2.ぼうぎょ\n");
		printf("3.まほう\n");
		printf("4.にげる\n");

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
				printf("プレイヤーの攻撃!\n");
				_getch();
				printf("スライムに%0.0fのダメージ!\n", rdm);
				if (he <= (double)0)
				{
					_getch();
					printf("敵を倒した!\n");
					exit(1);
				}
				else
				{
					//NR
				}
				break;
			case 2:
				rde /= (double)2;
				printf("プレイヤーはまもりをかためた!\n");
				break;
			case 3:
				printf("プレイヤーは呪文を唱えた!\n");
				_getch();
				printf("しかしなにもおこらなかった!\n");
				break;
			default:
				break;
			}
			hp -= rde;
			_getch();
			printf("スライムの攻撃!\n");
			_getch();
			printf("プレイヤーは%0.0fのダメージを受けた!\n", rde);
			_getch();
			double de = (double)3 - (double)bm / 6;
			if (hp <= (double)0)
			{
				printf("プレイヤーは倒れた!\n");
				exit(1);
			}
			else
			{
				//NR
			}
		}
		else
		{
			printf("逃げ出した!\n");
			exit(1);
		}
	} while (hp > (double)0);

	return 0;
}