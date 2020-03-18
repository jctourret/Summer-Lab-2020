#ifndef AMBULANCE_H
#define AMBULANCE_H

#include "raylib.h"

namespace SummerLab {

	class Ambulance {
	private:
		Rectangle _body;
		float _posXInitial;
		Color _color;
		bool _waitingCiv;
		Texture2D _ambulanceLeft;
		Texture2D _ambulanceRight;
		bool _posLeft;
		bool _posRight;
	public:
		Ambulance(float height, float width, float x, float y, bool positionRight, bool positionLeft);
		~Ambulance();
		void setWaitingCiv(bool waitingCiv);
		Rectangle getBody();
		void takeCivAway();
		void draw();
	};
}
#endif