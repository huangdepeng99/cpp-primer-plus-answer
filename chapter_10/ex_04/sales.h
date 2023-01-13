#ifndef SALES_H_
#define SALES_H_
namespace SALES {
	class Sales {
	public:
		static const int QUARTERS = 4;
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(const double ar[], int n);
		void setSales();
		void showSales() const;
	};
}
#endif
