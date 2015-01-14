//
//  AbstractParser.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_AbstractParser_h
#define Zing_AbstractParser_h

#include "NodeVisitor.h"
#include "Node.h"
#include "NodeFactory.h"
#include "ParserNodeException.h"

namespace Gherkin {

    template <class InputIterator>
    class AbstractParser : public NodeVisitor {

    public:

        AbstractParser(InputIterator begin,
                       InputIterator const end,
                       std::shared_ptr<Location> const &location,
                       std::shared_ptr<Node> root)
        :
        _begin(begin),
        _end(end),
        _root(root),
        _location(location)
        {}

        InputIterator parse() {

            while (_begin != _end) {

                auto node = NodeFactory::create(*_location, *_begin);

                if (node) {

                    auto locationBegin = *_location;
                    auto begin = _begin;

                    try {

                        ++(*_location);
                        ++_begin;
                        node->accept(*this);

                    } catch (ParserNodeException &e) {

                        *_location = locationBegin;
                        _begin = begin;
                        break;

                    }

                } else {

                    std::cout   << "Skipping: \""
                                << *_begin
                                << "\""
                                << std::endl;

                    ++(*_location);
                    ++_begin;

                }

            }

            return _begin;

        }

        std::shared_ptr<Node> const &root() const {
            return _root;
        }

        InputIterator &begin() {
            return _begin;
        }

        InputIterator end() const {
            return _end;
        }

        std::shared_ptr<Location> const &location() const {
            return _location;
        }

        void visit(Node &node) {

            throw ParserNodeException();

        }

        void visit(Feature &node) {

            throw ParserNodeException();

        }
        
        void visit(Scenario &node) {
            
            throw ParserNodeException();
            
        }
        
        void visit(Step &node) {
            
            throw ParserNodeException();
            
        }
        
    private:
        
        InputIterator               _begin;
        InputIterator const         _end;
        std::shared_ptr<Node>       _root;
        std::shared_ptr<Location>   _location;

    };

}

#endif
