#include<iostream>
#include<map>
#include<fstream>
#include<vector>
 struct Trie
    {
        std::map<std::string,struct Trie*> child;
        bool isword;
    };
    
Trie* getNewTrieNode()
{
    Trie* node=new Trie;
    node->isword=false;
    return node;
}
void insert( Trie* &root, const std:: string& str)
{
    if(root==nullptr)
        root=getNewTrieNode();
    Trie* temp=root;
    if(temp->child.find(str)==temp->child.end())
        temp->child[str]=getNewTrieNode();

    
    temp=temp->child[str];
    temp->isword=true;

}
bool search(Trie* root,const std::string& str)
{
    if(root==nullptr)
        return false;
    Trie* temp=root;
    temp=temp->child[str];
    if(temp==nullptr)
        return false;
    return temp->isword;
}
int main(){
Trie* root=nullptr;
std::string str;
std::cin>>str;

std::fstream fs;
fs.open("EnglishDictionary.csv",std::ios::in );
std::string temp,line;
while(fs>>temp)
{
    getline(fs,line,',');
    insert(root,line);
    line.erase();

    
}
insert(root,line);
bool ans=search(root,str);
if(ans==1)
{
    std::cout<<"YES"<<","<<std::endl;

}
else
{
    std::cout<<"NO"<<std::endl;
}


}
