#include <algorithm>
#include <iostream>

#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
#include "tree-height.hpp"

void set_kernel_stack_size() {
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  constexpr rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result = getrlimit(RLIMIT_STACK, &rl);

  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif
}

int findMaxHeight(std::vector<Node>& nodes) {
  int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < nodes.size(); leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }

  return maxHeight;
}
