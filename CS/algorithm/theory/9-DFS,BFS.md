재귀적으로 트리에 있는 내용을 찾아볼 때 굉장히 많이 사용되는 방식이다. 

## tree 속에 있는 데이터 찾기
- 어떤 순서로 방문할지에 대한 알고리듬이 필요하다. 
- 각 노드에서 실행할 수 있어야 한다. 

### 한 우물부터 깊이 판다.
루트부터 시작해서 리프까지 깊이 들어가는 방식 = 깊이 우선 방식, DFS
- 중위 순회와 매우 비슷하다. 따라서 재귀 함수로 쉽게 작성할 수 있다. 

### 깊이 우선 탐색 코드
```java
public static void searchDepthFirst(Node node) {
    Stack<Node> stack = new Stack<>();

    stack.push(node);
    while(!stack.empty()){
        Node next = stack.pop();

        System.out.println(next.data);

        for(Node child: next.children){
            stack.push(child);
        }
    }
}

```
### 여러 우물을 동시에 같은 깊이로
- 현재 깊이의 이웃 노드들을 우선 방문한다. 어느 한 가지부터 깊게 보지 않는다. 
- 최단 경로를 찾기에 적합하다. 
- 내가 보는 깊이보다 더 깊은 것은 안 봤다는 가정을 하기 때문

### 너비 우선 탐색 코드
```java
public static void searchBreadthFirst(Node node){
    Queue<Node> queue = new LinkedList<>();

    queue.add(node);

    while(!queue.isEmpty()){
        Node next = queue.remove();

        System.out.println(next.data);

        for(Node child: next.children){
            queue.add(child);
        }
    }
}

```

### 깊이 우선 vs 너비우선
깊이우선 탐색의 장점은, 재귀 함수 호출로 간단히 구현이 가능하다. 보통 BFS보다 메모리 사용량이 적다. 캐시 메모리에 좀 더 친화적이고 병렬처리에 적합하다. 

너비 우선 탐색은 언제나 최소깊이의 결과를 찾는다. 깊이가 무한인 트리에도 사용이 가능하다. 

### 그래프에서 조금 문제가 될 수도 있는 DFS, BFS
그래프란, 노드들끼리 연관이 있는 것이다. 그들을 엣지로 연결해주는 것이다. 부모 자식관계가 있지는 않다. 

그러한 노드 사이에 정해진 방향이 없을 경우, 계속 루프를 돌게될 수 있다. 

그래서 방문했던 노드를 기억해야한다. 
그러나 1차원 배열이 아니기 때문에, 인접 행렬을 트래킹해야한다. 

### 미니맥스(틱택토)= 최대 손실이 나는 경우를 최소화한다. 
트리 알고리듬을 통해서 진행 가능하다. 

### 틱택토 평가 함수.
내가 이기면 +10점, 상대방이 이기면 -10점인 점수 매기기 규칙이 있다고 해보자. 
이 때 최대 손실을 최소화해야한다. 

리프 노드로 와야만 게임이 끝난 줄 알 수 있다. 

평가는 리프노드에서부터 시작한다. 

상대방이 수를 놓는 상황에서는 Min, 내가 해야할 때는 Max 값을 취한다. 

이런 미니맥스 알고리듬은,
- 최악의 경우 발생할 수 있는 손실을 최소화하는 규칙이다
- 게임이론, 결정이론, 통계학, 철학 등에 널리 사용된다. 
- 제로섬 게임의 결정 알고리듬으로 적합하다. 
- 여기서 가정하는 것은 상대방도 최적의 결정을 내린다는 것이다.
- 게임이 순수히 전략적이어야한다. 


### 깊이 제한 미니맥스

아무래도 처음에 시작할 때가 많은 경우의 수가 있다. 최근 컴퓨터들은 이를 다 계산할 수 있지만, 

모든 계산을 못하는 경우, 특정 깊이까지만 게임 트리를 만들게된다. 

마지막 깊이에서 점수를 계산해야한다. 즉 근사치일수밖에 없고, 이를 평가할 함수를 만들어야한다.

### 미니맥스 알고리듬 성능
기준은 두 가지다. 
1. 점수 계산 함수가 얼마나 뛰어난가? 계산 함수가 얼마나 훌륭한가?
2. 얼마나 깊이 볼 수 있는가? 계산이 얼마나 빠른가? 힌트: 이미 방문했던 노드는 다시 깊이 들어갈 필요가 없다. 

```java
public class TicTacToe {
    public static final int BOARD_SIZE = 9;
    private TicTacToe(){

    }

    public static int getBestMoveIndex(final Player[] board, final Player player) {
        assert (board.length == BOARD_SIZE);
        Player opponent = player == Player.O? Player.X : Player.O;

        Move move = getBestMoveRecursive(board, player, opponent, player);

        return move.getIndex();
    }
    private static Move getBestMoveRecursive(final Player[] board, final Player player, final Player opponent, final Player turn) {
        assert(board.length == BOARD_SIZE);

        if(hasWon(board, opponent)){
            return new Move(-1, -10);
        }
        if(hasWon(board, player)){
            return new Move(-1, 10);
        }

        ArrayList<Integer> availableIndexes = getEmptyIndexes(board);

        if(availableIndexes.isEmpty()){
            return new Move(-1, 0);
        }

        ArrayList<Move> moves = new ArrayList<>();

        for(int i = 0; i< availableIndexes.size(); ++i){
            int index = availableIndexes.get(i);
            Player[] newBoard = copyBoard(board);

            newBoard[index] = turn;

            Player nextPlayer = turn == player? opponent:player;

            int score = getBestMoveRecursive(newBoard, player, opponent, nextPlayer).getScore();

            Move move = new Move(index, score);
            moves.add(move);

        }
        if(turn == player) {
            return getMaxScoreMove(moves);
        }
        return getMinScoreMove(moves);
    }
}
```