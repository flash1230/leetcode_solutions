/* https://leetcode.com/problems/counter/
2620. Counter
Easy
*/
var createCounter = function (n) {
    return function () {
        return n++
    };
};