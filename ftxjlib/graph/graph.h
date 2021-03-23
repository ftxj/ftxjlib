#pragma once
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
typedef std::string String;
typedef std::vector Vector;
typedef bool Bool;
typedef size_t uint;

template<typename Graph, typename Graph::EdgeType>
class EdgeGroup {
    Graph &graph_;    
    EdgeType edge_from_;
public:
    EdgeGroup(Graph &graph, EdgeType edge_from) : graph_(graph), edge_from_(edge_from) {}
    Graph::Iterator begin() const {
        return graph_.begin_at(edge_from);
    }

    Graph::Iterator end() const {
        return graph_.end_at(edge_from);
    }
};

class BaseGraph {
public:
    

    virtual String type() const {
        return "Base";
    }

    virtual void nodes_size() const = 0;
    virtual void edges_size() const = 0;
    virtual void memory_size() const = 0;

};

class StaticGraph : public BaseGraph {
public:
    String type() const {
        return "Static::" + BaseGraph::type();
    }
};

class DynamticGraph {
public:
    virtual void add_edge(int node_from, int node_to) = 0;
};

template<typename Weight_t, typename Container>
class CSRGraph {
    typedef unsigned int NodeId_t;
    Container<Weight_t> weights_;
    Container<NodeId_t> cols_;
    Container<size_t> offsets_;
public:
    class Iterator {
        int ptr_;
    public:
        Iterator& operator++() {
            return *this;
        }
        
    };
    class EdgeType {
    public:
        EdgeType(int node_id) : node_id_(ndoe_id), edge_id_(0) {}
        EdgeType(int node_id, int edge_id) : node_id_(ndoe_id), edge_id_(edge_id) {
            
        }
        int node_id_;
        int edge_id_;
    };
    Iterator begin_at(EdgeType &edge_from) const {
        auto& [node_id, edge_id] = edge_from;
        return Iterator(cols_[offsets_[node_id]], edge_id);
    }
};

template<typename Weight_t, typename Container>
class StaticCSRGraph : public StaticGraph, CSRGraph {
public:
    void init_from_csr_format(String file_path);
    void init_from_coo_format(String file_path);
};

template<typename Weight_t, typename Container>
class DynamticCSRGraph {
    public:
};