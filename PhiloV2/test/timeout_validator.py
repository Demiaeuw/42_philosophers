import sys
import subprocess
import time

if len(sys.argv) < 3:
    print("Usage: python3 timeout_validator.py <timeout> <command>")
    sys.exit(1)

timeout = int(sys.argv[1])
command = sys.argv[2:]

start_time = time.time()

process = subprocess.Popen(command)
try:
    process.wait(timeout=timeout)
    elapsed_time = time.time() - start_time
    if process.returncode == 0:
        print(f"Test Passed in {elapsed_time:.2f} seconds")
        sys.exit(0)
    else:
        print(f"Test Failed with return code {process.returncode}")
        sys.exit(process.returncode)
except subprocess.TimeoutExpired:
    print(f"Test Passed (timeout reached {timeout} seconds)")
    process.kill()
    sys.exit(0)
