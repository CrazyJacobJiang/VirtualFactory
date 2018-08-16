#include <cppkafka/producer.h>

using namespace std;

/*
int main() {
	
	cppkafka::Configuration config = {
		{ "metadata.broker.list", "192.168.1.199:9092" }
	};
	cppkafka::Producer producer(config);

	string message = "hey there!";
	producer.produce(cppkafka::MessageBuilder("test").partition(0).payload(message));
	producer.flush();
	return 0;
}

*/

