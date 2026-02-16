# Codex 핸드오프 문서 (업데이트: 2026-02-16)

## 프로젝트 개요
- 목적: 코딩테스트 합격을 위한 Day01~Day28 운영
- 언어: Java
- 루트 경로: `/Users/yowon/study/ps/practice`
- Day 경로: `/Users/yowon/study/ps/practice/days`

## 현재 운영 구조 (중앙+참조)
- 규칙 원본: `days/RULEBOOK.md`
- 일정/문제 배치 원본: `days/day11_2week_offer_routine/README.md`
- 실행 체크 원본: `days/PLAN_DAY1_28_EXECUTION.md`
- day01~day10 README는 RULEBOOK을 참조하는 실행 단위 문서

## 디렉토리 요약
```text
practice/
├── HANDOFF.md
├── README.md
└── days/
    ├── RULEBOOK.md
    ├── PLAN_DAY1_28_EXECUTION.md
    ├── day01_hash/
    ├── day02_bfs_dfs/
    ├── day03_impl_string/
    ├── day04_greedy_twopointer/
    ├── day05_dp/
    ├── day06_binsearch/
    ├── day07_mock1/
    ├── day08_review/
    ├── day09_sql/
    ├── day10_mock2/
    └── day11_2week_offer_routine/
```

## 현재 코드/문서 상태
- Day1~Day5: Java 풀이 파일 존재
- Day6~Day10: README 중심(코드 공백 큼)
- Day11: Day1~28 4주 일정표 + 구현 병행 트랙
- 공통 규칙은 RULEBOOK 단일 원본으로 관리

## 운영 원칙
1. 문제 교체/하향 금지
2. 실패 문제는 `T+1`, `T+3` 재도전
3. 하루 밀림 허용, 주말 회수 필수
4. 기준 미달 시 난이도 하향 대신 기간 연장
5. 매일 백지구현 1문제 필수

## 일일 실행 프로토콜
1. 당일 필수 문제 수행
2. 오답노트 3줄 작성
3. `T+1`, `T+3` 등록
4. Done Definition 5항목 체크
5. OpenClaw 일일 보고 템플릿 전송

## 합격 지표
1. 최근 모의 6회 중 4회 이상 2문제+ 해결
2. 구현 10문제 중 7문제 이상 40분 내 해결
3. 재구현률 90% 이상
4. 동일 실수 재발 주 3회 이하

## 다음 액션
1. Day1~Day3 상태칸 실진도 반영
2. Day4~Day6 코드 제출형 정리
3. Day7 모의 1회 실행
