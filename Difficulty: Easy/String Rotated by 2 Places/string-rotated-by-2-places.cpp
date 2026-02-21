class Solution {
public:

    // rotate string clockwise by 1
    void rotateClockwise(string &s) {
        char last = s[s.size() - 1];

        for(int i = s.size() - 1; i > 0; i--) {
            s[i] = s[i - 1];
        }

        s[0] = last;
    }

    // rotate string anticlockwise by 1
    void rotateAntiClockwise(string &s) {
        char first = s[0];

        for(int i = 0; i < s.size() - 1; i++) {
            s[i] = s[i + 1];
        }

        s[s.size() - 1] = first;
    }

    bool isRotated(string& s1, string& s2) {

        if(s1.size() != s2.size())
            return false;

        string clockwise = s1;
        string anticlockwise = s1;

        // rotate twice clockwise
        rotateClockwise(clockwise);
        rotateClockwise(clockwise);

        if(clockwise == s2)
            return true;

        // rotate twice anticlockwise
        rotateAntiClockwise(anticlockwise);
        rotateAntiClockwise(anticlockwise);

        if(anticlockwise == s2)
            return true;

        return false;
    }
};