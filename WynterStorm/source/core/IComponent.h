#ifndef WYNTERSTORM_ICOMPONENT_H
#define WYNTERSTORM_ICOMPONENT_H
#include <vector>
#include <string>
#include <stdint.h>

namespace ws {
	namespace core {
		class IGameObject;
		class IComponent {
		protected:
			uint64_t id;
			std::string tag;
			IGameObject* owner;
			bool enabled;
		public:
			IComponent(IGameObject* owner, std::string tag);
			
			static uint64_t getNextComponentId();

			std::string getTag();
			uint64_t getId();
			
			bool getEnabled();
			void setEnabled(bool newvalue);
			
			virtual void polymorphismhack();
		};
	}
}
#endif