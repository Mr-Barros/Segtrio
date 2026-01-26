P=a
make ${P} gen || exit 1
for ((i = 1; ; i++)) do
    ./gen $i > in
    ./${P} < in > out 2> errlog
    status=$?
    if (( status != 0 )); then
        echo "--> RTE (codigo $status)"
        echo "--> entrada:"
        cat in
        echo "--> saida:"
        cat out
        echo "--> stderr:"
        cat errlog
        break;
    fi
    echo $i
done
