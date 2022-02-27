void strmcpy( char *t, int m, char *s )
{   int l = strlen(t),i,k=0;
    for (i = m-1;i<=l;i++)
    {
        s[k++] = t[i];
    }
}