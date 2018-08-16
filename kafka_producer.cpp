#include <stdexcept>
#include <iostream>
#include "cppkafka/producer.h"
#include "cppkafka/configuration.h"

using namespace std;

int main(int argc, char* argv[]) {
	string brokers = "192.168.1.199:9092";
	string topic_name = "test";
	int partition_value = 0;

	// Create a message builder for this topic
	cppkafka::MessageBuilder builder(topic_name);

	// Get the partition we want to write to. If no partition is provided, this will be
	// an unassigned one
	if (partition_value != -1) {
		builder.partition(partition_value);
	}

	// Construct the configuration
	cppkafka::Configuration config = {
		{ "metadata.broker.list", brokers }
	};

	// Create the producer
	cppkafka::Producer producer(config);

	cout << "Producing messages into topic " << topic_name << endl;

	// Now read lines and write them into kafka
	string line;
	string message = "Juses help";
	builder.payload(message);
	producer.produce(builder);
	producer.flush();
	return 0;
}
