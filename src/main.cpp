/*************************************************************************
	> File Name: delNode.cpp
	> Author: zengtong
	> Mail: unixsudo@outlook.com
	> Created Time: 四  4/12 10:42:34 2018
 ************************************************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    vector<int> ids(1001, -1);
    vector<int> res;
    int count = 0;
    int n;
    cin >> n;
    while(n--) {
        int id;
        cin >> id;
        if (ids[id] == -1 && count < 10) {
            ids[id] = 1;
            ++count;
            res.push_back(ids[id]);
        }
    }
    for (auto i: res) {
        cout  << i << endl;
    }
    return 0;
}
/*class Solution {
public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int> >(m + 1);
        for(int i = 0; i <= m; ++i) memo[i] = vector<int>(n + 1, -1);
        return paths(m, n);
    }
    int paths(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        if (memo[m][n] != -1)
            return memo[m][n];

        int result = 0;
        if (m - 1 >= 1) {
            result += uniquePaths(m - 1, n);
        }
        if (n - 1 >= 1)  {
            result += uniquePaths(m, n - 1);
        }
        memo[m][n] = result;
        return result;
    }
private:
    vector<vector<int> > memo;
    int result = 0;
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
*//*    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
*//*
	int n;
	while(cin >> n) {
		long long res = 1;
		for(int i = 1; i <= n; ++i) res *= i;
		cout << n << "! = " << res << endl;
	}
    return 0;
}*/
/*using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty())
            return result;

        unordered_map<int, int> record;
        for(auto num: nums)
            ++record[num]; // count

        vector<vector<int>> bucket(nums.size() + 1, vector<int>());

        for(const auto& e: record) {
            cout << "num " << e.first << " appears " << e.second << " times." << endl;
            bucket[e.second].push_back(e.first);
        }

        for(int i = bucket.size() - 1; i >= 0 && k; --i) {
            if (!bucket[i].empty()) {
                for(int j = 0; j < bucket[i].size() && k; ++j, --k) {
                    result.push_back(bucket[i][j]);
                }
            }
        }
        return result;
    }
private:
    vector<int> result;
};
static int _____ = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}*/
/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return result;
        string tmp = "";
        dfs(digits, 0, tmp);
        return result;
    }
    void dfs(const string& digits, int begin, string tmp) {
        if (tmp.size() == digits.size()) {
            result.push_back(tmp);
            return;
        }
        // if (begin >= digits.size())
        //     return;
        string str = dtostr[digits[begin]];
        for(int j = 0; j < str.size(); ++j) {
            tmp.push_back(str[j]);
            dfs(digits, begin + 1, tmp);
            tmp.pop_back();
        }
    }
