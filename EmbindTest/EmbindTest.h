#include "bind.h"
#include <iostream>

namespace randomName
{
	struct Parameters
	{
		Parameters():
	sampleRate(44100), blockSize(4096){};

	unsigned int sampleRate;
	unsigned int blockSize;
	};

	Parameters setParameters()
	{
		Parameters parameters = Parameters();
		return parameters;
	};

	class RandomClass
	{
	public:
		RandomClass(const Parameters& parameters){};
		~RandomClass(){};

		void ptrWrapper(uintptr_t address, unsigned int samplesCount)
		{
			float *ptr = reinterpret_cast<float*>(address);
			processing(ptr, samplesCount);
		}
		float getFirstResult()
		{
			std::cout << "Result: " << results[0];
			return results[0];
		}

		void processing(const float* samples, unsigned int samplesCount)
		{

		};

		const std::vector<float>& getResult()
		{
			return results;
		};


	private:
		std::vector<float> results;
	};

}

EMSCRIPTEN_BINDINGS(random)
{
	emscripten::value_object<randomName::Parameters>("Parameters")
		.field("sampleRate", &randomName::Parameters::sampleRate)
		.field("blockSize", &randomName::Parameters::blockSize)
		;

	emscripten::function("setParameters", &randomName::setParameters);	

	emscripten::class_<randomName::RandomClass>("RandomClass")
		.constructor<randomName::Parameters&>()
		.function("ptrWrapper", &randomName::RandomClass::ptrWrapper)
		.function("getFirstResult", &randomName::RandomClass::getFirstResult)
		;
}