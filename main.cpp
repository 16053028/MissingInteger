#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){
    int g_numb = 0;

    sort(A.begin(), A.end()); //Sorting The Array
    A.erase( remove_if(A.begin(), A.end(), [](int i){return i < 0;}) , A.end() ); // Remove Negative Value
    A.erase( unique(A.begin(), A.end()) , A.end() ); // Remove duplicate Value

    if(A[0] > 1){
        g_numb = 1;
    } else if(A[0] == 0 || A[0] == 1){
        for(int i=0; i < A.size(); i++){
            g_numb = A[i] +1;
            if(A[i+1] != g_numb){
                break;
            }
        }
    }else {
        g_numb = 1;
    }
    return g_numb; // return g_numb;
}

void task(){
cout << "Create a function that return the smallest" << endl
<< "positive bigger than 0 integer in the given Array" << endl
<< "";
}

int main()
{
    task();
    cout << endl << "Pseudo-Code : " << endl;
    cout << "Test Input 1 \t\t: ";
    vector<int> A = {1,1,3,3,2,5,5,5}; // -3,-1,-5,-4 {1,2,3,5,6}
    for(int i : A){
        cout << i << " ";
    }sort(A.begin(), A.end()); cout << endl << "Sorted to \t\t: ";
    for(int i : A){
        cout << i << " ";
    }cout << endl << "Remove Duplicate \t: "; A.erase( unique(A.begin(), A.end()) , A.end() );
    for(int i : A){
        cout << i << " ";
    }cout << endl << "Remove Negative \t: "; A.erase( remove_if(A.begin(), A.end(), [](int i){return i < 0;}) , A.end() );
    for(int i : A){
        cout << i << " ";
    }
    cout << endl;
    cout << "Missing Number is \t: " << solution(A) << endl << endl;

    return 0;
}
