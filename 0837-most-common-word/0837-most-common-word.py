import re
from collections import Counter

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        # Convert paragraph to lowercase and split into words (ignoring punctuation)
        words = re.findall(r'\w+', paragraph.lower())
        
        # Count frequencies
        count = Counter(words)
        
        # Return the most common word not in banned list
        for word, freq in count.most_common():
            if word not in banned:
                return word
