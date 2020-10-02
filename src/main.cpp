#include "dispmapvideotesting.h"
#include "depthmapvideotesting.h"

int main()
{
	try
	{
		videoCameraDepthBfTest();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}