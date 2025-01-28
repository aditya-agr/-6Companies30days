class TrieNode{
public:
    bool end;
    TrieNode* child[26];
    TrieNode(){
        end = false;
        for(int i=0; i<26; i++)
            this->child[i] = NULL;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();   
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int i = c-'a';
            if(curr->child[i] == NULL)
                curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->end = true;
    }
    bool searchUtil(string word, TrieNode*curr) {
        int n = word.length();
        for(int i=0; i<n; i++){
            if(word[i] != '.'){
                int idx = word[i]-'a';
                if(curr->child[idx] == NULL)
                    return false;
                curr = curr->child[idx];
            }
            else{
                string s = word.substr(i+1);
                for(int j=0; j<26; j++)
                    if(curr->child[j] != NULL)
                        if(searchUtil(s, curr->child[j]))
                            return true;
                return false;
            }
        }
        return curr && curr->end;
    }
    bool search(string word){
        return searchUtil(word, root);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */