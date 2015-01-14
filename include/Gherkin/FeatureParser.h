//
//  FeatureParser.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_FeatureParser_h
#define Zing_FeatureParser_h

#include "ScenarioParser.h"

namespace Gherkin {

    template <class InputIterator>
    class FeatureParser : public AbstractParser<InputIterator> {

    public:
        using Base = AbstractParser<InputIterator>;

        FeatureParser(InputIterator begin, InputIterator const end, std::shared_ptr<Node> const &root)
        :
        Base(begin, end, root)
        {}

        void visit(Scenario &node) {

            auto scenario = std::make_shared<Scenario>(node);

            Base::begin() = ScenarioParser<InputIterator>(Base::begin(), Base::end(), scenario).parse();

            Base::root()->addChild(scenario);

        }
        
    };

}

#endif
