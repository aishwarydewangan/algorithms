class LRUCache {
public:
    LRUCache(int capacity) {
        myCap = capacity;
    }
    
    int get(int key) {
        if(myMap.find(key) == myMap.end())
            return -1;
        auto it = myMap[key];
        const int val = it->second; 
        myList.erase(it);
        myList.insert(myList.begin(), make_pair(key, val));
        myMap[key] = myList.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(myMap.find(key) != myMap.end()){
            myList.erase(myMap[key]);
            myMap.erase(key); 
        }
        
        if(myMap.size() >= myCap){
            int keyToBeRemoved = myList.rbegin()->first; 
            myList.pop_back();
            myMap.erase(keyToBeRemoved); 
        }
        myMap[key] = myList.insert(myList.begin(), make_pair(key, value)); 
    }

private:
    list<pair<int, int> > myList; 
    unordered_map<int, list<pair<int, int> >::iterator > myMap; 
    int myCap; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 *//* ipsc13 HVWzqSVX mpicc -o hello hello.c



#include <mpi.h>
#include <stdio.h>

int main()
{
    int num,recvbuf,size,myrank;
    num = 10;

    MPI_Init(0,0);
    MPI_Comm_size(MPI_COMM_WORLD,$size);
    MPI_Comm_rank(MPI_COMM_WORLD,$myrank);

    if(myrank==0)
        MPI_Send(&num,1,MPI_INT,1,123,MPI_COMM_WORLD);
    else
        MPI_Recv(&recvbuf,1,MPI_INT,0,123,MPI_COMM_WORLD,&status);

    if(myrank == 1)
        print()

    MPI_Finalise();
}

