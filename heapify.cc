/* max heap initialise obj with true.
min heap initialse obj with false 
left = 2*i+1
right = 2*i+2
parent = (i-1)/2 */


#include<bits/stdc++.h>
using namespace std;

class heap
{
    private:
        vector<int> heap_arr;
        bool max_;
        int heap_size_;
    public:
        heap(bool max)
        {
            max_ = max;
            heap_size_=0;
        }
        void insert_heap(int x)
        {
            heap_arr.push_back(x);
            heap_size_ ++;

        }

        void delete_element(int x);
        void print_heap();

        void max_heapify(int i);
        void min_heapify(int i);
        void min_bottom_heapify(int i);
        void max_bottom_heapify(int i);
        void insert_element(int ele);

        void build_heap();
        int left(int i) {
            return 2*i+1;
        }
        int right(int i) {
            return 2*i+2;
        }
        int parent(int i)
        {
            return (i-1)/2;
        }
};

void heap::delete_element(int i)
{
    for(auto it= heap_arr.begin(); it != heap_arr.end(); ++it)
    {
        if(*it == i) {
            swap(heap_arr[it-heap_arr.begin()], heap_arr[heap_size_-1]);
            heap_arr.pop_back();
            heap_size_--;
            
            max_? max_heapify(it-heap_arr.begin()) : 
                min_heapify(it-heap_arr.begin());

            
            break;
        }
    }
}

void heap::min_bottom_heapify(int i)
{
    int p= parent(i);
    int smallest;
    if(i > 0 && heap_arr[p] > heap_arr[i]) {
        swap(heap_arr[p], heap_arr[i]);
        min_bottom_heapify(p);
    }
}

void heap::max_bottom_heapify(int i)
{
    int p= parent(i);
    int largest;
    if(i > 0 && heap_arr[p] < heap_arr[i]) {
        swap(heap_arr[p], heap_arr[i]);
        max_bottom_heapify(p);
    }
}

void heap::insert_element(int ele)
{
    heap_arr.push_back(ele);
    heap_size_++;
    max_ ? max_bottom_heapify(heap_size_-1):min_bottom_heapify(heap_size_-1);
}

void heap::max_heapify(int i)
{
    int largest=i;
    int l = left(i);
    int r = right(i);
    if(l< heap_size_ && heap_arr[l] > heap_arr[i])
        largest = l;
    if(r < heap_size_ && heap_arr[r] > heap_arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(heap_arr[largest], heap_arr[i]);
        max_heapify(largest);
    }
}

void heap::min_heapify(int i)
{
    int smallest=i;
    int l = left(i);
    int r = right(i);
    if(l< heap_size_ && heap_arr[l] < heap_arr[i])
        smallest = l;
    if(r < heap_size_ && heap_arr[r] < smallest)
        smallest = r;
    if(smallest != i)
    {
        swap(heap_arr[smallest], heap_arr[i]);
        min_heapify(smallest);
    }
}

void heap::build_heap()
{
    int num=(heap_size_)/2-1;
    while(num>=0)
    {
        max_ ? max_heapify(num) : min_heapify(num);
        --num;
    }
}

void heap::print_heap()
{
    for(auto it = heap_arr.begin(); it!= heap_arr.end(); ++it)
        cout<<*it<<" "<<endl;
}

int main()
{
    int n,i, temp;
    cin>>n;
    heap hp(false);
    for(i=0; i<n; ++i) {
        cin>>temp;
        hp.insert_heap(temp);
    }
    hp.build_heap();
    hp.print_heap();
    cout<<"enter element to insert"<<endl;
    cin>>temp;
    hp.insert_element(temp);
    hp.print_heap();

}