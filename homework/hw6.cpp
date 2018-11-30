struct minimizer {
	virtual double operator()( ... ) = 0;
	virtual ~minimizer() {}
};

struct method1: struct minimizer
{
    virtual double operator() { 
        minimizer::operator();
        std::cout << "minimizing with method1" << std::endl;
    }
    virtual ~method1() {}
};

struct method2: struct minimizer
{
    virtual double operator() { 
        minimizer::operator();
        std::cout << "minimizing with method2" << std::endl;
    }
    virtual ~method2() {}
};

unique_ptr<minimizer> my_minimizer;
switch(minimizer_choice){
	case 1: my_minimizer = make_unique<method1>(new method1); break;
	case 2: my_minimizer = make_unique<method2>(new method2); break;
}
(*my_minimizer)( ... );

