#include <limits> // std::numeric_limits
#include <random>

#include "catch.hpp"
#include "Matrix.hpp"

//for generating random integers
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> rnd_p(0, 9); //random numbers on the closed interval [0, 9]
std::uniform_int_distribution<> rnd_pn(-9, 9); //random numbers on the closed interval [-9, 9]

bool DEBUG = true;

TEST_CASE( "Default constructor", "[Matrix]" )
{
  INFO("Hint: create an empty 2-by-2 matrix");
  Matrix A;

  //check dimensions to avoid invalid memory access 
  REQUIRE(A.size(1) == 2);
  REQUIRE(A.size(2) == 2);

  //check elements
  std::size_t i, j;
  
  for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++)
      REQUIRE(A.e(i,j) == 0);
}

/** 
 * NOTE: the below test cases are not comprehensive/complete/correct so you must supplement them.  They are only 
 * meant to invoke a particular method to force you to write stubs for all your methods.  This should ensure 
 * that your code will at least compile on the autograder because the instructor test code calls every method in
 * the header file and without at least a stub an error is produced.
 */
TEST_CASE( "Parameterized constructor 1", "[Matrix]" )
{
  INFO("Hint: create an empty matrix of user-supplied dimensions");
  Matrix A(2,2); 

  REQUIRE(A.equal(A));
}

TEST_CASE( "Parameterized constructor 2", "[Matrix]" )
{
  INFO("Hint: Use the parameters to set the matrix elements, vector");
  std::vector<Elem> elements;
  
  //get random values for a matrix
  for (int i = 0; i < 4; i++)
    elements.push_back(rnd_p(gen));

  Matrix A(elements,2);

  REQUIRE(A.equal(A));
  
}

TEST_CASE( "Parameterized constructor 3", "[Matrix]" )
{
  INFO("Hint: Use the parameters to set the matrix elements, array");
  Elem elements[4] = {1, 0, 0, 1};

  Matrix A(elements,2,2);

  REQUIRE(A.equal(A));
}

TEST_CASE( "Element get", "[Matrix]" )
{
  INFO("Hint: Returns the element at specified row, column index");
  Matrix A;

  REQUIRE(A.e(0,0) == 0);
}


TEST_CASE( "Method size", "[Matrix]" )
{
  INFO("Hint: Sets the element at specified row, column index to given value");
  Matrix A;

  REQUIRE(A.size(1) == 2);
}

TEST_CASE( "Method equal", "[Matrix]" )
{
  INFO("Hint: Returns true if two matrices are the same, false otherwise");
  Matrix A, B;

  REQUIRE(A.equal(B));
}

