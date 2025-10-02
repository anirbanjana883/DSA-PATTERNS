EULAR PATH --> all the path of edges that visit all the *edges* in a graph *exactly once*
not all graph have eularian path
be careful from which node ypu start and end the path
>>>>start_vertex,end_vertex has degree odd always**

EULARIAN CIRCUIT/CYCLE --> an *eularian path* which *starts and ends* at the *same* node
not all graph have eularian circuit/cycle ###[*[ all vertices must have *even degree*]*]###
if any graph have eularian circuit or cycle you can start from any node

if any graph is not an eularian circuit then 
        >eaither you would not be able to come back to the start node 
        >or you would have to visit some edge more than once

        *     *\
        |     | \
        |     |  \          this is not eularian path and(abviously not an eularian circuit)
        |     |   \
        *     *----*

        *     *\
              | \
              |  \          this is  eularian path and(also an eularian circuit)
              |   \
              *----*


######## +>to become and eular path all vertices with *non zero degree* must need to belongs to a single connected component

eular path = eular circuit/cycle
eular circuit/cycle != eular path

graph  ===>(eular path present) but (not eular circuit)==> *semi-eularian graph* [start_vertex,end_vertex has degree odd always]

graph  ===>(eular path present) and ( eular circuit present)==> *eularian graph*

semi-eularian graph=>all edges visited once but start != end

question type   detect eularian graph
                detect semi-eularian graph
                detect eularian path (imp) Leetcode
                detect eularian circuit/cycle
                detect non eularian graph

question solving to become an eular path non zero degree vertex must be connected