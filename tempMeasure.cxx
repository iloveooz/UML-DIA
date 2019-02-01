	#include <iostream>
	
	// -----------------------------------------------------------------
	class Sensor {
		int value;
	public:
		Sensor() { value = 0; }
		void setValue(int value) { this->value += value; }
		int getValue() { return value; }
	};
	
	// -----------------------------------------------------------------
	class MeasureCount {
		int number;
		
		static int total;
	public:
		MeasureCount() { number = 0; }
		void increment() { number++; total++; }
		int getNumber() { return number; }
	
		static int getTotal() { return total; }
	};
	
	int MeasureCount::total = 0;
	
	// -----------------------------------------------------------------
	class ITemperatureMeasure {
	public:
		virtual void setValue() = 0;
		virtual double getValue() = 0;
	};
	
	// -----------------------------------------------------------------
	class TemperatureMeasure : public virtual ITemperatureMeasure {
	private:
		Sensor *h;        // агрегация
		MeasureCount *measure;  // композиция
	public:
		TemperatureMeasure(Sensor *h);
		int getNumber() { return measure->getNumber(); }
		double getValue() { return (double)h->getValue() / measure->getNumber(); }
		
		void setValue() {
			int value;
			measure->increment();
			
			std::cout << "t[" << measure->getNumber() << "]= "; 
			std::cin >> value;
			h->setValue(value);
		}
		
		static int getTotal() { return MeasureCount::getTotal(); }
	};
	
	TemperatureMeasure::TemperatureMeasure(Sensor *h) {
		measure = new MeasureCount();
		this->h = h;
	}
	
	// ---------------------------------------------------------------------------
	class ShowTemperature { // зависимость 
	public:
	
		static void Show(TemperatureMeasure t) {
			std::cout << t.getNumber() << ": ";
			std::cout << t.getValue() << " oC" << '\n';
		}
	};

	int main() {
	Sensor *h1 = new Sensor();
	
	TemperatureMeasure tc1(h1);
	
	for(int i = 0; i < 5; i++)
		tc1.setValue();
	
	ShowTemperature::Show(tc1);
	std::cout << '\n';
	
	Sensor *h2 = new Sensor();
	
	TemperatureMeasure tc2(h2);
	
	for (int i = 0; i < 5; i++)
		tc2.setValue();
	
	ShowTemperature::Show(tc2);
	
	std::cout << '\n';
	std::cout << "Total: " << TemperatureMeasure::getTotal() << '\n';
	
	return 0;
	}
