[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver AHT20

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/aht20/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

차세대 온도 및 습도 센서인 AHT20은 크기와 성능 면에서 새로운 표준을 제시합니다. 리플로 납땜에 적합한 2열 플랫 핀 없는 SMD 패키지, 바닥면 3x3mm, 높이 1.0mm. 센서는 보정된 디지털 신호를 출력합니다. 표준 IIC 형식의 AHT20에는 새로 설계된 ASIC 전용 칩, 개선된 MEMS 반도체 용량성 습도 센서 요소 및 표준 온칩 온도 센서 요소가 장착되어 있습니다. 성능이 크게 향상되었거나 이전 세대 센서의 신뢰성 수준을 능가했습니다. 온도 및 습도 센서의 세대는 열악한 환경에서 보다 안정적인 성능을 제공하도록 개선되었습니다. 각 센서는 보정 및 테스트되며 제품 로트 번호가 제품 표면에 인쇄됩니다. 센서의 개선 및 소형화로 인해 더 비용 효율적이며 궁극적으로 모든 장치가 최첨단 에너지 절약 작동 모드의 이점을 누릴 수 있습니다. 그것은 소비자 전자 제품, 의료, 자동차, 산업, 기상 및 기타 분야에서 사용됩니다.

LibDriver AHT20은 LibDriver에서 출시한 AHT20의 전체 기능 드라이버입니다. 온도 및 상대 습도를 읽는 기능을 제공합니다. LibDriver는 MISRA를 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic](#example-basic)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver AHT20의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver AHT20용 플랫폼 독립적인 IIC버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver AHT20드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver AHT20프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver AHT20오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 AHT20데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인 IIC버스 템플릿을 참조하여 지정된 플랫폼에 대한 IIC버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

#### example basic

```C
#include "driver_aht20_basic.h"

uint8_t res;
uint8_t i;
float temperature;
uint8_t humidity;

res = aht20_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    aht20_interface_delay_ms(2000);
    res = aht20_basic_read((float *)&temperature, (uint8_t *)&humidity);
    if (res != 0)
    {
        (void)aht20_basic_deinit();

        return 1;
    }
    aht20_interface_debug_print("aht20: temperature is %0.2fC.\n", temperature);
    aht20_interface_debug_print("aht20: humidity is %d%%.\n", humidity); 
    
    ...
        
}

...

(void)aht20_basic_deinit();

return 0;
```

### 문서

온라인 문서: [https://www.libdriver.com/docs/aht20/index.html](https://www.libdriver.com/docs/aht20/index.html).

오프라인 문서: /doc/html/index.html.

### 기고

CONTRIBUTING.md 를 참조하십시오.

### 저작권

저작권 (c) 2015 - 지금 LibDriver 판권 소유

MIT 라이선스(MIT)

이 소프트웨어 및 관련 문서 파일("소프트웨어")의 사본을 얻은 모든 사람은 이에 따라 무제한 사용, 복제, 수정, 통합, 출판, 배포, 2차 라이선스를 포함하여 소프트웨어를 처분할 수 있는 권리가 부여됩니다. 소프트웨어의 사본에 대한 라이선스 및/또는 판매, 그리고 소프트웨어가 위와 같이 배포된 사람의 권리에 대한 2차 라이선스는 다음 조건에 따릅니다.

위의 저작권 표시 및 이 허가 표시는 이 소프트웨어의 모든 사본 또는 내용에 포함됩니다.

이 소프트웨어는 상품성, 특정 목적에의 적합성 및 비침해에 대한 보증을 포함하되 이에 국한되지 않는 어떠한 종류의 명시적 또는 묵시적 보증 없이 "있는 그대로" 제공됩니다. 어떤 경우에도 저자 또는 저작권 소유자는 계약, 불법 행위 또는 기타 방식에 관계없이 소프트웨어 및 기타 소프트웨어 사용으로 인해 발생하거나 이와 관련하여 발생하는 청구, 손해 또는 기타 책임에 대해 책임을 지지 않습니다.

### 문의하기

연락주세요lishifenging@outlook.com.