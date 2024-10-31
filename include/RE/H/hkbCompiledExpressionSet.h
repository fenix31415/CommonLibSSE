#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkbCompiledExpressionSet : public hkReferencedObject
	{
	public:
		/// A Token is either an operator, number or variable index. A list of Tokens is used as our Reverse Polish Notation (RPN).
		struct Token
		{
			/// Designates the token type: operator, number, or variable index.
			enum class TokenType : int8_t
			{
				TOKEN_TYPE_NONE,
				TOKEN_TYPE_OPERATOR,
				TOKEN_TYPE_NUMBER,
				TOKEN_TYPE_VARIABLE_INDEX,
				TOKEN_TYPE_OPENING_PAREN,
				TOKEN_TYPE_CLOSING_PAREN,
				TOKEN_TYPE_COMMA,
				TOKEN_TYPE_CHARACTER_PROPERTY_INDEX,
			};

			/// The operators allowed in expressions.
			/// New operators should be appended at the end for proper versioning
			enum class Operator : int8_t
			{
				OP_NOP,  // nothing

				OP_RAND01,

				OP_LOGICAL_NOT,  // "!"
				OP_UNARY_MINUS,  // "-"
				OP_UNARY_PLUS,   // "+"
				OP_SIN,
				OP_COS,
				OP_ASIN,
				OP_ACOS,
				OP_SQRT,
				OP_FABS,
				OP_CEIL,
				OP_FLOOR,
				OP_SQRTINV,

				OP_MUL,          // "*"
				OP_DIV,          // "/"
				OP_ADD,          // "+"
				OP_SUB,          // "-"
				OP_LOGICAL_OR,   // "||"
				OP_LOGICAL_AND,  // "&&"
				OP_EQ,           // "=="
				OP_NEQ,          // "!="
				OP_LT,           // "<"
				OP_GT,           // ">"
				OP_LEQ,          // "<="
				OP_GEQ,          // ">="
				OP_POW,
				OP_MAX2,
				OP_MIN2,
				OP_RANDRANGE,
				OP_ATAN2APPROX,

				OP_CLAMP,

				OP_MOD,  // "%"

				OP_DEG2RAD,
				OP_RAD2DEG,
				OP_COSD,
				OP_SIND,
				OP_ACOSD,
				OP_ASIND,
				OP_ATAN2APPROXD,

				OP_SIGN,
				OP_LERP,
				OP_CLERP,
				OP_COND
			};

			// members
			float     data;        // 00 - Contains either a number or variable index.
			TokenType type;        // 04 - Contains the type of the token.
			Operator  m_operator;  // 05 - Contains an operator.
			char      pad6[2];     // 06
		};

		struct FunctionOpStruct
		{
			const char*     functionName;
			Token::Operator m_operator;
		};

		static constexpr uint32_t                                   functionOpCount = 27;
		static inline std::array<FunctionOpStruct, functionOpCount> functionOps = { { { "rand01", Token::Operator::OP_RAND01 },
			{ "sind", Token::Operator::OP_SIND }, { "sin", Token::Operator::OP_SIN }, { "cosd", Token::Operator::OP_COSD },
			{ "cos", Token::Operator::OP_COS }, { "asind", Token::Operator::OP_ASIND }, { "asin", Token::Operator::OP_ASIN },
			{ "acosd", Token::Operator::OP_ACOSD }, { "acos", Token::Operator::OP_ACOS }, { "sqrt", Token::Operator::OP_SQRT },
			{ "fabs", Token::Operator::OP_FABS }, { "ceil", Token::Operator::OP_CEIL }, { "floor", Token::Operator::OP_FLOOR },
			{ "sqrtInverse", Token::Operator::OP_SQRTINV }, { "pow", Token::Operator::OP_POW }, { "max", Token::Operator::OP_MAX2 },
			{ "min", Token::Operator::OP_MIN2 }, { "randRange", Token::Operator::OP_RANDRANGE },
			{ "atan2d", Token::Operator::OP_ATAN2APPROXD }, { "atan2", Token::Operator::OP_ATAN2APPROX },
			{ "deg2rad", Token::Operator::OP_DEG2RAD }, { "rad2deg", Token::Operator::OP_RAD2DEG },
			{ "clamp", Token::Operator::OP_CLAMP }, { "sign", Token::Operator::OP_SIGN }, { "lerp", Token::Operator::OP_LERP },
			{ "clerp", Token::Operator::OP_CLERP }, { "cond", Token::Operator::OP_COND } } };

		static bool isTokenFunction(Token::Operator op)
		{
			switch (op) {
			case hkbCompiledExpressionSet::Token::Operator::OP_NOP:

			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_NOT:
			case hkbCompiledExpressionSet::Token::Operator::OP_UNARY_MINUS:
			case hkbCompiledExpressionSet::Token::Operator::OP_UNARY_PLUS:

			case hkbCompiledExpressionSet::Token::Operator::OP_MUL:
			case hkbCompiledExpressionSet::Token::Operator::OP_DIV:
			case hkbCompiledExpressionSet::Token::Operator::OP_ADD:
			case hkbCompiledExpressionSet::Token::Operator::OP_SUB:
			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_OR:
			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_AND:
			case hkbCompiledExpressionSet::Token::Operator::OP_EQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_NEQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_LT:
			case hkbCompiledExpressionSet::Token::Operator::OP_GT:
			case hkbCompiledExpressionSet::Token::Operator::OP_LEQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_GEQ:

			case hkbCompiledExpressionSet::Token::Operator::OP_MOD:
				return false;

			case hkbCompiledExpressionSet::Token::Operator::OP_RAND01:

			case hkbCompiledExpressionSet::Token::Operator::OP_SIN:
			case hkbCompiledExpressionSet::Token::Operator::OP_COS:
			case hkbCompiledExpressionSet::Token::Operator::OP_ASIN:
			case hkbCompiledExpressionSet::Token::Operator::OP_ACOS:
			case hkbCompiledExpressionSet::Token::Operator::OP_SQRT:
			case hkbCompiledExpressionSet::Token::Operator::OP_FABS:
			case hkbCompiledExpressionSet::Token::Operator::OP_CEIL:
			case hkbCompiledExpressionSet::Token::Operator::OP_FLOOR:
			case hkbCompiledExpressionSet::Token::Operator::OP_SQRTINV:

			case hkbCompiledExpressionSet::Token::Operator::OP_POW:
			case hkbCompiledExpressionSet::Token::Operator::OP_MAX2:
			case hkbCompiledExpressionSet::Token::Operator::OP_MIN2:
			case hkbCompiledExpressionSet::Token::Operator::OP_RANDRANGE:
			case hkbCompiledExpressionSet::Token::Operator::OP_ATAN2APPROX:
			case hkbCompiledExpressionSet::Token::Operator::OP_CLAMP:

			case hkbCompiledExpressionSet::Token::Operator::OP_DEG2RAD:
			case hkbCompiledExpressionSet::Token::Operator::OP_RAD2DEG:
			case hkbCompiledExpressionSet::Token::Operator::OP_COSD:
			case hkbCompiledExpressionSet::Token::Operator::OP_SIND:
			case hkbCompiledExpressionSet::Token::Operator::OP_ACOSD:
			case hkbCompiledExpressionSet::Token::Operator::OP_ASIND:
			case hkbCompiledExpressionSet::Token::Operator::OP_ATAN2APPROXD:
			case hkbCompiledExpressionSet::Token::Operator::OP_SIGN:

			case hkbCompiledExpressionSet::Token::Operator::OP_LERP:
			case hkbCompiledExpressionSet::Token::Operator::OP_CLERP:
			case hkbCompiledExpressionSet::Token::Operator::OP_COND:
				return true;

			default:
				return false;
			}
		}

		static int32_t getOperatorArgumentCount(Token::Operator op)
		{
			switch (op) {
			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_NOT:
			case hkbCompiledExpressionSet::Token::Operator::OP_UNARY_MINUS:
			case hkbCompiledExpressionSet::Token::Operator::OP_UNARY_PLUS:
				return 1;
			case hkbCompiledExpressionSet::Token::Operator::OP_MUL:
			case hkbCompiledExpressionSet::Token::Operator::OP_DIV:
			case hkbCompiledExpressionSet::Token::Operator::OP_ADD:
			case hkbCompiledExpressionSet::Token::Operator::OP_SUB:
			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_OR:
			case hkbCompiledExpressionSet::Token::Operator::OP_LOGICAL_AND:
			case hkbCompiledExpressionSet::Token::Operator::OP_EQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_NEQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_LT:
			case hkbCompiledExpressionSet::Token::Operator::OP_GT:
			case hkbCompiledExpressionSet::Token::Operator::OP_LEQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_GEQ:
			case hkbCompiledExpressionSet::Token::Operator::OP_MOD:
				return 2;
			default:
				return -1;
			}
		}

		static int32_t getFunctionArgumentCount(Token::Operator op)
		{
			switch (op) {
			case Token::Operator::OP_RAND01:
				return 0;
			case Token::Operator::OP_SIN:
			case Token::Operator::OP_COS:
			case Token::Operator::OP_ASIN:
			case Token::Operator::OP_ACOS:
			case Token::Operator::OP_SQRT:
			case Token::Operator::OP_FABS:
			case Token::Operator::OP_CEIL:
			case Token::Operator::OP_FLOOR:
			case Token::Operator::OP_SQRTINV:
			case Token::Operator::OP_DEG2RAD:
			case Token::Operator::OP_RAD2DEG:
			case Token::Operator::OP_COSD:
			case Token::Operator::OP_SIND:
			case Token::Operator::OP_ACOSD:
			case Token::Operator::OP_ASIND:
			case Token::Operator::OP_SIGN:
				return 1;
			case Token::Operator::OP_POW:
			case Token::Operator::OP_MAX2:
			case Token::Operator::OP_MIN2:
			case Token::Operator::OP_RANDRANGE:
			case Token::Operator::OP_ATAN2APPROX:
			case Token::Operator::OP_ATAN2APPROXD:
				return 2;
			case Token::Operator::OP_CLAMP:
			case Token::Operator::OP_LERP:
			case Token::Operator::OP_COND:
				return 3;
			case Token::Operator::OP_CLERP:
				return 5;
			default:
				return -1;
			}
		}

		static int32_t getPrecedence(Token::Operator op)
		{
			switch (op) {
			case Token::Operator::OP_RAND01:
			case Token::Operator::OP_SIN:
			case Token::Operator::OP_COS:
			case Token::Operator::OP_ASIN:
			case Token::Operator::OP_ACOS:
			case Token::Operator::OP_SQRT:
			case Token::Operator::OP_FABS:
			case Token::Operator::OP_CEIL:
			case Token::Operator::OP_FLOOR:
			case Token::Operator::OP_SQRTINV:
			case Token::Operator::OP_POW:
			case Token::Operator::OP_MAX2:
			case Token::Operator::OP_MIN2:
			case Token::Operator::OP_RANDRANGE:
			case Token::Operator::OP_ATAN2APPROX:
			case Token::Operator::OP_CLAMP:
			case Token::Operator::OP_DEG2RAD:
			case Token::Operator::OP_RAD2DEG:
			case Token::Operator::OP_COSD:
			case Token::Operator::OP_SIND:
			case Token::Operator::OP_ACOSD:
			case Token::Operator::OP_ASIND:
			case Token::Operator::OP_ATAN2APPROXD:
			case Token::Operator::OP_SIGN:
			case Token::Operator::OP_LERP:
			case Token::Operator::OP_CLERP:
			case Token::Operator::OP_COND:
				return 6;
			case Token::Operator::OP_LOGICAL_NOT:
			case Token::Operator::OP_UNARY_MINUS:
			case Token::Operator::OP_UNARY_PLUS:
				return 5;
			case Token::Operator::OP_MUL:
			case Token::Operator::OP_DIV:
			case Token::Operator::OP_MOD:
				return 4;
			case Token::Operator::OP_ADD:
			case Token::Operator::OP_SUB:
				return 3;
			case Token::Operator::OP_LOGICAL_OR:
			case Token::Operator::OP_LOGICAL_AND:
				return 2;
			case Token::Operator::OP_EQ:
			case Token::Operator::OP_NEQ:
			case Token::Operator::OP_LT:
			case Token::Operator::OP_GT:
			case Token::Operator::OP_LEQ:
			case Token::Operator::OP_GEQ:
				return 1;
			default:
				return -1;
			}
		}

		// members
		hkArray<Token> rpn;  // 10 - reverse polish notation structure (list of token)
		// 20 - the indices of the start of each expression in the m_rpn.
		// if the startIndex is -1 or the start index of an expression is the same as the end index of an expression
		// then the expression is invalid.
		hkArray<int32_t> expressionToRpnIndex;
		uint8_t              numExpressions;  // 30 - number of expressions
		char                 pad31[7];        // 31
	};
	static_assert(sizeof(hkbCompiledExpressionSet) == 0x38);
}
