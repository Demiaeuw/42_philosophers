import sys
import subprocess

if len(sys.argv) < 2:
    print("Usage: python3 check_valgrind.py <command>")
    sys.exit(1)

command = sys.argv[1:]

process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stdout, stderr = process.communicate()

# Afficher la sortie standard et la sortie d'erreur pour le débogage
print("STDOUT:")
print(stdout.decode())
print("STDERR:")
print(stderr.decode())

# Vérifier les fuites de mémoire dans la sortie de Valgrind
if b"All heap blocks were freed -- no leaks are possible" in stderr:
    print("Memory Leak Test Passed")
    sys.exit(0)
else:
    print("Memory Leak Test Failed")
    print(stderr.decode())
    sys.exit(1)
