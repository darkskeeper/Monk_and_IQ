#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector <pair<int, int>> v;//первый int - к-во студентов, второй - iq последнего подавшего
    pair <int, int> pv;
    multiset <pair<long long, int>> ms;//long long - произведения количества студентов на курсе на сумму двух последних подавших, int - номер курса
    pair <long long, int> pms;
    int Ncourses, Nfriends, Nstudents, iq;
    long long iqsum;
    cin >> Ncourses >> Nfriends >> Nstudents;
    for (int i = 0; i < Nstudents; i++)
    {
        cin >> iq;
        pv = make_pair(1, iq);
        v.push_back(pv);
        pms = make_pair(iq, i);
        ms.insert(pms);
    }
    if (Nstudents < Ncourses)//если студентов меньше чем курсов, то дозаполняем нулями
    {
        for (int i = Nstudents; i < Ncourses; i++)
        {
            pv = make_pair(0, 0);
            v.push_back(pv);
            pms = make_pair(0, i);
            ms.insert(pms);
        }
    }
    for (int i = 0; i < Nfriends; i++)
    {
        cin >> iq;//вводим iq друга monk-a
        pms = *ms.begin();//берём указатель на самый маленький элемент в ms
        ms.erase(ms.begin());//удаляем его
        pv = v[pms.second];//второй аргумент пары указывает на номер курса в векторе
        pv.first++;//увеличиваем к-во студентов на курсе
        iqsum = (pv.second + iq)*pv.first;//сумма двух последний поступивших * кол-во студентов
        pv.second = iq;//iq последнего поступившего = iq Друга monk-a
        v[pms.second] = pv;//изменяем пару, хранящуюся в векторе
        pms = make_pair(iqsum, pms.second);//закидываем iqsum и аргумент, указывающий на номер курса в векторе
        ms.insert(pms);//пихаем обратно в ms
        cout << pms.second + 1 << " ";//выводим номер курса(+1 т.к. отсчёт от 0)
    }
    return 0;
}