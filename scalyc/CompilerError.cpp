#include "scalyc.h"
using namespace scaly;
namespace scalyc {

long CompilerError::getErrorCode() {
    return (long)errorCode;
}

void* CompilerError::getErrorInfo() {
    return errorInfo;
}

_CompilerError_unableToReadFile::_CompilerError_unableToReadFile(_LetString* file, FileError* error)
: file(file), error(error) {
}

_CompilerError_unableToCreateOutputDirectory::_CompilerError_unableToCreateOutputDirectory(_LetString* directory, DirectoryError* error)
: directory(directory), error(error) {
}

_CompilerError_unableToReadFile* CompilerError::get_unableToReadFile(){
    return (_CompilerError_unableToReadFile*)errorInfo;
}

_CompilerError_syntaxError::_CompilerError_syntaxError(ParserError* error)
: error(error) {
}

_CompilerError_syntaxError* CompilerError::get_syntaxError(){
    return (_CompilerError_syntaxError*)errorInfo;
}

}