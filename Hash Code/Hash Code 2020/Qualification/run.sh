#!/bin/zsh

/usr/local/bin/g++-9 -O3 _book.cpp -o _book.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING a:"
./_book.out <a_example.txt >a_example.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING b:"
./_book.out <b_read_on.txt >b_read_on.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING c:"
./_book.out <c_incunabula.txt >c_incunabula.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING d:"
./_book.out <d_tough_choices.txt >d_tough_choices.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING e:"
./_book.out <e_so_many_books.txt >e_so_many_books.out

# read -s -k $'?Press any key to continue.\n'
echo $fg[red]"RUNNING f:"
./_book.out <f_libraries_of_the_world.txt >f_libraries_of_the_world.out
