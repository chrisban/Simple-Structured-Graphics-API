#ifndef ___DataConstraint___
#define ___DataConstraint___
#include <functional>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A macro that defines formula as a lambda expression. 
/// 			Example: the expression x - y, where x and y are of type int
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
#define formula [&]()

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A macro that defines setFormula. This macro simplifies the setFormulaInt function. 
/// 			Example: setFormula(x - y), where x and y are of type int
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="x">	The expression to process/assign. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////
#define setFormula(x) setFormulaInt([&]() {return ((x)); })

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A constraint class that ensures data that depends on other data remains updated 
/// 			and valid. 
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Constraint{
public:
	static stack<Constraint *> stk;
	using Formula = function <int()>; //only need ints
	Formula default_eval = [&](){return value; };
	bool valid;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructors. 
	/// 			Default constructor: sets formula to default eval which simply returns 
	/// 			the value 
	/// 			Constructor(int& v): sets formula to default eval, and sets the value as v
	/// 			Constructor(Constraint& f): sets the default copy ctor.
	/// </summary>
	///
	/// <remarks>	Chrisban, 4/27/2015. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Constraint() : eval(default_eval){}
	Constraint(int& v) : value(v), eval(default_eval){}
	Constraint(Formula f) : eval(f){}
	Constraint(Constraint& f) = default;

	Constraint& operator=(int& i){ set(i); return *this; };
	operator int(){ return (int)get(); };

	int get();
	void set(int new_val);
	void invalidate();
	void setFormulaInt(Formula f);

private:
	Formula eval;
	int value;
	vector<Constraint *> dependents;
};

#endif // ___DataConstraint___
