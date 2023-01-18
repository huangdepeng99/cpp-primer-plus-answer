#ifndef SALES_H_
#define SALES_H_
#include <string>
#include <stdexcept>

class Sales {
public:
    enum { MONTHS = 12 };   // could be a static const
    class bad_index : public std::logic_error {
    private:
        int bi;  // bad index value
    public:
        bad_index(int ix, const std::string & s);
		explicit bad_index(int ix, const char * s = "Index error in Sales object");
        virtual ~bad_index() { }
        int bi_val() const { return bi; }
    };
private:
    double gross[MONTHS];
    int year;
public:
    explicit Sales(int yy = 0);
    Sales(int yy, const double * gr, int n);
    virtual ~Sales() { }
    int Year() const { return year; }
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
};

class LabeledSales : public Sales {
public:
    class nbad_index : public bad_index {
    private:
        std::string lbl;
    public:
        nbad_index(const std::string & lb, int ix, const std::string & s);
		nbad_index(const std::string & lb, int ix, const char * s = "Index error in LabeledSales object");
        virtual ~nbad_index() { }
        const std::string & label_val() const { return lbl; }
     };
private:
    std::string label;
public:
    explicit LabeledSales(const std::string & lb = "none", int yy = 0);
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);
    virtual ~LabeledSales() { }
    const std::string & Label() const { return label; }
    double operator[](int i) const override;
    double & operator[](int i) override;
};

#endif
