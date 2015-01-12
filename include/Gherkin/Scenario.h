//
//  Scenario.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_Scenario_h
#define Zing_Scenario_h

namespace Gherkin {

    class Scenario : public Node {

    public:

        Scenario(std::string const &name,
                 std::initializer_list<std::shared_ptr<Node>> const &nodes)
        :
        Node("scenario", name, nodes)
        {}

        static std::shared_ptr<Node> create(Node const &node) {

            if (node.keyword() == "scenario") {

                return std::shared_ptr<Scenario>(new Scenario(node));

            }
            return {};

        }

        virtual void accept(NodeVisitor &visitor) {
            visitor.visit(*this);
        }

    protected:
        
        Scenario(Node const &node) : Node(node) {}
        
        
    };

}

#endif
