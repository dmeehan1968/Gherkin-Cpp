//
//  NodeFactory.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_NodeFactory_h
#define Zing_NodeFactory_h

#include "Feature.h"
#include "Scenario.h"
#include "Step.h"

namespace Gherkin {

    class NodeFactory {

    public:

        static std::shared_ptr<Node> create(std::string const &line) {

            std::regex  expr("^\\s*(feature|scenario|given|when|then|and|but|examples|\"\"\"):?\\s*(.*)\\s*$",
                             std::regex::icase | std::regex::ECMAScript);
            std::smatch matches;

            if (std::regex_match(line, matches, expr)) {

                auto keyword = matches[1].str();
                auto name = matches[2].str();

                auto node = std::make_shared<Node>(keyword, name);

                auto typedNode = Feature::create(*node);
                if (typedNode) {
                    return typedNode;
                }

                typedNode = Scenario::create(*node);
                if (typedNode) {
                    return typedNode;
                }

                typedNode = Step::create(*node);
                if (typedNode) {
                    return typedNode;
                }
                
                return node;
            }
            
            return {};
            
        }
        
    };

}

#endif
