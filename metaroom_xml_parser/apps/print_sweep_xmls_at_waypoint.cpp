#include <metaroom_xml_parser/simple_summary_parser.h>
#include <metaroom_xml_parser/simple_xml_parser.h>
#include <metaroom_xml_parser/simple_dynamic_object_parser.h>
#include <metaroom_xml_parser/load_utilities.h>

typedef pcl::PointXYZRGB PointType;
typedef semantic_map_load_utilties::DynamicObjectData<PointType> ObjectData;

typedef pcl::PointCloud<PointType> Cloud;
typedef typename Cloud::Ptr CloudPtr;

using namespace std;

int main(int argc, char** argv)
{
    string folder;
    string waypoint;


    if (argc > 2){
        folder = argv[1];
        waypoint = argv[2];
    } else {
        cout<<"Please specify the folder from where to load the data and sweep waypoint."<<endl;
        return -1;
    }

    cout<<"Looking for sweeps..."<<endl;
    vector<string> sweep_xmls = semantic_map_load_utilties::getSweepXmlsForTopologicalWaypoint<PointType>(folder, waypoint);
    cout<<sweep_xmls.size()<<" sweeps found."<<endl;

    for (string sweep : sweep_xmls){

        cout<<"Sweep "<<sweep<<endl;
    }
}
