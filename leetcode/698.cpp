//#include<vector>
//#include<numeric>
//#include<algorithm>
//using namespace std;
//
////bool canPartitionKSubsets(vector<int>& nums, int k) {
////	if (k > nums.size())return false;
////	int total = accumulate(nums.begin(), nums.end(), 0);
////	if (total % k != 0)return false;
////	vector<int> buck(k+1, 0);
////	vector<bool> used(k,false);
////	return traceBack(nums, buck, k, used, 0, total / k);
////	
////}
////bool traceBack(vector<int>& nums, vector<int>& buck, int k, vector<bool>& used, int curnum, int target) {
////	if (k == 0) return true;
////	if (buck[k] == target)traceBack(nums, buck, k--, used, 0, target);
////	//����ÿһ��k��ÿ�����ֶ�������ѡ�񣬵���ѡ���˺�Ͳ�����ѡ���ˣ� 2^n
////	for (int i = curnum; i < nums.size(); i++) {
////		if (!used[i]) {
////			if (buck[k] + nums[i] > target)continue;
////			used[i] = true;
////			buck[k] += nums[i];
////			if(traceBack(nums, buck, k, used, curnum + 1, target))return true;
////			buck[k] -= nums[i];
////			used[i] = false;
////		}
////	}
////	return false;
////}
//bool cmp(int a, int b) {
//	return a > b;
//}
//
//bool canPartitionKSubsets(vector<int>& nums, int k) {
//	if (k > nums.size())return false;
//	int total = accumulate(nums.begin(), nums.end(), 0);
//	if (total % k != 0)return false;
//	//�Ż�һ�������齵��
//	sort(nums.begin(), nums.end(), cmp);
//	vector<int> buck(k, 0);
//	return traceBack(nums, 0, buck, total / k);
//	
//}
//bool traceBack(vector<int>& nums, int index, vector<int>& buck, int target) {
//	if (index == nums.size())return true;//������ֽ�������ж�ÿһ��Ͱ���Ƿ����target
//	
//	for (int i = 0; i < buck.size(); i++) {
//		if (i > 0 && buck[i] == buck[i - 1]) continue;//�Ż���
//		if (buck[i] + nums[index] > target)continue;
//		buck[i] += nums[index];
//		if(traceBack(nums, index + 1, buck, target))return true;
//		buck[i] -= nums[index];
//	}
//	return false;
//	
//}