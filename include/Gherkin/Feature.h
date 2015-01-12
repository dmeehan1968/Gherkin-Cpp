//
//  Feature.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_Feature_h
#define Zing_Feature_h

namespace Gherkin {

    class Feature : public Node {

    public:

        Feature(std::string const &name,
                std::initializer_list<std::shared_ptr<Node>> const &nodes)
        :
        Node("feature", name, nodes)
        {}

        static std::shared_ptr<Node> create(Node const &node) {

            if (node.keyword() == "feature") {

                return std::shared_ptr<Feature>(new Feature(node));

            }

            return {};

        }

        virtual void accept(NodeVisitor &visitor) {
            visitor.visit(*this);
        }
        
    protected:
        
        Feature(Node const &node) : Node(node) {}
        
    };

}

#endif
