
const merger = (arr , start , mid , end) => {
  let i = start 
  let j = mid + 1
  let k = start 
  const temp = [] 
  while(i <= mid && j <= end) {
    if(arr[i] <= arr[j]) temp[k++] = arr[i++] 
    else temp[k++] = arr[j++]
  }
  while(i <= mid)
    temp[k++] = arr[i++]
  while(j <= end)
    temp[k++] = arr[j++]

  for(i = start ; i <= end ; i++)
    arr[i] = temp[i] 
  return arr 
}

const util = (arr , start , end) => {
  if(start == end) return arr ;
  const mid = parseInt(start + (end - start) / 2) 
  arr = util(arr, start , mid)
  arr = util(arr , mid + 1 , end)
  arr = merger(arr, start , mid , end)
  return arr 
}

const mergeSort = arr => {
  return util(arr , 0 , arr.length - 1) 
}


console.log(mergeSort([58,9,-1,0,0,0,98,4,3,2,1])) 
// o/p: 
// [
//   -1, 0, 0, 0,  1,
//    2, 3, 4, 9, 58,
//   98
// ]

