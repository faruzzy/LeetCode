// 587. Erect the Fence
// https://leetcode.com/problems/erect-the-fence/

/*
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	bool operator< (const Point& other) const {
		return this->x == other.x ? this->y < other.y : this->x < other.x;
	}
	bool operator== (const Point& other) const {
		return this->x == other.x and this->y == other.y;
	}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		if (points.empty()) {
			return {};
		}
		set<Point, Comp> rbtree(begin(points), end(points));
		vector<Point> result;
		Point end = *begin(rbtree), current = end, a(0, -1);
		while (1) {
			result.push_back(current);
			rbtree.erase(current);
			if (rbtree.empty()) {
				break;
			}
			rbtree.insert(end);
			Point next = *begin(rbtree);
			double c = -1;
			double d = numeric_limits<double>::max();
			for (const auto &i : rbtree) {
				if (i.x == current.x and i.y == current.y) {
					continue;
				}
				Point b(i.x - current.x, i.y - current.y);
				double nc = cos(a, b);
				double nd = sqrt(b.x * b.x + b.y * b.y);
				if ((fabs(nc - c) < EPS and nd < d) or (fabs(nc - c) >= EPS and nc > c)) {
					next = i;
					c = nc;
					d = nd;
				}
			}
			if (next.x == end.x and next.y == end.y) {
				break;
			}
			a.x = next.x - current.x;
			a.y = next.y - current.y;
			current = next;
		}
		return result;
	}
private:
	struct Comp {
		bool operator() (const Point& a, const Point& b) {
			return a.x == b.x ? a.y < b.y : a.x < b.x;
		}
	};
	double cos(const Point& a, const Point& b) {
		return double(a.x * b.x + a.y * b.y) / double (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y));
	}
	double EPS = 1E-9;
};

int main(void) {
	Solution solution;
	vector<Point> points, result, answer;

	points = {{0, 8}, {0, 10}, {0, 23}, {0, 30}, {0, 33}, {0, 52}, {0, 62}, {0, 68}, {0, 69}, {0, 86}, {0, 89}, {1, 8}, {1, 23}, {1, 24}, {1, 26}, {1, 31}, {1, 36}, {1, 37}, {1, 52}, {1, 67}, {1, 71}, {1, 72}, {1, 75}, {1, 90}, {2, 17}, {2, 18}, {2, 32}, {2, 54}, {2, 73}, {3, 2}, {3, 7}, {3, 57}, {3, 64}, {3, 65}, {3, 93}, {4, 0}, {4, 2}, {4, 17}, {4, 31}, {4, 58}, {4, 71}, {4, 73}, {4, 82}, {4, 83}, {4, 86}, {4, 91}, {4, 97}, {5, 3}, {5, 37}, {5, 38}, {5, 46}, {5, 50}, {5, 65}, {5, 79}, {6, 5}, {6, 26}, {6, 31}, {6, 34}, {6, 36}, {6, 52}, {6, 76}, {6, 81}, {6, 83}, {6, 85}, {6, 90}, {6, 98}, {7, 23}, {7, 28}, {7, 30}, {7, 31}, {7, 93}, {8, 1}, {8, 21}, {8, 36}, {8, 42}, {8, 45}, {8, 46}, {8, 50}, {8, 52}, {8, 58}, {8, 71}, {8, 99}, {9, 29}, {9, 46}, {9, 59}, {9, 63}, {9, 70}, {9, 74}, {9, 76}, {9, 80}, {9, 99}, {10, 2}, {10, 8}, {10, 27}, {10, 33}, {10, 45}, {10, 50}, {10, 52}, {10, 62}, {10, 76}, {11, 21}, {11, 63}, {11, 67}, {11, 71}, {11, 91}, {12, 23}, {12, 29}, {12, 35}, {12, 38}, {12, 41}, {12, 44}, {12, 60}, {12, 64}, {12, 77}, {12, 78}, {12, 92}, {13, 7}, {13, 8}, {13, 9}, {13, 18}, {13, 27}, {13, 32}, {13, 59}, {13, 60}, {13, 86}, {13, 87}, {14, 2}, {14, 6}, {14, 7}, {14, 25}, {14, 39}, {14, 42}, {14, 46}, {14, 49}, {14, 53}, {14, 88}, {14, 92}, {15, 2}, {15, 3}, {15, 18}, {15, 19}, {15, 20}, {15, 25}, {15, 40}, {15, 41}, {15, 57}, {15, 77}, {15, 80}, {16, 6}, {16, 11}, {16, 18}, {16, 26}, {16, 44}, {16, 61}, {16, 78}, {16, 82}, {16, 83}, {17, 1}, {17, 4}, {17, 10}, {17, 17}, {17, 33}, {17, 34}, {17, 35}, {17, 45}, {17, 56}, {17, 74}, {17, 81}, {17, 86}, {17, 94}, {17, 99}, {18, 20}, {18, 32}, {18, 37}, {18, 51}, {18, 67}, {18, 75}, {18, 78}, {18, 80}, {18, 83}, {18, 96}, {19, 0}, {19, 22}, {19, 33}, {19, 43}, {19, 46}, {19, 69}, {19, 93}, {19, 99}, {20, 22}, {20, 28}, {20, 36}, {20, 61}, {20, 62}, {20, 66}, {20, 88}, {21, 2}, {21, 5}, {21, 8}, {21, 13}, {21, 27}, {21, 28}, {21, 34}, {21, 35}, {21, 51}, {21, 56}, {21, 81}, {21, 83}, {21, 87}, {21, 89}, {21, 90}, {21, 92}, {21, 95}, {22, 12}, {22, 24}, {22, 27}, {22, 36}, {22, 43}, {22, 46}, {22, 49}, {22, 63}, {22, 72}, {22, 84}, {23, 1}, {23, 2}, {23, 32}, {23, 43}, {23, 52}, {23, 53}, {23, 56}, {23, 63}, {23, 64}, {23, 86}, {23, 88}, {24, 13}, {24, 18}, {24, 19}, {24, 21}, {24, 51}, {24, 58}, {24, 67}, {24, 87}, {25, 19}, {25, 20}, {25, 24}, {25, 44}, {25, 52}, {25, 56}, {25, 69}, {25, 86}, {26, 14}, {26, 30}, {26, 46}, {26, 76}, {26, 95}, {27, 4}, {27, 9}, {27, 13}, {27, 26}, {27, 43}, {27, 54}, {27, 67}, {27, 68}, {27, 75}, {27, 90}, {27, 91}, {27, 95}, {27, 96}, {27, 99}, {28, 4}, {28, 8}, {28, 10}, {28, 11}, {28, 50}, {28, 56}, {28, 63}, {28, 67}, {28, 68}, {29, 4}, {29, 12}, {29, 15}, {29, 34}, {29, 38}, {29, 42}, {29, 71}, {29, 81}, {29, 84}, {29, 89}, {29, 90}, {29, 91}, {29, 95}, {30, 2}, {30, 16}, {30, 19}, {30, 23}, {30, 46}, {30, 55}, {30, 64}, {30, 79}, {30, 84}, {30, 98}, {31, 8}, {31, 10}, {31, 11}, {31, 12}, {31, 14}, {31, 24}, {31, 33}, {31, 40}, {31, 48}, {31, 55}, {31, 57}, {31, 64}, {31, 73}, {31, 85}, {31, 97}, {32, 2}, {32, 5}, {32, 6}, {32, 29}, {32, 40}, {32, 58}, {32, 60}, {32, 64}, {32, 70}, {32, 77}, {32, 78}, {32, 92}, {32, 98}, {33, 4}, {33, 8}, {33, 19}, {33, 27}, {33, 31}, {33, 33}, {33, 41}, {33, 48}, {33, 59}, {33, 61}, {33, 75}, {33, 77}, {33, 79}, {33, 88}, {33, 94}, {34, 2}, {34, 11}, {34, 23}, {34, 24}, {34, 35}, {34, 54}, {34, 59}, {34, 81}, {34, 96}, {35, 1}, {35, 9}, {35, 51}, {35, 52}, {35, 72}, {35, 73}, {35, 74}, {35, 84}, {36, 34}, {36, 38}, {36, 43}, {36, 52}, {36, 55}, {36, 65}, {36, 82}, {36, 89}, {36, 98}, {36, 99}, {37, 7}, {37, 15}, {37, 32}, {37, 33}, {37, 37}, {37, 64}, {37, 69}, {37, 74}, {37, 76}, {37, 83}, {37, 93}, {38, 9}, {38, 25}, {38, 29}, {38, 32}, {38, 50}, {38, 76}, {38, 81}, {38, 86}, {38, 91}, {38, 95}, {39, 2}, {39, 9}, {39, 14}, {39, 20}, {39, 26}, {39, 35}, {39, 36}, {39, 58}, {39, 65}, {39, 66}, {39, 68}, {39, 72}, {39, 78}, {39, 82}, {40, 7}, {40, 25}, {40, 30}, {40, 37}, {40, 40}, {40, 48}, {40, 52}, {40, 68}, {40, 99}, {41, 26}, {41, 34}, {41, 45}, {41, 55}, {41, 60}, {41, 67}, {41, 70}, {41, 72}, {41, 79}, {41, 80}, {41, 84}, {42, 13}, {42, 18}, {42, 50}, {42, 51}, {42, 52}, {42, 71}, {42, 89}, {42, 98}, {43, 10}, {43, 11}, {43, 18}, {43, 28}, {43, 39}, {43, 45}, {43, 50}, {43, 52}, {43, 54}, {43, 55}, {43, 74}, {43, 80}, {43, 82}, {43, 87}, {43, 93}, {43, 95}, {43, 98}, {44, 0}, {44, 7}, {44, 18}, {44, 20}, {44, 33}, {44, 35}, {44, 49}, {44, 54}, {44, 55}, {44, 93}, {45, 13}, {45, 15}, {45, 20}, {45, 24}, {45, 55}, {45, 77}, {45, 89}, {45, 94}, {46, 0}, {46, 10}, {46, 19}, {46, 28}, {46, 35}, {46, 37}, {46, 50}, {46, 57}, {46, 61}, {46, 79}, {46, 85}, {47, 0}, {47, 7}, {47, 10}, {47, 37}, {47, 44}, {47, 54}, {47, 71}, {47, 87}, {47, 89}, {48, 11}, {48, 13}, {48, 16}, {48, 38}, {48, 64}, {48, 65}, {48, 68}, {48, 71}, {48, 78}, {48, 87}, {48, 98}, {49, 6}, {49, 8}, {49, 14}, {49, 18}, {49, 22}, {49, 27}, {49, 33}, {49, 40}, {49, 60}, {49, 63}, {49, 68}, {49, 71}, {49, 77}, {49, 84}, {49, 85}, {49, 99}, {50, 2}, {50, 15}, {50, 25}, {50, 47}, {50, 61}, {50, 73}, {50, 78}, {51, 6}, {51, 13}, {51, 29}, {51, 36}, {51, 55}, {51, 57}, {51, 62}, {51, 69}, {51, 75}, {51, 79}, {51, 98}, {52, 14}, {52, 16}, {52, 37}, {52, 73}, {52, 89}, {52, 95}, {52, 97}, {53, 5}, {53, 8}, {53, 11}, {53, 31}, {53, 60}, {53, 64}, {53, 82}, {53, 93}, {54, 20}, {54, 21}, {54, 31}, {54, 39}, {54, 54}, {54, 61}, {54, 67}, {54, 68}, {54, 71}, {54, 84}, {54, 85}, {54, 93}, {54, 99}, {55, 3}, {55, 11}, {55, 17}, {55, 19}, {55, 44}, {55, 45}, {55, 58}, {55, 76}, {55, 78}, {55, 83}, {55, 86}, {55, 89}, {56, 7}, {56, 10}, {56, 13}, {56, 35}, {56, 44}, {56, 54}, {56, 57}, {56, 60}, {56, 68}, {56, 71}, {56, 90}, {57, 1}, {57, 29}, {57, 35}, {57, 36}, {57, 49}, {57, 60}, {57, 92}, {58, 21}, {58, 44}, {58, 45}, {58, 54}, {58, 56}, {58, 65}, {58, 66}, {58, 71}, {58, 72}, {58, 78}, {58, 86}, {58, 90}, {58, 94}, {59, 4}, {59, 15}, {59, 22}, {59, 38}, {59, 47}, {59, 48}, {59, 58}, {59, 61}, {59, 63}, {59, 65}, {59, 67}, {59, 87}, {59, 94}, {59, 99}, {60, 0}, {60, 10}, {60, 18}, {60, 28}, {60, 35}, {60, 46}, {60, 68}, {60, 89}, {61, 15}, {61, 16}, {61, 17}, {61, 56}, {61, 66}, {61, 75}, {61, 77}, {61, 86}, {61, 87}, {61, 91}, {61, 93}, {62, 9}, {62, 20}, {62, 24}, {62, 25}, {62, 26}, {62, 48}, {62, 62}, {62, 75}, {62, 87}, {62, 92}, {62, 97}, {63, 17}, {63, 24}, {63, 26}, {63, 32}, {63, 41}, {63, 48}, {63, 52}, {63, 57}, {63, 66}, {63, 71}, {63, 84}, {64, 7}, {64, 12}, {64, 16}, {64, 31}, {64, 37}, {64, 41}, {64, 43}, {64, 46}, {64, 62}, {64, 77}, {64, 91}, {65, 0}, {65, 10}, {65, 18}, {65, 20}, {65, 23}, {65, 24}, {65, 35}, {65, 40}, {65, 41}, {65, 58}, {65, 60}, {65, 66}, {65, 70}, {65, 72}, {66, 0}, {66, 2}, {66, 16}, {66, 29}, {66, 35}, {66, 36}, {66, 38}, {66, 54}, {66, 76}, {66, 77}, {66, 78}, {66, 96}, {67, 0}, {67, 6}, {67, 11}, {67, 17}, {67, 20}, {67, 22}, {67, 32}, {67, 52}, {67, 58}, {67, 63}, {67, 74}, {67, 75}, {67, 78}, {67, 86}, {67, 90}, {67, 99}, {68, 0}, {68, 7}, {68, 18}, {68, 44}, {68, 49}, {68, 50}, {68, 55}, {68, 71}, {68, 74}, {68, 77}, {68, 78}, {68, 99}, {69, 1}, {69, 7}, {69, 9}, {69, 14}, {69, 24}, {69, 28}, {69, 37}, {69, 39}, {69, 44}, {69, 45}, {69, 56}, {69, 59}, {69, 76}, {69, 80}, {69, 84}, {69, 89}, {69, 99}, {70, 18}, {70, 23}, {70, 24}, {70, 70}, {70, 76}, {70, 78}, {70, 84}, {70, 90}, {70, 92}, {71, 26}, {71, 49}, {71, 63}, {71, 64}, {71, 78}, {71, 81}, {71, 82}, {71, 98}, {71, 99}, {72, 1}, {72, 17}, {72, 25}, {72, 44}, {72, 49}, {72, 62}, {72, 65}, {72, 80}, {72, 95}, {73, 7}, {73, 15}, {73, 21}, {73, 25}, {73, 39}, {73, 62}, {73, 67}, {73, 72}, {73, 73}, {73, 96}, {74, 19}, {74, 39}, {74, 48}, {74, 57}, {74, 60}, {74, 73}, {74, 78}, {75, 4}, {75, 30}, {75, 34}, {75, 36}, {75, 41}, {75, 55}, {75, 72}, {75, 86}, {76, 24}, {76, 27}, {76, 36}, {76, 39}, {76, 55}, {76, 65}, {76, 74}, {76, 91}, {77, 0}, {77, 19}, {77, 29}, {77, 48}, {77, 51}, {77, 59}, {77, 94}, {78, 4}, {78, 35}, {78, 62}, {78, 68}, {78, 81}, {78, 89}, {78, 93}, {78, 96}, {79, 13}, {79, 17}, {79, 45}, {79, 46}, {79, 68}, {79, 70}, {79, 71}, {79, 83}, {79, 87}, {79, 93}, {80, 4}, {80, 6}, {80, 8}, {80, 28}, {80, 39}, {80, 43}, {80, 53}, {80, 63}, {80, 73}, {80, 95}, {81, 2}, {81, 9}, {81, 11}, {81, 24}, {81, 25}, {81, 26}, {81, 28}, {81, 85}, {82, 1}, {82, 17}, {82, 27}, {82, 32}, {82, 37}, {82, 39}, {82, 45}, {82, 56}, {82, 64}, {82, 71}, {82, 74}, {82, 84}, {82, 87}, {83, 1}, {83, 9}, {83, 12}, {83, 41}, {83, 50}, {83, 52}, {83, 77}, {83, 98}, {83, 99}, {84, 1}, {84, 9}, {84, 10}, {84, 13}, {84, 14}, {84, 20}, {84, 53}, {84, 63}, {84, 72}, {84, 74}, {84, 76}, {84, 77}, {84, 87}, {84, 95}, {85, 5}, {85, 6}, {85, 7}, {85, 9}, {85, 16}, {85, 48}, {85, 58}, {85, 94}, {86, 1}, {86, 6}, {86, 20}, {86, 28}, {86, 53}, {86, 63}, {86, 81}, {87, 5}, {87, 8}, {87, 18}, {87, 33}, {87, 47}, {87, 67}, {87, 75}, {87, 82}, {87, 89}, {87, 94}, {88, 17}, {88, 31}, {88, 36}, {88, 44}, {88, 47}, {88, 51}, {88, 74}, {88, 78}, {89, 1}, {89, 28}, {89, 37}, {89, 39}, {89, 53}, {89, 55}, {89, 66}, {89, 67}, {89, 73}, {89, 79}, {89, 86}, {89, 98}, {90, 14}, {90, 15}, {90, 23}, {90, 27}, {90, 31}, {90, 40}, {90, 54}, {90, 70}, {90, 78}, {91, 33}, {91, 46}, {91, 63}, {91, 89}, {91, 96}, {92, 6}, {92, 11}, {92, 12}, {92, 15}, {92, 19}, {92, 20}, {92, 41}, {92, 43}, {92, 51}, {92, 70}, {92, 91}, {92, 93}, {93, 15}, {93, 18}, {93, 20}, {93, 22}, {93, 23}, {93, 48}, {93, 49}, {93, 54}, {93, 74}, {94, 2}, {94, 30}, {94, 34}, {94, 38}, {94, 46}, {94, 58}, {94, 61}, {94, 71}, {94, 74}, {94, 75}, {94, 83}, {95, 10}, {95, 37}, {95, 38}, {95, 43}, {95, 50}, {95, 57}, {95, 71}, {95, 85}, {95, 89}, {95, 97}, {95, 99}, {96, 6}, {96, 15}, {96, 16}, {96, 21}, {96, 31}, {96, 34}, {96, 44}, {96, 60}, {96, 62}, {96, 83}, {96, 86}, {96, 91}, {96, 94}, {97, 1}, {97, 14}, {97, 31}, {97, 45}, {97, 53}, {97, 76}, {97, 90}, {98, 7}, {98, 15}, {98, 30}, {98, 33}, {98, 36}, {98, 40}, {98, 47}, {98, 48}, {98, 64}, {98, 89}, {98, 94}, {99, 12}, {99, 19}, {99, 36}, {99, 38}, {99, 42}, {99, 43}, {99, 71}, {99, 72}, {99, 76}, {99, 90}, {99, 94}, {99, 96}, {99, 99}};
	answer = {{0, 8}, {3, 2}, {4, 0}, {19, 0}, {44, 0}, {46, 0}, {47, 0}, {60, 0}, {65, 0}, {66, 0}, {67, 0}, {68, 0}, {77, 0}, {97, 1}, {99, 12}, {99, 19}, {99, 36}, {99, 38}, {99, 42}, {99, 43}, {99, 71}, {99, 72}, {99, 76}, {99, 90}, {99, 94}, {99, 96}, {99, 99}, {95, 99}, {83, 99}, {71, 99}, {69, 99}, {68, 99}, {67, 99}, {59, 99}, {54, 99}, {49, 99}, {40, 99}, {36, 99}, {27, 99}, {19, 99}, {17, 99}, {9, 99}, {8, 99}, {6, 98}, {4, 97}, {0, 89}, {0, 86}, {0, 69}, {0, 68}, {0, 62}, {0, 52}, {0, 33}, {0, 30}, {0, 23}, {0, 10}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	points = {{3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
	answer = {{0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
	answer = {{1, 1}, {2, 0}, {4, 2}, {3, 3}, {2, 4}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	points = {{1, 2}, {2, 2}, {4, 2}};
	answer = {{1, 2}, {2, 2}, {4, 2}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
