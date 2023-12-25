#include<iostream>
using namespace std;
int main(){
    int res = 0;
    for(int i = 1; i <= 33; ++i){
        cout <<i<<" "<< (100 - i)/2 << " " << 100 - i - (100 - i)/2<< endl;
        for(int j = i+1; j <= (100 - i)/2; ++j){
            if(j == 100 - j -i)continue;
            res++;
        }
    }
    cout<<"取3个数和为100的数目" << res;
}