// https://leetcode.com/problems/length-of-last-word
// 58. Length of Last Word
// Easy
var lengthOfLastWord = function (s) {
    s = s.split(" ")
    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === "")
            continue
        else
            return s[i].length
    }
    return s[0].length
};