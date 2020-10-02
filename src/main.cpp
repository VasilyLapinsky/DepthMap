#include "dispmapvideotesting.h"
#include "depthmapvideotesting.h"

int main()
{
	try
	{
		videoCameraDepthBfTest(325, 150);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}