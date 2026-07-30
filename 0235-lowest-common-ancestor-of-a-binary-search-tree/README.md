<h2><a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree">235. Lowest Common Ancestor of a Binary Search Tree</a></h2><h3>Medium</h3><hr><p>Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.</p>

<p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: &ldquo;The lowest common ancestor is defined between two nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both <code>p</code> and <code>q</code> as descendants (where we allow <strong>a node to be a descendant of itself</strong>).&rdquo;</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 200px; height: 190px;" />
<pre>
<strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>Output:</strong> 6
<strong>Explanation:</strong> The LCA of nodes 2 and 8 is 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 200px; height: 190px;" />
<pre>
<strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [2,1], p = 2, q = 1
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p != q</code></li>
	<li><code>p</code> and <code>q</code> will exist in the BST.</li>
</ul>


Below are two separate Markdown notes. I’ve kept **BT as the core LCA problem**, then framed **BST as a special-case optimization/variation** so the relationship between the two solutions is explicit.

### 1. LCA in Binary Tree

````markdown
# Lowest Common Ancestor (LCA) — Binary Tree

## Problem Essence

Given a Binary Tree and two nodes `p` and `q`, find their **Lowest Common Ancestor (LCA)**.

### What is the LCA?

The LCA of `p` and `q` is the **lowest/deepest node in the tree that has both `p` and `q` somewhere in its subtree**.

A node can also be one of the two target nodes itself.

---

# Core Intuition

The entire problem can be reduced to one question:

> **Where is the first point in the tree where both `p` and `q` come together?**

For any current node, there are only a few possibilities:

```text
                 current
                /       \
             left       right
````

### Case 1 — `p` and `q` are on different sides

```text
                 current
                /       \
               p         q
```

One target is somewhere in the left subtree and the other is somewhere in the right subtree.

Therefore:

```text
current = LCA(p, q)
```

There is no need to search higher.

---

### Case 2 — Both are on the same side

```text
                 current
                /
              subtree
             /       \
            p         q
```

The current node is **not necessarily** their LCA.

We must continue searching inside that subtree.

---

### Case 3 — Current node is `p` or `q`

If:

```text
current == p
```

then `p` itself can be the LCA if `q` exists somewhere below it.

Likewise for `q`.

This is why the algorithm must consider the current node itself in addition to its left and right subtrees.

---

# The Core DFS Idea

Instead of explicitly asking:

> "Is `p` on the left and `q` on the right?"

we can make DFS return information about whether it found `p` or `q`.

For every node, calculate:

```text
left  = did the left subtree contain p or q?
right = did the right subtree contain p or q?
self  = is the current node p or q?
```

Then:

```text
total = left + right + self
```

Each of these contributes either:

```text
0 → not found
1 → found
```

Therefore:

```text
total = 0
```

Nothing found.

```text
total = 1
```

Exactly one of `p` or `q` has been found.

```text
total = 2
```

Both `p` and `q` have been found within the current node's subtree.

---

# Why `total == 2` Identifies the LCA

Suppose DFS reaches:

```text
                  X
                /   \
               p     q
```

After processing both children:

```text
left  = 1
right = 1
self  = 0

total = 1 + 1 + 0
      = 2
```

Therefore `X` is a common ancestor of both nodes.

But why is it the **lowest** common ancestor?

## DFS + Backtracking Insight

DFS goes:

```text
current
   ↓
left subtree
   ↓
deeper subtree
   ↓
backtrack
   ↓
right subtree
```

The first node encountered during the **bottom-up backtracking process** where:

```text
total == 2
```

is the deepest node whose subtree contains both targets.

Therefore it is the LCA.

---

# Why Do We Keep the First `total == 2`?

Use:

```cpp
if (total == 2 && !lcaNode)
    lcaNode = node;
```

Suppose:

```text
             A
            /
           B
          / \
         p   q
```

DFS reaches `B` first.

At `B`:

```text
left  = 1
right = 1
self  = 0

total = 2
```

So:

```text
lcaNode = B
```

Later DFS backtracks to `A`.

At `A`:

```text
total = 2
```

again.

But:

```cpp
!lcaNode
```

is now false.

Therefore `A` cannot overwrite `B`.

This preserves the **lowest/deepest** common ancestor.

---

# Implementation

```cpp
class Solution {
public:
    TreeNode* lcaNode;

