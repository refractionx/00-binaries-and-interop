import ctypes
import sys

greetings = ctypes.CDLL("libgreetings-bg.dylib")
greetings.getGreetingMessage.argtype = []
greetings.getGreetingMessage.restype = ctypes.c_char_p

sys.stdout.buffer.write(greetings.getGreetingMessage());