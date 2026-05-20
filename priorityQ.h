#include <unordered_map>
#include <cstdlib>
#include <string>
#include "lander.h"

#ifndef PRIORITY_Q
#define PRIORITY_Q

template <class t1, class t2>
class priorityQ
{
public:
    priorityQ();

    ~priorityQ() { delete [] heapArray; }

    void push_back(const t1&, const t2&);
    void pop_front();
    void update_element(const t1&, const t2&);

    t2 get_element(t1);
    t2 get_front_priority() const;
    t1 get_front_key() const;
    bool isEmpty() const;
private:
	class priorityType
  {
  public:
    t1 key;
    t2 priority;

    priorityType() : key(t1()), priority(t2()) {}
    priorityType(t1 k, t2 v) : key(k), priority(v) {}
  };

  void bubbleUp(std::size_t);
  void bubbleDown(std::size_t);

  priorityType * heapArray;
  std::size_t size;
  std::size_t capacity;
  std::unordered_map<t1, std::size_t> itemToPQ;
};

#endif


/*
///Notes and pseudo code for priorityQ.cpp////

template <classt1, class t2>
class priorityType
{
  public:
    t1 key;
    t2 priority;

};

size_t heapSize;
size_t capacity;

size_t bubbleUp(size_t);
size_t bubbleDown(size_t);


unordered_map<t1, size_t> keyToIndex;
public:
  priorityQ()
  {
    heapSize = 0;
    capacity = 10;
    heapArray = new priority TYpe[capacity + 1];

    void push_back(t1 k, t2 p){
    
    heapArray[heapSize + 1].key = k;
    heapArray[heapSize + 1].priority = p;

    heapSize++;

    bubbleUp(heapSize);

    }
  
  }


POP_FRONT


template <classt1, class t2>
class priorityQ
{
;;
public:

void pop_front();

heapArray[1] = heapArray[heapSize];
heapSize--;
bubbleDown(1);
}
}
}




Notes from the video:


ket will be a string and the priority will be a lander type class.


capacity will tell us how big the array is. 

remember our unorderd map:

my notes for these:
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //maps a string to an integer

    //insert/find takes O(1)
    unordered_map<string, int> people;

    people.insert( {"Leon", 13} );
    people.insert( {"Jill", 22} );
    people.insert( {"Claire", 15} );

    cout << people["Jill"] << endl;

    people["Jill"] = 19;

    cout << people["Jill"] << endl;

    people["Chris"] = 27;

    cout << people["Chris"] << endl;

    unordered_map<string, int>::iterator i = people.find("Jill");

    if (i != people.end())
    {
        cout << "Found" << endl;
        cout << i->first << " " << i->second << endl;
    }

    i = people.find("Grace");

    if (i == people.end())
    {
        cout << "Not found" << endl;
    }

    for (auto it = people.begin(); it != people.end(); it++)
    {
        cout << it->first << ":";
        cout << it->second << endl;
    }

    cout << endl;

    for (auto it : people)
    {
        cout << it.first << ":";
        cout << it.second << endl;
    }

    cout << "Done" << endl;

    return 0;
}


bak to video notes:
the heap array can be set to capacity +1 for when it s maxed out
for resize 
size will tell us how many elements were used up.
index 1 is going to be the root position and then the capacity will tell us 
how big the array is and we have to to a resize and a push back. 
PQ map is used for the update functions. 


Bubble Up - THis keeps on computing the passed in index into the function
when you call your push back functiion you will pass in the last inserted item and 
bubble up. You cam parent index to child or child to parent until you hit the root. 

Bubble down is similar concept to Bubble Up


  std::unordered_map<t1, std::size_t> itemToPQ;
  so this will be a string to an int.  

  so basically we can look up items and directly find the value. 

  we use bubble up and bubble down

  so to find a parent index is the value/ 2 
   new index and the map must be consistent with this change. 
   
   swap heap array and must swap their indices in our map as well. 


   we test our lander class and also our prioriyQ using the 
   LanderTest.cpp and priorityQTest.cpp as well. 



   INT MAIN notes:

  read in the file and he said we can just hard code into main. I guess. 
  LanderInput.txt pass it into a file string open function. 
  we need to implement our less than operator for our priority queue/ our lander class.
  
  we will be using our less than operator for our priority type.

  its going o print out the top three in our leader board. 
  first call the get pririty, get front key or front priority get front function. 
  then pop it from the priority queue. 
  then push the three in our leader board back into the priority queue so we can still have access
  to them. 
  we will propmt the user for lander namr anf throttle amount, 

  user types in a name and then we will use the update element 
  and then get element. we need to find the element first. 
  
  then we have to call the simulate function on that lander. 

  so everytime we ouput the top three and then prompt the user for 
  input. 

*/

