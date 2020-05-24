#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <algorithm>
#include <array>

class HighScore {
public:
  HighScore();
  ~HighScore();
  HighScore(const HighScore &source) = delete;
  HighScore &operator=(const HighScore &source) = delete;
  HighScore(HighScore &&source) = delete;
  HighScore &operator=(HighScore &&source) = delete;

  int GetHighScore() const;
  void PushScore(const int &score);

private:
  std::array<int, 10> score_table;
};

#endif