import time
import sys

def type_lyric(line, char_delay=0.065):
    for char in line:
        print(char, end='', flush=True)
        time.sleep(char_delay)
    print()

def print_lyrics():
    lyrics = [
          "Sochu ke milni te bolaanga ki",
          "Teri taan gallaan’ch…shaayari",
          "Vekhegi mainu te sochegi* kya tu",
          "Mitti da banda main, tu taan pari...",
          "Ishqe di galiyach, khoya e dil ve",
          "Aas lagaaye ik jaaye tu mil ve",
          "Kol tere mainu",
          "aan de soni",
          "karaan* main kitne jatan O soni",
          "Dooron dooron main",
    ]
    delays = [2.0, 1.8, 2.1, 2.4, 1.7, 2.0, 2.0, 1.7, 2.3, 2.5]
    print("\n🎵 Now Playing - Dooron Dooron❤️‍🩹 \n")
    time.sleep(1.5)
    for i, line in enumerate(lyrics):
        type_lyric(line)
        time.sleep(delays[i])

print_lyrics()
time.sleep(0.02)