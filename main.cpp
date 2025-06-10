#include <Novice.h>
#include"math.h"
#include <Vector3.h>
const char kWindowTitle[] = "GC2D_06_マスヤマ_リョウタ_タイトル";
const int kWindowWidte = 1280;
const int kWindowHaight = 720;
struct Matrix4x4
{
	float m[4][4];
};
Matrix4x4 MakeAffineMatrix(const Vector3 &scale, const Vector3& rotate, const Vector3& translate)
{

}
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix,const char*label){
	Novice::ScreenPrintf(x, 20 + y, "%s", label);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidte, kWindowHaight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		Vector3 scale{ 1.2f,0.79f,-2.1f };
		Vector3 rotate{ 0.4f,1.43f,-0.8f };
		Vector3 translate{ -2.7f,-4.15f,1.57f };
		Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		MatrixScreenPrintf(0, 0, worldMatrix, "worldMarix");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
