# philosophers
[식사하는 철학자들 문제 : 위키](https://ko.wikipedia.org/wiki/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94_%EC%B2%A0%ED%95%99%EC%9E%90%EB%93%A4_%EB%AC%B8%EC%A0%9C)

### 학습
 1. 스케줄링에는 선점형과 비선점형이 있다.
 2. usleep을 통해 자발적으로 스레드 실행권을 넘겨줄 수 있음.
 3. macos에서는 Multilevel feedback queue를 사용한다. 큐가 여러개임
     * 짧은 작업에 우선권을 준다.
     * 입출력 관련 프로세스에 우선권을 준다.
     * 프로세서 사용량에 따라 프로세스를 분류한다.
     * 대기시간이 길어지는 프로세스는 에이징이라는 기법을 이용해 우선순위가 높은 큐로 이동시켜 준다.
 
 4. 추가적으로 생성되는 스레드 갯수가 많아 질 경우 컨텍스트스위칭이 더 빈번해 지는것 같았다.(cpu점유시간이 짧아짐)

### 참조
 [컨텍스트 스위칭 시점](https://kyuri107.tistory.com/entry/%EC%8A%A4%EB%A0%88%EB%93%9C-%EC%BB%A8%ED%85%8D%EC%8A%A4%ED%8A%B8-%EC%8A%A4%EC%9C%84%EC%B9%98-%EC%8B%9C%EC%A0%90-%EC%95%8C-%EC%88%98-%EC%9E%88%EB%8A%94-%EB%B0%A9%EB%B2%95)
 
 [스레드 스케줄링](https://woo-dev.tistory.com/148)
