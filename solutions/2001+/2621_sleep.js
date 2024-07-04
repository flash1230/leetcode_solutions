/* https://leetcode.com/problems/sleep/
2621. Sleep
Easy
Promise
*/
async function sleep(millis) {
    return new Promise(resolve => setTimeout(resolve, millis))
}