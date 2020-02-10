#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/sll.h"
#include "src/lib/academicrecord.h"
using std::cout;
using std::endl;

int main()
{
    Solution solution ;
// Question 1:
/*
Pros / Cons:
Passing parameters by value:
    * Pros: Simpler / more straightforward. Don't have to worry about pointers. Original data is protected
    * Cons: Poor performance if parameter is large. Requires parameter to be copied. Costs memory and runtime performance. Original data cannot be modified 
Passing parameters using pointers:
    * Pros: Better performance since parameter is not copied. Can modify parameter directly
    * Cons: Original data is not protected.
Passing parameters using references:
    * Pros: Better performance since parameter is not copied. Can modify parameter directly. More intuitive than pointers
    * Cons: Original data is not protected. 
Passing parameters using const references:
    * Pros: Better performance since parameter is not copied. Original data is protected. More intuitive than pointers
    * Cons: Cannot directly modify parameter
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

cout << "Question 3:" << endl;
SinglyLinkedList sll;
SinglyLinkedList sll1(input,3);


sll.push_back(4);
//sll.print();
sll.push_back(7);
sll.push_front(5);
sll.print();
sll.push_front(6);
sll.insert_after(sll.head_->next->next, 11);
sll.print();
sll.erase(sll.head_->next);
sll.print();
sll.pop_front();
sll.print();
cout << sll.size() << endl;
sll.pop_back();
sll.print();
sll.push_back(7);
sll.print();
cout << "Back: " << sll.back() << endl;
cout << "Front: " << sll.front() << endl;
cout << sll.GetBackPointer() << endl;
cout << sll.GetIthPointer(1) << endl;




// Question 4:

  std::string input4 = "(a+b)";
  cout << "\nQuestion 4:\ninput: " << input4 << endl;
  bool output4 = solution.ValidBracket(input4);
  cout << output4 << endl;

// Question 5:

    AcademicRecord obj1, obj2;
    obj1.SetMaths(5);
    obj1.SetComputers(10);
    obj1.SetPhysics(95);
    cout << "Value before incrementation ::\n" << obj1.Print() << endl;
    obj1++;
    cout<< "Value after incrementation ::\n"<< obj1.Print() << endl;
    obj1--;
    cout<< "Value after decrementation ::\n"<< obj1.Print() << endl;
    obj2=obj1;
    cout<< "Value of Object 2::" << obj2.Print() << endl;
    obj2+=50;
    cout<< "Value of Object 2 after increasing marks by 50 for each subject::\n" << obj2.Print() << endl;
    obj2-=30;
    cout<< "Value of Object 2 after decreasing marks by 30 for each subject::\n" << obj2.Print() << endl;
    

// Question 6:

    Solution q6;
    std::vector<int> v = {1, 4, 5, 23, 100, 12, 18, 175};
    q6.SetV(v);
    //q6.SetIt(q6.GetV().begin());
    int select = 0;
    while(select != 5){
        cout <<"\n**************************************\n";
        q6.PrintV();
        cout << "**************************************\n";
        cout <<"Please choose any of the following options:\n";
        cout << "\t1. What is the first element?\n";
        cout << "\t2. What is the last element?\n";
        cout << "\t3. What is the current element?\n";
        cout << "\t4. What is the ith element from the current location?\n";
        cout << "\t5. Exit.\n";

    std::cin >> select;
        switch(select){
            case 1: 
                cout << "Output: " << q6.FirstElement();
                break;

            case 2: 
                cout << "Output: " << q6.LastElement();
                break;

            case 3: 
                cout << "Output: " << q6.CurrentElement();
                break;

            case 4: 
                cout << "What is the value of i? ";
                int i;
                std::cin >> i;
                q6.IthElement(i);
                
                break;

            case 5: 
                cout << "Exit!\n";
                break;
        
            default: cout << "Incorrect Input\n";
        
        }
    }
    return EXIT_SUCCESS;
}