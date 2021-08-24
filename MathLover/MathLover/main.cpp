#include "Default.h"
#include "MVector.h"
#include "MVectorHelper.h"

int main() {

	MathLover::MVector v1(3, { 2, 1, 1 });
	MathLover::MVector v2(3, { 3, 0, 1 });
	MathLover::MVector v3(3, { 1, -1, 1 });
	std::vector<MathLover::MVector> vecs = {v1, v2, v3};
	
	//auto ret = MathLover::MVectorHelper::UnitizationVector(v1);
	auto ret = MathLover::MVectorHelper::OrthogonalVectors(vecs);

	if (ret.has_value()) {
		MathLover::MVectorHelper::PrintMVectors(ret.value());
	}

	return 0;
}