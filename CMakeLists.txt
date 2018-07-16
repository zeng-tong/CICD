cmake_minimum_required(VERSION 3.8)
project(offer)

include_directories("include")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "excutables")

add_executable(offer ${SOURCE_FILES})

add_executable(longest_common_prefix src/LongestCommonPrefix.cpp)

add_executable(graph_circle src/GraphCircle.cpp)

add_executable(deleteDuplication src/deleteDuplication.cpp)

add_executable(circleEntry src/circleEntry.cpp)

add_executable(binaryTreeNext src/binaryTreeNextNode_inorder.cpp)

add_executable(isSymmetrical src/isSymmetrical.cpp)

add_executable(LevelPrintBinaryTree src/LevelPrintBinaryTree.cpp)

add_executable(kthOfBST src/kthOfBST.cpp)

add_executable(matrixHasPath src/hasPath.cpp)

add_executable(serializeBinaryTree src/SerializeBinaryTree.cpp)

add_executable(maxInWindows src/maxInWindows.cpp)

add_executable(Trie src/trie.cpp)

add_executable(MedianFromDataStream src/MedianFromDataStream.cpp)

add_executable(FirstUniqueCharInString src/FirstUniqueCharInString.cpp)

add_executable(MovingCount src/MovingCount.cpp)

add_executable(RegularExpressionMatching src/RegularExpressionMatching.cpp)

add_executable(IsNumeric src/IsNumeric.cpp)

add_executable(JumpGameII src/JumpGameII.cpp)

add_executable(StackSequence src/StackSequence.cpp)

add_executable(ReverseLinkList src/ReverseLinkList.cpp)

add_executable(FindLastKthNodeOfLinkList src/FindLastKthNodeOfLinkList.cpp)

add_executable(MergeList src/MergeList.cpp)

add_executable(ComplexListClone src/ComplexListClone.cpp)

add_executable(IntersectionNode src/IntersectionListNode.cpp)

add_executable(ReconstructBinaryTree src/ReconstructBinaryTree.cpp)