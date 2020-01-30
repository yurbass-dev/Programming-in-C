#include <stdio.h>
int main(void)
{
	float speed;
	float size_file;
	float time_download;

	printf("Для того, чтобы узнать за которое время загрузиться файл с интернета,"
		   "\nвведите размер файла в мегабайтах:\n");
	scanf("%f", &size_file);
	printf("Также введите скорость загрузки в мегабитах в секунду:\n");
	scanf("%f", &speed);

	time_download = size_file / (speed / 8);  

	printf("Для загрузки файла размером в %.2f мегабайт при скорости %.2f мегабит в секунду,\n" 
		   "потребуеться %.2f секунд (ы).\n", size_file, speed, time_download);

	return 0;
}