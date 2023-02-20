#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;

class Heap{
    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapup(int index);
        void heapdown(int index);
    public:
        Heap()
        {}
        void Insert(int element);
        void DeleteMin();
        int ExtractMin();
        void Display();
        int Size();
};
int Heap::Size(){
    return heap.size();
}
void Heap::Insert(int element)
{
    heap.push_back(element);
    heapup(heap.size() -1);
}
void Heap::DeleteMin()
{
    if (heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapdown(0);
    cout<<"Element Deleted"<<endl;
}
int Heap::ExtractMin()
{
    if (heap.size() == 0)
    {
        return -1;
    }
    else
        return heap.front();
}
void Heap::Display()
{
    vector <int>::iterator pos = heap.begin();
    while (pos != heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}
int Heap::left(int parent)
{
    int l = 2 * parent + 1;
    if(l < heap.size())
        return l;
    else
        return -1;
}
int Heap::right(int parent)
{
    int r = 2 * parent + 2;
    if(r < heap.size())
        return r;
    else
        return -1;
}
int Heap::parent(int child)
{
    int p = (child - 1)/2;
    if(child == 0)
        return -1;
    else
        return p;
}
void Heap::heapup(int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapup(parent(in));
    }
}
void Heap::heapdown(int in)
{

    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
       child = child1;
    }
    if (child > 0)
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        heapdown(child);
    }
}

int main()
{
    Heap h;
    while (1)
    {
        cout<<"----------------"<<endl;
        cout<<"Heap Operations:"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Extract Minimum Element"<<endl;
        cout<<"3.Delete Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.Insert(element);
            break;
        case 2:
            if (h.ExtractMin() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.ExtractMin()<<endl;
            break;
        case 3:
            h.DeleteMin();
            break;
        case 4:
            cout<<"Elements of Heap:  ";
            h.Display();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    return 0;
}