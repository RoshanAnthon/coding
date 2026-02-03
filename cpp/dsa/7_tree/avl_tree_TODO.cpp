/*
They might ask atleast the logic. no need to study full but understad the logic
WHY AVL TREE EXISTS (THE MOTIVATION)
Worst-case BST

Insert:

10, 20, 30, 40, 50


Tree becomes:

10
  \
   20
     \
      30
        \
         40
           \
            50

AVL idea (one sentence)

Keep the tree balanced automatically after every insert/delete


4️⃣ AVL TREE BASICS (DO NOT PANIC)

AVL = Self-balancing BST

Each node stores:

height = max(left_height, right_height) + 1


Balance factor:

balance = height(left) - height(right)


Allowed values:

-1, 0, +1


If outside → rotation required

5️⃣ AVL ROTATIONS (INTERVIEW CORE)
4 cases (only these)
Case	Situation	Fix
LL	Left heavy on left	Right rotate
RR	Right heavy on right	Left rotate
LR	Left heavy on right	Left + Right
RL	Right heavy on left	Right + Left
Example: Right Rotation (LL case)

Before:

      30
     /
   20
  /
10


After:

     20
    /  \
  10   30

Rotation code (don’t memorize, understand)
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

6️⃣ What interviewers REALLY expect

You do NOT need to write full AVL from memory.

They expect:

BST insert/search/delete — YES

AVL idea & rotations — YES

Full AVL code — ❌ rarely

If you can explain AVL rotations, you’re golden.
*/