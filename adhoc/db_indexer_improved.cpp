#include <iostream>
#include <memory>
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

class IIndex {
public:
  virtual ~IIndex() = default;
  virtual void addDocument(int id, const string &text) = 0;
  virtual unordered_set<int> getDocs(const string &keyword) const = 0;
};

class InvertedIndex : public IIndex {
private:
  unordered_map<string, unordered_set<int>> index;

public:
  void addDocument(int id, const string &document) {
    for (const string &token : tokenize(document)) {
      index[token].insert(id);
    }
  }

  unordered_set<int> getDocs(const string &keyword) const override {
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
  unique_ptr<ExprNode> left = nullptr, right = nullptr;
  ExprNode(const string &v) : val(v) {}
};

class IParser {
public:
  virtual ~IParser() = default;
  virtual unique_ptr<ExprNode> parse(const string &expr) = 0;
};

class Parser : public IParser {
private:
  int precedence(const string &operation) {
    if (operation == "NOT") {
      return 3;
    } else if (operation == "AND") {
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

  unique_ptr<ExprNode> buildAST(const vector<string> &postfix) {
    stack<unique_ptr<ExprNode>> st;
    for (const string &token : postfix) {
      // cout << "[" << token << "]\n";
      if (token == "AND" || token == "OR") {
        auto right = move(st.top());
        st.pop();
        auto left = move(st.top());
        st.pop();
        auto node = make_unique<ExprNode>(token);

        node->left = move(left);
        node->right = move(right);
        st.push(move(node));

      } else if (token == "NOT") {
        auto child = move(st.top());
        st.pop();
        auto node = make_unique<ExprNode>(token);
        node->left = move(child);
        st.push(move(node));
      } else {
        st.push(make_unique<ExprNode>(token));
      }
    }
    return move(st.top());
  }

public:
  unique_ptr<ExprNode> parse(const string &expr) {
    vector<string> postfix = infixToPostfix(expr);
    return buildAST(postfix);
  }
};

class IEvaluator {
public:
  virtual ~IEvaluator() = default;
  virtual unordered_set<int> evaluate(const ExprNode *node,
                                      const unordered_set<int> &allDocIds) = 0;
};

class Evaluator : public IEvaluator {
private:
  const IIndex &index;

  unordered_set<int> intersect(unordered_set<int> a,
                               unordered_set<int> b) const {
    // cout << a.size() << " " << b.size() << "\n";
    unordered_set<int> res;
    for (int v : a) {
      if (b.count(v)) {
        res.insert(v);
      }
    }
    return res;
  }

  unordered_set<int> unite(unordered_set<int> a, unordered_set<int> b) const {
    // cout << a.size() << " " << b.size() << "\n";
    unordered_set<int> res = a;
    for (int v : b) {
      res.insert(v);
    }
    return res;
  }

public:
  Evaluator(IIndex &idx) : index(idx) {}

  // evaluate the tree
  unordered_set<int> evaluate(const ExprNode *node,
                              const unordered_set<int> &allDocIds) {
    if (!node->left && !node->right) {
      return index.getDocs(node->val);
    }

    if (node->val == "NOT") {
      auto childSet = evaluate(node->left.get(), allDocIds);
      unordered_set<int> result;
      for (int id : allDocIds) {
        if (!childSet.count(id))
          result.insert(id);
      }
      return result;
    }

    auto leftSet = evaluate(node->left.get(), allDocIds);
    auto rightSet = evaluate(node->right.get(), allDocIds);

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
  unordered_set<int> allDocIds;

  unique_ptr<IIndex> index;
  unique_ptr<IParser> parser;
  unique_ptr<IEvaluator> evaluator;

public:
  DocumentStore(unique_ptr<InvertedIndex> idx, unique_ptr<Parser> prsr,
                unique_ptr<Evaluator> eval)
      : index(move(idx)), parser(move(prsr)), evaluator(move(eval)) {}

  void addDocument(int id, const string &content) {
    docs[id] = content;
    allDocIds.insert(id);
    index->addDocument(id, content);
  }

  vector<string> query(const string &expresssion) {
    auto ast = parser->parse(expresssion);
    auto result = evaluator->evaluate(ast.get(), allDocIds);

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

  void printIndices() const {
    // Downcast for demonstration — ideally add a virtual print() in IIndex if
    // needed
    if (auto ptr = dynamic_cast<InvertedIndex *>(index.get())) {
      ptr->printIndex();
    }
  }
};

int main() {
  auto index = make_unique<InvertedIndex>();
  auto parser = make_unique<Parser>();
  auto evaluator = make_unique<Evaluator>(*index);

  DocumentStore store(move(index), move(parser), move(evaluator));
  store.addDocument(1, "name age address");
  store.addDocument(2, "name address phone");
  store.addDocument(3, "age phone city");
  store.addDocument(4, "address email");

  // store.printAllDocs();
  // store.printIndices();

  //   // Query: NOT name
  // store.query("NOT name");

  // // Query: (name AND age) OR (NOT address)
  // store.query("(name AND age) OR (NOT address)");

  vector<string> selectdDocs = store.query("( name AND age ) OR NOT address");
  cout << "Found " << selectdDocs.size() << " matching Documents:\n";
  for (string str : selectdDocs) {
    cout << str << "\n";
  }
  return 0;
}