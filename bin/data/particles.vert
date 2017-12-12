/*{
    "pixelRatio": 1,
    "vertexCount": 100,
    "vertexMode": "POINTS",
}*/
precision mediump float;
attribute float vertexId;
uniform float vertexCount;
uniform float time;
uniform vec2 resolution;
uniform vec2 mouse;
varying vec4 v_color;
uniform sampler2D samples;
uniform sampler2D spectrum;
uniform sampler2D volume;

void main() {
  float t = time * .1;
  float i = vertexId * .2 + sin(vertexId) * 1.;


  vec3 pos = vec3(
    sin(t + vertexId + i * .1) * sin(t * 1.21 + i),
    cos(t + vertexId - i * .2) * cos(t * 1.19 + i),
    cos(t + i) * sin(t + vertexId * .22)
  );

  gl_Position = vec4(pos.x, pos.y * resolution.x / resolution.y, pos.z * .1, 1);
  gl_PointSize = .4 / max(abs(pos.z), .1);

  v_color = vec4(
    fract(pos.x),
    fract(pos.y),
    fract(pos.z),
    1
  );
}