TEST_CASE( "Method add", "[Matrix]" )
{
  INFO("Hint: Addition of matrices");
  Matrix A, B, C;

  A = B.add(C);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method sub", "[Matrix]" )
{
  INFO("Hint: Subtraction of matrices");
  Matrix A, B, C;

  A = B.sub(C);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method matrix mult", "[Matrix]" )
{
  INFO("Hint: Multiplication of matrices");
  Matrix A, B, C;

  A = B.mult(C);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method scalar mult", "[Matrix]" )
{
  INFO("Hint: Multiplication of matrix by a scalar");
  Matrix A;
  Scalar k = 1;

  A = A.mult(k);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method pow", "[Matrix]" )
{
  INFO("Hint: Matrix raised to a given power");
  Matrix A;
  Scalar k = 1;

  A = A.pow(k);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method trans", "[Matrix]" )
{
  INFO("Hint: Transpose matrix");
  Matrix A;

  A = A.trans();
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method cat", "[Matrix]" )
{
  INFO("Hint: Vertical or horizontal concatenation of two matrices");
  Matrix A, B, C;

  A = B.cat(C,1);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method invMod", "[Matrix]" )
{
  INFO("Hint: Modular multiplicative inverse, using the modulus m, of a matrix");
  Matrix A;

  A = A.invMod(29);
  
  REQUIRE(A.equal(A));
}

TEST_CASE( "Method rowSwitch", "[Matrix]" )
{
  INFO("Hint: Switch (swap) rows within the matrix (in-place operation)");
  Matrix A;
  
  REQUIRE(A.rowSwitch(1,2) == false);
}

TEST_CASE( "Method rowMult", "[Matrix]" )
{
  INFO("Hint: Multiply a row within the matrix by a scalar (in-place operation)");
  Matrix A;
  Scalar k = 1;
  
  REQUIRE(A.rowMult(1,k) == false);
}

TEST_CASE( "Method rowAdd", "[Matrix]" )
{
  INFO("Hint: Replace a row with the sum of itself and the scalar multiple of another row (in-place operation)");
  Matrix A;
  Scalar k = 1;
  
  REQUIRE(A.rowAdd(1,2,k) == false);
}

// My Tests
TEST_CASE("My 2nd Constructor", "[Matrix]"){
  std::vector<Elem> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::size_t cols = 3;

  Matrix A(elements, cols);

  REQUIRE(A.equal(A));
  
}

TEST_CASE( "My 3rd constructor", "[Matrix]" )
{
  INFO("Hint: Use the parameters to set the matrix elements, array");
  Elem elements[4] = {1, 0, 0, 1};
  std::vector<Elem> elements2 = {1,0,0,1};


  Matrix A(elements,2,2);
  Matrix B(elements2, 2);

  REQUIRE(A.equal(B));
}

TEST_CASE("My Method equal", "[Matrix]")
{
  INFO("Check if two matrices are equal to each other")
  std::vector<Elem> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<Elem> elements2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::size_t cols = 3;
  Matrix A(elements, cols);
  Matrix B(elements2, cols);
  
  REQUIRE(A.equal(B));

}

TEST_CASE("Method- Matrix add 1", "[Matrix]")
{
  INFO("Add two matrices together")
  std::vector<Elem> elements = {1, 0, 3, 0, 0, 6, 7, 8, 0};
  std::vector<Elem> elements2 = {1, 2, 0, 4, 5, 6, 7, 0, 9};
  std::size_t cols = 3;
  Matrix A(elements, cols);
  Matrix B(elements2, cols);

  std::vector<Elem> summed_elements = {2, 2, 3, 4, 5, 12, 14, 8, 9};
  Matrix C(summed_elements,cols);

  Matrix D = A.add(B);

  REQUIRE(D.equal(C));

}

TEST_CASE("Method- Matrix add 2", "[Matrix]")
{
  INFO("Add two matrices together")
  std::vector<Elem> elements = {1, 0, 3, 0, 0, 6, 7, 8, 0, 0, 3, 2};
  std::vector<Elem> elements2 = {1, 2, 0, 4, 5, 6, 7, 0, 9, 0, 0, 1};
  std::size_t cols = 4;
  Matrix A(elements, cols);
  Matrix B(elements2, cols);

  std::vector<Elem> summed_elements = {2,2,3,4,5,12,14,8,9,0,3,3};
  Matrix C(summed_elements,cols);

  Matrix D = A.add(B);

  REQUIRE(D.equal(C));

}

TEST_CASE("Method- Matrix sub 1", "[Matrix]")
{
  INFO("Subtract two matrices together")
  std::vector<Elem> elements = {1, 0, 3, 0, 0, 6, 7, 8, 0, 0, 3, 2};
  std::vector<Elem> elements2 = {1, 2, 0, 4, 5, 6, 7, 0, 9, 0, 0, 1};
  std::size_t cols = 4;
  Matrix A(elements, cols);
  Matrix B(elements2, cols);

  std::vector<Elem> summed_elements = {0,-2,3,-4,-5,0,0,8,-9,0,3,1};
  Matrix C(summed_elements,cols);

  Matrix D = A.sub(B);

  REQUIRE(D.equal(C));

}

TEST_CASE("Method- Matrix Mult 1", "[Matrix]")
{
  INFO("Multiply two matrices together")

  std::vector<Elem> elements = {1, 0, 3, 0, 0, 6, 7, 8, 0, 0, 3, 2};
  std::size_t cols1 = 4;
  Matrix A(elements, cols1);

  std::vector<Elem> elements2 = {4,0,2,4,0,2,9,0};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);

  std::vector<Elem> elements3 = {4,6,84,38,18,6};
  std::size_t cols3 = 2;
  Matrix D(elements3, cols3);

  Matrix C = A.mult(B);

  REQUIRE(C.equal(D));

}

TEST_CASE("Method- Matrix Mult Scalar 1", "[Matrix]")
{
  INFO("Multiply a matrix by a scalar value")

  std::vector<Elem> elements = {1, 0, 3, 0, 0, 6, 7, 8, 0, 0, 3, 2};
  std::size_t cols1 = 4;
  Matrix A(elements, cols1);

  std::vector<Elem> elements2 = {2, 0, 6, 0, 0, 12, 14, 16, 0, 0, 6, 4};
  std::size_t cols2 = 4;
  Matrix B(elements2, cols2);

  Matrix C = A.mult(2);


  REQUIRE(C.equal(B));

}


TEST_CASE("Method- Matrix Power", "[Matrix]")
{
  INFO("Multiply matrix by itself k times ")

  std::vector<Elem> elements = {2,2,2,2};
  std::size_t cols1 = 2;
  Matrix A(elements, cols1);

  std::vector<Elem> elements2 = {8,8,8,8};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);

  Matrix C = A.pow(2);

  REQUIRE(C.equal(B));


}

TEST_CASE("Method- Matrix Transpose", "[Matrix]")
{
  INFO("Return the transpose of a matrix")

  std::vector<Elem> elements = {1,2,3,4};
  std::size_t cols = 2;
  Matrix A(elements, cols);

  std::vector<Elem> elements2 = {1,3,2,4};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);


  Matrix C = A.trans();

  REQUIRE(C.equal(B));
}

TEST_CASE( "Method Row Switch 1", "[Matrix]" )
{
  INFO("Hint: Switch (swap) rows within the matrix (in-place operation)");
  std::vector<Elem> elements = {1,2,3,4};
  std::size_t cols = 2;
  Matrix A(elements, cols);

  std::vector<Elem> elements2 = {3,4,1,2};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);

  A.rowSwitch(0,1);

  
  REQUIRE(A.equal(B));
}

TEST_CASE( "Method row mult 1", "[Matrix]" )
{
  std::vector<Elem> elements = {1,2,3,4};
  std::size_t cols = 2;
  Matrix A(elements, cols);

  std::vector<Elem> elements2 = {3,6,3,4};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);

  A.rowMult(0,3);
  
  REQUIRE(A.equal(B));
}

TEST_CASE( "Method row add 1", "[Matrix]" )
{
  INFO("Hint: Replace a row with the sum of itself and the scalar multiple of another row (in-place operation)");
  std::vector<Elem> elements = {1,2,3,4};
  std::size_t cols = 2;
  Matrix A(elements, cols);

  std::vector<Elem> elements2 = {1,2,5,8};
  std::size_t cols2 = 2;
  Matrix B(elements2, cols2);

  A.rowAdd(1,0,2);

  std::cout << A << std::endl;
  std::cout << B << std::endl;



  REQUIRE(A.equal(B));
}

TEST_CASE( "Method rowAdd2", "[Matrix]" )
{
  INFO("Hint: Replace a row with the sum of itself and the scalar multiple of another row (in-place operation)");

  //test case: valid add
  std::vector<Elem> a = {2,0,1,0,3,0,1,0,4};

  Matrix A = Matrix(a,3);
  A.rowAdd(1,0,2);
  REQUIRE(true);
}

TEST_CASE( "Inverse Modular", "[Matrix]" )
{
  INFO("Test invmod function");
  std::vector<Elem> elements = {1,2,3,5,4,7,6,3,7,8,0,3,3,5,2,4};
  std::size_t cols = 4;
  Matrix A(elements, cols);

  std::vector<Elem> elements2 = {2,4,1,6,5,0,4,3,3,1,1,0,3,0,6,6};
  Matrix B(elements2, cols);

  Matrix C = A.invMod(7);

  std::cout << B << std::endl;
  std::cout << C << std::endl;

  REQUIRE(C.equal(B));
}
