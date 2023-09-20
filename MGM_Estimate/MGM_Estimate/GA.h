#pragma once

#include<vector>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

class GA
{
private:
	int max_genom_list;//�̐�
	int var_num;//�i���̌�
	double individualMutationRate = 0.1;//�̓ˑR�ψٗ�
	int minNum = 0, maxNum = 0;
	double alpha = 0.5;
	std::vector<double> varMax, varMin;//�ϐ��̍ŏ��l�E�ő�l
public:
	double resultSumValue;//�]���֐��̍��v

	class Data//�f�[�^�i�[�p�N���X
	{
	private:
		int var_num;//�ϐ��̐�
	public:
		std::vector<double> x;//���W
		double functionValue;//�^����ꂽ�֐��̒l
		double result;

		Data(int _var_num)//�R���X�g���N�^
		{
			var_num = _var_num;

			x.resize(var_num);//isIncluded�̔z��̒����̐ݒ�
		}
	};

	std::vector<Data> data, prev_data;//����O��Œl��ێ����邽�߂�2��
	Data eliteData;
	GA(int _max_genom_list, int _var_num, std::vector<double> _varMax, std::vector<double> _varMin);	//�R���X�g���N�^
	bool init();//������
	bool selection();//�I��

	bool blxAlphaCrossover();
	bool mutation();//�ˑR�ψ�
	bool calc(bool enableDisplay);//�]���֐��̌v�Z
private:
	bool calcResult(bool enableSort);
	int random(int min, int max);
	double random(int min, double max);
	double random(double min, int max);
	double random(double min, double max);
	bool displayValues();
; public:
	~GA();//�f�R���X�g���N�^
};