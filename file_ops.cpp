#include <iostream>
#include <string>

enum class ErrorType {
    SUCCESS,
    EPERMISSION,
};
class FileOps {
    public:
    virtual ErrorType WriteFile(const std::string& file_name) = 0;
    virtual ErrorType ReadFile(const std::string& file_name) = 0;
    virtual ErrorType DeleteFile(const std::string& file_name) = 0;
    virtual ErrorType CreateFile(const std::string& file_name) = 0;
   // virtual ~FileOps() = default;
};

class CloudFileOps : public FileOps {
    public:
    ErrorType WriteFile(const std::string& file_name) override {
        std::cout << "CloudFileOps::WriteFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType ReadFile(const std::string& file_name) override {
        std::cout << "CloudFileOps::ReadFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType DeleteFile(const std::string& file_name) override {
        std::cout << "CloudFileOps::DeleteFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType CreateFile(const std::string& file_name) override {
        std::cout << "CloudFileOps::CreateFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ~CloudFileOps() {
        std::cerr << "CloudFileOps::~CloudFileOps" << std::endl;
    }
};

class LocalFileOps : public FileOps {
    public:
    ErrorType WriteFile(const std::string& file_name) override {
        std::cout << "LocalFileOps::WriteFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType ReadFile(const std::string& file_name) override {
        std::cout << "LocalFileOps::ReadFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType DeleteFile(const std::string& file_name) override {
        std::cout << "LocalFileOps::DeleteFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ErrorType CreateFile(const std::string& file_name) override {
        std::cout << "LocalFileOps::CreateFile" << std::endl;
        return ErrorType::SUCCESS;
    }
    ~LocalFileOps() {
        std::cerr << "LocalFileOps::~LocalFileOps" << std::endl;
    }
};


int main() {
    FileOps* file_ops = new(CloudFileOps);


    auto generic_write = [](FileOps* file_ops, const std::string& file_name) {
        file_ops->WriteFile(file_name);
        return 0;
    };

    //generic_write(cloud_file_ops, "cloud_file.txt");
    //generic_write(local_file_ops, "local_file.txt");
    generic_write(file_ops, "local_file.txt");
    delete file_ops;
    return 0;
}
