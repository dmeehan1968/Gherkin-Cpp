//
//  Location.h
//  Gherkin-Cpp
//
//  Created by Dave Meehan on 14/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef Gherkin_Cpp_Location_h
#define Gherkin_Cpp_Location_h

#include <sstream>

namespace Gherkin {

    class Location {

    public:

        Location() : _line(0) {}
        
        Location(std::string const &filename,
                 size_t line = 1)
        :
        _filename(filename),
        _line(line)
        {}

        std::string const &filename() const {
            return _filename;
        }

        size_t line() const {
            return _line;
        }

        std::string str() const {
            std::ostringstream os;
            os << filename() << ":" << line();
            return os.str();
        }

        Location & operator++() {
            ++_line;
            return *this;
        }
        
        friend std::ostream & operator << (std::ostream &stream, Location const &location) {

            stream << location.str();
            return stream;

        }
        
    private:

        std::string         _filename;
        size_t              _line;

    };

}

#endif