    int lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return 0;

        int left = lca(node->left, p, q);
        int right = lca(node->right, p, q);

        int self = node == p || node == q;
        int total = left + right + self;

        if (total == 2 && !lcaNode)
            lcaNode = node;

        return total;
    }

    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        lcaNode = NULL;

        lca(root, p, q);

        return lcaNode;
    }
};
```

---

# Understanding the Return Value

The recursive function:

```cpp
int lca(...)
```

does **not** return the LCA.

It returns:

> How many of the two target nodes (`p`, `q`) exist inside this node's subtree?

Therefore:

```text
0 → neither found
1 → one found
2 → both found
```

The actual LCA is stored separately in:

```cpp
TreeNode* lcaNode;
```

---

# Why This Works for a General Binary Tree

A normal Binary Tree gives us no ordering information.

For a node:

```text
       root
      /    \
```

we cannot determine from values whether `p` or `q` is:

```text
left
right
or deeper somewhere below
```

So we need to **search the tree**.

DFS provides exactly that information.

The algorithm therefore does:

```text
Search left
+
Search right
+
Check current node
        ↓
      total
        ↓
   total == 2?
        ↓
       LCA
```

---

# Complexity

Let `N` = number of nodes.

### Time

```text
O(N)
```

Every node is visited at most once.

### Space

Recursive call stack:

```text
O(H)
```

where `H` is the height of the tree.

Balanced tree:

```text
O(log N)
```

Worst-case skewed tree:

```text
O(N)
```

---

# Core Mental Model

Remember LCA in a Binary Tree as:

```text
             node
            /    \
         left    right
           ↓       ↓
       found?    found?
            \     /
             self
               ↓
             total
               ↓
           total == 2
               ↓
              LCA
```

The essence is:

> **Find the deepest node whose subtree contains both `p` and `q`.**

The `left + right + self` technique is simply a way of encoding that information during DFS.

---

# Transition to BST

A BST is still a Binary Tree.

Therefore, the **LCA problem itself has not changed**.

What changes is the structure of the tree.

A BST gives us an additional guarantee:

```text
left subtree  <  root
right subtree > root
```

Therefore, unlike a normal Binary Tree, we can determine where `p` and `q` must be by comparing their values with the current node.

This allows us to avoid searching both subtrees.

That is the key optimization used in the BST version.

````

### 2. LCA in Binary Search Tree

```markdown
# Lowest Common Ancestor (LCA) — Binary Search Tree

## Relationship to LCA in a Binary Tree

A BST is a **special type of Binary Tree**.

The LCA definition remains exactly the same:

> Find the lowest node whose subtree contains both `p` and `q`.

The difference is that a BST gives us **ordering information**.

For every node:

```text
             root
            /    \
        smaller  larger
````

Therefore, by comparing:

```text
p->val
q->val
root->val
```

we can determine which subtree can possibly contain the targets.

This eliminates the need for a full DFS.

---

# BST Property

For a current node `root`:

```text
             root
            /    \
           <      >
```

Every value in the left subtree is:

```text
< root->val
```

Every value in the right subtree is:

```text
> root->val
```

This is the key piece of information that makes the BST solution much simpler.

---

# Case 1 — Both `p` and `q` are Smaller

Suppose:

```cpp
p->val < root->val
q->val < root->val
```

Therefore both nodes must be somewhere in:

```text
root->left
```

The current node cannot be their LCA because both targets are below it on the same side.

So:

```cpp
return lowestCommonAncestor(root->left, p, q);
```

Mental model:

```text
             root
            /
           ?
         p, q

Both → LEFT
```

---

# Case 2 — Both `p` and `q` are Larger

If:

```cpp
p->val > root->val
q->val > root->val
```

both nodes must be somewhere in:

```text
root->right
```

Therefore:

```cpp
return lowestCommonAncestor(root->right, p, q);
```

Mental model:

```text
             root
                \
                 ?
               p, q

