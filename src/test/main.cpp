#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <QApplication>
#include <QTimer>


class AkCoreInitializer : public testing::Environment
{
public:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ::testing::AddGlobalTestEnvironment(new AkCoreInitializer);
    ::testing::InitGoogleTest(&argc, argv);

    QTimer::singleShot(50, &app, [&app] {
        RUN_ALL_TESTS();
        app.quit();
    });

    return app.exec();
}
