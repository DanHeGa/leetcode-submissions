/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    char globalBuf[4];
    int gBufIdx = 0;
    int currBufSize = 0;

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        //exhaust global buffer before reading more
        while(count < n) {
            if (gBufIdx == currBufSize) { //we have read all buf chars
                //so we can re-add to out buffer
                currBufSize = read4(globalBuf);
                gBufIdx = 0; //reset global buffer index 

                if (currBufSize == 0) {
                    break;
                }
            }

            while(count < n && gBufIdx < currBufSize) {
                buf[count] = globalBuf[gBufIdx];
                gBufIdx++;
                count++;
            }
        }

        return count;
    }
};