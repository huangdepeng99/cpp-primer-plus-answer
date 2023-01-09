#ifndef _PERSONMI_H_
#define _PERSONMI_H_
#include <string>

class Person {
private:
	std::string fname;
	std::string lname;
protected:
	virtual void Get() = 0;
	virtual void Data() const = 0;
public:
	Person() { }
	Person(const std::string & fn, const std::string & ln)
			: fname(fn), lname(ln) { }
	virtual ~Person() = 0;
	virtual void Set();
	virtual void Show() const;
};

class Gunslinger : virtual public Person {
private:
	double dtime;
	int nicks;
protected:
	void Get() override;
	void Data() const override;
public:
	Gunslinger() : dtime(0.0), nicks(0) { }
	Gunslinger(const std::string & fn, const std::string & ln,
				double dt = 0.0, int n = 0)
			: Person(fn, ln), dtime(dt), nicks(n) { }
	explicit Gunslinger(const Person & p, double dt = 0.0, int n = 0)
			: Person(p), dtime(dt), nicks(n) { }
	virtual ~Gunslinger() { }
	double Draw() const { return dtime; }
	void Set() override;
	void Show() const override;
};

class PockerPlayer : virtual public Person {
protected:
	void Get() override { }
	void Data() const override { }
public:
	PockerPlayer() { }
	PockerPlayer(const std::string & fn, const std::string & ln)
			: Person(fn, ln) { }
	explicit PockerPlayer(const Person & p)
			: Person(p) { }
	virtual ~PockerPlayer() { }
	int Draw() const;
	using Person::Set;
	void Show() const override;
};

class BadDude final : public Gunslinger, public PockerPlayer {
protected:
	void Get() override { }
	void Data() const override { }
public:
	BadDude() { }
	BadDude(const std::string & fn, const std::string & ln,
			double dt = 0.0, int n = 0)
			: Person(fn, ln), Gunslinger(fn, ln, dt, n), PockerPlayer() { }
	explicit BadDude(const Person & p, double dt = 0.0, int n = 0)
			: Person(p), Gunslinger(p, dt, n), PockerPlayer() { }
	explicit BadDude(const Gunslinger & g)
			: Person(g), Gunslinger(g), PockerPlayer() { }
	explicit BadDude(const PockerPlayer & pp, double dt = 0.0, int n = 0)
			: Person(pp), Gunslinger(pp, dt, n), PockerPlayer(pp) { }
	double Gdraw() const { return Gunslinger::Draw(); }
	int Cdraw() const { return PockerPlayer::Draw(); }
	using Gunslinger::Set;
	void Show() const override;
};

#endif
