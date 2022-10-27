BED_EXE=/home/hawkinsw/code/bed/target/debug/bed
INPUT_FILE="build/binary"
cat ${INPUT_FILE} | ${BED_EXE} 23b1 e9 fb fe ff ff > ${INPUT_FILE}-2
cat ${INPUT_FILE}-2 | ${BED_EXE} 23b6 c3 > ${INPUT_FILE}-3
cat ${INPUT_FILE}-3 | ${BED_EXE} 22b1 48 8b 5d f8 > ${INPUT_FILE}-4
cat ${INPUT_FILE}-4 | ${BED_EXE} 22b5 e8 0c 00 00 00 > ${INPUT_FILE}-5
cat ${INPUT_FILE}-5 | ${BED_EXE} 22ba c9 e9 f6 00 00 00 > ${INPUT_FILE}-6

mv ${INPUT_FILE}-6 ${INPUT_FILE}-patched
chmod u+x ${INPUT_FILE}-patched
rm -rf ${INPUT_FILE}-2
rm -rf ${INPUT_FILE}-3
rm -rf ${INPUT_FILE}-4
rm -rf ${INPUT_FILE}-5

objdump -d ${INPUT_FILE}-patched > patched.obj
