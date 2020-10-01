#include "dispmapvideotesting.h"
#include "depthmapvideotesting.h"

int main()
{
	try
	{
		videoCameraDepthTest(325, 150);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}