#pragma once

class CZipFile {
public:
    CUnzippedFile* LoadFrom(std::string* assetPath, void* param_2, std::string* archivePassword);
};