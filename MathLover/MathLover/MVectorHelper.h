#pragma once
#include "MVector.h"

namespace MathLover {
	//�������������㷨��ʵ�֣���ʱ�����Ƕ��߳�
	class MVectorHelper{
	public:
		//��������������
		static std::optional<std::vector<MVector>> OrthogonalVectors(std::vector<MVector>& data);
		//��λ����������
		static MVector UnitizationVector(const MVector &v);
		//�������ڻ�
		static std::optional<double> InnerProduct(const MVector &v1, const MVector &v2);
		//������ͬά�����������������
		static std::optional<MVector> AddVector(const MVector& v1, double x1, const MVector& v2, double x2);
		//��ӡ������
		static void PrintMVectors(std::vector<MVector> &mvecs);
	};
};
