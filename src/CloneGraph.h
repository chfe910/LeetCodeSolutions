
#include "../MyLeetCode/stdafx.h"

/**
 * Definition for undirected graph.
 */

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		vector<UndirectedGraphNode *> srcNodes, dstNodes;
		if (node) {
			srcNodes.push_back(node);
			dstNodes.push_back(new UndirectedGraphNode(node->label));
		}

		for (size_t i = 0; i < srcNodes.size(); ++i) {
			for (auto neighbor : srcNodes[i]->neighbors) {
				auto pos = find(srcNodes.begin(), srcNodes.end(), neighbor);
				if (pos == srcNodes.end()) {
					UndirectedGraphNode *newNode = new UndirectedGraphNode(neighbor->label);
					dstNodes[i]->neighbors.push_back(newNode);
					srcNodes.push_back(neighbor);
					dstNodes.push_back(newNode);
				}
				else {
					dstNodes[i]->neighbors.push_back(dstNodes[pos - srcNodes.begin()]);
				}
			}
		}

		return node ? dstNodes[0] : nullptr;
    }
};

class Tester{
public:
    int test() {
		Solution sol;
		UndirectedGraphNode *newNode = new UndirectedGraphNode(0);
		UndirectedGraphNode *newNode1 = new UndirectedGraphNode(1);
		UndirectedGraphNode *newNode2 = new UndirectedGraphNode(5);
		newNode->neighbors.push_back(newNode1);
		newNode->neighbors.push_back(newNode2);
		newNode1->neighbors.push_back(newNode2);
		sol.cloneGraph(newNode);
        return 0;
    }
};