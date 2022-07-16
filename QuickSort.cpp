#include "iostream"
#include "vector"
#include "algorithm"
#include <cstdlib>
#include <ctime>
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

std::pair<unsigned int, unsigned int> Partition(std::vector<int>& A,  const int x,unsigned int random, unsigned int n, unsigned int k){
    std::vector<int>::iterator ra = A.begin() + random;


    if(random != k){
        swap(*(A.begin()+k) , *ra);
    }

    random = k;
    ra = A.begin()+k;


    std::vector<int>::iterator i = A.begin() + n -1;
    for(auto j = A.begin() + n ;j != (A.begin() + k); ++j ){
        if(*j< x){
            ++i;
            swap(*i,*j);
        }
    }


    ++i;
    swap(*i, *ra);
    unsigned int q1 =  i - A.begin();


    for(auto l = i;l!= (A.begin() + k)+1;++l){
        if((*l == x) && ((l - A.begin())!=q1) ){
            ++i;
            swap(*l,*i);
        }
    }
    unsigned int q2 =  i - A.begin();
    std::pair<unsigned int, unsigned int> pa = {q1,q2};
    std::cout<<" Partition work start in n,k = "<<n<<" "<<k <<std::endl;
    for(auto h = n;h<=k;++h)std::cout<<A[h]<<" ";
    std::cout<<" x = "<<x<<" q = "<<pa.first<<" "<<pa.second<<" Partition work end "<<std::endl;
    return pa;
}

void QuickSort(std::vector<int>& A, unsigned int n, unsigned int k){


    if(n < k) {
        std::cout<<"QuiqSort started in n,k = "<<n<<", "<<k<<std::endl;
        for(auto h = n;h<=k;++h)std::cout<<A[h]<<" ";
        std::cout<<" A now "<<std::endl;

        unsigned int random = k+1;
        while(random > k)
            random = 1+n + std::rand()/((RAND_MAX + 1u)/k);  // Note: 1+rand()%6 is biased

        int x = A[random];
        std::cout<<"random = "<<random<<" x = "<<x<<std::endl;

        std::pair<unsigned int, unsigned int> q = Partition(A, x, random, n, k);
        QuickSort(A, n, q.first);

        QuickSort(A, q.second+1, k);
    }
}

int main(){
    std::vector<int> E = {1,5,1,8,7,7,7,1,7,9,9,9};
    QuickSort(E,0, E.size()-1);

    for(auto i = 0; i < E.size(); ++i){
        std::cout<<" "<<E[i]<< " ";
    }
}