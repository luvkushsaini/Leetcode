class Solution {
    public int mirrorFrequency(String s) {
        Map<Character,Integer>mp=new HashMap<>();
        Set<Character>visited=new HashSet<>();

        for(char c:s.toCharArray()){
            mp.put(c,mp.getOrDefault(c,0)+1);
        }

        int ans=0;

        for(char c:mp.keySet()){
            if(visited.contains(c))continue;
            if(c>='0' && c<='9'){
                int num=9-(c-'0');
                char ch=(char)(num+'0');

                ans+=Math.abs(mp.getOrDefault(c,0)-mp.getOrDefault(ch,0));
                visited.add(ch);
                visited.add(c);
            }
            else{
                char  ch=(char)('z'-(c-'a'));
                ans+=Math.abs(mp.getOrDefault(c,0)-mp.getOrDefault(ch,0));
                visited.add(ch);
                visited.add(c);
            }
        }

        return ans;
    }
}