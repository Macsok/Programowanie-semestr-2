#include <iostream>
#include <vector>

//	pure virtual class (can't be created)
class Sensor {
public:
	//	pure virtual function (czysto wirtualna)
	virtual double getValue() = 0;
};

//	inheritance of Sensor
class PressureSensor : public Sensor {
public:
	double getValue() override;
};

class TemperatureSensor : public Sensor {
public:
	double getValue() override;
};

//	Manager (not a child of a Sensor class)
class SensorManager {
private:
	std::vector<Sensor*> sensors;
public:
	void addSensor(Sensor* s);
	void readAllValues();
};

int main() {
	TemperatureSensor tp;
	PressureSensor ps;
	SensorManager manager;

	manager.addSensor(&tp);
	manager.addSensor(&ps);

	manager.readAllValues();
	return 0;
}

double PressureSensor::getValue() {
	return 100;
}

double TemperatureSensor::getValue() {
	return 36;
}

void SensorManager::addSensor(Sensor* s) {
	sensors.push_back(s);
}

void SensorManager::readAllValues() {
	for (Sensor* s : sensors) {
		std::cout << s->getValue() << std::endl;
	}
}