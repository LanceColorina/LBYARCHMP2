# LBYARCHMP2


nasm -f win64 MP2asm.asm
gcc -c LBYARCHMP.c -o LBYARCHMP.obj -m64
gcc LBYARCHMP.obj MP2asm.obj -o MP.exe -m64
MP.exe







1048576 - 2^20
16777216 - 2^24
268435456 - 2^28
1073741824 - 2^30
