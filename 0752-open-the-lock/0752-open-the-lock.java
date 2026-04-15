class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String>visited=new HashSet<>();
        Set<String>dead=new HashSet<>(Arrays.asList(deadends));
        Queue<String>pq=new LinkedList<>();
        if(dead.contains("0000"))return -1;

        pq.add("0000");
        int level=-1;
        while(!pq.isEmpty()){
            int size=pq.size();
            level++;

            for(int k=0;k<size;k++){
            String s =pq.poll();
            if(visited.contains(s))continue;
            visited.add(s);
            StringBuilder sb= new StringBuilder(s);
            if(s.equals(target)){
                return level;
            }

            for(int i=0;i<=3;i++){
                char c=sb.charAt(i);
                int num=sb.charAt(i)-'0';
                sb.setCharAt(i,(char)((num+1)%10+'0'));
                if(!visited.contains(sb.toString()) && !dead.contains(sb.toString())){
                    pq.add(sb.toString());
                }
                sb.setCharAt(i, (char)((num + 9) % 10 + '0'));
                if(!visited.contains(sb.toString()) && !dead.contains(sb.toString())){
                    pq.add(sb.toString());
                }
                 sb.setCharAt(i,c);

             }

            }

        }

        return -1;


    }
}