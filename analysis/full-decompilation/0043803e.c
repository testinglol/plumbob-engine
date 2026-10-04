
bool __thiscall FUN_0043803e(int param_1,short param_2)

{
  short sVar1;
  
  if ((*(short *)(param_1 + 0x38) != 0) &&
     (sVar1 = *(short *)(*(int *)(param_1 + 0x118) + 0x80), sVar1 <= param_2)) {
    if ((int)param_2 < (int)*(short *)(param_1 + 0x38) + (int)sVar1) {
      return *(short *)(*(int *)(param_1 + 0x34) + ((int)param_2 - (int)sVar1) * 2) != 0;
    }
  }
  return true;
}

