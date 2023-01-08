// link: https://leetcode.com/problems/word-pattern/

/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    const map = {} , rev = {} ;
    const words = s.split(' ') ;
    if(pattern.length != words.length) return false ;
    for(let i = 0 ; i < pattern.length ; i++){
        const key = pattern[i].toString() ;
        if(key in map){
            if(map[key] != words[i]) return false ;
        }
        else{
            if(words[i] in rev) return false ;
            map[key] = words[i] ;
            rev[words[i]] = key ;
        }
    }
    return true ;
};