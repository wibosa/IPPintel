#include <stdio.h>
#include "ipp.h"
#include "ippi.h"

#define PRINT_INFO(feature, text) printf("  %-30s= ", #feature); \
    printf("%c\t%c\t", (cpuFeatures & feature) ? 'Y' : 'N', (enabledFeatures & feature) ? 'Y' : 'N'); \
    printf( #text "\n")

int main(int argc, char* argv[])
{
    const       IppLibraryVersion* libVersion;
    IppStatus   status;
    Ipp64u      cpuFeatures, enabledFeatures;

    ippInit();                      /* Initialize Intel(R) IPP library */
    libVersion = ippGetLibVersion();/* Get Intel(R) IPP library version info */
    printf("%s %s\n", libVersion->Name, libVersion->Version);
    printf("%s %d %d %s %s %s\n", libVersion->Name, libVersion->major, libVersion->minor, libVersion->Name, libVersion->Version, libVersion->targetCpu, libVersion->BuildDate );

    status = ippGetCpuFeatures(&cpuFeatures, 0);/* Get CPU features and features enabled with selected library level */
    if (ippStsNoErr != status) return status;
    enabledFeatures = ippGetEnabledCpuFeatures();
    printf("Features supported: by CPU\tby Intel(R) IPP\n");
    printf("------------------------------------------------\n");
    PRINT_INFO(ippCPUID_MMX, Intel(R) Architecture MMX technology supported);
    PRINT_INFO(ippCPUID_SSE, Intel(R) Streaming SIMD Extensions);
    PRINT_INFO(ippCPUID_SSE2, Intel(R) Streaming SIMD Extensions 2);
    PRINT_INFO(ippCPUID_SSE3, Intel(R) Streaming SIMD Extensions 3);
    PRINT_INFO(ippCPUID_SSSE3, Supplemental Streaming SIMD Extensions 3);
    PRINT_INFO(ippCPUID_MOVBE, Intel(R) MOVBE instruction);
    PRINT_INFO(ippCPUID_SSE41, Intel(R) Streaming SIMD Extensions 4.1);
    PRINT_INFO(ippCPUID_SSE42, Intel(R) Streaming SIMD Extensions 4.2);
    PRINT_INFO(ippCPUID_AVX, Intel(R) Advanced Vector Extensions instruction set);
    PRINT_INFO(ippAVX_ENABLEDBYOS, Intel(R) Advanced Vector Extensions instruction set is supported by OS);
    PRINT_INFO(ippCPUID_AES, Intel(R) AES New Instructions);
    PRINT_INFO(ippCPUID_CLMUL, Intel(R) CLMUL instruction);
    PRINT_INFO(ippCPUID_RDRAND, Intel(R) RDRAND instruction);
    PRINT_INFO(ippCPUID_F16C, Intel(R) F16C new instructions);
    PRINT_INFO(ippCPUID_AVX2, Intel(R) Advanced Vector Extensions 2 instruction set);
    PRINT_INFO(ippCPUID_ADCOX, Intel(R) ADOX / ADCX new instructions);
    PRINT_INFO(ippCPUID_RDSEED, Intel(R) RDSEED instruction);
    PRINT_INFO(ippCPUID_PREFETCHW, Intel(R) PREFETCHW instruction);
    PRINT_INFO(ippCPUID_SHA, Intel(R) SHA new instructions);
    PRINT_INFO(ippCPUID_AVX512F, Intel(R) Advanced Vector Extensions 512 Foundation instruction set);
    PRINT_INFO(ippCPUID_AVX512CD, Intel(R) Advanced Vector Extensions 512 CD instruction set);
    PRINT_INFO(ippCPUID_AVX512ER, Intel(R) Advanced Vector Extensions 512 ER instruction set);
    PRINT_INFO(ippCPUID_AVX512PF, Intel(R) Advanced Vector Extensions 512 PF instruction set);
    PRINT_INFO(ippCPUID_AVX512BW, Intel(R) Advanced Vector Extensions 512 BW instruction set);
    PRINT_INFO(ippCPUID_AVX512VL, Intel(R) Advanced Vector Extensions 512 VL instruction set);
    PRINT_INFO(ippCPUID_AVX512VBMI, Intel(R) Advanced Vector Extensions 512 Bit Manipulation instructions);
    PRINT_INFO(ippCPUID_MPX, Intel(R) Memory Protection Extensions);
    PRINT_INFO(ippCPUID_AVX512_4FMADDPS, Intel(R) Advanced Vector Extensions 512 DL floating - point single precision);
    PRINT_INFO(ippCPUID_AVX512_4VNNIW, Intel(R) Advanced Vector Extensions 512 DL enhanced word variable precision);
    PRINT_INFO(ippCPUID_KNC, Intel(R) Xeon Phi(TM) Coprocessor);
    PRINT_INFO(ippCPUID_AVX512IFMA, Intel(R) Advanced Vector Extensions 512 IFMA(PMADD52) instruction set);
    PRINT_INFO(ippAVX512_ENABLEDBYOS, Intel(R) Advanced Vector Extensions 512 is supported by OS);
    return 0;
}