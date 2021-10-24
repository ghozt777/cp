const insertionSort = arr => {
  for(let i = 0 ; i < arr.length - 1 ; i++){
    for(let j = i + 1 ; j > 0 ; j--) {
      if(arr[j] < arr[j - 1]){
        const temp = arr[j] ;
        arr[j] = arr[j-1] ;
        arr[j-1] = temp ;
      }
      else break 
    }
  }
  return arr ;
}

console.log(insertionSort([5,4,3,2,1]))
// o/p: 
// [ 1, 2, 3, 4, 5 ]