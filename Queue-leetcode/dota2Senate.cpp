// 649. Dota2 Senate
// "RRRDD" -> "RRDR" -> "RRR"

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        for(int i=0;i<senate.size();i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        int n = senate.size();

        while(r.size()>0 && d.size()>0){
            if(r.front() < d.front()){ //means smaller r index "RDD" --> "DR"
                d.pop();
                r.pop();  //remove r and add it in back with a greater idx
                r.push(n++);
            }
            else{ //means smaller d index "DR" --> "D"
                r.pop();
                d.pop();
                d.push(n++);
            }
        }
        if(r.size()>0) return "Radiant";
        else return "Dire";
    }
};