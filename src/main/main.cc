#include <iostream>
#include "src/lib/solution.h"
using std::cout;
using std::endl;

int main()
{
    Solution solution ;
// Question 1:
/*
Pros / Cons:
Passing parameters by value:
    * Pros:
    
Passing parameters using pointers
Passing parameters using references
Passing parameters using const references
*/

// Question 2:
    std::vector<int> input = {1,2,4, 4,3,9};
    int sum = 8 ;
    std::vector<int> output = solution.VectToSum(input, sum);
    cout << "Question 2\nv = [";
    for (auto i : input){
        cout << i << " ";
    }
    cout << "]" << endl;
    cout << "Sum to: " << sum << endl;
    if (output.size() > 0){
        cout << "output: v[" << output[0] << "] + v[" << output[1] << "] = " << sum << endl;
    }
    else{
        cout << "No elements add to sum" << endl;
    }

// Question 3:
    return EXIT_SUCCESS;
}