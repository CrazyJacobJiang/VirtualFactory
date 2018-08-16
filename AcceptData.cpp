#include <iostream>
#include <csignal>
#include "cppkafka/consumer.h"

using namespace std;
bool running = true;

int main(int argc, char* argv[]) {
	//配置消费者，负责接收命令
	string csm_brokers = "192.168.1.199:9092";
	string csm_topic_name = "Data";
	string csm_group_id = "0";

//	signal(SIGINT, [](int) { running = false; });
	
	cppkafka::Configuration csm_config = {
		{ "metadata.broker.list", csm_brokers },
		{ "group.id", csm_group_id },
		{ "enable.auto.commit", true }
	};
	
	cppkafka::Consumer consumer(csm_config);

	/*
	consumer.set_assignment_callback([](const cppkafka::TopicPartitionList& partitions) {
		cout << "Got assigned: " << partitions << endl;
	});
	consumer.set_revocation_callback([](const cppkafka::TopicPartitionList& partitions) {
		cout << "Got revoked: " << partitions << endl;
	});
	*/
	
	consumer.subscribe({ csm_topic_name });
	cout << "Consuming messages from topic " << csm_topic_name << endl;
	while (running) {
		cppkafka::Message csm_msg = consumer.poll();
		if (csm_msg) {
			cout << csm_msg.get_payload() << endl;
		}
	}
	/*
	while (running) {
		cppkafka::Message csm_msg = consumer.poll();
		if (csm_msg) {
			if (csm_msg.get_error()) {
				if (!csm_msg.is_eof()) {
					cout << "[+] Received error notification: " << csm_msg.get_error() << endl;
				}
			}
			else {
				cout << csm_msg.get_payload() << endl;
				//consumer.commit(csm_msg);
			}
		}
	}
	*/
}
