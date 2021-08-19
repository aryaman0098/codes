// Problem -> https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s){
   string ans = "";
   int max = 0;
   for(int i = 0; i < s.length(); i++){
       int l = i, r = i;
       while(l >= 0 && r < s.length() && s[l] == s[r]){
           if((r - l + 1) > max){
               ans = s.substr(l, r + 1 - l);
               max = r - l + 1;
           }
            l--;
            r++;
        }
        l = i; r = i + 1;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            if((r - l + 1) > max){
               ans = s.substr(l, r + 1 - l);
               max = r - l + 1;
            }
            l--;
            r++;
        }
   } 
    return ans;
}

//string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";  
