#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

void visitor(Function &F) {
    // Do something
}

struct FeatureExtractorPass : PassInfoMixin<FeatureExtractorPass> {
    PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
        visitor(F);
        return PreservedAnalyses::all();
    }
};

struct LegacyFeatureExtractorPass : public FunctionPass {
    static char ID;
    LegacyFeatureExtractorPass() : FunctionPass(ID) {}
    bool runOnFunction(Function &F) override {
        visitor(F);
        return false;
    }
};

} // namespace

llvm::PassPluginLibraryInfo getFeatureExtractorPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "Feature Extractor", LLVM_VERSION_STRING,
            [](PassBuilder &PB) {
                PB.registerPipelineParsingCallback(
                    [](StringRef Name, FunctionPassManager &FPM,
                       ArrayRef<PassBuilder::PipelineElement>) {
                        if (Name == "feature-extractor") {
                            FPM.addPass(FeatureExtractorPass());
                            return true;
                        }
                        return false;
                    });
            }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
    return getFeatureExtractorPassPluginInfo();
}

char LegacyFeatureExtractorPass::ID = 0;

static RegisterPass<LegacyFeatureExtractorPass>
    X("feature-extractor", "Feature Extractor", true, false);
