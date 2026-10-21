#pragma once
#include "Vector3.h"
#include <cmath>
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
		
		}
		Matrix3 operator *= (const Matrix3& Rhs) 
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
			return false;
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
	}