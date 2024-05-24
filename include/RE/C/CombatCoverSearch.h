#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/C/CombatCoverSearchData.h"
#include "RE/C/CombatObject.h"

namespace RE
{
	class CombatCoverSearchResult;

	class CombatCoverSearch : public CombatObject
	{
	public:
		~CombatCoverSearch() override;  // 00

		// override (CombatObject)
		uint32_t GetObjectType() override;                     // 02
		void     SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void     LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		void ClearSearchResult();
		void SetCoverLocation(const NiPointer<class CombatCoverLocation>& loc);
		void StartedSearch();

		// members
		CombatCoverSearchData    searchData;    // 10
		CombatCoverSearchResult* searchResult;  // 68
		uint32_t                 unk70;         // 70
		NiPoint3                 mb_actorPos;   // 74
		mutable BSReadWriteLock  resultLock;    // 30
	};
	static_assert(sizeof(CombatCoverSearch) == 0x88);
}
