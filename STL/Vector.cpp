//Vector is a Dynamic Array. It stores the data in a contiguous memory location just lke an array. Once the vector gets filled, on adding an additional element, it doubles its size. How is this possible,suppose, we create a vector of size 4. Now we add four elements to the vector. If we want to add a fifth element, the vector creates another vector of double its size and copies the element of the old vector to the new vector and after coping, it dumps the old vector.

#include<iostream>
#include<vector> // Include the vector library to use vectors in the program

using namespace std;

int main()
{
    //Declare an empty vector of integers
    vector<int> v;

    //Declare a vector 'a' with 5 elements, each initialized to 1
    vector<int> a(5,1);

    //Declare a vector 'b' and copy all elements from vector 'a'
    vector<int> b(a);

    //Print the elements of vector 'b'
    cout<<"Print b:"<<" ";
    for (int i:b) //Ranged-based for loop to iterate over all elements in vector 'b'
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    //Display the capacity of vector 'v'
    //Capacity: The number of elements the vector can store without resizing    
    cout<<"Capacity ->"<<v.capacity()<<endl;

    //Add elements to vector 'v' using push_back()
    v.push_back(1); //Add 1 to the vector 
    cout<<"Capacity ->"<<v.capacity()<<endl; //Check the updated capacity

    v.push_back(2); //Add 2 to the vector
    cout<<"Capacity ->"<<v.capacity()<<endl; //Check the updated capacity

    v.push_back(3); //Add 3 to the vector
    cout<<"Capacity ->"<<v.capacity()<<endl; //Check the updated capacity

    //Print the current sizeof the vector
    //Size: The number of elemts currently stored in the vector
    cout<<"Size->"<<v.size()<<endl;
   
    v.push_back(4); //Add 4 to the vector
    cout<<"Capacity ->"<<v.capacity()<<endl; //Check the updated capacity

    v.emplace_back(5); //Add 5 to the vector
    cout<<"Capacity ->"<<v.capacity()<<endl; //Check the updated capacity

    //Access and print the element at the 2nd index using .at() (with bounds checking)
    cout<<"Element at 2nd Index->"<<v.at(2)<<endl;

    //Access the first element of the array using .front()
    cout<<"Front Element->"<<v.front()<<endl;

    //Access the last element of the array using .back()
    cout<<"Last Element->"<<v.back()<<endl;

    //Remove the last element from the vector using pop_back()
    v.pop_back();

    //Print the vector after removing the last element
    cout<<"After pop"<<endl;
    for (int i:v) //Range-based for loop to iterate over elements in vector 'v'
    {
        cout<<i<<" "; //Print each element
    }
    cout<<endl;

    //Print the size of the vector before clearing its elements
    cout<<"Before Clear size"<<v.size()<<endl;

    //Clear all elements from the vector
    v.clear();

    //Print the size of the vector after clearing its elements 
    cout<<"After Clear size"<<v.size()<<endl;

    return 0; //End of Program
}