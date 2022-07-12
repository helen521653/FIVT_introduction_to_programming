#include <iostream>
#include <vector>


int main() {
    int N = 0;
    std::cin>>N;
    std::vector<std::pair<int,int>> k (N);
    for(auto i = 0; i<N; ++i){std::cin>>k[i].first >>k[i].second;}
    int M = INT_MIN;
    for(int g = 0; g<k.size();++g){
        if(k[g].second>M){M = k[g].second;}
    }
    std::vector<int> o (M+1);
    for(int i = 0; i<k.size();++i){
        for(int j = k[i].first;j<k[i].second;++j){++(o[j]);}
    }
    int otv = 0;
    std::cout<<std::endl;
    for(int l  = 0; l< o.size();++l){
        std::cout<<o[l]<<" ";
        if(o[l]==1){++otv;}
    }
    std::cout<<" otv " << otv << std::endl;


    return 0;
}
