#define Entry
#include <Lila/Lila.h>

#include <iostream>

class TestEvent : public Lila::Event {};
class TestHandler : public Lila::EventHandler {
public:
    void onEvent(Lila::Event& e) override {
        if(Lila::isIstanceOf<Lila::Event, TestEvent>(&e)) {
            lila_info("TestEvent handled")
        }
    }
};

class TestBedApp : public Lila::Application {
public:
    TestBedApp(std::string name) { name_m = name; }

    void create() override {
        lila_info("Creating Testbed");
    }

    void run() override {
        lila_info("Running Testbed");

        TestHandler testHandler;
        Lila::EventBus::addHandler(testHandler);

        TestEvent testEvent;
        Lila::EventBus::fireEvent(testEvent);

        Lila::Unique<Lila::Window> window = Lila::makeUnique<Lila::Window>("Window");

        while(window->isOpen()) {
            window->render();
            window->update();
        }
    }
};

Lila::Shared<Lila::Application> createApplication() {
    return Lila::makeShared<TestBedApp>("TestBed");
}
