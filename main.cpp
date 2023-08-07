//
//  main.cpp
//  heap
//
//  Created by Martin Astion on 20/8/21.
//

//#include <iostream>
//#include <queue>
//using namespace std;
//struct node
//{
//    int sum, bid, aid;
//    bool operator<(const node& o) const
//    {
//        return sum > o.sum;
//    }
//};
//priority_queue<node> que;
//int n;
//int a[100010], b[100010];
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//
//    for (int i = 1; i <= n; i++)
//        cin >> b[i];
//    node tmp;
//    for (int i = 1; i <= n; i++) {
//        tmp.sum = a[i] + b[1];
//        tmp.aid = i;
//        tmp.bid = 1;
//        que.push(tmp);
//    }
//    for (int i = 1; i <= n; i++) {
//        tmp = que.top();
//        que.pop();
//        cout << tmp.sum << " ";
//        if (tmp.bid < n) {
//            tmp.bid++;
//            tmp.sum = a[tmp.aid] + b[tmp.bid];
//            que.push(tmp);
//        }
//    }
//    return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;

int heap[200]; // heap array
int len;    // heap length
int n = 7;
int cows[7] = {3,5,1,7,6,4,2};
// method swap
void insert(int x)
{
    len++;  // heap length += 1
    heap[len] = x;   // insert new element into the tail
    int father, son; // pointer
    son = len;
    father = son/2;
    while(son > 1)
    {
        if(heap[son] >= heap[father])
        {
            break;
        }
        swap(heap[son], heap[father]);
        son = father;//get the new father
        father = son/2; // new father's father
    }
}

// find the appropriate place then replace

// method sink
// faster than swap
void insert_sink(int x)
{
    int father, son;
    len++;// add one position
    son = len;
    father = son/2;
    while(son > 1)// go to the root
    {
        if(x >= heap[father])
        {
            break;
        }
        heap[son] = heap[father];
        son = father;
        father = son/2;
    }
    heap[son] = x;
}

// find the pivot
// the most efficiency
void insert_pivot(int x)
{
    int father, son;
    heap[0] = -10000;
    len++;
    son = len;
    father = son/2;
    while(x < heap[father])
    {
        heap[son] = heap[father];
        son = father;
        father = son/2;
    }
    heap[son] = x;
}


// delete sink
// the last element moves to the root, then use this new root
// to compare with the rest of element and put it into an appropriate position

// method1, swap

int delete_min()
{
    int father, son;
    int root = heap[1]; // save the root element
    heap[1] = heap[len];// last element moves to the root
    len--;
    father = 1;
    son = father * 2;
    while (son <= len)
    {
        if(son < len and heap[son + 1] < heap[son])
        {
            // check whether children are smaller, left or right
            son++;
        }
        if(heap[father] <= heap[son])
        {
            break;
        }
        swap(heap[father], heap[son]);
        father = son; // update the father and sonn
        son = father * 2;
    }
    return root;
}

// method raise
int delete_min_raise()
{
    int father, son;
    int root = heap[1];
    int tail = heap[len];
    len--;
    father = 1;
    son = father * 2;
    while(son <= len)
    {
        if(son <= len and heap[son + 1] < heap[son])
        {
            son++;
        }
        if(tail <= heap[son])
        {
            break;
        }
        heap[father] = heap[son];
        father = son;
        son = father * 2;
    }
    heap[father] = tail;
    return root;
}


int main()
{
    for(int i = 0; i < n; i++)
    {
        insert_pivot(cows[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }
    for(int i = 0; i < n; i++)
    {
        cout << delete_min() << " ";
    }
}




