/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * Encode method:
 * 1. Use Inorder to encode the string
 * 2. Use 5 chars to encode, first char represent if node exist
 * 3. left 4 chars encode an int to 4 chars
 */
class Codec {
public:
    void encodeNumber(int val, string& str) {
        str += (unsigned char)((val & 0xff000000) >> 24);
        str += (unsigned char)((val & 0x00ff0000) >> 16);
        str += (unsigned char)((val & 0x0000ff00) >> 8);
        str += (unsigned char)(val & 0x000000ff);
    }

    void encode(TreeNode* root, string& str) {
        str += (unsigned char)(root == nullptr ? 0 : 1);
        if (root == nullptr) {
            return;
        }
        
        encodeNumber(root -> val, str);

        encode(root -> left, str);
        encode(root -> right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        encode(root, str);
        return str;
    }

    int decodeNumber(string data, int& idx) {
        int val = 0;
        for (int i = 0; i < 4; i++) {
            val <<= 8;
            val |= (unsigned char)data[idx++];
        }
        return val;
    }

    TreeNode* decode(const string& data, int& idx) {
        if (data[idx++] == 0) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(decodeNumber(data, idx));
        node -> left = decode(data, idx);
        node -> right = decode(data, idx);
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        TreeNode* tree = decode(data, idx);
        return tree;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
