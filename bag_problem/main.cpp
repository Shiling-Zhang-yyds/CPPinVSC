#include "vns.h"


void useVns(vector<bool> solution) 
{
	auto vns = new VNS(10, 20, 10);
	cout << "init " << endl;
	vns->print(solution);
	decltype(solution) global_best = solution; //全局最优解
	global_best = vns->mainFrame(solution);
	cout << endl << endl << "算法运行结束，最终输出解为" << endl;
	vns->print(global_best);
	cout << "背包中最多财富为 " << vns->f(global_best) << endl;
}


int main()
{
	srand((unsigned)time(0));

	vector<bool> solution{ 1, 1, 1, 1 };// 给定初始解
	useVns(solution);
	
	return 0;
}