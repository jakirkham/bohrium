#include <sstream>
#include <string>
#include "codegen.hpp"
//
//  NOTE: This file is autogenerated based on the tac-definition.
//        You should therefore not edit it manually.
//
using namespace std;
using namespace bohrium::core;

namespace bohrium{
namespace engine{
namespace cpu{
namespace codegen{

string Walker::oper_description(tac_t tac)
{
    stringstream ss;
    ss << operator_text(tac.oper) << " (";
    switch(core::tac_noperands(tac)) {
        case 3:
            ss << layout_text(kernel_.operands_[tac.out].operand_->layout);
            ss << ", ";
            ss << layout_text(kernel_.operands_[tac.in1].operand_->layout);
            ss << ", ";
            ss << layout_text(kernel_.operands_[tac.in2].operand_->layout);
            break;
        case 2:
            ss << layout_text(kernel_.operands_[tac.out].operand_->layout);
            ss << ", ";
            ss << layout_text(kernel_.operands_[tac.in1].operand_->layout);
            break;
        case 1:
            ss << layout_text(kernel_.operands_[tac.out].operand_->layout);
            break;
        default:
            break;
    }
    ss << ")";
    return ss.str();
}

string Walker::oper(tac_t tac)
{
    ETYPE etype = kernel_.operands_[tac.out].operand_->etype;
    
    Operand in1, in2;

    switch(core::tac_noperands(tac)) {
        case 3:
            in2 = kernel_.operands_[tac.in2];
        case 2:
            in1 = kernel_.operands_[tac.in1];
        default:
            break;
    }

    switch(tac.oper) {
        case ABSOLUTE:              return _abs(in1.walker_val(), in2.walker_val());
        case ADD:                   return _add(in1.walker_val(), in2.walker_val());
        case ARCCOS:            
            switch(etype) {
                case COMPLEX128:    return _cacos(in1.walker_val());
                case COMPLEX64:     return _cacosf(in1.walker_val());
                default:            return _acos(in1.walker_val());
            }
        case ARCCOSH:
            switch(etype) {
                case COMPLEX128:    return _cacosh(in1.walker_val());
                case COMPLEX64:     return _cacosf(in1.walker_val());
                default:            return _acos(in1.walker_val());
            }
        case ARCSIN:
            switch(etype) {
                case COMPLEX128:    return _casin(in1.walker_val());
                case COMPLEX64:     return _casinf(in1.walker_val());
                default:            return _asin(in1.walker_val());
            }
        case ARCSINH:
            switch(etype) {
                case COMPLEX128:    return _casinh(in1.walker_val());
                case COMPLEX64:     return _casinhf(in1.walker_val());
                default:            return _asinh(in1.walker_val());
            }
        case ARCTAN:
            switch(etype) {
                case COMPLEX128:    return _catan(in1.walker_val());
                case COMPLEX64:     return _catanf(in1.walker_val());
                default:            return _atan(in1.walker_val());
            }
        case ARCTAN2:               return _atan2(in1.walker_val(), in2.walker_val());
        case ARCTANH:
            switch(etype) {
                case COMPLEX128:    return _catanh(in1.walker_val());
                case COMPLEX64:     return _catanhf(in1.walker_val());
                default:            return _atanh(in1.walker_val());
            }
        case BITWISE_AND:           return _bitw_and(in1.walker_val(), in2.walker_val());
        case BITWISE_OR:            return _bitw_or(in1.walker_val(), in2.walker_val());
        case BITWISE_XOR:           return _bitw_xor(in1.walker_val(), in2.walker_val());
        case CEIL:                  return _ceil(in1.walker_val());
        case COS:
            switch(etype) {
                case COMPLEX128:    return _ccos(in1.walker_val());
                case COMPLEX64:     return _ccosf(in1.walker_val());
                default:            return _cos(in1.walker_val());
            }
        case COSH:
            switch(etype) {
                case COMPLEX128:    return _ccosh(in1.walker_val());
                case COMPLEX64:     return _ccoshf(in1.walker_val());
                default:            return _cosh(in1.walker_val());
            }
        case DISCARD:               break;  // TODO: Raise exception
        case DIVIDE:                return _div(in1.walker_val(), in2.walker_val());
        case EQUAL:                 return _eq(in1.walker_val(), in2.walker_val());
        case EXP:
            switch(etype) {
                case COMPLEX128:    return _cexp(in1.walker_val());
                case COMPLEX64:     return _cexpf(in1.walker_val());
                default:            return _exp(in1.walker_val());
            }
        case EXP2:
            switch(etype) {
                case COMPLEX128:    return _cexp2(in1.walker_val());
                case COMPLEX64:     return _cexp2f(in1.walker_val());
                default:            return _exp2(in1.walker_val());
            }
        case EXPM1:                 return _expm1(in1.walker_val());
        case EXTENSION_OPERATOR:    break;  // TODO: Raise exception
        case FLOOD:                 break;  // TODO: Raise exception
        case FLOOR:                 return _floor(in1.walker_val());
        case FREE:                  break;  // TODO: Raise exception
        case GREATER:               return _gt(in1.walker_val(), in2.walker_val());
        case GREATER_EQUAL:         return _gteq(in1.walker_val(), in2.walker_val());
        case IDENTITY:              return in1.walker_val();
        case IMAG:
            switch(etype) {
                case FLOAT32:       return _cimagf(in1.walker_val());
                default:            return _cimag(in1.walker_val());
            }
        case INVERT:
            switch(etype) {
                case BOOL:          return _invertb(in1.walker_val());
                default:            return _invert(in1.walker_val());
            }
        case ISINF:                 return _isinf(in1.walker_val());
        case ISNAN:                 return _isnan(in1.walker_val());
        case LEFT_SHIFT:            return _bitw_leftshift(in1.walker_val(), in2.walker_val());
        case LESS:                  return _lt(in1.walker_val(), in2.walker_val());
        case LESS_EQUAL:            return _lteq(in1.walker_val(), in2.walker_val());
        case LOG:
            switch(etype) {
                case COMPLEX128:    return _clog(in1.walker_val());
                case COMPLEX64:     return _clogf(in1.walker_val());
                default:            return _log(in1.walker_val());
            }
        case LOG10:
            switch(etype) {
                case COMPLEX128:    return _clog10(in1.walker_val());
                case COMPLEX64:     return _clog10f(in1.walker_val());
                default:            return _log10(in1.walker_val());
            }
        case LOG1P:                 return _log1p(in1.walker_val());
        case LOG2:                  return _log2(in1.walker_val());
        case LOGICAL_AND:           return _logic_and(in1.walker_val(), in2.walker_val());
        case LOGICAL_NOT:           return _logic_not(in1.walker_val());
        case LOGICAL_OR:            return _logic_or(in1.walker_val(), in2.walker_val());
        case LOGICAL_XOR:           return _logic_xor(in1.walker_val(), in2.walker_val());
        case MAXIMUM:               return _max(in1.walker_val(), in2.walker_val());
        case MINIMUM:               return _min(in1.walker_val(), in2.walker_val());
        case MOD:                   return _mod(in1.walker_val(), in2.walker_val());
        case MULTIPLY:              return _mul(in1.walker_val(), in2.walker_val());
        case NONE:                  break;  // TODO: Raise exception
        case NOT_EQUAL:             return _neq(in1.walker_val(), in2.walker_val());
        case POWER:
            switch(etype) {
                case COMPLEX128:    return _cpow(in1.walker_val(), in2.walker_val());
                case COMPLEX64:     return _cpowf(in1.walker_val(), in2.walker_val());
                default:            return _pow(in1.walker_val(), in2.walker_val());
            }
        case RANDOM:                return _random(in1.walker_val(), in2.walker_val());
        case RANGE:                 return _range();
        case REAL:
            switch(etype) {
                case FLOAT32:       return _crealf(in1.walker_val());
                default:            return _creal(in1.walker_val());
            }
        case RIGHT_SHIFT:           return _bitw_rightshift(in1.walker_val(), in2.walker_val());
        case RINT:                  return _rint(in1.walker_val());
        case SIN:
            switch(etype) {
                case COMPLEX128:    return _csin(in1.walker_val());
                case COMPLEX64:     return _csinf(in1.walker_val());
                default:            return _sin(in1.walker_val());
            }
        case SINH:
            switch(etype) {
                case COMPLEX128:    return _csinh(in1.walker_val());
                case COMPLEX64:     return _csinhf(in1.walker_val());
                default:            return _sinh(in1.walker_val());
            }
        case SQRT:
            switch(etype) {
                case COMPLEX128:    return _csqrt(in1.walker_val());
                case COMPLEX64:     return _csqrtf(in1.walker_val());
                default:            return _sqrt(in1.walker_val());
            }
        case SYNC:                  break;  // TODO: Raise exception
        case TAN:
            switch(etype) {
                case COMPLEX128:    return _ctan(in1.walker_val());
                case COMPLEX64:     return _ctanf(in1.walker_val());
                default:            return _tan(in1.walker_val());
            }
        case TANH:
            switch(etype) {
                case COMPLEX128:    return _ctanh(in1.walker_val());
                case COMPLEX64:     return _ctanhf(in1.walker_val());
                default:            return _tanh(in1.walker_val());
            }
        case TRUNC:                 return _trunc(in1.walker_val());

        default:
            return "NOT_IMPLEMENTED_YET";
            break;
    }
    return "THIS SHOULD NEVER HAPPEN";
}

}}}}
