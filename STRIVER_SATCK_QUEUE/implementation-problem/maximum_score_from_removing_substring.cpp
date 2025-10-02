1717. Maximum Score From Removing Substrings

with stack 

class Solution {
public:
    // time o(n)
    // space o(n)
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        // First pass: remove high priority pair
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * max(x, y);

        // Second pass: remove low priority pair
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        // Calculate score from second pass
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack
                    .pop();  // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};

approach 2 : without stack

class Solution {
public: 
    // time o(n)
    // space o(1)
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            totalPoints += removeSubstring(s, "ab", x);
            totalPoints += removeSubstring(s, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            totalPoints += removeSubstring(s, "ba", y);
            totalPoints += removeSubstring(s, "ab", x);
        }

        return totalPoints;
    }

    int removeSubstring(string& inputString, string targetSubstring,
                        int pointsPerRemoval) {
        int totalPoints = 0;
        int writeIndex = 0;

        // Iterate through the string
        for (int readIndex = 0; readIndex < inputString.size(); readIndex++) {
            // Add the current character
            inputString[writeIndex++] = inputString[readIndex];

            // Check if we've written at least two characters and
            // they match the target substring
            if (writeIndex > 1 &&
                inputString[writeIndex - 2] == targetSubstring[0] &&
                inputString[writeIndex - 1] == targetSubstring[1]) {
                writeIndex -= 2;  // Move write index back to remove the match
                totalPoints += pointsPerRemoval;
            }
        }

        // Trim the string to remove any leftover characters
        inputString.erase(inputString.begin() + writeIndex, inputString.end());

        return totalPoints;
    }
};