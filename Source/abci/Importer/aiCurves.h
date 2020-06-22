#pragma once
#include "pch.h"
#include "aiInternal.h"
#include "aiContext.h"
#include "aiObject.h"
#include "aiSchema.h"

class aiCurves;

class aiCurvesSample : public aiSample
{
    using super = aiSample;
public:
    aiCurvesSample(aiCurves *schema);
    void getSummary(aiCurvesSampleSummary &dst);

    ~aiCurvesSample(){}
    // void fillData(aiPointsData &dst);
    // void getSummary(aiPointsSampleSummary &dst);
    Abc::P3fArraySamplePtr m_position_sp/*, m_position_sp2*/;
    Abc::Int32ArraySamplePtr m_numVertices_sp;

    RawVector<abcV3> m_positions;
    RawVector<int32_t> m_numVertices;
    //IArray<abcV3> m_positions_ref;

    void fillData(aiCurvesData& data);
};

struct aiCurvesTraits
{
    using SampleT = aiCurvesSample;
    using AbcSchemaT = AbcGeom::ICurvesSchema;
};

class aiCurves : public aiTSchema<aiCurvesTraits>
{
    using super = aiTSchema<aiCurvesTraits>;
public:
    aiCurves(aiObject *parent, const abcObject &abc);
    ~aiCurves() override {};

    Sample* newSample() override;
    void readSampleBody(Sample& sample, uint64_t idx) override;
    void cookSampleBody(Sample& sample) override;
    const aiCurvesSummary& getSummary() const {return m_summary;}
private:
    void updateSummary();
    aiCurvesSummary m_summary;
};
