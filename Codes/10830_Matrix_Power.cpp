#include <iostream>
#include <vector>

using std::vector;
typedef long long ll;

void add(vector< vector<ll> > &A, vector< vector<ll> > &B, vector< vector<ll> > &res, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            res[i][j] = (A[i][j] + B[i][j]);
        }
    }
}

void sub(vector< vector<ll> > &A, vector< vector<ll> > &B, vector< vector<ll> > &res, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            res[i][j] = (A[i][j] - B[i][j]);
        }
    }
}

vector< vector<ll> > strassen(vector< vector<ll> > &A, vector< vector<ll> > &B, int n) {
    vector< vector<ll> > res (n, vector<ll>(n, 0));

    // Base case
    if (n == 1) {
        res[0][0] = A[0][0] * B[0][0];
        return res;
    }

    // Initialise matrices
    n /= 2;
    vector<ll> tmp(n, 0);

    vector< vector<ll> > A1(n, tmp), A2(n, tmp), A3(n, tmp), A4(n, tmp),
                         B1(n, tmp), B2(n, tmp), B3(n, tmp), B4(n, tmp),
                         C1(n, tmp), C2(n, tmp), C3(n, tmp), C4(n, tmp),
                         p1(n, tmp), p2(n, tmp), p3(n, tmp), p4(n, tmp), p5(n, tmp), p6(n, tmp), p7(n, tmp),
                         fmh(n, tmp), apb(n, tmp), cpd(n, tmp), gme(n, tmp), apd(n, tmp),
                         eph(n, tmp), bmd(n, tmp), gph(n, tmp), amc(n, tmp), epf(n, tmp),
                         tmpC1(n, tmp), tmpC2(n, tmp);

    // Split
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j+n];
            A3[i][j] = A[i+n][j];
            A4[i][j] = A[i+n][j+n];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j+n];
            B3[i][j] = B[i+n][j];
            B4[i][j] = B[i+n][j+n];
        }
    }

    // Get Intermediate matrices
    sub(B2, B4, fmh, n);
    add(A1, A2, apb, n);
    add(A3, A4, cpd, n);
    sub(B3, B1, gme, n);
    add(A1, A4, apd, n);
    add(B1, B4, eph, n);
    sub(A2, A4, bmd, n);
    add(B3, B4, gph, n);
    sub(A1, A3, amc, n);
    add(B1, B2, epf, n);

    // Get p matrices
    p1 = strassen(A1, fmh, n);   // p1 = a(f-h)
    p2 = strassen(apb, B4, n);   // p2 = (a+b)h
    p3 = strassen(cpd, B1, n);   // p3 = (c+d)e
    p4 = strassen(A4, gme, n);   // p4 = d(g-e)
    p5 = strassen(apd, eph, n);  // p5 = (a+d)(e+h)
    p6 = strassen(bmd, gph, n);  // p6 = (b-d)(g+h)
    p7 = strassen(amc, epf, n);  // p7 = (a-c)(e+f)

    // Get Resultant matrices

    // C1 = p5 + p4 - p2 + p6
    add(p5, p4, tmpC1, n);
    sub(tmpC1, p2, tmpC2, n);
    add(tmpC2, p6, C1, n);

    // C2 = p1 + p2
    add(p1, p2, C2, n);

    // C3 = p3 + p4
    add(p3, p4, C3, n);

    // C4 = p1 + p5 - p3 - p7
    add(p1, p5, tmpC1, n);
    sub(tmpC1, p3, tmpC2, n);
    sub(tmpC2, p7, C4, n);

    // Combine
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            res[i][j] = C1[i][j];
            res[i][j+n] = C2[i][j];
            res[i+n][j] = C3[i][j];
            res[i+n][j+n] = C4[i][j];
        }
    }

    return res;
}

vector< vector<ll> > operator * (vector< vector<ll> > &A, vector< vector<ll> > &B) {
    int n = A.size();
    vector< vector<ll> > res (n, vector<ll>(n, 0));
    res = strassen(A, B, n);
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            res[i][j] %= 1000;
        }
    }

    return res;
}

vector< vector<ll> > power(vector< vector<ll> > A, ll b) {
    int n = A.size();
    vector< vector<ll> > res (n, vector<ll>(n, 0));
    for (int i=0; i < n; i++) res[i][i] = 1;

    while (b > 0) {
        if (b&1) res = res * A;
        b /= 2;
        A = A * A;
    }

    return res;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    ll n, b;
    std::cin >> n >> b;

    int nn;
    if (n == 3) nn = 4;
    else if (n == 5) nn = 8;
    else nn = n;

    vector< vector<ll> > A (nn, std::vector<ll>(nn, 0));

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    vector< vector<ll> > ans;

    ans = power(A, b);
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}