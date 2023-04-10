class Node {
    int x;
    int y;
    int step;
    
    Node(int x,int y,int step)
    {
        this.x=x;
        this.y=y;
        this.step=step;
    }
}

class Solution {
    public int minimumVisitedCells(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        
        PriorityQueue<Node> pq=new PriorityQueue<>((a,b) -> a.step-b.step);
        
        int [][] distance=new int[n][m];
        
        pq.offer(new Node(0,0,1));
        
        while(pq.size()>0)
        {
            Node node=pq.peek();
            pq.poll();
            int x=node.x;
            int y=node.y;
            int step=node.step;
            
            
            if(x== n-1 && y== m-1)
                return step;
            
            
            if(distance[x][y]>0)
                continue;
            
            
            distance[x][y]=step;
            
            for(int i=x+1;i<=x+grid[x][y] && i < n;i++)
            {
                if(distance[i][y]==0)
                {
                    pq.offer(new Node(i,y,step+1));
                }
            }
            
            
            for(int i=y+1;i<=y+grid[x][y] && i<m;i++)
            {
                if(distance[x][i]==0)
                {
                    pq.offer(new Node(x,i,step+1));
                }
            }
        }
        
        return -1;
    }
}