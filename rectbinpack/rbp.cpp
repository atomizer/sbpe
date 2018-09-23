#include "MaxRectsBinPack.h"
#include <vector>

using namespace rbp;

MaxRectsBinPack mbp;

std::vector<Rect> dst;

int MaxRectsBestShortSideFit = MaxRectsBinPack::RectBestShortSideFit; ///< -BSSF: Positions the rectangle against the short side of a free rectangle into which it fits the best.
int MaxRectsBestLongSideFit = MaxRectsBinPack::RectBestLongSideFit; ///< -BLSF: Positions the rectangle against the long side of a free rectangle into which it fits the best.
int MaxRectsBestAreaFit = MaxRectsBinPack::RectBestAreaFit; ///< -BAF: Positions the rectangle into the smallest free rect into which it fits.
int MaxRectsBottomLeftRule = MaxRectsBinPack::RectBottomLeftRule; ///< -BL: Does the Tetris placement.
int MaxRectsContactPointRule = MaxRectsBinPack::RectContactPointRule; ///< -CP: Choosest the placement where the rectangle touches other rects as much as possible.


extern "C" {

void MaxRects_init(int width, int height, bool flip) {
    mbp.Init(width, height, flip);
}

struct Rect MaxRects_insertOne(int width, int height, enum MaxRectsFreeRectChoiceHeuristic method) {
	return mbp.Insert(width, height, (MaxRectsBinPack::FreeRectChoiceHeuristic)method);
}

unsigned int MaxRects_insert(struct RectSize *sizes, int num, enum MaxRectsFreeRectChoiceHeuristic method, struct Rect **out) {
	std::vector<RectSize> rects(sizes, sizes + num);
	mbp.Insert(rects, dst, (MaxRectsBinPack::FreeRectChoiceHeuristic)method);
	*out = dst.data();
	return dst.size();
}

float MaxRects_occupancy() {
	return mbp.Occupancy();
}

}
