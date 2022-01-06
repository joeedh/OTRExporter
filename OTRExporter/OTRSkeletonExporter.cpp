#include "OTRSkeletonExporter.h"
#include <OTRResource.h>

void OTRExporter_Skeleton::Save(ZResource* res, fs::path outPath, BinaryWriter* writer)
{
	ZSkeleton* skel = (ZSkeleton*)res;

	WriteHeader(res, outPath, writer, OtrLib::ResourceType::OTRSkeleton);

	writer->Write((uint8_t)skel->type);
	writer->Write((uint8_t)skel->limbType);

	writer->Write((uint32_t)skel->limbCount);
	writer->Write((uint32_t)skel->dListCount);

	writer->Write((uint8_t)skel->limbsTable.limbType);
	writer->Write((uint32_t)skel->limbsTable.count);

	for (int i = 0; i < skel->limbsTable.count; i++)
	{
		Declaration* skelDecl = skel->parent->GetDeclarationRanged(GETSEGOFFSET(skel->limbsTable.limbsAddresses[i]));

		if (skelDecl != nullptr)
		{
			std::string fName = StringHelper::Sprintf("%s\\%s", skel->parent->GetOutName().c_str(), skelDecl->varName.c_str());
			writer->Write(fName);
		}
		else
		{
			writer->Write("");
		}
	}
}
