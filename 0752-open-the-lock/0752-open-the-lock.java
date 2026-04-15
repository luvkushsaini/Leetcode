class Solution {

    class Pair{
        int f;
        String s;
        Pair(int f,String s){
            this.f=f;
            this.s=s;
        }
    }

    public int openLock(String[] deadends, String target) {
        Set<String>visited=new HashSet<>();
        Set<String>dead=new HashSet<>(Arrays.asList(deadends));
        PriorityQueue<Pair>pq=new PriorityQueue<>((a,b)->Integer.compare(a.f,b.f));
        if(dead.contains("0000"))return -1;

        pq.add(new Pair(0,"0000"));
        while(!pq.isEmpty()){
            Pair p=pq.poll();
            if(visited.contains(p.s))continue;
            visited.add(p.s);
            StringBuilder sb= new StringBuilder(p.s);
            if(p.s.equals(target)){
                return p.f;
            }

            for(int i=0;i<=3;i++){
                int count=p.f;
                char c=sb.charAt(i);
                int num=sb.charAt(i)-'0';
                sb.setCharAt(i,(char)((num+1)%10+'0'));
                if(!visited.contains(sb.toString()) && !dead.contains(sb.toString())){
                    pq.add(new Pair(count+1,sb.toString()));
                }
                sb.setCharAt(i, (char)((num + 9) % 10 + '0'));
                if(!visited.contains(sb.toString()) && !dead.contains(sb.toString())){
                    pq.add(new Pair(count+1,sb.toString()));
                }
                 sb.setCharAt(i,c);

        }
        }

        return -1;


    }
}