#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

class VNS
{
public:
    // 实例化参数 [外层迭代次数, 背包限制, 内层迭代次数]
    VNS(double limit, int iter_times, int inner_iter)
    {
        this->limit = limit;
        this->iter_times = iter_times;
        this->inner_iter = inner_iter;
    }

    double limit;   //背包容量限制
    int iter_times; // VNS的外层迭代次数
    int inner_iter; // VND中邻域迭代次数

    // 打印解
    void print(const vector<bool>& solution);

    //扰动邻域，将数组随机打乱
    void shaking(vector<bool>& s);

    // 适应度计算
    double f(vector<bool>& s);

    // 主框架
    vector<bool> mainFrame(vector<bool>& s);

    //邻域操作
    vector<bool> swap(vector<bool>& s);
    vector<bool> mutation(vector<bool>& s);
    vector<bool> insert(vector<bool>& s);
    vector<bool> reverse(vector<bool>& s); 
};