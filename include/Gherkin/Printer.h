//
//  Printer.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_Printer_h
#define Zing_Printer_h

namespace Gherkin {

    class Printer : public NodeVisitor {

    public:

        Printer() : _indent(0) {}

        void visit(Node &node) override {

            std::cout << std::string(_indent, ' ') << node << std::endl;

            _indent += 2;
            for ( auto &child : node.children() ) {

                child->accept(*this);

            }
            _indent -= 2;

        }

        void visit(Feature &testCase) override {

            std::cout << std::string(_indent, ' ') << testCase << std::endl;

            _indent += 2;
            for ( auto &child : testCase.children() ) {

                child->accept(*this);

            }
            _indent -= 2;

        }

        void visit(Scenario &scenario) override {

            std::cout << std::string(_indent, ' ') << scenario << std::endl;

            _indent += 2;
            for ( auto &child : scenario.children() ) {

                child->accept(*this);

            }
            _indent -= 2;

        }

        void visit(Step &step) override {

            std::cout << std::string(_indent, ' ') << step << std::endl;
            
            _indent += 2;
            for ( auto &child : step.children() ) {
                
                child->accept(*this);
                
            }
            _indent -= 2;
            
        }
        
    private:
        
        size_t _indent;
        
    };

}

#endif
