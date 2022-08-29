#include "vns.h"

void VNS::shaking(vector<bool>& s)
{
    random_shuffle(s.begin(), s.end());
}

vector<bool> VNS::swap(vector<bool>& s)
{
    vector<bool> temp_s = s;
    int idx1 = rand() % (s.size());
    int idx2 = rand() % (s.size());
    while (idx1 == idx2)
    {
        idx2 = rand() % (s.size());
    }
    //cout << "swap " << idx1 << " " << idx2 << endl;

    int temp = temp_s[idx1];
    temp_s[idx1] = temp_s[idx2];
    temp_s[idx2] = temp;
    return temp_s;
}

vector<bool> VNS::mutation(vector<bool>& s)
{
    vector<bool> temp_s = s;
    int idx = rand() % (s.size());
    //cout << "mutation " << idx << endl;
    temp_s[idx] = !temp_s[idx];
    return temp_s;
}

vector<bool> VNS::insert(vector<bool>& s)
{
    vector<bool> temp_s = s;
    int idx1 = rand() % (s.size()); // 提取位置
    int idx2 = rand() % (s.size()); // 插入位置
    while (idx1 == idx2)
    {
        idx2 = rand() % (s.size());
    }
    //cout << "insert " << idx1 << " " << idx2 << endl;

    // 1、如果 idx1 < idx2
    bool temp = temp_s.at(idx1);
    auto iter = temp_s.begin() + idx1;
    temp_s.erase(iter);

    temp_s.insert(temp_s.begin() + idx2, temp);

    return temp_s;
}

vector<bool> VNS::reverse(vector<bool>& s)
{
    vector<bool> temp_s;
    for (auto it = s.cbegin(); it != s.cend(); it++) {
        temp_s.push_back(*it);
    }
    return temp_s;
}