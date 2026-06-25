class Solution {
    public int strStr(String haystack, String needle) 
    {
        int i = 0;
        String word;
        
            if(haystack.indexOf(needle, i) != -1)
            {
                return haystack.indexOf(needle, i);
            }
            else
            {
                return -1;
            }
        
    }
}
