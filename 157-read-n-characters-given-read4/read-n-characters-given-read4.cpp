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

     // 6
    int read(char *buf, int n) { //buf is where we should retutn all the read characters
        int i = 0;
        int read = 4;
        int count = 0;
        char myBuf4[4];
    
        while(read >= 4) {
            read = read4(myBuf4); //abc
            cout << read << endl;
            count += read;
            for (int j = 0; j < read; j++) {
                buf[i] = myBuf4[j];
                i++;

                if (i == n) {
                    return i;
                }
            }
        }

        return count;
    }
};