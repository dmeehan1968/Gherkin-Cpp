//
//  Node.cpp
//  Gherkin-Cpp
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#include "Node.h"
#include "NodeVisitor.h"

#include <sstream>
#include <assert.h>

namespace Gherkin {

    Node::Node() {

        init("", "", {});

    }

    Node::Node(std::initializer_list<std::shared_ptr<Node>> const &nodes) {

        init("", "", nodes);

    }

    Node::Node(std::string const &keyword,
               std::string const &name) {

        init(keyword, name, {});

    }

    Node::Node(std::string const &keyword,
               std::string const &name,
               std::initializer_list<std::shared_ptr<Node>> const &nodes) {

        init(keyword, name, nodes);

    }

    std::string const &Node::keyword() const {
        return _keyword;
    }

    std::string const &Node::name() const {
        return _name;
    }

    std::string Node::str() const {

        std::ostringstream os;

        if (_keyword.empty() && _name.empty()) {
            os << "root";
        } else {
            os << _keyword << ": " << _name;
        }
        os << ", " << _children.size() << (_children.size() == 1 ? " child" : " children");
        return os.str();
    }

    void Node::accept(NodeVisitor &visitor) {
        visitor.visit(*this);
    }

    std::list<std::shared_ptr<Node>> const &Node::children() const {
        return _children;
    }

    void Node::addChild(std::shared_ptr<Node> const &node) {

        assert(node);

        _children.emplace_back(node);
    }

    void Node::init(std::string const &keyword,
              std::string const &name,
              std::initializer_list<std::shared_ptr<Node>> const &nodes) {
        
        std::transform(keyword.begin(), keyword.end(), std::back_inserter(_keyword), ::tolower);
        
        _name = name;
        
        std::copy(nodes.begin(), nodes.end(), std::back_inserter(_children));
        
    }

}
