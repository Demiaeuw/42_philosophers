import sys
import subprocess
import threading
import time

def run_with_timeout(cmd, timeout_sec):
    start_time = time.time()
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    timer = threading.Timer(timeout_sec, proc.kill)
    try:
        timer.start()
        stdout, stderr = proc.communicate()
        elapsed_time = time.time() - start_time
        return proc.returncode, stdout, stderr, elapsed_time
    finally:
        timer.cancel()

if len(sys.argv) < 3:
    print("Usage: python3 timeout_validator.py <timeout> <command> [args...]")
    sys.exit(1)

timeout = int(sys.argv[1])
command = sys.argv[2:]

returncode, stdout, stderr, elapsed_time = run_with_timeout(command, timeout)

if returncode == -9:  # -9 is the return code for SIGKILL
    print("Test passed: Process was killed after timeout")
    if 20 <= elapsed_time <= 22:
        sys.exit(0)
    else:
        print(f"Test failed: Process ran for {elapsed_time} seconds")
        sys.exit(1)
else:
    print(stdout.decode())
    print(stderr.decode())
    if elapsed_time < 20:
        print(f"Test failed: Execution time too short ({elapsed_time} seconds)")
        sys.exit(1)
    elif elapsed_time > 22:
        print(f"Test failed: Execution time too long ({elapsed_time} seconds)")
        sys.exit(1)
    else:
        sys.exit(0)
