#! /bin/bash

#filePass = "/Users/eyw/algorithm/ps in java/src/me/elyowon/programers"
files=(`/Users/eyw/algorithm/ps\ in\ java/src/me/elyowon/programers ls -1`)

for files in ${files[@]}
do 
  echo $files
done 


args=("$@")
for f in "${args[@]}"; 
do
  echo $f
done


