#ifndef CHALLENGE_extensions_hpp_INCLUDED
#define CHALLENGE_extensions_hpp_INCLUDED

#include "basics.hpp"

namespace extensions {

// In Python, we'd ideally like to wrap this as a single Thingamajig type with
// a "dtype" attribute and constructor argument that can be any of
// (complex<float>, Doodad).
// But we may want to start with two distinct Thingamajig types in Python
// (one for each instantiation).
template <typename T>
class Thingamajig : public basics::Doodad {
public:

    // Keyword arguments and default values should work in Python.
    Thingamajig(T extra, std::string const & name, double value=1);

    // In Python, this should ideally return a Thingamajig instance, not just
    // a Doodad.
    virtual std::unique_ptr<basics::Doodad> clone() const;

    // When T is complex<float> these will always return a copy, since they'll
    // be returning a Python built-in.  When returning a Doodad, we'd ideally
    // like to propagate constness, and tie the lifetime of the Doodad to the
    // lifetime of the Thingamajig, so it's impossible to get a dangling
    // reference in Python.
    T const & get_extra() const { return _extra; }
    T & get_extra() { return _extra; }

    void set_extra(T const & extra) { _extra = extra; }

private:
    T _extra;
};

} // namespace things

#endif //! CHALLENGE_extensions_hpp_INCLUDED
