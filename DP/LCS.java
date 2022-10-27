// The Following code is the solution of common DP problem: Longest comon subsequence or find the 
// length of longest common subsequence between two strings s1 and s2.

//DP reccurance relation is lcs(i,j) = lcs(i-1,j-1)+1 if (s1[i]==s2[j])
//                          lcs(i,j) = max(lcs(i-1,j),lcs(i,j-1)) otherwise
public class LCS
{
 
    int lcs( char[] X, char[] Y, int m, int n )
{
    int L[][] = new int[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}
    int max(int a, int b)
        {
            return (a > b)? a : b;
        }
     
    public static void main(String[] args)
    {
        LCS lcs = new LCS();
        String s1 = "aabbbbbcccdd";
        String s2 = "abcdaaabbc";
     
        char[] X=s1.toCharArray();
        char[] Y=s2.toCharArray();
        int m = X.length;
        int n = Y.length;
     
        System.out.println("Length of LCS is" + " " +
                                    lcs.lcs( X, Y, m, n ) );
    }
 
}