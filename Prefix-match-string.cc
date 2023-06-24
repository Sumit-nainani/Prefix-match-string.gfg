// Given an array of strings arr[] of size n, a string str and an integer k. 
// The task is to find the count of strings in arr[] whose prefix of length k 
// matches with the k-length prefix of str.
/*
  approach:
      we will create a Trie for string array and in a Trie node we will store a arr[26] array for counting 
      the characters and when we will insert a character in trie then we will increase the count for that character.
      for k length prefix we will store the minimum count until k length string.

*/
struct Node{
    Node * link[26];
    int arr[26];
    bool flag=false;
};
class Trie{
  public:
  Node*root;
  Trie(){
      root=new Node();
  }
  void insert(string&s){
      Node*node=root;
      int size=s.size();
      for(int i=0;i<size;i++){
          if(node->link[s[i]-'a']==NULL){
              node->link[s[i]-'a']=new Node();
          }
          node->arr[s[i]-'a']++;
          node=node->link[s[i]-'a'];
      }
      node->flag=true;
  }
  int val(int k,string str){
      Node*node=root;
      int size=str.size();
      int ans(INT_MAX);
      int i;
      for(i=0;i<min(k,size);i++){
          if(node->link[str[i]-'a']!=NULL){
              ans=min(ans,node->arr[str[i]-'a']);
              node=node->link[str[i]-'a'];
          }
          else break;
      }
      return i==k?ans:0;
  }
};
class Solution{   
public:
    
    int klengthpref(string arr[], int n, int k, string str){    
        Trie obj;
        for(int i=0;i<n;i++){
            obj.insert(arr[i]);
        }
        int ans=obj.val(k,str);
        return ans==INT_MAX?0:ans;
    }
};