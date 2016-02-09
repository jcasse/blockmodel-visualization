#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// DATA FILES
const string CLUSTERING_0("clustering_0.txt");
const string CLUSTERING_1("clustering_1.txt");
const string CLUSTERING_2("clustering_2.txt");
const string DENSITIES("densities.txt");

const float block_gap_factor = 20;

struct block_t
{
  float ctr[3];
  float dim[3];
  float dns;
};

typedef vector<vector<vector<block_t> > > matrix;

void store_dimensions(matrix & blocking, vector<vector<int> > & dimensions)
{
  for(size_t x = 0; x != blocking.size(); ++x)
  {
    for(size_t y = 0; y != blocking[0].size(); ++y)
    {
      for(size_t z = 0; z != blocking[0][0].size(); ++z)
      {
        blocking[x][y][z].dim[0] = dimensions[1][y];
        blocking[x][y][z].dim[1] = dimensions[0][x];
        blocking[x][y][z].dim[2] = dimensions[2][z];
      }
    }
  }
}

void get_dimensions(istream & in, vector<int> & dimensions)
{
  int size;
  while(!in.eof())
  {
    string line;
    getline(in, line);
    stringstream ss(line);
    string token;
    ss >> token;
    if(token == "cluster")
    {
      size = 0;
      continue;
    }
    else if(token == "")
    {
      dimensions.push_back(size);
      continue;
    }
    else ++size;
  }
}

void get_densities(istream & in, matrix & block_model)
{
  float frq;
  int x, y, z;
  string line;
  getline(in, line);
  while(!in.eof())
  {
    stringstream ss(line);
    ss >> x; ss >> y; ss >> z; ss >> frq; ss >> frq;
    block_model[x][y][z].dns = frq;
    getline(in, line);
  }
}

float max(vector<float> & dim)
{
  float max = 0.0f;
  for(size_t i = 0; i != dim.size(); ++i) if(dim[i] > max) max = dim[i];
  return max;
}

float max_dim(vector<vector<int> > & dim)
{
  float max = 0.0f;
  for(size_t i = 0; i != dim.size(); ++i)
  {
    float size = 0.0f;
    size_t clusters = dim[i].size();
    for(size_t j = 0; j != clusters; ++j) size += dim[i][j];
    if(size > max) max = size;
  }
  return max;
}

vector<float> get_outer_dim(vector<vector<int> > & dim, float gap)
{
  vector<float> outer_dim(3);
  for(size_t i = 0; i != dim.size(); ++i)
  {
    size_t clusters = dim[i].size();
    for(size_t j = 0; j != clusters; ++j)
      outer_dim[i] += dim[i][j];
    outer_dim[i] += gap * (clusters - 1);
  }
  return outer_dim;
}

void compute_block_centers(matrix & blocking, vector<vector<int> > & dim)
{
  // compute gap between blocks
  float gap = max_dim(dim) / 20;

  // compute block model outer dimensions
  vector<float> outer_dim = get_outer_dim(dim, gap);

  // compute centers
  vector<vector<float> > centers(3, vector<float>());
  for(size_t i = 0; i != dim.size(); ++i)
  {
    float cumulative = 0.0f;
    float mid = outer_dim[i] / 2;
    size_t clusters = dim[i].size();
    for(size_t j = 0; j != clusters; ++j)
    {
      cumulative += float(dim[i][j]) / 2;
      centers[i].push_back(cumulative - mid);
      cumulative += float(dim[i][j]) / 2;
      cumulative += float(gap);
    }
  }

  for(size_t x = 0; x != blocking.size(); ++x)
  {
    for(size_t y = 0; y != blocking[0].size(); ++y)
    {
      for(size_t z = 0; z != blocking[0][0].size(); ++z)
      {
        blocking[x][y][z].ctr[0] =  centers[1][y];
        blocking[x][y][z].ctr[1] = -centers[0][x];
        blocking[x][y][z].ctr[2] = -centers[2][z];
      }
    }
  }
}

vector<float> get_block_model(matrix & block_model, const string & dir)
{
  ifstream in;
  string file;
  vector<vector<int> > dimensions(3, vector<int>());

  // get x dimensions
  file = string(dir + CLUSTERING_0);
  in.open(file.c_str());
  if(in.fail()) {cerr << "error opening " << file << endl; exit(1);}
  get_dimensions(in, dimensions[0]);
  in.close();
  in.clear();

  // get y dimensions
  file = string(dir + CLUSTERING_1);
  in.open(file.c_str());
  get_dimensions(in, dimensions[1]);
  in.close();
  in.clear();

  // get z dimensions
  file = string(dir + CLUSTERING_2);
  in.open(file.c_str());
  get_dimensions(in, dimensions[2]);
  in.close();
  in.clear();

  // create matirx
  block_model = matrix(dimensions[0].size(),
    vector<vector<block_t> >(dimensions[1].size(),
      vector<block_t>(dimensions[2].size()) ) );

  // get block densities
  file = string(dir + DENSITIES);
  in.open(file.c_str());
  get_densities(in, block_model);
  in.close();

  // store block dimensions
  store_dimensions(block_model, dimensions);

  // compute block centers
  compute_block_centers(block_model, dimensions);

  // compute gap between blocks
  float gap = max_dim(dimensions) / block_gap_factor;

  return get_outer_dim(dimensions, gap);
}
