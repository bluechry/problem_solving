// There is a building of 100 floors. If an egg drops from the Nth floor or
// above, it will break. If it's dropped from any floor below, it will not
// break. You're given two eggs. Find N, while minimizing the number of drops
// for the worst case.

// Solution
//   Binary search를 사용하면 최대 7번만에 N층을 찾을 수 있지만,
//   계란이 7개 필요하므로 binary search를 사용할 수가 없다.
//
//   * 두 개의 계란을 가지고 N층을 찾아내는 간단한 방법
//     1. 첫번째 계란을 가지고 I층씩 올라가면서 계란을 떨어뜨린 후 계란이
//        깨지는 구간을 찾는다. 예를 들면, 10층, 20층, 30층, ..., 100층에서
//        계란을 떨어뜨린다. 최대 ceil(100 / I)번 계란을 떨어뜨리게 된다.
//
//     2. k * I 층에서 계란이 깨졌으면 (k - 1) * I + 1 층까지 1층씩 내려가면서
//        계란을 떨어뜨려본다. 최대 I - 1번 계란을 떨어뜨리게 된다.
//
//     I = 10일 때,
//     최대 계란 투척 횟수 = 첫번째 계란 투척 횟수 + 두번째 계란 투척 횟수
//                         = 10 + 9 = 19 (회)
//
//     일반화하면,
//     최대 계란 투척 횟수 = ceil(100 / I) + (I - 1)
//
//     첫번째 계란 투척 횟수가 늘어나면 두번째 계란 투척 횟수가 줄어들고,
//     첫번째 계란 투척 횟수가 줄어들면 두번째 계란 투척 횟수가 늘어난다.
//
//     최대 계란 투척 횟수를 최소로 만드는 I 값을 구해보자.
//
//     'y = 100 / x + x - 1' 을 미분하면, '0 = 1 - 100 / x^2, x = 10'
//     따라서, I가 10일 때 최대 계란 투척 횟수는 최소가 되며 횟수는 19회이다.
//     이 경우 N = 10이 된다.
//
//   * 최대 계란 투척 횟수가 19회가 나왔지만, 이건 위에서 언급한 방법에서의
//     최대 횟수이고 더 효과적인 방법을 도입하면 이 값이 바뀐다.
//
//     위 방법에서는 10층에서 첫 계란이 깨지면 총 10번 계란을 투척하면되지만,
//     20층에서 깨지면 총 11번, 30층에서 깨지면 총 12번, 100층에서 깨지면 19번
//     계란을 투척해야한다. 즉, 첫번째 계란이 다음 10층 위에서 깨질 때마다 투척
//     횟수가 1번씩 더 늘어난다.
//
//     첫번째 계란을 더 위층에서 투척하여도 투척 횟수를 갖게 만들어 보자.
//     즉, 첫번째 계란이 어느 층에서 깨지더라도 총 계란 투척 횟수는 항상 같게
//     만드는 거다.
//
//     첫번째 계란을 한 번 더 던질 때마다 두 번째 계란을 한 번 덜 던져야 하므로
//     I층에서 첫번째 계란이 깨지지 않으면 I - 1 층 위로 올라가서 던지고,
//     또 깨지지 않으면 I - 2층 위로 올라가서 던진다.
//
//     다음 수식을 만족하는 I의 최소값을 찾으면 N을 구할 수 있다.
//
//     I + (I - 1) + (I - 2) + (I - 3) ... + 1 >= 100
//     <=> I * (I + 1) / 2 >= 100
//     <=> I^2 + I - 200 >= 0
//
//     위 식을 만족하는 최소 I의 값은 14이고,
//     따라서 N = 14, 최대 계란 투척 횟수도 14이다.