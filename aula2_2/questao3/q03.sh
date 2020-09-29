!/bin/bash
file="/Users/joselito/Google Drive/UnB/SOE/quest/aula2_2/questao3/sites.txt"
while IFS= read -r line
do
    wget "$line"
done <"$file"
