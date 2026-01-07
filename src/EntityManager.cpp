#include "EntityManager.h"
#include <algorithm>
#include <vector>

void EntityManager::removeDeadEntities(EntityVec& vec) {
	for (int i = vec.size(); i > 0; i--) {
		if (vec[i].isAlive() == false) {
			vec.erase(vec.begin() + i);
		}
	}
}

void EntityManager::update() {
	for (auto entities : m_toAdd) {
		m_entities.pushback(entities);
		m_entityMap[entities.tag()].pushback(entities);
	}
	m_toAdd.clear();
	removeDeadEntities(m_entities);
	for (auto& [tag, entityvec] : m_entityMap) {
		removeDeadEntities(entityvec);
	}
}
std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) {
	m_totalEntities++;
	auto my_pointer = std::shared_pointer(new Entity(m_totalEntities, tag))
	m_toAdd.pushback(my_pointer);
	return my_pointer

}
const EntityVec& EntityManager::getEntities() const {
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag) {
	return m_entityMap[tag];
}
const EntityMap& EntityManager::getEntityMap() {
	return m_entityMap;
}
const size_t& EntityManager::getTotalEntities() {
	return m_totalEntities;
}