#pragma once

#include "CEvent.h"
#include "../types/MValue.h"
#include "../script-objects/IRml.h"

namespace alt
{
	class CRmlEvent : public CEvent
	{
	public:
		CRmlEvent(const std::shared_ptr<IRmlElement>& _element, const std::string& _name, const MValueDict& _args) :
			CEvent(Type::RMLUI_EVENT),
			element(_element),
			name(_name),
			args(_args)
		{

		}

		IRmlElement* GetElement() const { return element.get(); }
		std::string GetName() const { return name; }
		const MValueDict& GetArgs() const { return args; }

	private:
		std::shared_ptr<IRmlElement> element;
		std::string name;
		MValueDict args;
	};
}
