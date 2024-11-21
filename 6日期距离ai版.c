#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

// 全局变量用于存储两种日期格式下的日期
int m1, d1, y1;
int m2, d2, y2;

// 判断是否是闰年
int is_leap_year(int yr) {
    return (yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0));
}

// 计算日期是当年的第几天
int day_of_year(int month, int day, int year) {
    int days = 0;
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap_year(year)) days_in_month[1] = 29;

    for (int i = 0; i < month - 1; i++) {
        days += days_in_month[i];
    }
    return days + day;
}

// 判断日期是否有效，并返回对应规则的解析结果
int validate_date(int month, int day, int year, int label) {
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap_year(year)) days_in_month[1] = 29;

    if (month < 1 || month > 12 || day < 1 || day > days_in_month[month - 1]) return 0;

    if (label == 1) { // mmddyy
        m1 = month; d1 = day; y1 = year + 2000;
    }
    else if (label == 2) { // yymmdd
        m2 = month; d2 = day; y2 = year + 2000;
    }
    return 1;
}

// 计算两个日期之间的天数差
int calculate_date_difference(int m1, int d1, int y1, int m2, int d2, int y2) {
    if (y1 > y2 || (y1 == y2 && day_of_year(m1, d1, y1) > day_of_year(m2, d2, y2))) {
        int tmp_m = m1, tmp_d = d1, tmp_y = y1;
        m1 = m2; d1 = d2; y1 = y2;
        m2 = tmp_m; d2 = tmp_d; y2 = tmp_y;
    }

    int total_days = 0;

    // 计算整年的天数差
    for (int year = y1; year < y2; year++) {
        total_days += (is_leap_year(year) ? 366 : 365);
    }

    // 加上今年的天数差
    total_days += day_of_year(m2, d2, y2) - day_of_year(m1, d1, y1);

    return total_days;
}

// 打印日期的英文形式
void print_date_in_english(int month, int day, int year) {
    const char* month_names[] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December" };
    printf("%s %d, %d\n", month_names[month - 1], day, year);
}

int main22() {
    int a, b, c;
    while (scanf("%d/%d/%d", &a, &b, &c) != EOF) {
        int rule1 = validate_date(a, b, c, 1);
        int rule2 = validate_date(b, c, a, 2);

        if (rule1 && rule2) {
            int diff = calculate_date_difference(m1, d1, y1, m2, d2, y2);
            printf("%d\n", diff);
        }
        else if (rule1) {
            print_date_in_english(m1, d1, y1);
        }
        else if (rule2) {
            print_date_in_english(m2, d2, y2);
        }
        else {
            printf("Invalid date format\n");
        }
    }
    return 0;
}
