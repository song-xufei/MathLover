#include "MVectorHelper.h"
#include "MHelper.h"

namespace MathLover {

	//��������������
	std::optional<std::vector<MVector>> MVectorHelper::OrthogonalVectors(std::vector<MVector> &data) {
		if (data.empty())
			return std::nullopt;

		try {
			std::vector<MVector> ret(data.size(), MVector(data[0].size()));

			ret[0] = UnitizationVector(data[0]); //�˴���λ��

			int count = 0;	//����������������Ŀ
			for (unsigned int i = 1; i < data.size(); ++i) {
				MVector tmpRet = data[i]; //������λ������������, ������м�������������

				for (auto j = 0; j <= count; j++) {
					//�������ѵ�λ�������������ڻ�����Ϊ�ǵ�λ����������ֱ��Ϊ���ڸõ�λ������ͶӰ
					std::optional<double> optX = InnerProduct(ret[j], data[i]);

					if (optX != std::nullopt) {
						double x = optX.value();

						auto optVec = AddVector(tmpRet, 1, ret[j], x);

						if (optVec != std::nullopt) {
							tmpRet = optVec.value();	//������ʱ���
						}else{
							throw "Exception at Orthogonalization AddVector failed";
						}
					}
					else {
						throw "Exception at Orthogonalization: vector is not in same dimension";
					}
				}	//for (auto j = 0; j <= count; j++) {

				ret[++count] = UnitizationVector(tmpRet);
			}

			return ret;
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;

			return std::nullopt;
		}

	}


	//��λ����������
	MVector MVectorHelper::UnitizationVector(const MVector & v) {
		double sum = 0;
		for (int i = 0; i < v.size(); ++i) {
			sum = sum + v[i] * v[i];
		}

		sum = std::sqrt(sum);

		if (sum == 0)
			throw "UnitizationVector error : sum is zero";

		MVector ret(v.size());

		for (int i = 0; i < v.size(); ++i) {
			ret[i] = v[i] / sum;
			ret[i] = doubleRound(ret[i], 2);	//������λС��
		}

		return ret;
	}
	//�������ڻ�
	std::optional<double> MVectorHelper::InnerProduct(const MVector &v1, const MVector &v2) {
		
		if (v1.size() != v2.size()) {
			return std::nullopt;
		}

		double ret = 0;
		for (int i = 0; i < v1.size(); ++i) {
			ret = doubleRound(ret + v1[i] * v2[i], 2);
		}
		
		return ret;
	}
	//������ͬά�����������������
	std::optional<MVector> MVectorHelper::AddVector(const MVector& v1, double x1, const MVector& v2, double x2) {
		if (v1.size() != v2.size()) {
			return std::nullopt;
		}

		MVector ret(v1.size());

		for (auto i = 0; i < v1.size(); ++i) {
			ret[i] = doubleRound(v1[i] * x1 + v2[i] * x2, 2);
		}

		return ret;
	}

	void MVectorHelper::PrintMVectors(std::vector<MVector> &mvecs) {
		if (mvecs.empty()) {
			std::cout << "PrintMVectors empty" << std::endl;
			return;
		}

		std::cout << "Infos: line[" << mvecs.size() << "] rows[" << mvecs[0].size() << "]" << std::endl;
		for (auto mvec : mvecs) {
			mvec.print();
		}
		
	}
}