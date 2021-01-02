#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Breadth First Search

 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()) return 0;
        set<string> mySet;
        for(string x : wordList)
            mySet.insert(x);
        if(!mySet.count(endWord)) return 0;
        int level=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sizeQ=q.size();
            for(int i=0; i<sizeQ; i++){
                string curr=q.front();
                q.pop();
                for(int j=0; j<curr.size(); j++){
                    char temp=curr[j];
                    for(char c='a'; c<='z'; c++){
                        curr[j]=c;
                        if(mySet.count(curr)){
                            if(curr==endWord) return level+1;
                            q.push(curr);
                            mySet.erase(curr);
                        }
                    }
                    curr[j]=temp;
                }
            }
            level++;
        }
        return 0;
    }

int main() {
  
}