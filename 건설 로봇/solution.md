[유량 네트워크](http://en.wikipedia.org/wiki/Flow_network)에서 [최대 유량](http://en.wikipedia.org/wiki/Maximum_flow_problem)을 구하면 됩니다. 유량 네트워크의 그래프로 작업을 나타내는 W개의 노드와 기종을 나타내는 K개의 노드를 만듭니다. 그리고 source에서 기종에 각각 기종 별 노드에 대해 그 기종의 로봇 수만큼의 capacity를 갖는 간선을 추가합니다. 또한 작업을 나타내는 각각의 노드에서 최대 투입 가능한 로봇 수만큼의 capacity를 갖는 간선을 sink를 향해 추가합니다.

이젠 source에서 sink로 최대 유량을 보내기 위해 [Edmonds–Karp](http://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm) 알고리즘 등을 사용하는 일만 남게 되었습니다. 최대 유량을 구하면 그것이 이 문제의 정답이 됩니다.
