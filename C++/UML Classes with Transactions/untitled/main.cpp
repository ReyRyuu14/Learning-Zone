#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>

//Add your student details:
//56714270
//
//COS2611

using namespace std;
bool isEven(int num) {
    return num % 2 == 0;
}

void qRemoveElements(std::deque<int> numbers) {

    auto newEnd = remove_if(numbers.begin(), numbers.end(), isEven);
numbers.erase(newEnd, numbers.end());
    //display
    std::cout << "Number after removal" << "\n";

    for (int num : numbers) {
        std::cout << num << " ";
    }

}//qRemoveElemensts

int main(){

    std::deque<int> myNumbers = { 16,17, 20,23,38,55 };
    qRemoveElements(myNumbers);
    return 0;
}
