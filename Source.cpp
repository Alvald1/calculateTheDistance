#include <iostream>
#include <numbers>
#define EARTH_RADIUS 6372795 //� ������
double calculateTheDistance(const double& a1, const double& b1, const double& a2, const double& b2) {//���������� ����� ����� �������: a1, b1 - ������, ������� 1 - � �����; a2, b2 - ������, ������� 2 - � �����
    // ��������� ���������� � �������
    double lat1 = a1 * std::numbers::pi / 180;
    double lat2 = a2 * std::numbers::pi / 180;
    double long1 = b1 * std::numbers::pi / 180;
    double long2 = b2 * std::numbers::pi / 180;

    // �������� � ������ ����� � ������� ������
    double cl1 = cos(lat1);
    double cl2 = cos(lat2);
    double sl1 = sin(lat1);
    double sl2 = sin(lat2);
    double delta = long2 - long1;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    // ���������� ����� �������� �����
    double y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta;

    double ad = atan2(y, x);
    double dist = ad * EARTH_RADIUS;
    return dist;
}

int main() {
    std::pair<double, double>a{ 56.309724, 44.027357 }, b{ 56.311336, 44.030097 };
    std::cout << calculateTheDistance(a.first, a.second, b.first, b.second);
    return 0;
}