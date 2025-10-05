#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <windows.h>
#include "PointGenerator.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        std::ifstream fin("input.txt");
        if (!fin) {
            throw std::runtime_error("�� ������� ������� ����");
        }

        int N;
        fin >> N;
        if (N <= 0) {
            throw std::invalid_argument("N �� ���� ����������� ������");
        }

        double x0, y0;
        fin >> x0 >> y0;
        Point start(x0, y0);

        std::vector<Point> bases;
        double xb, yb;
        while (fin >> xb >> yb) {
            bases.emplace_back(xb, yb);
        }
        fin.close();

        if (bases.empty()) {
            throw std::invalid_argument("���� ������� ����� � ����");
        }

        PointGenerator gen(start, bases);

        std::ofstream fout("output.txt");
        if (!fout) {
            throw std::runtime_error("�� ������� ������� ���� output.txt");
        }

        for (int i = 0; i < N; i++) {
            Point p = gen();
            fout << p.x << " " << p.y << "\n";
        }

        fout.close();
        std::cout << "��������� � ���� output.txt\n";
    }
    catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}