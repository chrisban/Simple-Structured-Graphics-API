#include <functional>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include "../vc2013/constraints.h"

/// <summary>	The constraint stack. Initialized due to its static nature. </summary>
stack<Constraint *> Constraint::stk;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Evaluates each dependent recursively in order to accurately evaluate the constraint val.
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <returns> The recalculated constraint value of type int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

int Constraint::get(){
	if (!stk.empty()){
		this->dependents.push_back(stk.top());
	}
	if (!valid){
		this->valid = false;
		stk.push(this);
		this->value = eval();
		stk.pop();
	}
	return value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets the constraint value. If this constraint is a dependent of any others, they are
/// 			marked as invalid and require recalculation.
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="new_val">	The new value to set. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Constraint::set(int new_val){
	value = new_val;
	for (Constraint* dep : dependents){
		if (dep->valid){
			dep->invalidate();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Invalidates this constraint. All constraints dependent on this one also are marked 
/// 			as invalid.
/// </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Constraint::invalidate(){
	valid = false;
	for (auto& dep : dependents){
		if (dep->valid){
			dep->invalidate();
		}
	}
	dependents.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets formula for the constraint. </summary>
///
/// <remarks>	Chrisban, 4/27/2015. </remarks>
///
/// <param name="f">	The Formula to process. Must be integer arithmetic. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Constraint::setFormulaInt(Formula f){
	eval = f;
	invalidate();
}
