#ifndef Originator_h
#define Originator_h


/*
 * 
 */
class Originator {

 public:

    virtual void setMemento();

    virtual void createMemento();


 private:
    Integer state;
};

#endif // Originator_h
