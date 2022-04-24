# My Leetcode History
## Problem Pools
| Problem      | Difficulty |
| ------------ | ---------- |
| [1. Two Sum](Easy_problem/1.%20Two%20Sum)   | Easy       |
| [2. Add Two Numbers](Medium_problem/2.%20Add%20Two%20Numbers)    | Medium     |
| 3. Longest Substring Without Repeating Characters    | Medium     |
| [5. Longest Palindromic Substring](Medium_problem/5.%20Longest%20Palindromic%20Substring)   | Medium     |
| [6. Zigzag Conversion](Medium_problem/6.%20Zigzag%20Conversion)    | Medium     |
| 7. Reverse Integer   | Medium     |
| 9. Palindrome Number    | Medium     |
| 10. Regular Expression Matching    | Hard   |
| 11. Container With Most Water    | Medium     |
| 13. Roman to Integer    | Easy     |
| 19. Remove Nth Node From End of List    | Medium     |
| 20. Valid Parentheses    | Easy     |
| 21. Merge Two Sorted Lists    | Easy     |
| 26. Remove Duplicates from Sorted Array    | Easy     |
| 36. Valid Sudoku    | Medium     |
| 46. Permutations    | Medium     |
| 48. Rotate Image    | Medium     |
| 53. Maximum Subarray    | Easy     |
| 74. Search a 2D Matrix   | Medium     |
| 83. Remove Duplicates from Sorted List    | Easy     |
| 88. Merge Sorted Array    | Easy     |
| 94. Binary Tree Inorder Traversal    | Easy     |

## Shortest Path in Binary Matrix

```cpp=
class Solution {
public:
    struct path
    {
        int x, y;  
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0 || grid[grid.size()-1][grid[0].size()-1] != 0)return -1;
        else
        {
        vector<vector<int>> dis(grid.size()+2, vector<int> (grid[0].size()+2, 0));
        vector<vector<int>> dis2(grid.size()+2, vector<int> (grid[0].size()+2, 0));
        queue<path> pos;
        for(int i = 0; i < dis2.size(); i++)
        {
            for(int j = 0; j < dis2[0].size(); j++)
            {
                if(i == 0 || j == 0 || i == dis2.size()-1 || j == dis2[0].size()-1)
                {
                    dis2[i][j] = 1;
                    
                }
                else dis2[i][j] = grid[i-1][j-1];
                dis[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < dis2.size(); i++)
        {
            for(int j = 0; j < dis2[0].size(); j++)
            {
                cout<<dis2[i][j]<<" ";
            }
            cout<<endl;
        }
        int i = 1, j = 1;
        dis[1][1] = 1;
        pos.push({1, 1});
        while(pos.size() != 0)
        {
            i = pos.front().x;
            j = pos.front().y;
            pos.pop();
            if(dis2[i-1][j-1] == 0)
            {
 
                
                if(dis[i-1][j-1] > dis[i][j] + 1)
                {
                    dis[i-1][j-1] = dis[i][j] + 1;
                    pos.push({i-1, j-1});
                    
                }
            }
            if(dis2[i-1][j] == 0)
            {
                
                if(dis[i-1][j] > dis[i][j] + 1)
                {
                    dis[i-1][j] = dis[i][j] + 1;
                    pos.push({i-1, j});
                }
            }
            if(dis2[i-1][j+1] == 0)
            {
                
                if(dis[i-1][j+1] > dis[i][j] + 1)
                {
                    dis[i-1][j+1] = dis[i][j] + 1;
                    pos.push({i-1, j+1});
                }
            }
            if(dis2[i][j-1] == 0)
            {
                
                if(dis[i][j-1] > dis[i][j] + 1)
                {
                    dis[i][j-1] = dis[i][j] + 1;
                    pos.push({i, j-1});
                }
            }
            if(dis2[i][j+1] == 0 )
            {
                
                if(dis[i][j+1] > dis[i][j] + 1)
                {
                    dis[i][j+1] = dis[i][j] + 1;
                    pos.push({i, j+1});
                }
            }
            if(dis2[i+1][j-1] == 0 )
            {
                
                if(dis[i+1][j-1] > dis[i][j] + 1)
                {
                    dis[i+1][j-1] = dis[i][j] + 1;
                    pos.push({i+1, j-1});
                }
            }
            if(dis2[i+1][j] == 0 )
            {
                
                if(dis[i+1][j] > dis[i][j] + 1)
                {
                    dis[i+1][j] = dis[i][j] + 1;
                    pos.push({i+1, j});
                }
            }
            if(dis2[i+1][j+1] == 0)
            {
                if(dis[i+1][j+1] > dis[i][j] + 1)
                {
                    dis[i+1][j+1] = dis[i][j] + 1;
                    pos.push({i+1, j+1});
                }
            }
            
        }
        if(dis[grid.size()][grid[0].size()] == INT_MAX)return -1;
        else return dis[grid.size()][grid[0].size()];
        }
    }
};
```

