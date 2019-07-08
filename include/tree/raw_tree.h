#include <memory>

// raw_tree is a class which is used for creating a 'raw' tree. It allows
// client users to manipulate the tree in tree like operations.
//
// T is the value type of the element stored in the tree. This is expected to
// be MoveConstructible and MoveAssignable. raw_tree<T> itself is
// MoveConstructible and MoveAssignable.
template <typename T>
class raw_tree {
  public:
    raw_tree() = delete;
    explicit raw_tree(T &&value) : value_(std::move(value)) {}
    explicit raw_tree(const T &value) : value_(value) {}
    explicit raw_tree(raw_tree &&);

    raw_tree &operator=(raw_tree &&);

    T &operator*();

    bool has_parent() const;
    raw_tree &parent();

    bool has_left() const;
    raw_tree &left();
    void attach_left(raw_tree<T> &&left);
    raw_tree detach_left();

    bool has_right() const;
    raw_tree &right();
    void attach_right(raw_tree<T> &&right);
    raw_tree detach_right();

    // O(n) call as it actually iterates through the tree to recover the
    // counts.
    size_t size() const;

  private:
    T value_;
    raw_tree *parent_ = nullptr;
    std::unique_ptr<raw_tree> left_ = nullptr, right_ = nullptr;
};

#include "tree/raw_tree.hh"
