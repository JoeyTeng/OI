#!/bin/bash
echo "Compiling..."
/bin/bash ./compile.sh "$1"
echo -e "Testcase 1:\n"
./$1 < "$1.sample.1.in" # > "$1.sample.1.out"
# cat "$1.sample.1.out"
echo
echo -e "Testcase 2:\n"
./$1 < "$1.sample.2.in" # > "$1.sample.2.out"
# cat "$1.sample.2.out"
echo
echo -e "Testcase 3:\n"
./$1 < "$1.sample.3.in" # > "$1.sample.3.out"
# cat "$1.sample.3.out"
echo
echo -e "Testcase 4:\n"
./$1 < "$1.sample.4.in" # > "$1.sample.4.out"
# cat "$1.sample.4.out"
