#include "Vector2.h"
#include "Vector3.h"
int main() {
	Vector3 Right3D = { 1, 0, 0 };
	Vector3 Up3D = { 0, 1, 0 };
	Vector3 Foward = { 0, 0, 1 };

	Vector3 Cr = Right3D.Cross(Up3D);

	return 0;         
}