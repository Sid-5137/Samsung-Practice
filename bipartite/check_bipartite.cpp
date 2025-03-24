#include <iostream>
using namespace std;

int n;
int arr[100][100]={0};

bool isbipartite(int i, int* color){
    bool flag = true;
    for(int j = 0; j < n; j++){
        if(arr[i][j] == 1){
            if(color[j] == -1){
                color[j] = 1 - color[i];
                flag = flag & isbipartite(j, color);
            }
            else if(color[j] == color[i]){
                return false;
            }
        }
    }
    return flag;
}

int main(){
    cout<<"Enter the number nodes in graph: ";
    cin>>n; cout<<endl;

    int* color = new int[n];
    for(int i = 0;i < n;i++){
        color[i] = -1;
        for(int j = 0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!isbipartite(i, color)){
                cout<<"Given graph is not Bipartite!!!";
                delete[] color;
                return 0;
            }
        }
    }

    cout<<"Given graph is Bipartite!!!";
    return 0;
}