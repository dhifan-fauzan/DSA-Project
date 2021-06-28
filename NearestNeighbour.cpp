#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <time.h>
#define S 100
using namespace std;
using namespace std::chrono;


bool checkarray( vector<int> v,int x){
    if(std::find(v.begin(), v.end(), x) != v.end()) {
     return false;// check if val is within the vector
}else {
   return true;
}
}

void NearestNeighnour(int graph[S][S],int siz,int s, vector<int> alreadywent,int minimum){
    int temp[][2]={1000000,0};
    for(int j = 0; j < siz; j++){
        if(graph[s][j]!=0){
            if(graph[s][j] < temp[0][0] && checkarray(alreadywent,j)){
            temp[0][0]=graph[s][j];
            temp[0][1]=j;
            }
        }
    }
    cout<< alreadywent.size()+1<<" Iteration: From: "<<s+1<<" to "<<temp[0][1]+1<<" distance of "<<temp[0][0]<<"\n";
    alreadywent.push_back(s);
    minimum+=temp[0][0];

    if(alreadywent.size()<siz-1){
    NearestNeighnour(graph,siz,temp[0][1],alreadywent,minimum);
    }
    else{
        cout<< endl<<"Minimum distance need to be covered: "<<minimum<<endl;
    }
}


int main()
{
    int graph[S][S];
    int random;
    srand (time(NULL));
    for(int y=0;y<S;y++){
        for(int x=0;x<S;x++){
            if(y==x){
                graph[y][x]=0;
            }else if(x>y){
                graph[y][x] = (rand() % 100 + 1)| rand();// generate a random number
            }else {
                 graph[y][x]= graph[x][y];
            }
        }
    }

    vector<int> alreadywent;
    auto start = high_resolution_clock::now();// Used to get the run time before the program starts
    NearestNeighnour(graph,S,0,alreadywent,0);
    auto stop = high_resolution_clock::now();// Used to get the run time after the program finsihed
    auto duration = duration_cast<milliseconds>(stop - start);// get the difference between the stop and start and cast as milliseconds
    auto duration2 = duration_cast<microseconds>(stop - start);// get the difference between the stop and start and cast as microseconds
    auto duration3 = duration_cast<nanoseconds>(stop - start);// get the difference between the stop and start and cast as nanoseconds

    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl
         << duration2.count() << " microseconds" << endl
         << duration3.count() << " nanoseconds" << endl;
}
