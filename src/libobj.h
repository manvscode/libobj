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
#ifndef _LIBOBJ_H_
#define _LIBOBJ_H_
#include <stdlib.h>
#include <stdbool.h>

typedef float obj_scaler_t;

typedef struct obj_vertex {
    obj_scaler_t x;
    obj_scaler_t y;
    obj_scaler_t z;
} obj_vertex_t;

typedef struct obj_texture_coord {
    obj_scaler_t u;
    obj_scaler_t v;
} obj_texture_coord_t;

typedef struct obj_normal {
    obj_scaler_t nx;
    obj_scaler_t ny;
    obj_scaler_t nz;
} obj_normal_t;



struct obj_face;
typedef struct obj_face obj_face_t;

struct obj_group;
typedef struct obj_group obj_group_t;

struct obj_loader;
typedef struct obj_loader obj_loader_t;

obj_loader_t* obj_loader_load( const char *filename, bool verbose );
obj_loader_t* obj_loader_from_file( FILE* file, bool verbose );

obj_loader_t* obj_loader_create( void );
void obj_loader_destroy( obj_loader_t** ol );

/*
 * Get a group
 */
const obj_group_t* obj_loader_group_at( const obj_loader_t* ol, size_t index );
size_t obj_loader_group_count( obj_loader_t* ol );

/*
 * Get a pointer to the global list of vertices.
 */
const obj_vertex_t* obj_loader_vertices( const obj_loader_t* ol );
const size_t obj_loader_vertices_count( const obj_loader_t* ol );

/*
 * Get a pointer to the global list of texture coordinates.
 */
const obj_texture_coord_t* obj_loader_texture_coords( const obj_loader_t* ol );
const size_t obj_loader_texture_coords_count( const obj_loader_t* ol );

/*
 * Get a pointer to the global list of normals.
 */
const obj_normal_t* obj_loader_normals( const obj_loader_t* ol );
const size_t obj_loader_normals_count( const obj_loader_t* ol );

const char* obj_group_name( const obj_group_t* g );
const obj_face_t* obj_group_face( const obj_group_t* g, size_t index );
size_t obj_group_faces_count( const obj_group_t* g );

const size_t* obj_face_vertex_indices( const obj_face_t* f );
size_t obj_face_vertex_indices_count( const obj_face_t* f );

const size_t* obj_face_texture_coords_indices( const obj_face_t* f );
size_t obj_face_texture_coords_indices_count( const obj_face_t* f );

const size_t* obj_face_normal_indices( const obj_face_t* f );
size_t obj_face_normal_indices_count( const obj_face_t* f );


#endif /* _LIBOBJ_H_ */
