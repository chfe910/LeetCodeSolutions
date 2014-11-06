class Solution {
public:
    int lengthOfLastWord(const char *s) {
		int i, j, len = 0;
		for (i = 0; s[i] != '\0'; ++i) ;
		for (  --i; s[i] ==  ' '; --i) ;
		for (j = i; j >= 0 && s[j] != ' '; --j, ++len) ;
		return len;
    }
};

class Solution1 {
public:
    int lengthOfLastWord(const char *s) {
		int len = 0, last = 0;
		while (*s != '\0')
			if (*s++ == ' ') {
				last = len > 0 ? len : last;
				len = 0;
			}
			else ++len;

		return len > 0 ? len : last;
    }
};
