class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = defaultdict(int)

        max_count = 0

        i = 0
        sub_count = 0

        while i < len(s):
            if s[i] in last_seen and i - last_seen[s[i]] <= sub_count:
                max_count = max(sub_count, max_count)
                sub_count = i - last_seen[s[i]]
                last_seen[s[i]] = i
            else:
                sub_count += 1
                last_seen[s[i]] = i

            i += 1

        max_count = max(sub_count, max_count)

        return max_count
