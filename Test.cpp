#include "Vector.h"

#pragma warning (disable: 4244)
#pragma warning (disable: 4018)

int main() {
	size_t n = 5, m = 10, l = 15, max = 20;

	Vector <int> a(n, max);
	Vector <float> b(m, max);
	Vector <double> c(l, max);
	Vector <double> d(max, max);

	a.Create();
	b.Create();
	c.Create();
	d.Create();

	cout << "\n" << "a = " << a << "b = " << b << "c = " << c << "d = " << d << "\n";

	for (int i = 0; i < n; i++)
		b.PushBack(i - 5.2);

	Vector <float> e(b);

	a.Sort();
	e.Sort();

	for (size_t i = 0; i < m; i++)
		b.PopBack();

	for (size_t i = 0; i < n; i++)
		b.PushBack(i + 5.6);

	for (size_t i = 0; i < n; i++)
		c.PopBack();

	d = c;

	cout << "d = ";
	for (size_t i = 0; i < d.GetN(); i++)
		cout << " | " << d[i];
	cout << " |\n\n";

	d.Sort();

	cout << "\nFIRST (b) = " << b.GetFirstEl() << "\n";
	cout << "LAST (b) = " << b.GetLastEl() << "\n";

	cout << "\n" << "a = " << a << "b = " << b << "c = " << c << "d = " << d << "e = " << e << "\n\n\n";

	return 0;
}