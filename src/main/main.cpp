#include "core/log/logging.hpp"


int main(int argc, char **argv)
{

    flog << "hello from fc" << fcendl;

    fftl << "fatal from fc" << fcendl;
}