private:
    unordered_map<char, string> dtostr = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> result;
};
int main(void) {
    Solution solu;
    auto res = solu.letterCombinations("23");
    for (auto e: res)
        cout << e << " ";
    cout  << endl;
    return 0;
}*/
/*
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) getIndex[inorder[i]] = i;
        return construct(preorder, inorder, 0);
    }
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int i) {
        if (i >= preorder.size())
            return nullptr;
        TreeNode* result = new TreeNode(preorder[i]);
        int mid = getIndex[preorder[i]];
        if (i + 1 < preorder.size()) {
            if (mid > getIndex[preorder[i + 1]]) //下个元素是左子树
                result->left = construct(preorder, inorder, i + 1);
            else
                result->right = construct(preorder, inorder, i + 1);
        }
        return result;
    }
private:
    unordered_map<int, int> getIndex;
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);

        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

*/
/*class KMP {
public:
    KMP() {
    }
    int findSub(const string& source, const string& pattern) {
        generateNext(pattern);
        int sourceLength = source.size(), patternLength = pattern.size();

        int m;
        for(int n = 0; n < sourceLength; ++n) {
            for(m = 0; m < patternLength; ) {
                if (source[n + m] == pattern[m]) ++m;
                else break;
            }
            if (m == patternLength - 1) return n;
            else m = next[m];
        }
        return -1;
    }
private:
    vector<int> next;
    void generateNext(const string& pattern) {
        next = vector<int>(pattern.size(), 0);

        int i = 1;
        while(i < pattern.size()) {
            int j = next[i - 1];
            while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            if (pattern[i] == pattern[j])
                next[i] = j + 1;
            else
                next[i] = 0;
            ++i;
        }
        cout << "      ";
        for(auto c: pattern)
            cout << c << " ";
        cout << endl;
        cout << "next: ";
        for(auto c : next)
            cout << c << " ";
        cout <<endl;
    }
};

int main() {
    KMP kmp;
    cout << kmp.findSub("abcddbaaadcdcabdg", "dcdca") << endl;
    return 0;
}*/
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        list<string> list_strs(strs.begin(), strs.end());


        for(auto pre = list_strs.begin(); pre != list_strs.end(); ) {
            vector<string> tmp = {(*pre)};
            auto dummy = pre;
            for(auto cur = ++pre; cur != list_strs.end(); ) {
                if(Anagrams(dummy, cur)) {
                    tmp.push_back(*cur);
                    cur = list_strs.erase(cur);
                } else {
                    ++cur;
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
private:
    bool Anagrams(list<string>::iterator &s1, list<string>::iterator &s2) {
        if ( (*s1).size() != (*s2).size() )
            return false;

        unordered_map<char, int> record;

        for(int i = 0; i < (*s1).size(); ++i) {
            ++record[(*s1)[i]];
        }

        for(int i = 0; i < (*s2).size(); ++i)  {
            if (record.count((*s2)[i]) && record[(*s2)[i]] >= 0)
                --record[(*s2)[i]];
            else
                return false;
        }
        return true;
    }
};
int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto res = s.groupAnagrams(strs);

    return 0;
}*/

/*class Solution {
public:
     // @param m: An integer m denotes the size of a backpack
     // @param A: Given n items with size A[i]
     // @return: The maximum size
     //
    int backPack(int m, vector<int> &A) {
        if (A.empty()) return 0;
        return pack(m, A);
    }
    int pack(int capacity, vector<int>& A) {
        if (capacity < 0) return 0;
        int result = 0;
        for(int i = 0; i < A.size(); ++i) {
            if (capacity - A[i] < 0) 
                continue;
            else 
                result = max(result, pack(capacity - A[i], A) + A[i]);
        }
        return result;
    }
};

int main(){
	vector<int> vec = {3, 4, 5, 8};
	Solution s;
	cout << s.backPack(10, vec) << endl;
	return 0;
}
*/
// * Definition for a binary tree node.
/* struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ostringstream os;
        inOrder(root, os);
        string s = os.str();
        int pre = 0, cur = 1;
        while(cur < s.size()) {
            if (s[pre] >= s[cur]) return false;
            else ++pre, ++cur;
        }
        return true;
    }
private:
    void inOrder(TreeNode* root, ostream& os) {
        if (root == nullptr) return;
        inOrder(root->left, os);
        os << root->val;
        inOrder(root->right, os);
    }
};

static int _____ = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
*/
/*
int test_balls(int balls, int floors, vector<vector<int> >& dp) {
    if (floors == 0) return 0;
    if (floors == 1) return balls > 1 ? 1 : 0;
    if (balls == 0) return 0;
    if (balls == 1) return floors;

    if (dp[balls][floors] != -1) {
        return dp[balls][floors];
    }
    dp[balls][floors] = floors;

    for(int i = 1; i <= floors; ++i) {
        auto tmp = max(test_balls(balls - 1, i - 1, dp) + 1, test_balls(balls, floors - i, dp) + 1);
        dp[balls][floors] = min(tmp, dp[balls][floors]);
    }
    return dp[balls][floors];
}
int main(){
    int n;
    cin >> n;
    while(n--) {
        int seq, balls, layers;
        cin >> seq >> balls >> layers;
        vector<vector<int> > dp(balls + 1, vector<int>(layers + 1, -1));
        cout << seq << " " << test_balls(balls, layers, dp) << endl;
    }
    return 0;
}*/
/*
int main(){
    int m, n;
    while(cin >> m >> n) {
        unordered_set<string> record;
        string str;
        for(int i = 0; i < m; ++i) {
            cin >> str;
            record.insert(str);
        }
        for(int i = 0; i < n; ++i) {
            cin >> str;
            for(int j = 1; j <= str.size(); ++j) {
                string tmp = str.substr(0, j);
                if (record.count(tmp))  {
                    cout << 1 << endl;
                    break;
                }
            }
            cout << -1 << endl;
        }
        cout << endl;
    }
    return 0;
}

*/
/*
a
bc
d
eba
ebc
f

ebcc
ebd

 * */
//#include<iostream>
//#include <vector>
//using namespace std;

/*

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return 0;
        int maxLength = 1;
        int pos = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto tmp = pali(s, i, i);
            if (maxLength < tmp.first) {
                maxLength = tmp.first;
                pos = tmp.second;
            }
            tmp = pali(s, i, i + 1);
            if (maxLength < tmp.first) {
                maxLength = tmp.first;
                pos = tmp.second;
            }
        }
        return s.substr(pos, maxLength);
    }
private:
    pair<int,int> pali(const string& s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
        return make_pair(r - l + 1, l);
    }
};
int main(void)
{
    Solution solu;
    cout << solu.longestPalindrome("badda") << endl;
    return 0;
}

*/

/*
static int x = [](){ios_base::sync_with_stdio(false); return 0;}();

int f(int n, bool hasTakeMysit,vector<vector<int>>& dp) {
    if ( n == 1) return 1;
    if (dp[hasTakeMysit][n] != -1) return  dp[hasTakeMysit][n];
    if (hasTakeMysit) {
        dp[hasTakeMysit][n] =  f(n - 1, false, dp) - 1 + f (n - 1,true, dp) - 1;
    }else {
        dp[hasTakeMysit][n] =  f(n - 2, true, dp) + f(n - 2, false, dp);
    }
    return dp[hasTakeMysit][n];
}

int main(){
    int n;
    while(cin >> n ) {
        vector<vector<int>> dp(2, vector<int>(n + 1, -1));
        cout << n * f(n - 1, false, dp) << endl;
    }
    return 0;
}

*/
/*
#include<iostream>
#include <vector>

using namespace std;

int x = [](){ios_base::sync_with_stdio(false); return 0;}();


int f(int n, bool two, vector<vector<int>>& dp) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2 && two) return 2;
    if (dp[two][n] != -1){
        return dp[two][n];
    }
    else {
        if (two) {
            dp[two][n] = f(n - 2, false, dp) + f (n - 1, true, dp);
        }else {
            dp[two][n] =  f(n - 1, true, dp);
        }
    }
    return dp[two][n];
}

int main()
{
    int stages;
    while(cin >> stages) {
        vector<vector<int>> dp(2, vector<int>(stages + 1, -1));
        cout << f(stages, true, dp) << endl;
    }
    return 0;
}
*/

/*
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int in = m + n - 1;
        while ( m >= 0 || n >= 0) {
            if (m < 0) {
                nums1[in--]= nums2[n--];
            } else if (n < 0) {
                return;
            } else {
                nums1[in--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            }
        }
    }
};
int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> num2 = {3,5,6};
    Solution solution;
    solution.merge(nums1, 3, num2, 3);
    return 0;
}*/
/*
using namespace std;

class Solution {
private:
    struct Bound {
        int low;
        int high;
        Bound(int l, int h) : low(l), high(h) {}
        Bound(){}
    };
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, struct Bound> record;
        int maxLen = 0;
        for (auto n : nums) {
            if (record.find(n) != record.end()) {
                continue;
            }
            Bound b(n, n);
            record[n] = b;
            int low, high;
            low = record.find(n - 1) == record.end() ? n : record[n - 1].low;
            high = record.find(n + 1) == record.end() ? n : record[n + 1].high;
            if (record.find(n + 1) != record.end()) {
                record[n + 1].low = record[n].low = low;
                record[n + 1].high = record[n].high = high;
            }
            if (record.find(n - 1) != record.end()) {
                record[n - 1].high = record[n].high = high;
                record[n - 1].low = record[n].low = low;
            }
            maxLen = (high - low + 1) > maxLen ? high - low + 1 : maxLen;
        }
        return maxLen;
    }
};

int main() {
    vector<int> vec = {100,4,200,1,3,2};
    Solution s;
    cout << s.longestConsecutive(vec) << endl;
    return 0;
}*/
/*
#include<iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include<iostream>
#include<set>

#include<stdio.h>

int count(int coins[], int n , int length){
    int m = length;
    int c [length+1][n+1];

    for(int i = 0; i <=m; i++)
        c[i][0] = 1;
    for(int i = 1; i <=n; i++)
        c[0][i] = 0;

    for(int i = 1; i <=m; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            if(j < coins[i-1])//第 i 枚硬币 不可用. (需要找 5块钱,但是现在只有一张百元大钞)
            {
                c[i][j] = c[i-1][j];
                continue;
            }
            //在第 i 枚硬币可用的情况下, 不使用 第 i 枚硬币 或者第 i 枚硬币至少使用一次---状态方程
            c[i][j] = c[i-1][j] + c[i][j - coins[i-1]];//coinsValues下标从0开始
        }
    }
    return c[m][n];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int coins[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", coins + i);
        }
        printf("%d\n", count(coins, n, k));
    }
    return 0;
}*/
/*int count(const int coins[], int length, int target )
{
    int i, j, x, y;
    int dp[target+1][length];

    for (i=0; i<length; i++)
        dp[0][i] = 1;

    for (i = 1; i < target+1; i++)
    {
        for (j = 0; j < length; j++)
        {
            x = (i-coins[j] >= 0) ? dp[i - coins[j]][j]: 0;
            y = (j >= 1)? dp[i][j-1]: 0;
            dp[i][j] = (x + y) % 10000007;
        }
    }
    return dp[target][length-1];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int coins[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", coins + i);
        }
        printf("%d\n", count(coins, n, k));
    }
    return 0;
}*/
/*
int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        bitset<64> t(i);
        auto s = t.to_string();
        int in = 0;
        while(s[in] != '1') ++in;
        auto aux = s.substr(in);
        if (aux == string(aux.rbegin(), aux.rend())) {
            ++ans;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}*/
/*int main()
{
    int n; cin >> n;
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    set<int> ans;
    for (int i = 2; i <= n; ++i) {
        if ( !visited[i]) {
            ans.insert(i);
            for (int j = 2; i*j <= n; ++j) {
                visited[i*j] = true;
            }
        }
    }
    for (auto i : ans) {
        for(int j = 2; pow(i, j) <= n; ++j) {
            ans.insert(pow(i,j));
        }
    }
    cout << ans.size() << endl;
    return 0;
}*/
/*class Solution {
public:
    static vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int l = 0, r = 0;
        bool freq[256] = {false};
        for (auto e : p) freq[e] = true;
        while (r < s.size()) {
            if (freq[s[r]]) {
                if (r - l + 1 == p.size()) {
                    ans.push_back(l++);
                }
                ++r;
            } else {
                ++r;
                l = r;
            }
        }
        return ans;
    }
};
int main(){
    auto t = Solution().findAnagrams("cbaebabacd", "abc");
    return 0;
}*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i ){
            int left = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (left == nums[j]) {
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return vector<int>();
    }
};
int main()
{
    vector<int> vec = {3,2,4};
    Solution s;
    auto t = s.twoSum(vec, 6);
    return 0;
}*/
/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int newEnd = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[newEnd++]);
            }
        }
    }
};
int main() {
    vector<int> nums = {1, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(nums);
    return 0;
}*/
/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() < 9) {
            ++digits[digits.size() - 1];
            return digits;
        }
        else {
            int i = digits.size() - 1;
            while(i != 0 && digits[i] >= 9) {
                --i;
            }
            if (i == 0 && digits[i] >= 9) {
                vector<int> ans;
                ans.push_back(1);
                for (int u = 0; u < digits.size(); ++u) ans.push_back(0);
                return ans;
            } else {
                ++digits[i];
                for (int j = i + 1; j < digits.size(); ++j) digits[j] = 0;
                return vector<int>(digits.begin(), digits.end());
            }
        }

    }
};
int main() {
    vector<int> vec = {8,9,9};
    Solution s;
    auto t = s.plusOne(vec);
    return  0;
}*/
/*class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ++i, ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> v1 = {3,1,2}, v2 = {1,3};
    Solution solution;
    auto t = solution.intersect(v1, v2);
    return 0;
}*/
/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> v = {1,1,3,2,2,3,4};
    cout << s.singleNumber(v) << endl;
    return 0;
}*/
/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1 ) return false;
        map<int, int> m;
        for(auto i: nums) {
            if (m[i]) return false;
            else ++m[i];
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<int> v = {3,3};
    cout << s.containsDuplicate(v) << endl;
    return 0;
}*/
/*class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k % nums.size() == 0 || nums.empty()) return;
        k %= nums.size();
        _rotate(nums, nums.size() - k, nums.size() - 1);
        _rotate(nums, 0 , nums.size() - k - 1);
        _rotate(nums, 0, nums.size() - 1);
        return;
    }
    void _rotate(vector<int>& nums, int l, int r) {
        while(l < r) swap(nums[l++], nums[r--]);
    }
};
int main() {
    vector<int> n = {1,2};
    Solution solution;
    solution.rotate(n, 3);
    return 0;
}*/
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.empty() ) return 0;
        stack<int> mono;
        mono.push(prices[0]);
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if (prices[i] > mono.top()) {
                mono.push(prices[i]);
            }
            else {
                int top = mono.top();
                int bot = mono.top();
                while(!mono.empty()) {
                    bot = mono.top();
                    mono.pop();
                }
                ans += top - bot;
                mono.push(prices[i]);
            }
        }
        int top = mono.top();
        int bot = mono.top();
        while(!mono.empty()) {
            bot = mono.top();
            mono.pop();
        }
        ans += top - bot;
        return ans;
    }
};*/
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int remainPos = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[remainPos]) {
                nums[++remainPos] = nums[i];
            }else {
                continue;
            }
        }
        return remainPos + 1;
    }
};
int main() {
    vector<int> v = {1,1,1,2,4,4,5};
    Solution s;
    auto t = s.removeDuplicates(v);
    return  0;
}*/
/*
#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int Max; cin >> Max;
    int ans = n * (Max + Max - n + 1) / 2;
    ans -= Max;
    for (int i = n - 1; i > 0; --i) {
        int val; cin >> val;
        if (val == Max) continue;
        ans -= val;
    }
    cout << ans << endl;
    return 0;
}
*/
/*
#include <istream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <set>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

typedef long long ll;

ll gcd(ll x,ll y)
{
    while(x!=y)
    {
        if(x>y) x=x-y;
        else
            y=y-x;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    ll ans = 1;
    for(int i = n; i >=1; --i) {
            ans = i/gcd(i, ans)*ans;
    }
    cout << ans << endl;
    return 0;
}
*/

