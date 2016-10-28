#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
	void AddScore(int score)
	{
		m_Scores.push_back(score);
	}
	int GetScore(int n)
	{
		return m_Scores[n];
	}
	int GetTotalScore()
	{
		int sum = 0;
		for (int score : m_Scores)
			sum += score;
		return sum;
	}
	double GetAverageScore()
	{
		return (double)GetTotalScore() / m_Scores.size();
	}
private:
	vector<int> m_Scores;
};

class Quiz
{
public:
	void AddScore(int score)
	{
		m_Scores.push_back(score);
	}
	int GetScore(int n)
	{
		return m_Scores[n];
	}
	int GetTotalScore()
	{
		int sum = 0;
		for (int score : m_Scores)
			sum += score;
		return sum;
	}
	double GetAverageScore()
	{
		return (double)GetTotalScore() / m_Scores.size();
	}
	int GetHighestScore()
	{
		int max = 0;
		for (int score : m_Scores)
			if (score > max)
				max = score;
		return max;
	}
	int GetLowestScore()
	{
		int min = m_Scores.front();
		for (int score : m_Scores)
		{
			if (score < min)
				min = score;
		}
		return min;
	}
private:
	vector<int> m_Scores;
};

int main()
{
	int quizCount, stuCount;
	cout << "How many quiz grades?";
	cin >> quizCount;
	cout << "How many students?";
	cin >> stuCount;

	vector<Student> students;
	vector<Quiz> quizes;
	
	for (int i = 0; i < quizCount; ++i)
		quizes.emplace_back();
	for (int i = 0; i < stuCount; ++i)
		students.emplace_back();

	for (int i = 0; i < stuCount; ++i)
	{
		cout << "Student " << i + 1 << ":" << endl;
		for (int j = 0; j < quizCount; ++j)
		{
			int score;
			cout << "Quiz " << j + 1 << ":";
			cin >> score;
			students[i].AddScore(score);
			quizes[j].AddScore(score);
		}
	}

	cout << "Student\tTotal\tAverage" << endl;
	for (int i = 0; i < stuCount; ++i)
	{
		Student &s = students[i];
		cout << i + 1 << "\t" << s.GetTotalScore() << "\t" << s.GetAverageScore() << endl;
	}

	cout << "Quiz\tAverage\tHigest\tLowest" << endl;
	for (int j = 0; j < quizCount; ++j)
	{
		Quiz &q = quizes[j];
		cout << j + 1 << "\t" << q.GetAverageScore() << "\t" << q.GetHighestScore() << "\t" << q.GetLowestScore() << endl;
	}
	return 0;
}
