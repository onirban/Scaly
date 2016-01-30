#include "scalyc.h"
using namespace scaly;
namespace scalyc {

Options::Options()
:files(0), outputName() {}


_Result<Options, OptionsError> Options::parseArguments(_Page* _rp, _Page* _ep, Array<String>& args) {
    size_t length = args.length();
    Options& options = *new(_rp) Options();
    options.files = new(options.getPage()) Array<String>();
    for (size_t i = 0; i < length; i++) {

        if (length < 2 || (**args[i])[0] != '-') {
            options.files->append(*args[i]);
            continue;
        }
        switch ((**args[i])[1])
        {
            case 'o': {
                i++;
                if (i == length)
                    return _Result<Options, OptionsError>(new(_ep) OptionsError(*new(_ep) _InvalidOption(**args[i])));
                else
                    options.outputName = *args[i];
                    
                break;
            }
            default:
                return _Result<Options, OptionsError>(new(_ep) OptionsError(*new(_ep) _UnknownOption(**args[i])));
        }
    }

    if (!options.outputName)
        return _Result<Options, OptionsError>(new(_ep) OptionsError(noOutputOption));
    if (options.files->length() == 0)
        return _Result<Options, OptionsError>(new(_ep) OptionsError(noFilesToCompile));
    
    return _Result<Options, OptionsError>(&options);
}

}
