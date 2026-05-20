/*
 * Name: Silvia Williams
 * Description: This program implements a priority queue
 * using a heap. It supports push back, pop front, update element,
 * get front priority, get front key, get element, and is empty functions.
 * Input: Lander data from main.cpp
 * Output: Lander values returned to main.cpp
 *
 */

#include "priorityQ.h"

///////// PRIORITY QUEUE CONSTRUCTOR FUNCTION /////////
/*
initializes priority queue
sets initial capacity adn size
allocates heap array with extra space for index 1 root
*/
template <class t1, class t2>
priorityQ<t1, t2>::priorityQ()
{
    capacity = 5;
    size = 0;
    heapArray = new priorityType[capacity + 1];
}

///////// PRIORITY QUEUE PUSH BACK FUNCTION /////////
/*
inserts a new element into the priority queue/heap
*/
template <class t1, class t2>
void priorityQ<t1, t2>::push_back(const t1 &key, const t2 &priority)
{
    // resizes the heap array if size is at capacity
    if (size == capacity)
    {
        capacity = capacity * 2;
        priorityType *temp = new priorityType[capacity + 1];

        // copy old array into new array
        size_t i = 1;
        while (i <= size)
        {
            temp[i] = heapArray[i];
            i++;
        }
        // deletes old array
        // and sets heap array to new array
        delete[] heapArray;
        heapArray = temp;
    }
    size++; // move to the next open spot

    // inserts the new element
    // and updates the map with the new key and index
    // then calls bubble up for the new element
    heapArray[size].key = key;
    heapArray[size].priority = priority;
    itemToPQ[key] = size;
    bubbleUp(size);
}
///////// PRIORITY QUEUE POP FRONT FUNCTION /////////
/*
removes the highest priority element(the root) from the priority queue/heap
*/
template <class t1, class t2>
void priorityQ<t1, t2>::pop_front()
{
    // if the heap is empty, there is nothing to pop
    if (size == 0)
    {
        return;
    }
    // removes root key from map (unordered_map erase function)
    //  fromm https://www.geeksforgeeks.org/cpp/unordered_map-in-cpp-stl/
    itemToPQ.erase(heapArray[1].key);

    // removes a single element from the heap
    if (size == 1)
    {
        size--;
        return;
    }
    // move last element to root and updates map
    heapArray[1] = heapArray[size];
    itemToPQ[heapArray[1].key] = 1;
    // decrease size, then calls bubble down for new root element
    size--;
    bubbleDown(1);
}

///////// PRIORITY QUEUE UPDATE ELEMENT FUNCTION /////////
/*
updates the priority of an existing element in the heap
*/
template <class t1, class t2>
void priorityQ<t1, t2>::update_element(const t1 &key, const t2 &priority)
{
    // finds index of element using map
    size_t index = itemToPQ[key];

    // stores old priority for comparison
    t2 oldPriority = heapArray[index].priority;

    // updates to new priority
    heapArray[index].priority = priority;

    // fix heap depending on change in priority
    if (priority < oldPriority)
    {
        bubbleUp(index);
    }
    else
    {
        bubbleDown(index);
    }
}

///////// PRIORITY QUEUE GET FRONT PRIORITY FUNCTION /////////
template <class t1, class t2>
t2 priorityQ<t1, t2>::get_front_priority() const
{
    return heapArray[1].priority;
}

///////// PRIORITY QUEUE GET FRONT KEY FUNCTION /////////
template <class t1, class t2>
t1 priorityQ<t1, t2>::get_front_key() const
{
    return heapArray[1].key;
}

///////// PRIORITY QUEUE GET ELEMENT FUNCTION /////////
template <class t1, class t2>
t2 priorityQ<t1, t2>::get_element(t1 key)
{ // finds index of element using map
    // and returns the priority of that element
    size_t index = itemToPQ[key];
    return heapArray[index].priority;
}

///////// PRIORITY QUEUE IS EMPTY FUNCTION /////////
template <class t1, class t2>
bool priorityQ<t1, t2>::isEmpty() const
{
    return size == 0;
}

///////// PRIORITY QUEUE BUBBLE UP FUNCTION /////////
/*
moves an element up the heap to maintain order
padres = parent index
*/
template <class t1, class t2>
void priorityQ<t1, t2>::bubbleUp(std::size_t index)
{
    // while the element is not at the root
    while (index > 1)
    {
        // finds parent index
        size_t padres = index / 2;

        // if the element has higher priority than its parent, swap them
        if (heapArray[index].priority < heapArray[padres].priority)
        {
            // swaps the element with its parent
            priorityType temp = heapArray[index];
            heapArray[index] = heapArray[padres];
            heapArray[padres] = temp;

            // update map after swap
            t1 updateIndex = heapArray[index].key;
            t1 UpdateKey = heapArray[padres].key;
            itemToPQ[updateIndex] = index;
            itemToPQ[UpdateKey] = padres;

            // move up to the parent index and repeat
            index = padres;
        }
        else
        {
            break;
        }
    }
}

///////// PRIORITY QUEUE BUBBLE DOWN FUNCTION /////////
/*
moves an element down the heap to maintain order
hijos = child index
*/
template <class t1, class t2>
void priorityQ<t1, t2>::bubbleDown(std::size_t index)
{
    // se
    size_t hijos;

    // while current element has at least one child
    while (index * 2 <= size)
    {
        // starts with left child index
        hijos = index * 2;

        // if right child exists and has higher priority, use it instead of left child
        if (hijos != size && heapArray[hijos + 1].priority < heapArray[hijos].priority)
        {
            hijos++;
        }

        // if the child has higher priority than the current element, swap them
        if (heapArray[hijos].priority < heapArray[index].priority)
        {
            // swap elements
            priorityType temp = heapArray[index];
            heapArray[index] = heapArray[hijos];
            heapArray[hijos] = temp;

            // update map after swap
            t1 updateIndex = heapArray[index].key;
            t1 UpdateKey = heapArray[hijos].key;

            itemToPQ[updateIndex] = index;
            itemToPQ[UpdateKey] = hijos;

            index = hijos;
        }
        else
        {
            break;
        }
    }
}
template class priorityQ<std::string, int>;
template class priorityQ<std::string, lander>;
