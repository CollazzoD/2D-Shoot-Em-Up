#include "highscore.h"
#include <fstream>

HighScore::HighScore() {
    score_table.fill(0);
    std::ifstream input("highscore.txt");
    if (input.is_open()) {
        int i = 0;
        while(!input.eof()) {
            input >> score_table[i];
            i++;
            if (i > score_table.size())
                return;
        }
    }
}

HighScore::~HighScore() {
    std::ofstream output("highscore.txt");
    if(output.is_open()) {
        for (const auto &score : score_table)
            output << score << std::endl;
    }
}

int HighScore::GetHighScore() const {
  return *std::max_element(begin(score_table), end(score_table));
}

std::array<int, 10> HighScore::GetScores() const {
    return score_table;
}

void HighScore::PushScore(const int &score) {
  auto min = std::min_element(begin(score_table), end(score_table));
  if (score > *min)
    score_table[min - begin(score_table)] = score;
}