#include <stdio.h>

int main()
{
	///break: dùng trong vòng lặp với nghĩa thoát khỏi vòng lặp tức thì, bỏ qua các lệnh phía dưới nó.
	///continue: bỏ qua lần lặp hiện thời, bỏ qua tất cả lệnh phía dưới nó trong vòng lặp.
	///ví dụ:
	while (1)
	{
		printf("\n1");
		continue;
		printf("\n2");
		printf("\n3");
	}
	printf("\nKet thuc.");
	return 0;
}