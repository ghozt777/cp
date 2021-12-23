// question : write a function `fib(n)` that takes a number `n` as an argument and returns the n-th number
// from the fibonacci series

// YT : https://www.youtube.com/watch?v=oBt53YbR9Kk
import { question } from "readline-sync";

const useFib = () => {
  const fib = (n) => {
    if (n <= 0) {
      throw new Error("invalid position !");
    }
    if (n <= 2) {
      return 1;
    }

    let prev = 1;
    let preprev = 1;
    let curr = 0;
    for (let i = 3; i <= n; i++) {
      curr = prev + preprev;
      preprev = prev;
      prev = curr;
    }

    return curr;
  };

  const fibRecursive = (n) => {
    if (n <= 2) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
  };

  /**
   * Complexity Analysis for Recursive Solution :
   * for the first recursive call : fibRecursive(n - 1)
   * O(n) : Space
   * O(n) : Time
   *
   * for the second recursive call : fibRecursive(n - 2)
   * O(n/2) : Space = O(n)
   * O(n/2) : Time = O(n)
   *
   * Overall Time Complexity : O(n^2) : Exponential -> width of the recursion tree
   * Overall Space Complexity : O(n) : Linear -> Height of the recursion tree (max stack depth is height of the tree)
   *
   */
  return [fib, fibRecursive];
};

// now using DP and memoization :

const useFibMemo = () => {
  // now to store the results we need a data structure(ideally fast)
  // we are going to use plain objects , but equiavlent DS can be a hashmap in other languages
  // key -> argument to the function : val -> returned value from the function

  /**
   * Complexity Analysis :
   * O(2n)  = O(n) Space Complexity
   * O(2n)  = O(n) Time Complexity
   */

  const fib = (n, memo = {}) => {
    if (n in memo) {
      // console.log("used memo for n = ", n, "with result : ", memo[n]);
      return memo[n];
    }
    if (n <= 2) return 1;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo); // memo is going to be empty only for the main call but for the recursive calls mmemo is going to be non-empty
    return memo[n];
  };
  return fib;
};

function main() {
  const [fib_i, fib_r, fib_ar] = useFib();
  const fib = useFibMemo();
  let n = parseInt(question("Enter n : "));
  // console.log(`The ${n}th Fibanacci number is (iterative): ${fib_i(n)}`);
  // console.log(`The ${n}th Fibanacci number is (recursive): ${fib_r(n)}`); // slow af Eg : for n = 50
  console.log(`The ${n}th Fibonacci number is (memoized): ${fib(n)}`);
}

main();
