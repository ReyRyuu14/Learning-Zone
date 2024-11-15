#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QPixmap>

class TrafficLightSimulator : public QWidget {
    Q_OBJECT

public:
    TrafficLightSimulator(QWidget *parent = nullptr) : QWidget(parent) {
        setupUI();
    }

private slots:
    void startSimulation() {
        QString intervalStr = intervalLineEdit->text();
        int interval = intervalStr.toInt();

        if (interval <= 0)
            return;
        intervalLineEdit->setEnabled(false);
        startButton->setEnabled(false);
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TrafficLightSimulator::changeLight);
        timer->start(interval);
    }

    void changeLight() {
        if (currentLightIndex == 0) {
            currentLightIndex = 1;
            trafficLightLabel->setPixmap(QPixmap(":/yellow.jpg"));
        } else if (currentLightIndex == 1) {
            currentLightIndex = 2;
            trafficLightLabel->setPixmap(QPixmap(":/red.jpg"));
        } else {
            currentLightIndex = 0;
            trafficLightLabel->setPixmap(QPixmap(":/green.jpg"));
        }
    }

private:
    void setupUI() {
        QVBoxLayout *layout = new QVBoxLayout;

        trafficLightLabel = new QLabel;
        trafficLightLabel->setPixmap(QPixmap(":/green.jpg"));
        layout->addWidget(trafficLightLabel);

        intervalLineEdit = new QLineEdit;
        layout->addWidget(intervalLineEdit);

        startButton = new QPushButton("Start Simulation");
        connect(startButton, &QPushButton::clicked, this, &TrafficLightSimulator::startSimulation);
        layout->addWidget(startButton);

        setLayout(layout);
    }

    QLabel *trafficLightLabel;
    QLineEdit *intervalLineEdit;
    QPushButton *startButton;
    QTimer *timer;
    int currentLightIndex = 0;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TrafficLightSimulator simulator;
    simulator.show();

    return app.exec();
}

#include "main.moc"
