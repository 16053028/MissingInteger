#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){
    //Solution 1 -> have bug when there are numb 1;
//    sort(A.begin(), A.end());
//    A.erase( unique(A.begin(), A.end()) , A.end() );
//    int g_numb = A.front();
//
//    if(A.front() < 0){
//        g_numb = 1;
//    }else{
//        for(int i=0; i<A.size(); i++){
//            if(A[i] == g_numb){
//                g_numb++;
//            }else{
//                break;
//            }
//        }
//    }
//    return g_numb;

    //Solution 2 -> it's Working;
    bool hasOne; //flag for detect if the given input have value 1;
    int g_numb; // g_numb

    sort(A.begin(), A.end()); //Sorting The Array
    A.erase( remove_if(A.begin(), A.end(), [](int i){return i < 0;}) , A.end() ); // Remove Negative Value
    A.erase( unique(A.begin(), A.end()) , A.end() ); // Remove duplicate Value

    for(int i : A){ // iterate to all element in A
        if(i == 1){ // Check if the element have value 1
            hasOne = true; // flag for the value one has been found
        }
    }

    if(!hasOne){ // Check if the value one is found or not
        g_numb = 1; //If not found then value g_numb = 1
    }else{
        g_numb = A.front(); //if Found then value of g_numb is value of the first element.
    }

    if(g_numb < 0){ // check if value g_numb is less than 0.
        g_numb = 1; // if Yes, then change the g_numb value to 1;
    }else{ // if not less than 0
        for(int i=0; i<A.size(); i++){ // iterate to all element in given array
            if(A[i] == g_numb){ // if value g_numb is equal with value of A[i]
                g_numb++; // g_numb + 1
            }else{// if not
                break; // End the loop;
            }
        }
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
    vector<int> A = {1,2,2,4,5}; // -3,-1,-5,-4 {1,2,3,5,6}
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
