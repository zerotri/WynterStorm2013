#ifndef WYNTERSTORM_IEVENT_H
#define WYNTERSTORM_IEVENT_H
namespace ws {
	namespace core {
		class IEvent
		{
		public:
			IEvent(void);
			virtual ~IEvent(void);
		};
	}
}
#endif