---

## Number of Steps to Reduce a Number to Zero
```cpp=
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return num;
        if(num % 2 == 0) return 1 + numberOfSteps(num/2);
        else return 1 + numberOfSteps(num - 1);
    }
};
```


## Valid Anagram
```cpp=
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int *cha = new int[26];
        for(int i = 0; i < 26; i++)
        {
            cha[i] = 0;
        }
        for(int i = 0; i < s.size(); i++)
        {
            cha[(int)(s[i] - 'a')] ++;
            cha[(int)(t[i] - 'a')] --;
        }
        for(int i = 0; i < 26; i++)
        {
            if(cha[i] != 0) return false;
        }
        return true;
    }
};
```

---

## Copy List with Random Pointer
```cpp=
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans;
        unordered_map<Node*, Node*> m;
        if(head == NULL) return NULL;
        else
        {
            Node* temp = head;
            while(temp != NULL)
            {
                m[temp] = new Node(temp->val);
                temp = temp->next;
            }
            temp = head;
            while(temp != NULL)
            {
                m[temp]->next = m[temp->next];
                m[temp]->random = m[temp->random];
                temp = temp->next;
            }
            return m[head];
        }
    }
};
```
## Shortest Distance to a Character
```cpp=
class Solution {
public:
    struct info
    {
        int pos, f_size;  
    };
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        vector<info> all_size;
        int little_c = 1;
        bool first = true;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == c)
            {
                little_c --;
                all_size.push_back({i, little_c});
                little_c = 0;
            }
            little_c ++;
        }
        for(int i = 0; i < all_size.size(); i++)
        {
            int temp_size = all_size[i].f_size;
            for(int j = 0; j < all_size[i].f_size; j++)
            {
                if(first)
                {
                    ans.push_back(temp_size);
                    temp_size --;
                }       
                else
                {
                    if(temp_size > 1)
                    {

                        if((j + 1) <= (temp_size/2 + temp_size % 2))ans.push_back(j+1);
                        else ans.push_back(temp_size - j);
                    }
                    else
                    {
                        ans.push_back(1);
                    }
                    
                }
            }
            ans.push_back(0);
            first = false;
        }
        int all_dis = 0;
        for(int i = 0; i < all_size.size(); i++)
        {
            all_dis += all_size[i].f_size;
            all_dis ++;
        }
        all_dis = s.size() - all_dis;
        for(int i = 0; i < all_dis; i++)
        {
            ans.push_back(i + 1);
        }
        return ans;
    }
};
```
## Binary Tree Right Side View
```cpp=
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }

};
 
 
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q1;
        if(root)
        {
            q1.push(root);
            int queue_size = q1.size();
            while(q1.size() != 0)
            {
                for(int i = 0; i < queue_size; i++)
                {
                    TreeNode * node = q1.front();
                    q1.pop();
                    if( (i + 1) == queue_size )
                    {
                        ans.push_back(node->val);
                    }
                    if(node->left)
                    {
                        q1.push(node->left);
                    }
                    if(node->right)
                    {
                        q1.push(node->right);
                    }
                }
                queue_size = q1.size();
            }
            return ans;
        }
        else return {};
    }

};
```
## Remove Duplicates from Sorted Array
```cpp=
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int pos = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[pos] = nums[i];
                pos ++;
            }
        }
        return pos;
    }
};
```
## Delete Node in a Linked List
```cpp=
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node;
        p->val = p->next->val;
        p->next = p->next->next;  
    }
};
```
## Remove Nth Node From End of List
```cpp=
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; ++i) cur = cur->next;
        if (!cur) return head->next;
        //here is like total size minus n
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
```
## ZigZag Conversion
```cpp=
class Solution {
public:
    struct test
    {
        int x, y, z;
    };
    string convert(string s, int numRows) {
        vector<test> pos;
        string ans;
        bool now = false;
        int row = 0, col = 0, count = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(numRows == 1)
            {
                if(now)
                {
                    pos.push_back({row, col, i});
                    col ++;
                }
                else
                {
                    pos.push_back({row, col, i});
                    col ++;
                }
            }
            else
            {
                if(row == (numRows - 1) || row == 0) 
                {
                    now = !(now);
                }
                if(now)
                {
                    pos.push_back({row, col, i});
                    row ++;
                }
                else
                {
                    pos.push_back({row, col, i});
                    row --;
                    col ++;
                }
            }
        }
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < pos.size(); j++)
            {
                if(pos[j].x == i) ans.push_back(s[pos[j].z]);
            }
        }
        return ans;
    }
};
```
## Regular Expression Matching
```cpp=
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool s_match = ((!s.empty()) && (s[0] == p[0]) || (p[0] == '.'));
        if(p.size() >= 2 && p[1] == '*') 
        {
            return (isMatch(s, p.substr(2)) || s_match && (s.empty() ? false : isMatch(s.substr(1), p)));
        }
        else
        {
            return s_match && (s.empty() ? false : isMatch(s.substr(1), p.substr(1)));
        }
    }
};
```
## The K Weakest Rows in a Matrix
```cpp=
class Solution {
public:
    struct cus_pair
    {
        int x, y;
    };
    static bool comp(cus_pair s1, cus_pair s2)
    {
        return s1.y < s2.y;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<cus_pair> soldier;
        vector<int> a;
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(mat[i][j] != 1) 
                {
                    soldier.push_back({i, j});
                    break;
                }
                if(j == mat[i].size() - 1) soldier.push_back({i, j+1});
                
            }
        }
        stable_sort(soldier.begin(), soldier.begin() + soldier.size(), comp);
        for(int i = 0; i < k; i++)
        {
            a.push_back(soldier[i].x);
        }
        return a;
    }
};
```
## Short Encoding of Words
```cpp=
struct compare_first {
    bool operator()(const string &a1, const string &a2) const {
        int size = (a1.size() < a2.size()) ? a1.size() : a2.size();
        for(int i = 0; i < size; i++)
        {
            if(a1[i] != a2[i])
            {
                return a1[i] <= a2[i];
                break;
            }
        }
        cout<<a1<<" "<<a2;
        return a1.size() <= a2.size();
    }
};
// bool compare_first(string &a1,  string &a2)
// {
//     int size = (a1.size() < a2.size()) ? a1.size() : a2.size();
//     for(int i = 0; i < size; i++)
//     {
//         if(a1[i] != a2[i])
//         {
//             return a1[i] <= a2[i];
//             break;
//         }
//     }
//     cout<<a1<<" "<<a2;
//     return a1.size() <= a2.size();
// }
// struct compare_length {
//     bool operator()(const std::string &l, const std::string &r) const {
//         return l.size()<=r.size();
//     }
// };
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string temp_string = "";
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = words[i].size()-1; j>=0; j--)
            {
                temp_string += words[i][j];
            }
            words[i] = temp_string;
            temp_string = "";
        }
        string ans = "";
        stable_sort(words.begin(), words.end(), compare_first());
        words.push_back("");
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(words[i][j] != words[i+1][j])
                {
                    ans += words[i] + "#";
                    break;
                }
            }
        }
        cout<<ans<<endl;
        return ans.size();
    }
};
```
## Maximum Product of Word Lengths
```cpp=
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int cur_max = 0;
        int temp_max = 0;
        bool canDo = false;
        vector<set<int>> mask(words.size());
        for(int i = 0; i < words.size(); i++){
            for(char c: words[i]){
                mask[i].insert(c-'a');
            }   
        }
        for(int i = 0; i < words.size()-1; i++){
            for(int j = i+1; j < words.size(); j++){
                for(auto it = mask[j].begin(); it != mask[j].end(); it++){
                    if(mask[i].count(*it)){
                        canDo = true;
                        break;
                    }
                    else canDo = false;
                }
                if(!canDo){
                    temp_max = words[i].length()*words[j].length();
                    if(temp_max > cur_max)cur_max = temp_max;
                }
            }
        }
        return cur_max;
    }
};
```