/*
#include <istream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <set>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>

using namespace std;

typedef long long ll;

ll gcd(ll x,ll y)
{
   while(x!=y)
   {
       if(x>y) x=x-y;
       else
           y=y-x;
   }
   return x;
}

ll lcm(ll x, ll y) {
   return x/gcd(x,y)*y;
}
int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   if (n == 1) cout << 1 << endl;
   ll ans = 1;
   for(int i = 2; i <=n; ++i) {
       ans = lcm(i, ans);
   }
   cout << ans << endl;
   return 0;
}

*/


/*int main(){
    fstream s;
    s.open("/Users/zengtong/Dropbox/ClionProject/offer/out.txt", ios_base::out);
    if (!s.is_open()) {
        cout << "Open error" << endl;
        exit(1);
    }
    pid_t pid = fork();
    if (pid == 0) {
        s << "I am the Child \n";
        s.close();
    }
    if (pid > 0) {
        s << "I am the Parent\n";
        int p = waitpid(-1, NULL, 0);
        cout << "pid: " << p << " terminated. " << endl;
        s.close();
    }
    cout << "Finished !" << endl;
    return 0;
}*/

/*
 * 链家笔试第一题2018.4.8
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> ans;
    while(n--) {
        int num;
        cin >> num;
        while (num--) {
            int ord;
            cin >> ord;
            ans.insert(ord);
        }
    }
    cout << ans.size() << endl;
    return 0;
}
*/

