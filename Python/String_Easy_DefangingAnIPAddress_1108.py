import re

class Solution:
    def defangIPaddr(self, address: str) -> str:
        text = re.findall(r"\w+", address)

        return "[.]".join(text)
