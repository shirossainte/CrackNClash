#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QRegularExpression>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , aiTimer(new QTimer(this))
{
    ui->setupUi(this);

    // Show only start screen
    ui->stackedWidget->setCurrentWidget(ui->startScreen);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(aiTimer, &QTimer::timeout, this, &MainWindow::aiMakeGuess);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->difficultyScreen);
}

void MainWindow::on_easyButton_clicked()
{
    timeLeft = 60;
    codeLength = 3;
    switchToGameScreen();
}

void MainWindow::on_mediumButton_clicked()
{
    timeLeft = 45;
    codeLength = 4;
    switchToGameScreen();
}

void MainWindow::on_hardButton_clicked()
{
    timeLeft = 30;
    codeLength = 5;
    switchToGameScreen();
}

void MainWindow::switchToGameScreen()
{
    ui->stackedWidget->setCurrentWidget(ui->gameScreen);
    ui->outputTextEdit->clear();
    ui->submitButton->setEnabled(true);
    ui->inputLineEdit->setEnabled(true);
    ui->inputLineEdit->clear();
    ui->timeBar->setMaximum(timeLeft);
    ui->timeBar->setValue(timeLeft);

    generateSecretCode();
    timer->start(1000);
    startAI();

    ui->outputTextEdit->append("🎮 Game Started! Guess the " + QString::number(codeLength) + "-digit code (0-5).");
}

void MainWindow::generateSecretCode()
{
    secretCode.clear();
    for (int i = 0; i < codeLength; ++i) {
        secretCode.append(QRandomGenerator::global()->bounded(6));
    }
}

int MainWindow::countCorrectPins(const QString &guess)
{
    int correct = 0;
    for (int i = 0; i < codeLength; ++i) {
        if (i < guess.length() && guess[i].digitValue() == secretCode[i]) {
            correct++;
        }
    }
    return correct;
}

QString MainWindow::getCorrectPositionsFeedback(const QString &guess)
{
    QStringList feedback;

    for (int i = 0; i < codeLength; ++i) {
        if (i < guess.length() && guess[i].digitValue() == secretCode[i]) {
            QString ordinal;
            switch (i) {
            case 0: ordinal = "1st"; break;
            case 1: ordinal = "2nd"; break;
            case 2: ordinal = "3rd"; break;
            default: ordinal = QString::number(i + 1) + "th"; break;
            }
            feedback.append("✅ The " + ordinal + " number is correct");
        }
    }

    if (feedback.isEmpty())
        return "❌ No digits are correct at the right position.";
    return feedback.join("\n");
}

void MainWindow::on_submitButton_clicked()
{
    QString guess = ui->inputLineEdit->text();
    if (guess.length() != codeLength || guess.contains(QRegularExpression("[^0-5]"))) {
        ui->outputTextEdit->append("❌ Invalid input. Enter " + QString::number(codeLength) + " digits (0-5).");
        return;
    }

    int correct = countCorrectPins(guess);
    ui->outputTextEdit->append("🧑 You guessed: " + guess + " → " + QString::number(correct) + "/" + QString::number(codeLength));
    ui->outputTextEdit->append(getCorrectPositionsFeedback(guess));

    if (correct == codeLength) {
        timer->stop();
        aiTimer->stop();
        endGame("🎉 You cracked the code first!");
    }

    ui->inputLineEdit->clear();
}

void MainWindow::updateTimer()
{
    timeLeft--;
    ui->timeBar->setValue(timeLeft);

    if (timeLeft <= 0) {
        timer->stop();
        aiTimer->stop();
        QString code;
        for (int num : secretCode) code += QString::number(num);
        endGame("⏰ Time's up! The code was " + code);
    }
}

void MainWindow::startAI()
{
    aiGuessCount = 0;
    aiGuessHistory.clear();
    aiCandidates.clear();

    // Generate all possible combinations
    generateAllCombinations();

    aiTimer->start(1500); // Guess every 1.5 seconds
}

