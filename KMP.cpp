void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 
    lps[0] = 0; 

    
    int i = 1; 
    while (i < M) 
    { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) 
                len = lps[len - 1];
            else  
            lps[i] = 0,i++; 
        } 
    } 
}

int KMPSearch(string pat, string txt) 
{ 
    int M = pat.size(); 
    int N = txt.size(); 

    int lps[M]; 

    computeLPSArray(pat, M, lps); 

    int i = 0,j = 0; 
    while (i < N) 
    { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 

        if (j == M) return i-j;
        else if (i < N && pat[j] != txt[i]) 
        {
            if(j) j = lps[j - 1]; 
            else i++; 
        } 
    }
    
    return -1;
} 

int Solution::strStr(const string A, const string B) {
    int as=A.size(),bs=B.size();
    char txt[as]; 
    char pat[bs]; 

    for(int i=0;i<as;i++)
    txt[i]=A[i];

    for(int i=0;i<bs;i++)
    pat[i]=B[i];

    cout<<KMPSearch(pat, txt); 
    return 0; 
}
