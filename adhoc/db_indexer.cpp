#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> tokenize(const string &text) {
  vector<string> tokens;
  string word;
  // create stream of string based on whitespace
  istringstream ss(text);
  while (ss >> word) {
    tokens.push_back(word);
  }
  return tokens;
}

class InvertedIndex {
private:
  unordered_map<string, unordered_set<int>> index;

public:
  void addDocument(int id, const string &document) {
    for (const string &token : tokenize(document)) {
      index[token].insert(id);
    }
  }

  unordered_set<int> getDocs(const string &keyword) {
    auto it = index.find(keyword);
    if (it != index.end()) {
      return it->second;
    }
    return unordered_set<int>{};
  }

  void printIndex() {
    cout << index.size();
    for (auto &it : index) {
      cout << it.first << ": ";
      for (auto x : it.second) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
};

// AST node
struct ExprNode {
  string val;
  ExprNode *left = nullptr, *right = nullptr;
  ExprNode(string v) : val(v) {}
};

class Parser {
private:
  int precedence(const string &operation) {
    if (operation == "AND") {
      return 2;
    } else if (operation == "OR") {
      return 1;
    } else {
      return 0;
    }
  }

  vector<string> infixToPostfix(const string &query) {
    istringstream iss(query);
    vector<string> postfix;
    stack<string> ops;
    string token;

    while (iss >> token) {
      // cout << "[" << token << "]\n";
      if (token == "(") {
        ops.push(token);
      } else if (token == ")") {
        while (!ops.empty() && ops.top() != "(") {
          postfix.push_back(ops.top());
          ops.pop();
        }
        ops.pop(); // remove that last "("
      } else if (token == "AND" || token == "OR") {
        while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
          postfix.push_back(ops.top());
          ops.pop();
        }
        ops.push(token); // push the operator
      } else {
        postfix.push_back(token);
      }
    }
    while (!ops.empty()) {
      postfix.push_back(ops.top());
      ops.pop();
    }
    return postfix;
  }

  ExprNode *buildAST(const vector<string> &postfix) {
    stack<ExprNode *> st;
    for (const string &token : postfix) {
      // cout << "[" << token << "]\n";
      if (token == "AND" || token == "OR") {
        ExprNode *node = new ExprNode(token);
        node->right = st.top();
        st.pop();
        node->left = st.top();
        st.pop();
        st.push(node);
      } else {
        st.push(new ExprNode(token));
      }
    }
    return st.top();
  }

public:
  ExprNode *parse(const string &expr) {
    vector<string> postfix = infixToPostfix(expr);
    return buildAST(postfix);
  }
};

class Evaluator {
private:
  InvertedIndex &index;

  unordered_set<int> intersect(unordered_set<int> a, unordered_set<int> b) {
    // cout << a.size() << " " << b.size() << "\n";
    unordered_set<int> res;
    for (int v : a) {
      if (b.count(v)) {
        res.insert(v);
      }
    }
    return res;
  }

  unordered_set<int> unite(unordered_set<int> a, unordered_set<int> b) {
    // cout << a.size() << " " << b.size() << "\n";
    unordered_set<int> res = a;
    for (int v : b) {
      res.insert(v);
    }
    return res;
  }

public:
  Evaluator(InvertedIndex &idx) : index(idx) {}

  // evaluate the tree
  unordered_set<int> evaluate(ExprNode *node) {
    if (!node->left && !node->right) {
      return index.getDocs(node->val);
    }
    auto leftSet = evaluate(node->left);
    auto rightSet = evaluate(node->right);

    if (node->val == "AND") {
      return intersect(leftSet, rightSet);
    } else {
      return unite(leftSet, rightSet);
    }
  }
};

class DocumentStore {
private:
  unordered_map<int, string> docs;
  InvertedIndex index;
  Parser parser;

public:
  void addDocument(int id, string content) {
    docs[id] = content;
    index.addDocument(id, content);
  }

  vector<string> query(const string &expresssion) {
    ExprNode *ast = parser.parse(expresssion);
    Evaluator evaluator(index);
    unordered_set<int> result = evaluator.evaluate(ast);

    vector<string> selectdDocs;
    for (int id : result) {
      selectdDocs.push_back(docs[id]);
    }
    return selectdDocs;
  }

  void printAllDocs() {
    for (auto &it : docs) {
      cout << it.first << " " << it.second << "\n";
    }
  }

  void printIndices() { index.printIndex(); }
};

int main() {
  DocumentStore store;
  store.addDocument(1, "name age address");
  store.addDocument(2, "name address phone");
  store.addDocument(3, "age phone city");
  store.addDocument(4, "address email");

  // store.printAllDocs();
  // store.printIndices();

  vector<string> selectdDocs = store.query("(name AND age) OR address");
  cout << "Found " << selectdDocs.size() << " matching Documents:\n";
  for (string str : selectdDocs) {
    cout << str << "\n";
  }
  return 0;
}