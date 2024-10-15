# StructuredFuzzer

Code and data for the paper: [StructuredFuzzer: Fuzzing Structured Text-Based Control Logic Applications](https://doi.org/10.3390/electronics13132475).

NOTICE:  This computer software was prepared by Battelle Energy
Alliance, LLC, hereinafter the Contractor, under Contract
No. AC07-05ID14517 with the United States (U. S.) Department of
Energy (DOE).  The Government is granted for itself and others acting on
its behalf a nonexclusive, paid-up, irrevocable worldwide license in this
data to reproduce, prepare derivative works, and perform publicly and
display publicly, by or on behalf of the Government. There is provision for
the possible extension of the term of this license.  Subsequent to that
period or any extension granted, the Government is granted for itself and
others acting on its behalf a nonexclusive, paid-up, irrevocable worldwide
license in this data to reproduce, prepare derivative works, distribute
copies to the public, perform publicly and display publicly, and to permit
others to do so.  The specific term of the license can be identified by
inquiry made to Contractor or DOE.  NEITHER THE UNITED STATES NOR THE UNITED
STATES DEPARTMENT OF ENERGY, NOR CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR
IMPLIED, OR ASSUMES ANY LIABILITY OR RESPONSIBILITY FOR THE USE, ACCURACY,
COMPLETENESS, OR USEFULNESS OR ANY INFORMATION, APPARATUS, PRODUCT, OR
PROCESS DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT INFRINGE PRIVATELY
OWNED RIGHTS.




## Citation
```bibtex

@Article{electronics13132475,
AUTHOR = {Koffi, Koffi Anderson and Kampourakis, Vyron and Song, Jia and Kolias, Constantinos and Ivans, Robert C.},
TITLE = {StructuredFuzzer: Fuzzing Structured Text-Based Control Logic Applications},
JOURNAL = {Electronics},
VOLUME = {13},
YEAR = {2024},
NUMBER = {13},
ARTICLE-NUMBER = {2475},
URL = {https://www.mdpi.com/2079-9292/13/13/2475},
ISSN = {2079-9292},
ABSTRACT = {Rigorous testing methods are essential for ensuring the security and reliability of industrial controller software. Fuzzing, a technique that automatically discovers software bugs, has also proven effective in finding software vulnerabilities. Unsurprisingly, fuzzing has been applied to a wide range of platforms, including programmable logic controllers (PLCs). However, current approaches, such as coverage-guided evolutionary fuzzing implemented in the popular fuzzer American Fuzzy Lop Plus Plus (AFL++), are often inadequate for finding logical errors and bugs in PLC control logic applications. They primarily target generic programming languages like C/C++, Java, and Python, and do not consider the unique characteristics and behaviors of PLCs, which are often programmed using specialized programming languages like Structured Text (ST). Furthermore, these fuzzers are ill suited to deal with complex input structures encapsulated in ST, as they are not specifically designed to generate appropriate input sequences. This renders the application of traditional fuzzing techniques less efficient on these platforms. To address this issue, this paper presents a fuzzing framework designed explicitly for PLC software to discover logic bugs in applications written in ST specified by the IEC 61131-3 standard. The proposed framework incorporates a custom-tailored PLC runtime and a fuzzer designed for the purpose. We demonstrate its effectiveness by fuzzing a collection of ST programs that were crafted for evaluation purposes. We compare the performance against a popular fuzzer, namely, AFL++. The proposed fuzzing framework demonstrated its capabilities in our experiments, successfully detecting logic bugs in the tested PLC control logic applications written in ST. On average, it was at least 83 times faster than AFL++, and in certain cases, for example, it was more than 23,000 times faster.},
DOI = {10.3390/electronics13132475}
}



