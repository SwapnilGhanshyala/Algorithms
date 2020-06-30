#include <queue>

using namespace std;
class JukeBox
{
    private:
    int NumOfTunes=20;
    queue<int> nextSongNumber;
    public:
void playTune(int tuneNum);
void pauseMusic();
void stopMusic();
void queueSong(int songNum)
{
    nextSongNumber.push(songNum);
}
void shufflePlay();
void playNextInQueue();
};