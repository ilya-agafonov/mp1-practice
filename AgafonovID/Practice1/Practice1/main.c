#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Rus");
    int dvp = 1100, dsp = 750, wood = 700;
    float m, p, v; // m  - �����, p - ���������, v - �����
    float h, w, d, m1, m2, m3, m4, m5;
    float w_polok, m_polok; // ������ � ����� �����

    printf("������� ������, ������ � �������(������ �� 180 �� 220 ��, ������ �� 80 �� 120 ��, ������� �� 50 �� 90 ��):\n");
    scanf("%f %f %f", &h, &w, &d);
    while (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90) {
        printf("�������� ������. ���������� �����:\n");
        scanf("%f %f %f", &h, &w, &d);
    }
    //��������� � �����
    h /= 100; 
    w /= 100;
    d /= 100; 

    m1 = dvp * h * w * 0.005; // ����� ������ ������
    m2 = 2 * dsp * h * d * 0.015; // ����� ���� �������
    m3 = 2 * dsp * d * w * 0.015; // ����� ������� � ������ ������
    m4 = wood * h * 0.01 * w; // ����� ���� ������
    w_polok = w - 0.015 * 2; // ������� ������� �����
    m5 = dsp * d * w_polok * 0.015; // ����� ����� �����

    int k_polok = 0;
    while (h > 0.415) {
        h = h - 0.4 - 0.015;
        k_polok++;
    }
    m_polok = m5 * k_polok;

    m = m1 + m2 + m3 + m4 + m_polok;

    printf("����� ����� %f ��", m);

    return 0;
}
