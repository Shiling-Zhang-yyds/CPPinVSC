#include "vns.h"


void useVns(vector<bool> solution) 
{
	auto vns = new VNS(10, 20, 10);
	cout << "init " << endl;
	vns->print(solution);
	decltype(solution) global_best = solution; //ȫ�����Ž�
	global_best = vns->mainFrame(solution);
	cout << endl << endl << "�㷨���н��������������Ϊ" << endl;
	vns->print(global_best);
	cout << "���������Ƹ�Ϊ " << vns->f(global_best) << endl;
}


int main()
{
	srand((unsigned)time(0));

	vector<bool> solution{ 1, 1, 1, 1 };// ������ʼ��
	useVns(solution);
	
	return 0;
}