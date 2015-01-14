//
//  Node.h
//  Zing
//
//  Created by Dave Meehan on 12/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Zing_Node_h
#define Zing_Node_h

#include "Location.h"

#include <initializer_list>
#include <string>
#include <list>


namespace Gherkin {

    class NodeVisitor;

    class Node {

    public:

        Node(Location const &location);

        Node(Location const &location, std::initializer_list<std::shared_ptr<Node>> const &nodes);

        Node(Location const &location,
             std::string const &keyword,
             std::string const &name);

        Node(Location const &location,
             std::string const &keyword,
             std::string const &name,
             std::initializer_list<std::shared_ptr<Node>> const &nodes);

        friend std::ostream & operator << (std::ostream &stream, Node const &node) {

            stream << node.str();
            return stream;

        }

        Location &location();

        std::string const &keyword() const ;

        std::string const &name() const ;

        std::string str() const;

        virtual void accept(NodeVisitor &visitor);

        std::list<std::shared_ptr<Node>> const &children() const ;

        void addChild(std::shared_ptr<Node> const &node) ;

    protected:

        void init(std::string const &keyword,
                  std::string const &name,
                  std::initializer_list<std::shared_ptr<Node>> const &nodes) ;
        
    private:

        Location                                _location;
        std::string                             _keyword;
        std::string                             _name;
        std::list<std::shared_ptr<Node>>        _children;
        std::list<std::string>                  _tags;
        
    };

}

#endif