/*
 * class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        *//*
        暴力： 时间：O(n^2) 空间 O(1)
        缓存:  时间: O(n) 空间 O(n)
        *//*
        if (A.empty()) return vector<int>();

        vector<int> pre(A.size(), 0), latter(A.size(), 0);
        long product = 1;
        for(int i = 0; i < A.size(); ++i) {
            product *= A[i];
            pre[i] = product;
        }
        product = 1;
        for(int i = A.size() - 1; i >=0; --i) {
            product *= A[i];
            latter[i] = product;
        }
        vector<int> ans(A.size(), 0);
        ans[0] = latter[1];
        ans[A.size() - 1] = pre[A.size() - 2];
        for (int i = 1; i < A.size() - 1; ++i) {
            ans[i] = pre[i - 1] * latter[i + 1];
        }
        return ans;
    }
};*/
/*
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int, int> m;
        for(int i = 0; i < length; ++i) {
            if (m[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }else {
                ++m[numbers[i]];
            }
        }
        return false;
    }
};
int main(){
    int nums[] = {2,3,1,0,2,5,3};
    Solution solution;
    int ans = 0;
    cout << solution.duplicate(nums, 7, &ans) << " Ans:" << ans << endl;
    return 0;
}*/
/*class Solution {
public:
    int StrToInt(string str) {
        if (str.empty()) return 0;
        int isSign;
        if (str[0] == '+') isSign = 1;
        else if (str[0] == '-') isSign = 2;
        else isSign = 0;
        int i = isSign ? 1 : 0; // 判断是否为正负符号

        while(str[i] == '0') ++i; // 考虑截取前面的字符0

        int ans;
        if (str[i] >= '0' && str[i] <= '9') {
            ans = str[i] - '0';
        } else {
            return 0;
        }

        for(++i;i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                ans = ans*10 + str[i] - '0';
            } else {
                return 0;
            }
        }
        if (!isSign) return ans;
        else return isSign == 1 ? ans : -ans;
    }
};

int main(){
    Solution solution;
    string s;
    while (cin >> s) {
        cout << solution.StrToInt(s) << endl;
    }
    return 0;
}*/
/*
class Solution {
public:
    int Add(int num1, int num2)
    {
        do{
            int s1 = num1 ^ num2;
            int s2 = (num1 & num2) << 1;
            num1 = s1;
            num2 = s2;
        }while(num2 != 0);
        return num1;
    }
};
int main() {
    Solution solution;
    cout << solution.Add(3, 4) << endl;
    return 0;
}*/
/*class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        m = m - 1;
        Node* p, *head = new Node(0);
        p = head;
        for(int i = 1; i < n; ++i) {
            p->next = new Node(i);
            p = p->next;
        }
        p->next = head; // 形成环状
        Node* cur = head;
        while(cur->next != cur) {
            for(int i = 0; i < m; ++i){
                cur = cur->next;
                p = p->next;
            }
            p->next = cur->next;
            delete cur;
            cur = p->next;
        }
        return cur->val;
    }
private:
    struct Node
    {
        int val;
        Node* next;
        Node(int v) : val(v), next(NULL){}
    };
};
int main() {
    Solution solution;
    cout << solution.LastRemaining_Solution(5, 3) << endl;
    return 0;
}*/
/*class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int bucket[14] = {0}
        for(auto e: numbers) ++bucket[e];
        int start = 1;
        while(bucket[start] == 0) ++start;
        for (int i = 1; i < numbers.size() ; ++i) {
            if (bucket[start + i] != 1) {
                if (bucket[0]) {
                    --bucket[0];
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    Solution solution;
    vector<int> vec = {0,3,1,6,4};
    cout << solution.IsContinuous(vec);
    return 0;
}*/
/*class Solution {
public:
    string ReverseSentence(string str) {
        auto strs = split(str, ' ');
        string ans = "";
        std::for_each(strs.rbegin(), strs.rend(), [&ans](string s) mutable-> void { ans += s, ans+= " ";});
        return ans.substr(0, str.size());
    }
    vector<string> split(string str, char c) {
        istringstream ss( str );
        vector<string> ans;
        while (!ss.eof())         // See the WARNING above for WHY we're doing this!
        {
            string x;               // here's a nice, empty string
            getline( ss, x, c);  // try to read the next field into it
            ans.push_back(x);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.ReverseSentence("student. a am I");
    return 0;
}*/
/*class Solution {
public:
    string LeftRotateString(string str, int n) {
        *//*
        if (str.empty()) return str;
        if ( n > str.size()) n /= str.size();
        return  str.substr(n) + str.substr(0, n);
        *//*
        if (str.empty()) return str;
        if (n > str.size()) n /= str.size();
        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size() - 1);
        Reverse(str, 0, str.size() - 1);
        return str;
    }
    void Reverse(string& str, int l, int r) {
        if(l >= r) return;
        for(int i = l; i <= r;) {
            char temp = str[i];
            str[i] = str[r];
            str[r] = temp;
            ++i, --r;
        }
    }
};
int main()
{
    Solution solution;
    auto t = solution.LeftRotateString("abcXYZdef", 3);
    return 0;
}*/
/*class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        for(auto i : array) {
            if (i >= sum) break;
            bool isExist = binary_search(array.begin(), array.end(), sum - i);
            if (isExist) {
                if (ans.empty()) ans.push_back(min(i, sum - i)), ans.push_back(max(i, sum - i));
                else {
                    int product = std::accumulate(ans.begin(), ans.end(), 1, std::multiplies<int>());
                    if (product > i * (sum-i) ) {
                        ans[0] = min(i, sum - i);
                        ans[1] = max(i, sum - i);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    Solution solution;
    auto t = solution.FindNumbersWithSum(vec, 6);
    return 0;
}*/
/*class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int num) {
        vector<vector<int>> ans;
        vector<int> temp(2, 1);
        int small = 1, big = 2;
        int sum = small;
        while (big < num / 2 + 2) {
            if (temp.back() != big) {
                temp.push_back(big);
                sum += big;
            }
            if (sum < num) {
                ++big;
            } else if (sum > num) {
                sum -= temp[small];
                ++small;
            } else { // ( sum == num)
                ans.emplace_back(&temp[small], &temp[big] + 1);
                sum -= temp[small];
                ++small;
                ++big;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto s = solution.FindContinuousSequence(3);
    return 0;
}*/
/*class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() == 2) {
            *num1 = data[0], *num2 = data[1];
            return;
        }
        int and_or = data[0];
        for (int i = 1; i < data.size(); ++i) {
            and_or ^= data[i];
        }
        int s = 0;
        int aux = and_or;
        while ( !(and_or & 1)) {
            and_or = and_or >> 1;
            ++s;
        }
        int i = 0;
        while ( i < data.size() && !((data[i] >> s) & 1)) ++i;
        *num1 = data[i];
        for (++i; i < data.size(); ++i) {
            if ((data[i] >> s) & 1) *num1 ^= data[i];
        }
        *num2 = *num1 ^ aux;
    }
};

int main() {
    vector<int> vec = {4,6,2,2,3,3,8,8,9,9,1000000,1000000};
    int n1, n2;
    Solution solution;
    solution.FindNumsAppearOnce(vec, &n1, &n2);
    return 0;
}*/
/*class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //return count(data.begin(), data.end(), k);
        int rt = GetLastOfK(data, k);
        int lt= GetFirstOfK(data, k);
        if (rt != -1 && lt != -1)
            return GetLastOfK(data, k) - GetFirstOfK(data, k) + 1;
        return 0;
        *//*int l = 0, r = data.size() - 1;
        int mid = l + r / 2;
        while (l <= r) {
            if (data[mid] == k) {
                break;
            }else if (data[mid] > k) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
            mid = (l + r) /2;
        }
        int lt = mid, rt = mid;
        while (data[lt] == k || data[rt] == k) {
            if (lt < 0 || rt >= data.size()) break;
            if (data[lt] == k) --lt;
            if (data[rt] == k) ++rt;
        }
        return rt - lt - 1;*//*
    }

private:
    int GetFirstOfK(const vector<int>& data, int k) {
        int l = 0, r = data.size() - 1;
        int mid = (r + l) / 2;
        while (l <= r) {
            if (data[mid] == k) {
                if (mid - 1 >= 0 && data[mid - 1] == k) r = mid - 1;
                else return mid;
            } else if (data[mid] > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = (r + l) / 2 ;
        }
        return  -1;
    }

    int GetLastOfK(const vector<int>& data, int k) {
        int l = 0, r = data.size() - 1;
        int mid = (r + l) / 2;
        while (l <= r) {
            if (data[mid] == k) {
                if (mid + 1 <= r && data[mid + 1] == k) l = mid + 1;
                else return mid;
            } else if (data[mid] > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = (r + l) / 2 ;
        }
        return  -1;
    }
};
int main()
{
    Solution solution;
    vector<int> s = {1,2,3,3,3,3};
    cout << solution.GetNumberOfK(s, 3) << endl;
    return 0;
}*/
/*
class Solution {
public:
    int InversePairs(vector<int>& data) {
        ans = 0;
        if (data.empty() || data.size() == 1) return ans;
        merge_sort(data, 0, data.size() - 1);
        return this->ans;
    }

private:

    void merge_sort(vector<int>& data, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        merge_sort(data, l, mid);
        merge_sort(data, mid + 1, r);
        merge(data, l, mid, r);
    }
    void merge(vector<int> &data, int l, int mid, int r) {
        vector<int> temp(&data[l], (&data[r]) + 1);
        int m = l, n = mid + 1;
        for (int i = l; i <= r; ++i) {
            if(m > mid) {
                data[i] = temp[n - l];
                ++n;
            }
            else if (n > r) {
                data[i] = temp[m - l];
                ++m;
            }
            else if (temp[m-l] > temp[n-l]) {
                ans += (mid - m + 1) % 1000000007;
                data[i] = temp[n - l];
                ++n;
            } else {
                data[i] = temp[m - l];
                ++m;
            }
        }
    }
private:
    int ans;
};
int main() {
    vector<int> w = {1,3,4,2,0};
    Solution solution;
    cout << solution.InversePairs(w) << endl;
    return 0;
}*/
/*
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, pair<int,int> > m;
        for (int i = 0; i < str.size(); ++i) {
            m[str[i]].first = i;
            ++m[str[i]].second;
        }
        int ans = str.size();
        for (auto &it : m) {
            if (it.second.second == 1) ans = min(ans, it.second.first);
        }
        return ans;
    }
};

int main() {
    string str = "11223355788";
    Solution solution;
    cout << solution.FirstNotRepeatingChar(str) << endl;
    return 0;
}*/
/*class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), [](const int& a, const int& b){
            return ( to_string(a) + to_string(b) ) < (to_string(b) + to_string(a));
        });
        string res;
        for(auto each: numbers) {
            res += to_string(each);
        }
        return res;
    }
};

int main() {
    vector<int> s ={3, 32, 321};
    Solution solution;
    string t = solution.PrintMinNumber(s);
    return 0;
}*/
/*
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            string str = to_string(i);
            ans += count(str.begin(), str.end(), '1');
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.NumberOf1Between1AndN_Solution(13) << endl;

    string s = "1 2 3 4 5";
    istringstream ss( s );
    while (!ss.eof())         // See the WARNING above for WHY we're doing this!
    {
        string x;               // here's a nice, empty string
        getline( ss, x, ' ' );  // try to read the next field into it
        cout << x << endl;      // print it out, EVEN IF WE ALREADY HIT EOF
    }
    return 0;
}
*/

