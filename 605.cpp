
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n >= flowerbed.size() / 2 + 2) return false;

    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 1) {
        if (n == 0)
          return true;
        else
          return false;
      } else {
        if (n <= 1)
          return true;
        else
          return false;
      }
    } else if (flowerbed.size() == 2) {
      if (flowerbed[0] == 1 || flowerbed[1] == 1) {
        if (n == 0)
          return true;
        else
          return false;
      } else {
        if (n <= 1)
          return true;
        else
          return false;
      }

    } else {
      if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        n--;
        flowerbed[0] = 1;
      }

      for (int i = 1; i < flowerbed.size() - 1 && n > 0; i++) {
        if (flowerbed[i + 1] == 0 && flowerbed[i] == 0 &&
            flowerbed[i - 1] == 0) {
          flowerbed[i] = 1;
          n--;
          if (n == 0) return true;
        }
      }

      if (flowerbed[flowerbed.size() - 2] == 0 &&
          flowerbed[flowerbed.size() - 1] == 0) {
        n--;
        flowerbed[flowerbed.size() - 1] = 1;
      }

      if (n > 0) {
        return false;
      } else {
        return true;
      }
    }

    return false;
  }
};
