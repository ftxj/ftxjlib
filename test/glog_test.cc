#include <gflags/gflags.h>
#include <glog/logging.h>

int main(int argc, char* argv[])
{
    // 解析命令行参数
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    // 初始化日志库
    google::InitGoogleLogging(argv[0]);
    LOG(ERROR) << "Hello, World!";
}