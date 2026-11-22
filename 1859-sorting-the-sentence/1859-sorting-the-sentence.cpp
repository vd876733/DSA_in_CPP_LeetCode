class Solution {
public:

    // string stream approach
    string sortSentence(string s) {
        stringstream ss(s); // breakes sentence into words
        string word;
        vector<string> result(10); //beacuse no more than 10
        while(ss>>word){
            int position = word.back() - '0'; // to convert it to integer
            word.pop_back();//return only the word
            result[position]=word;
        }

        string answer;
        for(int i=0;i<10;i++){
            if(result[i] != ""){
                answer += result[i];
                answer +=" ";
            }
        }

        answer.pop_back(); //to avoid the last unwanted space

        return answer;
    }
};