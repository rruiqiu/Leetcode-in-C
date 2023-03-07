int lengthOfLongestSubstring(char *s)
{
    int offset[128];
    int max_len = 0;
    int len = 0;
    int index = 0;

    memset(offset, 0xff, sizeof(offset));
    while (*s != '\0') {
        if (offset[*s] == -1) {
            len++;
        } else {
            if (index - offset[*s] > len) {
                /* not included in sliding window, go on increasing */
                len++;
            } else {
                /* repetition in sliding window, count from scratch */
	            len = index - offset[*s];
            }
        }
        if (len > max_len) {
            max_len = len;
        }
        offset[*s++] = index++;
    }

    return max_len;
}
