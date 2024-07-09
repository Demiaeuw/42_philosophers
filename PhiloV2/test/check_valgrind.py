import sys
import subprocess

if len(sys.argv) < 2:
    print("Usage: python3 check_valgrind.py <command>")
    sys.exit(1)

command = sys.argv[1:]

process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stdout, stderr = process.communicate()

if b"definitely lost: 0 bytes" in stderr and b"indirectly lost: 0 bytes" in stderr:
    print("Memory Leak Test Passed")
    sys.exit(0)
else:
    print("Memory Leak Test Failed")
    print(stderr.decode())
    sys.exit(1)
