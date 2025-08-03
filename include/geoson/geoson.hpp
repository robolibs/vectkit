#pragma once

#include "parser.hpp"
#include "types.hpp"
#include "writter.hpp"

// Convenient aliases for common operations
namespace geoson {

    // Read function alias
    inline FeatureCollection read(const std::filesystem::path &file) { return ReadFeatureCollection(file); }

    // Write function aliases - with CRS choice
    inline void write(const FeatureCollection &fc, const std::filesystem::path &outPath, CRS outputCrs) {
        WriteFeatureCollection(fc, outPath, outputCrs);
    }

    // Write function alias - defaults to WGS output format (for interoperability)
    // Note: Internal representation is always Point (ENU) coordinates
    inline void write(const FeatureCollection &fc, const std::filesystem::path &outPath) {
        WriteFeatureCollection(fc, outPath);
    }

} // namespace geoson
