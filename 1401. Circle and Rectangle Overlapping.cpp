class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1, min(x2, xCenter));
        int y = max(y1, min(y2, yCenter));
        int dx = xCenter-x;
        int dy = yCenter-y;
        return dx*dx + dy*dy <= radius*radius;
    }
};