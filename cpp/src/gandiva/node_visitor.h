// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef GANDIVA_NODE_VISITOR_H
#define GANDIVA_NODE_VISITOR_H

#include <string>

#include "arrow/status.h"

#include "gandiva/logging.h"

namespace gandiva {

class FieldNode;
class FunctionNode;
class IfNode;
class LiteralNode;
class BooleanNode;
template <typename Type>
class InExpressionNode;

/// \brief Visitor for nodes in the expression tree.
class NodeVisitor {
 public:
  virtual ~NodeVisitor() = default;

  virtual Status Visit(const FieldNode& node) = 0;
  virtual Status Visit(const FunctionNode& node) = 0;
  virtual Status Visit(const IfNode& node) = 0;
  virtual Status Visit(const LiteralNode& node) = 0;
  virtual Status Visit(const BooleanNode& node) = 0;
  virtual Status Visit(const InExpressionNode<int32_t>& node) = 0;
  virtual Status Visit(const InExpressionNode<int64_t>& node) = 0;
  virtual Status Visit(const InExpressionNode<std::string>& node) = 0;
};

}  // namespace gandiva

#endif  // GANDIVA_NODE_VISITOR_H
