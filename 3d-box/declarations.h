#pragma once
/*
=                       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
=                     @@V[4]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
=                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@V[5]@
=                 @@@@@@@@@@                                                           @@@@@@
=               @@@@@@ @@@@@                                                         @@@@@@@@
=             @@@@@@   @@@@@                                                       @@@@@ @@@@
=           @@@@@@     @@@@@                                                     @@@@@   @@@@
=         @@@@@@       @@@@@                                                   @@@@@     @@@@
=       @@@@@@         @@@@@                                                 @@@@@       @@@@
=     @@@@@@           @@@@@                                               @@@@@         @@@@
=   @@@@@@                                                               @@@@@           @@@@
= @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@
=V[0]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@V[1]               @@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@               @@@@
=@@@@                                                                 @@@@               @@@@
=@@@@                                                                 @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                                                                 @@@@               @@@@
=@@@@                                                                 @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@                                          @@@@               @@@@
=@@@@                  @@@@@    @@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@   @@@@  @@@@@@@@@@@@@@@@@
=@@@@                  @V[7]    @@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@   @@@@  @@@@@@@@@@@@@V[6]
=@@@@                                                                 @@@@             @@@@@
=@@@@                                                                 @@@@           @@@@@
=@@@@          @@@@@                                                  @@@@         @@@@@
=@@@@        @@@@@                                                    @@@@       @@@@@
=@@@@      @@@@@                                                      @@@@     @@@@@
=@@@@    @@@@@                                                        @@@@   @@@@@
=@@@@  @@@@@                                                          @@@@ @@@@@
=@@@@@@@@                                                             @@@@@@@@
=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
=V[3]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@V[2]
오른쪽으로 갈수록 x증가
위로 갈수록 y증가
뒤로 갈수로 z증가
각각의 모서리는 길이2000


=      y축                                               화면                                         :::::::
=     .+++.                                               %                                   :::::::
=   ++  %  ++                                             %                            :::::::
= ++    %    ++                                           %                     .::::::
=       %                                                 %              :::::::
=       %                                                 %       :::::::
=       %                                                 %:::::::
=       %                                           ::::::%
=       %                                    :::::::      %                  ::::
=       %                             :::::::             %                ::    :::::::::::
=       %                      :::::::                    %               ::                :::::::::::
=       %               :::::::                           %              ::                            ::::
= ::::::%:::::::::::::::                                  %            ::                                ::  +
= :     %        :                                        %           ::                                ::    +
= :    원점(카메라)::::::::::::::::::::::::::::::::::::::::.%.:::::::::::::::::::::::::::::::::::::::::::::::::::z축
= ::::::::::::::::::                                      %         ::                                ::      +
=                   ::::::::                              %        ::                                ::      +
=                           ::::::::                      %       :::::                             ::
=                                   ::::::::              %            :::::::::::                 ::
=                                           ::::::::      %                       :::::::::::     ::
=                                                   ::::::%                                 :::::::
=                                                         %::::::::
=                                                         %        :::::::
=                                                         %               :::::::::
=                                                         %                        :::::::
=                                                         %                               ::::::::
=                                                         %                                       ::::::::
=                                                         %                                               :
16/9 ~ -16/9
*/

#include <Windows.h>
#include <Windowsx.h>
#include <process.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

//앞면 시계방향		:0123
//뒷면 시계방향		:5476
//왼편 시계방향		:3740
//오른편 시계방향	:1562
//윗면 시계방향		:4510
//아랫면 시계방향	:7326
struct original_CUBE_struct {
	XMFLOAT3 F[8] = {
		{ (FLOAT)-1000, (FLOAT)1000, (FLOAT)-1000 },
		{ (FLOAT)1000, (FLOAT)1000, (FLOAT)-1000 },
		{ (FLOAT)1000, (FLOAT)-1000, (FLOAT)-1000 },
		{ (FLOAT)-1000, (FLOAT)-1000, (FLOAT)-1000 },
		{ (FLOAT)-1000, (FLOAT)1000, (FLOAT)1000 },
		{ (FLOAT)1000, (FLOAT)1000, (FLOAT)1000 },
		{ (FLOAT)1000, (FLOAT)-1000, (FLOAT)1000 },
		{ (FLOAT)-1000, (FLOAT)-1000, (FLOAT)1000 } };
	//8개의 점의 좌표
};
struct CUBE_struct {
	XMVECTOR V[8] = { NULL, }; //물체내부를 원점으로 잡은상태
	XMVECTOR Accel = XMVectorZero();
	XMVECTOR Veloc = XMVectorZero();
	XMMATRIX Torque = XMMatrixIdentity();
};
typedef vector<XMVECTOR> VV;
typedef vector<POINT> VP;
/* 타입 정의 */

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
/* 메시지 프로시저 */

#define LOG_id 100
#define FOV_text_id 101
#define FOV_id 102
#define LINE_text_id 111
#define LINE_id 112
/* 상수 정의 */

void LOG_print(LPCTSTR);
void LOG_print(int);
void LOG_print(float);
void LOG_setting(HWND, HINSTANCE);
void LOG_destroy();
/* log창 관련 */

void FOV_setting(HWND, HINSTANCE);
void FOV_handling(WPARAM, LPARAM);
FLOAT FOV_get();
void FOV_destroy();
bool FOV_paint();
/* fov컨트롤 관련 */

void LINE_setting(HWND, HINSTANCE);
void LINE_destroy();
void LINE_handling(WPARAM, LPARAM);
int LINE_NUM_get();
bool LINE_paint();
/* 빗금개수 관련 */

bool is_bumped(XMVECTOR);
bool is_bumped(XMMATRIX);
void camera_rotating(FLOAT, FLOAT);
void setting();
bool is_hidden(int);
void physic_calc(bool);
void physic_reset();
void front(); void rear(); void left(); void right();
void update_matrix();
XMVECTOR get_point(int, int);
XMVECTOR get_transformed(int, int);
void get_line(VV&, VV&);
void set_display(RECT&);
/* 물체 계산 관련 */

void handling_WM_CREATE(HWND, UINT, WPARAM, LPARAM);
void handling_WM_PAINT(HWND, UINT, WPARAM, LPARAM);
void handling_WM_MOUSEMOVE(HWND, UINT, WPARAM, LPARAM);
void handling_WM_LBUTTONUP(HWND, UINT, WPARAM, LPARAM);
void handling_WM_RBUTTONUP(HWND, UINT, WPARAM, LPARAM);
void handling_WM_SIZE(HWND, UINT, WPARAM, LPARAM);
void handling_WM_DESTROY(HWND, UINT, WPARAM, LPARAM);
void handling_WM_HSCROLL(HWND, UINT, WPARAM, LPARAM);
/* 메세지핸들링 */

int inline _key(char C) { return GetAsyncKeyState(C) & 0x8000; }
int inline _key1(char C) { return (GetAsyncKeyState(C) & 0x8001) == 0x8001; }
POINT inline vtop(XMVECTOR& V) { return { (LONG)XMVectorGetX(V), (LONG)XMVectorGetY(V) }; }
void inline vvtovp(VV& V, VP& P) { for each (XMVECTOR var in V) P.push_back(vtop(var)); }
/* 인라인함수 */

void Box_Translation(HWND, UINT, UINT_PTR, DWORD);
void Physic_Effects(HWND, UINT, UINT_PTR, DWORD);
void Camera_Movement(HWND, UINT, UINT_PTR, DWORD);
void Paint_Trigger(HWND, UINT, UINT_PTR, DWORD);
void Key_Check(HWND, UINT, UINT_PTR, DWORD);
/* Timer핸들링 */