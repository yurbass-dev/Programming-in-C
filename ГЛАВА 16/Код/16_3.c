#include <stdio.h>
#include <math.h>

void scan_num(double * num);
struct rect_v transfm_polar_to_rect(struct polar_v);
void clear_str(void);

struct polar_v
{
	double magnitude;
	double angle;
};

struct rect_v
{
	double x;
	double y;
};

int main(void)
{
	struct polar_v polar_st = {1, 1};
	struct rect_v rect_st;

	while (polar_st.magnitude != 0 && polar_st.angle != 0)
	{
		printf("Для перевода из полярной системы координат в декартовую,\nвведите (для выхода 0 и 0) ");
		printf("значение модуля: ");
		scan_num(&polar_st.magnitude);
		printf("теперь введите угол (в градусах): ");
		scan_num(&polar_st.angle);

		if (polar_st.magnitude == 0 && polar_st.angle == 0)
			break;

		rect_st = transfm_polar_to_rect(polar_st);

		printf("\nВ полярной системе модуль %.2f с углом %.2f равен:\nх = %.2f и y = %.2f"
			   " в декартовой системе координат.\n\n", polar_st.magnitude, polar_st.angle, rect_st.x, rect_st.y);
	}

	puts("Программа завершена!");

	return 0;
}

struct rect_v transfm_polar_to_rect(struct polar_v polar)
{
	struct rect_v rect;

	rect.x = polar.magnitude * (cos((polar.angle * (4 * atan(1))) / 180));
	rect.y = polar.magnitude * (sin((polar.angle * (4 * atan(1))) / 180));

	return rect;
}

void scan_num(double * num)
{
	while (scanf("%lf", num) != 1)
	{
		clear_str();
		printf("Значение должно быть числом (напр. 3, 5.7, -10.2): ");
		continue;
	}
}

void clear_str(void)
{
	while(getchar() != '\n')
		continue;
}