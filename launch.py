#! /usr/bin/python3
from subprocess import Popen, PIPE, STDOUT

if __name__ == "__main__":
    # subprocess.call("./posix")
    p = Popen(['./posix', 'f'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)    
    grep_stdout = p.communicate(input=b'35 6 98 41 54 54 67 465\n')[0]
    print(grep_stdout.decode())
