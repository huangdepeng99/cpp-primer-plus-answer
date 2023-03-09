#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp {
private:
	std::string fname;
	std::string lname;
	std::string job;
protected:
	virtual const char * Self() const = 0;
public:
	abstr_emp() { }
	abstr_emp(const std::string & fn, const std::string & ln,
			  const std::string & j)
			: fname(fn), lname(ln), job(j) { }
	virtual ~abstr_emp() = 0;
	virtual void SetAll();
	virtual void ShowAll() const;
	virtual void ReadAll(std::istream & is);
	virtual void WriteAll(std::ostream & os) const;
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};

class employee final : public abstr_emp {
protected:
	const char * Self() const override { return "employee"; }
public:
	employee() { }
	employee(const std::string & fn, const std::string & ln,
			 const std::string & j)
			: abstr_emp(fn, ln, j) { }
	explicit employee(const abstr_emp & e)
			: abstr_emp(e) { }
	using abstr_emp::SetAll;
	using abstr_emp::ShowAll;
	using abstr_emp::ReadAll;
	using abstr_emp::WriteAll;
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};

class manager : virtual public abstr_emp {
private:
	int inchargeof;
protected:
	const int & InChargeOf() const { return inchargeof; }
	int & InChargeOf() { return inchargeof; }
	const char * Self() const override { return "manager"; }
public:
	manager() : inchargeof(0) { }
	manager(const std::string & fn, const std::string & ln,
			const std::string & j, int ico = 0)
			: abstr_emp(fn, ln, j), inchargeof(ico) { }
	explicit manager(const abstr_emp & e, int ico = 0)
			: abstr_emp(e), inchargeof(ico) { }
	virtual ~manager() { }
	void SetAll() override;
	void ShowAll() const override;
	void ReadAll(std::istream & is) override;
	void WriteAll(std::ostream & os) const override;
	friend std::ostream & operator<<(std::ostream & os, const manager & m);
};

class fink : virtual public abstr_emp {
private:
	std::string reportsto;
protected:
	const std::string & ReportsTo() const { return reportsto; }
	std::string & ReportsTo() { return reportsto; }
	const char * Self() const override { return "fink"; }
public:
	fink() { }
	fink(const std::string & fn, const std::string & ln,
		 const std::string & j, const std::string & rpo)
			: abstr_emp(fn, ln, j), reportsto(rpo) { }
	fink(const abstr_emp & e, const std::string & rpo)
			: abstr_emp(e), reportsto(rpo) { }
	virtual ~fink() { }
	void SetAll() override;
	void ShowAll() const override;
	void ReadAll(std::istream & is) override;
	void WriteAll(std::ostream & os) const override;
	friend std::ostream & operator<<(std::ostream & os, const fink & f);
};

class highfink final : public manager, public fink {
protected:
	const char * Self() const override { return "highfink"; }
public:
	highfink() { }
	highfink(const std::string & fn, const std::string & ln,
			 const std::string & j, const std::string & rpo,
			 int ico = 0)
			: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
			{ }
	highfink(const abstr_emp & e, const std::string & rpo, int ico = 0)
			: abstr_emp(e), manager(e, ico), fink(e, rpo) { }
	explicit highfink(const fink & f, int ico = 0)
			: abstr_emp(f), manager(f, ico) , fink(f) { }
	explicit highfink(const manager & m, const std::string & rpo)
			: abstr_emp(m), manager(m), fink(m, rpo) { }
	void SetAll() override;
	void ShowAll() const override;
	void ReadAll(std::istream & is) override;
	void WriteAll(std::ostream & os) const override;
	friend std::ostream & operator<<(std::ostream & os, const highfink & hf);
};

#endif
