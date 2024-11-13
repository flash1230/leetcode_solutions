/* https://leetcode.com/problems/find-center-of-star-graph/
1791. Find Center of Star Graph
Easy
Graph
*/
var findCenter = function (edges) {
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1]
};