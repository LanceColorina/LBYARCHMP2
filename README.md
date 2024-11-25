# LBYARCHMP2


nasm -f win64 MP2asm.asm
gcc -c LBYARCHMP.c -o LBYARCHMP.obj -m64
gcc LBYARCHMP.obj MP2asm.obj -o MP.exe -m64
MP.exe





TEST CASES - https://docs.google.com/document/d/1F12VF2DXUa9VVSk8pB65RLfIPQPjav55yMBcUfP_JCI/edit?usp=sharing

1048576 - 2^20:


16777216 - 2^24:


268435456 - 2^28:

