#include <bits/stdc++.h>

using namespace std;

bool knows(int a, int b)
{
    return true;
}

//自己寫不出來
int findCelebrity(int n)
{
    //候選人預設為0
    int res = 0;
    //一個一個開始問
    //如果res認識i，表示res一定不是候選人
    //如果res不認識i，表示i一定不是候選人
    //所以如果res認識i，那就把候選人設為i
    for(int i = 0; i < n; ++i)
        if(knows(res, i)) res = i;

    //檢查看看484根本沒有候選人
    for(int i = 0; i < n; ++i)
        if(res != i && (knows(res, i) || !knows(i, res)))
            return -1;
    return res;
}