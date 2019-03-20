#!/bin/zsh

SHELL=../42sh
TESTS=basic.tests
TRACES=basic.traces
TRACE_BUF=buf
RIGHT=basic.right
DEFAULT='\x1b[0m'
GREEN='\x1b[32m'
RED='\x1b[31m'

rm -rf $TRACES $TRACE_BUF newfile test.txt test
echo "=============TESTING...=============\n" | tee -a $TRACES
$SHELL $TESTS 2> /dev/null | tee -a $TRACE_BUF
cat $TRACE_BUF >> $TRACES
rm -rf newfile test.txt test
echo "\n=============DIFFERENCE=============\n" | tee -a $TRACES
diff -Ew $RIGHT $TRACE_BUF
RET=$?
diff -Ewc $RIGHT $TRACE_BUF >> $TRACES
if (($RET == 0)); then
    echo "\n==========ALL TESTS PASSED==========\n" >> $TRACES
    echo "\n$GREEN==========ALL TESTS PASSED==========$DEFAULT"
    echo "            (＃￣0￣)              " | tee -a $TRACES
else
    echo "\n==========SOME TESTS FAILED=========\n" >> $TRACES
    echo "\n$RED==========SOME TESTS FAILED=========$DEFAULT"
    echo "              (︶︹︺)              " | tee -a $TRACES
fi
rm $TRACE_BUF
