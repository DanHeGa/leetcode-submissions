/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    int read(char *buf, int n) {
        int realRead = 4;
        char myBuf[4];
        int bufIdx = 0;
        int count = 0;

        while(realRead == 4) {
            realRead = read4(myBuf);
            count += realRead;

            for (int i = 0; i < realRead; i++) {
                buf[bufIdx] = myBuf[i]; 
                bufIdx++;

                if (bufIdx == n) {
                    return n;
                } 
            }
        }

        return count;
    }
};