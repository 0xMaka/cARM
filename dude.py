import sys
import subprocess

CHIP = 'atmega328p'
PORT = '/dev/ttyUSB0'
BAUDRATE = '19200'

if len(sys.argv) == 5:
  chip = sys.argv[1]
  port = sys.argv[2]
  baud = sys.argv[3]
  program = sys.argv[4] 

else:
  program = sys.argv[1]
  chip, port, baud = (CHIP, PORT, BAUDRATE)

command = ('avrdude' + ' -p' + chip + ' -cusbasp' + ' -P' + port +' -b' + baud + ' -Uflash:w:' + program + '.hex:i')

print command

subprocess.run(command)

CompletedProcess(args=command, returncode=0))

quit()