Both → RIGHT
```

---

# Case 3 — They Split Around the Current Node

If neither of the above conditions is true:

```text
NOT:

p < root && q < root

AND

NOT:

p > root && q > root
```

then the targets are on different sides of the current node, **or one of them is the current node itself**.

Therefore:

```text
root = LCA
```

Return:

```cpp
return root;
```

---

# The Three Cases

At every BST node:

```text
              root
             /    \
```

### Both left

```text
p < root
q < root

        ↓

go LEFT
```

### Both right

```text
p > root
q > root

        ↓

go RIGHT
```

### Otherwise

```text
one left + one right
OR
p == root
OR
q == root

        ↓

root is LCA
```

---

# Implementation

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        if (!root)
            return nullptr;

        if (p->val < root->val &&
            q->val < root->val)
        {
            return lowestCommonAncestor(
                root->left,
                p,
                q
            );
        }

        else if (p->val > root->val &&
                 q->val > root->val)
        {
            return lowestCommonAncestor(
                root->right,
                p,
                q
            );
        }

        return root;
    }
};
```

---

# Why the `return root` Case Works

Consider:

```text
             6
            / \
           2   8
```

Suppose:

```text
p = 2
q = 8
```

At `6`:

```text
p < 6
q > 6
```

They are on opposite sides.

Therefore:

```text
6 = LCA
```

No further traversal is required.

---

# What If One Node Is the Current Root?

Suppose:

```text
             6
            /
           2
```

and:

```text
p = 6
q = 2
```

At root:

```text
p->val == root->val
q->val < root->val
```

The "both left" condition is false.

The "both right" condition is false.

Therefore:

```cpp
return root;
```

Correct.

The current node itself is the LCA.

---

# The Main Insight

The Binary Tree version asks:

> **Where are `p` and `q`?**

We have to search to discover that.

The BST version asks:

> **Where must `p` and `q` be according to the BST ordering property?**

We can determine that immediately from their values.

Therefore:

```text
Binary Tree
    ↓
No ordering information
    ↓
Need DFS
    ↓
O(N)
```

while:

```text
Binary Search Tree
    ↓
Ordering information available
    ↓
Choose LEFT or RIGHT
    ↓
Only follow one path
    ↓
O(H)
```

where `H` is the height of the BST.

---

# Recursive BST Complexity

### Time

```text
O(H)
```

because we only follow one path from the root.

Balanced BST:

```text
O(log N)
```

Worst-case skewed BST:

```text
O(N)
```

### Space

Recursive version:

```text
O(H)
```

because of the call stack.

---

# Iterative BST Version

The same logic can be written without recursion:

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(
        TreeNode* root,
        TreeNode* p,
        TreeNode* q
    ) {
        while (root) {
            if (p->val < root->val &&
                q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val &&
                     q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return nullptr;
    }
};
```

Space:

```text
O(1)
```

This is the optimal implementation when you do not need recursion.

---

# Connection Back to Binary Tree

The BST solution is not a completely different LCA problem.

It is:

```text
LCA in Binary Tree
        +
BST ordering property
        ↓
Eliminate unnecessary exploration
```

The Binary Tree solution conceptually does:

```text
             root
           /      \
       search    search
       left      right
           \      /
          find p/q
```

The BST solution can determine beforehand:

```text
Both left?
    ↓
go left

Both right?
    ↓
go right

Otherwise?
    ↓
current node = LCA
```

So the BST version is essentially an **optimized special case of the general Binary Tree LCA problem**.

---

# Final Mental Model

## Binary Tree

```text
Can I determine the side from values?

NO

↓

Search both sides

↓

left + right + self

↓

both found

↓

LCA
```

## BST

```text
Can I determine the side from values?

YES

↓

Both smaller → LEFT

Both larger  → RIGHT

Otherwise    → CURRENT NODE

↓

LCA
```

### One-line distinction

> **BT:** Search to discover where `p` and `q` are.
> **BST:** Use ordering to know where `p` and `q` must be.

```

This gives you a clean progression for the GitHub notes:

**LCA in Binary Tree → understand the fundamental problem → derive the `left + right + self` DFS → then recognize BST as a special Binary Tree where ordering lets you eliminate the expensive search.**
```
