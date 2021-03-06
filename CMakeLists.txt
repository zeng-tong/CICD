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

add_executable(IsSubTree src/IsSubTree.cpp)

add_executable(FindPathInBinaryTree src/FindPathInBinaryTree.cpp)

add_executable(ConvertBstToLinklist src/ConvertBstToLinklist.cpp)

add_executable(BinaryTreeDepth src/BinaryTreeDepth.cpp)

add_executable(BalancedBinaryTree src/BalancedBinaryTree.cpp)

add_executable(GetNextNodeOfTree src/GetNextNodeOfTree.cpp)

add_executable(PrintShapeZOfTree src/PrintShapeZOfTree.cpp)
add_executable(Permutation src/Permutation.cpp)

add_executable(RotateString src/RotateString.cpp)

add_executable(ReverseSentence src/ReverseSentence.cpp)

add_executable(atoi src/atoi.cpp)

add_executable(Search2DMatrix src/Search2DMatrix.cpp)

add_executable(ReorderArray src/ReorderArray.cpp)

add_executable(SpiralMatrix src/SpiralMatrix.cpp)

add_executable(MajorityElement src/MajorityElement.cpp)

add_executable(ConstructSmallestNumber src/ConstructSmallestNumber.cpp)

add_executable(CountAppearingInSortedArray src/CountAppearingInSortedArray.cpp)

add_executable(SingleNumberII src/SingleNumber.cpp)

add_executable(FindDuplicated src/FindDuplicatedNumber.cpp)

add_executable(ProductExceptSelf src/ProductExceptSelf.cpp)

add_executable(TopK src/TopK.cpp)

add_executable(Strlen src/Strlen.cpp)

add_executable(Memcpy src/Memcpy.cpp)

add_executable(QuickSort src/QuickSort.cpp)

add_executable(MergeSort src/MergeSort.cpp)

add_executable(Heap src/Heap.cpp)

add_executable(DecmailToHex src/DecToHex.cpp)

add_executable(IntegerBreak src/IntegerBreak.cpp)