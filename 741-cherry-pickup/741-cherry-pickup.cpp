class Solution {
public:
    
    int cp( int r1, int c1, int r2, int c2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp )
    {
        int n = grid.size() ;
        if( r1>=0  && r2>=0 && c1>=0 && c2>=0 && r1<n && r2<n && c1<n && c2<n && grid[r1][c1]!=-1 && grid[r2][c2] !=-1 )
        {
            if( dp[r1][c1][r2][c2] != -1 ) return dp[r1][c1][r2][c2] ;

            if( r1==n-1 && c1==n-1 ) return grid[r1][c1] ;

            int cherry = 0 ;

            if( r1 == r2 && c1 == c2 )
                cherry += grid[r1][c1] ;
            else
                cherry += ( grid[r1][c1] + grid[r2][c2] ) ;

            int f1 = cp( r1 , c1+1 , r2 , c2+1 , grid , dp ) ;
            int f2 = cp( r1+1 , c1 , r2+1 , c2 , grid , dp ) ;
            int f3 = cp( r1+1 , c1 , r2 , c2+1 , grid , dp ) ;
            int f4 = cp( r1 , c1+1 , r2+1 , c2 , grid , dp ) ;

            dp[r1][c1][r2][c2] = ( cherry += max( max( f1, f2) , max( f3, f4) ) ) ;
            
            return dp[r1][c1][r2][c2] ;         
        }
        return INT_MIN ;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() ;
   
       vector<vector<vector<vector<int>>>> dp( n, vector<vector<vector<int>>>( n, vector<vector<int>>( n, vector<int>(n,-1)))) ;

       int ans = cp( 0, 0, 0, 0, grid, dp) ;

       if( ans <= 0 )
           return 0 ;

       return ans ;
    }
};