## Rotate Image
```cpp=
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int row = 0; row < n/2; row++)
        {
            int cur_size = n - 2*row;

            for(int col = row; col < cur_size-1+row; col++)
            {
                swap(matrix[row][col], matrix[n-1-col][row]);
                swap(matrix[n-1-col][row], matrix[n-1-row][n-col-1]);
                swap(matrix[n-1-row][n-col-1], matrix[col][n-1-row]);
                cout<<"cur row: "<<row<<endl<<endl;
                for ( const auto &row : matrix )
                {
                    for ( const auto &s : row ) cout << s << ' ';
                    cout << std::endl;
                }
                cout<<endl<<endl;
            }

        }

    }
};
```

## Minimun Area Rectangle 2
```cpp=
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0.0;
        double res = DBL_MAX;
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long dist = getLength(points[i], points[j]);
                double centerX = (points[i][0] + points[j][0]) / 2.0;
                double centerY = (points[i][1] + points[j][1]) / 2.0;
                string key = to_string(dist) + "_" + to_string(centerX) + "_" + to_string(centerY);
                m[key].push_back({i, j});
            }
        }
        for (auto &a : m) {
            vector<vector<int>> vec = a.second;
            if (vec.size() < 2) continue;
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = i + 1; j < vec.size(); ++j) {
                    int p1 = vec[i][0], p2 = vec[j][0], p3 = vec[j][1];
                    double len1 = sqrt(getLength(points[p1], points[p2]));
                    double len2 = sqrt(getLength(points[p1], points[p3]));
                    res = min(res, len1 * len2);
                }
            }
        }
        return res == DBL_MAX ? 0.0 : res;
    }
    long getLength(vector<int>& pt1, vector<int>& pt2) {
        return (pt1[0] - pt2[0]) * (pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1]);
    }
};




#define distance(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int a, b, c, d; double w, l;
        double min_area = DBL_MAX, area;
        map<pair<int, int>, bool> m;
        
        for(vector<int> p : points)
            m[make_pair(p[0], p[1])] = true;
        
        for(a = 0;a < points.size() - 2;a++){
            for(b = a + 1;b < points.size() - 1;b++){
                for(c = b + 1;c < points.size();c++){
                    int x1, y1, x2, y2, x3, y3, x4, y4;
                    x1 = points[a][0]; y1 = points[a][1];
                    x2 = points[b][0]; y2 = points[b][1];
                    x3 = points[c][0]; y3 = points[c][1];
                    x4 = x2 + x3 - x1; y4 = y2 + y3 - y1;
                    
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                    if(m.find(make_pair(x4, y4)) == m.end()) continue;
                    w = distance(x4, y4, x2, y2);
                    l = distance(x4, y4, x3, y3);
                    area = w * l;
                    if(min_area > area) min_area = area;
                }
            }
        }
        return min_area == DBL_MAX ? 0.0 : min_area;
    }
};


class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) 
    {
        map<pair<int, int>, bool> point_dict;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        double min_area = DBL_MAX;
        double temp_area;
        for(const auto row: points)
        {
            point_dict[make_pair(row[0], row[1])] = true;
        }
        for(int p1 = 0; p1 < points.size()-2; p1++)
        {
            for(int p2 = p1+1; p2 < points.size()-1; p2++)
            {
                for(int p3 = p2+1; p3 < points.size(); p3++)
                {
                    x1 = points[p1][0]; y1 = points[p1][1];
                    x2 = points[p2][0]; y2 = points[p2][1];
                    x3 = points[p3][0]; y3 = points[p3][1];
                    x4 = x3 + x2 - x1; y4 = y3 + y2 - y1;
                    if(point_dict.find(make_pair(x4, y4)) != point_dict.end())
                    {
                        if(((x1-x2) * (x1-x3) + (y1-y2) * (y1-y3)) == 0)
                        {
                            temp_area = get_distance(x1, y1, x2, y2)*get_distance(x1, y1, x3, y3);
                            if(temp_area <= min_area)
                            {
                                min_area = temp_area;
                            }
                        }
                    }
                    
                }
            }
        }
        return (min_area == DBL_MAX)?0:min_area;
        
    }
    double get_distance(int x1, int y1, int x2, int y2)
    {
        return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    }
};
```

