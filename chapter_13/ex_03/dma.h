#ifndef _DMA_H_
#define _DMA_H_
// base class topDMA
class topDMA {
private:
	char *label;
    int rating;
public:
	explicit topDMA(const char * l = "null", int r = 0);
	topDMA(const topDMA & rs);
	virtual ~topDMA();
	topDMA & operator=(const topDMA & rs);
	virtual void View() const = 0;
};

// derived class baseDMA
class baseDMA final : public topDMA {
public:
	explicit baseDMA(const char * l = "null", int r = 0);
	baseDMA(const topDMA & rs);
	baseDMA & operator=(const topDMA & rs);
    void View() const override;
};

// derived class lacksDMA
class lacksDMA final : public topDMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    explicit lacksDMA(const char * c = "blank", const char * l = "null",
						int r = 0);
    lacksDMA(const char * c, const topDMA & rs);
	void View() const override;
};

// derived class hasDMA
class hasDMA final : public topDMA {
private:
    char *style;
public:
    explicit hasDMA(const char * s = "none", const char * l = "null",
					int r = 0);
    hasDMA(const char * s, const topDMA & rs);
    hasDMA(const hasDMA & rs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
	void View() const override;
};
#endif
