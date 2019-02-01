#ifndef Memento_h
#define Memento_h


class Memento {

 public:

    virtual void getState();

    virtual void setState();


 private:
    Integer state;

};

#endif // Memento_h
