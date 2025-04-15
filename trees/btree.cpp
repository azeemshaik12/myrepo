//binary tree example 
#include<iostream>
#include<set>
#include<memory>
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

class b_tree{
    node *root;
    std::unique_ptr<std::set<int>> a = std::make_unique<std::set<int>>();
    void inserrec(node *root,int value){
       if(value < root->data) {
           if(!root->left){
             root->left=new node(value); 
           }
           else{
             inserrec(root->left,value); 
           }
       }
       else{
          if(!root->right){
             root->right=new node(value); 
           }
           else{
             inserrec(root->right,value); 
           } 
       }
    }
    void remove_node(node *ptr){
        if(ptr!=nullptr){ 
        remove_node(ptr->left);
        remove_node(ptr->right);
        std::cout<<"deleteing ->"<<ptr->data<<"\n";
        delete ptr;
        }
    }
  public:  
  b_tree(){
      root=nullptr;
  }
  b_tree(int value){
      root=new node(value);
  }
  void insert(int value){
      if(root==nullptr){
        root=new node(value);  
      }
      else{
        inserrec(root,value);
      }
  }
  void print(node *root){
      if(!root){
      }
      else{
          std::cout<<root->data<<", ";
          print(root->left);
          print(root->right);
      }
  }
  void inorder(node *root){
      if(!root){
      }
      else{
          inorder(root->left);
          std::cout<<root->data<<", ";
          inorder(root->right);
      }
  }
  void preorder(node *root){
      print(root);
  }
  void postorder(node *root){
      if(!root){
      }
      else{
          postorder(root->left);
          postorder(root->right);
          std::cout<<root->data<<", ";
      }
  }
  void invert(node *root){
      if(!root){
      }
      else{
          node * temp=root->left;
          root->left= root->right;
          root->right=temp;
          invert(root->left);
          invert(root->right);
      }
     
  }
  int width(node *root,int val=0){
       
      if(!root){
          
      }
      else{
        width(root->left,val-1);
        a->insert(val);
        width(root->right,val+1);
      }
      return a->size();
  }
  
  node * begin(){
      return root;
  }
  ~b_tree(){
      if(!root){
          
      }else{
        remove_node(root);  
      }
  }
};

int main(){
   b_tree t(10);
   t.insert(12);
   t.insert(9);
   t.insert(4);
   t.insert(12);
   t.insert(11);
   t.insert(99);
   t.insert(55);
   t.insert(88);
   t.print(t.begin());
   std::cout<<"\n";
   t.invert(t.begin());
   t.print(t.begin());
   std::cout<<"\n";
   t.print(t.begin()->right);
   std::cout<<"\n";
   t.preorder(t.begin());
   std::cout<<"\n";
   t.inorder(t.begin());
   std::cout<<"\n";
   t.postorder(t.begin());
   std::cout<<"\n";
   std::cout<<t.width(t.begin())<<"\n"; 
   b_tree x(10);
   x.insert(12);
   x.insert(9);
   x.insert(4);
   x.insert(12);
   x.insert(11);
   x.insert(99);
   x.insert(55);
   x.insert(88);
   std::cout<<x.width(x.begin())<<"\n"; 
   std::cout<<sizeof(x)<<"\n";
}
