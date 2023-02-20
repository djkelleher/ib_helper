#include "../src/ib_helper/IBConnector.hpp"

class MockIBConnector : public ib_helper::IBConnector
{
    public:
    MockIBConnector(const std::string& hostname, int port, int clientId);
    ~MockIBConnector();
    uint32_t GetNextRequestId();
    std::future<ContractDetails> GetContractDetails(const Contract& contract);
    private:
    std::atomic<uint32_t> nextRequestId;
    std::atomic<uint32_t> nextOrderId;
    std::unordered_map<uint32_t, std::promise<ContractDetails>> contractDetailsHandlers;
};