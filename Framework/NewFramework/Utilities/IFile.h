#pragma once

struct FileReadResult {
    void* content = nullptr;
    uint32_t unknown_1;
    size_t bytesRead = 0;
    size_t readEnd = 0;
}

class IFile {
    virtual ~IFile();
    virtual void FreeFile();
    virtual const std::string& GetFilePath();
    virtual void FUN_008ae7c0();
    virtual void SeekBytes(size_t bytesToSeek, size_t whereToStop);
    virtual size_t GetSeekedBytes();
    virtual bool ReadString(std::string& result);
    virtual void FUN_008ae640();
    virtual uint64_t ReadFromCursor(void* resultBuffer, uint32_t bufferLen, uint32_t param_3);
    virtual void FUN_008ae700();
    virtual void FUN_008ae820();
    virtual void FUN_008ae830();
    virtual void FUN_008ae810();
    virtual void FUN_008ae870();
}