## Subdomain Visit Count
```cpp=

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        unordered_map<string, int> counts;
        for(const auto str: cpdomains)
        {
            size_t index = str.find(" ");
            int times = stoi(str.substr(0, index));
            string domain_name = str.substr(index+1);
            while(true)
            {
                counts[domain_name] += times;
                size_t d_index = domain_name.find('.');
                if(d_index == string::npos)break;
                domain_name = domain_name.substr(d_index+1);
            }
        }
        vector<string> ans;
        for(const auto data: counts)
        {   
            ans.push_back(to_string(data.second) + ' ' + data.first);
        }
        return ans;
    }
};
```

## Number of Islands
```cpp=

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, j, i, m, n);
                    ans ++;
                }
            }
        }
        
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n)
    {
        if(x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '0') return;
        grid[y][x] = '0';
        dfs(grid, x-1, y, m, n);
        dfs(grid, x+1, y, m, n);
        dfs(grid, x, y-1, m, n);
        dfs(grid, x, y+1, m, n);
    }
};
```

## Reduction Operations to Make the Array Elements Equal
```cpp=
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur_count = 0;
        int ans = 0;
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(res != nums[i])
            {
                cur_count ++;
                res = nums[i];
            }
            ans += cur_count;
            
        }
        return ans;
    }
};
```

