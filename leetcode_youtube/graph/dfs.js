const graph = require('./_graph')


const visited = new Set()
!(function dfs (graph,start) {
  visited.add(start)
  console.log(start)
  graph[start].filter(c=>!visited.has(c)).forEach(c=>dfs(graph, c))
})(graph, 2)
