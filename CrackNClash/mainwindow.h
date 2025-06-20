#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Structure to store AI guess history
struct AIGuess {
    QVector<int> code;
    int correctPins;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_easyButton_clicked();
    void on_mediumButton_clicked();
    void on_hardButton_clicked();
    void on_submitButton_clicked();
    void updateTimer();
    void aiMakeGuess();

private:
    Ui::MainWindow *ui;

    // Game state
    QVector<int> secretCode;
    int codeLength;
    int timeLeft;
    QTimer *timer;

    // AI state
    QTimer *aiTimer;
    int aiGuessCount;
    QVector<AIGuess> aiGuessHistory;
    QVector<QVector<int>> aiCandidates;

    // Game methods
    void switchToGameScreen();
    void generateSecretCode();
    int countCorrectPins(const QString &guess);
    QString getCorrectPositionsFeedback(const QString &guess);
    void endGame(const QString &message);

    // AI backtracking methods
    void startAI();
    void generateAllCombinations();
    void generateCombinationsRecursive(QVector<int> &combination, int position);
    QVector<int> findBestGuess();
    void filterCandidates(const AIGuess &lastGuess);
    bool isConsistentWithHistory(const QVector<int> &candidate);
    int getCorrectPinsForCodes(const QVector<int> &code1, const QVector<int> &code2);
};

#endif // MAINWINDOW_H
