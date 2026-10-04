
char * FUN_004e0a5f(uint param_1)

{
  HMODULE lpSource;
  DWORD dwLanguageId;
  LPSTR lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  
  if (param_1 < 0xc000008e) {
    if (param_1 == 0xc000008d) {
      return s_FLT_DENORMAL_OPERAND_006c9488;
    }
    if (param_1 < 0xc0000007) {
      if (param_1 == 0xc0000006) {
        return s_IN_PAGE_ERROR_006c950c;
      }
      if (param_1 == 0x80000001) {
        return s_GUARD_PAGE_006c951c;
      }
      if (param_1 == 0x80000002) {
        return s_DATATYPE_MISALIGNMENT_006c9528;
      }
      if (param_1 == 0x80000003) {
        return s_BREAKPOINT_006c9540;
      }
      if (param_1 == 0x80000004) {
        return s_SINGLE_STEP_006c954c;
      }
      if (param_1 == 0xc0000005) {
        return s_ACCESS_VIOLATION_006c9558;
      }
    }
    else {
      if (param_1 == 0xc0000008) {
        return s_INVALID_HANDLE_006c94a0;
      }
      if (param_1 == 0xc000001d) {
        return s_ILLEGAL_INSTRUCTION_006c94b0;
      }
      if (param_1 == 0xc0000025) {
        return s_NONCONTINUABLE_EXCEPTION_006c94c4;
      }
      if (param_1 == 0xc0000026) {
        return s_INVALID_DISPOSITION_006c94e0;
      }
      if (param_1 == 0xc000008c) {
        return s_ARRAY_BOUNDS_EXCEEDED_006c94f4;
      }
    }
  }
  else if (param_1 < 0xc00000fe) {
    if (param_1 == 0xc00000fd) {
      return s_STACK_OVERFLOW_006c93d0;
    }
    switch(param_1) {
    case 0xc000008e:
      return s_FLT_DIVIDE_BY_ZERO_006c9474;
    case 0xc000008f:
      return s_FLT_INEXACT_RESULT_006c9460;
    case 0xc0000090:
      return s_FLT_INVALID_OPERATION_006c9448;
    case 0xc0000091:
      return s_FLT_OVERFLOW_006c9438;
    case 0xc0000092:
      return s_FLT_STACK_CHECK_006c9428;
    case 0xc0000093:
      return s_FLT_UNDERFLOW_006c9418;
    case 0xc0000094:
      return s_INT_DIVIDE_BY_ZERO_006c9404;
    case 0xc0000095:
      return s_INT_OVERFLOW_006c93f4;
    case 0xc0000096:
      return s_PRIV_INSTRUCTION_006c93e0;
    }
  }
  Arguments = (va_list *)0x0;
  nSize = 0x200;
  lpBuffer = &DAT_006f235c;
  dwLanguageId = 0;
  lpSource = GetModuleHandleA(s_NTDLL_DLL_006c93c4);
  FormatMessageA(0xa00,lpSource,param_1,dwLanguageId,lpBuffer,nSize,Arguments);
  return &DAT_006f235c;
}

