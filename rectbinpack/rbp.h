struct RectSize {
	int width;
	int height;
	int id;
};

struct Rect {
	int x;
	int y;
	int width;
	int height;
	int id;
};

enum MaxRectsFreeRectChoiceHeuristic {
	MaxRectsBestShortSideFit, ///< -BSSF: Positions the rectangle against the short side of a free rectangle into which it fits the best.
	MaxRectsBestLongSideFit, ///< -BLSF: Positions the rectangle against the long side of a free rectangle into which it fits the best.
	MaxRectsBestAreaFit, ///< -BAF: Positions the rectangle into the smallest free rect into which it fits.
	MaxRectsBottomLeftRule, ///< -BL: Does the Tetris placement.
	MaxRectsContactPointRule ///< -CP: Choosest the placement where the rectangle touches other rects as much as possible.
};

void MaxRects_init(int width, int height, bool flip);
struct Rect MaxRects_insertOne(int width, int height, enum MaxRectsFreeRectChoiceHeuristic method);
unsigned int MaxRects_insert(struct RectSize *sizes, int num, enum MaxRectsFreeRectChoiceHeuristic method, struct Rect **out);
float MaxRects_occupancy();
