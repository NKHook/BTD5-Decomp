#pragma once

#include "../IFile.h"
#include <string>
#include <stdint.h>

class CUnzippedFile {
public:
    void* fileContent = nullptr;
    FileReadResult readResult;
    size_t fileSize = 0;
    std::string filePath = "";
    uint32_t unknown_1;
public:
    CUnzippedFile();

    virtual ~CUnzippedFile();
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