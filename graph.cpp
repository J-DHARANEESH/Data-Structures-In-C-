#include<iostream> 
using namespace std;
void adjmat(int adj[][5],int l,int m){
    adj[l][m]=1;
    adj[m][l]=1;
}
void dspl(int adj[][5],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j];
        }cout<<"\n";
    }
}

void DFS(int adj[][5],int visited[],int i,int n) 
{ 
    int j; 
    cout <<i;
    visited[i]=1; 
    for(j=0;j<n;j++) 
        if(!visited[j]&&adj[i][j]==1) 
            DFS(adj,visited,j,n); 
} 

int main(){
    int c,l,m,v;
    int n=5;
    int adj[5][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    int b=1;
    while(b=1){
     cout <<"\n------------------------------\n";
        cout << "1.Adjacency matrix\n";
        cout << "2.DFS\n";
        cout << "3.print adj matrix\n";
        cout << "4.Quit\n";
        cout <<"------------------------------\n";
        cout << "Enter your choice : \n";
        cin >> c;
        switch (c){
            case 1:
            cout<<"Enter the connected nodes in graph: \n";
            cin>>l;
            cin>>m;
            adjmat(adj,l,m);
            break;
            case 2:
            cout <<"Enter the starting node value:";
            cin >>v;
            int visited[10];
            for(int i=0;i<n;i++){
               visited[i]=0;}
            DFS(adj,visited,v,n);
            break;
            case 3:
            dspl(adj,n);
            break;
            case 4:
            cout <<"Thank you";
            break;
            default:
            cout <<"Wrong choice !";
        }
}}