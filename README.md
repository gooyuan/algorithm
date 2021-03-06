# algorithm

## question list

### Container with most water

1. 这个算法, 今天一下子就搞明白了, 按水的流动来理解
2. 加深了暴力枚举的作用的认识

### 3sum

1. 跟container with most water 有类似的思想, 枚举是过不了关的
2. 还未通关, 去除重复有点麻烦

### power(x, n)
1. 递归与循环是可以互换的
2. 位运算
3. for循环是搞不定的

### remove k digits
1. 

### design circular queue
1. 

### cheapest flight within k stops
1. Dijkstra 
- 思路:
    1. 必须有一个起点, 初始化起点到各个城市的花费
    2. 将此城市可到达的城市都放在一个队列里待搜索
    3. 以队列中的城市为起点, 再次编历整个数组, 更新可到达城市的最小花费, 然后将可到达城市再次加入队列
    4. 临界条件, stops == K站的时候, 只比较可到达目的地的站点, 更新目的地的值, 此临界已经不会再向队列中加入城市, 所以是最后一次搜索
        * 问题: 在K站以内, 理论上直达要比多站买票便宜, 直达票在第一次比较中就已经初淘汰了, 怎么办
        * 直达票每有被淘汰, 而是优化更新在了目的地中, 等到中转到目的地, 再比较, 所以不会丢掉值 

- 贪心算法
- 图
    * 图有什么性质
    * 松弛操作

- BFS, DFS, BF
    * Broad First Search
    * Deep First Search
    * Binary Find
- Dijkstra 是复用了广度优先搜索, 优化版本是在缓冲 queue上, 有queue, priorityQueue, Fibonacci heap

2. Bellman
- 松弛操作
    * 实际上是对相邻节点的访问
    * 第n次松弛操作保证了所有尝试为n的路径最短, 由于图的最短路径不会超过 n-1, 可知算法没最短路径
- 负边权操作
- 负权环判定
    * 负权环可以无限制地降低总花费, 所以 发现第n次操作仍可降低花销, 就一定存在负权环
- 优化
    * 循环提前跳出, 当某次循环不再松弛时, 直接退出循环, 进入负权环的判定
    * 队列记录松弛过的点

### Traingle
1. 思路
- 广度优先搜索， 遍历出每一条路径的最小值
2. 实现
- 确实实现了， 还是需要调试信息才可， 直接记事本写代码， 人脑调试有些难度

### Perfect Squares
0. 描述

    给定一个正整数, 找到最少的平方数(1,4,9,16...)和的个数

        example：

        input: 13
        export: 2
        explain: 13 = 4 + 9
     
        input: 12
        export: 3
        explain: 12 = 4 + 4 + 4
- 思路
    1. 数学理论: Legendre's three-square theorem <br>
    一个整数可以分解成 4\*k(8\*m + 7)的形式， 就一定是4个完美平方数之和, 如果不能分解成， 再判断 n-i*i 是不是平方数， 如果是， 答案就2, 如果不是，答案就是3

    数学方法更高效， 也更难一些， 最主要的方法还是要学会计算机思维的算法， 才可能解决更普遍的问题
    2. 动态规划: 一直不得其法<br>
        特点: 下一步的决策依赖已经产生的结果，再具有纠错能力,就是回溯算法<br>
        有一个数组专门记录状态？迷宫问题也是如此, 所以迷宫也是DP问题<br>
        那又是如何得出来dp(n) = Min{dp[n - i*i] + 1} 的？ <br>
        一个数拆解为平方数的思路： 先找到范围内最大的平方数 i*i, 再拆解剩下的数, n - i*i, n - i*i在dp[] 中已经记录， 而 dp(1), dp(2), dp(3) 是显然已知的, 因此可得第n个数的完美平方数个数为 Min{dp[n - i*i] + 1}, 因此也可证明数学问题
    3. 广度优先搜索: Breadth-First Search

- 实现

### Valid Parethensis String