## Flood Fill
```cpp=
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old_color = image[sr][sc];   
        dfs(image, sr, sc, -1, old_color);
        for(int i = 0; i < image.size(); i++)
            for(int j = 0; j < image[0].size(); j++)
                if(image[i][j] == -1) image[i][j] = newColor;
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor)
    {
        if(i < 0 || j < 0 || i >= image.size()|| j >= image[0].size()) return;
        else
        {
            if(image[i][j] == oldColor) 
            {
                image[i][j] = newColor;
                dfs(image, i-1, j, newColor, oldColor);
                dfs(image, i+1, j, newColor, oldColor);
                dfs(image, i, j-1, newColor, oldColor);
                dfs(image, i, j+1, newColor, oldColor);
            }
        }

    }
};
```

##  Detect Cycles in 2D Grid
```cpp=
class Solution {
    public:
    bool containsCycle(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(visited[i][j])continue;
                if(has_cycle(make_pair(-1, -1), i, j, grid[i][j], visited, grid))return true;
            }
        return false;
    }
    bool has_cycle(pair<int, int> prev, int i, int j, char match_val, vector<vector<int>> &visited, vector<vector<char>>& grid){
        vector<pair<int,int>> dir = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
        visited[i][j] = 1;
        for(const auto &m: dir){
            int x = i + m.first;
            int y = j + m.second;
            if(x<0||y<0||x>=grid.size()||y>=grid[0].size())continue;
            if(x == prev.first && y == prev.second)continue;
            if(grid[x][y]!=match_val)continue;
            if(visited[x][y])return true;
            if(has_cycle(make_pair(i, j), x, y, match_val, visited, grid))return true;
        }
        return false;
    }

};
```

## Minimum Time Difference
```cpp=
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_map<string, int> check;
        int min_minute = INT_MAX;
        int cur_minute;
        int temp = -1;
        int dis;
        vector<int> time_list;
        for(const auto & time: timePoints)
        {
            if(check[time])check[time]++;
            else check[time] = 1;
            cur_minute = stoi(time.substr(0, 2))*60+stoi(time.substr(3, 5));
            time_list.push_back(cur_minute);
            time_list.push_back(cur_minute+1440);
        }
        sort(time_list.begin(), time_list.end());
        for(const auto & time:time_list){
            cur_minute = time;
            if(temp != -1)
            {
                if(temp>=cur_minute) dis = temp-cur_minute;
                else dis = cur_minute-temp;
            }
            temp = cur_minute;
            if(temp != -1 && dis <= min_minute) min_minute = dis;
        }
        for(int i = 0; i < timePoints.size(); i++){
            if(check[timePoints[i]]>=2) {
                min_minute = 0;
            }
        }
        cout<<"hi";
        return min_minute;
    }
};
```

