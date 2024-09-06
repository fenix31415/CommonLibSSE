#pragma once

namespace RE
{
	class NiAnimationKey
	{
	public:
		enum class KeyContent : uint32_t
		{
			kFloat,
			kPos,
			kRot,
			kColor,
			kText,
			kBool,

			kTotal
		};

		enum class KeyType : uint32_t
		{
			kNoInterp,
			kLin,
			kBez,
			kTCB,
			kEuler,
			kStrip,

			kTotal
		};

		NiAnimationKey();
		NiAnimationKey(float a_time);
		~NiAnimationKey();

		static bool Equal(const NiAnimationKey& a, const NiAnimationKey& b);
		static NiAnimationKey* (*GetArrayFunction(KeyContent content, KeyType type))(uint32_t size);
		static void (*GetDeleteFunction(KeyContent content, KeyType type))(NiAnimationKey*);
		static bool (*GetEqualFunction(KeyContent content, KeyType type))(const NiAnimationKey& a, const NiAnimationKey& b);
		static void (*GetFillDerivedFunction(KeyContent content, KeyType type))(NiAnimationKey*, uint32_t numKeys, uint8_t keySize);
		static uint8_t GetKeySize(KeyContent content, KeyType type);
		static void    GuaranteeKeyAtStartAndEnd(KeyContent content, KeyType type, NiAnimationKey*& keys, uint32_t& numKeys, float start, float end);

		[[nodiscard]] float           GetTime() const;
		void                          SetTime(float a_time);
		[[nodiscard]] NiAnimationKey* GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize) const;

	protected:
		// members
		float _time;  // 00

	private:
		using ms_keysizes_t = std::array<std::array<uint8_t, static_cast<uint32_t>(KeyType::kTotal)>, static_cast<uint32_t>(KeyContent::kTotal)>;
		static const ms_keysizes_t& ms_keysizes();

		using deleter_t = void (*)(NiAnimationKey*);
		using ms_deletes_t = std::array<std::array<deleter_t, static_cast<uint32_t>(KeyType::kTotal)>, static_cast<uint32_t>(KeyContent::kTotal)>;
		static const ms_deletes_t& ms_deletes();

		using equals_t = bool (*)(const NiAnimationKey&, const NiAnimationKey&);
		using ms_equals_t = std::array<std::array<equals_t, static_cast<uint32_t>(KeyType::kTotal)>, static_cast<uint32_t>(KeyContent::kTotal)>;
		static const ms_equals_t& ms_equals();

		using arrays_t = NiAnimationKey* (*)(uint32_t size);
		using ms_arrays_t = std::array<std::array<arrays_t, static_cast<uint32_t>(KeyType::kTotal)>, static_cast<uint32_t>(KeyContent::kTotal)>;
		static const ms_arrays_t& ms_arrays();

		using fillderived_t = void (*)(NiAnimationKey*, uint32_t numKeys, uint8_t keySize);
		using ms_fillderived_t = std::array<std::array<fillderived_t, static_cast<uint32_t>(KeyType::kTotal)>, static_cast<uint32_t>(KeyContent::kTotal)>;
		static const ms_fillderived_t& ms_fillderived();
	};
	static_assert(sizeof(NiAnimationKey) == 0x4);
}
