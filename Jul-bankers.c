#include <stdio.h>
Int main ()
{
Int n, m, i, j, k, alloc[5][4], max[5][4];
N = 5;
M = 4;
Printf (“Enter allocation”);
For (i = 0; i < 5; i++)
    {
For (j = 0; j < 4; j++)
{
Scanf (“%d”, &alloc[i][j]);
}
   
}
Printf (“Enter Max allocation”);
For (i = 0; i < 5; i++)
    {
For (j = 0; j < 4; j++)
{
 
Scanf (“%d”, &max[i][j]);
}
   
}

Int avail[4] = { 1, 5, 2, 0 };
Int f[n], ans[n], ind = 0;
For (k = 0; k < n; k++)
    {
F[k] = 0;
}
Int need[n][m];
For (i = 0; i < n; i++)
    {
For (j = 0; j < m; j++)
Need[i][j] = max[i][j] – alloc[i][j];
}
  Printf (“NEED”);
  For (i = 0; i < 5; i++)
    {
      Printf (“\n”);
      For (j = 0; j < 4; j++)
{
 Printf (“%d”, need[i][j]);
}
    }
Int y = 0;
For (k = 0; k < 5; k++)
    {
For (i = 0; i < n; i++)
{
If (f[i] == 0)
   {
Int flag = 0;
For (j = 0; j < m; j++)
{
If (need[i][j] > avail[j])
   
   {
Flag = 1;
Break;
}
}
If (flag == 0)
{
Ans[ind++] = i;
For (y = 0; y < m; y++)
Avail[y] += alloc[i][y];
F[i] = 1;

         }
      }
  }
}
Printf (“\nFollowing is the SAFE Sequence\n”);
For (i = 0; i < n; i++)
Printf (“ P%d,”, ans[i]);

}
