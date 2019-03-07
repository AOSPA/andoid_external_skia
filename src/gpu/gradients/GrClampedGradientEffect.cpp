/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrClampedGradientEffect.fp; do not modify.
 **************************************************************************************************/
#include "GrClampedGradientEffect.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLClampedGradientEffect : public GrGLSLFragmentProcessor {
public:
    GrGLSLClampedGradientEffect() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrClampedGradientEffect& _outer = args.fFp.cast<GrClampedGradientEffect>();
        (void)_outer;
        auto leftBorderColor = _outer.leftBorderColor();
        (void)leftBorderColor;
        auto rightBorderColor = _outer.rightBorderColor();
        (void)rightBorderColor;
        auto makePremul = _outer.makePremul();
        (void)makePremul;
        auto colorsAreOpaque = _outer.colorsAreOpaque();
        (void)colorsAreOpaque;
        fLeftBorderColorVar = args.fUniformHandler->addUniform(
                kFragment_GrShaderFlag, kHalf4_GrSLType, kDefault_GrSLPrecision, "leftBorderColor");
        fRightBorderColorVar =
                args.fUniformHandler->addUniform(kFragment_GrShaderFlag, kHalf4_GrSLType,
                                                 kDefault_GrSLPrecision, "rightBorderColor");
        SkString _child1("_child1");
        this->emitChild(1, &_child1, args);
        fragBuilder->codeAppendf(
                "half4 t = %s;\nif (!%s && t.y < 0.0) {\n    %s = half4(0.0);\n} else if (t.x < "
                "0.0) {\n    %s = %s;\n} else if (t.x > 1.0) {\n    %s = %s;\n} else {",
                _child1.c_str(),
                (_outer.childProcessor(1).preservesOpaqueInput() ? "true" : "false"),
                args.fOutputColor, args.fOutputColor,
                args.fUniformHandler->getUniformCStr(fLeftBorderColorVar), args.fOutputColor,
                args.fUniformHandler->getUniformCStr(fRightBorderColorVar));
        SkString _input0("t");
        SkString _child0("_child0");
        this->emitChild(0, _input0.c_str(), &_child0, args);
        fragBuilder->codeAppendf("\n    %s = %s;\n}\n@if (%s) {\n    %s.xyz *= %s.w;\n}\n",
                                 args.fOutputColor, _child0.c_str(),
                                 (_outer.makePremul() ? "true" : "false"), args.fOutputColor,
                                 args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {
        const GrClampedGradientEffect& _outer = _proc.cast<GrClampedGradientEffect>();
        {
            const SkPMColor4f& leftBorderColorValue = _outer.leftBorderColor();
            if (fLeftBorderColorPrev != leftBorderColorValue) {
                fLeftBorderColorPrev = leftBorderColorValue;
                pdman.set4fv(fLeftBorderColorVar, 1, leftBorderColorValue.vec());
            }
            const SkPMColor4f& rightBorderColorValue = _outer.rightBorderColor();
            if (fRightBorderColorPrev != rightBorderColorValue) {
                fRightBorderColorPrev = rightBorderColorValue;
                pdman.set4fv(fRightBorderColorVar, 1, rightBorderColorValue.vec());
            }
        }
    }
    SkPMColor4f fLeftBorderColorPrev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    SkPMColor4f fRightBorderColorPrev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    UniformHandle fLeftBorderColorVar;
    UniformHandle fRightBorderColorVar;
};
GrGLSLFragmentProcessor* GrClampedGradientEffect::onCreateGLSLInstance() const {
    return new GrGLSLClampedGradientEffect();
}
void GrClampedGradientEffect::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                    GrProcessorKeyBuilder* b) const {
    b->add32((int32_t)fMakePremul);
}
bool GrClampedGradientEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrClampedGradientEffect& that = other.cast<GrClampedGradientEffect>();
    (void)that;
    if (fLeftBorderColor != that.fLeftBorderColor) return false;
    if (fRightBorderColor != that.fRightBorderColor) return false;
    if (fMakePremul != that.fMakePremul) return false;
    if (fColorsAreOpaque != that.fColorsAreOpaque) return false;
    return true;
}
GrClampedGradientEffect::GrClampedGradientEffect(const GrClampedGradientEffect& src)
        : INHERITED(kGrClampedGradientEffect_ClassID, src.optimizationFlags())
        , fLeftBorderColor(src.fLeftBorderColor)
        , fRightBorderColor(src.fRightBorderColor)
        , fMakePremul(src.fMakePremul)
        , fColorsAreOpaque(src.fColorsAreOpaque) {
    this->registerChildProcessor(src.childProcessor(0).clone());
    this->registerChildProcessor(src.childProcessor(1).clone());
}
std::unique_ptr<GrFragmentProcessor> GrClampedGradientEffect::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrClampedGradientEffect(*this));
}
