#include "iostream"
#include "queue"
#include "vector"

void Merge(std::vector<int>& B,std::vector<int>& C,std::vector<int>& A){
    auto i = 0;
    auto j = 0;
    auto p = 0;
    while (i < B.size() && j < C.size()){
        if(B[i] < C[j]){A[p++] = B[i++];}
        else{A[p++] = C[j++];}
    }
    while (i < B.size()){A[p++] = B[i++];}
    while (j < C.size()){A[p++] = C[j++];}
}

void UMergeSort(std::vector<int>& A,unsigned long long r){
    std::queue<std::vector<int>> q;
    for(int i = 0; i < r; ++i){
        q.push({A[i]});
    }
    while (q.size() > 1){
        std::vector<int> a = q.front(); q.pop();
        std::vector<int> b = q.front(); q.pop();
        std::vector<int> c(a.size()+b.size());
        Merge(a,b,c);
        q.push(c);
    }
    A = q.front();
}

int main(){
    std::vector<int> A = {1,5,2,7,4};
    UMergeSort(A,A.size());
    for(auto i = 0; i < A.size(); ++i){
        std::cout<<" "<<A[i]<< " ";
    }
}