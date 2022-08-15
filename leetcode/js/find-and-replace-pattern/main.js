// link: https://leetcode.com/problems/find-and-replace-pattern/

/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
 const check = (s1,s2) => {
    if(s1.length != s2.length) return false;
    const s = new Set() ;
    const m = new Map() ;
    const n = s1.length;
    for(let i=0;i<n;i++){
        if(!m.has(s1[i])){
            if(s.has(s2[i])) return false;
            s.add(s2[i]);
            m.set(s1[i],s2[i]);
        }else if(m.get(s1[i])!=s2[i])return false;
    }
    return true;
}

var findAndReplacePattern = function(words, pattern) {
    const res=[];
    for(let i=0;i<words.length;i++) if(check(words[i],pattern))res.push(words[i])
    return res;
};