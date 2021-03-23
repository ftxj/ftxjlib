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

template<typename Graph>
class Property {
public:
    typedef enum  {
        INIT,
        Complete,
        Fixed,
        Bounded,
        PowerLaw,
        Random,
        None
    } DegreeProperty;
    
    typedef enum  {
        Direct,
        UnDirect,
        None
    } EdgeProperty;
    
    typedef enum  {
        INIT,
        Bipartite,
        Diagonal,
        None
    } TopologicalProperty;
    
    typedef enum  {
        Multiple,
        Single,
        None
    } WeightProperty;
    
    DegreeProperty degree_prop_;
    EdgeProperty edge_prop;
    TopologicalProperty topo_prop_;
    WeightProperty weight_prop_;
public:
    static DegreeProperty compute_degree_property(Graph &graph) {
        auto degree_vector = graph.get_degree_vector();
        for(auto iter = DegreeProperty::INIT + 1; iter != DegreeProperty::None; ++iter) {
            if(degree_funcs[iter - DegreeProperty::INIT](degree_vector)) {
                return iter;
            }
        }
        return DegreeProperty::None;
    }
    
    static EdgeProperty compute_edge_property(Graph &graph) {
        return EdgeProperty::None;
    }
    
    static TopologicalProperty compute_topo_property(Graph &graph) {
        return TopologicalProperty::None;
    }

    static WeightProperty compute_weight_property(Graph &graph) {
        return WeightProperty::None;
    }
private:
    static std::function<DegreeProperty(Vector<size_t>)> degree_funcs = {
        is_power_law_graph,
        is_complete_graph,
        is_fixed_graph,
        is_bounded_graph,
        is_random_graph
    };
};

Bool is_power_law_graph(Vector<uint> &degrees, uint edge_nums, uint node_nums) {
    const double big_node_percentage = 0.2;
    const double big_node_degree_percentage = 0.8;
    std::sort(degrees.begin(), degree.end(), std::greater<size_t>);
    uint big_node_edges = 0;
    for(uint iter = 0; iter < uint(node_nums * big_node_degree_percentage); ++iter) {
        big_node_edges += degrees[iter];
    }
    return (double)big_node_edges / edge_nums > big_node_degree_percentage;
}

Bool is_bounded_graph(Vector<uint> &degrees, uint edge_nums, uint node_nums) {
    // TODO: how to deal with undirect or direct graph?
    return false;
}

Bool is_fixed_graph(Vector<uint> &degrees, uint edge_nums, uint node_nums) {
    // TODO: how to deal with undirect or direct graph?
    return false;
}


Bool is_complete_graph(Vector<uint> &degrees, uint edge_nums, uint node_nums) {
    // TODO: how to deal with undirect or direct graph?
    return false;
}

Bool is_random_graph(Vector<uint> &degrees, uint edge_nums, uint node_nums) {
    // TODO: how to deal with undirect or direct graph?
    return false;
}

