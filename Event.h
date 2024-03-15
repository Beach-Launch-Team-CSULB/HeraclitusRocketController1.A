// This file was generated by Hunter >:) 


/*#ifndef EVENT_H
#define EVENT_H

#include <string>

enum State {READY, RUNNING, SUSPENDED, BLOCKED};

class Event {
public:
    Event(std::string name, int id, State state, int priority = 0);
    
    // Virtual destructor for proper cleanup of derived types
    virtual ~Event() {}

    std::string getName() const;
    int getId() const;
    State getState() const;
    int getPriority() const;
    void setState(State state);
    void setPriority(int priority);
    virtual void run() {};
private:
    std::string name;
    State state;
    int priority;
    int id;
};

#endif // EVENT_H
*/