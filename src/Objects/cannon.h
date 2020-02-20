#ifndef CANNON_H
#define CANNON_H


namespace SummerLab {
	class cannon {
	private:
		float _waterTank;
		float _pressure;
	public:
		cannon();
		~cannon();
		void setWaterTank();
		void setPressure();
		float getWaterTank();
		float getPressure();
		void shoot();
	};
}
#endif
