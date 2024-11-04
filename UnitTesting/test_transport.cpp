#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "TransportDepartment.h"
#include "TransportCommand.h"
#include "Transportation.h"

class TransportMockery : public Transportation
{
    public:
        bool isOpen = false;
        bool isClosed = false;

        TransportMockery() : Transportation("") {}

        void open() override {this->isOpen = true;}
        void close() override {this->isClosed = true;}
};

class OpenBusinessMockery : public TransportCommand
{
    public:
        bool didExecute = false;

        void execute(Transportation* Transport) override {this->didExecute = true;}
        bool getStatus() override {return this->didExecute;}
};

class CloseBusinessMockery : public TransportCommand
{
    public:
        bool didExecute = false;

        void execute(Transportation* Transport) override {this->didExecute = true;}
        bool getStatus() override {return this->didExecute;}
};

TEST_CASE("Only one singleton")
{
    TransportDepartment* first = TransportDepartment::instance();
    TransportDepartment* second = TransportDepartment::instance();

    CHECK(first == second);
}

TEST_CASE("Add Tranpsort")
{
    TransportDepartment* d = TransportDepartment::instance();
    TransportMockery* t = new TransportMockery();

    d->addTransport(t);

    d->openTransport();
    CHECK(t->isOpen == true);

    d->removeTransport(t);
    delete t;
}

TEST_CASE("Remove Transport")
{
    TransportDepartment* d = TransportDepartment::instance();
    TransportMockery* t = new TransportMockery();

    d->addTransport(t);
    d->removeTransport(t);

    d->openTransport();
    CHECK(t->isOpen == false);

    delete t;
}

TEST_CASE("Test Open and Close Commands")
{
    TransportDepartment* d = TransportDepartment::instance();
    TransportMockery* t = new TransportMockery();

    d->addTransport(t);
    d->openTransport();

    CHECK(t->isOpen == true);

    d->closeTransport();
    CHECK(t->isClosed == true);

    d->removeTransport(t);
    delete t;
}