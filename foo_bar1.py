import sys
input = sys.stdin.readline

def insr(s):
    encrypted = [char for char in s]
    decrypted = ''
    
    for letter in encrypted:
        if (letter.islower()):
            dec = chr(ord('z') - (ord(letter) - ord('a')))     
            decrypted = decrypted + dec
        else:
            decrypted = decrypted + letter
    return decrypted            

def main():
    out = insr("Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!")
    print(out)
    path = bin(7)[3:]
    print(path)

if __name__ == "__main__":
    main()



