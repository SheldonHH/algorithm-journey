   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> results;
        deque<TreeNode*> queue;
        queue.push_back(root);
        bool reverse = false;

        while (!queue.empty()) {
            int size = queue.size();
            vector<int> level(size);

            // Calculate start position and step based on whether we are reversing
            int start = reverse ? size - 1 : 0;
            int step = reverse ? -1 : 1;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = reverse ? queue.back() : queue.front();
                if (reverse) queue.pop_back(); else queue.pop_front();
                level[start + i * step] = node->val;
                
                // Enqueue child nodes in the order required for next level's processing order
                if (!reverse) {
                    if (node->left) queue.push_back(node->left);
                    if (node->right) queue.push_back(node->right);
                } else {
                    if (node->right) queue.push_front(node->right);
                    if (node->left) queue.push_front(node->left);
                }
            }
            
            results.push_back(move(level));
            reverse = !reverse;
        }
        
        return results;
    }