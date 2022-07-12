#include "iostream"
#include "vector"
void Merge(std::vector<int>& B,std::vector<int>& C,std::vector<int>& A);
void MergeSort(std::vector<int>& A){
    if (A.size()==1){ return; }
    std::vector<int> B(A.size()/2);
    std::vector<int> C(A.size() -(A.size()/2));
    std::copy(A.begin(), A.begin()+(A.size()/2)+1,B.begin());
    std::copy((A.begin() + A.size()/2),A.end(),C.begin());
    MergeSort(B);
    MergeSort(C);
    Merge(B,C,A);

}
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
};

int main(){
    std::vector<int> L = {1,10,4,2,7,11,3,9,1,0};

    MergeSort(L);
    for(auto i = L.begin(); i !=L.end(); ++i){
        std::cout<<" "<< *i <<" ";
    }
    return 0;
}
