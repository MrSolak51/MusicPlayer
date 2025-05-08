def sec_to_min(second):
    min_ = int(second/60)
    sec_ = int(second%60)
    return [min_, sec_]


sec = 125
min = sec_to_min(sec)
min_str = ""
sec_str = ""
if min[0] < 10:
    min_str = f"0{min[0]}"
if min[1] < 10:
    sec_str = f"0{min[1]}"

print(f"{min_str} : {sec_str}")