/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int Max = array[0];
        for (int i = 0; i < array.size(); ++i) {
            int sum = array[i];
            Max = max(sum, Max);
            for (int j = i + 1; j < array.size(); ++j) {
                sum += array[j];
                Max = max(sum, Max);
            }
        }
        return Max;
    }
};
int main()
{
    vector<int> t = {1,-2,3,10,-4,7,2,-5};
    Solution s;
    cout << s.FindGreatestSumOfSubArray(t);
    return 0;
}*/
/*class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k == 0 || k > input.size())
            return vector<int>();
        priority_queue<int> pq;
        for(auto i : input) {
            if(pq.size() < k) {
                pq.push(i);
                continue;
            }
            if (i < pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};

int main()
{
    vector<int> t = {4,5,1,6,2,7,3,8,23,123,13224,5433,23,1,23,5,3,42,5566};
    Solution s;
    auto ans = s.GetLeastNumbers_Solution(t, 0);
    return 0;
}*/
/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> m;
        for (auto i: numbers) {
            ++m[i];
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > numbers.size() / 2) return it->first;
        }
        return 0;
    }
};*/
/*#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        long long a, _b, c, ans;
        ans = 0;
        scanf("%lld %lld %lld",&a, &_b, &c);
        long long r , g , b;
        b = max(max(a, _b), c);
        g = max(min(a, _b), c);
        r = min(min(a, _b), c);
        if (r <= 0) {
            cout << r << endl;
            return 0;
        }
        ans += r;
        g -= r;
        b -= r;
        while ( g*2 > b) {
            g = b / 2;
        }
        if ( g + b >= 3 ) {
            ans += g;
        }
        printf("%lld\n", ans);
    }
    return 0;
}*/
/*#include<iostream>
#include<cstdio>
using namespace std;

int jdz(int num) {
    return num > 0 ? num : -num;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--) {
        int s;
        scanf("%d",&s);
        long ans = 0;
        while(s--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ans += jdz(x2 - x1 + 1)*jdz(y2-y1+1);
        }
        cout << ans << endl;
    }
    return 0;
}*/
/*

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if( pHead == NULL) return NULL;
        RandomListNode* p = pHead;
        map<oldNode, newNode> nodes;
        RandomListNode* new_cur;

        new_cur = new RandomListNode(pHead->label);
        nodes[pHead] = new_cur;
        p = p->next;
        while(p) {
            new_cur->next = new RandomListNode(p->label);
            nodes[p] = new_cur->next;

            p = p->next;
            new_cur = new_cur->next;
        }

        p = pHead;
        new_cur = nodes[pHead];
        while(p) {
            new_cur->random = nodes[p->random];
            p = p->next;
            new_cur = new_cur->next;
        }
        return nodes[pHead];
    }
private:
    typedef RandomListNode* oldNode;
    typedef RandomListNode* newNode;
};

int main(){
    auto n1 = new RandomListNode(1);
    auto n2 = new RandomListNode(2);
    auto n3 = new RandomListNode(3);
    n1->next = n2;
    n2->next = n3;
    n1->random = n3;

    Solution s;
    RandomListNode* p = s.Clone(n1);
    return 0;
}*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void __findPath(TreeNode* root, int expectNumber, vector<int> vec) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL && expectNumber == root->val) {
            vec.push_back(root->val);
            path.push_back(vec);
            return;
        }
        vec.push_back(root->val);
        __findPath(root->left, expectNumber - root->val, vec);
        __findPath(root->right, expectNumber - root->val, vec);
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        path = vector<vector<int> >();
        __findPath(root, expectNumber, vector<int>());
        return this->path;
    }
private:
    vector<vector<int> > path;
};
*/

/*
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec;
    int zero_cnt = 0;
    while(n--) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) ++zero_cnt;
        else vec.push_back(temp);
    }
    for(int i = 0; i < vec.size(); ++i) {
        printf("%d\n", vec[i]);
    }
    while(zero_cnt--) {
        printf("0\n");
    }
    return 0;
}
*/

