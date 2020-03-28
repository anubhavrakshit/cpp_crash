#include <cstdio>
#include <cassert>

char read_from(char *buf, int len, int index);
void write_to(char *buf, int len, int index, char data);


int main()
{
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char *upper_ptr = upper;
    
    lower[3] = 'd';
    upper_ptr[3] = 'D';

    char letter_d = read_from(lower, sizeof(lower)/sizeof(char), 3);
    char letter_D = read_from(upper, sizeof(upper)/sizeof(char), 3);

    printf("lower: %s\nupper: %s", lower, upper);
    write_to(lower, sizeof(lower)/sizeof(char), 7, 'g');    
}

char read_from(char *buf, int len, int index) {
    assert(index >= 0 && index < len);
    return buf[index];
}

void write_to(char *buf, int len, int index, char data) {
    assert(index >= 0 && index < len);
    buf[index] = data;
}