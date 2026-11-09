cbuffer FrameUniforms : register(b0, space1) {
    float ElapsedTime;
}

struct Input {
    float3 Position : POSITION;
};

struct Output {
    float4 Position : SV_Position;
    float4 Color    : TEXCOORD0;
};

Output main(Input InputData, uint VertexID : SV_VertexID) {
    Output OutputData;
    
    OutputData.Position = float4(InputData.Position, 1.0f);
    
    float PhaseAngle = float(VertexID) * radians(120.0f);
    float CurrentTime = PhaseAngle + ElapsedTime;
    
    OutputData.Color.r = sin(CurrentTime) * 0.5f + 0.5f;
    OutputData.Color.g = sin(CurrentTime + radians(120.0f)) * 0.5f + 0.5f;
    OutputData.Color.b = sin(CurrentTime + radians(240.0f)) * 0.5f + 0.5f;
    OutputData.Color.a = 1.0f;
    
    return OutputData;
}
