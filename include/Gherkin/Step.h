//
//  Step.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_Step_h
#define Zing_Step_h

namespace Gherkin {

    class Step : public Node {

    public:

        Step(std::string const &keyword,
             std::string const &name,
             std::initializer_list<std::shared_ptr<Node>> const &nodes = {})
        :
        Node(keyword, name, nodes)
        {}

        static std::shared_ptr<Node> create(Node const &node) {

            if (node.keyword() == "scenario" || node.keyword() == "given" || node.keyword() == "when" || node.keyword() == "then" || node.keyword() == "and" || node.keyword() == "but") {

                return std::shared_ptr<Step>(new Step(node));

            }
            return {};

        }

        virtual void accept(NodeVisitor &visitor) {
            visitor.visit(*this);
        }

    protected:
        
        Step(Node const &node) : Node(node) {}
        
        
    };

}

#endif
