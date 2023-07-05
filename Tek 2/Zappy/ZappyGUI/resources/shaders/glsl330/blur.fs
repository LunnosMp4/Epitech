#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

// NOTE: Render size values must be passed from code
const float renderWidth = 800;
const float renderHeight = 450;

const int numSamples = 49;
const float offset[49] = float[](
    -3.0, -3.0, -3.0, -3.0, -3.0, -3.0, -3.0,
    -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
     0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,
     1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,
     2.0,  2.0,  2.0,  2.0,  2.0,  2.0,  2.0,
     3.0,  3.0,  3.0,  3.0,  3.0,  3.0,  3.0
);
const float weight[49] = float[](
    0.013, 0.016, 0.017, 0.019, 0.021, 0.016, 0.013,
    0.016, 0.017, 0.021, 0.025, 0.019, 0.017, 0.016,
    0.017, 0.021, 0.025, 0.033, 0.037, 0.021, 0.017,
    0.019, 0.025, 0.033, 0.045, 0.053, 0.025, 0.019,
    0.021, 0.019, 0.037, 0.043, 0.055, 0.019, 0.021,
    0.016, 0.017, 0.021, 0.025, 0.019, 0.017, 0.016,
    0.013, 0.016, 0.017, 0.019, 0.021, 0.016, 0.013
);

void main()
{
    // Texel color fetching from texture sampler
    vec3 texelColor = vec3(0.0);

    for (int i = 0; i < numSamples; i++)
    {
        vec2 sampleOffset = vec2(offset[i] / renderWidth, offset[i] / renderHeight);
        texelColor += texture(texture0, fragTexCoord + sampleOffset).rgb * weight[i];
    }

    finalColor = vec4(texelColor, 1.0);
}