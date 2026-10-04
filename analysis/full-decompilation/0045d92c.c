
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall FUN_0045d92c(int param_1)

{
  char cVar1;
  char cVar2;
  
  if (*(short *)(param_1 + 0x61a) != 0) {
    return '\0';
  }
  cVar2 = '\0';
  if ((*(int *)(param_1 + 0xa44) != *(int *)(param_1 + 0xa40)) &&
     (((int)*(short *)(param_1 + 0x5ce) <
       *(int *)((*(uint *)(param_1 + 0xa40) & 7) * 0x44 + 0x83c + param_1) ||
      ((*(uint *)((*(uint *)(param_1 + 0xa40) & 7) * 0x44 + 0x860 + param_1) >> 1 & 1) != 0)))) {
    cVar2 = '\x01';
  }
  cVar1 = FUN_004074bc();
  if (((cVar1 != '\0') && (cVar2 == '\0')) && (*(short *)(param_1 + 0x5cc) < 2)) {
    if ((_DAT_00667428 <= *(float *)(param_1 + 0x7a8)) &&
       (_DAT_00667428 <= *(float *)(param_1 + 0x7b0))) {
      if (_DAT_00667428 <= *(float *)(param_1 + 0x7a0)) {
        return '\0';
      }
      if (1 < *(short *)(param_1 + 0x60e)) {
        return '\0';
      }
    }
    cVar2 = '\x01';
  }
  return cVar2;
}

