//950. Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;   //create a queue for storing indices
        for(int i=0;i<n;i++){
            q.push(i);
        }

        //now we reveal first card(push it to vector) and then move the next front to the bottom
        vector<int> idx;
        while(q.size()>0){
            idx.push_back(q.front()); //reveal
            q.pop(); //after reveal pop

            q.push(q.front());  //put top card in the bottom
            q.pop();
        }
        
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        //using idx array and sorted deck array we will put the ele in ans array. 
        for(int i=0;i<n;i++){
            ans[idx[i]] = deck[i];
        }

        return ans;


    }
};