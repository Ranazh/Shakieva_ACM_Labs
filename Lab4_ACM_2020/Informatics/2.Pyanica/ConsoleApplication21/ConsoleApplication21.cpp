#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main()
{
	string player1, player2;
	int n = 0;
	getline(cin, player1);
	getline(cin, player2);
	deque <int> nums1, nums2;

	for (int i = 0; i < player1.size(); ++i) {
		if (player1[i] != ' ') {
			nums1.push_back(player1[i] - '0');
			nums2.push_back(player2[i] - '0');
		}
	}
	int size = nums1.size();
	while (size != 0) {
		if (nums1.front() > nums2.front()) {
			if (nums1.front() == 9 && nums2.front() == 0) {
				nums2.push_back(nums1.front());
				nums2.push_back(nums2.front());
			}
			else {
				nums1.push_back(nums1.front());
				nums1.push_back(nums2.front());
			}
			nums1.pop_front();
			nums2.pop_front();
		}
		else if (nums2.front() > nums1.front()) {
			if (nums2.front() == 9 && nums1.front() == 0) {
				nums1.push_back(nums1.front());
				nums1.push_back(nums2.front());
			}
			else {
				nums2.push_back(nums1.front());
				nums2.push_back(nums2.front());
			}
			nums2.pop_front();
			nums1.pop_front();
		}
		n++;
		size = min(nums1.size(), nums2.size());
		if (n > 1000000) {
			break;
		}
	}

	if (n > 1000000) {
		cout << "botva";
	}
	else {
		if (nums1.size() != 0) {
			cout << "first " << n;
		}
		else {
			cout << "second " << n;
		}
	}
	return 0;
}
