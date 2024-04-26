class Codec {
public:
   string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "#,";
        } else {
            out << node->val << ',';
            serializeHelper(node->left, out);
            serializeHelper(node->right, out);
        }
    }

    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        if (!getline(in, val, ',')) return nullptr;
        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
