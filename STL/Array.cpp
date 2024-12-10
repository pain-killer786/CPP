#include<iostream> //For input and output operations
#include<array> // For using the C++ STL array container

using namespace std;

int main()
{
    //Create a C++ STL array with 4 elements initialized to {1,2,3,4}
    array<int,4> a ={1,2,3,4};
    
    //Get the size of the array using the .size() method
    int size = a.size();

    //Loop through the array elements using the size and print each element 
    for (int i=0;i<size;i++)
    {
        cout<<a[i]<<endl; //Print the element at index 'i'
    }
    
    // Use the .at() method to access the element at the 2nd index 
    cout<<"Element at 2nd Index->"<<a.at(2)<<endl;

    //Check if the array is empty using .empty(), return true if empty, false otherwise
    cout<<"Empty or not->"<<a.empty()<<endl;

    //Access the first element of the array using .front()
    cout<<"Front Element->"<<a.front()<<endl;

    //Access the last element of the array using .back()
    cout<<"Last Element->"<<a.back()<<endl;

    return 0; //End of program
}