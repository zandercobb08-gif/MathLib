#pragma once
#include "Vector3.h"


namespace aie {
	struct Matrix3
	{
		union {
			struct {
				float M1, M2, M3, M4, M5, M6, M7, M8, M9;
			};

			float Data[9];
			float Data2D[3][3];
		};

		Matrix3() : M1{ 0 }, M2 { 0 }, M3 { 0 }, M4 { 0 }, M5 { 0 }, M6 { 0 }, M7 { 0 }, M8 { 0 }, M9 { 0 }
		{

		}

		
		Matrix3(float A1, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9) : M1{ A1 }, M2{ A2 }, M3{ A3 }, M4{ A4 }, M5{ A5 }, M6{ A6 }, M7{ A7 }, M8{ A8 }, M9{ A9 } 
		{

		}
		
		Matrix3(float num[]) : M1{ num[0]}, M2{ num[1] }, M3{ num[2] }, M4{ num[3] }, M5{ num[4] }, M6{ num[5] }, M7{ num[6] }, M8{ num[7] }, M9{ num[8] }
		{

		}
		static Matrix3 MakeIdentity()
		{
			Matrix3 Identity;
			Identity.M1 = 1.0f;
			Identity.M5 = 1.0f;
			Identity.M9 = 1.0f;

			return Identity;
		}
		float& operator [](int Index)
		{
			return Data[Index];
		}
		const float& operator [](int Index) const
		{
			return Data[Index];
		}
		Matrix3 operator * (const Matrix3& Rhs) const
		{
			Matrix3 Product;
			Product.M1 = M1 * Rhs.M1 + M4 * Rhs.M2 + M7 * Rhs.M3;
			Product.M4 = M1 * Rhs.M4 + M4 * Rhs.M5 + M7 * Rhs.M6;
			Product.M7 = M1 * Rhs.M7 + M4 * Rhs.M8 + M7 * Rhs.M9;
			Product.M2 = M2 * Rhs.M1 + M5 * Rhs.M2 + M8 * Rhs.M3;
			Product.M5 = M2 * Rhs.M4 + M5 * Rhs.M5 + M8 * Rhs.M6;
			Product.M8 = M2 * Rhs.M7 + M5 * Rhs.M8 + M8 * Rhs.M9;
			Product.M3 = M3 * Rhs.M1 + M6 * Rhs.M2 + M9 * Rhs.M3;
			Product.M6 = M3 * Rhs.M4 + M6 * Rhs.M5 + M9 * Rhs.M6;
			Product.M9 = M3 * Rhs.M7 + M6 * Rhs.M8 + M9 * Rhs.M9;
			return Product;
		}
		Matrix3 operator *= (Matrix3& Rhs) 
		{
			Matrix3 Mat;
			Mat.M1 = M1 * Rhs.M1 + M4 * Rhs.M2 + M7 * Rhs.M3;
			Mat.M4 = M1 * Rhs.M4 + M4 * Rhs.M5 + M7 * Rhs.M6;
			Mat.M7 = M1 * Rhs.M7 + M4 * Rhs.M8 + M7 * Rhs.M9;
			Mat.M2 = M2 * Rhs.M1 + M5 * Rhs.M2 + M8 * Rhs.M3;
			Mat.M5 = M2 * Rhs.M4 + M5 * Rhs.M5 + M8 * Rhs.M6;
			Mat.M8 = M2 * Rhs.M7 + M5 * Rhs.M8 + M8 * Rhs.M9;
			Mat.M3 = M3 * Rhs.M1 + M6 * Rhs.M2 + M9 * Rhs.M3;
			Mat.M6 = M3 * Rhs.M4 + M6 * Rhs.M5 + M9 * Rhs.M6;
			Mat.M9 = M3 * Rhs.M7 + M6 * Rhs.M8 + M9 * Rhs.M9;
			M1 = Mat.M1;
			M2 = Mat.M2;
			M3 = Mat.M3;
			M4 = Mat.M4;
			M5 = Mat.M5;
			M6 = Mat.M6;
			M7 = Mat.M7;
			M8 = Mat.M8;
			M9 = Mat.M9;

			return *this;
		}
		Vector3 operator * (const Vector3& Rhs) const 
		{
			return Vector3(
				M1 * Rhs.X + M4 * Rhs.Y + M7 * Rhs.Z,
				M2 * Rhs.X + M5 * Rhs.Y + M8 * Rhs.Z,
				M3 * Rhs.X + M6 * Rhs.Y + M9 * Rhs.Z
			);
		}
		bool operator == (const Matrix3& Rhs) const 
		{
			for (size_t i = 0; i < 9; ++i) 
			{
				if (Data[i] != Rhs.Data[i])
				{
					return false;
				}
			}
			return true;
		}
		bool Equals(const Matrix3& Rhs, float Talerance = 0.0001f) const
		{

			for (size_t i = 0; i < 9; ++i)
			{
				float Delta = std::abs(Data[i] - Rhs.Data[i]);

				if (Delta > Talerance) {
					return false;

				}
			}
			return true;
		}
		Matrix3 Transposed() {
			Matrix3 Mat;
			Mat.M1 = M1;
			Mat.M5 = M5;
			Mat.M9 = M9;
			Mat.M2 = M4;
			Mat.M4 = M2;
			Mat.M3 = M7;
			Mat.M7 = M3;
			Mat.M6 = M8;
			Mat.M8 = M6;
			return Mat;
		}
		bool operator != (const Matrix3& Rhs) const 
		{
			return !(*this == Rhs);
		}
		operator float* ()
		{
			return Data;
		}
		operator float const * () const
		{
			return Data;
		}
	};
	inline std::ostream& operator << (std::ostream& stream, const Matrix3& mat) {
		stream << mat.M1 << "," << mat.M2 << "," << mat.M3 << "," << mat.M4 << "," << mat.M5 << "," << mat.M6 << "," << mat.M7 << "," << mat.M8 << "," << mat.M9;
		return stream;
	}
	inline std::wostream& operator << (std::wostream& stream, const Matrix3& mat) {
		stream << mat.M1 << "," << mat.M2 << "," << mat.M3 << "," << mat.M4 << "," << mat.M5 << "," << mat.M6 << "," << mat.M7 << "," << mat.M8 << "," << mat.M9;
		return stream;
	}
	}