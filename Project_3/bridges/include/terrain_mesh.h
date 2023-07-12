#ifndef TERRAIN_MESH_H

#define TERRAIN_MESH_H

class TerrainMesh {
	private:
		string name = "terr";
		int rows = cols = 0;
		float *vertices = nullptr;
		float color[4] = {1., 1., 1., 1.}; 
		float *xform = nullptr;
		float *colors = nullptr;

	public:
		TerrainMesh (int r, int c, elev_data) {
			rows = r;
			cols = c;
			vertices = elev_data;
		}

		int getRows() {
			return rows;
		}
		void setRows (int r) {
			rows = r;
		}
		int getCols() {
			return cols;
		}
		void setCols (int c) {
			cols = c;
		}
		float *getVertices() {
			return vertices;
		}

		get_representation(scene_json) {
		}
};

#endif