/*************************************************************************
	> File Name: nonHead.cpp
	> Author: zengtong
	> Mail: unixsudo@outlook.com
	> Created Time: 四  3/29 14:30:06 2018
 ************************************************************************//*


#include<iostream>
using namespace std;

class UPNumber{
public:
    static void* operator new(size_t sz) {
        onTheHeap = true;
        return ::operator new(sz);
    }
    UPNumber() {
        if(onTheHeap) {
            cout << "Trying to Construct in heap !" << endl;
        }
        onTheHeap = false;
    }

    void print() {
        cout << "print works" << endl;
    }
private:
    static bool onTheHeap;
};

class NonHeap{
public:
    static NonHeap* makeNonHeapInstance() {
        return new NonHeap();
    }
    ~NonHeap(){}
    void print() {
        cout << "NonHeap print works !" << endl;
    }
private:
    NonHeap() {}
    NonHeap(const NonHeap& rhs){}
};
bool UPNumber::onTheHeap = false;

int main()
{
    UPNumber n;
    n.print();
    UPNumber* t = new UPNumber();
    t->print();

    NonHeap* p = NonHeap::makeNonHeapInstance();
    p->print();
    delete p;
    return 0;
}
*/

/*
#include<iostream>
#include<typeinfo>
using namespace std;

class NLPComponent{
public:
    virtual NLPComponent* clone() {
        return new NLPComponent(*this);
    }
};


class TextBlock : public NLPComponent {
public:
    virtual TextBlock* clone() {
        return new TextBlock(*this);
    }
    void getInt() {
        cout << "GetInt" << endl;
        return;
    }
};

int main()
{
    NLPComponent* nlp = new NLPComponent();
    cout << typeid(nlp).name() << endl;
    TextBlock* textBlock = new TextBlock();
    cout << typeid(textBlock).name() << endl;
    cout << typeid(textBlock->clone()).name() << endl;
    cout << typeid(TextBlock).name() << endl;
    return 0;
}
*/

/*

class Solution {
public:

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return verify(sequence, 0, sequence.size() - 1);
    }
private:
    bool verify(const vector<int>& sequence, int l, int r) {
        if (sequence.empty()) return true;
        if (l >= r) return true;
        int val = sequence[r];
        int mid = 0;
        while(mid <= r && sequence[mid] < val) {
            ++mid;
        }
        for(int cur = mid; cur <= r; ++cur) {
            if (sequence[cur] < val) return false;
        }
        return verify(sequence, l, mid-1) && verify(sequence, mid, r - 1);
    }
};

int main()
{
    vector<int> v = {4, 8 ,6, 12, 16, 14, 10};
    Solution s;
    cout << s.VerifySquenceOfBST(v) << endl;
    return 0;
}
*/

/*
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == popV.size() && pushV.empty()) return true;

        if (popV.size() == pushV.size() && popV.size() == 1)
            return popV[0] == pushV[0];

        vector<bool> visited(popV.size(), false);
        for (int i = 0; i + 1 < popV.size(); ++i) {
            auto last = find(pushV.begin(), pushV.end(), popV[i]);
            auto next = find(pushV.begin(), pushV.end(), popV[i+1]);
            if (last == pushV.end() || next == pushV.end())
                return false;
            visited[last - pushV.begin()] = true;
            int interval = 0;
            for (auto cur = last; cur != next; cur > next ? --cur : ++ cur) {
                if ( !visited[cur - pushV.begin() - 1]) ++interval;
            }
            if (interval > 1) return false;
        }
        return true;
    }
};

int main()
{
//    vector<int> pushV = {1,2,3,4,5};
//    vector<int> popV_wrong = {4,3,5,1,2};
//    vector<int> popV = {4,5,3,2,1};
    vector<int> pushV = {1};
    vector<int> popV = {2};
    Solution s;
    cout << s.IsPopOrder(pushV, popV) << endl;
//    cout << s.IsPopOrder(pushV, popV_wrong) << endl;
    return 0;
}
*/

/*#include<cstdio>
#include <cstdlib>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int spot;
        scanf("%d", &spot);
        char *str = (char*) malloc(sizeof(char)*spot);
        scanf("%s", str);
        int ans = 0;
        for (int i = 0; i < spot; ++i) {
            if (str[i] == 'X') continue;
            if (str[i] == '.') ++ans;
            i += 2;
        }
        printf("%d\n", ans);
        free(str);
        str = NULL;
    }
    return 0;
}*/
/*
 * 网易笔试
 * #include<cstdio>
using namespace std;
int main()
{
    long long l, r;
    while(scanf("%lld %lld", &l, &r) != EOF) {
        int output = 0;
        for (long long i = l; i <=r; ++i) {
            if ( ( (i*i + i) / 2 ) % 3 == 0) ++output;
        }
        printf("%d", output);
    }
    return 0;
}*/

/*
#include<iostream>
using namespace std;
long long sum_of_each(const string& val) {
    long long res = 0;
    for (char i : val) {
        res += i - '0';
    }
    return res;
}

string generateNumber(long long order) {
    string rtn;
    for (int i = 1; i <= order; ++i) {
        rtn += to_string(i);
    }
    return rtn;
}
int main()
{
    long long  l, r;
    cin >> l >> r;
    long long res = 0;
    long long sums = sum_of_each(generateNumber(l));
    if (sums % 3 == 0) ++res;
    long long cur = l + 1;
    while(cur <= r) {
        sums += sum_of_each(to_string(cur));
        if ( sums % 3 ==0 ) ++ res;
        ++ cur;
    }
    cout << res;
    return 0;
}*/

/*#include<iostream>
using namespace std;
bool isDived(string val) {
    long long res = 0;
    for (char i : val) {
        res += i - '0';
    }
    return res % 3 == 0;
}

string generateNumber(long long order) {
    string rtn;
    for (int i = 1; i <= order; ++i) {
        rtn += to_string(i);
    }
    return rtn;
}
int main()
{
    long long  l, r;
    cin >> l >> r;
    long long res = 0;
    string t = generateNumber(l);
    if (isDived(t)) ++ res;
    long long cur = l + 1;
    while(cur <= r) {
        t += to_string(cur);
        if (isDived(t)) ++res;
        ++cur;
    }
    cout << res;
    return 0;
}*/
/*
#include<iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> charset;
    string cs[10][5];
    cs[0][1] = "66666";
    cs[0][2] = "6...6";
    cs[0][3] = "6...6";
    cs[0][4] = "6...6";
    cs[0][5] = "66666";

    for (int i = 1; i <=5; ++i) {
        cs[1][i] = "....6";
    }

    cs[2][1] = "66666";
    cs[2][2] = "....6";
    cs[2][3] = "66666";
    cs[2][4] = "6....";
    cs[2][5] = "66666";

    cs[3][1] = "66666";
    cs[3][2] = "....6";
    cs[3][3] = "66666";
    cs[3][4] = "....6";
    cs[3][5] = "66666";

    cs[4][1] = "6...6";
    cs[4][2] = "6...6";
    cs[4][3] = "66666";
    cs[4][4] = "....6";
    cs[4][5] = "....6";

    cs[5][1] = "66666";
    cs[5][2] = "6....";
    cs[5][3] = "66666";
    cs[5][4] = "....6";
    cs[5][1] = "66666";

    cs[6][1] = "66666";
    cs[6][2] = "6....";
    cs[6][3] = "66666";
    cs[6][4] = "6...6";
    cs[6][5] = "66666";

    cs[7][1] = "66666";
    cs[7][2] = "....6";
    cs[7][3] = "....6";
    cs[7][4] = "....6";
    cs[7][5] = "....6";

    cs[8][1] = "66666";
    cs[8][2] = "6...6";
    cs[8][3] = "66666";
    cs[8][4] = "6...6";
    cs[8][5] = "66666";

    cs[9][1] = "66666";
    cs[9][2] = "6...6";
    cs[9][3] = "66666";
    cs[9][4] = "....6";
    cs[9][5] = "66666";

    cs[10][5] = "..";
    cs[10][1] = "..";
    cs[10][2] = "..";
    cs[10][3] = "..";
    cs[10][4] = "..";

    int n;
    cin >> n;
    while (n--) {
        string str;
        getline(cin, str);
        long ret = getResult(str);
    }




    return 0;
}
*/

