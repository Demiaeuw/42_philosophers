# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 21:08:57 by acabarba          #+#    #+#              #
#    Updated: 2024/07/07 22:14:37 by acabarba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess
import re
import time
from threading import Timer

class bcolors:
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    WARNING = '\033[93m'
    ENDC = '\033[0m'

def run_command(command, timeout):
    proc = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    timer = Timer(timeout, proc.kill)
    try:
        timer.start()
        stdout, stderr = proc.communicate()
        return stdout.decode('utf-8').strip(), stderr.decode('utf-8').strip(), proc.returncode
    finally:
        timer.cancel()

def validate_output(output, expect_death, max_meals):
    lines = output.split('\n')
    keywords = ["died", "dead", "eating", "sleeping", "thinking", "takenforks", "taking forks", "bed"]
    last_timestamp = -1
    meal_counts = {}
    death_occurred = False

    for line in lines:
        match = re.match(r'^(\d+)', line)
        if match:
            timestamp = int(match.group(1))
            if timestamp < last_timestamp:
                return False, f"KO -> No timer: {line}"
            last_timestamp = timestamp
        else:
            return False, f"KO -> No timer: {line}"

        if not any(keyword in line for keyword in keywords):
            return False, f"KO -> No keyword message: {line}"

        if "died" in line or "dead" in line:
            death_occurred = True
            continue

        if death_occurred:
            return False, f"KO -> Speak after death: {line}"

        if max_meals:
            for keyword in ["eating", "sleeping", "thinking", "takenforks", "taking forks", "bed"]:
                if keyword in line:
                    philo_id = re.search(r'n° (\d+)', line).group(1)
                    meal_counts[philo_id] = meal_counts.get(philo_id, 0) + 1

    if expect_death and not death_occurred:
        return False, "KO -> Expected death did not occur"
    
    if max_meals and not all(count >= max_meals for count in meal_counts.values()):
        return False, f"KO -> Not all philosophers ate {max_meals} times"

    return True, "OK"

def run_test(test_number, command, expect_death=False, max_meals=None, timeout=15):
    print(f"test n°{test_number} : {command} : ", end='', flush=True)
    stdout, stderr, returncode = run_command(command, timeout)
    if returncode != 0:
        print(f"{bcolors.FAIL}KO -> Command failed{bcolors.ENDC}")
        return False

    result, message = validate_output(stdout, expect_death, max_meals)
    if result:
        print(f"{bcolors.OKGREEN}{message}{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}{message}{bcolors.ENDC}")
    return result

def run_memory_leak_test(command):
    stdout, stderr, returncode = run_command(f"valgrind --leak-check=full {command}", 60)
    if "definitely lost: 0 bytes" in stderr and "indirectly lost: 0 bytes" in stderr:
        return True
    return False

def run_data_race_test(command):
    stdout, stderr, returncode = run_command(f"valgrind --tool=helgrind {command}", 60)
    if "ThreadSanitizer: data race" not in stderr:
        return True
    return False

def main():
    tests = [
        ("1", "1 800 200 200", True, None),
        ("2", "5 800 200 200", False, None),
        ("3", "5 800 200 200 7", False, 7),
        ("4", "4 410 200 200", False, None),
        ("5", "4 310 200 100", True, None)
    ]

    all_tests_ok = True
    memory_leak_check = True
    data_race_check = True

    for test_number, params, expect_death, max_meals in tests:
        command = f"./philosopher {params}"
        result = run_test(test_number, command, expect_death, max_meals)
        if not result:
            all_tests_ok = False

    if run_memory_leak_test("./philosopher 5 800 200 200"):
        print(f"{bcolors.OKGREEN}Memory Leak Test 1 OK{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}Memory Leak Test 1 KO -> Memory Leak{bcolors.ENDC}")
        memory_leak_check = False

    if run_memory_leak_test("./philosopher 4 310 200 100"):
        print(f"{bcolors.OKGREEN}Memory Leak Test 2 OK{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}Memory Leak Test 2 KO -> Memory Leak{bcolors.ENDC}")
        memory_leak_check = False

    if run_data_race_test("./philosopher 5 800 200 200"):
        print(f"{bcolors.OKGREEN}Data Race Test 1 OK{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}Data Race Test 1 KO -> Data Races{bcolors.ENDC}")
        data_race_check = False

    if run_data_race_test("./philosopher 4 310 200 100"):
        print(f"{bcolors.OKGREEN}Data Race Test 2 OK{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}Data Race Test 2 KO -> Data Races{bcolors.ENDC}")
        data_race_check = False

    if all_tests_ok and memory_leak_check and data_race_check:
        print(f"{bcolors.OKGREEN}Philosopher OK{bcolors.ENDC}")
    elif all_tests_ok:
        print(f"{bcolors.WARNING}Philosopher OK but check leaks and data races{bcolors.ENDC}")
    else:
        print(f"{bcolors.FAIL}Philosopher KO{bcolors.ENDC}")

if __name__ == "__main__":
    main()
