/* https://leetcode.com/problems/array-prototype-last/
2619. Array Prototype Last
Easy
*/
Array.prototype.last = function () {
    return this.length ? this.pop() : -1
};