/*string getString(int v1, int v2){
    if (v1 > v2) return to_string(v1) + to_string(v2);
    else return to_string(v2) + to_string(v1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    set<string> res;
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] - vec[j] == k) res.insert(getString(vec[i], vec[j]));
            else if (vec[i] - vec[j] > k) break;
        }
    }
    cout << res.size();
    return 0;
}*/
/*
 * '0' - '9'
 * int main ()
{
    map<char, int> t;
    for (char i = '1'; i <= '9'; ++i) {
        t[i] = 0;
    }
    string str;
    cin >> str;
    int zero_cnt = 0;
    for (int j = 0; j < str.size(); ++j) {
        if (str[j] == '0') ++zero_cnt;
        else ++t[str[j]];
    }
    if (t.begin()->second == 0) {
        cout << t.begin()->first;
    }
    else {
        if (zero_cnt == 0) {
            cout << t.begin()->first << '0';
        } else {
            map<char, int>::iterator it = t.begin();
            for (map<char,int>::iterator j = t.begin(); j != t.end(); ++j) {
                it = it->second < j->second ? it : j;
            }
            for (int i = 0; i <= it->second; ++i) {
                cout << it->first;
            }
        }
    }
    return 0;
}*/
/*int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    int sum = 0;
    for (int i = 0; i <= s1.size() - s2.size(); ++i) {
        int length = 0;
        int cur = i;
        for (int j = 0; j < s2.size(); ++j) {
            if (s1[cur++] != s2[j]) ++length;
        }
        sum += length;
    }
    cout << sum << endl;
    return 0;
}*/
/*
 * QuickSort
 *
int __partition(vector<int> &vec, int l, int r)
{
    swap(vec[l], vec[random() % ( r - l + 1)  + l]);
    int  j = r;
    int val = vec[l];
    for (int cur = l + 1; cur <= j; ++cur)
    {
        if(vec[cur] > val) {
            swap(vec[cur], vec[j--]);
            --cur;
        }
    }
    swap(vec[j], vec[l]);
    return j;
}

vector<int> quickSort(vector<int> &vec, int l, int r)
{
    if ( l >= r)
        return vec;
    int p = __partition(vec, l , r);
    quickSort(vec, l, p - 1);
    quickSort(vec, p + 1, r);
    return vec;
}

int main(void)
{
    srand(time(NULL));
    vector<int> t{1,32,24,234,43,23,243,6,2,6,2,4643,2447,562,872};
    quickSort(t, 0, t.size() - 1);
    return 0;
}*/
/*
 * Permutation
 *
 * class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty())
            return vector<string> ();
        set<string> result;
        permute(std::move(str), 0, result);
        return vector<string>(result.begin(), result.end());
    }
    void permute(string str, int beg, set<string>& r)
    {
        if (beg >= str.size()){
            r.insert(str);
            return;
        }
        for (int i = beg; i < str.size(); ++i){
            swap(str[i], str[beg]);
            permute(str, beg + 1, r);
            swap(str[i], str[beg]);
        }
    }
};

int main(void)
{
    Solution solution;
    string t = "aa";
    vector<string> res = solution.Permutation(t);
    return 0;
}*/


/*
 *  Top k
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k || input.empty())
            return vector<int>();
        map<int, int> pq;
        for (auto i : input)
            pq[i]++;
        vector<int> rtrn;
        for (auto cur = pq.begin(); cur != pq.end() && k > 0; cur++)
        {
            for (int i = 0; i < cur->second && k > 0; ++i)
            {
                rtrn.push_back(cur->first);
                --k;
            }
        }
        return rtrn;
    }
};
int main(void)
{
    vector<int> i{4,5,1,6,2,7,3,8};
    Solution s;
    auto res = s.GetLeastNumbers_Solution(i, 4);
    return 0;
}*/
/*
#include<iostream>
#include<unistd.h>
using namespace std;
int main(int argc, char* argv[], char* envp[]) {
    cout << argc << endl;
    cout << "Conmmad line arguments:" << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    }
    cout << "Enviroment variables:" << endl;
    for (char **cur = envp; *cur != NULL; ++cur) {
        cout << "envp[" << (cur - envp) << "]:" << (*cur) << endl;
    }
    return 0;
}
*/

/*struct type
{
    int line1;
    int line2;
    long sum;
    bool operator <(const type& other) const
    {
        return this->sum < other.sum;
    }
    type(const vector<int>& a, const vector<int>& b, int line1, int line2)
    {
        this->line1 = line1;
        this->line2 = line2;
        long res = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            res += max(a[i], b[i]);
        }
        this->sum = res;
    }
};

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > val;
    int times = n;
    while(times--)
    {
        vector<int> temp;
        for (int i = 0; i < 5; ++i)
        {
            int power;
            cin >> power;
            temp.push_back(power);
        }
        val.push_back(temp);
    }

    vector<bool> visited(n, false);

    priority_queue<type> pq;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            type t(val[i], val[j], i, j);
            pq.push(t);
        }
    }
    int result = 0;
    for (int i = 0; i < k / 2; ++i)
    {
        while ( !pq.empty() )
        {
            type t = pq.top();
            if (!visited[t.line1] && !visited[t.line2])
            {
                result += t.sum;
                visited[t.line2] = true;
                visited[t.line1] = true;
                pq.pop();
                break;
            }
            pq.pop();
        }
    }
    cout << result;
    return 0;
}*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//    int coins, total_money;
//    cin >> coins >> total_money;
//    vector<int> values;
//    while (coins--)
//    {
//        int val;
//        cin >> val;
//        values.push_back(val);
//    }
//    sort(values.begin(), values.end());
//    int cnt = 0, result = 0;
//    for(vector<int>::iterator val = values.begin(); val != values.end() && cnt < total_money; ++val)
//    {
//        cnt += (*val);
//        result++;
//    }
//    for(vector<int>::iterator val = values.begin(); val != values.end() && cnt - (*val) >= total_money; ++val, --result)
//    {
//        cnt -= (*val);
//    }
//    cout << result;
//    return 0;
//}


//#include <vector>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <limits.h>
//#include <map>
//#include <fstream>
//#include <fcntl.h>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//    stack<int> t;
//    t.push
//    return 0;
//}

/** 请完成下面这个函数，实现题目要求的功能 **//*
*//** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **//*
int minLast(const vector<vector<int>>& costs, int row, int excludeIndex)
{
    int resIndex = costs[row].size() - 1 == excludeIndex ? excludeIndex - 1 : excludeIndex + 1;
    for (int i = 0; i < costs[row].size(); ++i) {
        if (excludeIndex != i) {
            resIndex = costs[row][i] < costs[row][resIndex] ? i : resIndex;
        }
    }
    return resIndex;
}
int minCost(vector<vector<int>>& costs)
{
    for (int i = 1; i < costs.size(); ++i) {
        for (int j = 0; j < costs[i].size(); ++j) {
            int min = minLast(costs, i - 1, j);
            costs[i][j] = costs[i - 1][min] + costs[i][j];
        }
    }
    sort(costs[costs.size() - 1].begin(), costs[costs.size() - 1].end());
    return costs[costs.size() - 1][0];
}
int main()
{
    int N,K;
    int cost;
    vector<vector<int> > costs;
    string s;
    istringstream is;

    getline(cin, s);
    is.str(s);
    is>>N>>K;
    for(int i =0 ; i < N; i++)
    {
        vector<int> t;
        getline(cin, s);
        is.clear();
        is.str(s);
        for(int j = 0; j < K; j++) {
            is >> cost;
            t.push_back(cost);
        }
        costs.push_back(t);
    }
    cout<<minCost(costs)<<endl;
    return 0;
}*/

