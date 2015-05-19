n = int( raw_input() )

t = sorted( map( int, raw_input().split( " " ) ) )

total_time = 0
cnt = 0

for i in range( 0, n ):
    if total_time > t[i]:
        continue;
    cnt += 1
    total_time += t[i]

print "%d" % (cnt)


