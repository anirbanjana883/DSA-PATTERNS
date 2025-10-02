165. Compare Version Numbers

catch is you have to consider each version to find which is  greater

                    STRING TOCKENIZER   

class Solution {
public:
    vector<string>getToken(string v){
        stringstream ss(v);

        string token = "";
        vector<string>tokens;

        while(getline(ss , token , '.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = getToken(version1);
        vector<string>v2 = getToken(version2);
        int n1 = v1.size();
        int n2 = v2.size();

        int i = 0;
        while( i < n1 || i < n2){
            int a = i < n1 ? stoi(v1[i]) : 0 ;
            int b = i < n2 ? stoi(v2[i]) : 0 ;

            if(a < b) return -1;
            else if(a > b) return 1;
            else i++;
        }
        return 0;
    }
};



class Solution {
public:
    int compareVersion(string version1, string version2) {   
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size(), num1 = 0, num2 = 0; 
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.')
            {
                num1 = num1*10+(version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.')
            {
                num2 = num2*10+(version2[j]-'0');
                j++;
            }
            if(num1>num2)
            {
                return 1;
            }
            if(num1 < num2) 
            {
                return -1;
            }
            i++;
            j++;
            num1 = 0;
            num2 = 0;
        }
        return 0; 
    }
};