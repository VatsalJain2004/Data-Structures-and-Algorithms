// class Solution {
//     string vowels = "aeiouAEIOU";
// public:
//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         set<string> originalWords(wordlist.begin(), wordlist.end());
//         unordered_map<string, string> lowerCaseWord;
//         unordered_map<string, string> vowelInsensitive;

//         for (string s : wordlist) {
//             string lower = s;
//             transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

//             if (!lowerCaseWord.count(lower))
//                 lowerCaseWord[lower] = s;

//             string mask = lower;
//             for (char& c : mask) {
//                 if (vowels.find(c) != string::npos) c = '*';
//             }
//             if (!vowelInsensitive.count(mask))
//                 vowelInsensitive[mask] = s;
//         }

//         vector<string> correctWords;
//         for (string q : queries) {
//             if (originalWords.count(q)) {
//                 correctWords.push_back(q);
//                 continue;
//             }

//             string lower = q;
//             transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
//             if (lowerCaseWord.count(lower)) {
//                 correctWords.push_back(lowerCaseWord[lower]);
//                 continue;
//             }

//             for (char& c : lower) {
//                 if (vowels.find(c) != string::npos) c = '*';
//             }
//             if (vowelInsensitive.count(lower)) {
//                 correctWords.push_back(vowelInsensitive[lower]);
//             } else {
//                 correctWords.push_back("");
//             }
//         }
//         return correctWords;
//     }
// };











class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> actual;
        unordered_map<string,string> small;
        unordered_map<string,string> vowel;
 
        for(auto s:wordlist) {
            actual.insert(s);
 
            string small_case = get_low(s); 
            small.insert({small_case,s});

            string vowel_string = get_vowel(s);
            vowel.insert({vowel_string,s});
        }
 
        for(int i = 0;i < queries.size(); i++) {
            string s = queries[i];
            if(actual.count(queries[i])) {
                continue;
            }
 
            if(small.count(get_low(s))) {
                queries[i] = small[get_low(s)];
            }
            else if(vowel.count(get_vowel(s))) {
                queries[i] = vowel[get_vowel(s)];
            }
            else {
                queries[i] = "";
            }
        }
 
        return queries;
    }

    string get_low(string s) {
        string str = "";
 
        for(auto ch: s) {
            str += tolower(ch);
        }
        return str;
    }

    string get_vowel(string s) {
        string str = "";

        for(auto ch: s) {
            char c = tolower(ch);
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
                c = '*';
            }

            str+=c;
        }
        return str;
    }
};