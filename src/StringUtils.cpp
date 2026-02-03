#include "StringUtils.h"
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>

std::string Upper(const std::string &str){
    std::string res = str;
    for(char &c : res){
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return res;
}

std::string Lower(const std::string &str){
    std::string res = str;
    for(char &c : res){
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return res;
}

std::string Capitalize(const std::string &str){
    if(str.empty()) return str;
    std::string res = Lower(str);
    res[0] = std::toupper(static_cast<unsigned char>(res[0]));
    return res;
}

std::string LStrip(const std::string &str){
    size_t i = 0;
    while(i < str.size() && std::isspace(static_cast<unsigned char>(str[i]))){
        i++;
    }
    return str.substr(i);
}

std::string RStrip(const std::string &str){
    if(str.empty()) return str;
    ssize_t i = str.size() - 1;
    while(i >= 0 && std::isspace(static_cast<unsigned char>(str[i]))){
        i--;
    }
    return str.substr(0, i + 1);
}

std::string Strip(const std::string &str){
    return LStrip(RStrip(str));
}

std::string Slice(const std::string &str, ssize_t start, ssize_t end){
    ssize_t len = str.size();

    if(start < 0) start += len;
    if(end <= 0) end += len;

    start = std::max<ssize_t>(0, std::min(start, len));
    end   = std::max<ssize_t>(0, std::min(end, len));

    if(start >= end) return "";
    return str.substr(start, end - start);
}

std::string Replace(const std::string &str,
                    const std::string &old,
                    const std::string &rep){
    if(old.empty()) return str;

    std::string res;
    size_t pos = 0, found;
    while((found = str.find(old, pos)) != std::string::npos){
        res += str.substr(pos, found - pos);
        res += rep;
        pos = found + old.length();
    }
    res += str.substr(pos);
    return res;
}

std::vector<std::string> Split(const std::string &str,
                               const std::string &splt){
    std::vector<std::string> res;

    if(splt.empty()){
        std::istringstream iss(str);
        std::string word;
        while(iss >> word){
            res.push_back(word);
        }
        return res;
    }

    size_t pos = 0, found;
    while((found = str.find(splt, pos)) != std::string::npos){
        res.push_back(str.substr(pos, found - pos));
        pos = found + splt.length();
    }
    res.push_back(str.substr(pos));
    return res;
}

std::string Join(const std::string &str,
                 const std::vector<std::string> &vect){
    std::string res;
    for(size_t i = 0; i < vect.size(); i++){
        res += vect[i];
        if(i + 1 < vect.size()){
            res += str;
        }
    }
    return res;
}

std::string LJust(const std::string &str, int width, char fill){
    if((int)str.size() >= width) return str;
    return str + std::string(width - str.size(), fill);
}

std::string RJust(const std::string &str, int width, char fill){
    if((int)str.size() >= width) return str;
    return std::string(width - str.size(), fill) + str;
}

std::string Center(const std::string &str, int width, char fill){
    if((int)str.size() >= width) return str;
    int total = width - str.size();
    int left = total / 2;
    int right = total - left;
    return std::string(left, fill) + str + std::string(right, fill);
}

std::string ExpandTabs(const std::string &str, int tabsize){
    std::string res;
    int col = 0;
    for(char c : str){
        if(c == '\t'){
            int spaces = tabsize - (col % tabsize);
            res.append(spaces, ' ');
            col += spaces;
        }else{
            res += c;
            col++;
        }
    }
    return res;
}

int EditDistance(const std::string &left,
                 const std::string &right,
                 bool ignorecase){
    std::string a = left;
    std::string b = right;

    if(ignorecase){
        a = Lower(a);
        b = Lower(b);
    }

    int n = a.size();
    int m = b.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cost = (a[i-1] == b[j-1]) ? 0 : 1;
            dp[i][j] = std::min({
                dp[i-1][j] + 1,
                dp[i][j-1] + 1,
                dp[i-1][j-1] + cost
            });
        }
    }
    return dp[n][m];
}
