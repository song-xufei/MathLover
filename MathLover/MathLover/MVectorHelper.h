#pragma once
#include "MVector.h"

namespace MathLover {
	//关于向量基本算法的实现，暂时不考虑多线程
	class MVectorHelper{
	public:
		//计算正交向量组
		static std::optional<std::vector<MVector>> OrthogonalVectors(std::vector<MVector>& data);
		//单位化正交向量
		static MVector UnitizationVector(const MVector &v);
		//两向量内积
		static std::optional<double> InnerProduct(const MVector &v1, const MVector &v2);
		//两个相同维数向量的数量积相加
		static std::optional<MVector> AddVector(const MVector& v1, double x1, const MVector& v2, double x2);
		//打印向量组
		static void PrintMVectors(std::vector<MVector> &mvecs);
	};
};
