/**
 * Question : Write a function `canSum(targetSym , numbers)` that takes in a target sum and an array of numbers as arguments .
 * The Function should return a boolean indicating wether or not it is possible to generate the targetSum using numbers from the array
 * You may use an element of the array as many times as needed .
 * You may assume all input numbers are non negative .
 */

 const bruteForce = () => {
    /**
     * Complexity Analysis :
     * O(n^m) -> Time (Exponential)
     * O(m) -> Space
     */
    const canSum = (targetSum, numbers) => {
      if (targetSum === 0) return true;
      const res = numbers.map((number) => {
        if (targetSum - number >= 0) return canSum(targetSum - number, numbers);
        else return false;
      });
      if (res.includes(true)) return true;
      else return false;
    };
  
    const betterSolution = (targetSum, numbers) => {
      if (targetSum === 0) return true;
      if (targetSum < 0) return false;
      for (let num of numbers) {
        if (betterSolution(targetSum - num, numbers)) {
          return true;
        }
      }
      return false;
    };
  
    return [canSum, betterSolution];
  };
  
  const canSum_memoized = (targetSum, numbers, memo = {}) => {
    /**
     * Complexity Analysis :
     * O(m*n) -> Time
     * O(m) -> Space
     */
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;
    if (targetSum in memo) return memo[targetSum];
    for (let num of numbers) {
      if (canSum_memoized(targetSum - num, numbers, memo)) {
        memo[targetSum] = true;
        return true;
      }
    }
    memo[targetSum] = false;
    return false;
  };
  
  const main = () => {
    const [canSum_bf, canSum_bf2] = bruteForce();
    console.log(canSum_bf2(8, [5, 3, 2]));
    console.log(canSum_bf(8, [5, 3, 2]));
    console.log(canSum_memoized(300, [7, 14])); // fast as fuck boi
  };
  
  main();
  