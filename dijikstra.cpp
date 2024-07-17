#include<iostream>
#include<limits.h>
using namespace std;
#define V 9
class dj{
    public:
    int distance[V];
    bool shortestpath[V];
    
    int mindist(int distance[], bool shortestpath[]){
        int min=INT_MAX;
        int minindex;
        for(int v=0; v<V; v++){
            if(shortestpath[v]==false&& distance[v]<=min){
                min=distance[v];
                minindex=v;
            }
        }
        return minindex;
    }
    
    void findspt(int graph[V][V], int source){
        for(int i=0; i<V; i++){
            distance[i]=INT_MAX;
            shortestpath[i]=false;
        }
        distance[source]=0;
        for(int count=0; count<V-1; count++){
            int u=mindist(distance, shortestpath);
            shortestpath[u]=true;
            for(int v=0; v<V; v++){
                if(shortestpath[v]==false && (graph[u][v]+distance[u]<distance[v])&& graph[u][v]>0 && distance[u]!=INT_MAX){
                    distance[v]=distance[u]+graph[u][v];
                }
            }
        }
        print(distance);
    }
    
    void print(int distance[]){
        for(int i=0; i<V ; i++){
            cout<<i<<" "<<distance[i]<<endl;
        }
    }
};
int main(){
     dj spt; 
 int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
 { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
 { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
 { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
 { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
 { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
 { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
 { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
 { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
 
 spt.findspt(graph, 0); 
}