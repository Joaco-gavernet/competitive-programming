import sys
file1 = sys.argv[1]
file2 = sys.argv[2]

lines = open(file1).readlines()
lines2 = open(file2).readlines()

if len(lines) != len(lines2):
    print("Files have different number of lines.")
    sys.exit(1)
else:
    for i in range(len(lines)):
        if lines[i].strip() != lines2[i].strip():
            sys.exit(1)
    sys.exit(0)
