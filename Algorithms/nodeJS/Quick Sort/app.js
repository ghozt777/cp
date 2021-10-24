const partitioner = (arr , start , end) => {
  const key = arr[end]
  let pi = start 
  for(let i = start ; i < end ; i++){
    if(arr[i] <= key) {
      const temp = arr[pi] ;
      arr[pi] = arr[i] ;
      arr[i] = temp
      ++pi
    }
  }
  arr[end] = arr[pi]
  arr[pi] = key
  return [arr , pi] 
}


const quickSortUtil = (arr , start , end) => {
  if( start < end ){
    const [rArr , pi] = partitioner(arr , start , end) ;
    arr = rArr
    arr = quickSortUtil(arr , start , pi - 1)
    arr = quickSortUtil(arr , pi + 1 , end)
  }
  return arr 
}

const quickSort = arr => quickSortUtil(arr , 0 , arr.length - 1)

console.log(quickSort([5,4,3,2,1]))
console.log(quickSort([58,9,-1,0,0,0,98,4,3,2,1]))

// o/p:
// [ 1, 2, 3, 4, 5 ]
// [
//   -1, 0, 0, 0,  1,
//    2, 3, 4, 9, 58,
//   98
// ]