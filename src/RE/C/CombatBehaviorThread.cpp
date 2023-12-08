#include "RE/C/CombatBehaviorThread.h"

namespace RE
{
	CombatBehaviorThread::CombatBehaviorThread(CombatBehaviorController* parent_control, CombatBehaviorThread* parent_thread)
	{
		using func_t = CombatBehaviorThread*(CombatBehaviorThread*, CombatBehaviorController*, CombatBehaviorThread*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46226, 0) };  // I do not know for AE
		func(this, parent_control, parent_thread);
	}

	CombatBehaviorThread::~CombatBehaviorThread()
	{
		using func_t = void(CombatBehaviorThread*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46227, 0) };  // I do not know for AE
		func(this);
	}

	void CombatBehaviorThread::Abort()
	{
		using func_t = decltype(&CombatBehaviorThread::Abort);
		REL::Relocation<func_t> func{ RELOCATION_ID(46237, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::AddChildThread(CombatBehaviorThread* thread)
	{
		using func_t = decltype(&CombatBehaviorThread::AddChildThread);
		REL::Relocation<func_t> func{ RELOCATION_ID(46251, 0) };  // I do not know for AE
		return func(this, thread);
	}

	void CombatBehaviorThread::Ascend()
	{
		using func_t = void(CombatBehaviorThread*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46229, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Ascend(CombatBehaviorTreeNode* node)
	{
		using func_t = void(CombatBehaviorThread*, CombatBehaviorTreeNode * node);
		REL::Relocation<func_t> func{ RELOCATION_ID(529915, 0) };  // I do not know for AE
		return func(this, node);
	}

	bool CombatBehaviorThread::CheckRelated(CombatBehaviorThread* other) const
	{
		using func_t = decltype(&CombatBehaviorThread::CheckRelated);
		REL::Relocation<func_t> func{ RELOCATION_ID(46235, 0) };  // I do not know for AE
		return func(this, other);
	}

	bool CombatBehaviorThread::CheckParent(CombatBehaviorThread* is_parent) const
	{
		using func_t = decltype(&CombatBehaviorThread::CheckParent);
		REL::Relocation<func_t> func{ RELOCATION_ID(46234, 0) };  // I do not know for AE
		return func(this, is_parent);
	}

	void CombatBehaviorThread::Descend(uint32_t ind)
	{
		using func_t = void(CombatBehaviorThread*, uint32_t);
		REL::Relocation<func_t> func{ RELOCATION_ID(46230, 0) };  // I do not know for AE
		return func(this, ind);
	}

	void CombatBehaviorThread::Descend(CombatBehaviorTreeNode* node)
	{
		using func_t = void(CombatBehaviorThread*, CombatBehaviorTreeNode*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46231, 0) };  // I do not know for AE
		return func(this, node);
	}

	bool CombatBehaviorThread::GetAscendingUpdate() const
	{
		using func_t = decltype(&CombatBehaviorThread::GetAscendingUpdate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46233, 0) };  // I do not know for AE
		return func(this);
	}

	uint32_t CombatBehaviorThread::GetChildIndex() const
	{
		using func_t = decltype(&CombatBehaviorThread::GetChildIndex);
		REL::Relocation<func_t> func{ RELOCATION_ID(46531, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorThread::GetInitialUpdate() const
	{
		using func_t = decltype(&CombatBehaviorThread::GetInitialUpdate);
		REL::Relocation<func_t> func{ RELOCATION_ID(46232, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Pause()
	{
		flags.set(Flags::kPaused);
	}

	void CombatBehaviorThread::Resume()
	{
		using func_t = decltype(&CombatBehaviorThread::Resume);
		REL::Relocation<func_t> func{ RELOCATION_ID(46236, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::SetAborted()
	{
		using func_t = decltype(&CombatBehaviorThread::SetAborted);
		REL::Relocation<func_t> func{ RELOCATION_ID(46243, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::SetFailed(bool failed)
	{
		using func_t = decltype(&CombatBehaviorThread::SetFailed);
		REL::Relocation<func_t> func{ RELOCATION_ID(46240, 0) };  // I do not know for AE
		return func(this, failed);
	}

	void CombatBehaviorThread::Unpause()
	{
		flags.reset(Flags::kPaused);
	}

	void CombatBehaviorThread::Suspend()
	{
		using func_t = decltype(&CombatBehaviorThread::Suspend);
		REL::Relocation<func_t> func{ RELOCATION_ID(46238, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Update()
	{
		using func_t = decltype(&CombatBehaviorThread::Update);
		REL::Relocation<func_t> func{ RELOCATION_ID(46228, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Unsuspend()
	{
		using func_t = decltype(&CombatBehaviorThread::Unsuspend);
		REL::Relocation<func_t> func{ RELOCATION_ID(46239, 0) };  // I do not know for AE
		return func(this);
	}
}
