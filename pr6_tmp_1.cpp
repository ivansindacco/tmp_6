#include <iostream>

class IService {
public:
    virtual void performAction() = 0;
};

class ConcreteService : public IService {
public:
    void performAction() override {
        std::cout << "Performing some action..." << std::endl;
    }
};

class ServiceFactory {
public:
    static std::shared_ptr<IService> createService() {
        return std::make_shared<ConcreteService>();
    }
};

class Client {
private:
    std::shared_ptr<IService> service;

public:
    Client(std::shared_ptr<IService> service) : service(service) {}

    void executeService() {
        service->performAction();
    }
};

int main() {
    std::shared_ptr<IService> service = ServiceFactory::createService();
    Client client(service);

    client.executeService();

    return 0;
}