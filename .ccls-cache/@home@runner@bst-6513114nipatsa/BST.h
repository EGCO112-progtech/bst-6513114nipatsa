// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );
/*
void insertNode_R(TreeNodePtr * t,int value){
  if(*t==NULL){
  *t =(TreeNodePtr) malloc(sizeof(struct TreeNode));
   *t=new TreeNode;
	 if(*t){
		*t->leftPtr=NULL;
		*t->rightPtr=NULL;
		*t->data=value;
   }
  }
  else{
     if((*t)->data>=value) insertNode_R(&(*t)->leftPtr,value);//left
        
     else insertNode_R(&(*t)->rightPtr,value); //right
      
   }
}
*/
void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){ //เช็คว่าmallocสำเร็จ
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root) //b=NULL	
    b->root=new_node;
		else {
while(!inserted){
   if(t->data >=value){ //ค่าที่มีอยู่t->data>=ค่าใหม่
     /* move/insert to the left*/
     if(!t->leftPtr) {//ถ้าซ้ายของtว่าง t->leftPtr==NULL;
     t->leftPtr=new_node;
       inserted=1;
       }
    else 
       t=t->leftPtr;
     
       
     }
  	 
  
   else{
        if(!t->rightPtr) {
        t->rightPtr=new_node;
          inserted=1;
          }
     else t=t->rightPtr;
	      /* move/ insert to the right*/
    
      }
  
  }//end while		
  }//end else;
  
  b->size++;
  }
  
}//end function

void printTree(TreeNodePtr treePtr, int num)
{
 if(treePtr !=NULL){
  printTree(treePtr->rightPtr, num+3);
  for(int i=0; i<num; i++) printf("  ");
  printf("%d\n",treePtr->data);
  printTree(treePtr->leftPtr,num+3);
}
}


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void PreOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
      printf("%3d",treePtr->data) ;  //print the value 
     
      PreOrder( treePtr->leftPtr ); //Recursion to the left

      PreOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void postOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
      
     
      postOrder( treePtr->leftPtr ); //Recursion to the left

      postOrder( treePtr->rightPtr ); //Recursion to the right

      printf("%3d",treePtr->data) ;  //print the value 
   } // end if                          
} // end 

