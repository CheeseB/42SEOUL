#! /bin/sh
cat /etc/passwd | grep -v '#' | awk '{if(!(NR % 2))print}' | cut -d ':' -f 1 | rev | sort -r | awk '{if(NR >= '$FT_LINE1' && NR <= '$FT_LINE2')print}' | paste -sd ',' - | sed 's/,/, /g' | sed 's/$/&./' | tr -d '\n'
