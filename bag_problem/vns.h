#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <ctime>
#include <random>
#include <algorithm>
class VNS
{
public:
    //扰动邻域，将数组随机打乱
    void shaking(vector<bool>& s);
    //邻域操作
    vector<bool> swap(vector<bool>& s);
    vector<bool> mutation(vector<bool>& s);
    vector<bool> insert(vector<bool>& s);
    vector<bool> reverse(vector<bool>& s);

private:
};

// vns主框架

// vnd框架

// shaking框架

// 邻域操作
