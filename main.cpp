#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector <pair<int, int>> v;//������ int - �-�� ���������, ������ - iq ���������� ���������
    pair <int, int> pv;
    multiset <pair<long long, int>> ms;//long long - ������������ ���������� ��������� �� ����� �� ����� ���� ��������� ��������, int - ����� �����
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
    if (Nstudents < Ncourses)//���� ��������� ������ ��� ������, �� ����������� ������
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
        cin >> iq;//������ iq ����� monk-a
        pms = *ms.begin();//���� ��������� �� ����� ��������� ������� � ms
        ms.erase(ms.begin());//������� ���
        pv = v[pms.second];//������ �������� ���� ��������� �� ����� ����� � �������
        pv.first++;//����������� �-�� ��������� �� �����
        iqsum = (pv.second + iq)*pv.first;//����� ���� ��������� ����������� * ���-�� ���������
        pv.second = iq;//iq ���������� ������������ = iq ����� monk-a
        v[pms.second] = pv;//�������� ����, ���������� � �������
        pms = make_pair(iqsum, pms.second);//���������� iqsum � ��������, ����������� �� ����� ����� � �������
        ms.insert(pms);//������ ������� � ms
        cout << pms.second + 1 << " ";//������� ����� �����(+1 �.�. ������ �� 0)
    }
    return 0;
}