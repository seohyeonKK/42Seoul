# Defense

## 프로젝트 개요

- 가상 머신의 작동 방식
    
    가상 머신은 물리적 하드웨어 시스템에 구축되어 자체 cpu, 메모리, 네트워크 인터페이스 및 스토리지를 갖추고 가상 컴퓨터 시스템으로 작동하는 가상 환경이다. 하이퍼바이저가 하드웨어에서 가상 머신의 리소스를 분리하고 적절히 프로비저닝(요청에 맞게 공급)하여 사용할 수 있도록 함.
    
    VM이 실행 중이고 사용자 또는 프로그램이 물리적 환경에서 추가적으로 리소스를 요구하면 하이퍼바이저가 물리적 리소스에 대해 해당 요청을 예약한다. 따라서 VM의 운영체제 및 어플리케이션이 리소스를 공유할 수 있게 된다.
    
    +) 하이퍼바이저란 가상머신을 생성하고 구동하는 소프트웨어이다. 가상 머신 모니터(VMM)라고도 불리며 하이퍼바이저 운영체제와 가상 머신의 리소스를 분리해 VM을 생성하고 관리한다.
    
    [가상 머신(버추얼 머신), 가상 서버, 가상 OS 개념 및 작동 방식](https://www.redhat.com/ko/topics/virtualization/what-is-a-virtual-machine)
    
    [하이퍼바이저란?](https://www.redhat.com/ko/topics/virtualization/what-is-a-hypervisor)
    
- 가상 머신의 목적
    
    악성 코드를 분석하거나 감염을 방지하기 위해 컴퓨터의 다른 부분에 영향을 주지 않는 독립적인 환경을 만들고 싶을 때 사용한다.
    
    새로운 어플리케이션을 테스트하거나 프로덕션 환경을 설정할 수 있다.
    
    서버를 가상화하면 각 물리 서버에 수많은 가상 서버를 배치하여 하드웨어 활용률을 개선할 수 있다.
    
- CentOS
    
    Community Enterprise Operating System 의 약자로 Red Hat이 공개한 RHEL(RedHat Enterprise Linux)를 그대로 가져와 RedHat의 브랜드와 로고만 제거하고 배포한 배포본이다. 무료로 사용가능하지만 문제 발생시에 RedHat 회사가 아닌 커뮤니티를 통해 지원되어 패치가 느리다. 서버용 운영체제로 인기가 높다.
    
    RHEL 은 안정성을 우선시한다.
    
- Debian
    
    온라인 커뮤니티에서 제작하여 RedHat보다 먼저 배포되어 시장을 선점했다. 넓은 유저층을 가지고 있어 사용법이 온라인 웹사이트나 커뮤니티에 자세하게 기술되어 있어서 초보 리눅스 유저들이 접근하기 쉬운 운영체제이다. 주로 개인사용자 서버용으로 인기가 많다.
    
    패키지 설치와 업그레이드 등 패키지 관리가 편하다. 패키지 관리 도구(apt 등)를 이용해 패키지 업데이트나 의존성 및 보안 관련 업데이트를 자동으로 수행한다. 패키지 관리가 편리해서 많은 사람의 지지를 받았다.
    
- aptitude
    
    apt의 프론트엔드 프로그램
    
    사용자 인터페이스를 추가해 사용자가 패키지를 검색하여 설치, 제거할 수 있는 high-level 패키지 관리 도구이다. 텍스트 기반 대화형 인터페이스와 비대화형 command line 모드 모두 작동한다.
    
- apt
    
    advanced packaging tool로 소프트웨어의 설치와 제거를 처리하는 패키지 관리 툴이다. 그래픽 인터페이스 없이 명령어로만 사용된다.
    
    설치할 때 패키지 명을 입력하면 해당 패키지와 종속성 목록을 함께 찾아 자동으로 설치한다. 따라서 어떠한 패키지를 설치할 때 종속성 문제를 걱정하지 않아도 된다.
    
- aptitude vs apt
    
    aptitude가 더 방대하고 apt의 apt-get, apt-cache를 포함한 기능을 모두 포함한다. 만약 apt-get이 패키지 설치, 업그레이드, 종속성 검사 등을 한다면 aptitude는 이보다 더 많은 일을 할 수 있다.
    
    aptitude는 why, wht-not 명령어를 이용해 어떤 동작이 왜 안되고 왜 되는지 볼 수 있다.
    
    apt는 설치, 제거 중 충돌이 일어날 경우 종료되지만 aptitude는 해결 방법을 제시할 수 있다.
    
    [What is APT and Aptitude? and What's real Difference Between Them?](https://www.tecmint.com/difference-between-apt-and-aptitude/)
    
- AppArmor
    
    리눅스 어플리케이션 보안 시스템이다. 프로그램에서 엑세스할 수 있는 파일을 지정하는 규칙에 따라 프로그램을 제한한다.
    
    예를 들어 Ubuntu의 기본 구성에서 제한되는 애플리케이션 중 하나는 Evince PDF 뷰어이다. Evince는 사용자 계정으로 실행될 수 있지만 특정 작업 만 수행 할 수 있다. Evince는 PDF 문서를 실행하고 작업하는 데 필요한 최소한의 권한 만 가지고 있다. Evince의 PDF 렌더러에서 취약점이 발견되어 Evince를 점령 한 악성 PDF 문서를 열면 AppArmor가 Evince로 인한 피해를 제한한다. 전통적인 Linux 보안 모델에서 Evince는 액세스 할 수있는 모든 항목에 액세스 할 수 있다. AppArmor를 사용하면 PDF 뷰어가 액세스해야하는 항목에만 액세스 할 수 있다.
    

## 기본 설정

- UFW 확인
    
    ufw status
    
- SSH 확인
    
    systemctl status ssh
    
- OS 확인
    
    cat /etc/os-release
    
    lsb_release -a
    

## 사용자

- 비밀번호
    
    /etc/login.defs
    
    /etc/pam.d/common-password
    
    [How to enforce password complexity on Linux](https://www.networkworld.com/article/2726217/how-to-enforce-password-complexity-on-linux.html)
    
- 유저 추가
    
    adduser {유저이름}
    
- 그룹 생성
    
    groupadd {그룹명}
    
- 그룹에 유저 할당
    
    usermod -aG {그룹} {유저}
    
    -a : add the user to the supplemetary group(s). Use only with the -G option.
    
    -G : 추가로 다른 그룹에 속하게 할 때 사용한다.
    

## 호스트명과 파티션들

- 호스트이름 변경
hostnamectl set-hostname {name}
- 파티션 확인
    
    lsblk
    
- LVM (Logical Volume Manager)
    
    리눅스의 저장 공간을 효율적이고 유연하게 관리하기 위한 커널의 한 부분이다.
    
    특정영역에 사용량이 많아져 저장공간이 부족할 경우 유연하게 용량 조절할 수 있으며 크기 조절이 가능하다. 
    
    디스크나 대용량 스토리지 장치를 유연하고 확장이 가능하게 다룰 수 있는 기술이며 이를 커널에 구현한 기능이다.
    
    ![LVM](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/1f608bd0-bae1-4578-b86b-7c7004aa44b0/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220721%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220721T124702Z&X-Amz-Expires=86400&X-Amz-Signature=751b888a99d75ae36a231f9b3b93b3cd2a1338b4bad1c1681c0169f90106df97&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22&x-id=GetObject)
    

## SUDO

- sudo 확인
    
    sudo -v
    
- visudo
    
    passwd_tries=3
    
    badpass_message=””
    
    iolog_dir=”/var/log/sudo/”
    
    requiretty
    
    secure_path
    
    visudo 커맨드를 사용하여 편집이 가능하다. 만약 visudo를 쓰지 않고 직접 /etc/sudoers를 편집할 경우, 편집하다 실수하면 sudo를 사용하지 못하게 되므로, 문법체크를 해주는 visudo를 사용하는 게 좋다.
    
    +) tty는 리눅스 디바이스 드라이브 중에서 콘솔이나 터미널을 의미한다.
    
- sudo를 사용하는 이유
    
    예를 들어 관리자의 권한이 필요할 때 여러 사람이 root 패스워드를 공유하면 root 패스워드의 정기적인 변경이 어려워지고 root 패스워드가 외부로 노출될 확률이 상대적으로 높아지게 된다.
    
    log추적이 쉬워지며 관리의 권한과 책임이 명확해진다.
    

## UFW

- ufw 확인
    
    ufw status
    
- ufw 란?
    
    Uncomplicated Firewall 로 사용하기 쉬운 방화벽 프로그램이다. 사용자가 직접 방화벽을 설정하는 것은 매우 복잡한데, ufw는 사용자 친화적이고 사용하기 쉬운 인터페이스를 제공하는 방화벽 관리 프로그램이다.
    
- ufw allow 4242
- ufw delete allow 4242

## SSH

- ssh 확인
    
    systemctl status ssh
    
- ssh 란 ?
    
    secure shell protocol로 네트워크 프로토콜이며 인터넷과 같은 public 네트워크를 통해 서로 통신할 때 보안적으로 안전하게 통신하기 위해 사용하는 프로토콜이다. 데이터 전송과 원격제어 등에 사용된다.
    
- 포트포워딩
    
    ssh {name}@{host ip} -p {port}
    

## Script monitoring

- cron
    
    어떠한 작업을 특정 시간에 실행시키기 위한 데몬이다.
