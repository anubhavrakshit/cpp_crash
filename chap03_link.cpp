#include <cstdio>
struct Element
{
    Element *next{};
    Element *prev{};
    void insert_after(Element *new_element)
    {
        new_element->next = next;
        new_element->prev = this;
        if (next)
        {
            next->prev = new_element;
        }
        next = new_element;
    }

    void insert_before(Element *new_element)
    {
        new_element->next = this;
        new_element->prev = prev;
        if (prev)
        {
            prev->next = new_element;
        }
        prev = new_element;
    }
    char prefix[2];
    short operating_number;
};

int main() 
{
    Element e1, e2, e3;
    e1.prefix[0] = 'a';
    e1.prefix[1] = 'b';
    e1.operating_number = 1;

    e2.prefix[0] = 'c';
    e2.prefix[1] = 'd';
    e2.operating_number = 2;

    e3.prefix[0] = 'e';
    e3.prefix[1] = 'f';
    e3.operating_number = 3;

    e1.insert_after(&e3);
    e3.insert_before(&e2);

    for (Element* cursor = &e1; cursor;  cursor = cursor->next) {
        printf("element %c%c-%d\n",
               cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }
    
    for (Element *cursor = &e3; cursor; cursor = cursor->prev)
    {
        printf("element %c%c-%d\n",
               cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }

    return 0;
}