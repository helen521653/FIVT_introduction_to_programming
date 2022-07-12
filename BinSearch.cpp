#include <iostream>

void BinSearch(const int* A, int length, int x){
    int l = 0;
    int r = length;
    while ((r - l) > 1){
        int m = (l+r)/2;
        if(A[m] < x){l = m;}
        else{r = m;}
    }
    if(A[l]==x || A[r] == x){std::cout<<"YES";}
    else{std::cout<<"NO";}
}


int main(){
    int n = 5;
    int a[n] = {1,4,6,7,8};
    BinSearch(a,n,8);
}