import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        // HashMap <Character,Integer> mapS = new HashMap<>();
        // HashMap <Character,Integer> mapT = new HashMap<>();

        // for(int i=0;i<s.length();i++){
        //     char charS = s.charAt(i);     
        //     char charT = t.charAt(i);
            
        //     // 
        //     mapS.put(charS, mapS.getOrDefault(charS, 0) + 1);
        //     mapT.put(charT, mapT.getOrDefault(charT, 0) + 1);
        // }
        // return mapS.equals(mapT);
        char[] originalArr = s.toCharArray();
        char[] modifiedArr = t.toCharArray();

        Arrays.sort(originalArr);
        Arrays.sort(modifiedArr);

        return Arrays.equals(originalArr, modifiedArr);
    }
}
