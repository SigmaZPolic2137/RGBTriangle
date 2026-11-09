struct Input {
    float4 Position : SV_Position;
    float4 Color    : TEXCOORD0;
};

struct Output {
    float4 Color : SV_Target0;
};

Output main(Input InputData) {
    Output OutputData;
    
    OutputData.Color = InputData.Color;   
    
    return OutputData;
}
