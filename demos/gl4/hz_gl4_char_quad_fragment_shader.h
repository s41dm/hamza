const char hz_gl4_char_quad_fragment_shader[] = 
{
    "#version 450 core\n"
    "#extension GL_ARB_separate_shader_objects : enable\n"
    "\n"
    "in vec2 f_texcoords;\n"
    "uniform sampler2D u_sdf_texture;\n"
    "\n"
    "layout(location=0) out vec4 outColor;\n"
    "\n"
    "#define ALPHA_THRESHOLD 0.0003\n"
    "void main(){\n"
    "    vec2 uv = f_texcoords;\n"
    "    float sigDist = texture(u_sdf_texture, uv).x;\n"
    "\n"
    "#if 0\n"
    "    float alpha = float(sigDist>0.5);\n"
    "#else\n"
    "    ivec2 sz = textureSize(u_sdf_texture, 0).xy;\n"
    "    float dx = dFdx(uv.x) * sz.x; \n"
    "    float dy = dFdy(uv.y) * sz.y;\n"
    "    float toPixels = 8.0/sqrt(dx * dx + dy * dy);\n"
    "    float w = fwidth(sigDist);\n"
    "    float alpha = smoothstep(0.5 - w, 0.5 + w, sigDist);\n"
    "#endif\n"
    "\n"
    "    if (alpha < ALPHA_THRESHOLD)\n"
    "        discard;\n"
    "\n"
    "    outColor = vec4(1.0,1.0,1.0,alpha);\n"
    "}\n"
};
