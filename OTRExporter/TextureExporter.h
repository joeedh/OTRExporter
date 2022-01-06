#pragma once

#include "ZResource.h"
#include "ZTexture.h"
#include "OTRExporter.h"
#include <Utils/BinaryWriter.h>

class OTRExporter_Texture : public OTRExporter
{
public:
	virtual void Save(ZResource* res, const fs::path outPath, BinaryWriter* writer) override;
};