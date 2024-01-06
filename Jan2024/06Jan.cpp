class Solution {
public:
    int primePowers(int n)
    {
        int cnt = 0;
        for(int i = 2; i <= sqrt(n); i++)
        {
            while(n % i == 0)
            {
                cnt++;
                n = n / i;
            }
        }
        
        if(n > 1)
            cnt++;
        
        return cnt;
    }
    
    int sumOfPowers(int a, int b)
    {
        int cnt = 0;
        for(int i = a; i <= b; i++)
            cnt += primePowers(i);
        
        return cnt;
    }
};
