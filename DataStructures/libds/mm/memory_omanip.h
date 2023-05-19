#pragma once

#include <ostream>
#include <iomanip>
#include <sstream>

namespace ds::mm {

	template<typename PositionType>
	class PtrPrint {
	public:
		PtrPrint(const PositionType* ptr, int base, int width);

		const PositionType* ptr_;
		std::ostringstream oss_;
	};

	template<typename PositionType>
	class PtrPrintBin : public PtrPrint<PositionType> {
	public:
		PtrPrintBin(const PositionType* ptr);
	};

	template<typename PositionType>
    PtrPrint<PositionType>::PtrPrint(const PositionType* ptr, int base, int width) :
		ptr_(ptr)
	{
		oss_ << std::setbase(base) << std::setw(width);

		unsigned char* ptrB = (unsigned char*)(void*)ptr_;

		for (size_t byte = 0; byte < sizeof(PositionType); byte++, ptrB++) {
			oss_ << "|" << (int)*ptrB;
		}
		oss_ << "|";
	}

	template<typename PositionType>
    PtrPrintBin<PositionType>::PtrPrintBin(const PositionType* ptr) :
		PtrPrint<PositionType>(ptr, 2, 8)
	{
	}

}

template<typename PositionType>
std::ostream& operator<<(std::ostream& os, const ds::mm::PtrPrint<PositionType>& pp) {
	return os << pp.oss_.str();
}
