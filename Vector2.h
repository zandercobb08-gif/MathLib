#pragma once
#include <cmath>
namespace aie {
	struct Vector2 {
		union {
			struct { float X; float Y; };
			float Data[2];

		};

		Vector2() : X{ 0 }, Y{ 0 } {}
		Vector2(float A, float B) : X{ A }, Y{ B } {}
		Vector2 operator +(const Vector2& rhs) const {
			Vector2 Sum;
			Sum.X = X + rhs.X;
			Sum.Y = Y + rhs.Y;
		}
		Vector2 operator -(const Vector2& rhs) const {
			Vector2 Sum;
			Sum.X = X - rhs.X;
			Sum.Y = Y - rhs.Y;
		}
		Vector2 operator *(float rhs) const {
			Vector2 Sum;
			Sum.X = X * rhs;
			Sum.Y = Y * rhs;
		}
		Vector2 operator /(float rhs) const {
			Vector2 Sum;
			Sum.X = X / rhs;
			Sum.Y = Y / rhs;
		}
		Vector2& operator +=(const Vector2& rhs) {

			X += rhs.X;
			Y += rhs.Y;

			return *this;
		}
		Vector2& operator -=(const Vector2& rhs) {

			X -= rhs.X;
			Y -= rhs.Y;

			return *this;
		}
		Vector2& operator *=(float rhs) {

			X *= rhs;
			Y *= rhs;

			return *this;
		}
		Vector2& operator /=(float rhs) {

			X /= rhs;
			Y /= rhs;

			return *this;
		}
		Vector2 operator * (float Scalar) {
			Vector2 Copy;
			Copy.X = X * Scalar;
			Copy.Y = Y * Scalar;
			return Copy;
		}
		float Dot(const Vector2& Rhs) const {
			return X* Rhs.X + Y * Rhs.Y;
		
		}
		bool operator ==(const Vector2& rhs) {
			return X == rhs.X && Y == rhs.Y;
		}
		bool Equals(const Vector2& rhs, float tolerance = 0.0001f) const {

			float XDelta = abs(X - rhs.X);
			float YDelta = abs(Y - rhs.Y);

			return XDelta < tolerance && YDelta < tolerance;
		}
		float Magnitude() const {
			return sqrt(X * X + Y * Y);
		}

		Vector2 Normalized() const {
			float Mag = Magnitude();

			Vector2 Copy;

			Copy.X = X / Mag;
			Copy.Y = Y / Mag;
		}
		void Normalize()
		{
			*this = Normalized();
		}
		Vector2 SafeNormalized() const
		{
			float Mag = Magnitude();
			if (Mag == 0.0f)
			{
				return Vector2{ 0,0 };

			}
			else {
				Vector2 Copy;
				Copy.X = X / Mag;
				Copy.Y = Y / Mag;
				return Copy;
			}
		}
	};
	inline Vector2 operator *(float Scalar, const Vector2& Vec)
	{
		return Vec * Scalar;
	}
}
