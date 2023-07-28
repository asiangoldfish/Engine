#ifndef __RESOURCE_HOLDER_H__
#define __RESOURCE_HOLDER_H__

#include <map>
#include <memory>

/**
 * @brief We use Textures::ID to easily get the texture we need
 */
enum Identifier {
    GrassTileset
};

/**
 * @brief Container that holds references to textures.
 * The container manages the textures' life time. Internally it uses unique
 * pointers, so a texture may only have one owner at a time.
 */
template <typename Resource, typename Identifier>
class ResourceHolder {

    // Private methods
private:
    /**
     * @brief Load a resource to the container.
     *
     * @param id The key that this texture is referred is.
     * @param filename Filepath on disk to the texture.
     * @throw std::runtime_error Thrown when loading the texture fails
     */
    void load(Identifier id, const std::string& filename);

    template <typename Parameter>
    void load(Identifier id, const std::string &filename, const Parameter &secondParam);

    /**
     * @brief Get a reference to a texture by id
     *
     * @param id The resource's id to reference by
     * @return Resource& Reference to the texture resource.
     */
    Resource& get(Identifier id);

    /**
     * @brief Get a reference to a texture by id
     *
     * @param id The texture's id to reference by
     * @return Resource& Reference to the texture resource.
     */
    const Resource& get(Identifier id) const;

    // Member variables
private:
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

#include "core/ResourceHolder.inl"

#endif
