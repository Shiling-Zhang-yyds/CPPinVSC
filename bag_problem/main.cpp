#include "vns.h"

// 计算目标函数值
double f(const vector<bool>& list, const double limit)
{
	if (list.size() != 4)
	{
		throw "数组长度必须为4";
	}
	double value[4] = { 1, 3, 5, 9 };  //价值
	double weight[4] = { 2, 3, 4, 7 }; //重量
	double obj_val = 0;
	double treasure = 0, penalty = 0;
	for (int i = 0; i < 4; i++)
	{
		treasure += list.at(i) * value[i];
		penalty += list.at(i) * weight[i];
	}

	// cout << "财富值 " << treasure << "     总重量 " << penalty << endl;
	penalty -= limit;
	if (penalty > 0)
	{
		penalty *= 3;
		obj_val = treasure - penalty;
	}
	else
	{
		obj_val = treasure;
	}
	return obj_val;
}

double fp(const vector<bool>& list, const double limit)
{
	if (list.size() != 4)
	{
		throw "数组长度必须为4";
	}
	double value[4] = { 1, 3, 5, 9 };  //价值
	double weight[4] = { 2, 3, 4, 7 }; //重量
	double obj_val = 0;
	double treasure = 0, penalty = 0;
	for (int i = 0; i < 4; i++)
	{
		treasure += list.at(i) * value[i];
		penalty += list.at(i) * weight[i];
	}

	cout << "财富值 " << treasure << "     总重量 " << penalty << endl;
	penalty -= limit;
	if (penalty > 0)
	{
		penalty *= 3;
		obj_val = treasure - penalty;
	}
	else
	{
		obj_val = treasure;
	}
	return obj_val;
}

void print(const vector<bool>& solution)
{
	for (auto iter = solution.begin(); iter != solution.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(0));
	vector<bool> solution{ 0, 1, 0, 1 };
	auto vns = new VNS();
	const int iter_times = 20;
	int i = 0;
	const int limit = 10; //背包容量
	cout << "init " << endl;
	print(solution);

	 decltype(solution) global_best = solution; //全局最优解

	// VNS
	while (i < iter_times)
	{
		cout << "当前迭代第" << i + 1 << "次 ";
		vns->shaking(solution);
		cout << "扰动解";
		print(solution);
		int j = 0;
		int inner_iter = 10;
		bool noExit = true;
		decltype(solution) current = solution;
		decltype(solution) best = solution;
		// VND
		while (noExit)
		{
			switch (j)
			{
			case 0:
			{
				int n = 0;
				while (n < inner_iter)
				{
					decltype(solution) inner_s = vns->reverse(current);
					if (f(inner_s, limit) > f(best, limit))
					{
						current = inner_s;
					}
					n++;
				}
				if (f(current, limit) > f(best, limit))
				{
					best = current;
					cout << "邻域1 reverse  " << f(best, limit) << endl;
					print(best);
					j = 0;
				}
				else
				{
					j++;
				}
				break;
			}
			case 1:
			{
				int n = 0;
				while (n < inner_iter)
				{
					decltype(solution) inner_s = vns->mutation(current);
					if (f(inner_s, limit) > f(best, limit))
					{
						current = inner_s;
					}
					n++;
				}
				if (f(current, limit) > f(best, limit))
				{
					best = current;
					cout << "邻域2 mutation  " << f(best, limit) << endl;
					print(best);
					j = 0;
				}
				else
				{
					j++;
				}
				break;
			}
			case 2:
			{
				int n = 0;
				while (n < inner_iter)
				{
					decltype(solution) inner_s = vns->insert(current);
					if (f(inner_s, limit) > f(best, limit))
					{
						current = inner_s;
					}
					n++;
				}
				if (f(current, limit) > f(best, limit))
				{
					best = current;
					cout << "邻域3 insert  " << f(best, limit) << endl;
					print(best);
					j = 0;
				}
				else
				{
					j++;
				}
				break;
			}
			case 3:
			{
				int n = 0;
				while (n < inner_iter)
				{
					decltype(solution) inner_s = vns->swap(current);
					if (f(inner_s, limit) > f(best, limit))
					{
						current = inner_s;
					}
					n++;
				}
				if (f(current, limit) > f(best, limit))
				{
					best = current;
					cout << "邻域4 swap  " << f(best, limit) << endl;
					print(best);
					j = 0;
				}
				else
				{
					j++;
				}
				break;
			}

			default:

				noExit = false;
				break;
			}
		}
		
		if (f(best, limit) > f(global_best, limit))
		{
			global_best = best;
		}
		cout << "第 " << i + 1 << "次迭代完成后，全局最优解为 " << endl;
		print(global_best);
		cout << "--------------------------" << endl;
		cout << "--------------------------" << endl;
		cout << endl;
		i++;
	}

	cout << endl << endl << "算法运行结束，最终输出解为" << endl;
	print(global_best);
	cout << "背包中最多财富为 " << f(global_best, limit) << endl;
	system("pause");
	return 0;
}