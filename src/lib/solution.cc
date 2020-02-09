#include "solution.h"
#include <iostream>
#include <iterator>
using std::cout;
using std::endl;


// Question 2
// O(n)
std::vector<int> Solution::VectToSum(std::vector<int>& input, int sum){
    std::unordered_map<int,int> vectMap;
    std::vector<int> output;

    if(input.size() <= 1){
        return output;
    }

    // O(n)
    for (int i = 0; i < input.size(); i++){
        // O(1) - unordered
        vectMap.insert(std::pair<int,int>(input[i],i));
    }
    


    int firstInt;
    int secondInt;
    // O(n)
    for(auto it = input.begin(); it < input.end(); it++){
        firstInt = *it;
        secondInt = sum - *it;
        // if(secondInt < 0){
        //     continue;
        // }
        // else
        {
            // O(1)
            std::unordered_map<int,int>::const_iterator mapIt = vectMap.find(secondInt);

            if (mapIt == vectMap.end()){ // second int does not exist to add to sum
                cout << "DNE" << endl;
            }
            else { // second int exists - find index
                int secondIndex = mapIt->second;
                int firstIndex = it - input.begin();
                // assuming you cannot use the same value twice
                if(secondIndex == firstIndex){
                    continue;
                }
                // cout << "first int: " << firstInt << " first index: " << it - input.begin() << endl;
                // cout << "second int: "<< secondInt << " second index: " << secondIndex << endl;
                else if(secondIndex > firstIndex){
                    output.push_back(firstIndex); // push first index
                    output.push_back(secondIndex); // push second index
                }
                else if (firstIndex > secondIndex){
                   output.push_back(secondIndex); // push second index 
                   output.push_back(firstIndex); // push first index
                }
                // cout << "first index: " << output[0] << " second index: " << output[1] << endl;
                return output;
            }
        }
    }
    return output;
}

// Question 4
// O(n)
bool Solution::ValidBracket(std::string input){
    std::stack<char> bracketStack; 
    for (auto i : input){
        if(i == '('){
            bracketStack.push(')');
        }
        else if( i == '{' ){
            bracketStack.push('}');
        }
        else if(i == '['){
            bracketStack.push(']');
        }

        if(i == ')'){ // check stack if this char is top
            if (bracketStack.top() != ')'){
                return false;
            }
            else{
                bracketStack.pop();
            }
        }
        else if( i == '}' ){
            if (bracketStack.top() != '}'){
                return false;
            }
            else{
                bracketStack.pop();
            }
        }
        else if(i == ']'){
            if (bracketStack.top() != ']'){
                return false;
            }
            else{
                bracketStack.pop();
            }
        }

    }
    if (!bracketStack.empty()){
        return false;
    }
    else{
        return true;
    }
}

// Question 6

void Solution::SetV(std::vector<int> v){
    v_ = v;
    vSize_ = v_.end() - v_.begin();
    it_ = v_.begin();
}
void Solution::SetIt(std::vector<int>::iterator it){
    it_ = it;
}

std::vector<int> Solution::GetV(){
    return v_;
}

std::vector<int>::iterator Solution::GetIt(){
    return it_;
}

int Solution::GetSize(){
    return vSize_;
}

void Solution::PrintV(){
    cout << "Vector: ";
    for (auto i : v_){
        cout << i << " ";
    }
    cout << "\n";
}

int Solution::FirstElement(){
    return *v_.begin();
}

int Solution::LastElement(){
    return *(v_.end()-1);
}

int Solution::CurrentElement(){
    return *it_;
}

void Solution::IthElement(int i){
    // cout << "Dist: " << ((v_.begin()-it_) + i) << endl;
    // cout << "size: " << vSize_ << endl;
    if((it_ - v_.begin() + i) > vSize_){
        cout << "\nSorry! You cannot traverse "<< i <<" elements from your current location." << endl;
        }
    else{
        //cout << "Dist: " << ((v_.begin()-it_) + i) << endl;
        it_ = it_ + i;
        cout << "Output: " << *it_ << endl;
        
    }
    
}