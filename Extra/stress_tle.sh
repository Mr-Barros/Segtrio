P=a
TIME_LIMIT=1
make ${P} gen || exit 1
for ((i = 1; ; i++)) do
    ./gen $i > in
    timeout ${TIME_LIMIT}s ./${P} < in > out
    status=$?
    if (( status == 124 )); then
        echo "--> entrada:"
        cat in
        echo "--> saida:"
        cat out
        break;
    fi
    echo $i
done
