# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 21:08:57 by acabarba          #+#    #+#              #
#    Updated: 2024/07/06 21:20:43 by acabarba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import subprocess

# Définir les couleurs ANSI pour l'affichage coloré
class bcolors:
    HEADER = '\033[95m'
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

# Fonction pour exécuter un test
def run_test(command, expected_output=None, timeout=30):
    try:
        # Exécuter la commande avec une limite de temps
        result = subprocess.run(command, shell=True, check=True, capture_output=True, text=True, timeout=timeout)
        output = result.stdout.strip()
        # Vérifier si la sortie contient le texte attendu
        if expected_output and expected_output not in output:
            return False, output
        return True, output
    except subprocess.TimeoutExpired:
        return False, "TimeOUT"
    except subprocess.CalledProcessError as e:
        return False, e.output

def main():
    # Définition des tests à exécuter
    tests = [
        {"command": "./philosopher 5 800 200 200", "description": "test n°1 : 5 800 200 200", "expected": "Philosophe n°"},
        {"command": "./philosopher 1 800 200 200", "description": "test n°2 : 1 800 200 200", "expected": "Philosophe n°"},
        {"command": "./philosopher 5 800 200 200 7", "description": "test n°3 : 5 800 200 200 7", "expected": "Philosophe n°"},
        {"command": "./philosopher 4 410 200 200", "description": "test n°4 : 4 410 200 200", "expected": "Philosophe n°"},
        {"command": "./philosopher 4 310 200 100", "description": "test n°5 : 4 310 200 100", "expected": "Philosophe n°"},
        {"command": "./philosopher 2 310 200 100", "description": "test n°6 : 2 310 200 100", "expected": "Philosophe n°"},
        {"command": "valgrind --tool=helgrind ./philosopher 5 800 200 200", "description": "helgrind test : 5 800 200 200", "expected": "Philosophe n°"},
        {"command": "valgrind --leak-check=full ./philosopher 5 800 200 200", "description": "memory leak test : 5 800 200 200", "expected": "Philosophe n°"}
    ]

    all_tests_passed = True

    # Exécution des tests
    for test in tests:
        # Affichage de la description du test
        print(f"{test['description']} : ", end="", flush=True)
        passed, output = run_test(test["command"], test["expected"])
        if passed:
            # Affichage de "OK" en vert si le test est réussi
            print(f"{bcolors.OKGREEN}OK{bcolors.ENDC}")
        else:
            # Affichage de "KO / TimeOUT" en rouge si le test dépasse le temps imparti
            if output == "TimeOUT":
                print(f"{bcolors.FAIL}KO / TimeOUT{bcolors.ENDC}")
            else:
                # Affichage de "KO" en rouge avec les détails de l'erreur
                print(f"{bcolors.FAIL}KO\nDetails: {output}{bcolors.ENDC}")
            all_tests_passed = False

    # Résumé final des tests
    if all_tests_passed:
        print(f"\n{bcolors.OKGREEN}All tests passed: Philo OK{bcolors.ENDC}\n")
    else:
        print(f"\n{bcolors.FAIL}Some tests failed: Philo KO{bcolors.ENDC}\n")

if __name__ == "__main__":
    main()
