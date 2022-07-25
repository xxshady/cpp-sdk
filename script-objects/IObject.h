#pragma once

#include "../objects/IEntity.h"

namespace alt
{
	class IObject : public virtual IEntity
	{
	public:
		virtual void SlideTo(alt::Position pos, alt::Vector3f speed) = 0;

#ifdef ALT_CLIENT_API
		virtual bool IsRemote() const = 0;
#endif

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
}
