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
		MVector(int _dimension, std::vector<int> &_data):
		m_nDimension(_dimension),
		m_vData(_data){

		};

	private:
		int m_nDimension;
		std::vector<int> m_vData;
	};
}
