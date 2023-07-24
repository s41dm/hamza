const char hz_gl4_char_quad_vertex_shader[] = 
{
    "#version 450 core\n"
    "#extension GL_ARB_separate_shader_objects : enable\n"
    "#define MAX_SLOTS_BUFFER_SIZE 1024\n"
    "\n"
    "layout(location = 0) in uint a_lru_id;\n"
    "layout(location = 1) in vec3 a_pos;\n"
    "layout(location = 2) in vec3 a_rot;\n"
    "layout(location = 3) in vec2 a_scale;\n"
    "\n"
    "out vec2 f_texcoords;\n"
    "\n"
    "struct slot {\n"
    "    uint id;\n"
    "    float u1,v1,u2,v2;\n"
    "};\n"
    "layout (binding = 0) uniform u_cache_slots {\n"
    "    slot slots[MAX_SLOTS_BUFFER_SIZE];\n"
    "};\n"
    "\n"
    "const vec2 quad_vertices[6] = vec2[6](\n"
    "    vec2(0.0,0.0),\n"
    "    vec2(1.0,0.0),\n"
    "    vec2(0.0,1.0),\n"
    "    vec2(0.0,1.0),\n"
    "    vec2(1.0,0.0),\n"
    "    vec2(1.0,1.0)\n"
    ");\n"
    "\n"
    "void main(){\n"
    "    vec2 q = quad_vertices[gl_VertexID];\n"
    "    vec3 px = a_pos + vec3(q*a_scale,0);\n"
    "    gl_Position = vec4(px/300.0,1);\n"
    "    slot s = slots[a_lru_id];\n"
    "    f_texcoords = mix(vec2(s.u1,s.v1),vec2(s.u2,s.v2),q);\n"
    "}\n"
};
