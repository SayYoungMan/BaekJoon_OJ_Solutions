#include <iostream>

int main() {
    long long int t, x, y, speed, ans, dist, cur;

    std::cin >> t;
    for (int i = 0; i < t; i++){
        std::cin >> x >> y;
        dist = y - x;
        cur = 0;

        ans = 0;
        speed = 0;
        while (cur < dist) {
            // printf("Currently at %i/%i with speed %i and %i moves\n", cur, dist, speed, ans);
            // printf("%i and %i\n", dist-cur, ((speed+1)*(speed+2))/2);
            if ((dist - cur) >= ((speed+1)*(speed+2))/2) {
                speed++;
                ans ++;
                cur += speed;
            } else if ((dist - cur) < (speed*(speed+1))/2) {
                speed--;
                ans ++;
                cur += speed;
            } else {
                ans ++;
                cur += speed;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}