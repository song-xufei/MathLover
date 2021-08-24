/*************************************************
Copyright:
Author:xufei-song
Date:2021-08-09
Description: define Math vector
**************************************************/

#pragma once
#include "Default.h"

namespace MathLover {
	class MVector {
	public:
		MVector(int _dimension, const std::vector<double> &_data):
		m_nDimension(_dimension),
		m_vData(_data){

		};

		MVector(int _dimension) :
			m_nDimension(_dimension),
			m_vData(std::vector<double>(m_nDimension)) {

		};

		int size() {
			return m_vData.size();
		}

		int size() const {
			return m_vData.size();
		}

		bool empty() {
			return m_vData.empty();
		}

		bool empty() const {
			return m_vData.empty();
		}

		//用于左值
		double& operator[](unsigned int n) {
			if (n < 0 || n >= m_vData.size()) {
				throw "invailed parameter";
			}
			return m_vData[n];
		}

		//用于右值
		const double& operator[](unsigned int n) const {
			if (n < 0 || n >= m_vData.size()) {
				throw "invailed parameter";
			}
			return m_vData[n];
		}

		void print() {
			for (unsigned int i = 0; i < m_vData.size(); ++i) {
				std::cout << m_vData[i] << " " << std::ends;
			}

			std::cout << std::endl;
		}

		void print() const {
			for (unsigned int i = 0; i < m_vData.size(); ++i) {
				std::cout << m_vData[i] << " " << std::ends;
			}

			std::cout << std::endl;
		}

	private:
		int m_nDimension;
		std::vector<double> m_vData;
	};
}
