#include<stdio.h>
#include<stdlib.h>

int func()
{

	printf("[%s] START\n",__FUNCTION__);
	printf("[%s] END\n",__FUNCTION__);
	return 0;
}



int funb()
{
	printf("[%s] START\n",__FUNCTION__);
	printf("[%s] call func \n",__FUNCTION__);
	func();
	printf("[%s] func back\n",__FUNCTION__);
	printf("[%s] END\n",__FUNCTION__);
	return 0;
}



int funa()
{

	printf("[%s] START\n",__FUNCTION__);
	printf("[%s] call funb\n",__FUNCTION__);
	funb();
	printf("[%s] funb back\n",__FUNCTION__);
	printf("[%s] END\n",__FUNCTION__);
	return 0;
}

int main()
{
	
	printf("[%s] START\n",__FUNCTION__);
	printf("[%s] call funa \n",__FUNCTION__);
	funa();
	printf("[%s] funa back\n",__FUNCTION__);
	printf("[%s] START\n",__FUNCTION__);
	return 0;
}






















