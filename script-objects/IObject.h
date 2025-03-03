#pragma once

#include "../objects/IEntity.h"

namespace alt
{
	class IObject : public virtual IEntity
	{
	public:
		virtual uint8_t GetAlpha() const = 0;
		virtual void SetAlpha(uint8_t alpha) = 0;
		virtual void ResetAlpha() = 0;

		virtual bool IsDynamic() const = 0;

		virtual uint16_t GetLodDistance() const = 0;
		virtual void SetLodDistance(uint16_t distance) = 0;

		virtual bool HasGravity() const = 0;
		virtual void ToggleGravity(bool toggle) = 0;

		virtual void AttachToEntity(IEntity* entity, int16_t bone, alt::Position pos, alt::Rotation rot, bool useSoftPinning, bool collision, bool fixedRot) = 0;
		virtual void AttachToEntity(uint32_t scriptId, int16_t bone, alt::Position pos, alt::Rotation rot, bool useSoftPinning, bool collision, bool fixedRot) = 0;
		virtual void Detach(bool dynamic) = 0;

		virtual bool IsCollisionEnabled() const = 0;
		virtual void ToggleCollision(bool toggle, bool keepPhysics) = 0;

		virtual void PlaceOnGroundProperly() = 0;

		virtual void SetPositionFrozen(bool toggle) = 0;

		virtual void ActivatePhysics() = 0;

		virtual uint8_t GetTextureVariation() const = 0;
		virtual void SetTextureVariation(uint8_t variation) = 0;

		// True = Created by GTA, False = Created by API
		virtual bool IsWorldObject() const = 0;

#ifdef ALT_CLIENT_API
		virtual bool IsRemote() const = 0;
#endif
	};
}
