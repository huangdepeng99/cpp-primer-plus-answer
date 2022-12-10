#ifndef _LIST_H_
#define _LIST_H_
namespace LIST {
	typedef int Item;
	
	class List {
	private:
		static const int MAX = 20;
		Item items[MAX];
		int size;
	public:
		List() { size = 0; };
		bool add(const Item & item);
		bool isempty() const { return size == 0; };
		bool isfull() const { return size == MAX; };
		void visit(void (*pf)(Item &));
	};
	
	void show(Item & item);
}
#endif
