class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict_1 = {}
        dict_2 = {}

        for i in range(len(s)):
            if s[i] in dict_1:
                dict_1[s[i]] += 1
            else:
                dict_1[s[i]] = 1
        for i in range(len(t)):
            if t[i] in dict_2:
                dict_2[t[i]] += 1
            else:
                dict_2[t[i]] = 1
        
        if dict_1 == dict_2:
            return True
        else:
            return False