#include <bits/stdc++.h> 
#define MAX_TREE_HT 256 
using namespace std; 

map<char, string> codes; 

map<char, int> freq; 

class Node 
{ 
	public:
    char data;          
    int freq;           
    Node *left, *right; 
  
    Node(char data, int freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 

class compare 
{ 
	public:
    bool operator()(Node* l, Node* r) 
    { 
        return (l->freq > r->freq); 
    } 
}; 


void storeCodes(Node* root, string str) 
{ 
    if (root==NULL) 
        return; 
    if (root->data != '$') 
        codes[root->data]=str; 
    storeCodes(root->left, str + "0"); 
    storeCodes(root->right, str + "1"); 
} 
 string decode_file( Node* root, string s) 
{ 
    string ans = ""; 
    Node* curr = root; 
    for (int i=0;i<s.size();i++) 
    { 
        if (s[i] == '0') 
           curr = curr->left; 
        else
           curr = curr->right; 
  
        if (curr->left==NULL and curr->right==NULL) 
        { 
            ans += curr->data; 
            curr = root; 
        } 
    } 
    return ans+'\0'; 
} 

void calcFreq(string str, int n) 
{ 
    for (int i=0; i<str.size(); i++) 
        freq[str[i]]++; 
}
priority_queue<Node*, vector<Node*>, compare> minHeap; 

void HuffmanCodes(int size) 
{ 
    Node *left, *right, *top; 
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++) 
        minHeap.push(new Node(v->first, v->second)); 
    while (minHeap.size() != 1) 
    { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new Node('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
    storeCodes(minHeap.top(), ""); 
} 
 
void printCodes(Node* root, string str) 
{ 
    if (!root) 
        return; 
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 

 
  
int main() 
{ 
    string str = "FAST"; 
    string encoded, decoded; 
    calcFreq(str, str.length()); 
    HuffmanCodes(str.length()); 
    
    
    cout << "Huffman Codes:\n"; 
    for (auto v=codes.begin(); v!=codes.end(); v++) 
        cout << v->first <<' ' << v->second << endl; 
  
    for (auto i: str) 
        encoded+=codes[i]; 
  
    cout << "\nEncoded  Data:\n" << encoded << endl; 
  
    decoded = decode_file(minHeap.top(), encoded); 
    cout << "\nDecoded  Data:\n" << decoded << endl; 
    return 0; 
}
