void inorder (TreeNode<int> *root , vector <int> &in)
{
   if ( root == NULL ) 
       return ;
   
   inorder (root -> left , in) ;
   in.push_back(root -> data) ;
   inorder( root -> right , in) ;
}

vector<int> mergeArrays(vector<int> &a , vector<int> &b) 
{
   vector <int> ans(a.size() + b.size()) ;
   
   int i = 0 , j = 0 ; 
    int k = 0 ; 
   
   while ( i < a.size() && j < b.size() ) 
   {
       if ( a[i] < b[j] ) {
           ans[k++] = a[i] ; 
           i++ ; 
       }
       else {
           ans[k++] = b[j] ;
           j++ ; 
       }
   }
   
   while ( i < a.size() ) {
       ans[k++] = a[i] ;
       i++ ;
   }
   while ( j < b.size() ) {
       ans[k++] = b[j] ;
       j++ ; 
   }
     return ans ; 
}

TreeNode<int>* inorderToBST( int s , int e , vector<int> &in ) 
{
//      BASE CASE 
   if ( s > e ) 
       return NULL ;
   
//      RECURSION CALL 
   int mid = s + (e-s)/2 ; 
   TreeNode<int>* root = new TreeNode<int>(in[mid]) ;
   root -> left = inorderToBST(s , mid-1 , in) ;
   root -> right = inorderToBST(mid+1 , e , in) ;
   return root ; 
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
//     STEP-1 --> STORE INORDER 
     vector <int> bst1 , bst2 ;
     inorder (root1 , bst1) ;
     inorder (root2 , bst2) ;
//      STEP-2 --> MERGE BOTH SORTED ARRAYS
  vector <int> mergeArray = mergeArrays(bst1 , bst2) ;
   
//      STEP-3--> USE INORDER ARRAY TO BUILD BST
    int s = 0 , e = mergeArray.size() - 1 ; 
   return inorderToBST ( s , e , mergeArray ) ;   
}
