#bin/shell/pipipi
ARGC=("$#")
ARGV=("$@")
for i in $(seq 0 2 $((ARGC-1)))
do
    cal ${ARGV[$i]} ${ARGV[$i+$1]}
done
