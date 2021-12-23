// Question : Say that you are a traveller on a 2D grid
// You begin in the top left corner and your goal is to travel to the bottom-right corner.
// You may only move down or right .
// in how may ways you can travel to the goal on a grid with dimensionsm m * n ?

// Write a function `gridTraveller(m,n)` that calculates it .

import { question as ask } from "readline-sync";

const bruteForce = () => {
  const gridTraveller = (m, n) => {
    // initial position taken as : (0,0) -> destination : (m-1,n-1) ; // array like
    /**
     * Complexity Analysis :
     * O(2^(n + m)) -> Time Complexity
     * O(n + m) -> Space Complexity
     */
    let ans = 0;
    const util = (x, y) => {
      if (x >= n || y >= m) return;
      if (x == n - 1 && y == m - 1) ++ans;
      util(x, y + 1);
      util(x + 1, y);
    };
    util(0, 0);
    return ans;
  };

  const gridTraveller_v2 = (m, n) => {
    // initial postion taken as (m,n) -> destination (1,1)
    if (m == 1 && n == 1) return 1;
    if (m <= 0 || n <= 0) return 0;
    return gridTraveller_v2(m - 1, n) + gridTraveller_v2(m, n - 1);
  };

  return [gridTraveller, gridTraveller_v2];
};

const gridTraveller_memoized = () => {
  const gridTraveller = (m, n, memo = {}) => {
    if ([m, n].toString() in memo) return memo[[m, n].toString()]; // (x , y) has the same result as  (y , x)
    if ([n, m].toString() in memo) return memo[[n, m].toString()];
    if (m == 1 && n == 1) return 1;
    if (m <= 0 || n <= 0) return 0;
    memo[[m, n].toString()] =
      gridTraveller(m - 1, n, memo) + gridTraveller(m, n - 1, memo);
    return memo[[m, n].toString()];
  };
  return gridTraveller;
};

const main = () => {
  const [gridTraveller, gridTraveller_v2] = bruteForce();
  const gridTraveller_m = gridTraveller_memoized();
  let m = parseInt(ask("Enter m : "));
  let n = parseInt(ask("Enter n  : "));
  console.log("(memoized)", gridTraveller_m(m, n));
  console.log("(recursive)", gridTraveller(m, n));
};

main();
