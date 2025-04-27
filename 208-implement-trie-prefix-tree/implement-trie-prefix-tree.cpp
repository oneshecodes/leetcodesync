class Trie {
public:
    struct TrieNode{
        bool endOfWord;
        TrieNode* children[26];
    };
    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->endOfWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    // Initializing Root of Trie;
    TrieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                crawler->children[ch-'a']=getNode();
            }
            crawler=crawler->children[ch-'a'];
        }
        crawler->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* crawler=root;
        for(char &ch:word){
            if(crawler->children[ch-'a']==NULL){
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
        return crawler->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler=root;
        for(char &ch:prefix){
            if(crawler->children[ch-'a']==NULL){
                return false;
            }
            crawler=crawler->children[ch-'a'];
        }
        return true;
    }
};