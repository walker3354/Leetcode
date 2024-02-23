#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end());
            int n = citations.size();
            int h = 0;
            for (int i = 0; i < n; ++i) {
                int citation_count = citations[i];
                int papers_count = n - i;
                h = max(h, min(citation_count, papers_count));
            }
            return h;
        }
};

/*
Given an array of integers citations where citations[i] is the number of
citations a researcher received for their ith paper, return the researcher's
h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as
the maximum value of h such that the given researcher has published at least h
papers that have each been cited at least h times.


H指數（H-index）是用來衡量一位學者學術成就的指標，它結合了作者的發表文章數量和這些文章的被引用次數。計算H指數的方法如下：

首先，將作者的所有文章按照引用次數由高到低排序。
接著，從最高引用次數的文章開始往下數，直到數字超過或等於該文章的引用次數為止。這個數字即為H指數。
舉例來說，如果一位作者的10篇文章分別被引用了30、25、20、15、10、8、5、3、2、1次，那麼他的H指數為5，因為他有5篇文章被引用了至少5次。

在計算H指數時，要注意以下幾點：

H指數並不考慮文章被引用的總數量，而是考慮到有多少篇文章被引用了至少相應次數。
如果有多位作者的文章被合著在一起發表，則每位作者都可以得到相同的H指數。
H指數的值越高，表示一位學者的影響力越大。

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of
them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has
3 papers with at least 3 citations each and the remaining two with no more than
3 citations each, their h-index is 3. Example 2:

Input: citations = [1,3,1]
Output: 1
*/