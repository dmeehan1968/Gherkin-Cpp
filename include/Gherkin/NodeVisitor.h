//
//  NodeVisitor.h
//  Zing
//
//  Created by Dave Meehan on 11/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_NodeVisitor_h
#define Zing_NodeVisitor_h

namespace Gherkin {

    class Node;
    class Feature;
    class Scenario;
    class Step;

    class NodeVisitor {

    public:

        virtual void visit(Node &node) = 0;
        virtual void visit(Feature &testCase) = 0;
        virtual void visit(Scenario &scenario) = 0;
        virtual void visit(Step &step) = 0;
        
    };

}

#endif
