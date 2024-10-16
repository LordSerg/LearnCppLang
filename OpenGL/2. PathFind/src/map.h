#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <memory>
#include <tuple>
/*a minimal map element*/
class node
{
	bool is_barier = false;
	int thing_that_is_here = 0;


public:
    int x,y;
	std::vector<node*> neighbours;
	node(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
};

/*the whoke map operations*/
class map
{
public:
	static int width, height;//map size
	static std::vector< std::unique_ptr<node>> map_itself;
	
	/*size of current map*/
	static int getW(){return width;}
	static int getH(){return height;}

	/*set and get things that are on the map*/
	static int whatIsThere(int _x, int _y);
	static void setToLocation(int _x, int _y, int _whatToSet);
	
	/*read map from saved file*/
	static void loadMap(std::string path);

	/*for saving in file*/
	static std::string Serialize();
	static std::string Deserialize();
	
	/*save map to the file*/
	static void openMap(std::string path);	

	//generate random map
	static void generate(int w, int h)
    {
        width = w;
        height = h;
        for(int i=0;i<width; ++i)
        {
            for(int j=0;j<height;++j)
            {
                map_itself.push_back(std::unique_ptr<node>(new node(i,j)));
            }
        }

        //make connections
        for(int i=0;i<width; ++i)
        {
            for(int j=0;j<height;++j)
            {
                if(i<width-1)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j)*width+(i+1)].get());
                if(i>0)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j)*width+(i-1)].get());
                if(j<height-1)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j+1)*width+(i)].get());
                if(j>0)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j-1)*width+(i)].get());
                
                if(i<width-1 && j<height-1)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j+1)*width+(i+1)].get());

                if(i>0 && j>0)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j-1)*width+(i-1)].get());

                if(i<width-1 && j>0)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j-1)*width+(i+1)].get());

                if(i>0 && j<height-1)
                    map_itself[j*width+i]->neighbours.push_back(map_itself[(j+1)*width+(i-1)].get());
            }
        }


    }
	
	static std::vector<std::tuple<int, int>> findPath(int x_0, int y_0, int x_1, int y_1)
    {
        std::vector<std::tuple<int, int>> answer{};
    }
};

int map::width=0;
int map::height=0;
std::vector< std::unique_ptr<node>> map::map_itself={};
#endif