#pragma once

struct Vector3 {
	union {
		struct { float X; float Y; float Z; };
		float Data[3];
	};
	Vector3() : X{ 0 }, Y{ 0 }, Z{ 0 }
	{
	}
	Vector3(float InX, float InY, float InZ) : X{ InX }, Y{ InY }, Z{ InZ }
	{
	}
	Vector3 Cross(const Vector3& Other) 
	{
		return Vector3
		{
			Y * Other.Z - Z * Other.Y,
			Z * Other.X - X * Other.Z,
			X * Other.Y - Y * Other.X
		};
		 
	}
};