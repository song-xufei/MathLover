#include "MVectorHelper.h"
#include "MHelper.h"

namespace MathLover {

	//计算正交向量组
	std::optional<std::vector<MVector>> MVectorHelper::OrthogonalVectors(std::vector<MVector> &data) {
		if (data.empty())
			return std::nullopt;

		try {
			std::vector<MVector> ret(data.size(), MVector(data[0].size()));

			ret[0] = UnitizationVector(data[0]); //此处单位化

			int count = 0;	//已正交化向量的数目
			for (unsigned int i = 1; i < data.size(); ++i) {
				MVector tmpRet = data[i]; //即将单位正交化的向量, 计算的中间结果都会在这里

				for (auto j = 0; j <= count; j++) {
					//计算与已单位正交化向量的内积，因为是单位向量，这里直接为其在该单位向量的投影
					std::optional<double> optX = InnerProduct(ret[j], data[i]);

					if (optX != std::nullopt) {
						double x = optX.value();

						auto optVec = AddVector(tmpRet, 1, ret[j], x);

						if (optVec != std::nullopt) {
							tmpRet = optVec.value();	//存入临时结果
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


	//单位化正交向量
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
			ret[i] = doubleRound(ret[i], 2);	//保留两位小数
		}

		return ret;
	}
	//两向量内积
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
	//两个相同维数向量的数量积相加
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