/*
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C)
class Solution {
public:
    int Sum_Solution(int n) {
        int val = n;
        (n && (val += Sum_Solution(n - 1)));
        return val;
    }
};
*/

/*
 * 判断树2 是不是 树1 的子树.
 * struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL) return false;
        preTraverse(pRoot1, tree1, {pRoot2->val});
        preTraverse(pRoot2, tree2, {});
        for (auto index : indexes) {
            if(tree1.substr(index, tree2.size()) == tree2)
                return true;
        }
        return false;
    }

private:
    void preTraverse(TreeNode* root, string& characters,const initializer_list<int>& rootKey){
        if (root == NULL)
            return;
        if (rootKey.size()) {
            if (root->val == *rootKey.begin()) {
                indexes.push_back(characters.size()); // size 值为 val 的index, index 在后一句插入.
            }
        }
        characters += to_string(root->val);
        preTraverse(root->left, characters, rootKey);
        preTraverse(root->right, characters, rootKey);
    }
private:
    string tree1;
    string tree2;
    vector<size_t> indexes;
};
int main(void)
{
    TreeNode* pRoot1 = new TreeNode(1); pRoot1->left = new TreeNode(2); pRoot1->right = new TreeNode(3);
    pRoot1->left->left = new TreeNode(4); pRoot1->left->right = new TreeNode(5);

    TreeNode* pRoot2 = new TreeNode(2); pRoot2->left = new TreeNode(4); pRoot2->right = new TreeNode(5);

    Solution solution;
    bool res = solution.HasSubtree(pRoot1, pRoot2);
    cout << res << endl;
    return 0;
}*/

/*
 * 实现栈数据结构, 并可以获取最小值.
 *
 * class Solution {
public:
    void push(int value) {
        min_heap[value]++;
        values.push(value);
    }

    void pop() {
        int val = values.top();
        if (--min_heap[val] == 0) min_heap.erase(val);
        values.pop();
    }

    int top() {
        return values.top();
    }

    int min() {
        return (*min_heap.begin()).first;
    }

private:
    typedef int VALUE;
    typedef int TIME;
    map<VALUE, TIME> min_heap;
    stack<int> values;
};*/

/*
 * 顺时针打印矩阵
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        this->matrix = std::move(matrix);
        int startRow = 0, lastRow = this->matrix.size() - 1;
        int startCol = 0, lastCol = this->matrix[0].size() - 1;
        while (startRow <= lastRow && startCol <= lastCol) {
            printCircle(startCol, lastCol, startRow, lastRow);
            ++startCol, --lastCol, ++startRow, --lastRow;
        }
        return res;
    }

private:
    void printCircle(int startCol, int endCol, int startRow, int endRow) {
        for (int i = startCol; i <= endCol; ++i) res.push_back(matrix[startRow][i]);
        for (int j = startRow + 1; j <= endRow; ++j) res.push_back(matrix[j][endCol]);
        if (startRow != endRow)
            for (int k = endCol - 1; k >= startCol; --k) res.push_back(matrix[endRow][k]);
        if (startCol != endCol)
            for (int l = endRow - 1; l > startRow; --l) res.push_back(matrix[l][startCol]);
    }

private:
    vector<vector<int>> matrix;
    vector<int> res;
};
*/

/*
 * 归并两个有序链表，维持非递减序。
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode *res, *backup;
        if (pHead1 == nullptr) res = pHead2;
        if (pHead2 == nullptr) res = pHead1;
        res = new ListNode(USELESS_NUMBER);
        backup = res;
        while (pHead1 || pHead2) {
            if (pHead1 == nullptr) {
                this->gotoNext(pHead2, res);
                continue;
            }
            if (pHead2 == nullptr) {
                this->gotoNext(pHead1, res);
                continue;
            }
            if (pHead1->val <= pHead2->val) this->gotoNext(pHead1, res);
            else this->gotoNext(pHead2, res);
        }
        return backup->next;
    }

private:
    void gotoNext(ListNode *&pHead, ListNode *&res) {
        res->next = new ListNode(pHead->val);
        pHead = pHead->next;
        res = res->next;
    }
    const int USELESS_NUMBER = 0;
};
*/

/*
 * 反转链表
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr) return pHead;
        ListNode *last = nullptr, *cur = pHead;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};
*/

/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;
        vector<int> even;
        for (int num : array)
            if (num % 2) odd.push_back(num);
            else even.push_back(num);
        array.assign(odd.begin(), odd.end());
        for (auto num: even) array.push_back(num);
        return;
    }
};
*/

/*
 * 求 base 的 exponent 次方

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent < 0) base = 1 / base, exponent *= -1;
        if (exponent % 2) return base * Power(base * base, exponent / 2);
        else return Power(base * base, exponent / 2);
    }
};
*/

/*
 * 统计输入数字的二进制位数是多少, 负数是以补码表示
class Solution {
public:
    int  NumberOf1(int n) {
        int cnt = 0;
        if (n < 0) {
            n &= 0x7fffffff;
            ++cnt;
        }
        while (n) {
            cnt += n & 1;
            n = n >> 1;
        }
        return cnt;
    }
};
*/

/*
 * 矩形覆盖
class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int n_2 = 1, n_1 = 2;
        for (int i = 3; i <= number ; ++i) {
            int temp = n_2 + n_1;
            n_2 = n_1;
            n_1 = temp;
        }
        return n_1;
    }
};*/


/*
 * 重建二叉树
//  Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        this->pre_index = 0;
        root = nullptr;
        return reConstructBinaryTree(0, vin.size() - 1, pre, vin, root);
    }
    TreeNode* reConstructBinaryTree(int startIn, int endIn, const vector<int>& pre, const vector<int>& vin, TreeNode* &root){
        if(!root) root = new TreeNode(pre[this->pre_index]);

        int index = this->getInIndexByValue[ pre[this->pre_index] ];
        if (++this->pre_index >= pre.size()) return root;
        if (index - 1 - startIn >= 0) reConstructBinaryTree(startIn, index - 1, pre, vin, root->left);
        if (endIn - index - 1 >= 0) reConstructBinaryTree(index + 1, endIn, pre, vin, root->right);
        return root;
    }
private:
    void generateIndexMap(const vector<int>& vin){
        for(int i = 0; i < vin.size(); ++i){
            this->getInIndexByValue[vin[i]] = i;
        }
    }
private:
    typedef int INDEX;
    typedef int VALUE;
    TreeNode* root;
    map<VALUE, INDEX> getInIndexByValue;
    int pre_index;
};
*/
