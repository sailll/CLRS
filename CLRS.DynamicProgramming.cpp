#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class Cutrod{
private:
    vector<int> prices;
    int length;
public:
    int findmax(int n){
        int ans=0;
        for(int i=1;i<n/2+1;++i){
            ans=max(findmax(n-i)+findmax(i),ans);
        }
        ans=max(prices[n-1],ans);
        return ans;
    }
    void input(){
        printf("please enter the length\n");
        scanf("%d",&length);
        for(int i=0;i<length;++i){
            int cval;
            scanf("%d",&cval);
            prices.push_back(cval);
        }
    }
    int _getlength(){
        return this->length;
    }
};
int main(){
    Cutrod instance;
    instance.input();
    int n;
    scanf("%d",&n);
    printf("%d",instance.findmax(n));
    return 0;
}