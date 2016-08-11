#include "LinkedList.h"

int main(int argc, char *argv[]) {
    //LinkedList list(std::cout);


    /*The method is initializes the Google framework and must be called before RUN_ALL_TESTS */
    ::testing::InitGoogleTest(&argc, argv);

    /*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro. 
    It's must be called only once in the code because multiple calls lead to conflicts and, 
    therefore, are not supported.
    */
    return RUN_ALL_TESTS();
}