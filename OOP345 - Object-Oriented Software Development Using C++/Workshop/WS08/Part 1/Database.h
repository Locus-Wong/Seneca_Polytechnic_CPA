#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H
#include <string>
#include <memory>
namespace seneca {
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };

    class Database{
    static std::shared_ptr<Database>instance;
        
        int numOfEntries{};
        std::string keys[20]; // statically-allocated array of strings with a size of 20
        std::string values[20]{}; // statically-allocated array of strings with a size of 20
        std::string filename{};
        Database(const std::string& filename); // private constructor to prevent client from instantiating this class.
        void encryptDecrypt(std::string& value) {};
        
    public:
        static std::shared_ptr<Database> getInstance(const std::string& filename);
        Err_Status GetValue(const std::string& key, std::string& value);
        Err_Status SetValue(const std::string& key, const std::string& value);
        ~Database();
    };
}



#endif
