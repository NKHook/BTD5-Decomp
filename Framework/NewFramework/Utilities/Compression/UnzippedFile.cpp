#include "UnzippedFile.h"

CUnzippedFile::CUnzippedFile() {}
CUnzippedFile::~CUnzippedFile() {}
void CUnzippedFile::FreeFile() {
    if(this->fileContent) {
        free(this->fileContent);
        this->fileContent = nullptr;
    }
}
const CUnzippedFile::std::string& GetFilePath() {
    return this->filePath;
}
void CUnzippedFile::FUN_008ae7c0();
void CUnzippedFile::SeekBytes(size_t bytesToSeek, size_t whereToStop) {
    if (this->fileContent) {
        this->readResult.content = this->fileContent + bytesToSeek;
        this->readResult.bytesRead = bytesToSeek;
        this->readResult.readEnd = whereToStop;
    }
}
size_t CUnzippedFile::GetSeekedBytes() {
    return this->readResult.bytesRead;
}
bool CUnzippedFile::ReadString(std::string& result) {
    if (this->fileContent != 0) {
        result = std::string(this->fileContent,this->fileSize);
    }
    return this->fileContent != nullptr;
}
void CUnzippedFile::FUN_008ae640();
uint64_t CUnzippedFile::ReadFromCursor(void* resultBuffer, uint32_t bufferLen, uint32_t param_3) {
    if (this->fileContent == 0) {
        return 0;
    }
    if (resultBuffer != nullptr) {
        if ((bufferLen | param_3) != 0) {
            if (this->readResult.content == nullptr) {
                this->readResult.content = this->fileContent;
                this->readResult.bytesRead = 0;
                this->readResult.readEnd = 0;
            }
            memcpy(resultBuffer, this->readResult.content, bufferLen);
            this->readResult.content = this->readResult.content + bufferLen;
            pBytesRead = &this->readResult.bytesRead;
            bytesRead = *pBytesRead;
            *pBytesRead = *pBytesRead + bufferLen;
            pBytesRead = &this->readResult.readEnd;
            *pBytesRead = *pBytesRead + param_3 + (uint)CARRY4(bytesRead, bufferLen);
            return CONCAT44(param_3,bufferLen);
        }
    }
    return 0;
}
void CUnzippedFile::FUN_008ae700();
void CUnzippedFile::FUN_008ae820();
void CUnzippedFile::FUN_008ae830();
void CUnzippedFile::FUN_008ae810();
void CUnzippedFile::FUN_008ae870();