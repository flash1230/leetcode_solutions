/* https://leetcode.com/problems/create-hello-world-function/
2667. Create Hello World Function
Easy 
*/
function createHelloWorld() {
    return function (...args): string {
        return "Hello World"
    };
};