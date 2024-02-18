#include "iostream"

/**/
void countEvenDigits(long long n, int& ans)
{
    if (n == 0)
    {
        return;
    }

    if ((n % 10) % 2 == 0)
    {
        ans++;
    }

    countEvenDigits(n / 10, ans);
}

void task3()
{
    long long n = 9223372036854775806;

    int ans = 0;
    countEvenDigits(n, ans);

    std::cout << "Количество четных цифр в " << n << ": " << ans << std::endl;
}