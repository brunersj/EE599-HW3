#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<int> VectToSum(std::vector<int>&, int);
    bool ValidBracket(std::string);
    int FirstElement();
    int LastElement();
    int CurrentElement();
    void IthElement(int i);
    void SetV(std::vector<int> v);
    void SetIt(std::vector<int>::iterator it);
    std::vector<int> GetV();
    std::vector<int>::iterator GetIt();
    int GetSize();
    void PrintV();
private:
    std::vector<int>::iterator it_;
    std::vector<int> v_;
    int vSize_;


};



#endif