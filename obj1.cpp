class car
{ 
    int speed;
    public : int* getSpeed()
    { 
        return &speed; 
    }
};

int main()
{
    car c;
    int *ptr=c.getSpeed();
    return 0;
}