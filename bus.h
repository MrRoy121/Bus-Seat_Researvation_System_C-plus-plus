#ifndef BUS_H
#define BUS_H

class Bus {
    
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
};

void vline(char ch);

#endif