# Day01~Day28 공통 운영 규칙 (RULEBOOK)

적용 범위: `/Users/yowon/study/ps/practice/days/day01_*` ~ `day28`

## 1) 불가침 규칙
1. 문제 목록은 교체/하향하지 않는다.
2. 못 푼 문제는 삭제하지 않고 `T+1`, `T+3` 재도전으로 해결한다.
3. 하루 밀려도 포기하지 않는다. 주말에 밀린 문제를 회수한다.
4. 기준 미달이면 난이도를 낮추지 않고 기간을 1~2주 연장한다.
5. 당일 최소 1문제 백지구현은 반드시 수행한다.

## 2) 시간/풀이 규칙
1. 1문제당 40분 제한, 초과 시 해설 확인.
2. 해설 본 문제는 24시간 내 재구현(T+1).
3. 해설 본 문제는 72시간 내 재구현(T+3).
4. 제출 전 시간복잡도 1줄을 적는다.

## 3) 오답노트 규칙
1. 문제당 3줄만 작성한다.
2. 기록 항목은 고정한다: `원인`, `정답 아이디어`, `다음 재발 방지`.

## 4) 일일 완료 기준 (Done Definition)
- [ ] `today_required_done` (당일 필수 문제 완료)
- [ ] `time_limit_applied` (40분 제한 적용)
- [ ] `wrong_note_written` (오답노트 작성)
- [ ] `retry_registered` (`T+1`, `T+3` 등록)
- [ ] `openclaw_report_sent` (일일 보고 전송)

## 5) 일일 보고 스키마 (OpenClaw 점검용)
- `date`: YYYY-MM-DD
- `day_id`: Day01~Day28
- `solved_count`: 정답 수
- `failed_count`: 실패 수
- `implementation_done`: Y/N
- `blank_coding_done`: Y/N
- `retry_t_plus_1`: 문제 목록
- `retry_t_plus_3`: 문제 목록
- `rule_violations`: 없으면 `none`
- `study_minutes`: 총 학습 시간(분)

## 6) 일일 보고 템플릿 (복붙)
```text
오늘 코테 점검해줘.
- date: YYYY-MM-DD
- day_id: DayXX
- solved_count: X
- failed_count: X
- implementation_done: Y/N
- blank_coding_done: Y/N
- retry_t_plus_1: ...
- retry_t_plus_3: ...
- rule_violations: none
- study_minutes: XXX
규칙 위반 여부와 내일 해야 할 3가지만 정해줘.
```

## 7) 주간 체크 기준
1. 모의코테 최소 1회(2시간)
2. 구현 7문제 이상
3. 24시간 재구현 완료율 90% 이상
4. 문제 교체 없이 계획 유지

## 8) 합격 판정 기준
1. 최근 모의 6회 중 4회 이상 `2문제+` 해결
2. 구현 문제 최근 10개 중 7개 이상 40분 내 해결
3. 오답 재구현률 90% 이상
4. 동일 실수 재발 주 3회 이하
