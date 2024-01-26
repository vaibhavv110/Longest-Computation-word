#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

#define ll long long
#define LOOP_COUNT int LOOP_COUNT; cin >> LOOP_COUNT; while (LOOP_COUNT--)
#define pb push_back
#define FOR_LOOP(i, n) for (int i = 0; i < n; i++)
#define LOOP_MISS(i, x, n) for (int i = x; i < n; i++)
#define REVERSE_LOOP(n, i) for (int i = n - 1; i >= 0; i--)
#define br cout << endl
#define vi vector<int>
#define ff first
#define ss second
#define vb vector<bool>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define msi map<string, int>
#define mint map<int, int>
#define pint pair<int, int>
#define MAX_LENGTH 1001
#define MOD 1000000007

bool compareLengthLexico(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}

void findCompoundWords() {
    string word;
    vector<string> wordsList;
    unordered_set<string> seenWords;

    while (cin >> word) {
        wordsList.push_back(word);
        seenWords.insert(word);
    }

    string longestCompoundWord, secondLongestCompoundWord;

    sort(wordsList.begin(), wordsList.end(), compareLengthLexico);

    int listSize = wordsList.size() - 1;

    vector<bool> dp(MAX_LENGTH);

    while (listSize > -1) {
        string &currentWord = wordsList[listSize--];
        int wordLength = currentWord.size();
        string temp;

        fill(dp.begin(), dp.end(), false);

        for (int i = 0; i < wordLength; i++) {
            temp = "";

            for (int j = 0; j <= i; j++) {
                if (seenWords.count(currentWord.substr(j, i - j + 1))) {
                    if (j == 0 && i != wordLength - 1) {
                        dp[i] = true;
                        break;
                    } else if (j >= 1 && dp[j - 1]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        if (dp[wordLength - 1] == true) {
            if (longestCompoundWord.empty())
                longestCompoundWord = currentWord;
            else if (secondLongestCompoundWord.empty())
                secondLongestCompoundWord = currentWord;
            else
                break;
        }
    }

    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Longest compound word: " << longestCompoundWord << "\n";
        outputFile << "Second longest compound word: " << secondLongestCompoundWord << "\n";
        outputFile.close();
    } else {
        cout << "Unable to open file";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    auto beginTime = high_resolution_clock::now();

    LOOP_COUNT {
        findCompoundWords();
    }

    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(endTime - beginTime);

    cout << "Time taken to process input file: " << duration.count() << " milliseconds";
    return 0;
}
