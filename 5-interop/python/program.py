import ctypes
import sys

# macOS
# greetings = ctypes.CDLL("libgreetings-bg.dylib")

# Linux
greetings = ctypes.CDLL("./libgreetings-bg.so")

greetings.getGreetingMessage.argtype = []
greetings.getGreetingMessage.restype = ctypes.c_char_p

sys.stdout.buffer.write(greetings.getGreetingMessage());