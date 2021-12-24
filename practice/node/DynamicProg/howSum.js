/**
 * Question : Write a function `howSum(targetSum , numbers)` that takes in a target sum and an array as argument.
 *
 * The function should return an array containing any combination of elements that add up to exactly the target sum .
 * If there is no combination of elements that adds up to the target sum return null .
 * Tf there are multiple combinations return anyone of the combinations
 */

import { question as ask } from "readline-sync";

const bruteForce = () => {
  const howSum = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;
    let ans = null;
    for (let num of numbers) {
      const res = howSum(targetSum - num, numbers);
      if (res !== null) {
        ans = [...res, num];
        return ans;
      }
    }
    return null;
  };
  return howSum;
};

const main = () => {
  const howSum_bf = bruteForce();
  const targetSum = ask("Enter targetSum : ");
  const n = ask("Enter n :");
  const numbers = [];
  for (let i = 0; i < n; i++) numbers[i] = ask("");
  console.log(howSum_bf(targetSum, numbers));
};

main();
