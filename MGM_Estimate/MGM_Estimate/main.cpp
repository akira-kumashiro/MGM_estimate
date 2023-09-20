//#include "stdafx.h"
#include "GA.h"
#include <conio.h>
#include <stdio.h>

#define MAX_GENERATION 30000
#define MAX_GENOM_LIST 50
#define MAX_WEIGHT 60
#define VAR_NUM 2
//min:(-0.54719,-1.54719)=-1.9133

int main()
{
	double varMax[] = { 4,4 };
	double varMin[] = { -1.5,-3 };

	//�z���std::vector�֕ϊ�
	std::vector<double> vMax(varMax, std::end(varMax));
	std::vector<double> vMin(varMin, std::end(varMin));
	GA ga(MAX_GENOM_LIST, VAR_NUM, vMax, vMin);//��`�I�A���S���Y�����֐����܂Ƃ߂��N���X�̐錾

	//ga.init();//�ϐ��̏�����

	for (int i = 0; i <= MAX_GENERATION; i++)//���C���̃��[�v
	{
		bool change = ga.selection();//�I��

		ga.blxAlphaCrossover();//����

		//ga.mutation();//�ˑR�ψ�

		if (i % (MAX_GENERATION / 10) == 0 || change)
		{
			std::cout << "i=" << std::to_string(i) << std::endl;
			ga.calc(true);//�]���֐��̌v�Z
		}
		else
		{
			ga.calc(false);//�]���֐��̌v�Z
		}
	}

	while (1)
	{
		if (_kbhit() && _getch() == 27)
			break;
	}
	return 0;
}