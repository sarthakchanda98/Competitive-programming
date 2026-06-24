class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1
        states = 2 * m
        
        # Matrix multiplication helper
        def multiply(A, B):
            size = len(A)
            C = [[0] * size for _ in range(size)]
            for i in range(size):
                for k in range(size):
                    if A[i][k] == 0:
                        continue
                    for j in range(size):
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
            return C

        # Matrix exponentiation helper
        def power(base, exp):
            size = len(base)
            res = [[0] * size for _ in range(size)]
            for i in range(size):
                res[i][i] = 1
            while exp > 0:
                if exp & 1:
                    res = multiply(res, base)
                base = multiply(base, base)
                exp >>= 1
            return res

        # Construct the transition matrix T
        # Map: 
        # State [0 ... m-1]     -> DOWN(x) (next element must be smaller than x)
        # State [m ... 2m-1]    -> UP(x)   (next element must be larger than x)
        T = [[0] * states for _ in range(states)]
        
        for x in range(m):
            down_state = x
            up_state = x + m
            
            # From UP(x) -> DOWN(y) requires y > x
            for y in range(x + 1, m):
                T[y][up_state] = 1
                
            # From DOWN(x) -> UP(y) requires y < x
            for y in range(x):
                T[y + m][down_state] = 1

        # The initial vector for a single element array (n=1 conceptually)
        # Any single number can start as either a peak or a valley for the next move
        start = [1] * states
        
        # Compute T^(n-1)
        T_pow = power(T, n - 1)
        
        # Multiply final matrix with the initial vector
        ans = 0
        for i in range(states):
            row_sum = 0
            for j in range(states):
                row_sum = (row_sum + T_pow[i][j] * start[j]) % MOD
            ans = (ans + row_sum) % MOD
            
        return ans
