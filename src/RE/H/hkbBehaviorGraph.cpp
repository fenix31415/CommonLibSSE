#include "RE/H/hkbBehaviorGraph.h"

namespace RE
{
	hkbNode* hkbBehaviorGraph::getNodeClone(hkbNode* nodeTemplate) const
	{
		if (nodeTemplate->cloneState == RE::hkbNode::CloneState::kClone || !nodeTemplateToCloneMap)
			return nodeTemplate;

		hkbNode* ans = (hkbNode*)nodeTemplateToCloneMap->getWithDefault((uint64_t)nodeTemplate, 0);

		return ans ? ans : nodeTemplate;
	}

	hkbNode* hkbBehaviorGraph::getNodeTemplate(hkbNode* nodeClone) const
	{
		if (nodeClone->cloneState == RE::hkbNode::CloneState::kClone && nodeCloneToTemplateMap)
			return (hkbNode*)nodeCloneToTemplateMap->getWithDefault((uint64_t)nodeClone, 0);
		else
			return nodeClone;
	}
}
