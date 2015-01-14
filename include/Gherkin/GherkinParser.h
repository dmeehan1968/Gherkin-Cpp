//
//  GherkinParser.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_GherkinParser_h
#define Zing_GherkinParser_h

#include "AbstractParser.h"
#include "Feature.h"
#include "FeatureParser.h"

namespace Gherkin {

    template <class InputIterator>
    class GherkinParser : public AbstractParser<InputIterator> {

    public:
        using Base = AbstractParser<InputIterator>;

        GherkinParser(InputIterator begin, InputIterator const end, std::shared_ptr<Node> const &root)
        :
        Base(begin, end, root)
        {}

        void visit(Feature &node) {

            auto feature = std::make_shared<Feature>(node);

            Base::begin() = FeatureParser<InputIterator>(Base::begin(), Base::end(), feature).parse();

            Base::root()->addChild(feature);
            
        }
        
    protected:
        
    };
    
}

#endif
