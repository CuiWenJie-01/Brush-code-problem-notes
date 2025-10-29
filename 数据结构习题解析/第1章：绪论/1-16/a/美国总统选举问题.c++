#include <bits/stdc++.h>
using namespace std;

// �������ж��Ƿ��ܽ����ϻ���Ϊ��������ȵ��Ӽ�
// ������S - ���������ϣ�vector����target - ÿ���Ӽ���Ŀ��ͣ����ܺ͵�һ�룩
bool canPartition(const vector<int>& S, int target) {
    int n = S.size();
    // ����һ�������Ͷ�̬�滮�� dp����СΪ (target+1)
    // dp[j] ��ʾ�Ƿ��ܴ� S ��ǰ i ��Ԫ����ѡ���Ӽ���ʹ��ǡ��Ϊ j
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : S) {
        for (int j = target; j >= num; j--) {
             // �� target �� num-1 �������dp���飬�����ظ�ʹ��ͬһԪ��
            if (dp[j - num]) {
                dp[j] = true;
                if (j == target) return true;
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> electoral_votes = {54, 38, 29, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    /*
     accumulate����
     Ĭ����ʽ��ִ�мӷ�����
     �Զ�����ʽ������ָ���κζ�Ԫ����
    */
    int total_votes = accumulate(electoral_votes.begin(), electoral_votes.end(), 0);
    
    if (total_votes % 2 != 0) {
        cout << "�ܺͲ���ż�����޷�ƽ��" << endl;
        return 1;
    }
    
    int target = total_votes / 2;
    if (canPartition(electoral_votes, target)) {
        cout << "���Ի���Ϊ�����ܺ;�Ϊ " << target << " ���Ӽ�" << endl;
    } else {
        cout << "�޷�����" << endl;
    }
    
    return 0;
}