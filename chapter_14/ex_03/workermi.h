#ifndef _WORKERMI_H_
#define _WORKERMI_H_
#include <string>

class Worker {		// an abstract base class
private:
    std::string fullname;
    long id;
protected:
    virtual void Get();
    virtual void Data() const;
public:
    Worker() : fullname("no one"), id(0L) { }
    Worker(const std::string & s, long n)
			: fullname(s), id(n) { }
    virtual ~Worker() = 0;		// pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker {
private:
    int panache;
protected:
    void Get() override;
    void Data() const override;
public:
    Waiter() : Worker(), panache(0) { }
    Waiter(const std::string & s, long n, int p = 0)
			: Worker(s, n), panache(p) { }
    explicit Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p) { }
	virtual ~Waiter() { }
    void Set() override;
    void Show() const override;
};

class Singer : virtual public Worker {
public:
	enum { other, alto, contralto, soprano,
			bass, baritone, tenor, end_ };
protected:
    void Get() override;
    void Data() const override;
private:
    enum { Vtypes = end_ };
	
    static const char * pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) { }
    Singer(const std::string & s, long n, int v = other)
			: Worker(s, n), voice(v) { }
    explicit Singer(const Worker & wk, int v = other)
			: Worker(wk), voice(v) { }
	virtual ~Singer() { }
    void Set() override;
    void Show() const override;
};

// multiple inheritance
class SingingWaiter final : public Singer, public Waiter {
protected:
    void Get() override;
    void Data() const override;
public:
    SingingWaiter() { }
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
			: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) { }
    explicit SingingWaiter(const Worker & wk, int p = 0, int v = other)
            : Worker(wk), Waiter(wk, p), Singer(wk, v) { }
    explicit SingingWaiter(const Waiter & wt, int v = other)
            : Worker(wt), Waiter(wt), Singer(wt, v) { }
    explicit SingingWaiter(const Singer & sg, int p = 0)
            : Worker(sg),Waiter(sg, p), Singer(sg) { }
    void Set() override;
    void Show() const override;
};

#endif
