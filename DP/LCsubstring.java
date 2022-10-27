/*
The following problem is same as the LCS ( longest common subsequence
 but here we look at the substring and not the subsequence) so thus we
 reccurance relation is
 lcs(i,j) = lcs(i-1,j-1)+1 if s1[i]==s2[j]
 else lcs(i,j) = 0
 */
class LCsubstring{
    static int LCSubStr(char X[], char Y[],
                         int m, int n)
    {
        int LCStuff[][] = new int[m + 1][n + 1];
        int result = 0;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    LCStuff[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                {
                    LCStuff[i][j]
                        = LCStuff[i - 1][j - 1] + 1;
                    result = Integer.max(result,
                                         LCStuff[i][j]);
                }
                else
                    LCStuff[i][j] = 0;
            }
        }
        return result;
    }
    public static void main(String[] args)
    {
        String X = "Hi my name is ishankapur ok ok dnt do";
        String Y = "github code by ishankapur.co pucho to ishan";
 
        int m = X.length();
        int n = Y.length();
 
        System.out.println(LCSubStr(X.toCharArray(),
                                    Y.toCharArray(), m,
                       n));
    }
}