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
        int ans[100]={0};
        for(int i=1;i<=length;++i){
            ans[i]=prices[i-1];
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=i;++j){
            ans[i]=max(ans[i-j]+ans[j],ans[i]);
            }
        }
        return ans[n];
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