#include "vns.h"

void VNS::print(const vector<bool>& solution)
{
	for (auto iter = solution.begin(); iter != solution.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void VNS::shaking(vector<bool>& s)
{
	random_shuffle(s.begin(), s.end());
}

double VNS::f(vector<bool>& list) {
	if (list.size() != 4) { throw "数组长度必须为4"; }
	double value[4] = { 1, 3, 5, 9 };  //价值
	double weight[4] = { 2, 3, 4, 7 }; //重量
	double obj_val = 0;
	double treasure = 0, penalty = 0;
	for (int i = 0; i < 4; i++)
	{
		treasure += list.at(i) * value[i];
		penalty += list.at(i) * weight[i];
	}
	penalty -= limit;
	if (penalty > 0) {
		penalty *= 3;
		obj_val = treasure - penalty;
	}
	else { obj_val = treasure; }
	return obj_val;
}

vector<bool> VNS::mainFrame(vector<bool>& solution) {
	int i = 0;
	vector<bool> global_best = solution;
	while (i < iter_times)
	{
		cout << "当前迭代第" << i + 1 << "次 ";
		shaking(solution);
		cout << "扰动解";
		print(solution);
		int j = 0;
		//int inner_iter = 10;
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
					auto inner_s = reverse(current);
					if (f(inner_s) > f(best)) { current = inner_s; }
					n++;
				}
				if (f(current) > f(best))
				{
					best = current;
					cout << "邻域1 reverse  " << f(best) << endl;
					print(best);
					j = 0;
				}
				else { j++; }
				break;
			}
			case 1:
			{
				int n = 0;
				while (n < inner_iter)
				{
					auto inner_s = mutation(current);
					if (f(inner_s) > f(best)) { current = inner_s; }
					n++;
				}
				if (f(current) > f(best))
				{
					best = current;
					cout << "邻域2 mutation  " << f(best) << endl;
					print(best);
					j = 0;
				}
				else { j++; }
				break;
			}
			case 2:
			{
				int n = 0;
				while (n < inner_iter)
				{
					auto inner_s = insert(current);
					if (f(inner_s) > f(best)) { current = inner_s; }
					n++;
				}
				if (f(current) > f(best))
				{
					best = current;
					cout << "邻域3 insert  " << f(best) << endl;
					print(best);
					j = 0;
				}
				else { j++; }
				break;
			}
			case 3:
			{
				int n = 0;
				while (n < inner_iter)
				{
					auto inner_s = swap(current);
					if (f(inner_s) > f(best)) { current = inner_s; }
					n++;
				}
				if (f(current) > f(best))
				{
					best = current;
					cout << "邻域4 swap  " << f(best) << endl;
					print(best);
					j = 0;
				}
				else { j++; }
				break;
			}
			default:
				noExit = false;
				break;
			}
		}
		if (f(best) > f(global_best)) { global_best = best; }
		cout << "第 " << i + 1 << "次迭代完成后，全局最优解为 " << endl;
		print(global_best);
		cout << f(global_best) << endl;
		
		cout << endl;
		i++;
	}
	return global_best;
}

vector<bool> VNS::swap(vector<bool>& s)
{
	vector<bool> temp_s = s;
	int idx1 = rand() % (s.size());
	int idx2 = rand() % (s.size());
	while (idx1 == idx2) { idx2 = rand() % (s.size()); }
	int temp = temp_s[idx1];
	temp_s[idx1] = temp_s[idx2];
	temp_s[idx2] = temp;
	return temp_s;
}

vector<bool> VNS::mutation(vector<bool>& s)
{
	vector<bool> temp_s = s;
	int idx = rand() % (s.size());
	temp_s[idx] = !temp_s[idx];
	return temp_s;
}

vector<bool> VNS::insert(vector<bool>& s)
{
	vector<bool> temp_s = s;
	int idx1 = rand() % (s.size()); // 提取位置
	int idx2 = rand() % (s.size()); // 插入位置
	while (idx1 == idx2) { idx2 = rand() % (s.size()); }
	bool temp = temp_s.at(idx1);
	auto iter = temp_s.begin() + idx1;
	temp_s.erase(iter);
	temp_s.insert(temp_s.begin() + idx2, temp);
	return temp_s;
}

vector<bool> VNS::reverse(vector<bool>& s)
{
	vector<bool> temp_s;
	for (auto it = s.cbegin(); it != s.cend(); it++) { temp_s.push_back(*it); }
	return temp_s;
}