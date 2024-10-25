# include "base.hpp"
# include "a.hpp"
# include "b.hpp"
# include "c.hpp"

Base* generate(void)
{
    int random = rand() % 3;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

// Uses dynamic_cast with pointers (returns nullptr if cast fails)
void identify(Base* p)
{
  if (dynamic_cast<A*>(p))  // Check if p can be cast to A*
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p)) // Check if p can be cast to B*
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p)) // Check if p can be cast to C*
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

// Uses dynamic_cast with references (throws exception if cast fails)
void identify(Base& p)
{
  try
  {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "A" << std::endl;
  }
  catch(const std::exception& e)
  {
    try
    {
      B& b = dynamic_cast<B&>(p);
      (void)b;
      std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
      try
      {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cout << "Unknown" << std::endl;
      }
    }
  }
}

int main (void)
{
  srand(time(0));
  Base* base1 = generate();
  Base* base = generate();

  identify(base1);
  identify(*base1);

  identify(base);
  identify(*base);

  delete base;
  delete base1;
  return 0;
}