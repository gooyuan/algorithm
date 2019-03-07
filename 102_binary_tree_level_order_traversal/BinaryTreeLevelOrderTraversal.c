#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void traverse(int** res, int level, struct TreeNode* cur, int** cols, int *rsize){
    if(!cur) return;

    printf("val: %d, level %d, rsize: %d\n", cur->val, level, *rsize);

    if(level >= *rsize){
        *rsize += 1;
        res = (int**)realloc(res, *rsize * sizeof(int*));
        res[level] = (int*)realloc(res[level], (cols[0][level]+1) * sizeof(int));
        *cols = (int*)realloc(*cols, *rsize * sizeof(int));
    }

    //printf("level: %d, cols: %d,realloc rsize: %d\n", level, cols[0][level], *rsize);

    *(res[level]+cols[0][level]) = cur->val;

    //printf("level: %d, column: %d\n", level, cols[0][level]);
    //printf("level: %d, column: %d, val: %d\n", level, cols[0][level], res[0][0]);
    //printf("level: %d, column: %d, val: %d\n", level, cols[0][level], res[level][**(cols+level)]);

    *(cols[0] + level) +=1;
    printf("level: %d, column: %d\n", level, cols[0][1]);

    traverse(res, level + 1, cur->left, cols, rsize);
    traverse(res, level + 1, cur->right, cols, rsize);
}

int** levelOrder(struct TreeNode* root, int** cols, int* rsize) {
    //int** res = (int**)calloc(50, sizeof(int*));
    int** res = (int**)calloc(1, sizeof(int*));
    *cols = (int*)calloc(1, sizeof(int));
    *res = (int*)calloc(1, sizeof(int));
    res[0] = (int*)calloc(1,sizeof(int));
    *rsize = 1;
    traverse(res, 0, root, cols, rsize);
    return res;
}

int main(){
    TreeNode root; 
    TreeNode left; 
    TreeNode right; 
    TreeNode left1; 
    TreeNode right1; 
    root.val = 3;
    left1.val = 15;
    left1.left = NULL;
    left1.right = NULL;
    right1.val = 7;
    right1.left = NULL;
    right1.right = NULL;
    left.val = 9;
    left.left = NULL;
    left.right = NULL;
    right.val = 20;
    root.left = &left;
    root.right = &right;
    right.left = &left1;
    right.right = &right1;

    int** cols = (int**)malloc(sizeof(int*)); 
    int size = 0;
    int* rsize = &size;
    int aa[5] = {0};
    rsize = aa;
    printf("%ld\n", sizeof(aa));

    int** res = levelOrder(&root, cols, rsize);   

    printf("%d-%d\n", *rsize, cols[0][0]);

    for(int i=0; i<*rsize; i++){
        for(int j=0; j<cols[0][i]; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    free(cols[0]);
    free(cols);

    return 0;
}
