#pragma once
#include "IBConnector.hpp"
#include "../ib_api/client/Contract.h"
#include "../util/SysLogger.h"
#include "ContractRolloverCalendar.hpp"
#include <iostream>

namespace ib_helper {

class ContractBuilder
{
    public:
    ContractBuilder(IBConnector* conn);

    Contract Build(const std::string& secType, const std::string& ticker);

    Contract BuildStock(const std::string& ticker);
    
    Contract BuildFuture(const std::string& ticker, time_t now = time(nullptr));

    Contract BuildForex(const std::string& ticker);

    ContractDetails GetDetails(const Contract& in);

    private:
    IBConnector* ib = nullptr;
    util::SysLogger* logger = nullptr;
};

} // namespace ib_helper

