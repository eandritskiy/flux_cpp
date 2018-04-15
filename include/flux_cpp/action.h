#ifndef FLUX_CPP_ACTION_H
#define FLUX_CPP_ACTION_H

#include <any>
#include <type_traits>
#include <utility>

namespace flux_cpp
{
	template<typename E>
	using is_scoped_enum = std::integral_constant<bool, std::is_enum<E>::value && !std::is_convertible<E, int>::value>;

	class Action final
	{
	public:
		template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
		Action(ScopedEnum type, std::any& payload, bool error = false)
			: type_(static_cast<int>(type)), payload_(payload), error_(error)
		{
		}

		template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
		Action(ScopedEnum type, std::any&& payload = std::any(), bool error = false)
			: type_(static_cast<int>(type)), payload_(std::move(payload)), error_(error)
		{
		}

		Action(const Action&) = default;
		Action(Action&&) = default;
		Action& operator=(const Action&) = default;
		Action& operator=(Action&&) = default;
		~Action() = default;

		template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
		auto getType() const
		{
			return static_cast<ScopedEnum>(type_);
		}

		template<class T>
		auto getPayload() const
		{
			return std::any_cast<T>(payload_);
		}

		bool getError() const
		{
			return error_;
		}

	private:
		int type_;
		bool error_;
		std::any payload_;
	};
}

#endif