void MainWindow::generateAllCombinations()
{
    QVector<int> combination(codeLength, 0);
    generateCombinationsRecursive(combination, 0);
}

void MainWindow::generateCombinationsRecursive(QVector<int> &combination, int position)
{
    if (position == codeLength) {
        aiCandidates.append(combination);
        return;
    }

    for (int digit = 0; digit <= 5; ++digit) {
        combination[position] = digit;
        generateCombinationsRecursive(combination, position + 1);
    }
}

void MainWindow::aiMakeGuess()
{
    QString guess;

    if (aiCandidates.isEmpty()) {
        // Fallback to random if no candidates (shouldn't happen in normal game)
        for (int i = 0; i < codeLength; ++i) {
            guess += QString::number(QRandomGenerator::global()->bounded(6));
        }
    } else {
        // Use backtracking algorithm to make intelligent guess
        QVector<int> bestGuess = findBestGuess();
        for (int digit : bestGuess) {
            guess += QString::number(digit);
        }
    }

    aiGuessCount++;
    int correct = countCorrectPins(guess);

    // Store this guess and its result
    AIGuess guessResult;
    guessResult.code.clear();
    for (QChar c : guess) {
        guessResult.code.append(c.digitValue());
    }
    guessResult.correctPins = correct;
    aiGuessHistory.append(guessResult);

    ui->outputTextEdit->append("🤖 AI guessed: " + guess + " → " + QString::number(correct) + "/" + QString::number(codeLength));
    ui->outputTextEdit->append(getCorrectPositionsFeedback(guess));

    if (correct == codeLength) {
        timer->stop();
        aiTimer->stop();
        endGame("💻 AI cracked the code before you!");
        return;
    }

    // Filter candidates based on this guess result
    filterCandidates(guessResult);
}

QVector<int> MainWindow::findBestGuess()
{
    if (aiGuessHistory.isEmpty()) {
        // First guess - use a strategic starting guess
        if (codeLength >= 3) {
            return QVector<int>{0, 1, 2, 3, 4}.mid(0, codeLength);
        }
    }

    // If we have candidates remaining, pick the first valid one
    if (!aiCandidates.isEmpty()) {
        return aiCandidates.first();
    }

    // Backtrack if needed - generate new possibilities
    return QVector<int>(codeLength, 0);
}

void MainWindow::filterCandidates(const AIGuess &lastGuess)
{
    QVector<QVector<int>> validCandidates;

    for (const QVector<int> &candidate : aiCandidates) {
        if (isConsistentWithHistory(candidate)) {
            validCandidates.append(candidate);
        }
    }

    aiCandidates = validCandidates;

    ui->outputTextEdit->append("🔍 AI narrowed down to " + QString::number(aiCandidates.size()) + " possibilities");
}

bool MainWindow::isConsistentWithHistory(const QVector<int> &candidate)
{
    // Check if this candidate is consistent with all previous guesses
    for (const AIGuess &previousGuess : aiGuessHistory) {
        int expectedCorrect = 0;

        // Count how many positions would be correct if this candidate was the secret
        for (int i = 0; i < codeLength; ++i) {
            if (previousGuess.code[i] == candidate[i]) {
                expectedCorrect++;
            }
        }

        // If the expected correct count doesn't match the actual feedback,
        // this candidate is not consistent
        if (expectedCorrect != previousGuess.correctPins) {
            return false;
        }
    }

    return true;
}

// Helper function to simulate getting correct pins for any two codes
int MainWindow::getCorrectPinsForCodes(const QVector<int> &code1, const QVector<int> &code2)
{
    int correct = 0;
    for (int i = 0; i < codeLength && i < code1.size() && i < code2.size(); ++i) {
        if (code1[i] == code2[i]) {
            correct++;
        }
    }
    return correct;
}

void MainWindow::endGame(const QString &message)
{
    ui->outputTextEdit->append("\n" + message);
    ui->submitButton->setEnabled(false);
    ui->inputLineEdit->setEnabled(false);
}
