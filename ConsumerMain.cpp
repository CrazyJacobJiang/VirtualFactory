#include <cppkafka/consumer.h>
#include <cppkafka/configuration.h>
#include <iostream>

using namespace std;
using namespace cppkafka;

bool running = true;

int main() {
	Configuration config = {
		{ "metadata.broker.list", "192.168.1.199:9092" }
	};

	Consumer consumer(config);

	while (running) {
		Message msg = consumer.poll();
		if (msg) {
			if (msg.get_key()) {
				cout << msg.get_key() << "->";
			}
			cout << msg.get_payload() << endl;
		}
	}

}