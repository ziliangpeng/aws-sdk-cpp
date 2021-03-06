﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/dynamodb/model/TransactGetItemsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::DynamoDB::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

TransactGetItemsResult::TransactGetItemsResult()
{
}

TransactGetItemsResult::TransactGetItemsResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

TransactGetItemsResult& TransactGetItemsResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("ConsumedCapacity"))
  {
    Array<JsonView> consumedCapacityJsonList = jsonValue.GetArray("ConsumedCapacity");
    for(unsigned consumedCapacityIndex = 0; consumedCapacityIndex < consumedCapacityJsonList.GetLength(); ++consumedCapacityIndex)
    {
      m_consumedCapacity.push_back(consumedCapacityJsonList[consumedCapacityIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("Responses"))
  {
    Array<JsonView> responsesJsonList = jsonValue.GetArray("Responses");
    for(unsigned responsesIndex = 0; responsesIndex < responsesJsonList.GetLength(); ++responsesIndex)
    {
      m_responses.push_back(responsesJsonList[responsesIndex].AsObject());
    }
  }



  return *this;
}