### backtracking 演算法
![](https://i.imgur.com/aLEZl78.png)

## 46. Permutations
```cpp=
// version 1
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> ans;
        permuteDFS(num, 0, ans);
        return ans;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& ans) {
        if (start >= num.size()) ans.push_back(num);
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, ans);
            swap(num[start], num[i]);
        }
    }
};

// version 2
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> viewed(nums.size(), false);
        backtracking(nums, ans, temp, viewed);
        return ans;
        
    }
    void backtracking(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &viewed){
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(viewed[i]) continue;
            temp.push_back(nums[i]);
            viewed[i] = true;
            backtracking(nums, ans, temp, viewed);
            temp.pop_back();
            viewed[i] = false;
        }
    }
};
```

## 338. Counting Bits
```cpp=
class Solution {
public:
    vector<int> countBits(int n) {
        int a1, bin_n;
        vector<int> ans;
        for(int i = 0; i <= n; i++)
        {
            a1 = i;
            bin_n = 0;
            while(a1>0)
            {
                if(a1)
                {
                    bin_n += a1 % 2;
                    a1 /= 2;
                }
            }
            ans.push_back(bin_n);
        }
        return ans;
    }
};
```

## 53. Maximum Subarray
```cpp=
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum1 = 0;
        int maxi_sub = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum1 += nums[i];
            if(maxi_sub < sum1) maxi_sub = sum1;
            if(sum1 < 0){
                sum1 = 0;
                continue;
            }
        }
        return maxi_sub;
    }
};
```

## 217. Contains Duplicate
```cpp=
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> test_valid;
        bool ans = false;
        for(int i = 0; i < nums.size(); i++){
            if(test_valid[nums[i]]){
                ans = true;
                break;
            }
            else test_valid[nums[i]] = true;
        }
        return ans;
    }
};
```
## 1. Two Sum
```cpp=
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        int left;
        for(int i = 0; i < nums.size(); i++){
            index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            left = target-nums[i];
            if(index.count(left)&&index[left]!=i)return {i, index[left]};
        }
        return {};
    }
};
```
## 36. Valid Sudoku
```cpp=
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int start, end;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.'){
                    unordered_map<int, int> checkRow, checkCol, checkBox;
                    for(int z = 0; z < 9; z++){
                        if(board[i][z]!='.'){
                            if(checkRow[board[i][z]]) {
                                cout<<i<<" "<<j<<" "<<i<<" "<<z<<endl;
                                return false;
                            }
                            else checkRow[board[i][z]] = 1;     
                        }
                    }
                    for(int z = 0; z < 9; z++){
                        if(board[z][j]!='.'){
                            if(checkCol[board[z][j]]) return false;
                            else checkCol[board[z][j]] = 1;     
                        }
                    }
                    start = i - (i%3);
                    end = j - (j%3);
                    for(int z = start; z <= start+2; z++){
                        for(int x = end; x <= end+2; x++){
                            if(board[z][x]!='.'){

                                if(checkBox[board[z][x]]){
                                    
                                    return false;
                                }
                                else checkBox[board[z][x]] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
```
## 74. Search a 2D Matrix
```cpp=
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0;
        while(true){
            if(row >= m) {
                row--;
                break;
            }
            if(target <= matrix[row][n-1]) break;
            else row++;
        }
        for(int i = matrix[0].size()-1; i>=0; i--){
            if(target == matrix[row][i]) return true;
        }
        return false;
    }
};
```
## 387. First Unique Character in a String
```cpp=
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]]){
                m[s[i]]++;
            }
            else{
                m[s[i]] = 1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
```

## 141. Linked List Cycle
```cpp=
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> m;
        while(head){
            if(m[head] == 1){
                return true;
            }
            else m[head] = 1;
            head = head->next;
        }
        return false;
    }
};
```
## 208. Implement Trie (Prefix Tree) --JAVA
```java=
class Trie {
    private Node[] root;
    public Trie() {
        root = new Node[26];
    }
    
    public void insert(String word) {
        Node node = null;
        for(int i = 0; i < word.length(); i++){
            char ch = word.charAt(i);
            int index = ch - 'a';
            if(i == 0){
                if(null == root[index]){
                    root[index] = new Node(ch, false);
                }
                node = root[index];
            }
            else{
                if(null == node.children[index]){
                    node.children[index] = new Node(ch, false);
                }
                node = node.children[index];
            }
            if(i == word.length()-1){
                node.isend = true;
            }
        }
    }
    
    public boolean search(String word) {
        Node node = null;
        for(int i = 0; i < word.length(); i++){
            char ch = word.charAt(i);
            int index = ch - 'a';
            if(i == 0){
                if(root[index] == null){
                    return false;
                }
                node = root[index];
            }
            else{
                if(node.children[index] == null){
                    return false;
                }
                node = node.children[index];
            }
        }
        return node.isend;
    }
    
    public boolean startsWith(String prefix) {
        Node node = null;
        for(int i = 0; i < prefix.length(); i++){
            char ch = prefix.charAt(i);
            int index = ch - 'a';
            if(i == 0){
                if(root[index] == null){
                    return false;
                }
                node = root[index];
            }
            else{
                if(node.children[index] == null){
                    return false;
                }
                node = node.children[index];
            }
        }
        return true;
    }
}
public class Node{
    public char ch;
    public boolean isend;
    public Node[] children;
    public Node(char ch, boolean isend){
        this.ch = ch;
        this.isend = isend;
        this.children = new Node[26];
    }
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */

```




## 720. Longest Word in Dictionary
```cpp=
class Solution {
public:
    string longestWord(vector<string>& words) {
        string best;        
        unordered_set<string> dict(words.begin(), words.end());
        
        for (const string& word : words) {
            if (word.length() < best.length() 
             || (word.length() == best.length() && word > best)) 
                continue;
            string prefix;
            bool valid = true;
            for (int i = 0; i < word.length() - 1 && valid; ++i) {
                prefix += word[i];
                if (!dict.count(prefix)) valid = false;
            }
            if (valid) best = word;
        }
        
        return best;
    }
};
```

## 234. Palindrome Linked List
```cpp=
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        slow = reverse(slow);
        while (slow) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
  }
private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
  }
};
```

## 1261. Find Elements in a Contaminated Binary Tree
```cpp=
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    TreeNode* root1;
    FindElements(TreeNode* root) {
        this->root1 = root;
        traversal_tree(root);
    }
    void traversal_tree(TreeNode* root){
        if(root){
            if(root->val == -1) root->val = 0;
            if(root->left) root->left->val = root->val*2 + 1;
            traversal_tree(root->left);
            if(root->right) root->right->val = root->val*2 + 2;
            traversal_tree(root->right);
        }
    }
    bool search_tree(int num, TreeNode* root){
        if(!root) return false;
        else{
            if(root->val == num) return true;
            if(search_tree(num, root->left)) return true;
            if(search_tree(num, root->right)) return true;       
            return false;
        }
    }
    bool find(int target) {
        return search_tree(target, this->root1);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```
## 731. My Calendar II
```cpp=
// solution 1
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for(const auto& val: overlap){
            if(max(start, val.first) < min(end, val.second)) return false;
        }
        for(const auto& val: booked){
            int ss = max(start, val.first);
            int ee = min(end, val.second);
            if(ss < ee) overlap.emplace_back(make_pair(ss, ee));
        }
        booked.emplace_back(make_pair(start, end));
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlap;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// solution2
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        ++delta_[start];
        --delta_[end];
        int count = 0;
        for (const auto& kv : delta_) {
            count += kv.second;
            if (count == 3) {
                --delta_[start];
                ++delta_[end];
                return false;
            }
            // 這個區間[start, end) 有幾個人是實心的
            if (kv.first > end){
                break;
            }
        }
        return true;
    }
private:
    map<int, int> delta_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```

## 104. Maximum Depth of Binary Tree
```cpp
// solution 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root){
            count++;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
        else return 0;

    }
private:
    int count = 0;
};

// solution 2
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }
};
```

## 13. Roman to Integer
```cpp=
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> my_dict;
        my_dict['I'] = 1;
        my_dict['V'] = 5;
        my_dict['X'] = 10;
        my_dict['L'] = 50;
        my_dict['C'] = 100;
        my_dict['D'] = 500;
        my_dict['M'] = 1000;
        int ans = 0;
        int n = s.length() - 1;
        int prev = -1;
        for(int i = n; i >= 0; i--){
            if(i == n) {
                ans += my_dict[s[i]];
                prev = my_dict[s[i]];
            }
            else{
                if(my_dict[s[i]] >= prev){
                    ans += my_dict[s[i]];
                    prev = my_dict[s[i]];
                }
                else{
                    ans -= my_dict[s[i]];
                    prev = my_dict[s[i]];
                }
            }
        }
        return ans;
    }
};
```
