//
//  ScenarioParser.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_ScenarioParser_h
#define Zing_ScenarioParser_h

namespace Gherkin {

    template <class InputIterator>
    class ScenarioParser : public AbstractParser<InputIterator> {

    public:
        using Base = AbstractParser<InputIterator>;

        ScenarioParser(InputIterator begin,
                       InputIterator const end,
                       std::shared_ptr<Location> const &location,
                       std::shared_ptr<Node> const &root)
        :
        Base(begin, end, location, root)
        {}

        void visit(Step &node) {

            auto step = std::make_shared<Step>(node);

            Base::root()->addChild(step);

        }
        
    protected:
        
    };

}

#endif
