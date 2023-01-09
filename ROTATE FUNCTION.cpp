class Solution {
    public int maxRotateFunction(int[] A) {
        // F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]
        // F(k+1) = 0 * Bk+1[0] + 1 * Bk+1[1] + ... + (n-1) * Bk+1[n-1]
        //        = 0 * Bk[n - 1] + 1 * Bk[0] + ... + (n -1) * Bk[n-2]
        // F(k+1) - F(k) = Bk[0] + Bk[1] + .. Bk[n -2] - (n-1) * Bk[n-1]
        //               = sum(0 to n - 1) - n * Bk[n - 1]
        int sum = 0, F = 0, n = A.length;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            F += i * A[i];
        }
        int max = F;
        for (int i = n - 1; i > 0; i--) {
            F = F + sum - n * A[i];
            max = Math.max(max, F);
        }
        return max;
    }
}