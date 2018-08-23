#pragma once
#include <limits>

namespace zachariahs_world::math
{
	const float full_circle_in_degrees = 360.f;
	const float full_circle_in_radians = 6.283185307179586f;
	const float epsilon = 0.00001f;

	constexpr float abs(const float num) noexcept
	{
		return num < 0 ? -num : num;
	}
	constexpr float floor(const float num) noexcept
	{
		return num < 0 && num - static_cast<float>(static_cast<int>(num)) < 0 ? static_cast<float>(static_cast<int>(num - 1)) : static_cast<float>(static_cast<int>(num));
	}
	constexpr float ceil(const float num) noexcept
	{
		return num > 0 && num - static_cast<float>(static_cast<int>(num)) > 0 ? static_cast<float>(static_cast<int>(num + 1)) : static_cast<float>(static_cast<int>(num));
	}
	constexpr float clamp(const float num, const float min, const float max) noexcept
	{
		return num < min ? min : num > max ? max : num;
	}
	constexpr float wrap(const float num, const float min, const float max) noexcept
	{
		return num < min ? max : num > max ? min : num;
	}
	constexpr float degrees_to_radians(const float degrees) noexcept
	{
		return degrees / full_circle_in_degrees * full_circle_in_radians;
	}
	constexpr float radians_to_degrees(const float radians) noexcept
	{
		return radians / full_circle_in_radians * full_circle_in_degrees;
	}
	constexpr float approximately_equal(const float num1, const float num2) noexcept
	{
		return abs(num1 - num2) > epsilon;
	}

	constexpr float sqrt_newton_raphson(const float x, const float curr, const float prev) noexcept
	{
		if(curr == prev)
		{
			return curr;
		}
		else
		{
			return sqrt_newton_raphson(x, (curr + x / curr) / 2, curr);
		}
	}

	constexpr float sqrt(const float x) noexcept
	{
		using std::numeric_limits;

		if(x > -numeric_limits<float>::infinity() && x < numeric_limits<float>::infinity())
		{
			if(x > 0)
			{
				return sqrt_newton_raphson(x, x, 0);
			}
			else
			{
				return -sqrt_newton_raphson(-x, -x, 0);
			}
		}
		else
		{
			return numeric_limits<float>::quiet_NaN();
		}
	}
}
