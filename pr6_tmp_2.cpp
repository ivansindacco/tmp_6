#include <iostream>

class IService {
public:
    virtual void request() = 0;
};

class RealService : public IService {
public:
    void request() override {
        std::cout << "RealService: Obrabotka ." << std::endl;
    }
};

class ProxyService : public IService {
private:
    RealService* realService;

public:
    ProxyService() : realService(nullptr) {}

    void request() override {
        if (realService == nullptr) {
            realService = new RealService();
        }
        std::cout << "ProxyService: Peredacha." << std::endl;
        realService->request();
    }

    ~ProxyService() {
        delete realService;
    }
};

int main() {
    ProxyService proxy;

    proxy.request();

    proxy.request();

    return 0;
}