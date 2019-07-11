#ifndef TREE_ACCESSOR_H
#define TREE_ACCESSOR_H

template <typename T>
class accessor {
  public:
    // An iterator which is specifically pointing to 'node' and set at 'depth'.
    // This may be used when the call site already knows enough to actually
    // construct a pointer to the right object with the right depth.
    //
    // TODO(ghochee): This should be public to allow clients of the overall
    // library to use externally available information when creating the
    // iterator. We already allow public conversion between one type of
    // iterator to another.
    explicit accessor(raw_tree<T> *node, int16_t depth = 0)
        : node_(node), depth_(depth) {}

    accessor(const accessor &) = default;
    accessor(accessor &&) = default;
    accessor<T> &operator=(const accessor<T> &) = default;
    accessor<T> &operator=(accessor<T> &&) = default;

    bool operator==(const accessor &other) const;
    bool operator!=(const accessor &other) const;
    T &operator*() const;

    void up();

    template <side wing>
    bool down();

    template <traversal_order order, side wing>
    void next();

  private:
    template <side wing>
    void preorder_increment();
    template <side wing>
    void inorder_increment();
    template <side wing>
    void postorder_increment();

    // The node that we are pointing to currently in the tree but if depth_ ==
    // -1 this indicates the root of the tree.
    raw_tree<T> *node_ = nullptr;

    // Depth indicates the depth of the node in our tree. Root node has a depth
    // of 0 and all subsequent values are 1 more. The only valid negative value
    // is -1 which indicates that the node is at the end. In such a situation
    // the node_ is set to the root.
    //
    // Having this has a few benefits:
    // - Without a second field we will have to set node_ to a tree-neutral
    //   value to indicate end of iterator. This means we would store a pointer
    //   to a value which is completely disconnected from the tree and hence
    //   can never lead us back to the tree. This is normally fine but we would
    //   do well with this because we can reverse iterate if we have access to
    //   the original tree element.
    // - This allows us to have iterators which range only over a subtree. This
    //   seems like a pretty useful feature for writing more complex algorithms.
    // - Depth is a useful feature when iterating through a tree. Though
    //   clients can set it as part of their T value and the updates etc. are
    //   expected to update them it would be convoluted to bake it together.
    // TODO(ghochee): Should this be part of every iterator or should we have a
    // different class for having this feature as well, or is this a feature
    // for a wrapper to T that we provide to all clients and the generic
    // iterator would use it when T's type traits make it possible.
    int16_t depth_ = -1;
};

#include "accessor.hh"

#endif  // TREE_ACCESSOR_H