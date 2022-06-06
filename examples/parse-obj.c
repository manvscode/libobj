/*
 * Copyright (C) 2016-2022 by Joseph A. Marrero. https://joemarrero.com/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdlib.h>
#include <stdio.h>
#include "libobj.h"

/*
 * This program reads an OBJ file and dumps it's geometry out for each group.
 */
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Missing input file.\n");
		goto done;
	}

	const char* input = argv[1];

	FILE* file = fopen(input, "r");

	if (file)
	{
		obj_loader_t* obj = obj_loader_from_file(file, false);

		if (obj)
		{
			/*
			 * First, we get a pointer to the vertex, texture coordinate,
			 * and normalss. The geometry faces will use indices into
			 * these arrays.
			 */
			const obj_vertex_t* vertices = obj_loader_vertices(obj);
			size_t vertex_count = obj_loader_vertices_count(obj);

			const obj_texture_coord_t* texture_coords = obj_loader_texture_coords(obj);
			size_t texture_coords_count = obj_loader_texture_coords_count(obj);

			const obj_normal_t* normals = obj_loader_normals(obj);
			size_t normals_count = obj_loader_normals_count(obj);

			/*
			 * Iterate over all of the groups. A group is a grouping
			 * of geometry in the obj file format (i.e. a mesh).
			 */
			size_t group_count = obj_loader_group_count(obj);
			for (size_t i = 0; i < group_count; i += 1)
			{
				const obj_group_t* g = obj_loader_group_at(obj, i);

				const char* name = obj_group_name(g);
				size_t faces_count = obj_group_faces_count(g);

				printf("Group %s:\n", name);
				printf("\t%zu faces.\n", faces_count);

				/*
				 * If we have vertex data, then print out all of the vertices.
				 */
				if (vertex_count > 0)
				{
					printf("\tvertices:\n");
					for (size_t j = 0; j < faces_count; j += 1)
					{
						const obj_face_t* face = obj_group_face(g, j);

						const size_t* vertex_indices = obj_face_vertex_indices(face);
						size_t vertex_indices_count = obj_face_vertex_indices_count(face);

							for (int k = 0; k < vertex_indices_count; k += 1)
							{
								size_t index = vertex_indices[k];
								obj_vertex_t vertex = vertices[index];

								printf("\t\t%6zu  (%+.5f, %+.5f, %+.5f)\n", 3 * j + k + 1, vertex.x, vertex.y, vertex.z);
							}
					}
				}

				/*
				 * If we have texture-coordinates, then print out all of the texture-coodinates.
				 */
				if (texture_coords_count > 0)
				{
					printf("\ttexture-coordinates:\n");
					for (size_t j = 0; j < faces_count; j += 1)
					{
						const obj_face_t* face = obj_group_face(g, j);

						const size_t* texture_coords_indices = obj_face_texture_coords_indices(face);
						size_t texture_coords_indices_count = obj_face_texture_coords_indices_count(face);

						if (texture_coords_indices_count > 0)
						{
							for (int k = 0; k < texture_coords_indices_count; k += 1)
							{
								size_t index = texture_coords_indices[k];
								obj_texture_coord_t uv = texture_coords[index];

								printf("\t\t%6zu  (%+.5f, %+.5f)\n", 2 * j + k + 1, uv.u, uv.v);
							}
						}
					}
				}

				/*
				 * If we have normals, then print out all of the normals.
				 */
				if (normals_count > 0)
				{
					printf("\tnormals:\n");
					for (size_t j = 0; j < faces_count; j += 1)
					{
						const obj_face_t* face = obj_group_face(g, j);

						const size_t* normal_indices = obj_face_normal_indices(face);
						size_t normal_indices_count = obj_face_normal_indices_count(face);

						if (normal_indices_count > 0)
						{
							for (int k = 0; k < normal_indices_count; k += 1)
							{
								size_t index = normal_indices[k];
								obj_normal_t normal = normals[index];
								printf("\t\t%6zu  (%+.5f, %+.5f, %+.5f)\n", 3 * j + k + 1, normal.nx, normal.ny, normal.nz);
							}
						}
					}
				}

				printf("\n");
			}

			obj_loader_destroy(&obj);
		}

		fclose(file);
	}
	else
	{
		fprintf(stderr, "Unable to open \"%s\"\n", input);
	}

done:
	return 0;
}

