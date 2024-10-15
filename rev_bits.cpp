class Solution {
public:
    void swap_bits_pos(uint32_t &n, int l,  int r) {
        uint32_t l_bit = n & (1 << l);
        uint32_t r_bit = n & (1 << r);
        if ((l_bit >> l) == (r_bit >> r)) {
            return;
        }
        n ^= (1 << l);
        n ^= (1 << r);
    }
    
    uint32_t reverseBits(uint32_t n) {
        
        int l = 0, r = 31;
        while (l < r) {
            swap_bits_pos(n, l , r);
            l++;
            r--;
        }
        return n;
    }
};