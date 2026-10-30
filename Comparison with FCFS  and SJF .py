
processes = [
    ["P1", 3, 3],
    ["P2", 2, 5],
    ["P3", 5, 4],
    ["P4", 1, 3],
    ["P5", 6, 2]
]

print("========== SJF ==========")

ready = processes.copy()
time = 0
result = []

while ready:
    available = []

    for p in ready:
        if p[1] <= time:
            available.append(p)

    if not available:
        time = min(ready, key=lambda p: p[1])[1]
        continue

    job = min(available, key=lambda p: p[2])
    ready.remove(job)

    name = job[0]
    at = job[1]
    bt = job[2]

    ct = time + bt
    tat = ct - at
    wt = tat - bt

    result.append([name, at, bt, ct, tat, wt])
    time = ct

print("PD  AT  BT  CT  TAT WT")

for p in result:
    print(*p)

print("Average TAT =", sum(p[4] for p in result) / len(result))
print("Average WT =", sum(p[5] for p in result) / len(result))

print("\nExecution Sequence:")
for p in result:
    print(p[0], end=" ")

print("\n\n========== FCFS ==========")

processes.sort(key=lambda p: p[1])

time = 0
result = []

for p in processes:
    name = p[0]
    at = p[1]
    bt = p[2]

    if time < at:
        time = at

    ct = time + bt
    tat = ct - at
    wt = tat - bt

    result.append([name, at, bt, ct, tat, wt])
    time = ct

print("PD  AT  BT  CT  TAT WT")

for p in result:
    print(*p)

print("Average TAT =", sum(p[4] for p in result) / len(result))
print("Average WT =", sum(p[5] for p in result) / len(result))

print("\nExecution Sequence:")
for p in result:
    print(p[0], end=" ")
