
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0047603d(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (param_2 == '\0') {
    if (iVar1 == 0) goto LAB_004760a8;
    if (iVar1 == 1) goto LAB_004760a0;
    if (iVar1 == 2) {
      return (float10)_DAT_006c4d70;
    }
    if (iVar1 == 3) {
      return (float10)_DAT_006c4d74;
    }
    if (iVar1 == 4) {
      return (float10)_DAT_006c4d78;
    }
  }
  else {
    if (iVar1 == 0) {
LAB_004760a8:
      return (float10)*(float *)(param_1 + 0x10);
    }
    if (iVar1 == 1) {
LAB_004760a0:
      return (float10)_DAT_0066657c;
    }
    if (iVar1 == 2) {
      return (float10)_DAT_006c4d7c;
    }
    if (iVar1 == 3) {
      return (float10)_DAT_006c4d80;
    }
    if (iVar1 == 4) {
      return (float10)_DAT_006c4d84;
    }
  }
  return (float10)_DAT_00667368;
}

