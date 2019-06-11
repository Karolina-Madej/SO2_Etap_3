#include <vector>

class Screen{

    private: 
         float screenWidth;
         float screenHieght;

    public:
        Screen();
        ~Screen();

        void initScreen();
        float getScreenWidth();
        float getScreenHeight();
};
