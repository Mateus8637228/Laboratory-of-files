/*****************************
* Автор: Дорошкевич Матвей   *
* Название: Вариант 5        *     
*****************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  ifstream fin("school.txt");
  ofstream fout("result.txt");

  if (!fin.is_open()) {
    cout << "Ошибка: не удалось открыть файл school.txt" << endl;
    return 1;
  }

  int limit;
  cout << "Введите минимальный рост: ";
  cin >> limit;

  string surname, name;
  int height, weight;

  int sumHeight = 0, sumWeight = 0;
  int countAbove = 0;
  int maxHeight = 0;
  string maxSurname, maxName;

  cout << "\nУченики с ростом выше " << limit << " см:" << endl;
  fout << "Ученики с ростом выше " << limit << " см:" << endl;

  while (fin >> surname >> name >> height >> weight) {
    if (height > maxHeight) {
      maxHeight = height;
      maxSurname = surname;
      maxName = name;
    }

    if (height > limit) {
      cout << surname << " " << name
           << ": рост " << height << " см, вес " << weight << " кг" << endl;
      fout << surname << " " << name
           << ": рост " << height << " см, вес " << weight << " кг" << endl;

      sumHeight += height;
      sumWeight += weight;
      countAbove++;
    }
  }

  if (countAbove > 0) {
    int avgHeight = sumHeight / countAbove;
    int avgWeight = sumWeight / countAbove;

    cout << "\nСредний рост: " << avgHeight << " см" << endl;
    cout << "Средний вес: " << avgWeight << " кг" << endl;

    fout << "\nСредний рост: " << avgHeight << " см" << endl;
    fout << "Средний вес: " << avgWeight << " кг" << endl;
  } else {
    cout << "\nНет учеников выше заданного роста." << endl;
    fout << "\nНет учеников выше заданного роста." << endl;
  }

  cout << "\nСамый высокий ученик: " << maxSurname << " " << maxName
       << ": " << maxHeight << " см" << endl;
  fout << "\nСамый высокий ученик: " << maxSurname << " " << maxName
       << ": " << maxHeight << " см" << endl;

  fin.close();
  fout.close();

  return 0;
}
