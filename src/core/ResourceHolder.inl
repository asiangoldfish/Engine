#include "core/ResourceHolder.hpp"

#include <stdexcept>
#include <assert.h>
#include <memory>

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> resource(new Resource());
    
    // When unable to load the file, throw an exception with filename
    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }

    // Pair of iterator and bool. Iteratore is the return value from
    // std::map::insert, and bool is true if successfully inserted and false
    // if the key already exists.
    auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
inline void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    std::unique_ptr<sf::Texture> resource(new Resource());
    
    // When unable to load the file, throw an exception with filename
    if (!resource->loadFromFile(filename, secondParam)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }

    // Pair of iterator and bool. Iteratore is the return value from
    // std::map::insert, and bool is true if successfully inserted and false
    // if the key already exists.
    auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::ResourceHolder::get(Identifier id)
{
    // Reference to the texture found. It may also be nullptr.
    auto found = resourceMap.find(id);
    
    // Assert if the texture was not found
    assert(found != resourceMap.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::ResourceHolder::get(Identifier id) const
{
    // Reference to the texture found. It may also be nullptr.
    auto found = resourceMap.find(id);
    return *found->second;
}