0. 描述
    给定一个字符串， 只包含三种字符 '(', ')', '*' <br>
    '*' 可以匹配空字符，'(', ')'， <br> 
    () 成对匹配， 字符串为true

    example:

        input: "()"
        output: "true"

        input: "(*"
        output: true

        input: "(*))"
        output: true

- 思路
    使用堆栈思想, 使用计数器模拟, 不用计 *, 同时讲左(右)

- 实现

    `(())((())()()(*)(*()(())())())()()((()())((()))(*`

    method 1:<br>
    一次循环能记录多条分支结果:
    (: right++，需要等到循环结束， 查看left 是否为零，才能判断是否有分支满足
    '*': do nothing, 不用作判断
    ')': left--, 如果在实际的')'的匹配过程中，right < 0 了， 说明此分支终结

    method 2: </br>
    分别遍历两次， 先将`*`当成 ( 处理, 如果此是时 balence == 0 ， 说明合法
    再将 * 当成')'处理， 最终结果是 bal == 0, 说明合法, 这个思想是将上面的实现拆分

### Maximum Frequency Stack
- 描述
    设计一个可以存入， 弹出栈中最多个数的值
- 思路

    Map<Integer, Integer> 用来存放值与频率
    Map<Integer, Stack<Integer>> 存放频点与对应数值为该频点时出现的时机, 真妙
    在存入的时候，更新当前最大频点, 频点是线性增加的， 步长为1

    因此在pop的时候, 当前频点的stack.empty()时， 最大频点更新减1

### Pascal's Triangle
- 描述
    杨辉三角，刷一刷， 凑个数吧, 一天一道easy， 一道medium
- 思路
    边界问题的判断
    看看最高效的算法

### Maximum length of Pair Chain
- 描述

    给一个数组对集合， 每个数组对[a,b]都满足 a`<`b, 现规定数组对[a,b], [c,d]， 当且仅当 b`<`c时， 才可以组成一个链, 求这个集合中最大的链的长度. 不可能使用得上所有的集合数据， You can select pairs in any order(可的将集合排序)

- 思路
    1. 先将数组对排序， 按左数需要降序， 右数需升序
    2. 如果是以左数排序， 比对右数, 记录当前最小的左数
    3. if(curStart `>` pairs[i][1])为更新长度条件

### Subarrays with K Different Integers
- 描述
    > 一个非负的数组(连续可重复) A, 给定一个K, 由K 个连续且不同的数字组成的子数组， 称为good subarray, 求数组 A 的good subarrary 个数
    子数组中的数字为为原数组连续且可重复的， k 只是要求组组中的不同数字的个数

        example:
        input: [1,2,1,2,3], k=2
        output: 7
        explanation: [1,2] [2,1] [1,2] [2,3] [1,2,1] [2,1,2] [1,2,1,2]

        input: [1,2,1,3,4] k=3
        output: 3
        explanation: [1,2,1,3]  [2,1,3] [1,3,4] 

- 思路
    > 理解题设， 有点难度， 
    slide window, 好像是做过类似的题, 关键的点是连续，不同， 所以才可以使用slide window
    虽然是一个hard难度的题， 但是这两天的表现也有些太搓了。难吗？ 代码量并不大， 就是思维想不到那一层面。而且没有立下目标， 想着一天刷着一道题就够了， 这样容易产生惰性。要考虑的事情很多。 

    这样的问题， 该从什么方向考虑呢？ 
    总结人脑去查找的过程， 这是所有的算法最根本之道。 
    再者，看着别人的答案， 从过程来推理， 刷得多了， 有创新能力。 
    猜测， 那些第一次想到这些算法的人， 有些算法肯定不是说真得就几分钟就搞定了，那也是有相着领域的长时间浸淫, 这一点也毋庸置疑, 也无须再怀疑， 就算是靠天赋， 我也只能靠这一种方式去习得了。

    按人脑思路去思考: O(nlogn) <br>
    1. 两个指针l, r, 使用while循环，动态更新l,r,  使用map 缓存每个数出现的次数， 同时map 的大小可以标识当前的window中different integer 的个数
    2. 当map.size() `>` K 时， l++， 重置r = l, map.clear()
    3. r++ 从l 开始遍历，当r == A.length - 1 时， l++, 重置r=l, map.clear(), 开始新一轮的遍历
    4. 当l `>` A.length - K 时， 整个查找结束。这相当于穷举法

    slide window, 如果只用数组来缓存， 每个数字重复的次数与K来限制循环， 再加上数学证明，可以将算法优化到 O(n) 
    1. 使用count 记录slide window 中的 Different Integer 个数, 使用prefix 记录上一次window中的 good subarray 个数， 在`count > K`时清零进行下一次window统计, 使用res记录总结果, l,r为左右指针 
    2.  统计`s[A[l++]]>1` 每重复一次，就多一种可能 ，这里使用l++ 是因为要subarray need continus, 统计A[l] 在slide window中的个数， 有多少个， 当前window的结果就+1, 
    3. count == K 时， 统计res
    4. 由于l, r 可以并行统计， 所以可以将两层循环放在一层

### Longest Substring without Repeating Characters
- 描述
    统计一个字符串中最大不重复子串
- 思路
    这个思想是只需要更新重复字母的最大索引值即可

### 4Sum
- 描述
    给定一个数组，和一个target值， 找出数组出所有不重复的quadruplet(四元组)
- 思路
    遍历法， 遍历前两个数， 后面两个数使用首尾指针, 可简化成 2Sum问题了

### Remove Nth Node From End of List
- 描述

    给定一个链表， 从链尾开始删除第N个元素，返回链表头
- 思路
 
    先遍历一次求出链表长度， 再遍历一次， 根据索引找出待删除的node <br>
    或者 先翻转一次链表， 再遍历出第N个元素，顺便再翻转一次链表

### Rotate List
- 描述
    有一个链表， 给定一个非负数k, 从尾部开始执行k次， 翻转k个元素， k 可为0, 也可大于链表长度
    > example:
    > input: 1->2->3->4->5      2
    > output: 4->5->1->2->3
- 思路
    1. 先求出链表大小，将 k = k % size 去除重复的翻转
    2. 翻转k个元素， 等价转化为 从尾部开始，将第k个元素到尾部的所有元素移到链表前
    3. 遍历将 i + k = size 的元素作为newHead，newHead.next = head, last = null;
    4. 注意临界， k = n * size 或 k==1;

### Sort Colors
- 描述
    给定一个数组， 元素为 0,1,2 分别代表 red, green, blue, 将相同的颜色排在一起， 不能使用已有的库排序方法
    > example:
    > input: [0,1,2,2,1,0]
    > output: [0,0,1,1,2,2,]
- 思路
    这里有无素仅为0,1,2 就可以使用一个buf[3] 来计数， 然后依个数依次重写入原数组nums, 应该是值排序算法了
    看着取巧， 后面再找时间， 总结一下八大排序算法

### Remove Duplicates from Sorted Array
- 描述
    easy:
        给定一个排序的数组， 移除掉相同的元素， 保证数组元素唯一， 要求memory开销为O(1)
    medium:
        给定一个排序的数组，允许数组中元素最多有两个相同， 要求memory开销为O(1)
- 思路
    easy:
        因为是已排序好的，比较简单， 使用一个count 记录当前不重复元素索引， 两层循环，外层遍历， 内层查找， 直接按nums[count]赋值即可
    medium:
        在easy的基础上， 内层循环判断不重复的元素索引 `j>i+1`, 说明至少有一个重复的，此时将count数再填入, 注意判断边界最后一个数`j == len -1`相等的情况, 更新`nums[count], count, i = j`

### Linked List Cycle II
- 描述

    判断一个链表从哪个节点开始进入循环，如果没有循环， return null
- 思路
    快慢法， 可判断是否有循环，可求出结点位置吗？ 还是要解方程，取特殊值, 数学方法证明之
    相遇时, 经历了k步, 快的距离 2k, 慢的距离k, 设循环长度为r, 起始点距离为s, 相遇点到s 点距离为m
    可知， `2k - k = n * r => k = nr,  k - s = m => s = nr - m`, 因为n是循环次数，多少次都不影响结果，
    故取n=1, 得知 s = r - m，所以慢节点从起点出发， 快节点从相遇点出发， 都以步长为1进行， 再次相遇点即为循环起始点

### Minimum Size Subarray Sum
- 描述
    有n个正整数的数组， 给定一个正整数s, 找出最小长度的连续元素子数组满足所有元素之和`>=s`
- 思路
    1. 最简单的就是两层循环遍历， 当然也是效率最低的
    2. 有O(n), O(logn)算法, 
        两个指针， 
        先更新right, sum+=nums[right];
        当`sum >= s`时，再更新left, sum -= nums[left]; 
        此时以 `sum >= s` 为条件， 更新minLen，
        遍历完， 注意`sum < s`````的临界条件

### Kth Smallest Element in a Sorted Matrix
- 描述
    有一个`n*n`的二维矩阵， 每行和每列都各自按升序排列， 找到第k个最小的元素

    > example:

        input:[
            [1, 5, 9],
            [10, 11, 13],
            [12, 13, 15],
            ]
            8 
        output:
            13

        input:[
            [1,2,10,20],
            [3,5,11,25],
            [4,8,15,26],
            [5,10,16,28]
        ]
        9
- 思路
    每行和每列按升序排列， 并不是整个矩阵的各个元素按升序排列<br>
    首先想到的解法是给整个二维数组排序，再直接输出`matrix[k/n][k%n-1]` <br>
    每行每列已经排序了， 肯定不用整体排序就可以有利用的信息, 
    `matrix[k/n][k%n-1]只会与matrix[k/n -1][k%n] ~ matrix[k/n-1][n-1]`之间有乱序, 
    而本身`matrix[k/n-1][k%n] ~ matrix[k/n-1][n]`又是升序,  还是只能确定在`matrix[k/n][k%n-1]~`后的元素不用再进行排序， 在此之前的元素都得再排一次序
    而排序， 可以将所有元素放在`buf[n*n]`, 中使用Arrays.sort()排序，这样的效率要低一些，因为会将所有元素排序
    使用堆排序，PriorityQueue, 内部实现何用堆， 这个集合还是用得少。这样的效率是`O(n*logn*logn)`
    BinarySearch, 这个解法也很妙，排序的matrix可以得到最大值最小值，之前了解的二分法是从index上二分， 这里可以从值上二分来查找目标值， 复杂度是nlogn

### Find K Pairs with Smallest Sums
- 描述
    有两个排序的数组 nums1, nums2, 各从每个数组中取出一个元素组成数对(u,v), 求这些数对前K个最小和(u+v)的数对

- 思路
    可以使用最小堆， 对PriorityQueue 的使用

### Find Minimum in Rotated Sorted Array
- 描述
    有一个排序数组， 以某个轴(不知道在哪里)旋转，找出最小元素
    > example:

        [0,1,2,3,4] -> [2,3,4,0,1]
- 思路
    还不明了经过几次旋转， 如果只是一个轴， 那么只需要找到小于的那一个数即可, 也可以采用two pointer 来比较 
    如果是多个轴, 那么就只能再排序了, 确定了是只是一个轴旋转， 那也太简单了点... O(n/2)

    最原始的再排序也可以解决问题

### Find the Duplicate Number
- 描述
    有一个n+1的数组， 元素范围为 1～n， 有仅仅有一个重复的元素，但是一个元素可以重复多次, 找到这个元素 
- 思路
    这个可以采用数值当作索引的方式， 链表遍历， 遇到重复元素，肯定会再次回去，走过的地方置个标记, 但是这样会走进循环,  如果先排序， 那么也好解决了

### Max Consecutive Ones III
- 描述

    有一个只包含0, 1 的数组，给定一个k, 意味可以将k个0变成1, 找出转换后， 最长连续为1的子序列长度
- 思路
    比赛题， 刚好是two pointer的应用， 搞定它
    两个指针， faster 遇到0为变1， 直到k = 0, 然后slower遇到0, K+=1, 直到遇到0, 再前进faster
    实现起来不容易， 但是看别人的答案， 又是那么容易。。。
    看优秀解法， 豁然开朗，使用一个变量记录faster 遇到的0, count++, 当count > K 时， 再更新slower位置， 遇到A[s] == 0, count--;
    每一次统计长度 f - s + 1;

### Find Common Characters
- 描述
    有一个只有小写字母组成的数组A, 找到每个单词共有的字母（包括重复的字母)

    > example

        input: ["bella", "label", "roller"]
        output: ["e", "l", "l"]

        input: ["cool", "lock", "cook"]
        output: ["c", "o"]

- 思路
    使用空间换时间， 实现为O(n), 本来可使用Map, 在字母的情况下， 只需要使用buf[26][A.length] 大小的数组即可
    其他解法也大同小异

## Tree
### 1. 二叉树， 二叉查找树, 二叉树的插入， 删除， 查找操作
    - 空树
    - 左子树为空
    - 右子树为空
    - 左右子树都不为空

### 2. 平衡树, 旋转
    - AVL
    - Treap
    - 伸展树
    - 红黑树
    - 加权平衡树
    - 2-3树
    - AA树
    - 替罪羊树

### 3. 树的遍历
    - 深度优先
        前序 
        中序 
        后序
        真正的遍历还是按照root -> left -> right的顺序来, 根据处理数据的时机来分遍历顺序 
        在访问root时处理节点， 为中序
        在访问left时处理节点， 为先序
        在访问right时处理节点， 为后序
    - 广度优先
        只有唯一一种访问方式

### Unique Binary Search Tree II
- 描述
    输入一个数n, 生成所有的 BSTs用来存储1...n 
- 思路

    分治思想， 如汉诺塔思想一样， 递归的形式， 将复杂问题分解成单位可解问题

    BST:
        1. 若任意节点的左子树不为空， 则左子树上的所有节点的值均小于它的根节点的值
        2. 若任意节点的右子树不为空， 则右子树上的所有节点的值均小于它的根节点的值
        3. 任意节眯的左右子树分别为二叉树
        4. 没有键值相等的节点

    对于递归的思想， 还是有些懵，宏观考虑<br>
    n 个数组成的所有的树， 1...n 每个数都可以作为root节点, 也可以作为左节点，右节点,
    数n 是递增的， 所以， 先左后右，退出递归条件是当start > end, 这可以保证二叉树特点, 

### Valide Binary Search Tree
- 描述
    判断一个树是否是合法的二叉树 
- 思路
    中序遍历, root -> left -> right
    先序遍历，left -> root -> right 
    后序遍历, right -> root -> left

### Binary Tree Level Order Traversal
- 描述
    按层级从左向右遍历二叉树
- 思路
    递归的形式也可以达到层级遍历，traverse(res, k+1, node)
    使用LinkedList 可用作Queue, 结合循环层级遍历

### Binary Tree Zigzag Level Order Traversal
- 描述
    按层级之字顺序遍历二叉
- 思路
    这两道题没啥难度
    使用C语言就有些麻烦了， 不过可以先遍历一次，求得最大的层级， 再预分配将数组分配好，
    malloc, calloc, realloc 比较耗时

### kmp 算法
- 描述
    查找字符串, 一个字符串是否包含另一个字符串
- 思路
    遍历， 一个字母一个字母的匹配， 遇到不匹配的字符， 根据部分匹配表，向前移动 index - (partial match) 位， 可以免去已匹配的字符， 增加效率
    部分匹配表的使用公式如何证明？
    部分匹配表, 有什么高效的方法算出来吗？

## thought
1. 所有的算法， 最根本的思想就是穷举， 因为计算机只能干穷举的事. 
2. 算法优化就是剔除掉不必要的穷举， 减少穷举的次数, 这里就涉及到算法优化的证明
3. 证明有从经验出发的， 人为根据算法的每一步， 去优化， 也有从数学公式着手， 只需要按公式编程即可。还有的就是一些奇淫巧技， 这就是考验天赋的。
4. 曾经的boss题, 现在也不过是个精英，首领


