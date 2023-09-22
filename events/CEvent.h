#pragma once

#include <functional>

namespace alt
{
	class CEvent
	{
	public:
		enum class Type : uint16_t
		{
			NONE,

			// Server
			SERVER_STARTED,
			CLIENT_REQUEST_OBJECT_EVENT,
			CLIENT_DELETE_OBJECT_EVENT,

			// Shared
			PLAYER_CONNECT,
			PLAYER_DISCONNECT,
			PLAYER_CONNECT_DENIED,
			PLAYER_SPAWN,

			CONNECTION_QUEUE_ADD,
			CONNECTION_QUEUE_REMOVE,

			RESOURCE_START,
			RESOURCE_STOP,
			RESOURCE_ERROR,
			
			SERVER_SCRIPT_EVENT,
			CLIENT_SCRIPT_EVENT,

			META_CHANGE,
			SYNCED_META_CHANGE,
			STREAM_SYNCED_META_CHANGE,
			GLOBAL_META_CHANGE,
			GLOBAL_SYNCED_META_CHANGE,
			LOCAL_SYNCED_META_CHANGE,

			PLAYER_DAMAGE,
			PLAYER_DEATH,
			PLAYER_HEAL,
			FIRE_EVENT,
			EXPLOSION_EVENT,
			START_PROJECTILE_EVENT,
			WEAPON_DAMAGE_EVENT,
			VEHICLE_DESTROY,
			VEHICLE_DAMAGE,

			REQUEST_SYNCED_SCENE,
			START_SYNCED_SCENE,
			STOP_SYNCED_SCENE,
			UPDATE_SYNCED_SCENE,

			COLSHAPE_EVENT,
			PLAYER_ENTER_VEHICLE,
			PLAYER_START_ENTER_VEHICLE,
			PLAYER_ENTERING_VEHICLE,
			PLAYER_LEAVE_VEHICLE,
			PLAYER_START_LEAVE_VEHICLE,
			PLAYER_CHANGE_VEHICLE_SEAT,
			PLAYER_WEAPON_CHANGE,
			PLAYER_REQUEST_CONTROL,

			VEHICLE_ATTACH,
			VEHICLE_DETACH,
			VEHICLE_HORN,
			VEHICLE_SIREN,
			NETOWNER_CHANGE,

			CREATE_BASE_OBJECT_EVENT,
			REMOVE_BASE_OBJECT_EVENT,

			CONSOLE_COMMAND_EVENT,

			PLAYER_CHANGE_ANIMATION_EVENT,

			PLAYER_CHANGE_INTERIOR_EVENT,

			PLAYER_WEAPON_SHOOT_EVENT,
			PLAYER_BULLET_HIT_EVENT,

			PLAYER_DIMENSION_CHANGE,

			GIVE_PED_SCRIPTED_TASK,

			// Client
			CONNECTION_COMPLETE,
			DISCONNECT_EVENT,
			WEB_VIEW_EVENT,
			KEYBOARD_EVENT,
			GAME_ENTITY_CREATE,
			GAME_ENTITY_DESTROY,
			WEB_SOCKET_CLIENT_EVENT,
			AUDIO_EVENT,
			TASK_CHANGE,
			SPAWNED,
			RMLUI_EVENT,
			WINDOW_FOCUS_CHANGE,
			WINDOW_RESOLUTION_CHANGE,
			ENTITY_HIT_ENTITY,

			WORLD_OBJECT_POSITION_CHANGE,
			WORLD_OBJECT_STREAM_IN,
			WORLD_OBJECT_STREAM_OUT,

			VOICE_CONNECTION_EVENT,

			PED_DAMAGE,
			PED_DEATH,
			PED_HEAL,

			ALL,
			SIZE
		};

		CEvent(Type _type) :type(_type) { }
		virtual ~CEvent() = default;

		virtual bool IsCancellable() const { return false; }

		Type GetType() const { return type; };

	private:
		Type type;
	};

	class CCancellableEvent : public CEvent
	{
	public:
		CCancellableEvent(Type _type) : CEvent(_type) {}

		bool IsCancellable() const override { return true; }

		bool WasCancelled() const { return cancelled; }
		void Cancel() const { cancelled = true; }

	private:
		mutable bool cancelled = false;
	};
}
